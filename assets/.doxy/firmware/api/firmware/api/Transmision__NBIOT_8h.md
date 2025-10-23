

# File Transmision\_NBIOT.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Transmision\_NBIOT.h**](Transmision__NBIOT_8h.md)

[Go to the source code of this file](Transmision__NBIOT_8h_source.md)



* `#include "Configuracion.h"`
* `#include <Arduino.h>`
* `#include <ArduinoJson.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**ReiniciarDispositivo**](#function-reiniciardispositivo) (void) <br>_Restarts the microcontroller._  |
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
| define  | [**NOTOK**](Transmision__NBIOT_8h.md#define-notok)  `2`<br> |
| define  | [**OK**](Transmision__NBIOT_8h.md#define-ok)  `1`<br> |
| define  | [**RST**](Transmision__NBIOT_8h.md#define-rst)  `2`<br> |
| define  | [**SERIALTIMEOUT**](Transmision__NBIOT_8h.md#define-serialtimeout)  `3000`<br> |
| define  | [**SIM7020baud**](Transmision__NBIOT_8h.md#define-sim7020baud)  `115200`<br> |
| define  | [**SIM7020board**](Transmision__NBIOT_8h.md#define-sim7020board)  `Serial1`<br> |
| define  | [**TIMEOUTERR**](Transmision__NBIOT_8h.md#define-timeouterr)  `3`<br> |

## Public Functions Documentation




### function ReiniciarDispositivo 

_Restarts the microcontroller._ 
```C++
inline void ReiniciarDispositivo (
    void
) 
```



Used for cases where it is not possible to establish a connection to the server. 


        

<hr>



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





### define NOTOK 

```C++
#define NOTOK `2`
```




<hr>



### define OK 

```C++
#define OK `1`
```




<hr>



### define RST 

```C++
#define RST `2`
```




<hr>



### define SERIALTIMEOUT 

```C++
#define SERIALTIMEOUT `3000`
```




<hr>



### define SIM7020baud 

```C++
#define SIM7020baud `115200`
```




<hr>



### define SIM7020board 

```C++
#define SIM7020board `Serial1`
```




<hr>



### define TIMEOUTERR 

```C++
#define TIMEOUTERR `3`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Transmision_NBIOT.h`

