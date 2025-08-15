/***********************************************************************************************************************
 * @file        Alarma.h
 * @brief       Cabecera para la gestión de alarmas temporizadas y promedio de datos.
 * @details     Declara las funciones y variables globales para controlar tareas periódicas
 * (ej. cada 5s, cada 10min) y para manejar los datos de los sensores.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 **********************************************************************************************************************/

#ifndef ALARMA_H
#define ALARMA_H

#include "DS3231M.h"

/**
 * @{
 * @name      Variables globales externas
 * @details   El atributo **extern** indica que estas variables existen, pero se definen (se les asigna memoria) en Alarma.cpp.
 * Esto permite que sean accesibles desde cualquier archivo que incluya Alarma.h.
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
/**@}*/

/**
 * @{
 * @name      Prototipos de funciones públicas
 * @details   Estas son las funciones que otros módulos del programa pueden llamar.
 */
void rtc_alarma_inicializar(void);
void check_alarma_5s(void);
void acumular_datos(void);
void check_alarma_10min(void);
void promediar_datos(void);
void reset_acumuladores(void);
/**@}*/

#endif  // ALARMA_H