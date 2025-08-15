/***********************************************************************************************************************
 * @file        Debug.h
 * @brief       Cabecera para la gestión de mensajes de depuración.
 * @details     Define un conjunto de macros que permiten imprimir mensajes en el puerto serie
 * dependiendo de un nivel de depuración establecido en "Configuracion.h".
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 **********************************************************************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

/**
 * @def TEST_MINUTAL
 * @brief Descomenta la siguiente línea para habilitar la transmisión de promedios minutales.
 * @details Útil para depurar el envío de mensajes o la comunicación con los sensores.
 */
#define TEST_MINUTAL 1

/**
 * @{
 * @name Configuración de los mensajes de depuración.
 * @details Controla la cantidad de información de cada módulo que se imprime en el Monitor Serie cada módulo
 * y de forma global. Si el nivel de depuración es 0, todas las macros de depuración se definen como vacías.
 * El compilador las optimizará y las eliminará del código final, ahorrando memoria.
 *
 *   - 0 = Sin depuración. Ahorra memoria y hace el programa más rápido.
 *   - 1 = Errores (ERROR): Muestra solo mensajes críticos.
 *   - 2 = Advertencias (WARN): Muestra errores y advertencias importantes.
 *   - 3 = Información (INFO): Muestra el flujo general del programa (recomendado para depuración normal).
 *   - 4 = Detallado (VERBOSE): Muestra información muy detallada, como lecturas de sensores cada 5s.
 */
#define DEBUG_LEVEL 3    //!< Nivel de depuración global
#define DEBUG_ALARMA 2   //!< Controla la cantidad de información de depuración del bucle de adquisición y promediado.
#define DEBUG_SEN5X 2    //!< Controla la cantidad de información de depuración del sensor SEN5X.
#define DEBUG_T6793 2    //!< Controla la cantidad de información de depuración del sensor T6793K (CO2).
#define DEBUG_DS3231M 2  //!< Controla la cantidad de información depuración del RTC.
#define DEBUG_NBIOT 2    //!< Controla la cantidad de información del módulo NB-IoT.
/**@}*/

#include <stdarg.h>  // Necesario para va_list, va_start, va_end
#include <stdio.h>   // Necesario para snprintf

#define DEBUG_PRINTF_BUFFER_SIZE 256                        //!< Ajusta el tamaño según la longitud máxima esperada de los mensajes a enviar.
static char debug_printf_buffer[DEBUG_PRINTF_BUFFER_SIZE];  //!< Buffer para los mensajes de depuración formateados.

#if DEBUG_LEVEL == 0
#define DEBUG_ERROR(format, ...)
#define DEBUG_WARN(format, ...)
#define DEBUG_INFO(format, ...)
#define DEBUG_VERBOSE(format, ...)

#else  // Si el nivel de depuración es > 0, se definen las macros para imprimir en el Serial.

/**
 * @fn DEBUG_PRINT_PREFIX(level)
 * @brief Define un prefijo común para todos los mensajes de depuración.
 * @details Utiliza la macro DEBUG_TAG que debe ser definida en cada archivo .cpp para identificar 
 * el origen del mensaje.
 * @verbatim [level][millis()][DEBUG_TAG] @endverbatim
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
 * @{
 * @name Macros de depuración.
 * @brief Se utilizan al igual que la función @c printf(). Agregan automaticamente el nivel de DEBUG, 
 * los millis actuales a modo de _timestamp_ y el módulo que lo generó.
 * @details Ejemplo:
 * @code{.cpp}
    DEBUG_ERROR("No es posible establecer la comunicación con el RTC");
 * @endcode
 *
 * @verbatim [ERROR][1543][RTC] No es posible establecer la comunicación con el RTC @endverbatim
 */

/**
 * @fn DEBUG_ERROR(format, ...)
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
 * @fn DEBUG_WARN(format, ...)
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
 * @fn DEBUG_INFO(format, ...)
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
 * @fn DEBUG_VERBOSE(format, ...)
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
/**@}*/

#endif  // DEBUG_LEVEL == 0

#endif  // DEBUG_H
