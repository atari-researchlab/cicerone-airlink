#include "Configuracion.h"
#if HABILITAR_NBIOT

#ifndef TRANSMISION_NBIOT_H
#define TRANSMISION_NBIOT_H

//#include <String.h>
#include <ArduinoJson.h>

/* ==============================SETTINGS NB_IoT==============================*/

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

String SIM7020read(void);
byte SIM7020waitFor(String response1, String response2, unsigned long timeOut);
byte SIM7020command(String command, String response1, String response2, unsigned long timeout, uint16_t repetitions);
void SIM7020input(void);
bool SIM7020begin(void);
String jsonToHex(const JsonDocument& doc);

inline void Reiniciar_Dispositivo(void) {
  //NVIC_SystemReset();
}

#endif //TRANSMISION_NBIOT_H

#endif // HABILITAR_NBIOT