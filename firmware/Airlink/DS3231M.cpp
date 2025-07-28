/***********************************************************************************************************************
 * @file DS3231M.cpp
 * @brief Define la estructura básica de la clase DS3231M.
 *
 * @author      [ALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note Este archivo implementa las funcionalidades para el módulo de reloj en tiempo real (RTC) DS3231M.
 * Proporciona métodos para leer y establecer la hora y fecha, gestionar alarmas y otras configuraciones del RTC.
 *
 * Este módulo se basa en la librería de DFRobot para el DS3231M https://github.com/DFRobot/DFRobot_DS3231M
 * Copyright 2010 DFRobot Co.Ltd
 * Licencia: Licencia MIT
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions
 * of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 **********************************************************************************************************************/

#include "DS3231M.h"  // Incluye la cabecera de la clase DS3231M.
#include "Debug.h"              // Contiene las macros para controlar la salida de depuración por Serial.

#define DEBUG_TAG "DS3231M"
#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_DS3231M

// Array en PROGMEM (memoria de programa) que almacena el número de días en cada mes.
// Esto ahorra memoria RAM en microcontroladores.
const uint8_t daysInMonth[] PROGMEM = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/**
 * @brief Convierte un año, mes y día en el número total de días desde el año 2000.
 * @param y Año (ej. 2024).
 * @param m Mes (1-12).
 * @param d Día (1-31).
 * @return Número total de días desde el 1 de enero del año 2000.
 */
static uint16_t date2days(uint16_t y, uint8_t m, uint8_t d) {
  if (y >= 2000)
    y -= 2000;        // Elimina el offset del año (ej. 2024 -> 24).
  uint16_t days = d;  // Inicializa los días con el día actual.
  for (uint8_t i = 1; i < m; ++i) {
    // Suma los días de los meses anteriores. pgm_read_byte se usa para leer de PROGMEM.
    days += pgm_read_byte(daysInMonth + i - 1);
  }
  // Si el año es bisiesto y el mes es posterior a febrero, añade un día extra.
  if (m > 2 && y % 4 == 0)
    days++;
  return days + 365 * y + (y + 3) / 4 - 1;  // Calcula los días totales incluyendo años bisiestos.
}

/**
 * @brief Convierte un año, mes, día y hora en segundos desde el 1 de enero de 2000.
 * @param y Año.
 * @param m Mes.
 * @param d Día.
 * @param h Hora.
 * @param mi Minuto.
 * @param s Segundo.
 * @return Número total de segundos desde el 1 de enero de 2000.
 */
static uint32_t time2long(uint16_t y, uint8_t m, uint8_t d, uint8_t h, uint8_t mi, uint8_t s) {
  // Convierte la fecha a días y luego a segundos, sumando los segundos de la hora, minuto y segundo actuales.
  return ((uint32_t)date2days(y, m, d) * 24L * 60L * 60L) + (h * 60L * 60L) + (mi * 60L) + s;
}

/**
 * @brief Destructor de la clase DS3231M.
 */
DS3231M::~DS3231M() {}

/**
 * @brief Inicializa la comunicación I2C.
 * @return Verdadero si tiene éxito la comunicación con el módulo, falso si es errónea.
 */
bool DS3231M::begin(void) {
  _pWire->begin();
  delay(100);
  _pWire->beginTransmission(_deviceAddr);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
}

/**
 * @brief Establece la hora y fecha del RTC.
 * @param year Año (ej. 2024).
 * @param month Mes (1-12).
 * @param day Día (1-31).
 * @param hour Hora (0-23).
 * @param minute Minuto (0-59).
 * @param second Segundo (0-59).
 */
void DS3231M::setRTCTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
  // Almacena los valores en el array rtc y los convierte a formato BCD (Binary-Coded Decimal)
  // que es el formato que utiliza el DS3231M.
  rtc[0] = bin2bcd(second);
  rtc[1] = bin2bcd(minute);
  rtc[2] = bin2bcd(hour);
  rtc[3] = bin2bcd(dayOfTheWeek(year, month, day));  // Calcula el día de la semana.
  rtc[4] = bin2bcd(day);
  rtc[5] = bin2bcd(month);
  rtc[6] = bin2bcd(year - 2000);  // El chip DS3231M almacena el año como offset desde 2000.

  // Escribe los datos en los registros del RTC a través de I2C.
  writeReg(DS3231M_REG_RTC_SEC, rtc, 7);
}

