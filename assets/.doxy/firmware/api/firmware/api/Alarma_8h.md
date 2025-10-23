

# File Alarma.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Alarma.h**](Alarma_8h.md)

[Go to the source code of this file](Alarma_8h_source.md)

_Header for timed alarm and data averaging management._ [More...](#detailed-description)

* `#include <Arduino.h>`
* `#include "DS3231M.h"`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**acumular\_datos**](#function-acumular_datos) (void) <br>_Reads data from all sensors and accumulates them for averaging._  |
|  void | [**check\_alarma\_10min**](#function-check_alarma_10min) (void) <br>_Verifies if the 10-minute cycle has completed. If so, activates the alarma\_10min flag._  |
|  void | [**check\_alarma\_5s**](#function-check_alarma_5s) (void) <br>_Checks if 5 seconds have passed using millis(). If so, activates the alarma\_5s flag._  |
|  void | [**promediar\_datos**](#function-promediar_datos) (void) <br>_Processes accumulated data to calculate averages and stores them._  |
|  void | [**reset\_acumuladores**](#function-reset_acumuladores) (void) <br>_Resets counters and accumulators._  |
|  void | [**rtc\_alarma\_inicializar**](#function-rtc_alarma_inicializar) (void) <br>_Initializes the RTC module and configures the first 10-minute alarm._  |




























## Detailed Description


Declares functions and global variables to control periodic tasks (e.g., every 5s, every 10min) and to handle sensor data.




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later 





    
## Public Functions Documentation




### function acumular\_datos 

_Reads data from all sensors and accumulates them for averaging._ 
```C++
void acumular_datos (
    void
) 
```



Calls the reading functions of the SEN55 and T6793 modules and adds their values to the corresponding _sum\_\*_ accumulators. Increments the averaging counters. 


        

<hr>



### function check\_alarma\_10min 

_Verifies if the 10-minute cycle has completed. If so, activates the alarma\_10min flag._ 
```C++
void check_alarma_10min (
    void
) 
```



Checks the RTC time to see if the next 10-minute interval has been reached (e.g., 12:10, 12:20). 

**Note:**

Must be called continuously in the main loop. 





        

<hr>



### function check\_alarma\_5s 

_Checks if 5 seconds have passed using millis(). If so, activates the alarma\_5s flag._ 
```C++
void check_alarma_5s (
    void
) 
```





**Note:**

Must be called continuously in the main loop. 





        

<hr>



### function promediar\_datos 

_Processes accumulated data to calculate averages and stores them._ 
```C++
void promediar_datos (
    void
) 
```



This function is called at the end of each averaging period (e.g., every 10 minutes) and the averages are stored in the corresponding _avg\_\*_ variables. 


        

<hr>



### function reset\_acumuladores 

_Resets counters and accumulators._ 
```C++
void reset_acumuladores (
    void
) 
```




<hr>



### function rtc\_alarma\_inicializar 

_Initializes the RTC module and configures the first 10-minute alarm._ 
```C++
void rtc_alarma_inicializar (
    void
) 
```



Configures the RTC with initial date and time if necessary, or synchronizes it. This function must be called in 'setup()'. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Alarma.h`

