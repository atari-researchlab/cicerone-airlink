

# File Transmision\_NBIOT.cpp



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Transmision\_NBIOT.cpp**](Transmision__NBIOT_8cpp.md)

[Go to the source code of this file](Transmision__NBIOT_8cpp_source.md)

_Implementation of functions for NB-IoT data transmission._ [More...](#detailed-description)

* `#include "Configuracion.h"`
* `#include <ArduinoJson.h>`
* `#include "Debug.h"`
* `#include "Transmision_NBIOT.h"`
* `#include "Alarma.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  String | [**co2**](#variable-co2)   = `"10"`<br>_CO2 value (initial example)_  |
|  JsonDocument | [**doc**](#variable-doc)  <br>_JSON object._  |
|  String | [**hexData**](#variable-hexdata)  <br>_String that will contain the JSON data in hexadecimal format._  |
|  String | [**hum**](#variable-hum)   = `"70"`<br>_Humidity value (initial example)_  |
|  String | [**json\_data**](#variable-json_data)  <br>_String that will contain the complete JSON payload._  |
|  String | [**nox**](#variable-nox)   = `"100"`<br>_NOx value (initial example)_  |
|  String | [**ppm1**](#variable-ppm1)   = `"100"`<br>_PM1.0 value (initial example)_  |
|  String | [**ppm10**](#variable-ppm10)   = `"100"`<br>_PM10.0 value (initial example)_  |
|  String | [**ppm25**](#variable-ppm25)   = `"100"`<br>_PM2.5 value (initial example)_  |
|  String | [**ppm4**](#variable-ppm4)   = `"100"`<br>_PM4.0 value (initial example)_  |
|  const char \* | [**respuestas**](#variable-respuestas)   = `{ "", "OK", "NOTOK", "TIMEOUTERR", "RST"}`<br>_Array with the response types returned by the SIM7020 module._  |
|  String | [**temp**](#variable-temp)   = `"22"`<br>_Temperature value (initial example)_  |
|  String | [**voc**](#variable-voc)   = `"15"`<br>_VOC value (initial example)_  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**SIM7020begin**](#function-sim7020begin) (void) <br>_Initializes communication with the SIM7020 module._  |
|  byte | [**SIM7020command**](#function-sim7020command) (String command, String response1, String response2, unsigned long timeout, uint16\_t repetitions) <br>_Sends an AT command to the SIM7020 module and waits for a specific response._  |
|  String | [**SIM7020read**](#function-sim7020read) (void) <br>_Reads messages sent by the SIM7020 module._  |
|  byte | [**SIM7020waitFor**](#function-sim7020waitfor) (String response1, String response2, unsigned long timeOut) <br>_Function that waits for a specific response with maximum time._  |
|  String | [**jsonToHex**](#function-jsontohex) (const JsonDocument & doc) <br>_Converts a JSON object to a hexadecimal string._  |
|  void | [**nbiot\_enviar**](#function-nbiot_enviar) (void) <br>_Transmits sensor data to the server._  |
|  void | [**nbiot\_inicializar**](#function-nbiot_inicializar) (void) <br>_Initializes the NB-IoT module (SIM7020)._  |
|  void | [**nbiot\_paquete**](#function-nbiot_paquete) (void) <br>_Creates the JSON payload with current sensor data._  |
|  void | [**nbiot\_transmitir**](#function-nbiot_transmitir) (void) <br>_Performs an HTTP POST request to the server._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**DEBUG\_LEVEL**](Transmision__NBIOT_8cpp.md#define-debug_level)  `[**DEBUG\_NBIOT**](Debug_8h.md#define-debug_nbiot)`<br>_Redefinition of the debug level for this source file._  |
| define  | [**DEBUG\_TAG**](Transmision__NBIOT_8cpp.md#define-debug_tag)  `"NBIOT"`<br>_Tag when sending debug messages._  |

## Detailed Description


This file contains global variable definitions and implementations of the functions declared in '[**Transmision\_NBIOT.h**](Transmision__NBIOT_8h.md)'.




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later




**Note:**

This module is fundamental for connectivity and sending sensor-collected data to a remote monitoring platform. 





    
## Public Attributes Documentation




### variable co2 

_CO2 value (initial example)_ 
```C++
String co2;
```




<hr>



### variable doc 

_JSON object._ 
```C++
JsonDocument doc;
```




<hr>



### variable hexData 

_String that will contain the JSON data in hexadecimal format._ 
```C++
String hexData;
```




<hr>



### variable hum 

_Humidity value (initial example)_ 
```C++
String hum;
```




<hr>



### variable json\_data 

_String that will contain the complete JSON payload._ 
```C++
String json_data;
```




<hr>



### variable nox 

_NOx value (initial example)_ 
```C++
String nox;
```




<hr>



### variable ppm1 

_PM1.0 value (initial example)_ 
```C++
String ppm1;
```




<hr>



### variable ppm10 

_PM10.0 value (initial example)_ 
```C++
String ppm10;
```




<hr>



### variable ppm25 

_PM2.5 value (initial example)_ 
```C++
String ppm25;
```




<hr>



### variable ppm4 

_PM4.0 value (initial example)_ 
```C++
String ppm4;
```




<hr>



### variable respuestas 

_Array with the response types returned by the SIM7020 module._ 
```C++
const char* respuestas[5];
```




<hr>



### variable temp 

_Temperature value (initial example)_ 
```C++
String temp;
```




<hr>



### variable voc 

_VOC value (initial example)_ 
```C++
String voc;
```




<hr>
## Public Functions Documentation




### function SIM7020begin 

_Initializes communication with the SIM7020 module._ 
```C++
bool SIM7020begin (
    void
) 
```



Uses SIM7020 module-specific AT commands to detect if communication is correct and resets configuration to a predefined state.




**Returns:**

True if communication and configuration were successful 





        

<hr>



### function SIM7020command 

_Sends an AT command to the SIM7020 module and waits for a specific response._ 
```C++
byte SIM7020command (
    String command,
    String response1,
    String response2,
    unsigned long timeout,
    uint16_t repetitions
) 
```





**Parameters:**


* `command` The AT command to send. 
* `response1` The expected response string to consider the command successful. 
* `response2` String to search for if an "OK" response is not expected. 
* `timeout` Maximum wait time for the response in milliseconds. 
* `repetitions` Number of retries if the response is not as expected. 



**Returns:**

OK if the response is as expected, NOTOK if not, TIMEOUTERR if timeout occurs. 





        

<hr>



### function SIM7020read 

_Reads messages sent by the SIM7020 module._ 
```C++
String SIM7020read (
    void
) 
```





**Returns:**

String with the received message. 





        

<hr>



### function SIM7020waitFor 

_Function that waits for a specific response with maximum time._ 
```C++
byte SIM7020waitFor (
    String response1,
    String response2,
    unsigned long timeOut
) 
```





**Parameters:**


* `response1` The expected response string to consider the command successful. 
* `response2` String to search for if an "OK" response is not expected. 
* `timeout` Maximum wait time for the response in milliseconds. 



**Returns:**

OK if the response is as expected, NOTOK if not, TIMEOUTERR if timeout occurs. 





        

<hr>



### function jsonToHex 

_Converts a JSON object to a hexadecimal string._ 
```C++
String jsonToHex (
    const JsonDocument & doc
) 
```





**Parameters:**


* `doc` The DynamicJsonDocument object to convert. 



**Returns:**

String representing the JSON in hexadecimal format. 





        

<hr>



### function nbiot\_enviar 

_Transmits sensor data to the server._ 
```C++
void nbiot_enviar (
    void
) 
```



This is the main function for data transmission. Builds the JSON, converts it to hexadecimal and performs the HTTP POST request. 


        

<hr>



### function nbiot\_inicializar 

_Initializes the NB-IoT module (SIM7020)._ 
```C++
void nbiot_inicializar (
    void
) 
```



Configures the serial port for communication with the module and executes a series of AT commands to ensure the module is operational and connected to the network. 


        

<hr>



### function nbiot\_paquete 

_Creates the JSON payload with current sensor data._ 
```C++
void nbiot_paquete (
    void
) 
```



Data is obtained from global variables and formatted into a JSON string. 


        

<hr>



### function nbiot\_transmitir 

_Performs an HTTP POST request to the server._ 
```C++
void nbiot_transmitir (
    void
) 
```



Uses SIM7020 module-specific AT commands to create an HTTP connection and send hexadecimal data as payload. 


        

<hr>
## Macro Definition Documentation





### define DEBUG\_LEVEL 

_Redefinition of the debug level for this source file._ 
```C++
#define DEBUG_LEVEL `DEBUG_NBIOT`
```




<hr>



### define DEBUG\_TAG 

_Tag when sending debug messages._ 
```C++
#define DEBUG_TAG `"NBIOT"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Transmision_NBIOT.cpp`

