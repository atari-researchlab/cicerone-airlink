

# Class T67XX



[**ClassList**](annotated.md) **>** [**T67XX**](classT67XX.md)



_Class for_ [_**T67XX**_](classT67XX.md) _CO2 sensor communication._

* `#include <T67XX.h>`

















## Public Types

| Type | Name |
| ---: | :--- |
| union  | [**StatusRegister**](#union-statusregister)  <br>_Each bit represents the status of a device function or error._  |




















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**T67XX**](#function-t67xx) (TwoWire \* pWire=&Wire, uint8\_t deviceAddress=[**T67XX\_DEFAULT\_I2C\_ADDR**](T67XX_8h.md#define-t67xx_default_i2c_addr)) <br>[_**T67XX**_](classT67XX.md) _class constructor._ |
|  bool | [**begin**](#function-begin) (void) <br>_Initializes I2C communication._  |
|  bool | [**beginCalibration**](#function-begincalibration) (bool waitForCompletion=false) <br>_Starts the single point calibration routine._  |
|  void | [**disableABCMode**](#function-disableabcmode) (void) <br>_Disable ABC autocalibration._  |
|  void | [**enableABCMode**](#function-enableabcmode) (void) <br>_Enable ABC autocalibration._  |
|  void | [**endCalibration**](#function-endcalibration) (void) <br>_Stops the single point calibration routine._  |
|  void | [**flashUpdate**](#function-flashupdate) (void) <br>_Saves configuration to flash._  |
|  uint16\_t | [**getFirmwareVersion**](#function-getfirmwareversion) (void) <br>_Gets the sensor firmware version._  |
|  uint16\_t | [**getStatus**](#function-getstatus) (void) <br>_Gets the current sensor status and stores it in the internal variable._  |
|  String | [**getStatusMsg**](#function-getstatusmsg) (void) <br>_Genera un mensaje con el estado actual del sensor._  |
|  uint16\_t | [**readPPM**](#function-readppm) (void) <br>_Gets the current CO2 value from the sensor in PPM._  |
|  void | [**reset**](#function-reset) (void) <br>_Resets the sensor._  |
|  uint8\_t | [**setSlaveAddress**](#function-setslaveaddress) (uint8\_t newAddress) <br>_Modifies the sensor's internal I2C address._  |
|   | [**~T67XX**](#function-t67xx) () <br>[_**T67XX**_](classT67XX.md) _class destructor._ |




























## Public Types Documentation




### union StatusRegister 

_Each bit represents the status of a device function or error._ 
```C++

```



Allows verification of device status and the different errors that can occur.


Under error conditions, a "1" indicates an error; a "0" indicates no error. A Flash error is fatal (i.e., no recovery). Calibration errors can be cleared by running the calibration procedure again with correct results.


Under calibration conditions, a "1" indicates that the calibration cycle is in progress. No other calibration cycle can be started while one is in progress and the Modbus response will report an error to the new calibration request.


If the warmup bit (_WARMUP_) is active, the sensor is in a mode where internal registers and gas data (ppm) are being initialized and are not necessarily correct. 


    

<hr>
## Public Functions Documentation




### function T67XX 

[_**T67XX**_](classT67XX.md) _class constructor._
```C++
inline T67XX::T67XX (
    TwoWire * pWire=&Wire,
    uint8_t deviceAddress=T67XX_DEFAULT_I2C_ADDR
) 
```





**Parameters:**


* `pWire` Peripheral used for I2C communication. 
* `deviceAddress` I2C address of the sensor used. 




        

<hr>



### function begin 

_Initializes I2C communication._ 
```C++
bool T67XX::begin (
    void
) 
```





**Returns:**

True if communication with the module is successful, false if it fails. 





        

<hr>



### function beginCalibration 

_Starts the single point calibration routine._ 
```C++
bool T67XX::beginCalibration (
    bool waitForCompletion=false
) 
```



The single point calibration routine is generally performed at room temperature (~500 ppm, 25 °C) and takes several minutes to complete after starting (approximately 6 minutes). During this time, the sensor status and current ppm gas readings can be queried. The user can check the calibration status by reading the status register and noting if the single point calibration bit is active. Calibration can be stopped before it finishes.




**Parameters:**


* `waitForCompletion` Optional: Wait for calibration to finish (disabled by default). 



**Returns:**

True if calibration has finished. 





        

<hr>



### function disableABCMode 

_Disable ABC autocalibration._ 
```C++
void T67XX::disableABCMode (
    void
) 
```





**See also:** [**enableABCMode()**](classT67XX.md#function-enableabcmode) 



        

<hr>



### function enableABCMode 

_Enable ABC autocalibration._ 
```C++
void T67XX::enableABCMode (
    void
) 
```



Automatic Background Logic (ABC) is a patented autocalibration technique designed for use in applications where concentrations drop to outdoor ambient conditions (400 ppm) at least once (15 minutes) in a 7-day period, which typically occurs during unoccupied periods.


Full accuracy is achieved using ABC Logic. With ABC Logic enabled, the sensor generally reaches its operational accuracy after 25 hours of continuous operation, provided it has been exposed to reference ambient air levels of 400 ppm ±10ppm CO2. The sensor will maintain accuracy specifications with ABC Logic enabled, as long as it is exposed to the reference value at least once every 7 days, and this reference value is the lowest concentration to which the sensor is exposed.




**Note:**

ABC Logic requires continuous sensor operation in increments of at least 4 hours each.




**Warning:**

Not recommended for applications where the sensor is not regularly exposed to fresh air (400 ppm CO2). 





        

<hr>



### function endCalibration 

_Stops the single point calibration routine._ 
```C++
void T67XX::endCalibration (
    void
) 
```




<hr>



### function flashUpdate 

_Saves configuration to flash._ 
```C++
void T67XX::flashUpdate (
    void
) 
```




<hr>



### function getFirmwareVersion 

_Gets the sensor firmware version._ 
```C++
uint16_t T67XX::getFirmwareVersion (
    void
) 
```





**Returns:**

Firmware version. 





        

<hr>



### function getStatus 

_Gets the current sensor status and stores it in the internal variable._ 
```C++
uint16_t T67XX::getStatus (
    void
) 
```





**Returns:**

Current sensor status. 





        

<hr>



### function getStatusMsg 

_Genera un mensaje con el estado actual del sensor._ 
```C++
String T67XX::getStatusMsg (
    void
) 
```





**Returns:**

Cadena con el estado actual del sensor. 





        

<hr>



### function readPPM 

_Gets the current CO2 value from the sensor in PPM._ 
```C++
uint16_t T67XX::readPPM (
    void
) 
```





**Returns:**

CO2 value in PPM. 





        

<hr>



### function reset 

_Resets the sensor._ 
```C++
void T67XX::reset (
    void
) 
```




<hr>



### function setSlaveAddress 

_Modifies the sensor's internal I2C address._ 
```C++
uint8_t T67XX::setSlaveAddress (
    uint8_t newAddress
) 
```



Configures a new sensor I2C address and resets it to apply the changes.




**Parameters:**


* `newAddress` New sensor I2C address 



**Returns:**

True if communication with the module at the new address is successful, false if it fails.




**Warning:**

This change is permanent when the sensor is reset. 





        

<hr>



### function ~T67XX 

[_**T67XX**_](classT67XX.md) _class destructor._
```C++
inline T67XX::~T67XX () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/T67XX.h`

