/**
 * @file    Alarma.h
 * @brief   Cabecera para la gestión de alarmas temporizadas y promedio de datos.
 * @details Declara las funciones y variables globales para controlar tareas periódicas
 * (ej. cada 5s, cada 10min) y para manejar los datos de los sensores.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 */

#ifndef ALARMA_H
#define ALARMA_H
 
#include <Arduino.h>
#include "DS3231M.h"

/* Declaración de las variables globales con el atributo **extern**. Este indica que estas 
 * variables existen, pero se  definen (se les asigna memoria) en otro archivo como Alarma.cpp. 
 * Esto permite que sean accesibles desde cualquier otro módulo que incluya Alarma.h.
 */
extern bool alarma_10min;
extern bool alarma_5s;
extern unsigned long prev_millis;
extern uint8_t minuto_actual;
extern uint8_t minuto_siguiente;
extern float sum_sen5x_voc;
extern float sum_sen5x_mc_1p0;
extern float sum_sen5x_mc_2p5;
extern float sum_sen5x_mc_4p0;
extern float sum_sen5x_mc_10p0;
extern float sum_temp;
extern float sum_hum;
extern float sum_sen5x_nox;
extern float sum_t6793_co2;
extern float avg_sen5x_voc;
extern float avg_sen5x_mc_1p0;
extern float avg_sen5x_mc_2p5;
extern float avg_sen5x_mc_4p0;
extern float avg_sen5x_mc_10p0;
extern float avg_temp;
extern float avg_hum;
extern float avg_sen5x_nox;
extern float avg_t6793_co2;

extern DS3231M rtc;
extern DateTime now;
extern String fecha;
extern String hora;

/**
 * @brief   Inicializa el módulo RTC y configura la primera alarma de 10 minutos.
 * @details Configura el RTC con una fecha y hora iniciales si es necesario, o lo sincroniza.
 * Esta función debe ser llamada en 'setup()'.
 */
void rtc_alarma_inicializar(void);

/**
 * @brief Comprueba si han pasado 5 segundos utilizando millis(). Si es así, activa la bandera alarma_5s.
 * @note  Debe llamarse continuamente en el loop principal.
 */
void check_alarma_5s(void);

/**
 * @brief   Lee los datos de todos los sensores y los acumula para el promedio.
 * @details Llama a las funciones de lectura de los módulos SEN55 y T6793 y suma sus valores
 * a los acumuladores \a sum_* correspondientes. Incrementa los contadores de promedio.
 */
void acumular_datos(void);

/**
 * @brief   Verifica si se ha completado el ciclo de 10 minutos. Si es así, activa la bandera alarma_10min.
 * @details Comprueba la hora del RTC para ver si se ha alcanzado el siguiente intervalo de 10
 * minutos (ej: 12:10, 12:20).
 * @note    Debe llamarse continuamente en el loop principal.
 */
void check_alarma_10min(void);

/**
 * @brief   Procesa los datos acumulados para calcular los promedios y los almacena.
 * @details Esta función se llama al final de cada período de promedio (ej. cada 10 minutos)
 * y los promedios se guardan en las variables \a avg_* correspondientes.
 */
void promediar_datos(void);

/**
 * @brief Reinicia los contadores y acumuladores.
 */
void reset_acumuladores(void);

#endif  // ALARMA_H