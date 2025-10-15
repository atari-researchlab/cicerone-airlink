/**
 * @file    DS3231M.h
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
 * @note This module is based on the DFRobot library for DS3231M
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

#ifndef _DS3231M_H
#define _DS3231M_H
#include <Arduino.h>
#include <Wire.h>

/**
 * @name  DS3231M register and constant definitions
 */
#define DS3231M_IIC_ADDRESS 0x68             //!< Default I2C address of DS3231M.
#define SECONDS_FROM_1970_TO_2000 946684800  //!< Constant to convert seconds from 1970 to seconds from 2000.
#define DS3231M_REG_RTC_SEC 0X00             //!< RTC seconds register.
#define DS3231M_REG_RTC_MIN 0X01             //!< RTC minutes register.
#define DS3231M_REG_RTC_HOUR 0X02            //!< RTC hours register.
#define DS3231M_REG_RTC_DAY 0X03             //!< RTC day of the week register.
#define DS3231M_REG_RTC_DATE 0X04            //!< RTC day of the month register.
#define DS3231M_REG_RTC_MONTH 0X05           //!< RTC month register.
#define DS3231M_REG_RTC_YEAR 0X06            //!< RTC year register.
#define DS3231M_REG_ALARM1_SEC 0X07          //!< Alarm 1 seconds register.
#define DS3231M_REG_ALARM1_MIN 0X08          //!< Alarm 1 minutes register.
#define DS3231M_REG_ALARM1_HOUR 0X09         //!< Alarm 1 hours register.
#define DS3231M_REG_ALARM1_DAY 0X0A          //!< Alarm 1 day/day of the week register.
#define DS3231M_REG_ALARM2_MIN 0X0B          //!< Alarm 2 minutes register.
#define DS3231M_REG_ALARM2_HOUR 0X0C         //!< Alarm 2 hours register.
#define DS3231M_REG_ALARM2_DAY 0X0D          //!< Alarm 2 day/day of the week register.
#define DS3231M_REG_CTRL 0X0E                //!< Control register.
#define DS3231M_REG_STATUS 0X0F              //!< Status register.
#define DS3231M_REG_TEMP 0X11                //!< Temperature register.
//!@}

/**
 * @brief Enumeration to define the available alarm types.
 */
typedef enum {
  eEverySecond,  //!< Alarm every second.
  eEveryMinute,  //!< Alarm every minute (at the specified second).
  eEveryHour,    //!< Alarm every hour (at the specified minute and second).
  eEveryDay,     //!< Alarm every day (at the specified hour, minute and second).
  eEveryWeek,    //!< Alarm every week (at the specified day of the week, hour, minute and second).
  eEveryMonth,   //!< Alarm every month (at the specified day of the month, hour, minute and second).
} eAlarmType_t;

/**
 * @brief Helper class to conveniently handle date and time.
 */
class DateTime {
public:
  /**
    * @brief Constructor of the DateTime class
    * @param y Year
    * @param m Month
    * @param d Day
    * @param hh Hours
    * @param mm Minutes
    * @param ss Seconds
    */
  DateTime(uint16_t y = 0, uint8_t m = 0, uint8_t d = 0, uint8_t hh = 0, uint8_t mm = 0, uint8_t ss = 0)
    : y(y), m(m), d(d), hh(hh), mm(mm), ss(ss){};

  /**
    * @brief Gets the year.
    * @return Year.
    */
  uint16_t year() const {
    return y;
  }
  /**
    * @brief Gets the month.
    * @return Month.
    */
  uint8_t month() const {
    return m;
  }
  /**
    * @brief Gets the day of the month.
    * @return Day of the month.
    */
  uint8_t day() const {
    return d;
  }
  /**
    * @brief Gets the hour.
    * @return Hour.
    */
  uint8_t hour() const {
    return hh;
  }
  /**
    * @brief Gets the minute.
    * @return Minute.
    */
  uint8_t minute() const {
    return mm;
  }
  /**
    * @brief Gets the second.
    * @return Second.
    */
  uint8_t second() const {
    return ss;
  }

  /**
    * @brief Calculates the day of the week.
    * @return Day of the week (1 = Sunday, 2 = Monday, ..., 7 = Saturday).
    */
  uint8_t dayOfTheWeek() const;

protected:
  uint16_t y;  //!< Year
  uint8_t m;   //!< Month
  uint8_t d;   //!< Day of the month
  uint8_t hh;  //!< Hours
  uint8_t mm;  //!< Minutes
  uint8_t ss;  //!< Seconds
};

/**
 * @brief Class for DS3231M RTC communication.
 */
