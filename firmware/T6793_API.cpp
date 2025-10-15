/**
 * @file    T6793_API.cpp
 * @brief   Implementation of the API for the Telaire T6793-5K CO2 sensor.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  This module is an abstraction layer over the T67XX library.
 */

#include "T6793_API.h"
#include "T67XX.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793  //!< Redefinition of debug level for this source file.
#define DEBUG_TAG "T6793_API"    //!< Tag when sending debug messages.

T67XX t6793_sensor;      //!< Instance of the library object for the sensor.
uint16_t t6793_co2 = 0;  //!< Definition of the global variable.

void t6793_inicializar(void) {
  uint16_t sensorStatus = 1;

  while (!t6793_sensor.begin()) {
    DEBUG_ERROR("Sensor could not be found, check connections");  // Error message if sensor is not detected.
    delay(2000);                                                  // Wait 2 seconds before retrying.
  }
  DEBUG_INFO("Connection established. Resetting...");  // Success message.
  t6793_sensor.reset();                                // Reset the sensor to ensure a known state.

  // Wait for the sensor to exit warm-up state or any other initial error state.
  do {
    sensorStatus = t6793_sensor.getStatus();                        // Read initial sensor status.
    DEBUG_INFO("Status: %s", t6793_sensor.getStatusMsg().c_str());  // Print current status message.
    delay(T67XX_MEASURE_DELAY);                                     // Wait for recommended measurement time.
  } while (sensorStatus);

  DEBUG_INFO("Firmware version: %u", t6793_sensor.getFirmwareVersion());  // Print firmware version.

  DEBUG_VERBOSE("Enabling autocalibration...");  // Informational message.
  /* Enable automatic calibration (ABC).
   * This is recommended in applications where the sensor is regularly
   * exposed to fresh air (400 ppm CO2). */
  t6793_sensor.enableABCMode();
  DEBUG_INFO("Autocalibration enabled...");

  DEBUG_INFO("Saving configuration...");  // Informational message.
  t6793_sensor.flashUpdate();             // Save settings to sensor's flash memory.

  DEBUG_INFO("Sensor initialized.");
}

bool t6793_leer(void) {
  uint16_t sensorStatus = t6793_sensor.getStatus();
  if (sensorStatus & (~(1u >> 0x0F) & 0x01)) {
    DEBUG_WARN("Invalid CO2 reading (0 PPM). Status: %s", t6793_sensor.getStatusMsg().c_str());
    t6793_co2 = 0;
    return false;
  }

  t6793_co2 = t6793_sensor.readPPM();

  DEBUG_INFO("CO2: %u ppm", t6793_co2);

  return true;
}
