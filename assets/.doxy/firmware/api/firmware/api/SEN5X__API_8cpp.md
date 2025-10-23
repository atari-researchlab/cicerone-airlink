

# File SEN5X\_API.cpp



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**SEN5X\_API.cpp**](SEN5X__API_8cpp.md)

[Go to the source code of this file](SEN5X__API_8cpp_source.md)

_Implementation of functions for reading and initializing the SEN5X sensor._ [More...](#detailed-description)

* `#include <SensirionI2CSen5x.h>`
* `#include "SEN5X_API.h"`
* `#include "Debug.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  SensirionI2CSen5x | [**sen5x**](#variable-sen5x)  <br>_Instance of Sensirion library object for the SEN5X sensor._  |
|  float | [**sen5x\_hum**](#variable-sen5x_hum)   = `0.0f`<br>_Relative humidity._  |
|  float | [**sen5x\_mc\_10p0**](#variable-sen5x_mc_10p0)   = `0.0f`<br>_PM10 mass concentration._  |
|  float | [**sen5x\_mc\_1p0**](#variable-sen5x_mc_1p0)   = `0.0f`<br>_PM1.0 mass concentration._  |
|  float | [**sen5x\_mc\_2p5**](#variable-sen5x_mc_2p5)   = `0.0f`<br>_PM2.5 mass concentration._  |
|  float | [**sen5x\_mc\_4p0**](#variable-sen5x_mc_4p0)   = `0.0f`<br>_PM4.0 mass concentration._  |
|  float | [**sen5x\_nox**](#variable-sen5x_nox)   = `0.0f`<br>_Nitrogen Oxides (NOx) index._  |
|  float | [**sen5x\_temp**](#variable-sen5x_temp)   = `0.0f`<br>_Temperature._  |
|  float | [**sen5x\_voc**](#variable-sen5x_voc)   = `0.0f`<br>_Volatile Organic Compounds (VOC) index._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**sen5x\_inicializar**](#function-sen5x_inicializar) (void) <br>_Initializes the SEN5X sensor._  |
|  bool | [**sen5x\_leer**](#function-sen5x_leer) (void) <br>_Reads the latest data measured by the sensor and updates the global variables_ `sen5x_*` _with the new values._ |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_LEVEL**](SEN5X__API_8cpp.md#define-debug_level)  `[**DEBUG\_SEN5X**](Debug_8h.md#define-debug_sen5x)`<br>_Redefinition of debug level for this source file._  |
| define  | [**DEBUG\_TAG**](SEN5X__API_8cpp.md#define-debug_tag)  `"SEN5X\_API"`<br>_Tag when sending debug messages._  |

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

This module is an abstraction layer over the SensirionI2CSen5x library. 





    
## Public Attributes Documentation




### variable sen5x 

_Instance of Sensirion library object for the SEN5X sensor._ 
```C++
SensirionI2CSen5x sen5x;
```




<hr>



### variable sen5x\_hum 

_Relative humidity._ 
```C++
float sen5x_hum;
```




<hr>



### variable sen5x\_mc\_10p0 

_PM10 mass concentration._ 
```C++
float sen5x_mc_10p0;
```




<hr>



### variable sen5x\_mc\_1p0 

_PM1.0 mass concentration._ 
```C++
float sen5x_mc_1p0;
```




<hr>



### variable sen5x\_mc\_2p5 

_PM2.5 mass concentration._ 
```C++
float sen5x_mc_2p5;
```




<hr>



### variable sen5x\_mc\_4p0 

_PM4.0 mass concentration._ 
```C++
float sen5x_mc_4p0;
```




<hr>



### variable sen5x\_nox 

_Nitrogen Oxides (NOx) index._ 
```C++
float sen5x_nox;
```




<hr>



### variable sen5x\_temp 

_Temperature._ 
```C++
float sen5x_temp;
```




<hr>



### variable sen5x\_voc 

_Volatile Organic Compounds (VOC) index._ 
```C++
float sen5x_voc;
```




<hr>
## Public Functions Documentation




### function sen5x\_inicializar 

_Initializes the SEN5X sensor._ 
```C++
void sen5x_inicializar (
    void
) 
```



Searches for the sensor on the I2C bus, resets it, and starts measurements. 


        

<hr>



### function sen5x\_leer 

_Reads the latest data measured by the sensor and updates the global variables_ `sen5x_*` _with the new values._
```C++
bool sen5x_leer (
    void
) 
```





**Returns:**

True if the reading was successful 





        

<hr>
## Macro Definition Documentation





### define DEBUG\_LEVEL 

_Redefinition of debug level for this source file._ 
```C++
#define DEBUG_LEVEL `DEBUG_SEN5X`
```




<hr>



### define DEBUG\_TAG 

_Tag when sending debug messages._ 
```C++
#define DEBUG_TAG `"SEN5X_API"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/SEN5X_API.cpp`

