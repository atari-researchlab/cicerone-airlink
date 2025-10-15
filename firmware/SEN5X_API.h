/**
 * @file    SEN5X_API.h
 * @brief   Header for the Sensirion SEN5X sensor API.
 * @details Declares functions and global variables for interacting with the sensor.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  This module is an abstraction layer over the SensirionI2CSen5x library.
 */

#ifndef SEN5X_API_H
#define SEN5X_API_H
#include <Arduino.h>
 
/**
 * @name    External global variables
 * @details These variables store the latest sensor readings and are accessible
 * from other modules that include this file.
 * @{
 */
extern float sen5x_mc_1p0;
extern float sen5x_mc_2p5;
extern float sen5x_mc_4p0;
extern float sen5x_mc_10p0;
extern float sen5x_hum;
extern float sen5x_temp;
extern float sen5x_voc;
extern float sen5x_nox;
//!@}

/**
 * @brief   Initializes the SEN5X sensor.
 * @details Searches for the sensor on the I2C bus, resets it, and starts measurements.
 */
void sen5x_inicializar(void);

/**
 * @brief Reads the latest data measured by the sensor and updates the global variables
 * @c sen5x_* with the new values.
 *
 * @return  True if the reading was successful
 */
bool sen5x_leer(void);

#endif  // SEN5X_API_H
