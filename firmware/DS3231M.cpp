/**
 * @file    DS3231M.cpp
 * @brief   This file implements functionalities for the DS3231M RTC module.
 * @details Provides methods for reading and setting time and date, managing alarms and other
 * RTC configurations.
 *
 * - DS3231M Datasheet: https://dfimg.dfrobot.com/nobody/wiki/456426e32d698477163ee658755f4d05.pdf
 * - DFRobot_DS3231M library repository: https://github.com/DFRobot/DFRobot_DS3231M
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note This module is based on the DFRobot library for the DS3231M
 * https://github.com/DFRobot/DFRobot_DS3231M
 *
 * Copyright 2010 DFRobot Co.Ltd
 *
 * License: MIT License
 */

/*
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "Wire.h"
#include "DS3231M.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_DS3231M  //!< Redefinition of the debug level for this source file.
#define DEBUG_TAG "DS3231M"        //!< Tag when sending debug messages.

bool DS3231M::begin(void) {
  _pWire->begin();
  delay(100);
  _pWire->beginTransmission(_deviceAddr);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
}

void DS3231M::setRTCTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second) {
  // Stores values in the rtc array and converts them to BCD (Binary-Coded Decimal) format
  // which is the format used by the DS3231M.
  rtc[0] = bin2bcd(second);
  rtc[1] = bin2bcd(minute);
  rtc[2] = bin2bcd(hour);
  rtc[3] = bin2bcd(dayOfTheWeek(year, month, day));  // Calculates the day of the week.
  rtc[4] = bin2bcd(day);
  rtc[5] = bin2bcd(month);
  rtc[6] = bin2bcd(year - 2000);  // The DS3231M chip stores the year as an offset from 2000.

  // Writes the data to the RTC registers via I2C.
  writeReg(DS3231M_REG_RTC_SEC, rtc, 7);
}

DateTime DS3231M::getRTCTime() {
  // Reads the 7 time and date registers from the DS3231M.
  readReg(DS3231M_REG_RTC_SEC, rtc, 7);

  // Converts BCD values to BIN and creates a DateTime object.
  return DateTime(bcd2bin(rtc[6]) + 2000, bcd2bin(rtc[5]), bcd2bin(rtc[4]), bcd2bin(rtc[2]), bcd2bin(rtc[1]), bcd2bin(rtc[0]));
}

void DS3231M::setAlarm1(const DateTime& dt, eAlarmType_t type) {
  uint8_t sec = bin2bcd(dt.second());
  uint8_t min = bin2bcd(dt.minute());
  uint8_t hour = bin2bcd(dt.hour());
  uint8_t day = bin2bcd(dt.day());
  uint8_t dy;

  // Configures the control bit for the alarm type.
  switch (type) {
    case eEverySecond:  // Every second
      sec |= 0x80;
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryMinute:  // Every minute (at the specified second)
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryHour:  // Every hour (at the specified minute and second)
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryDay:  // Every day (at the specified hour, minute and second)
      day |= 0x80;
      break;
    case eEveryWeek:  // Every week (at the specified day of the week, hour, minute and second)
      dy = bin2bcd(dt.dayOfTheWeek());
      day = dy | 0x40;  // Bit 6 to indicate day of the week instead of day of the month.
      break;
    case eEveryMonth:  // Every month (at the specified day of the month, hour, minute and second)
      break;
    default:
      return;  // Invalid alarm type.
  }

  // Writes the alarm values to the corresponding registers.
  writeReg(DS3231M_REG_ALARM1_SEC, &sec, 1);
  writeReg(DS3231M_REG_ALARM1_MIN, &min, 1);
  writeReg(DS3231M_REG_ALARM1_HOUR, &hour, 1);
  writeReg(DS3231M_REG_ALARM1_DAY, &day, 1);

  // Enables alarm 1 interrupt (A1IE) in the control register.
  uint8_t ctrl[1];
  readReg(DS3231M_REG_CTRL, ctrl, 1);
  ctrl[0] |= 0x01;  // Set A1IE bit
  writeReg(DS3231M_REG_CTRL, ctrl, 1);
}

void DS3231M::setAlarm2(const DateTime& dt, eAlarmType_t type) {
  uint8_t min = bin2bcd(dt.minute());
  uint8_t hour = bin2bcd(dt.hour());
  uint8_t day = bin2bcd(dt.day());
  uint8_t dy;

  // Configures the control bit for the alarm type.
  switch (type) {
    case eEveryMinute:  // Every minute (at the specified minute)
      min |= 0x80;
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryHour:  // Every hour (at the specified minute)
      hour |= 0x80;
      day |= 0x80;
      break;
    case eEveryDay:  // Every day (at the specified hour and minute)
      day |= 0x80;
      break;
    case eEveryWeek:  // Every week (at the specified day of the week, hour and minute)
      dy = bin2bcd(dt.dayOfTheWeek());
      day = dy | 0x40;  // Bit 6 to indicate day of the week instead of day of the month.
      break;
    case eEveryMonth:  // Every month (at the specified day of the month, hour and minute)
      break;
    default:
      return;  // Invalid alarm type.
  }

  // Writes the alarm values to the corresponding registers.
  writeReg(DS3231M_REG_ALARM2_MIN, &min, 1);
  writeReg(DS3231M_REG_ALARM2_HOUR, &hour, 1);
  writeReg(DS3231M_REG_ALARM2_DAY, &day, 1);

  // Enables alarm 2 interrupt (A2IE) in the control register.
  uint8_t ctrl[1];
  readReg(DS3231M_REG_CTRL, ctrl, 1);
  ctrl[0] |= 0x02;  // Set A2IE bit
  writeReg(DS3231M_REG_CTRL, ctrl, 1);
}

float DS3231M::getTemp() {
  uint8_t temp[2];
  // Reads the two bytes from the temperature register.
  readReg(DS3231M_REG_TEMP, temp, 2);
  // Combines the bytes to obtain the temperature and converts it to float.
  return (float)temp[0] + ((temp[1] >> 6) * 0.25);
}

bool DS3231M::isAlarm() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);  // Reads the status register.
  return status[0] & 3;                    // Returns true if bits 0 (A1F) or 1 (A2F) are set.
}

void DS3231M::clearAlarm() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Reads the status register.
  status[0] &= 0xFC;                        // Clears bits A1F (bit 0) and A2F (bit 1).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Writes the new status value.
}

void DS3231M::enable32k() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Reads the status register.
  status[0] |= 0x08;                        // Sets the EN32kHz bit (bit 3).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Writes the new status value.
}

void DS3231M::disable32k() {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);   // Reads the status register.
  status[0] &= 0xF7;                        // Clears the EN32kHz bit (bit 3).
  writeReg(DS3231M_REG_STATUS, status, 1);  // Writes the new status value.
}

bool DS3231M::lostPower(void) {
  uint8_t status[1];
  readReg(DS3231M_REG_STATUS, status, 1);
  return status[0] >> 7;
}

void DS3231M::writeReg(uint8_t reg, const void* pBuf, size_t size) {
  if (pBuf == NULL) {
    // Prints a debug message if the pointer is null.
    DEBUG_ERROR("pBuf null pointer");
  }
  uint8_t* _pBuf = (uint8_t*)pBuf;  // Casts the pointer to uint8_t for iteration.

  _pWire->beginTransmission(DS3231M_IIC_ADDRESS);  // Starts I2C transmission to the DS3231M.
  _pWire->write(reg);                              // Sends the register address.
  for (size_t i = 0; i < size; i++) {
    _pWire->write(_pBuf[i]);  // Sends each byte from the buffer.
  }
  _pWire->endTransmission();  // Ends I2C transmission.
}

uint8_t DS3231M::readReg(uint8_t reg, const void* pBuf, size_t size) {
  if (pBuf == NULL) {
    // Prints a debug message if the pointer is null.
    DEBUG_ERROR("pBuf null pointer");
  }
  uint8_t* _pBuf = (uint8_t*)pBuf;  // Casts the pointer to uint8_t for iteration.

  _pWire->beginTransmission(DS3231M_IIC_ADDRESS);  // Starts I2C transmission to the DS3231M.
  _pWire->write(reg);                              // Sends the register address to read.
  _pWire->endTransmission(false);                  // Ends transmission but keeps the connection (repeated start).

  // Requests 'size' bytes from the DS3231M
  uint8_t i = 0;
  _pWire->requestFrom(DS3231M_IIC_ADDRESS, size);
  while (_pWire->available()) {
    if (i < size) {
      _pBuf[i++] = _pWire->read();  // Reads bytes and stores them in the buffer.
    } else {
      _pWire->read();  // Discards extra bytes if more than requested are read.
    }
  }
  return i;  // Returns the number of bytes read.
}

uint8_t DS3231M::bcd2bin(uint8_t val) {
  return val - 6 * (val >> 4);  // BCD to BIN conversion.
}

uint8_t DS3231M::bin2bcd(uint8_t val) {
  return val + 6 * (val / 10);  // BIN to BCD conversion.
}

uint8_t DS3231M::dayOfTheWeek(uint16_t y, uint8_t m, uint8_t d) const {
  // Implementation of Zeller's algorithm to calculate the day of the week.
  // k = day of the month
  // m = month (3=March, 4=April, ..., 12=December, 1=January, 2=February)
  // D = year of the century (e.g. for 2024, D=24)
  // C = century (e.g. for 2024, C=20)
  uint8_t k = d;
  uint8_t month = m;
  uint16_t year = y;

  if (month <= 2) {
    month += 12;
    year -= 1;
  }

  uint8_t D = year % 100;
  uint8_t C = year / 100;

  // Zeller's formula: h = (k + floor(2.6 * m - 0.2) + D + floor(D/4) + floor(C/4) - 2 * C) mod 7
  // The result is 0=Saturday, 1=Sunday, ..., 6=Friday.
  // Adjusted so that 1=Sunday, ..., 7=Saturday.
  uint8_t dayOfWeek = (k + (26 * (month + 1)) / 10 + D + D / 4 + C / 4 + 5 * C) % 7;
  return (dayOfWeek == 0) ? 7 : dayOfWeek;  // Adjusts so that Sunday is 7 or 1 depending on the convention.
}

