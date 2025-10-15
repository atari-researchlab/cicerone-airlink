/**
 * @file    T6793_API.h
 * @brief   Header for the Telaire T6793-5K CO2 sensor API.
 * @details Declares functions and global variables for this specific sensor, using the
 * T67XX base library.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  This module is an abstraction layer over the T67XX library.
 */

#ifndef T6793_API_H
#define T6793_API_H

#include <Arduino.h>

extern uint16_t t6793_co2;

/**
 * @brief Initializes the T6793 sensor, configures I2C communication and disables ABC
 * calibration.
 */
void t6793_inicializar(void);

/**
 * @brief   Reads the CO2 value from the sensor and updates the global variable 't6793_co2'.
 * @return  True if the reading was successful.
 */
bool t6793_leer(void);

#endif  // T6793_API_H
