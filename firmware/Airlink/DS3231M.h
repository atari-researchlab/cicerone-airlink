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

#ifndef _DS3231M_H  // Guarda de inclusión para evitar inclusiones múltiples.
#define _DS3231M_H

// Inclusión condicional de la cabecera de Arduino según la versión.
#if ARDUINO >= 100
#include "Arduino.h"  // Para versiones de Arduino IDE 1.0 y posteriores.
#else
#include "WProgram.h"  // Para versiones de Arduino IDE anteriores a 1.0.
#endif

#include <Wire.h>  // Incluye la librería Wire para la comunicación I2C.

/***********************************************************************************************************************
 * DEFINICIONES DE MACROS Y DIRECCIONES I2C
 **********************************************************************************************************************/
#define DS3231M_IIC_ADDRESS 0x68  // Dirección I2C predeterminada del DS3231M.

// Constante para convertir segundos desde 1970 a segundos desde 2000.
#define SECONDS_FROM_1970_TO_2000 946684800

// Definiciones de las direcciones de los registros del DS3231M.
#define DS3231M_REG_RTC_SEC 0X00    // Registro de segundos del RTC.
#define DS3231M_REG_RTC_MIN 0X01    // Registro de minutos del RTC.
#define DS3231M_REG_RTC_HOUR 0X02   // Registro de horas del RTC.
#define DS3231M_REG_RTC_DAY 0X03    // Registro del día de la semana del RTC.
#define DS3231M_REG_RTC_DATE 0X04   // Registro del día del mes del RTC.
#define DS3231M_REG_RTC_MONTH 0X05  // Registro del mes del RTC.
#define DS3231M_REG_RTC_YEAR 0X06   // Registro del año del RTC.

#define DS3231M_REG_ALARM1_SEC 0X07   // Registro de segundos de la alarma 1.
#define DS3231M_REG_ALARM1_MIN 0X08   // Registro de minutos de la alarma 1.
#define DS3231M_REG_ALARM1_HOUR 0X09  // Registro de horas de la alarma 1.
#define DS3231M_REG_ALARM1_DAY 0X0A   // Registro del día/día de la semana de la alarma 1.

#define DS3231M_REG_ALARM2_MIN 0X0B   // Registro de minutos de la alarma 2.
#define DS3231M_REG_ALARM2_HOUR 0X0C  // Registro de horas de la alarma 2.
#define DS3231M_REG_ALARM2_DAY 0X0D   // Registro del día/día de la semana de la alarma 2.

#define DS3231M_REG_CTRL 0X0E    // Registro de control.
#define DS3231M_REG_STATUS 0X0F  // Registro de estado.
#define DS3231M_REG_TEMP 0X11    // Registro de temperatura.

/***********************************************************************************************************************
 * ENUMERACIONES
 **********************************************************************************************************************/

/**
 * @brief Enumeración para definir los tipos de alarma disponibles.
 */
typedef enum {
  eEverySecond,  // Alarma cada segundo.
  eEveryMinute,  // Alarma cada minuto (en el segundo especificado).
  eEveryHour,    // Alarma cada hora (en el minuto y segundo especificados).
  eEveryDay,     // Alarma cada día (en la hora, minuto y segundo especificados).
  eEveryWeek,    // Alarma cada semana (en el día de la semana, hora, minuto y segundo especificados).
  eEveryMonth,   // Alarma cada mes (en el día del mes, hora, minuto y segundo especificados).
} eAlarmType_t;

/***********************************************************************************************************************
 * CLASE DateTime
 *
 * Una clase auxiliar para manejar la fecha y hora de manera conveniente.
 **********************************************************************************************************************/
class DateTime {
public:
  /**
     * @brief Constructor de la clase DateTime.
     * @param y Año.
     * @param m Mes.
     * @param d Día.
     * @param hh Hora.
     * @param mm Minuto.
     * @param ss Segundo.
     */
  DateTime(uint16_t y = 0, uint8_t m = 0, uint8_t d = 0, uint8_t hh = 0, uint8_t mm = 0, uint8_t ss = 0)
    : y(y), m(m), d(d), hh(hh), mm(mm), ss(ss){};

  /**
     * @brief Obtiene el año.
     * @return Año.
     */
  uint16_t year() const {
    return y;
  }
  /**
     * @brief Obtiene el mes.
     * @return Mes.
     */
  uint8_t month() const {
    return m;
  }
  /**
     * @brief Obtiene el día del mes.
     * @return Día del mes.
     */
  uint8_t day() const {
    return d;
  }
  /**
     * @brief Obtiene la hora.
     * @return Hora.
     */
  uint8_t hour() const {
    return hh;
  }
  /**
     * @brief Obtiene el minuto.
     * @return Minuto.
     */
  uint8_t minute() const {
    return mm;
  }
  /**
     * @brief Obtiene el segundo.
     * @return Segundo.
     */
  uint8_t second() const {
    return ss;
  }

