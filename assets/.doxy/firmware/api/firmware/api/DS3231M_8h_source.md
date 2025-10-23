

# File DS3231M.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**DS3231M.h**](DS3231M_8h.md)

[Go to the documentation of this file](DS3231M_8h.md)


```C++


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

#define DS3231M_IIC_ADDRESS 0x68             
#define SECONDS_FROM_1970_TO_2000 946684800  
#define DS3231M_REG_RTC_SEC 0X00             
#define DS3231M_REG_RTC_MIN 0X01             
#define DS3231M_REG_RTC_HOUR 0X02            
#define DS3231M_REG_RTC_DAY 0X03             
#define DS3231M_REG_RTC_DATE 0X04            
#define DS3231M_REG_RTC_MONTH 0X05           
#define DS3231M_REG_RTC_YEAR 0X06            
#define DS3231M_REG_ALARM1_SEC 0X07          
#define DS3231M_REG_ALARM1_MIN 0X08          
#define DS3231M_REG_ALARM1_HOUR 0X09         
#define DS3231M_REG_ALARM1_DAY 0X0A          
#define DS3231M_REG_ALARM2_MIN 0X0B          
#define DS3231M_REG_ALARM2_HOUR 0X0C         
#define DS3231M_REG_ALARM2_DAY 0X0D          
#define DS3231M_REG_CTRL 0X0E                
#define DS3231M_REG_STATUS 0X0F              
#define DS3231M_REG_TEMP 0X11                

typedef enum {
  eEverySecond,  
  eEveryMinute,  
  eEveryHour,    
  eEveryDay,     
  eEveryWeek,    
  eEveryMonth,   
} eAlarmType_t;

class DateTime {
public:
  DateTime(uint16_t y = 0, uint8_t m = 0, uint8_t d = 0, uint8_t hh = 0, uint8_t mm = 0, uint8_t ss = 0)
    : y(y), m(m), d(d), hh(hh), mm(mm), ss(ss){};

  uint16_t year() const {
    return y;
  }
  uint8_t month() const {
    return m;
  }
  uint8_t day() const {
    return d;
  }
  uint8_t hour() const {
    return hh;
  }
  uint8_t minute() const {
    return mm;
  }
  uint8_t second() const {
    return ss;
  }

  uint8_t dayOfTheWeek() const;

protected:
  uint16_t y;  
  uint8_t m;   
  uint8_t d;   
  uint8_t hh;  
  uint8_t mm;  
  uint8_t ss;  
};

class DS3231M {
public:
  DS3231M(TwoWire* pWire = &Wire) {
    _pWire = pWire;
  };

  ~DS3231M(){};

  bool begin(void);

  void setRTCTime(uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);

  DateTime getRTCTime();

  void setAlarm1(const DateTime& dt, eAlarmType_t type);

  void setAlarm2(const DateTime& dt, eAlarmType_t type);

  float getTemp();

  bool isAlarm();

  void clearAlarm();

  void enable32k();

  void disable32k();

  bool lostPower(void);

  uint8_t rtc[7];  

protected:
  virtual void writeReg(uint8_t reg, const void* pBuf, size_t size);

  virtual uint8_t readReg(uint8_t reg, const void* pBuf, size_t size);

  static uint8_t bcd2bin(uint8_t val);

  static uint8_t bin2bcd(uint8_t val);

  uint8_t dayOfTheWeek(uint16_t y, uint8_t m, uint8_t d) const;

private:
  TwoWire* _pWire;

  uint8_t _deviceAddr = DS3231M_IIC_ADDRESS;

  const char* daysOfTheWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                  "Thursday", "Friday", "Saturday"};

  const char* hourOfAM[4] = { "", "", "AM", "PM" };
};

#endif  // _DS3231M_H
```


