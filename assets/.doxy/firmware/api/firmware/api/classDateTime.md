

# Class DateTime



[**ClassList**](annotated.md) **>** [**DateTime**](classDateTime.md)



_Helper class to conveniently handle date and time._ 

* `#include <DS3231M.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DateTime**](#function-datetime) (uint16\_t y=0, uint8\_t m=0, uint8\_t d=0, uint8\_t hh=0, uint8\_t mm=0, uint8\_t ss=0) <br>_Constructor of the_ [_**DateTime**_](classDateTime.md) _class._ |
|  uint8\_t | [**day**](#function-day) () const<br>_Gets the day of the month._  |
|  uint8\_t | [**dayOfTheWeek**](#function-dayoftheweek) () const<br>_Calculates the day of the week._  |
|  uint8\_t | [**hour**](#function-hour) () const<br>_Gets the hour._  |
|  uint8\_t | [**minute**](#function-minute) () const<br>_Gets the minute._  |
|  uint8\_t | [**month**](#function-month) () const<br>_Gets the month._  |
|  uint8\_t | [**second**](#function-second) () const<br>_Gets the second._  |
|  uint16\_t | [**year**](#function-year) () const<br>_Gets the year._  |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**d**](#variable-d)  <br>_Day of the month._  |
|  uint8\_t | [**hh**](#variable-hh)  <br>_Hours._  |
|  uint8\_t | [**m**](#variable-m)  <br>_Month._  |
|  uint8\_t | [**mm**](#variable-mm)  <br>_Minutes._  |
|  uint8\_t | [**ss**](#variable-ss)  <br>_Seconds._  |
|  uint16\_t | [**y**](#variable-y)  <br>_Year._  |




















## Public Functions Documentation




### function DateTime 

_Constructor of the_ [_**DateTime**_](classDateTime.md) _class._
```C++
inline DateTime::DateTime (
    uint16_t y=0,
    uint8_t m=0,
    uint8_t d=0,
    uint8_t hh=0,
    uint8_t mm=0,
    uint8_t ss=0
) 
```





**Parameters:**


* `y` Year 
* `m` Month 
* `d` Day 
* `hh` Hours 
* `mm` Minutes 
* `ss` Seconds 




        

<hr>



### function day 

_Gets the day of the month._ 
```C++
inline uint8_t DateTime::day () const
```





**Returns:**

Day of the month. 





        

<hr>



### function dayOfTheWeek 

_Calculates the day of the week._ 
```C++
uint8_t DateTime::dayOfTheWeek () const
```





**Returns:**

Day of the week (1 = Sunday, 2 = Monday, ..., 7 = Saturday). 





        

<hr>



### function hour 

_Gets the hour._ 
```C++
inline uint8_t DateTime::hour () const
```





**Returns:**

Hour. 





        

<hr>



### function minute 

_Gets the minute._ 
```C++
inline uint8_t DateTime::minute () const
```





**Returns:**

Minute. 





        

<hr>



### function month 

_Gets the month._ 
```C++
inline uint8_t DateTime::month () const
```





**Returns:**

Month. 





        

<hr>



### function second 

_Gets the second._ 
```C++
inline uint8_t DateTime::second () const
```





**Returns:**

Second. 





        

<hr>



### function year 

_Gets the year._ 
```C++
inline uint16_t DateTime::year () const
```





**Returns:**

Year. 





        

<hr>
## Protected Attributes Documentation




### variable d 

_Day of the month._ 
```C++
uint8_t DateTime::d;
```




<hr>



### variable hh 

_Hours._ 
```C++
uint8_t DateTime::hh;
```




<hr>



### variable m 

_Month._ 
```C++
uint8_t DateTime::m;
```




<hr>



### variable mm 

_Minutes._ 
```C++
uint8_t DateTime::mm;
```




<hr>



### variable ss 

_Seconds._ 
```C++
uint8_t DateTime::ss;
```




<hr>



### variable y 

_Year._ 
```C++
uint16_t DateTime::y;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/DS3231M.h`

