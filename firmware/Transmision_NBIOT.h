/**
 * @file    Transmision_NBIOT.cpp
 * @brief   Implementation of functions for NB-IoT data transmission.
 * @details This file contains global variable definitions and implementations
 * of the functions declared in 'Transmision_NBIOT.h'.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  This module is fundamental for connectivity and sending sensor-collected
 * data to a remote monitoring platform.
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
 * @brief     Initializes the NB-IoT module (SIM7020).
 * @details   Configures the serial port for communication with the module and executes a series
 * of AT commands to ensure the module is operational and connected to the network.
 */
void nbiot_inicializar(void);

/**
 * @brief     Transmits sensor data to the server.
 * @details   This is the main function for data transmission.
 * Builds the JSON, converts it to hexadecimal and performs the HTTP POST request.
 */
void nbiot_enviar(void);

/**
 * @brief     Creates the JSON payload with current sensor data.
 * @details   Data is obtained from global variables and formatted into a JSON string.
 */
void nbiot_paquete(void);

/**
 * @brief     Performs an HTTP POST request to the server.
 * @details   Uses SIM7020 module-specific AT commands to create an HTTP connection
 * and send hexadecimal data as payload.
 */
void nbiot_transmitir(void);

/**
 * @brief     Initializes communication with the SIM7020 module.
 * @details   Uses SIM7020 module-specific AT commands to detect if communication
 * is correct and resets configuration to a predefined state.
 *
 * @return    True if communication and configuration were successful
 */
bool SIM7020begin(void);

/**
 * @brief   Reads messages sent by the SIM7020 module.
 * @return  String with the received message.
 */
String SIM7020read(void);

/**
 * @brief   Sends an AT command to the SIM7020 module and waits for a specific response.
 * @param   command The AT command to send.
 * @param   response1 The expected response string to consider the command successful.
 * @param   response2 String to search for if an "OK" response is not expected.
 * @param   timeout Maximum wait time for the response in milliseconds.
 * @param   repetitions Number of retries if the response is not as expected.
 * @return  OK if the response is as expected, NOTOK if not, TIMEOUTERR if timeout occurs.
 */
byte SIM7020command(String command, String response1, String response2, unsigned long timeout,
                    uint16_t repetitions);

/**
 * @brief   Function that waits for a specific response with maximum time.
 * @param   response1 The expected response string to consider the command successful.
 * @param   response2 String to search for if an "OK" response is not expected.
 * @param   timeout Maximum wait time for the response in milliseconds.
 * @return  OK if the response is as expected, NOTOK if not, TIMEOUTERR if timeout occurs.
 */
byte SIM7020waitFor(String response1, String response2, unsigned long timeOut);

/**
 * @brief   Converts a JSON object to a hexadecimal string.
 * @param   doc The DynamicJsonDocument object to convert.
 * @return  String representing the JSON in hexadecimal format.
 */
String jsonToHex(const JsonDocument& doc);

/**
 * @brief   Restarts the microcontroller.
 * @details Used for cases where it is not possible to establish a connection to the server.
 */
inline void ReiniciarDispositivo(void) {
  //NVIC_SystemReset();
}

#endif //TRANSMISION_NBIOT_H

#endif // HABILITAR_NBIOT
