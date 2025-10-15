/**
 * @file        Debug.h
 * @brief       Header for debug message management.
 * @details     Defines a set of macros that allow printing messages to the serial port
 * depending on a debug level set in "Configuracion.h".
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22/2025-10-15]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 */

#ifndef DEBUG_H
#define DEBUG_H

/**
 * @brief Uncomment the following line to enable per-minute average transmission.
 * @details Useful for debugging message sending or sensor communication.
 */
#define TEST_MINUTAL 1

/**
 * @name Debug message configuration.
 * @details Controls the amount of information printed to the Serial Monitor for each module
 * and globally. If the debug level is 0, all debug macros are defined as empty.
 * The compiler will optimize and remove them from the final code, saving memory.
 *
 *   - 0 = No debugging. Saves memory and makes the program faster.
 *   - 1 = Errors (ERROR): Shows only critical messages.
 *   - 2 = Warnings (WARN): Shows errors and important warnings.
 *   - 3 = Information (INFO): Shows general program flow (recommended for normal debugging).
 *   - 4 = Verbose (VERBOSE): Shows very detailed information, such as sensor readings every 5s.
 * @{
 */
#define DEBUG_LEVEL 3    //!< Global debug level
#define DEBUG_ALARMA 2   //!< Controls debug information for acquisition and averaging loop.
#define DEBUG_SEN5X 2    //!< Controls debug information for SEN5X sensor.
#define DEBUG_T6793 2    //!< Controls debug information for T6793K sensor (CO2).
#define DEBUG_DS3231M 2  //!< Controls debug information for RTC.
#define DEBUG_NBIOT 2    //!< Controls debug information for NB-IoT module.
//!@}

#include <Arduino.h>
#include <stdarg.h>  // Required for va_list, va_start, va_end
#include <stdio.h>   // Required for snprintf

#define DEBUG_PRINTF_BUFFER_SIZE 256                        //!< Adjust size according to expected maximum message length.
static char debug_printf_buffer[DEBUG_PRINTF_BUFFER_SIZE];  //!< Buffer for formatted debug messages.

#if DEBUG_LEVEL == 0
#define DEBUG_ERROR(format, ...)
#define DEBUG_WARN(format, ...)
#define DEBUG_INFO(format, ...)
#define DEBUG_VERBOSE(format, ...)

#else  // If debug level is > 0, macros are defined to print to Serial.

/**
 * @brief Defines a common prefix for all debug messages.
 * @details Uses the DEBUG_TAG macro which must be defined in each .cpp file to identify
 * the message source.
 *
 * ``` [level][millis()][DEBUG_TAG] ```
 */
#define DEBUG_PRINT_PREFIX(level) \
  Serial.print(F("[")); \
  Serial.print(level); \
  Serial.print(F("][")); \
  Serial.print(millis()); \
  Serial.print(F("][")); \
  Serial.print(DEBUG_TAG); \
  Serial.print(F("] "))

/**
 * @name Debug macros.
 * @brief Used like the @c printf() function. Automatically adds the DEBUG level,
 * current millis as a _timestamp_, and the module that generated it.
 * @details Example:
 *
 * @code{.cpp}
    DEBUG_ERROR("Unable to establish communication with RTC");
 * @endcode
 *
 * ``` [ERROR][1543][RTC] Unable to establish communication with RTC ```
 * @{
 */

/**
 * @brief DEBUG_LEVEL >= 1
 */
#define DEBUG_ERROR(format, ...) \
  if (DEBUG_LEVEL >= 1) { \
    DEBUG_PRINT_PREFIX("ERROR"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

/**
 * @brief DEBUG_LEVEL >= 2
 */
#define DEBUG_WARN(format, ...) \
  if (DEBUG_LEVEL >= 2) { \
    DEBUG_PRINT_PREFIX("WARN"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

/**
 * @brief DEBUG_LEVEL >= 3
 */
#define DEBUG_INFO(format, ...) \
  if (DEBUG_LEVEL >= 3) { \
    DEBUG_PRINT_PREFIX("INFO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

/**
 * @brief DEBUG_LEVEL >= 4
 */
#define DEBUG_VERBOSE(format, ...) \
  if (DEBUG_LEVEL >= 4) { \
    DEBUG_PRINT_PREFIX("VERBO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }
//!@}

#endif  // DEBUG_LEVEL == 0

#endif  // DEBUG_H
