/**
 * @file  SEN5X_API.cpp
 * @brief Implementation of functions for reading and initializing the SEN5X sensor.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  This module is an abstraction layer over the SensirionI2CSen5x library.
 */

#include <SensirionI2CSen5x.h>
#include "SEN5X_API.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_SEN5X  //!< Redefinition of debug level for this source file.
#define DEBUG_TAG "SEN5X_API"    //!< Tag when sending debug messages.

/**
 * @name      Global variables
 * @details   Here memory is allocated for the global variables of sensor values.
 * @{
 */
float sen5x_mc_1p0 = 0.0f;   //!< PM1.0 mass concentration
float sen5x_mc_2p5 = 0.0f;   //!< PM2.5 mass concentration
float sen5x_mc_4p0 = 0.0f;   //!< PM4.0 mass concentration
float sen5x_mc_10p0 = 0.0f;  //!< PM10 mass concentration
float sen5x_hum = 0.0f;      //!< Relative humidity
float sen5x_temp = 0.0f;     //!< Temperature
float sen5x_voc = 0.0f;      //!< Volatile Organic Compounds (VOC) index
float sen5x_nox = 0.0f;      //!< Nitrogen Oxides (NOx) index
//!@}

SensirionI2CSen5x sen5x;  //!< Instance of Sensirion library object for the SEN5X sensor.

void sen5x_inicializar(void) {
  Wire.begin();
  sen5x.begin(Wire);  // Start I2C communication.

  uint16_t error;

  // Reset the sensor to ensure a known state.
  error = sen5x.deviceReset();
  if (error) {
    DEBUG_ERROR("Error resetting device.");
  }

  // Start measurements. The sensor will measure continuously in the background.
  error = sen5x.startMeasurement();
  if (error) {
    DEBUG_ERROR("Error starting measurements.");
  }

  DEBUG_INFO("Sensor initialized.");
}

bool sen5x_leer(void) {
  uint16_t error;

  // Read measured values from the sensor
  error = sen5x.readMeasuredValues(
    sen5x_mc_1p0, sen5x_mc_2p5, sen5x_mc_4p0, sen5x_mc_10p0,
    sen5x_hum, sen5x_temp, sen5x_voc, sen5x_nox);

  if (error) {
    DEBUG_ERROR("Error reading data.");
    return false;
  } else {
    // Print the read values if debug level is high
    DEBUG_INFO("Temp: %f", sen5x_temp);
    DEBUG_INFO("Hum: %f", sen5x_hum);
    DEBUG_INFO("PM1.0: %f", sen5x_mc_1p0);
    DEBUG_INFO("PM2.5: %f", sen5x_mc_2p5);
    DEBUG_INFO("PM4.0: %f", sen5x_mc_4p0);
    DEBUG_INFO("PM10.0: %f", sen5x_mc_10p0);
    DEBUG_INFO("VOC: %f", sen5x_voc);
    DEBUG_INFO("NOx: %f", sen5x_nox);
    return true;
  }
}
