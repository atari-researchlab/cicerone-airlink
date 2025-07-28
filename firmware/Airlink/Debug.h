/***********************************************************************************************************************
 * @file        Debug.h
 * @brief       Cabecera para la gestión de mensajes de depuración.
 * Define un conjunto de macros que permiten imprimir mensajes en el puerto serie
 * dependiendo de un nivel de depuración establecido en "Configuracion.h".
 *
 * @author      [TU_NOMBRE_AQUÍ / ALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 **********************************************************************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

// Descomenta la siguiente línea para habilitar la transmisión de promedios minutales.
#define TEST_MINUTAL 1

/***********************************************************************************************************************
 * CONFIGURACIÓN DEL PUERTO SERIE (DEBUG)
 * Controla la cantidad de información de cada módulo que se imprime en el Monitor Serie.
 * 0 = Sin depuración. Ahorra memoria y hace el programa más rápido.
 * 1 = Errores (ERROR): Muestra solo mensajes críticos.
 * 2 = Advertencias (WARN): Muestra errores y advertencias importantes.
 * 3 = Información (INFO): Muestra el flujo general del programa (recomendado para depuración normal).
 * 4 = Detallado (VERBOSE): Muestra información muy detallada, como lecturas de sensores cada 5s.
 **********************************************************************************************************************/
#define DEBUG_LEVEL 3
// Controla la cantidad de información de depuración del bucle de adquisición y promediado.
#define DEBUG_ALARMA 2
// Controla la cantidad de información de depuración del sensor SEN5X.
#define DEBUG_SEN5X 2
// Controla la cantidad de información de depuración del sensor T6793K (CO2).
#define DEBUG_T6793 2
// Controla la cantidad de información depuración del RTC.
#define DEBUG_DS3231M 2
// Controla la cantidad de información del módulo NB-IoT.
#define DEBUG_NBIOT 2
// Controla la cantidad de información del módulo de tos.
// #define DEBUG_TOS 4

#include <stdarg.h>  // Necesario para va_list, va_start, va_end
#include <stdio.h>   // Necesario para snprintf

// Buffer para los mensajes de depuración formateados.
// Ajusta el tamaño según la longitud máxima esperada de tus mensajes.
#define DEBUG_PRINTF_BUFFER_SIZE 256
static char debug_printf_buffer[DEBUG_PRINTF_BUFFER_SIZE];

// Si el nivel de depuración es 0, todas las macros de depuración se definen como vacías.
// El compilador las optimizará y las eliminará del código final, ahorrando memoria.
#if DEBUG_LEVEL == 0
#define DEBUG_ERROR(format, ...)
#define DEBUG_WARN(format, ...)
#define DEBUG_INFO(format, ...)
#define DEBUG_VERBOSE(format, ...)

#else  // Si el nivel de depuración es > 0, se definen las macros para imprimir en el Serial.

// Define un prefijo común para todos los mensajes de depuración.
// Utiliza la macro DEBUG_TAG que debe ser definida en cada archivo .cpp para identificar el origen del mensaje.
#define DEBUG_PRINT_PREFIX(level) \
  Serial.print(F("[")); \
  Serial.print(level); \
  Serial.print(F("][")); \
  Serial.print(millis()); \
  Serial.print(F("][")); \
  Serial.print(DEBUG_TAG); \
  Serial.print(F("] "))

// --- MACROS DE IMPRESIÓN ---

// DEBUG_ERROR: Siempre se imprime si DEBUG_LEVEL >= 1
#define DEBUG_ERROR(format, ...) \
  if (DEBUG_LEVEL >= 1) { \
    DEBUG_PRINT_PREFIX("ERROR"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

// DEBUG_WARN: Se imprime si DEBUG_LEVEL >= 2
#define DEBUG_WARN(format, ...) \
  if (DEBUG_LEVEL >= 2) { \
    DEBUG_PRINT_PREFIX("WARN"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

// DEBUG_INFO: Se imprime si DEBUG_LEVEL >= 3
#define DEBUG_INFO(format, ...) \
  if (DEBUG_LEVEL >= 3) { \
    DEBUG_PRINT_PREFIX("INFO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

// DEBUG_VERBOSE: Se imprime si DEBUG_LEVEL >= 4
#define DEBUG_VERBOSE(format, ...) \
  if (DEBUG_LEVEL >= 4) { \
    DEBUG_PRINT_PREFIX("VERBO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

#endif  // DEBUG_LEVEL == 0

#endif  // DEBUG_H
