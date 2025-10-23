

# File Transmision\_NBIOT.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Transmision\_NBIOT.h**](Transmision__NBIOT_8h.md)

[Go to the documentation of this file](Transmision__NBIOT_8h.md)


```C++

#include "Configuracion.h"

#if HABILITAR_NBIOT

#ifndef TRANSMISION_NBIOT_H
#define TRANSMISION_NBIOT_H

#include <Arduino.h>
#include <ArduinoJson.h>

#define OK 1
#define NOTOK 2
#define TIMEOUTERR 3
#define RST 2
#define SIM7020board Serial1
#define SIM7020baud 115200
#define SERIALTIMEOUT 3000

void nbiot_inicializar(void);

void nbiot_enviar(void);

void nbiot_paquete(void);

void nbiot_transmitir(void);

bool SIM7020begin(void);

String SIM7020read(void);

byte SIM7020command(String command, String response1, String response2, unsigned long timeout,
                    uint16_t repetitions);

byte SIM7020waitFor(String response1, String response2, unsigned long timeOut);

String jsonToHex(const JsonDocument& doc);

inline void ReiniciarDispositivo(void) {
  //NVIC_SystemReset();
}

#endif //TRANSMISION_NBIOT_H

#endif // HABILITAR_NBIOT
```


