/***********************************************************************************************************************
 * @file        Alarma.h
 * @brief       Cabecera para la gestión de alarmas temporizadas y promedio de datos.
 * Declara las funciones y variables globales para controlar tareas periódicas
 * (ej. cada 5s, cada 10min) y para manejar los datos de los sensores.
 *
 * @author      [TU_NOMBRE_AQUÍ / ALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Las implementaciones de estas funciones se encuentran en Alarma.cpp.
 **********************************************************************************************************************/

#ifndef ALARMA_H
#define ALARMA_H

#include <Arduino.h>
//#include <String.h>
#include "DS3231M.h"  // Librería para el RTC.

/***********************************************************************************************************************
 * DECLARACIONES 'EXTERN' DE VARIABLES GLOBALES
 * 'extern' indica que estas variables existen, pero se definen (se les asigna memoria) en Alarma.cpp.
 * Esto permite que sean accesibles desde cualquier archivo que incluya Alarma.h.
 **********************************************************************************************************************/

// --- Banderas de control de alarmas ---
extern bool alarma_10min;  // Se pone a 'true' cuando se cumple el ciclo de 10 minutos.
extern bool alarma_5s;     // Se pone a 'true' cuando se cumple el ciclo de 5 segundos.

// --- Variables para el temporizador de 5s basado en millis() ---
extern unsigned long prev_millis;  // Almacena el tiempo de la última activación de la alarma de 5s.

// --- Variables para la alarma de 10min basada en RTC ---
extern uint8_t minuto_actual;     // Guarda el minuto actual leído del RTC.
extern uint8_t minuto_siguiente;  // Calcula y guarda el próximo minuto en el que sonará la alarma (ej. 10, 20, 30...).

// --- Acumuladores para promediar las lecturas de los sensores ---
extern float sum_sen5x_voc;      // Acumulador para el índice VOC del SEN5X.
extern float sum_sen5x_mc_1p0;   // Acumulador para PM1.0 del SEN5X.
extern float sum_sen5x_mc_2p5;   // Acumulador para PM2.5 del SEN5X.
extern float sum_sen5x_mc_4p0;   // Acumulador para PM4.0 del SEN5X.
extern float sum_sen5x_mc_10p0;  // Acumulador para PM10.0 del SEN5X.
extern float sum_temp;           // Acumulador para la temperatura ambiente.
extern float sum_hum;            // Acumulador para la humedad ambiente.
extern float sum_sen5x_nox;      // Acumulador para el indice NOx del SEN55.
extern float sum_t6793_co2;      // Acumulador para CO2 del T6793.

// --- Variables para almacenar los promedios ---
extern float avg_sen5x_voc;      // Promedio del índice VOC del SEN5X.
extern float avg_sen5x_mc_1p0;   // Promedio de PM1.0 del SEN5X.
extern float avg_sen5x_mc_2p5;   // Promedio de PM2.5 del SEN5X.
extern float avg_sen5x_mc_4p0;   // Promedio de PM4.0 del SEN5X.
extern float avg_sen5x_mc_10p0;  // Promedio de PM10.0 del SEN5X.
extern float avg_temp;           // Promedio de la temperatura ambiente.
extern float avg_hum;            // Promedio de la humedad ambiente.
extern float avg_sen5x_nox;      // Promedio del indice NOx del SEN55.
extern float avg_t6793_co2;      // Promedio de CO2 del T6793.
extern int tTos;                 // Conteo total de tos detectadas en el período de promedio.

// --- Instancia del objeto RTC ---
extern DS3231M rtc;

// --- Variables globales de fecha y hora del RTC ---
extern DateTime now;  // Estructura para almacenar la fecha y hora actuales
extern String fecha;            // Cadena para almacenar la fecha actual (ej. "YYYY-MM-DD").
extern String hora;             // Cadena para almacenar la hora actual (ej. "HH:MM:SS").

/***********************************************************************************************************************
 * DECLARACIÓN DE FUNCIONES PÚBLICAS
 * Estas son las funciones que otros módulos del programa pueden llamar.
 **********************************************************************************************************************/

/**
 * @brief Inicializa el módulo RTC y configura la primera alarma de 10 minutos.
 */
void rtc_alarma_inicializar(void);

/**
 * @brief Comprueba si han pasado 5 segundos usando millis(). Si es así, activa la bandera alarma_5s.
 * Debe llamarse continuamente en el loop principal.
 */
void check_alarma_5s(void);

/**
 * @brief Comprueba la hora del RTC para ver si se ha alcanzado un intervalo de 10 minutos (ej: 12:10, 12:20).
 * Si es así, activa la bandera alarma_10min.
 */
void check_alarma_10min(void);

/**
 * @brief Acumula las últimas lecturas de los sensores en las variables 'sum_'.
 */
void acumular_datos(void);

/**
 * @brief Calcula el promedio de los datos acumulados y los guarda en las variables 'avg_'.
 */
void promediar_datos(void);

/**
 * @brief Reinicia a cero todos los contadores y acumuladores para el siguiente ciclo.
 */
void reset_acumuladores(void);

#endif  // ALARMA_H


/***********************************************************************************************************************
 * SECCIÓN DE LICENCIAS DE LIBRERÍAS EXTERNAS (ESPECÍFICAS DE ESTE ARCHIVO)
 *
 * Este archivo es parte de tu proyecto principal y está bajo la Licencia Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-SA 4.0).
 *
 * 1.  **Librería: 'DS3231M'**
 * * **Autor:** DFRobot Co.Ltd (yufeng)
 * * **Licencia:** MIT License
 * * **URL:** https://github.com/DFRobot/DS3231M/blob/master/LICENSE
 * * **Compatibilidad con CC-BY-SA 4.0:** Compatible.
 *
 * Para una descripción más detallada de la compatibilidad general de licencias, consulta la sección
 * "SECCIÓN DE LICENCIAS DE LIBRERÍAS EXTERNAS" en 'Airlink.ino'.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * SECCIÓN DE REFERENCIAS Y AGRADECIMIENTOS (ESPECÍFICAS DE ESTE ARCHIVO)
 *
 * - Datasheet del DS3231M: [Añadir URL al datasheet si está disponible públicamente]
 * - Repositorio de la librería DS3231M: https://github.com/DFRobot/DS3231M
 **********************************************************************************************************************/
