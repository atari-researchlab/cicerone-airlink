/***********************************************************************************************************************
 * @file        T67XX.h
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

#ifndef T67XX_H
#define T67XX_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Wire.h"

#define T67XX_I2C_ADDR 0x15
#define T67XX_REG_VAL_ENABLE 0xFF00
#define T67XX_REG_VAL_DISABLE 0x0000

#define T67XX_READ_DELAY 10       // Recommended value
#define T67XX_MEASURE_DELAY 2250  // Recommended value
#define ABC_LOGIC_ON true
#define ABC_LOGIC_OFF false

// Registers
enum {
  T67XX_REG_FIRMWARE = 0x1389,
  T67XX_REG_STATUS = 0x138A,
  T67XX_REG_PPM = 0x138B,
  T67XX_REG_RESET = 0x03E8,
  T67XX_REG_SPCAL = 0x03EC,
  T67XX_REG_FLASH_UPDATE = 0x03ED,
  T67XX_REG_ADDRESS = 0x0FA5,
  T67XX_REG_ABC_LOGIC = 0x03EE,
  T67XX_REG_MOD_MODE = 0x100B
};

class T67XX {
public:
  T67XX();
  bool begin(void);
  bool begin(uint8_t Address);
  uint16_t readPPM(void);
  uint16_t getStatus(void);
  uint16_t getFirmwareVersion(void);
  void reset(void);
  void setABCMode(bool ABCMode);
  uint8_t setSlaveAddress(uint8_t Address);
  void flashUpdate(void);
  bool beginCalibration(void);
  bool beginCalibration(bool waitForCompletion);
  bool endCalibration(void);

  // 0: no error; 1: error has occurred
  struct status {
    uint16_t ERROR : 1;
    uint16_t FLASH_ERROR : 1;
    uint16_t CALIBRATION_ERROR : 1;
    uint16_t REBOOT : 1;
    uint16_t WARMUP : 1;
    uint16_t SINGLE_POINT_CAL : 1;
    uint16_t STA : 16;

    void set(uint16_t data) {
      STA = data;
      ERROR = data & 0x01;
      FLASH_ERROR = (data >> 0x01) & 0x01;
      CALIBRATION_ERROR = (data >> 0x02) & 0x01;
      REBOOT = (data >> 0x0A) & 0x01;
      WARMUP = (data >> 0x0B) & 0x01;
      SINGLE_POINT_CAL = (data >> 0x0F) & 0x01;
    }
  };

  String getStatusMsg(void);

private:
  uint8_t _data[6];
  uint16_t read16(uint16_t addr);
  void write8(uint16_t addr, uint8_t data);
  void write16(uint16_t addr, uint16_t data);

  // The status register
  status _status;
  uint8_t _address = T67XX_I2C_ADDR;
};

#endif  // T67XX_H
