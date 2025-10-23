

# File Debug.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Debug.h**](Debug_8h.md)

[Go to the source code of this file](Debug_8h_source.md)

_Header for debug message management._ [More...](#detailed-description)

* `#include <Arduino.h>`
* `#include <stdarg.h>`
* `#include <stdio.h>`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  char | [**debug\_printf\_buffer**](#variable-debug_printf_buffer)  <br>_Buffer for formatted debug messages._  |









































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_ALARMA**](Debug_8h.md#define-debug_alarma)  `2`<br>_Controls debug information for acquisition and averaging loop._  |
| define  | [**DEBUG\_DS3231M**](Debug_8h.md#define-debug_ds3231m)  `2`<br>_Controls debug information for RTC._  |
| define  | [**DEBUG\_ERROR**](Debug_8h.md#define-debug_error) (format, ...) `/* multi line expression */`<br>_DEBUG\_LEVEL &gt;= 1._  |
| define  | [**DEBUG\_INFO**](Debug_8h.md#define-debug_info) (format, ...) `/* multi line expression */`<br>_DEBUG\_LEVEL &gt;= 3._  |
| define  | [**DEBUG\_LEVEL**](Debug_8h.md#define-debug_level)  `3`<br>_Global debug level._  |
| define  | [**DEBUG\_NBIOT**](Debug_8h.md#define-debug_nbiot)  `2`<br>_Controls debug information for NB-IoT module._  |
| define  | [**DEBUG\_PRINTF\_BUFFER\_SIZE**](Debug_8h.md#define-debug_printf_buffer_size)  `256`<br>_Adjust size according to expected maximum message length._  |
| define  | [**DEBUG\_SEN5X**](Debug_8h.md#define-debug_sen5x)  `2`<br>_Controls debug information for SEN5X sensor._  |
| define  | [**DEBUG\_T6793**](Debug_8h.md#define-debug_t6793)  `2`<br>_Controls debug information for T6793K sensor (CO2)._  |
| define  | [**DEBUG\_VERBOSE**](Debug_8h.md#define-debug_verbose) (format, ...) `/* multi line expression */`<br>_DEBUG\_LEVEL &gt;= 4._  |
| define  | [**DEBUG\_WARN**](Debug_8h.md#define-debug_warn) (format, ...) `/* multi line expression */`<br>_DEBUG\_LEVEL &gt;= 2._  |
| define  | [**TEST\_MINUTAL**](Debug_8h.md#define-test_minutal)  `1`<br>_Uncomment the following line to enable per-minute average transmission._  |

## Detailed Description


Defines a set of macros that allow printing messages to the serial port depending on a debug level set in "Configuracion.h".




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

1.0




**Copyright:**

GNU General Public License version 3 or later 





    
## Public Static Attributes Documentation




### variable debug\_printf\_buffer 

_Buffer for formatted debug messages._ 
```C++
char debug_printf_buffer[DEBUG_PRINTF_BUFFER_SIZE];
```




<hr>
## Macro Definition Documentation





### define DEBUG\_ALARMA 

_Controls debug information for acquisition and averaging loop._ 
```C++
#define DEBUG_ALARMA `2`
```




<hr>



### define DEBUG\_DS3231M 

_Controls debug information for RTC._ 
```C++
#define DEBUG_DS3231M `2`
```




<hr>



### define DEBUG\_ERROR 

_DEBUG\_LEVEL &gt;= 1._ 
```C++
#define DEBUG_ERROR (
    format,
    ...
) `/* multi line expression */`
```




<hr>



### define DEBUG\_INFO 

_DEBUG\_LEVEL &gt;= 3._ 
```C++
#define DEBUG_INFO (
    format,
    ...
) `/* multi line expression */`
```




<hr>



### define DEBUG\_LEVEL 

_Global debug level._ 
```C++
#define DEBUG_LEVEL `3`
```




<hr>



### define DEBUG\_NBIOT 

_Controls debug information for NB-IoT module._ 
```C++
#define DEBUG_NBIOT `2`
```




<hr>



### define DEBUG\_PRINTF\_BUFFER\_SIZE 

_Adjust size according to expected maximum message length._ 
```C++
#define DEBUG_PRINTF_BUFFER_SIZE `256`
```




<hr>



### define DEBUG\_SEN5X 

_Controls debug information for SEN5X sensor._ 
```C++
#define DEBUG_SEN5X `2`
```




<hr>



### define DEBUG\_T6793 

_Controls debug information for T6793K sensor (CO2)._ 
```C++
#define DEBUG_T6793 `2`
```




<hr>



### define DEBUG\_VERBOSE 

_DEBUG\_LEVEL &gt;= 4._ 
```C++
#define DEBUG_VERBOSE (
    format,
    ...
) `/* multi line expression */`
```




<hr>



### define DEBUG\_WARN 

_DEBUG\_LEVEL &gt;= 2._ 
```C++
#define DEBUG_WARN (
    format,
    ...
) `/* multi line expression */`
```




<hr>



### define TEST\_MINUTAL 

_Uncomment the following line to enable per-minute average transmission._ 
```C++
#define TEST_MINUTAL `1`
```



Useful for debugging message sending or sensor communication. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Debug.h`

