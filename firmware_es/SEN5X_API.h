/**
 * @file    SEN5X_API.h
 * @brief   Cabecera para la API del sensor Sensirion SEN5X.
 * @details Declara las funciones y variables globales para interactuar con el sensor.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  Este módulo es una capa de abstracción sobre la librería SensirionI2CSen5x.
 */

#ifndef SEN5X_API_H
#define SEN5X_API_H
#include <Arduino.h>
 
/**
 * @name    Variables globales externas
 * @details Estas variables almacenan las últimas lecturas del sensor y son accesibles
 * desde otros módulos que incluyan este archivo.
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
 * @brief   Inicializa el sensor SEN5X.
 * @details Busca el sensor en el bus I2C, lo reinicia y comienza las mediciones.
 */
void sen5x_inicializar(void);

/**
 * @brief Lee los últimos datos medidos por el sensor y Actualiza las variables globales 
 * @c sen5x_* con los nuevos valores.
 *
 * @return  Verdadero si la lectura ha sido correcta
 */
bool sen5x_leer(void);

#endif  // SEN5X_API_H
