

# Class DS3231M



[**ClassList**](annotated.md) **>** [**DS3231M**](classDS3231M.md)



_Class for_ [_**DS3231M**_](classDS3231M.md) _RTC communication._

* `#include <DS3231M.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**rtc**](#variable-rtc)  <br>_Array to store RTC time and date data._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DS3231M**](#function-ds3231m) (TwoWire \* pWire=&Wire) <br>_Constructor of the_ [_**DS3231M**_](classDS3231M.md) _class._ |
|  bool | [**begin**](#function-begin) (void) <br>_Initializes I2C communication._  |
|  void | [**clearAlarm**](#function-clearalarm) () <br>_Clears the alarm flags in the status register._  |
|  void | [**disable32k**](#function-disable32k) () <br>_Disables the 32kHz square wave output on the SQW/INT pin._  |
|  void | [**enable32k**](#function-enable32k) () <br>_Enables the 32kHz square wave output on the SQW/INT pin._  |
|  [**DateTime**](classDateTime.md) | [**getRTCTime**](#function-getrtctime) () <br>_Gets the current RTC time._  |
|  float | [**getTemp**](#function-gettemp) () <br>_Gets the current temperature from the_ [_**DS3231M**_](classDS3231M.md) _sensor._ |
|  bool | [**isAlarm**](#function-isalarm) () <br>_Checks if any alarm has been triggered._  |
|  bool | [**lostPower**](#function-lostpower) (void) <br>_Checks if the RTC lost backup power._  |
|  void | [**setAlarm1**](#function-setalarm1) (const [**DateTime**](classDateTime.md) & dt, [**eAlarmType\_t**](DS3231M_8h.md#enum-ealarmtype_t) type) <br>_Sets the first RTC alarm (alarm 1)._  |
|  void | [**setAlarm2**](#function-setalarm2) (const [**DateTime**](classDateTime.md) & dt, [**eAlarmType\_t**](DS3231M_8h.md#enum-ealarmtype_t) type) <br>_Sets the second RTC alarm (alarm 2)._  |
|  void | [**setRTCTime**](#function-setrtctime) (uint16\_t year, uint8\_t month, uint8\_t day, uint8\_t hour, uint8\_t minute, uint8\_t second) <br>_Sets the RTC time and date._  |
|   | [**~DS3231M**](#function-ds3231m) () <br>_Destructor of the_ [_**DS3231M**_](classDS3231M.md) _class._ |
























## Protected Functions

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**dayOfTheWeek**](#function-dayoftheweek) (uint16\_t y, uint8\_t m, uint8\_t d) const<br>_Calculates the day of the week for a given date._  |
| virtual uint8\_t | [**readReg**](#function-readreg) (uint8\_t reg, const void \* pBuf, size\_t size) <br>_Reads data from a specific_ [_**DS3231M**_](classDS3231M.md) _register via I2C._ |
| virtual void | [**writeReg**](#function-writereg) (uint8\_t reg, const void \* pBuf, size\_t size) <br>_Writes data to a specific_ [_**DS3231M**_](classDS3231M.md) _register via I2C._ |


## Protected Static Functions

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**bcd2bin**](#function-bcd2bin) (uint8\_t val) <br>_Converts a BCD (Binary-Coded Decimal) value to BIN (Binary)._  |
|  uint8\_t | [**bin2bcd**](#function-bin2bcd) (uint8\_t val) <br>_Converts a BIN (Binary) value to BCD (Binary-Coded Decimal)._  |


## Public Attributes Documentation




### variable rtc 

_Array to store RTC time and date data._ 
```C++
uint8_t DS3231M::rtc[7];
```




<hr>
## Public Functions Documentation




### function DS3231M 

_Constructor of the_ [_**DS3231M**_](classDS3231M.md) _class._
```C++
inline DS3231M::DS3231M (
    TwoWire * pWire=&Wire
) 
```





**Parameters:**


* `pWire` Peripheral used for I2C communication. 




        

<hr>



### function begin 

_Initializes I2C communication._ 
```C++
bool DS3231M::begin (
    void
) 
```





**Returns:**

True if communication with the module succeeds, false if it fails. 





        

<hr>



### function clearAlarm 

_Clears the alarm flags in the status register._ 
```C++
void DS3231M::clearAlarm () 
```



This is necessary after an alarm has been triggered so it can be activated again. 


        

<hr>



### function disable32k 

_Disables the 32kHz square wave output on the SQW/INT pin._ 
```C++
void DS3231M::disable32k () 
```




<hr>



### function enable32k 

_Enables the 32kHz square wave output on the SQW/INT pin._ 
```C++
void DS3231M::enable32k () 
```




<hr>



### function getRTCTime 

_Gets the current RTC time._ 
```C++
DateTime DS3231M::getRTCTime () 
```





**Returns:**

[**DateTime**](classDateTime.md) object containing the current time and date. 





        

<hr>



### function getTemp 

_Gets the current temperature from the_ [_**DS3231M**_](classDS3231M.md) _sensor._
```C++
float DS3231M::getTemp () 
```





**Returns:**

Temperature in degrees Celsius (float). 





        

<hr>



### function isAlarm 

_Checks if any alarm has been triggered._ 
```C++
bool DS3231M::isAlarm () 
```





**Returns:**

True if alarm 1 or alarm 2 has been triggered, false otherwise. 





        

<hr>



### function lostPower 

_Checks if the RTC lost backup power._ 
```C++
bool DS3231M::lostPower (
    void
) 
```





**Returns:**

True if backup power was lost. 





        

<hr>



### function setAlarm1 

_Sets the first RTC alarm (alarm 1)._ 
```C++
void DS3231M::setAlarm1 (
    const DateTime & dt,
    eAlarmType_t type
) 
```





**Parameters:**


* `dt` [**DateTime**](classDateTime.md) object with the alarm time and date. 
* `type` Alarm type (e.g. every minute, every hour, every day, etc.). 




        

<hr>



### function setAlarm2 

_Sets the second RTC alarm (alarm 2)._ 
```C++
void DS3231M::setAlarm2 (
    const DateTime & dt,
    eAlarmType_t type
) 
```





**Parameters:**


* `dt` [**DateTime**](classDateTime.md) object with the alarm time and date. 
* `type` Alarm type (e.g. every minute, every hour, every day, etc.). 




        

<hr>



### function setRTCTime 

_Sets the RTC time and date._ 
```C++
void DS3231M::setRTCTime (
    uint16_t year,
    uint8_t month,
    uint8_t day,
    uint8_t hour,
    uint8_t minute,
    uint8_t second
) 
```





**Parameters:**


* `year` Year (e.g. 2024). 
* `month` Month (1-12). 
* `day` Day (1-31). 
* `hour` Hour (0-23). 
* `minute` Minute (0-59). 
* `second` Second (0-59). 




        

<hr>



### function ~DS3231M 

_Destructor of the_ [_**DS3231M**_](classDS3231M.md) _class._
```C++
inline DS3231M::~DS3231M () 
```




<hr>
## Protected Functions Documentation




### function dayOfTheWeek 

_Calculates the day of the week for a given date._ 
```C++
uint8_t DS3231M::dayOfTheWeek (
    uint16_t y,
    uint8_t m,
    uint8_t d
) const
```





**Parameters:**


* `y` Year. 
* `m` Month. 
* `d` Day. 



**Returns:**

Day of the week (1 = Sunday, 2 = Monday, ..., 7 = Saturday). 





        

<hr>



### function readReg 

_Reads data from a specific_ [_**DS3231M**_](classDS3231M.md) _register via I2C._
```C++
virtual uint8_t DS3231M::readReg (
    uint8_t reg,
    const void * pBuf,
    size_t size
) 
```





**Parameters:**


* `reg` Register address to read from. 
* `pBuf` Pointer to the buffer where read data will be stored. 
* `size` Number of bytes to read. 



**Returns:**

The number of bytes read (0 in case of error or if no bytes were read). 





        

<hr>



### function writeReg 

_Writes data to a specific_ [_**DS3231M**_](classDS3231M.md) _register via I2C._
```C++
virtual void DS3231M::writeReg (
    uint8_t reg,
    const void * pBuf,
    size_t size
) 
```





**Parameters:**


* `reg` Register address to write to. 
* `pBuf` Pointer to the data buffer to write. 
* `size` Number of bytes to write. 




        

<hr>
## Protected Static Functions Documentation




### function bcd2bin 

_Converts a BCD (Binary-Coded Decimal) value to BIN (Binary)._ 
```C++
static uint8_t DS3231M::bcd2bin (
    uint8_t val
) 
```





**Parameters:**


* `val` Value in BCD format. 



**Returns:**

Value in BIN format. 





        

<hr>



### function bin2bcd 

_Converts a BIN (Binary) value to BCD (Binary-Coded Decimal)._ 
```C++
static uint8_t DS3231M::bin2bcd (
    uint8_t val
) 
```





**Parameters:**


* `val` Value in BIN format. 



**Returns:**

Value in BCD format. 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/DS3231M.h`

