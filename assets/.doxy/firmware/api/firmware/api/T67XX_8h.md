

# File T67XX.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T67XX.h**](T67XX_8h.md)

[Go to the source code of this file](T67XX_8h_source.md)

_This is a library for the Telaire_ [_**T67XX**_](classT67XX.md) _series miniature CO2 sensor module._[More...](#detailed-description)

* `#include <Arduino.h>`
* `#include <Wire.h>`















## Classes

| Type | Name |
| ---: | :--- |
| class | [**T67XX**](classT67XX.md) <br>_Class for_ [_**T67XX**_](classT67XX.md) _CO2 sensor communication._ |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**Modbus\_FC**](#enum-modbus_fc)  <br>_Modbus function codes._  |
| union  | [**StatusRegister**](#union-statusregister)  <br>_Each bit represents the status of a device function or error._  |
| enum  | [**T67XX\_Registers**](#enum-t67xx_registers)  <br>[_**T67XX**_](classT67XX.md) _register addresses._ |















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**T67XX\_DEFAULT\_I2C\_ADDR**](T67XX_8h.md#define-t67xx_default_i2c_addr)  `0x15`<br>_Default I2C address._  |
| define  | [**T67XX\_MEASURE\_DELAY**](T67XX_8h.md#define-t67xx_measure_delay)  `2250`<br>_Delay between starting PPM measurement and reading the data (manufacturer recommended value)._  |
| define  | [**T67XX\_READ\_DELAY**](T67XX_8h.md#define-t67xx_read_delay)  `10`<br>_Delay between read/write transmissions (manufacturer recommended value)._  |
| define  | [**T67XX\_REG\_VAL\_DISABLE**](T67XX_8h.md#define-t67xx_reg_val_disable)  `0x0000`<br>_Value to disable a register._  |
| define  | [**T67XX\_REG\_VAL\_ENABLE**](T67XX_8h.md#define-t67xx_reg_val_enable)  `0xFF00`<br>_Value to enable a register._  |

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


    
## Public Types Documentation




### enum Modbus\_FC 

_Modbus function codes._ 
```C++
enum Modbus_FC {
    MODBUS_READ_COIL = 0x01,
    MODBUS_READ_DISCRETE_INPUT = 0x02,
    MODBUS_READ_MULTIPLE_HOLDING_REGISTERS = 0x03,
    MODBUS_READ_INPUT_REGISTERS = 0x04,
    MODBUS_WRITE_SINGLE_COIL = 0x05,
    MODBUS_WRITE_SINGLE_REGISTER = 0x06,
    MODBUS_WRITE_MULTIPLE_COILS = 0x0F,
    MODBUS_WRITE_MULTIPLE_REGISTERS = 0x10
};
```



The I2C implementation uses the Modbus protocol and encapsulates the message in I2C format; however, in this case CRC is not included. Function codes vary according to the data type and whether a single or multiple read/write is performed.


Modbus data model:



* Discrete Inputs: 1bit. Read only.
* Coils: 1bit. Read/Write.
* Input Registers: 16bits. Read only.
* Holding Registers: 16bits. Read/Write. 




        

<hr>



### union StatusRegister 

_Each bit represents the status of a device function or error._ 
```C++

```



Allows verification of device status and the different errors that can occur.


Under error conditions, a "1" indicates an error; a "0" indicates no error. A Flash error is fatal (i.e., no recovery). Calibration errors can be cleared by running the calibration procedure again with correct results.


Under calibration conditions, a "1" indicates that the calibration cycle is in progress. No other calibration cycle can be started while one is in progress and the Modbus response will report an error to the new calibration request.


If the warmup bit (_WARMUP_) is active, the sensor is in a mode where internal registers and gas data (ppm) are being initialized and are not necessarily correct. 


    

<hr>



### enum T67XX\_Registers 

[_**T67XX**_](classT67XX.md) _register addresses._
```C++
enum T67XX_Registers {
    T67XX_REG_FIRMWARE = 0x1389,
    T67XX_REG_STATUS = 0x138A,
    T67XX_REG_PPM = 0x138B,
    T67XX_REG_RESET = 0x03E8,
    T67XX_REG_SPCAL = 0x03EC,
    T67XX_REG_FLASH_UPDATE = 0x03ED,
    T67XX_REG_ADDRESS = 0x0FA5,
    T67XX_REG_ABC_LOGIC = 0x03EE,
    T67XX_REG_MOD_MODE = 0x100B
};
```




<hr>
## Macro Definition Documentation





### define T67XX\_DEFAULT\_I2C\_ADDR 

_Default I2C address._ 
```C++
#define T67XX_DEFAULT_I2C_ADDR `0x15`
```




<hr>



### define T67XX\_MEASURE\_DELAY 

_Delay between starting PPM measurement and reading the data (manufacturer recommended value)._ 
```C++
#define T67XX_MEASURE_DELAY `2250`
```




<hr>



### define T67XX\_READ\_DELAY 

_Delay between read/write transmissions (manufacturer recommended value)._ 
```C++
#define T67XX_READ_DELAY `10`
```




<hr>



### define T67XX\_REG\_VAL\_DISABLE 

_Value to disable a register._ 
```C++
#define T67XX_REG_VAL_DISABLE `0x0000`
```




<hr>



### define T67XX\_REG\_VAL\_ENABLE 

_Value to enable a register._ 
```C++
#define T67XX_REG_VAL_ENABLE `0xFF00`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/T67XX.h`

