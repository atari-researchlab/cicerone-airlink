/***********************************************************************************************************************
 * @file        T6793_API.cpp
 * @brief       Implementación de la API para el sensor de CO2 Telaire T6793-5K.
 *
 * @author      [ALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 **********************************************************************************************************************/

#include "T6793_API.h"
#include "T67XX.h"
#include "Debug.h"              // Contiene las macros para controlar la salida de depuración por Serial.

// Etiqueta para los mensajes de depuración.
#define DEBUG_TAG "T6793_API"
#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793

// Instancia del objeto de la librería para el sensor.
T67XX t6793_sensor;

// Definición de la variable global.
uint16_t t6793_co2 = 0;

/***********************************************************************************************************************
 * IMPLEMENTACIÓN DE FUNCIONES
 **********************************************************************************************************************/

/**
 * @brief Inicializa el sensor T6793.
 */
void t6793_inicializar(void) {
  while (!t6793_sensor.begin()) {
    DEBUG_ERROR("Could not find a valid T67XX sensor, please check wiring");  // Mensaje de error si el sensor no es detectado.
    delay(2000);                                                                         // Espera 2 segundos antes de reintentar.
  }
  DEBUG_INFO("Connection with T67XX sensor established");  // Mensaje de éxito.
  t6793_sensor.reset();                                               // Reinicia el sensor para asegurar un estado conocido.

  uint16_t sensorStatus = t6793_sensor.getStatus();  // Lee el estado inicial del sensor.
  // Espera a que el sensor salga del estado de calentamiento o cualquier otro estado de error inicial.
  while (sensorStatus) {
    DEBUG_INFO("T67XX Status: %s", t6793_sensor.getStatusMsg().c_str());  // Imprime el mensaje de estado actual.
    delay(T67XX_MEASURE_DELAY);                                              // Espera el tiempo de medición recomendado.
    sensorStatus = t6793_sensor.getStatus();                                 // Vuelve a leer el estado.
  }
  DEBUG_INFO("Sensor firmware version: %u", t6793_sensor.getFirmwareVersion());  // Imprime la versión del firmware.
  DEBUG_INFO("Enabling ABC self-calibration");                                   // Mensaje informativo.
  // Deshabilita la calibración automática (ABC).
  // Esto es recomendable en aplicaciones donde el sensor no está expuesto
  // regularmente a aire fresco (400 ppm de CO2).
  t6793_sensor.setABCMode(ABC_LOGIC_ON);
  DEBUG_INFO("ABC self-calibration enabled.");

  DEBUG_INFO("Saving settings to flash");  // Mensaje informativo.
  t6793_sensor.flashUpdate();                         // Guarda las configuraciones en la memoria flash del sensor.
}

/**
 * @brief Lee la concentración de CO2 del sensor.
 */
bool t6793_leer(void) {
  uint16_t sensorStatus = t6793_sensor.getStatus();
  if (sensorStatus & (~(1u >> 0x0F) & 0x01)) {
    DEBUG_WARN("Lectura de CO2 invalida (0 PPM). T67XX Status: %s", t6793_sensor.getStatusMsg().c_str());
    t6793_co2 = 0;
    return false;
  }

  t6793_co2 = t6793_sensor.readPPM();

  DEBUG_INFO("CO2: %u ppm", t6793_co2);

  return true;
}
