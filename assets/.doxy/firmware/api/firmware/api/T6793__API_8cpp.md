

# File T6793\_API.cpp



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T6793\_API.cpp**](T6793__API_8cpp.md)

[Go to the source code of this file](T6793__API_8cpp_source.md)

_Implementation of the API for the Telaire T6793-5K CO2 sensor._ [More...](#detailed-description)

* `#include "T6793_API.h"`
* `#include "T67XX.h"`
* `#include "Debug.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  uint16\_t | [**t6793\_co2**](#variable-t6793_co2)   = `0`<br>_Definition of the global variable._  |
|  [**T67XX**](classT67XX.md) | [**t6793\_sensor**](#variable-t6793_sensor)  <br>_Instance of the library object for the sensor._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**t6793\_inicializar**](#function-t6793_inicializar) (void) <br>_Initializes the T6793 sensor, configures I2C communication and disables ABC calibration._  |
|  bool | [**t6793\_leer**](#function-t6793_leer) (void) <br>_Reads the CO2 value from the sensor and updates the global variable 't6793\_co2'._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_LEVEL**](T6793__API_8cpp.md#define-debug_level)  `[**DEBUG\_T6793**](Debug_8h.md#define-debug_t6793)`<br>_Redefinition of debug level for this source file._  |
| define  | [**DEBUG\_TAG**](T6793__API_8cpp.md#define-debug_tag)  `"T6793\_API"`<br>_Tag when sending debug messages._  |

## Detailed Description




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later




**Note:**

This module is an abstraction layer over the [**T67XX**](classT67XX.md) library. 





    
## Public Attributes Documentation




### variable t6793\_co2 

_Definition of the global variable._ 
```C++
uint16_t t6793_co2;
```




<hr>



### variable t6793\_sensor 

_Instance of the library object for the sensor._ 
```C++
T67XX t6793_sensor;
```




<hr>
## Public Functions Documentation




### function t6793\_inicializar 

_Initializes the T6793 sensor, configures I2C communication and disables ABC calibration._ 
```C++
void t6793_inicializar (
    void
) 
```




<hr>



### function t6793\_leer 

_Reads the CO2 value from the sensor and updates the global variable 't6793\_co2'._ 
```C++
bool t6793_leer (
    void
) 
```





**Returns:**

True if the reading was successful. 





        

<hr>
## Macro Definition Documentation





### define DEBUG\_LEVEL 

_Redefinition of debug level for this source file._ 
```C++
#define DEBUG_LEVEL `DEBUG_T6793`
```




<hr>



### define DEBUG\_TAG 

_Tag when sending debug messages._ 
```C++
#define DEBUG_TAG `"T6793_API"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/T6793_API.cpp`