/**
 * @brief Obtiene la hora actual del RTC.
 * @return Objeto DateTime que contiene la hora y fecha actuales.
 */
DateTime DS3231M::getRTCTime() {
  // Lee los 7 registros de tiempo y fecha del DS3231M.
  readReg(DS3231M_REG_RTC_SEC, rtc, 7);

  // Convierte los valores BCD a BIN y crea un objeto DateTime.
  return DateTime(bcd2bin(rtc[6]) + 2000, bcd2bin(rtc[5]), bcd2bin(rtc[4]), bcd2bin(rtc[2]), bcd2bin(rtc[1]), bcd2bin(rtc[0]));
}

/**
 * @brief Establece la primera alarma del RTC (alarma 1).
 * @param dt Objeto DateTime con la hora y fecha de la alarma.
 * @param type Tipo de alarma (ej. cada minuto, cada hora, cada día, etc.).
 */
void DS3231M::setAlarm1(const DateTime& dt, eAlarmType_t type) {
  uint8_t sec = bin2bcd(dt.second());
  uint8_t min = bin2bcd(dt.minute());
  uint8_t hour = bin2bcd(dt.hour());
  uint8_t day = bin2bcd(dt.day());
  uint8_t dy;

  // Configura el bit de control para el tipo de alarma.
  switch (type) {
    case eEverySecond:  // Cada segundo
      sec |= 0x80;
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryMinute:  // Cada minuto (en el segundo especificado)
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryHour:  // Cada hora (en el minuto y segundo especificados)
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryDay:  // Cada día (en la hora, minuto y segundo especificados)
      day |= 0x80;
      break;
    case eEveryWeek:  // Cada semana (en el día de la semana, hora, minuto y segundo especificados)
      dy = bin2bcd(dt.dayOfTheWeek());
      day = dy | 0x40;  // Bit 6 para indicar día de la semana en lugar de día del mes.
      break;
    case eEveryMonth:  // Cada mes (en el día del mes, hora, minuto y segundo especificados)
      break;
    default:
      return;  // Tipo de alarma no válido.
  }

  // Escribe los valores de la alarma en los registros correspondientes.
  writeReg(DS3231M_REG_ALARM1_SEC, &sec, 1);
  writeReg(DS3231M_REG_ALARM1_MIN, &min, 1);
  writeReg(DS3231M_REG_ALARM1_HOUR, &hour, 1);
  writeReg(DS3231M_REG_ALARM1_DAY, &day, 1);

  // Habilita la interrupción de alarma 1 (A1IE) en el registro de control.
  uint8_t ctrl[1];
  readReg(DS3231M_REG_CTRL, ctrl, 1);
  ctrl[0] |= 0x01;  // Set A1IE bit
  writeReg(DS3231M_REG_CTRL, ctrl, 1);
}

/**
 * @brief Establece la segunda alarma del RTC (alarma 2).
 * @param dt Objeto DateTime con la hora y fecha de la alarma.
 * @param type Tipo de alarma (ej. cada minuto, cada hora, cada día, etc.).
 */
void DS3231M::setAlarm2(const DateTime& dt, eAlarmType_t type) {
  uint8_t min = bin2bcd(dt.minute());
  uint8_t hour = bin2bcd(dt.hour());
  uint8_t day = bin2bcd(dt.day());
  uint8_t dy;

  // Configura el bit de control para el tipo de alarma.
  switch (type) {
    case eEveryMinute:  // Cada minuto (en el minuto especificado)
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryHour:  // Cada hora (en el minuto especificado)
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryDay:  // Cada día (en la hora y minuto especificados)
      day |= 0x80;
      break;
    case eEveryWeek:  // Cada semana (en el día de la semana, hora y minuto especificados)
      dy = bin2bcd(dt.dayOfTheWeek());
      day = dy | 0x40;  // Bit 6 para indicar día de la semana en lugar de día del mes.
      break;
    case eEveryMonth:  // Cada mes (en el día del mes, hora y minuto especificados)
      break;
    default:
      return;  // Tipo de alarma no válido.
  }

  // Escribe los valores de la alarma en los registros correspondientes.
  writeReg(DS3231M_REG_ALARM2_MIN, &min, 1);
  writeReg(DS3231M_REG_ALARM2_HOUR, &hour, 1);
  writeReg(DS3231M_REG_ALARM2_DAY, &day, 1);

  // Habilita la interrupción de alarma 2 (A2IE) en el registro de control.
  uint8_t ctrl[1];
  readReg(DS3231M_REG_CTRL, ctrl, 1);
  ctrl[0] |= 0x02;  // Set A2IE bit
  writeReg(DS3231M_REG_CTRL, ctrl, 1);
}

