

# Union T67XX::StatusRegister



[**ClassList**](annotated.md) **>** [**T67XX**](classT67XX.md) **>** [**StatusRegister**](unionT67XX_1_1StatusRegister.md)



_Each bit represents the status of a device function or error._ [More...](#detailed-description)

* `#include <T67XX.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  uint16\_t | [**CALIBRATION\_ERROR**](#variable-calibration_error)  <br>_Bit 2._  |
|  uint16\_t | [**ERROR**](#variable-error)  <br>_Bit 0._  |
|  uint16\_t | [**FLASH\_ERROR**](#variable-flash_error)  <br>_Bit 1._  |
|  uint16\_t | [**REBOOT**](#variable-reboot)  <br>_Bit 10._  |
|  uint16\_t | [**SINGLE\_POINT\_CAL**](#variable-single_point_cal)  <br>_Bit 15._  |
|  uint16\_t | [**WARMUP**](#variable-warmup)  <br>_Bit 11._  |
|  uint16\_t | [**\_\_pad0\_\_**](#variable-__pad0__)  <br>_Bits 3-9 (unused, ignored)_  |
|  uint16\_t | [**\_\_pad1\_\_**](#variable-__pad1__)  <br>_Bits 12-14 (unused)_  |
|  struct [**T67XX::StatusRegister**](unionT67XX_1_1StatusRegister.md) | [**bits**](#variable-bits)  <br>_Access to individual bits._  |
|  uint16\_t | [**raw\_value**](#variable-raw_value)  <br>_Access to the complete 16-bit status._  |












































## Detailed Description


Allows verification of device status and the different errors that can occur.


Under error conditions, a "1" indicates an error; a "0" indicates no error. A Flash error is fatal (i.e., no recovery). Calibration errors can be cleared by running the calibration procedure again with correct results.


Under calibration conditions, a "1" indicates that the calibration cycle is in progress. No other calibration cycle can be started while one is in progress and the Modbus response will report an error to the new calibration request.


If the warmup bit (_WARMUP_) is active, the sensor is in a mode where internal registers and gas data (ppm) are being initialized and are not necessarily correct. 


    
## Public Attributes Documentation




### variable CALIBRATION\_ERROR 

_Bit 2._ 
```C++
uint16_t T67XX::StatusRegister::CALIBRATION_ERROR;
```




<hr>



### variable ERROR 

_Bit 0._ 
```C++
uint16_t T67XX::StatusRegister::ERROR;
```




<hr>



### variable FLASH\_ERROR 

_Bit 1._ 
```C++
uint16_t T67XX::StatusRegister::FLASH_ERROR;
```




<hr>



### variable REBOOT 

_Bit 10._ 
```C++
uint16_t T67XX::StatusRegister::REBOOT;
```




<hr>



### variable SINGLE\_POINT\_CAL 

_Bit 15._ 
```C++
uint16_t T67XX::StatusRegister::SINGLE_POINT_CAL;
```




<hr>



### variable WARMUP 

_Bit 11._ 
```C++
uint16_t T67XX::StatusRegister::WARMUP;
```




<hr>



### variable \_\_pad0\_\_ 

_Bits 3-9 (unused, ignored)_ 
```C++
uint16_t T67XX::StatusRegister::__pad0__;
```




<hr>



### variable \_\_pad1\_\_ 

_Bits 12-14 (unused)_ 
```C++
uint16_t T67XX::StatusRegister::__pad1__;
```




<hr>



### variable bits 

_Access to individual bits._ 
```C++
struct T67XX::StatusRegister T67XX::StatusRegister::bits;
```




<hr>



### variable raw\_value 

_Access to the complete 16-bit status._ 
```C++
uint16_t T67XX::StatusRegister::raw_value;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/T67XX.h`

