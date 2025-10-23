

# File Datetime\_helper.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Datetime\_helper.h**](Datetime__helper_8h.md)

[Go to the source code of this file](Datetime__helper_8h_source.md)

_Preprocessor macros to convert_ `__DATE__` _and_`__TIME__` _macros into numeric values for the RTC._[More...](#detailed-description)

































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**BUILD\_DAY**](Datetime__helper_8h.md#define-build_day)  `/* multi line expression */`<br>_Extracts the day from the_ `__DATE__` _string (e.g.: "Jul 22 2024" -&gt; 22). Handles the case where the day has a single digit (e.g.: "Jul  7 2024")._ |
| define  | [**BUILD\_HOUR**](Datetime__helper_8h.md#define-build_hour)  `((\_\_TIME\_\_[0] - '0') \* 10 + (\_\_TIME\_\_[1] - '0'))`<br>_Extracts the hour from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 18)._ |
| define  | [**BUILD\_MIN**](Datetime__helper_8h.md#define-build_min)  `((\_\_TIME\_\_[3] - '0') \* 10 + (\_\_TIME\_\_[4] - '0'))`<br>_Extracts the minute from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 30)._ |
| define  | [**BUILD\_MONTH**](Datetime__helper_8h.md#define-build_month)  `/* multi line expression */`<br>_Converts the text month to number (e.g.: "Jan" -&gt; 1, "Feb" -&gt; 2, etc)._  |
| define  | [**BUILD\_SEC**](Datetime__helper_8h.md#define-build_sec)  `((\_\_TIME\_\_[6] - '0') \* 10 + (\_\_TIME\_\_[7] - '0'))`<br>_Extracts the second from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 00)._ |
| define  | [**BUILD\_YEAR**](Datetime__helper_8h.md#define-build_year)  `/* multi line expression */`<br>_Extracts the year from the_ `__DATE__` _string (e.g.: "Jul 22 2024" -&gt; 2024)._ |

## Detailed Description


This file is a utility that allows setting the RTC clock time automatically to the time when the program was compiled. No modification is necessary.


Example of `__DATE__:` "Jul 22 2024"


Example of `__TIME__:` "18:30:00"




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later 





    
## Macro Definition Documentation





### define BUILD\_DAY 

_Extracts the day from the_ `__DATE__` _string (e.g.: "Jul 22 2024" -&gt; 22). Handles the case where the day has a single digit (e.g.: "Jul  7 2024")._
```C++
#define BUILD_DAY `/* multi line expression */`
```




<hr>



### define BUILD\_HOUR 

_Extracts the hour from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 18)._
```C++
#define BUILD_HOUR `((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))`
```




<hr>



### define BUILD\_MIN 

_Extracts the minute from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 30)._
```C++
#define BUILD_MIN `((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))`
```




<hr>



### define BUILD\_MONTH 

_Converts the text month to number (e.g.: "Jan" -&gt; 1, "Feb" -&gt; 2, etc)._ 
```C++
#define BUILD_MONTH `/* multi line expression */`
```




<hr>



### define BUILD\_SEC 

_Extracts the second from the_ `__TIME__` _string (e.g.: "18:30:00" -&gt; 00)._
```C++
#define BUILD_SEC `((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))`
```




<hr>



### define BUILD\_YEAR 

_Extracts the year from the_ `__DATE__` _string (e.g.: "Jul 22 2024" -&gt; 2024)._
```C++
#define BUILD_YEAR `/* multi line expression */`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Datetime_helper.h`

