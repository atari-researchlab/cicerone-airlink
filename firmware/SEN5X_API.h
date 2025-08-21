/***********************************************************************************************************************
 * @file        SEN5X_API.h
 * @brief       Cabecera para la API del sensor Sensirion SEN5X.
 * @details     Declara las funciones y variables globales para interactuar con el sensor.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note        Este módulo es una capa de abstracción sobre la librería SensirionI2CSen5x.
 **********************************************************************************************************************/

#ifndef SEN5X_API_H
#define SEN5X_API_H
#include <Arduino.h>
/**
 * @{
 * @name      Variables globales externas
 * @details   Estas variables almacenan las últimas lecturas del sensor y son accesibles
 * desde otros módulos que incluyan este archivo.
 */
extern float sen5x_mc_1p0;
extern float sen5x_mc_2p5;
extern float sen5x_mc_4p0;
extern float sen5x_mc_10p0;
extern float sen5x_hum;
extern float sen5x_temp;
extern float sen5x_voc;
extern float sen5x_nox;
/**@}*/

void sen5x_inicializar(void);
bool sen5x_leer(void);

#endif  // SEN5X_API_H
