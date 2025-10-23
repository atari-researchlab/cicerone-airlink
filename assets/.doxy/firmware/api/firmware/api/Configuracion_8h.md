

# File Configuracion.h



[**FileList**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Configuracion.h**](Configuracion_8h.md)

[Go to the source code of this file](Configuracion_8h_source.md)

_Global configuration file for the Airlink project._ [More...](#detailed-description)

































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**APN\_NBIOT**](Configuracion_8h.md#define-apn_nbiot)  `"iot.1nce.net"`<br>_Internet provider APN._  |
| define  | [**HABILITAR\_NBIOT**](Configuracion_8h.md#define-habilitar_nbiot)  `1`<br>_Uncomment to enable data transmission via NB-IoT._  |
| define  | [**ID\_USUARIO**](Configuracion_8h.md#define-id_usuario)  `"AIRLINK\_01"`<br>_Device identification._  |
| define  | [**SERVIDOR\_API**](Configuracion_8h.md#define-servidor_api)  `"/aqindoor"`<br>_API location for HTTP transmissions._  |
| define  | [**SERVIDOR\_IP**](Configuracion_8h.md#define-servidor_ip)  `"http://direccion.servidor.com"`<br>_Server IP where data will be sent._  |
| define  | [**SERVIDOR\_PUERTO**](Configuracion_8h.md#define-servidor_puerto)  `"64340"`<br>_Server port._  |

## Detailed Description


This file centralizes all options that can be adjusted to change the firmware behavior without modifying the source code.




**Author:**

[ALD-DSL/ATARI\_RESEARCH\_LAB] 




**Date:**

[2024-07-22/2025-10-15] 




**Version:**

2.0




**Copyright:**

GNU General Public License version 3 or later




**Note:**

Modify this file to change the program behavior without altering the main code. 





    
## Macro Definition Documentation





### define APN\_NBIOT 

_Internet provider APN._ 
```C++
#define APN_NBIOT `"iot.1nce.net"`
```



Enter the internet provider APN. Some providers do not require an APN to be entered.


Examples:



```C++
#define APN_NBIOT ""             // No APN
#define APN_NBIOT "iot.1nce.net" // 1NCE APN
#define APN_NBIOT "TM"           // ThingMobile APN
```
 


        

<hr>



### define HABILITAR\_NBIOT 

_Uncomment to enable data transmission via NB-IoT._ 
```C++
#define HABILITAR_NBIOT `1`
```



Comment or uncomment these lines to include or exclude functionalities from the final program. This is useful to save memory and power if not all modules are used. 


        

<hr>



### define ID\_USUARIO 

_Device identification._ 
```C++
#define ID_USUARIO `"AIRLINK_01"`
```



Defines a unique ID for this device. 


        

<hr>



### define SERVIDOR\_API 

_API location for HTTP transmissions._ 
```C++
#define SERVIDOR_API `"/aqindoor"`
```




<hr>



### define SERVIDOR\_IP 

_Server IP where data will be sent._ 
```C++
#define SERVIDOR_IP `"http://direccion.servidor.com"`
```




<hr>



### define SERVIDOR\_PUERTO 

_Server port._ 
```C++
#define SERVIDOR_PUERTO `"64340"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `firmware/Configuracion.h`

