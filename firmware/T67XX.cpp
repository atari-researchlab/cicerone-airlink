/***********************************************************************************************************************
 * @file        T67XX.cpp
 * @brief       Esta es una biblioteca para el módulo sensor de CO2 miniatura de la serie Telaire T67XX.
 * @details Estos sensores utilizan UART e I2C para comunicarse. Esta biblioteca está diseñada para la opción de
 * comunicación I2C. Se requieren 2 pines para la interfaz. Para habilitar la comunicación I2C, conecte el pin
 * CTRL (pin 6 del módulo) a GND.
 *
 * @author      [ALD/ATARI_RESEARCH_LAB]
 * @date        2024
 * @version     1.1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note Este módulo se basa en la librería de Yaroslav Osadchyy (drug123@gmail.com) con MIT License
 *
 * Copyright (c) 2020 Yaroslav Osadchyy (drug123@gmail.com)
 * MIT license, all text above must be included in any redistribution
 * https://github.com/drug123/T67XX
 **********************************************************************************************************************/

#include "T67XX.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793  //!< Redefinición del nivel de depuración en la compilación de este archivo fuente
#define DEBUG_TAG "T67XX"        //!< Etiqueta al enviar mensajes de depuración

/**
 * @brief Inicializa la comunicación I2C.
 * @return Verdadero si tiene éxito la comunicación con el módulo, falso si es errónea.
 */
bool T67XX::begin(void) {
  _pWire->begin();
  delay(100);
  _pWire->beginTransmission(_deviceAddr);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
}

/**
 * @brief Obtiene el valor de CO2 actual del sensor en PPM.
 * @return Valor de CO2 en PPM.
 */
uint16_t T67XX::readPPM(void) {
  DEBUG_VERBOSE("Leyendo valor de CO2 [PPM]...");
  return this->read16(T67XX_REG_PPM);
};

/**
 * @brief Obtiene el estado actual del sensor y lo almacena en la variable interna.
 * @return Estado actual del sensor.
 */
uint16_t T67XX::getStatus(void) {
  DEBUG_VERBOSE("Leyendo estado del sensor...");
  
  _status.raw_value = this->read16(T67XX_REG_STATUS);

  DEBUG_INFO("Estado: %u", _status.raw_value);
  DEBUG_VERBOSE("FEDCBA9876543210");
  String sStatus = String("0000000000000000") + String(_status.raw_value, BIN);
  sStatus.remove(0, sStatus.length() - 16);
  DEBUG_VERBOSE("%s", sStatus.c_str());
  DEBUG_VERBOSE("Banderas: %s", this->getStatusMsg().c_str());

  return _status.raw_value;
};

/**
 * @brief Obtiene la versión de firmware del sensor.
 * @return Versión del firmware.
 */
uint16_t T67XX::getFirmwareVersion(void) {
  DEBUG_VERBOSE("Leyendo versión del firmware...");
  uint16_t firmware_version = this->read16(T67XX_REG_FIRMWARE);
  DEBUG_VERBOSE("Firmware: 0x%04X", firmware_version);
  return firmware_version;
};

/**
 * @brief Reinicia el sensor.
 */
void T67XX::reset(void) {
  DEBUG_VERBOSE("Reiniciando...");
  this->write16(T67XX_REG_RESET, T67XX_REG_VAL_ENABLE);
};

/**
 * @brief Habilitar autocalibración ABC.
 * @details La Lógica Automática de Fondo (Automatic Background Logic), es una técnica de autocalibración
 * patentada diseñada para usarse en aplicaciones donde las concentraciones descienden a las condiciones
 * ambientales exteriores (400 ppm) al menos una vez (15 minutos) en un período de 7 días, lo cual suele
 * ocurrir durante periodos desocupados.
 *
 * Se logra una precisión completa utilizando la Lógica ABC. Con la Lógica ABC activada, el sensor 
 * generalmente alcanza su precisión operativa después de 25 horas de funcionamiento continuo, siempre
 * que haya estado expuesto a niveles ambientales de referencia de aire de 400 ppm ±10 ppm de CO2. El
 * sensor mantendrá las especificaciones de precisión con la Lógica ABC activada, siempre que esté 
 * expuesto al valor de referencia al menos una vez cada 7 días, y este valor de referencia sea la
 * concentración más baja a la que está expuesto el sensor.
 *
 * La Lógica ABC requiere el funcionamiento continuo del sensor en incrementos de al menos 4 horas cada uno.
 *
 * @warning No es recomendable en aplicaciones donde el sensor no esté expuesto regularmente a aire fresco
 * (400 ppm de CO2)
 */
void T67XX::enableABCMode(void) {
  DEBUG_VERBOSE("Habilitando autocalibración ABC");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_ENABLE);
};

/**
 * @brief Deshabilitar autocalibración ABC.
 * @see enableABCMode()
 */
void T67XX::disableABCMode(void) {
  DEBUG_VERBOSE("Deshabilitando autocalibración ABC");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_DISABLE);
};

