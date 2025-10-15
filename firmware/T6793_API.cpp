/**
 * @file    T6793_API.cpp
 * @brief   Implementación de la API para el sensor de CO2 Telaire T6793-5K.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  Este módulo es una capa de abstracción sobre la librería T67XX.
 */

#include "T6793_API.h"
#include "T67XX.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793  //!< Redefinición del nivel de depuración de este archivo fuente.
#define DEBUG_TAG "T6793_API"    //!< Etiqueta al enviar mensajes de depuración.

T67XX t6793_sensor;      //!< Instancia del objeto de la librería para el sensor.
uint16_t t6793_co2 = 0;  //!< Definición de la variable global.

void t6793_inicializar(void) {
  uint16_t sensorStatus = 1;

  while (!t6793_sensor.begin()) {
    DEBUG_ERROR("No se ha podido encontrar el sensor, verifique las conexiones");  // Mensaje de error si el sensor no es detectado.
    delay(2000);                                                                   // Espera 2 segundos antes de reintentar.
  }
  DEBUG_INFO("Conexión establecida. Reiniciando...");  // Mensaje de éxito.
  t6793_sensor.reset();                                // Reinicia el sensor para asegurar un estado conocido.

  // Espera a que el sensor salga del estado de calentamiento o cualquier otro estado de error inicial.
  do {
    sensorStatus = t6793_sensor.getStatus();                        // Lee el estado inicial del sensor.
    DEBUG_INFO("Estado: %s", t6793_sensor.getStatusMsg().c_str());  // Imprime el mensaje de estado actual.
    delay(T67XX_MEASURE_DELAY);                                     // Espera el tiempo de medición recomendado.
  } while (sensorStatus);

  DEBUG_INFO("Firmware version: %u", t6793_sensor.getFirmwareVersion());  // Imprime la versión del firmware.

  DEBUG_VERBOSE("Habilitando autocalibración...");  // Mensaje informativo.
  /* Habilita la calibración automática (ABC).
   * Esto es recomendable en aplicaciones donde el sensor está expuesto
   * regularmente a aire fresco (400 ppm de CO2). */
  t6793_sensor.enableABCMode();
  DEBUG_INFO("Autocalibración habilitada...");

  DEBUG_INFO("Guardando configuración...");  // Mensaje informativo.
  t6793_sensor.flashUpdate();                // Guarda las configuraciones en la memoria flash del sensor.

  DEBUG_INFO("Sensor inicializado.");
}

bool t6793_leer(void) {
  uint16_t sensorStatus = t6793_sensor.getStatus();
  if (sensorStatus & (~(1u >> 0x0F) & 0x01)) {
    DEBUG_WARN("Lectura de CO2 invalida (0 PPM). Estado: %s", t6793_sensor.getStatusMsg().c_str());
    t6793_co2 = 0;
    return false;
  }

  t6793_co2 = t6793_sensor.readPPM();

  DEBUG_INFO("CO2: %u ppm", t6793_co2);

  return true;
}