  /**
     * @brief Calcula el día de la semana.
     * @return Día de la semana (1 = Domingo, 2 = Lunes, ..., 7 = Sábado).
     */
  uint8_t dayOfTheWeek() const;

protected:
  uint16_t y;  ///< Año
  uint8_t m;   ///< Mes
  uint8_t d;   ///< Día del mes
  uint8_t hh;  ///< Hora
  uint8_t mm;  ///< Minuto
  uint8_t ss;  ///< Segundo
};

/***********************************************************************************************************************
 * CLASE DS3231M
 *
 * Clase principal para interactuar con el chip RTC DS3231M.
 **********************************************************************************************************************/
class DS3231M {
public:
  /**
     * @brief Constructor de la clase DS3231M.
     */
  DS3231M(TwoWire* pWire = &Wire) {
    _pWire = pWire;
  };

  /**
    * @brief Destructor de la clase DS3231M.
    */
  ~DS3231M();

  /**
    * @brief Inicializa la comunicación I2C.
    * @return Verdadero si tiene éxito la comunicación con el módulo, falso si es errónea.
    */
  bool begin(void);

  /**
     * @brief Establece la hora y fecha del RTC.
     * @param year Año.
     * @param month Mes.
     * @param day Día.
     * @param hour Hora.
     * @param minute Minuto.
     * @param second Segundo.
     */
  void setRTCTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

  /**
     * @brief Obtiene la hora actual del RTC.
     * @return Objeto DateTime que contiene la hora y fecha actuales.
     */
  DateTime getRTCTime();

  /**
     * @brief Establece la primera alarma del RTC (alarma 1).
     * @param dt Objeto DateTime con la hora y fecha de la alarma.
     * @param type Tipo de alarma (ver eAlarmType_t).
     */
  void setAlarm1(const DateTime& dt, eAlarmType_t type);

  /**
     * @brief Establece la segunda alarma del RTC (alarma 2).
     * @param dt Objeto DateTime con la hora y fecha de la alarma.
     * @param type Tipo de alarma (ver eAlarmType_t).
     */
  void setAlarm2(const DateTime& dt, eAlarmType_t type);

  /**
     * @brief Obtiene la temperatura actual del sensor DS3231M.
     * @return Temperatura en grados Celsius (float).
     */
  float getTemp();

  /**
     * @brief Verifica si alguna alarma se ha disparado.
     * @return True si la alarma 1 o la alarma 2 se han disparado, false en caso contrario.
     */
  bool isAlarm();

  /**
     * @brief Limpia las banderas de alarma en el registro de estado.
     */
  void clearAlarm();

  /**
     * @brief Habilita la salida de onda cuadrada de 32kHz en el pin SQW/INT.
     */
  void enable32k();

  /**
     * @brief Deshabilita la salida de onda cuadrada de 32kHz en el pin SQW/INT.
     */
  void disable32k();

  /**
     *@brief Comprueba si el RTC perdió la alimentación auxiliar
     *@return Verdadero si se perdió la alimentación.
     */
  bool lostPower(void);

  uint8_t rtc[7];  // Array para almacenar los datos de tiempo y fecha del RTC.

protected:
  /**
     * @brief Escribe datos en un registro específico del DS3231M a través de I2C.
     * @param reg Dirección del registro a escribir.
     * @param pBuf Puntero al buffer de datos a escribir.
     * @param size Número de bytes a escribir.
     */
  virtual void writeReg(uint8_t reg, const void* pBuf, size_t size);
  /**
     * @brief Lee datos de un registro específico del DS3231M a través de I2C.
     * @param reg Dirección del registro a leer.
     * @param pBuf Puntero al buffer donde se almacenarán los datos leídos.
     * @param size Número de bytes a leer.
     * @return El número de bytes leídos.
     */
  virtual uint8_t readReg(uint8_t reg, const void* pBuf, size_t size);

  /**
     * @brief Convierte un valor BCD (Binary-Coded Decimal) a BIN (Binario).
     * @param val Valor en formato BCD.
     * @return Valor en formato BIN.
     */
  static uint8_t bcd2bin(uint8_t val);
  /**
     * @brief Convierte un valor BIN (Binario) a BCD (Binary-Coded Decimal).
     * @param val Valor en formato BIN.
     * @return Valor en formato BCD.
     */
  static uint8_t bin2bcd(uint8_t val);
  /**
     * @brief Calcula el día de la semana para una fecha dada.
     * @param y Año.
     * @param m Mes.
     * @param d Día.
     * @return Día de la semana.
     */
  uint8_t dayOfTheWeek(uint16_t y, uint8_t m, uint8_t d) const;

private:
  TwoWire* _pWire;
  uint8_t _deviceAddr = DS3231M_IIC_ADDRESS;
  const char* daysOfTheWeek[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
  const char* hourOfAM[4] = { "", "", "AM", "PM" };
};

#endif  // _DS3231M_H

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
