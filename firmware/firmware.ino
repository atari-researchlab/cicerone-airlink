/***********************************************************************************************************************
 * @file        firmware.ino
 * @brief       Main code for an air quality monitoring system ("Airlink").
 * @details     This program integrates readings from various sensors and manages their operation
 * through non-blocking timers (millis). It includes optional modules
 * for data transmission via NB-IoT and for cough detection using Edge Impulse.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22 / Last Modified]
 * @version     1.0-rc1
 *
 * @copyright   GNU General Public License version 3 or later
 * @warning     Server values and APN must be correctly configured to use the IoT module.
 * @see         Configuracion.h
 **********************************************************************************************************************/

#include "Configuracion.h"  // Central configuration file to enable/disable modules.
#include "Debug.h"          // Contains macros to control debug output via Serial.
#include "Alarma.h"         // Custom module for timer management (periodic alarms).
#include "SEN5X_API.h"      // API for handling the Sensirion SEN5X sensor.
#include "T6793_API.h"      // API for handling the T6793-5K CO2 sensor.

// --- Conditional module inclusion (controlled from Configuracion.h) ---
#if HABILITAR_NBIOT
#include "Transmision_NBIOT.h"  // Module for data transmission via Narrowband IoT.
#endif

#define DEBUG_TAG "MAIN"  //!< Tag when sending debug messages

/**
 * @brief Initializes communications, sensors, and system modules.
 * Runs only once when the microcontroller is powered on or reset.
 */
void setup() {
  // Serial port initialization if debugging is enabled in Configuracion.h
#if (DEBUG_LEVEL >= 1)
  Serial.begin(115200);
  // On some boards (like ESP32), it's useful to wait for the serial port to connect.
  while (!Serial) {
    ;  // Wait loop
  }
#endif

  DEBUG_INFO("**********************************************");
  DEBUG_INFO("*       AIRLINK Monitoring System            *");
  DEBUG_INFO("**********************************************");
  DEBUG_INFO("Initializing system...");

  // Initialize the RTC (Real-Time Clock) and periodic alarms
  rtc_alarma_inicializar();

  // Initialize the T6793 sensor
  t6793_inicializar();

  // Initialize the SEN5X sensor
  sen5x_inicializar();

  // Conditional module initialization
#if HABILITAR_NBIOT
  nbiot_inicializar();
#endif

  DEBUG_INFO("Initialization completed. Starting main loop.");
}

/**
 * @brief Runs repeatedly after setup() has finished.
 * This is the heart of the program, where periodic tasks are checked and executed.
 */
void loop() {
  // Check if the 5-second alarm has been triggered to read sensors.
  // This function is non-blocking and based on millis().
  check_alarma_5s();

  // Check if the 10-minute alarm has been triggered to average and send data.
  // This function is based on the RTC clock.
  check_alarma_10min();

  // If the 5-second flag is active, execute the readings.
  if (alarma_5s) {
    DEBUG_INFO("5s alarm triggered. Reading sensors...");

    // Accumulate the read data for later averaging
    acumular_datos();

    // Reset the flag for the next iteration
    alarma_5s = false;
  }

  // If the 10-minute flag is active, execute averaging and transmission.
  if (alarma_10min) {
    DEBUG_INFO("10min alarm triggered. Processing and sending data...");

    // Calculate the average of accumulated readings
    promediar_datos();

// Transmit the averaged data if the module is enabled
#if HABILITAR_NBIOT
    nbiot_enviar();
#endif

    // Reset the flag for the next iteration
    alarma_10min = false;
  }
}