/**
 * @brief Obtiene la temperatura actual del sensor DS3231M.
 * @return Temperatura en grados Celsius (float).
 */
float DS3231M::getTemp() {
  uint8_t temp[2];
  // Lee los dos bytes del registro de temperatura.
  readReg(DS3231M_REG_TEMP, temp, 2);
  // Combina los bytes para obtener la temperatura y la convierte a float.
  return (float)temp[0] + ((temp[1] >> 6) * 0.25);
}

/**
 * @brief Verifica si alguna alarma se ha disparado.
 * @return True si la alarma 1 o la alarma 2 se han disparado, false en caso contrario.
 */
bool DS3231M::isAlarm() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);  // Lee el registro de estado.
  return status[0] & 3;                    // Retorna true si los bits 0 (A1F) o 1 (A2F) están activados.
}

/**
 * @brief Limpia las banderas de alarma en el registro de estado.
 * Esto es necesario después de que una alarma se ha disparado para que pueda volver a activarse.
 */
void DS3231M::clearAlarm() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Lee el registro de estado.
  status[0] &= 0xFC;                        // Limpia los bits A1F (bit 0) y A2F (bit 1).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Escribe el nuevo valor de estado.
}

/**
 * @brief Habilita la salida de onda cuadrada de 32kHz en el pin SQW/INT.
 */
void DS3231M::enable32k() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Lee el registro de estado.
  status[0] |= 0x08;                        // Establece el bit EN32kHz (bit 3).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Escribe el nuevo valor de estado.
}

/**
 * @brief Deshabilita la salida de onda cuadrada de 32kHz en el pin SQW/INT.
 */
void DS3231M::disable32k() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Lee el registro de estado.
  status[0] &= 0xF7;                        // Limpia el bit EN32kHz (bit 3).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Escribe el nuevo valor de estado.
}

/**
 *@brief Comprueba si el RTC perdió la alimentación auxiliar
 */
bool DS3231M::lostPower(void) {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);
  return status[0] >> 7;
}

/**
 * @brief Escribe datos en un registro específico del DS3231M a través de I2C.
 * @param reg Dirección del registro a escribir.
 * @param pBuf Puntero al buffer de datos a escribir.
 * @param size Número de bytes a escribir.
 */
void DS3231M::writeReg(uint8_t reg, const void* pBuf, size_t size) {
  if (pBuf == NULL) {
    // Imprime un mensaje de depuración si el puntero es nulo.
    DEBUG_ERROR("pBuf null pointer");
  }
  uint8_t* _pBuf = (uint8_t*)pBuf;  // Castea el puntero a uint8_t para iterar.

  _pWire->beginTransmission(DS3231M_IIC_ADDRESS);  // Inicia la transmisión I2C al DS3231M.
  _pWire->write(reg);                              // Envía la dirección del registro.
  for (size_t i = 0; i < size; i++) {
    _pWire->write(_pBuf[i]);  // Envía cada byte del buffer.
  }
  _pWire->endTransmission();  // Finaliza la transmisión I2C.
}

/**
 * @brief Lee datos de un registro específico del DS3231M a través de I2C.
 * @param reg Dirección del registro a leer.
 * @param pBuf Puntero al buffer donde se almacenarán los datos leídos.
 * @param size Número de bytes a leer.
 * @return El número de bytes leídos (0 en caso de error o si no se leyeron bytes).
 */
