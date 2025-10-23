

# File SEN5X\_API.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**SEN5X\_API.h**](SEN5X__API_8h.md)

[Go to the source code of this file](SEN5X__API_8h_source.md)

_Header for the Sensirion SEN5X sensor API._ [More...](#detailed-description)

* `#include <Arduino.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  float | [**sen5x\_hum**](#variable-sen5x_hum)  <br>_Relative humidity._  |
|  float | [**sen5x\_mc\_10p0**](#variable-sen5x_mc_10p0)  <br>_PM10 mass concentration._  |
|  float | [**sen5x\_mc\_1p0**](#variable-sen5x_mc_1p0)  <br>_PM1.0 mass concentration._  |
|  float | [**sen5x\_mc\_2p5**](#variable-sen5x_mc_2p5)  <br>_PM2.5 mass concentration._  |
|  float | [**sen5x\_mc\_4p0**](#variable-sen5x_mc_4p0)  <br>_PM4.0 mass concentration._  |
|  float | [**sen5x\_nox**](#variable-sen5x_nox)  <br>_Nitrogen Oxides (NOx) index._  |
|  float | [**sen5x\_temp**](#variable-sen5x_temp)  <br>_Temperature._  |
|  float | [**sen5x\_voc**](#variable-sen5x_voc)  <br>_Volatile Organic Compounds (VOC) index._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**sen5x\_inicializar**](#function-sen5x_inicializar) (void) <br>_Initializes the SEN5X sensor._  |
|  bool | [**sen5x\_leer**](#function-sen5x_leer) (void) <br>_Reads the latest data measured by the sensor and updates the global variables_ `sen5x_*` _with the new values._ |




























## Detailed Description


Declares functions and global variables for interacting with the sensor.




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

------------------------------
The documentation for this class was generated from the following file `firmware/SEN5X_API.h`

