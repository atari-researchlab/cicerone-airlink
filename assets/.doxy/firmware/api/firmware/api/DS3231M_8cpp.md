

# File DS3231M.cpp



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**DS3231M.cpp**](DS3231M_8cpp.md)

[Go to the source code of this file](DS3231M_8cpp_source.md)

_This file implements functionalities for the_ [_**DS3231M**_](classDS3231M.md) _RTC module._[More...](#detailed-description)

* `#include "Wire.h"`
* `#include "DS3231M.h"`
* `#include "Debug.h"`
































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_LEVEL**](DS3231M_8cpp.md#define-debug_level)  `[**DEBUG\_DS3231M**](Debug_8h.md#define-debug_ds3231m)`<br>_Redefinition of the debug level for this source file._  |
| define  | [**DEBUG\_TAG**](DS3231M_8cpp.md#define-debug_tag)  `"DS3231M"`<br>_Tag when sending debug messages._  |

## Detailed Description


Provides methods for reading and setting time and date, managing alarms and other RTC configurations.



* [**DS3231M**](classDS3231M.md) Datasheet: [https://dfimg.dfrobot.com/nobody/wiki/456426e32d698477163ee658755f4d05.pdf](https://dfimg.dfrobot.com/nobody/wiki/456426e32d698477163ee658755f4d05.pdf)
* DFRobot\_DS3231M library repository: [https://github.com/DFRobot/DFRobot\_DS3231M](https://github.com/DFRobot/DFRobot_DS3231M)






**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later




**Note:**

This module is based on the DFRobot library for the [**DS3231M**](classDS3231M.md) [https://github.com/DFRobot/DFRobot\_DS3231M](https://github.com/DFRobot/DFRobot_DS3231M)


Copyright 2010 DFRobot Co.Ltd


License: MIT License 


    
## Macro Definition Documentation





### define DEBUG\_LEVEL 

_Redefinition of the debug level for this source file._ 
```C++
#define DEBUG_LEVEL `DEBUG_DS3231M`
```




<hr>



### define DEBUG\_TAG 

_Tag when sending debug messages._ 
```C++
#define DEBUG_TAG `"DS3231M"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/DS3231M.cpp`