uint8_t DS3231M::readReg(uint8_t reg, const void* pBuf, size_t size) {
  if (pBuf == NULL) {
    // Imprime un mensaje de depuración si el puntero es nulo.
    DEBUG_ERROR("pBuf null pointer");
  }
  uint8_t* _pBuf = (uint8_t*)pBuf;  // Castea el puntero a uint8_t para iterar.

  _pWire->beginTransmission(DS3231M_IIC_ADDRESS);  // Inicia la transmisión I2C al DS3231M.
  _pWire->write(reg);                              // Envía la dirección del registro a leer.
  _pWire->endTransmission(false);                  // Finaliza la transmisión pero mantiene la conexión (repeated start).

  // Solicita 'size' bytes del DS3231M.
  uint8_t i = 0;
  _pWire->requestFrom(DS3231M_IIC_ADDRESS, size);
  while (_pWire->available()) {
    if (i < size) {
      _pBuf[i++] = _pWire->read();  // Lee los bytes y los almacena en el buffer.
    } else {
      _pWire->read();  // Descarta bytes adicionales si se leen más de lo solicitado.
    }
  }
  return i;  // Retorna el número de bytes leídos.
}

/**
 * @brief Convierte un valor BCD (Binary-Coded Decimal) a BIN (Binario).
 * @param val Valor en formato BCD.
 * @return Valor en formato BIN.
 */
uint8_t DS3231M::bcd2bin(uint8_t val) {
  return val - 6 * (val >> 4);  // Conversión BCD a BIN.
}

/**
 * @brief Convierte un valor BIN (Binario) a BCD (Binary-Coded Decimal).
 * @param val Valor en formato BIN.
 * @return Valor en formato BCD.
 */
uint8_t DS3231M::bin2bcd(uint8_t val) {
  return val + 6 * (val / 10);  // Conversión BIN a BCD.
}

/**
 * @brief Calcula el día de la semana para una fecha dada.
 * @param y Año.
 * @param m Mes.
 * @param d Día.
 * @return Día de la semana (1 = Domingo, 2 = Lunes, ..., 7 = Sábado).
 */
uint8_t DS3231M::dayOfTheWeek(uint16_t y, uint8_t m, uint8_t d) const {
  // Implementación del algoritmo de Zeller para calcular el día de la semana.
  // k = día del mes
  // m = mes (3=marzo, 4=abril, ..., 12=diciembre, 1=enero, 2=febrero)
  // D = año del siglo (ej. para 2024, D=24)
  // C = siglo (ej. para 2024, C=20)
  uint8_t k = d;
  uint8_t month = m;
  uint16_t year = y;

  if (month <= 2) {
    month += 12;
    year -= 1;
  }

  uint8_t D = year % 100;
  uint8_t C = year / 100;

  // Fórmula de Zeller: h = (k + floor(2.6 * m - 0.2) + D + floor(D/4) + floor(C/4) - 2 * C) mod 7
  // El resultado es 0=Sábado, 1=Domingo, ..., 6=Viernes.
  // Se ajusta para que 1=Domingo, ..., 7=Sábado.
  uint8_t dayOfWeek = (k + (26 * (month + 1)) / 10 + D + D / 4 + C / 4 + 5 * C) % 7;
  return (dayOfWeek == 0) ? 7 : dayOfWeek;  // Ajusta para que el domingo sea 7 o 1 según la convención.
}

/***********************************************************************************************************************
 * SECCIÓN DE LICENCIAS DE LIBRERÍAS EXTERNAS (ESPECÍFICAS DE ESTE ARCHIVO)
 *
 * 1.  **Librería: 'DFRobot_DS3231M'**
 * * **Autor:** DFRobot Co.Ltd (yufeng)
 * * **Licencia:** MIT License
 * * **URL:** https://github.com/DFRobot/DFRobot_DS3231M/blob/master/LICENSE
 * * **Compatibilidad con CC-BY-SA 4.0:** Compatible.
 *
 * Para una descripción más detallada de la compatibilidad general de licencias, consulta la sección
 * "SECCIÓN DE LICENCIAS DE LIBRERÍAS EXTERNAS" en 'Airlink.ino'.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * SECCIÓN DE REFERENCIAS Y AGRADECIMIENTOS (ESPECÍFICAS DE ESTE ARCHIVO)
 *
 * - Datasheet del DS3231M: https://dfimg.dfrobot.com/nobody/wiki/456426e32d698477163ee658755f4d05.pdf
 * - Repositorio de la librería DFRobot_DS3231M: https://github.com/DFRobot/DFRobot_DS3231M
 **********************************************************************************************************************/