/**
 * @brief               Modifica la dirección I2C interna del sensor
 * @details             Configura una nueva dirección I2C del sensor y lo reinicia para aplicar los cambios
 * @param newAddress    Nueva dirección I2C del sensor
 * @return              Verdadero si tiene éxito la comunicación con el módulo en la nueva dirección, falso si es errónea.
 * @warning             Este cambio es permanente al reiniciar el sensor
 */
uint8_t T67XX::setSlaveAddress(uint8_t newAddress) {
  DEBUG_VERBOSE("Estableciendo nueva dirección I2C a 0x%02X", newAddress);
  _deviceAddr = newAddress;
  this->write8(T67XX_REG_ADDRESS, newAddress);
  this->reset();
  delay(1000);
  _pWire->beginTransmission(newAddress);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
};

/**
 * @brief Guarda la configuración en la flash
 */
void T67XX::flashUpdate(void) {
  DEBUG_VERBOSE("Guardando la configuración en la flash...");
  this->write16(T67XX_REG_FLASH_UPDATE, T67XX_REG_VAL_ENABLE);
}

/**
 * @brief     Inicia la rutina de calibración de punto único.
 * @details   La rutina de calibración de punto único se realiza generalmente a temperatura
 * ambiente (~500 ppm, 25 °C) y tarda varios minutos en completarse tras su inicio
 * (aproximadamente 6 minutos). Durante este tiempo, se puede consultar el estado del sensor
 * y las lecturas actuales de ppm del gas. El usuario puede comprobar el estado de la 
 * calibración leyendo el registro de estado y anotando si el bit de calibración de punto
 * único está activado. La calibración se puede detener antes de que finalice.
 *
 * @param     waitForCompletion Opcional: Espera a que finalice la calibración (deshabilitada por defecto)
 * @return    Verdadero si ha finalizado la calibración.
 */
bool T67XX::beginCalibration(bool waitForCompletion) {
  DEBUG_VERBOSE("Iniciando calibración de punto único %s espera...", waitForCompletion ? "con" : "sin");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_ENABLE);
  do {
    _status.raw_value = this->getStatus();
    delay(100);
  } while (waitForCompletion && _status.bits.SINGLE_POINT_CAL);

  return !_status.bits.SINGLE_POINT_CAL;
};

/**
 * @brief Detiene la rutina de calibración de punto único.
 */
void T67XX::endCalibration(void) {
  DEBUG_VERBOSE("Terminating single point calibration");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_DISABLE);
};

/**
 * @brief Lee el valor actual de un registro de 8bits.
 * @param registerAddress Dirección del registro a escribir.
 * @return Valor del registro leido.
 */
uint8_t T67XX::read8(uint16_t registerAddress) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_READ_INPUT_REGISTERS);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 4);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Byte count = %u", _data[1]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[2] << 8) | _data[3]);
  return _data[3];
}

/**
 * @brief Lee el valor actual de un registro de 16bits.
 * @param registerAddress Dirección del registro a escribir.
 * @return Valor del registro leido.
 */
uint16_t T67XX::read16(uint16_t registerAddress) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_READ_INPUT_REGISTERS);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 4);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Byte count = %u", _data[1]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[2] << 8) | _data[3]);
  return ((_data[2] << 8) | _data[3]);
}

/**
 * @brief Escribe un dato en un registro de 8bits.
 * @param registerAddress Dirección del registro a escribir.
 * @param data Dato a escribir.
 * @return Valor del registro tras la escritura.
 */
uint8_t T67XX::write8(uint16_t registerAddress, uint8_t data) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_WRITE_SINGLE_REGISTER);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(data);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Reg. Address = 0x%04X", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[3] << 8) | _data[4]);
  return _data[4];
}

/**
 * @brief Escribe un dato en un registro de 16bits.
 * @param registerAddress Dirección del registro a escribir.
 * @param data Dato a escribir.
 * @return Valor del registro tras la escritura.
 */
uint16_t T67XX::write16(uint16_t registerAddress, uint16_t data) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_WRITE_SINGLE_COIL);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(byte(data >> 8));
  Wire.write(byte(data & 0xFF));
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Reg. Address = 0x%04X", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[3] << 8) | _data[4]);
  return ((_data[3] << 8) | _data[4]);
}

/**
 * @brief Genera un mensaje con el estado actual del sensor.
 * @return Cadena con el estado actual del sensor.
 */
String T67XX::getStatusMsg(void) {
  String statusString = "";

  if (_status.raw_value) {
    if (_status.bits.ERROR)
      statusString.concat("GENERAL ERROR; ");
    if (_status.bits.CALIBRATION_ERROR)
      statusString.concat("CALIBRATION ERROR; ");
    if (_status.bits.FLASH_ERROR)
      statusString.concat("FLASH ERROR; ");
    if (_status.bits.REBOOT)
      statusString.concat("REBOOT; ");
    if (_status.bits.WARMUP)
      statusString.concat("WARMUP; ");
    if (_status.bits.SINGLE_POINT_CAL)
      statusString.concat("CALIBRATING");
  } else
    statusString = "OK";

  return statusString;
}
