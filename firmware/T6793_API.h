/***********************************************************************************************************************
 * @file        T6793_API.h
 * @brief       Cabecera para la API del sensor de CO2 Telaire T6793-5K.
 * @details     Declara las funciones y variables globales para este sensor específico,
 * utilizando la librería base T67XX.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note        Este módulo es una capa de abstracción sobre la librería T67XX.
 **********************************************************************************************************************/

#ifndef T6793_API_H
#define T6793_API_H

#include <Arduino.h>

extern uint16_t t6793_co2;

void t6793_inicializar(void);
bool t6793_leer(void);

#endif  // T6793_API_H
