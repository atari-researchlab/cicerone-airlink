

# File T67XX.cpp



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T67XX.cpp**](T67XX_8cpp.md)

[Go to the source code of this file](T67XX_8cpp_source.md)

_This is a library for the Telaire_ [_**T67XX**_](classT67XX.md) _series miniature CO2 sensor module._[More...](#detailed-description)

* `#include "T67XX.h"`
* `#include "Debug.h"`
































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_LEVEL**](T67XX_8cpp.md#define-debug_level)  `[**DEBUG\_T6793**](Debug_8h.md#define-debug_t6793)`<br>_Redefinition of debug level for this source file._  |
| define  | [**DEBUG\_TAG**](T67XX_8cpp.md#define-debug_tag)  `"T67XX"`<br>_Tag when sending debug messages._  |

## Detailed Description


These sensors use UART and I2C to communicate. This library is designed for the I2C communication option. 2 pins are required for the interface. To enable I2C communication, connect pin CTRL (pin 6 of the module) to GND.




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later




**Note:**

This module is based on the library by Yaroslav Osadchyy ([drug123@gmail.com](mailto:drug123@gmail.com)) with MIT License


Copyright (c) 2020 Yaroslav Osadchyy ([drug123@gmail.com](mailto:drug123@gmail.com)) [https://github.com/drug123/T67XX](https://github.com/drug123/T67XX)


MIT license, all text above must be included in any redistribution 


    
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
#define DEBUG_TAG `"T67XX"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/T67XX.cpp`

