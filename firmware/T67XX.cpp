/**
 * @file    T67XX.cpp
 * @brief   Esta es una biblioteca para el módulo sensor de CO2 miniatura de la serie Telaire T67XX.
 * @details Estos sensores utilizan UART e I2C para comunicarse. Esta biblioteca está diseñada para la opción de
 * comunicación I2C. Se requieren 2 pines para la interfaz. Para habilitar la comunicación I2C, conecte el pin
 * CTRL (pin 6 del módulo) a GND.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note Este módulo se basa en la librería de Yaroslav Osadchyy (drug123@gmail.com) con MIT License
 *
 * Copyright (c) 2020 Yaroslav Osadchyy (drug123@gmail.com) https://github.com/drug123/T67XX
 *
 * MIT license, all text above must be included in any redistribution
 */

#include "T67XX.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793  //!< Redefinición del nivel de depuración de este archivo fuente.
#define DEBUG_TAG "T67XX"        //!< Etiqueta al enviar mensajes de depuración.

bool T67XX::begin(void) {
  _pWire->begin();
  delay(100);
  _pWire->beginTransmission(_deviceAddr);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
}

uint16_t T67XX::readPPM(void) {
  DEBUG_VERBOSE("Leyendo valor de CO2 [PPM]...");
  return this->read16(T67XX_REG_PPM);
};

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

uint16_t T67XX::getFirmwareVersion(void) {
  DEBUG_VERBOSE("Leyendo versión del firmware...");
  uint16_t firmware_version = this->read16(T67XX_REG_FIRMWARE);
  DEBUG_VERBOSE("Firmware: 0x%04X", firmware_version);
  return firmware_version;
};

void T67XX::reset(void) {
  DEBUG_VERBOSE("Reiniciando...");
  this->write16(T67XX_REG_RESET, T67XX_REG_VAL_ENABLE);
};

void T67XX::enableABCMode(void) {
  DEBUG_VERBOSE("Habilitando autocalibración ABC");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_ENABLE);
};

void T67XX::disableABCMode(void) {
  DEBUG_VERBOSE("Deshabilitando autocalibración ABC");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_DISABLE);
};

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

void T67XX::flashUpdate(void) {
  DEBUG_VERBOSE("Guardando la configuración en la flash...");
  this->write16(T67XX_REG_FLASH_UPDATE, T67XX_REG_VAL_ENABLE);
}

bool T67XX::beginCalibration(bool waitForCompletion) {
  DEBUG_VERBOSE("Iniciando calibración de punto único %s espera...", waitForCompletion ? "con" : "sin");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_ENABLE);
  do {
    _status.raw_value = this->getStatus();
    delay(100);
  } while (waitForCompletion && _status.bits.SINGLE_POINT_CAL);

  return !_status.bits.SINGLE_POINT_CAL;
};

void T67XX::endCalibration(void) {
  DEBUG_VERBOSE("Terminating single point calibration");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_DISABLE);
};

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