class DS3231M {
public:
  /**
   * @brief Constructor of the DS3231M class.
   *
   * @param pWire   Peripheral used for I2C communication.
   */
  DS3231M(TwoWire* pWire = &Wire) {
    _pWire = pWire;
  };

  /**
   * @brief Destructor of the DS3231M class.
   */
  ~DS3231M(){};

  /**
   * @brief Initializes I2C communication.
   *
   * @return True if communication with the module succeeds, false if it fails.
   */
  bool begin(void);

  /**
   * @brief Sets the RTC time and date.
   *
   * @param year Year (e.g. 2024).
   * @param month Month (1-12).
   * @param day Day (1-31).
   * @param hour Hour (0-23).
   * @param minute Minute (0-59).
   * @param second Second (0-59).
   */
  void setRTCTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

  /**
   * @brief Gets the current RTC time.
   *
   * @return DateTime object containing the current time and date.
   */
  DateTime getRTCTime();

  /**
   * @brief Sets the first RTC alarm (alarm 1).
   *
   * @param dt DateTime object with the alarm time and date.
   * @param type Alarm type (e.g. every minute, every hour, every day, etc.).
   */
  void setAlarm1(const DateTime& dt, eAlarmType_t type);

  /**
   * @brief Sets the second RTC alarm (alarm 2).
   *
   * @param dt DateTime object with the alarm time and date.
   * @param type Alarm type (e.g. every minute, every hour, every day, etc.).
   */
  void setAlarm2(const DateTime& dt, eAlarmType_t type);

  /**
   * @brief Gets the current temperature from the DS3231M sensor.
   *
   * @return Temperature in degrees Celsius (float).
   */
  float getTemp();

  /**
   * @brief Checks if any alarm has been triggered.
   *
   * @return True if alarm 1 or alarm 2 has been triggered, false otherwise.
   */
  bool isAlarm();

  /**
   * @brief Clears the alarm flags in the status register.
   *
   * This is necessary after an alarm has been triggered so it can be activated again.
   */
  void clearAlarm();

  /**
   * @brief Enables the 32kHz square wave output on the SQW/INT pin.
   */
  void enable32k();

  /**
   * @brief Disables the 32kHz square wave output on the SQW/INT pin.
   */
  void disable32k();

  /**
   * @brief Checks if the RTC lost backup power.
   *
   * @return True if backup power was lost.
   */
  bool lostPower(void);

  uint8_t rtc[7];  //!< Array to store RTC time and date data.

protected:
  /**
   * @brief Writes data to a specific DS3231M register via I2C.
   *
   * @param reg Register address to write to.
   * @param pBuf Pointer to the data buffer to write.
   * @param size Number of bytes to write.
   */
  virtual void writeReg(uint8_t reg, const void* pBuf, size_t size);

  /**
   * @brief Reads data from a specific DS3231M register via I2C.
   *
   * @param reg Register address to read from.
   * @param pBuf Pointer to the buffer where read data will be stored.
   * @param size Number of bytes to read.
   * @return The number of bytes read (0 in case of error or if no bytes were read).
   */
  virtual uint8_t readReg(uint8_t reg, const void* pBuf, size_t size);

  /**
   * @brief Converts a BCD (Binary-Coded Decimal) value to BIN (Binary).
   *
   * @param val Value in BCD format.
   * @return Value in BIN format.
   */
  static uint8_t bcd2bin(uint8_t val);

  /**
   * @brief Converts a BIN (Binary) value to BCD (Binary-Coded Decimal).
   *
   * @param val Value in BIN format.
   * @return Value in BCD format.
   */
  static uint8_t bin2bcd(uint8_t val);

  /**
   * @brief Calculates the day of the week for a given date.
   *
   * @param y Year.
   * @param m Month.
   * @param d Day.
   * @return Day of the week (1 = Sunday, 2 = Monday, ..., 7 = Saturday).
   */
  uint8_t dayOfTheWeek(uint16_t y, uint8_t m, uint8_t d) const;

private:
  /**
   * @brief Pointer to the I2C peripheral used.
   */
  TwoWire* _pWire;

  /**
   * @brief I2C address of the RTC module.
   */
  uint8_t _deviceAddr = DS3231M_IIC_ADDRESS;

  /**
   * @brief Array to store the days of the week in text format.
   */
  const char* daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                  "Thursday", "Friday", "Saturday"};

  /**
   * @brief Array to store the hour type for 12-hour mode.
   */
  const char* hourOfAM[4] = { "", "", "AM", "PM" };
};

#endif  // _DS3231M_H
