/***********************************************************************************************************************
 * @file        T67XX.cpp
 * @brief       This is a library for the Telaire T6700 Series Miniature CO2 Sensor Module.
 * These sensors use UART and I2C to communicate, this library intended for I2C communication option,
 * 2 pins are required to interface. To enable I2C communication, connect CTRL pin (pin 6 on the module)
 * to GND.
 *
 * @author      Yaroslav Osadchyy (drug123@gmail.com)
 * @date        2020
 * @version     1.0.0
 *
 * @license     MIT License
 *
 * Copyright (c) 2020 Yaroslav Osadchyy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 **********************************************************************************************************************/
#include "T67XX.h"
#include "Debug.h"  // Contiene definiciones de macros de depuración.

#define DEBUG_TAG "T67XX"
#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793

T67XX::T67XX() {}

bool T67XX::begin(void) {
  return this->begin(T67XX_I2C_ADDR);
};

bool T67XX::begin(uint8_t Address) {
  _address = Address;
  Wire.begin();
  bool status = true;
  DEBUG_VERBOSE("T67XX: Initiate I2C communication");
  return status;
}

uint16_t T67XX::readPPM(void) {
  DEBUG_VERBOSE("T67XX: Requesting CO2 PPM value");
  return this->read16(T67XX_REG_PPM);
};

uint16_t T67XX::getStatus(void) {
  DEBUG_VERBOSE("T67XX: Requesting sensor status");
  uint16_t _sta = this->read16(T67XX_REG_STATUS);
  _status.set(_sta);

  DEBUG_VERBOSE("T67XX: Status of the sensor: %u", _sta);
  DEBUG_VERBOSE("T67XX: FEDCBA9876543210");
  String sStatus = String("0000000000000000") + String(_sta, BIN);
  sStatus.remove(0, sStatus.length() - 16);
  DEBUG_VERBOSE("T67XX: %s", sStatus);
  DEBUG_VERBOSE("T67XX: Status flags: %s", this->getStatusMsg());

  return _sta;
};

uint16_t T67XX::getFirmwareVersion(void) {
  DEBUG_VERBOSE("T67XX: Requesting firmware version");
  return this->read16(T67XX_REG_FIRMWARE);
};

void T67XX::reset(void) {
  DEBUG_VERBOSE("T67XX: Performing reset");
  this->write16(T67XX_REG_RESET, T67XX_REG_VAL_ENABLE);
};

void T67XX::setABCMode(bool ABCMode) {
  DEBUG_VERBOSE("T67XX: Setting ABC self-calibration to %s", ABCMode ? "Enabled" : "Disabled");
  this->write16(T67XX_REG_ABC_LOGIC,
                ABCMode ? T67XX_REG_VAL_ENABLE : T67XX_REG_VAL_DISABLE);
};

uint8_t T67XX::setSlaveAddress(uint8_t Address) {
  DEBUG_VERBOSE("T67XX: Setting new I2C address 0x%X", Address);
  // TODO:
  return Address;
};

void T67XX::flashUpdate(void) {
  DEBUG_VERBOSE("T67XX: Updating flash with settings in RAM");
  this->write16(T67XX_REG_FLASH_UPDATE, T67XX_REG_VAL_ENABLE);
}

bool T67XX::beginCalibration(void) {
  beginCalibration(false);
  return true;
};

bool T67XX::beginCalibration(bool waitForCompletion) {
  DEBUG_VERBOSE("T67XX: Begin single point calibration and %s wait for completion", waitForCompletion ? "" : "do not");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_ENABLE);
  do {
    _status.set(this->getStatus());
    delay(100);
  } while (waitForCompletion && _status.SINGLE_POINT_CAL);

  return true;
};

bool T67XX::endCalibration(void) {
  DEBUG_VERBOSE("T67XX: Terminating single point calibration");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_DISABLE);

  return true;
};

/*** Private Section ***/
uint16_t T67XX::read16(uint16_t addr) {
  Wire.beginTransmission(_address);
  Wire.write(0x04);
  Wire.write(byte(addr >> 8));
  Wire.write(byte(addr & 0xFF));
  Wire.write(0x00);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_address), 4);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  DEBUG_VERBOSE("T67XX: Returned function = %u", _data[0]);
  DEBUG_VERBOSE("T67XX: Returned byte count = %u", _data[1]);
  DEBUG_VERBOSE("T67XX: Returned Value = %u", (_data[2] << 8) | _data[3]);
  return ((_data[2] << 8) | _data[3]);
}

void T67XX::write8(uint16_t addr, uint8_t data) {
  Wire.beginTransmission(_address);
  Wire.write(0x06);
  Wire.write(byte(addr >> 8));
  Wire.write(byte(addr & 0xFF));
  Wire.write(0x00);
  Wire.write(data);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_address), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("T67XX: Returned function = %u", _data[0]);
  DEBUG_VERBOSE("T67XX: Returned Address = %u", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("T67XX: Returned Value = %u", (_data[3] << 8) | _data[4]);
}

void T67XX::write16(uint16_t addr, uint16_t data) {
  Wire.beginTransmission(_address);
  Wire.write(0x05);
  Wire.write(byte(addr >> 8));
  Wire.write(byte(addr & 0xFF));
  Wire.write(byte(data >> 8));
  Wire.write(byte(data & 0xFF));
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_address), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("T67XX: Returned function = %u", _data[0]);
  DEBUG_VERBOSE("T67XX: Returned Address = %u", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("T67XX: Returned Value = %u", (_data[3] << 8) | _data[4]);
}

String T67XX::getStatusMsg(void) {
  String statusString = "";

  if (_status.STA) {
    if (_status.ERROR)
      statusString.concat("GENERAL ERROR; ");
    if (_status.CALIBRATION_ERROR)
      statusString.concat("CALIBRATION ERROR; ");
    if (_status.FLASH_ERROR)
      statusString.concat("FLASH ERROR; ");
    if (_status.REBOOT)
      statusString.concat("REBOOT; ");
    if (_status.WARMUP)
      statusString.concat("WARMUP; ");
    if (_status.SINGLE_POINT_CAL)
      statusString.concat("CALIBRATING;");
  } else
    statusString = "OK";

  return statusString;
}
