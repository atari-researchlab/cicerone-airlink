/**
 * @file    Transmision_NBIOT.cpp
 * @brief   Implementación de las funciones para la transmisión de datos vía NB-IoT.
 * @details Este archivo contiene las definiciones de las variables globales y las implementaciones
 * de las funciones declaradas en 'Transmision_NBIOT.h'.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  Este módulo es fundamental para la conectividad y el envío de datos recopilados
 * por los sensores a una plataforma de monitoreo remoto.
 */
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

/**
 * @brief     Inicializa el módulo NB-IoT (SIM7020).
 * @details   Configura el puerto serie para la comunicación con el módulo y realiza una serie de
 * comandos AT para asegurar que el módulo esté operativo y conectado a la red.
 */
void nbiot_inicializar(void);

/**
 * @brief     Transmite los datos de los sensores al servidor.
 * @details   Esta función es la principal para la transmisión de datos.
 * Construye el JSON, lo convierte a hexadecimal y realiza la solicitud HTTP POST.
 */
void nbiot_enviar(void);

/**
 * @brief     Crea el payload JSON con los datos actuales de los sensores.
 * @details   Los datos se obtienen de las variables globales y se formatean en una cadena JSON.
 */
void nbiot_paquete(void);

/**
 * @brief     Realiza una solicitud HTTP POST al servidor.
 * @details   Utiliza comandos AT específicos del módulo SIM7020 para crear una conexión HTTP
 * y enviar los datos hexadecimales como payload.
 */
void nbiot_transmitir(void);

/**
 * @brief     Inicializa la comunicación con el módulo SIM7020.
 * @details   Utiliza comandos AT específicos del módulo SIM7020 para detectar si la comunicación
 * es correcta y resetea la configuración a una manera predefinida.
 *
 * @return    Verdadero si la comunicación y configuración ha sido satisfactoria
 */
bool SIM7020begin(void);

/**
 * @brief   Lee los mensajes enviados por el módulo SIM7020.
 * @return  Cadena con el mensaje recibido.
 */
String SIM7020read(void);

/**
 * @brief   Envía un comando AT al módulo SIM7020 y espera una respuesta específica.
 * @param   command El comando AT a enviar.
 * @param   response1 La cadena de respuesta esperada para considerar el comando exitoso.
 * @param   response2 Cadena a buscar si no se espera una respuesta "OK".
 * @param   timeout Tiempo máximo de espera para la respuesta en milisegundos.
 * @param   repetitions Número de reintentos si la respuesta no es la esperada.
 * @return  OK si la respuesta es la esperada, NOTOK si no, TIMEOUTERR si se agota el tiempo.
 */
byte SIM7020command(String command, String response1, String response2, unsigned long timeout,
                    uint16_t repetitions);

/**
 * @brief   Función de espera una respuesta específica con tiempo máximo.
 * @param   response1 La cadena de respuesta esperada para considerar el comando exitoso.
 * @param   response2 Cadena a buscar si no se espera una respuesta "OK".
 * @param   timeout Tiempo máximo de espera para la respuesta en milisegundos.
 * @return  OK si la respuesta es la esperada, NOTOK si no, TIMEOUTERR si se agota el tiempo.
 */
byte SIM7020waitFor(String response1, String response2, unsigned long timeOut);

/**
 * @brief   Convierte un objeto JSON a una cadena hexadecimal.
 * @param   doc El objeto DynamicJsonDocument a convertir.
 * @return  Cadena que representa el JSON en formato hexadecimal.
 */
String jsonToHex(const JsonDocument& doc);

/**
 * @brief   Reinicia el microcontrolador.
 * @details Se utiliza para los casos en que no sea posible establecer la conexión con el servidor.
 */
inline void ReiniciarDispositivo(void) {
  //NVIC_SystemReset();
}

#endif //TRANSMISION_NBIOT_H

#endif // HABILITAR_NBIOT