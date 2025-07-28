/***********************************************************************************************************************
 * @file        T6793_API.h
 * @brief       Cabecera para la API del sensor de CO2 Telaire T6793-5K.
 * Declara las funciones y variables globales para este sensor específico,
 * utilizando la librería base T67XX.
 *
 * @author      [TU_NOMBRE_AQUÍ / ALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Este módulo es una capa de abstracción sobre la librería T67XX.
 **********************************************************************************************************************/

#ifndef T6793_API_H
#define T6793_API_H

#include <Arduino.h>

/***********************************************************************************************************************
 * DECLARACIONES 'EXTERN' DE VARIABLES GLOBALES
 **********************************************************************************************************************/

// Almacena la última lectura de CO2 en PPM.
extern uint16_t t6793_co2;

/***********************************************************************************************************************
 * DECLARACIÓN DE FUNCIONES PÚBLICAS
 **********************************************************************************************************************/

/**
 * @brief Inicializa el sensor T6793.
 * Configura la comunicación I2C y deshabilita la calibración ABC.
 * @return void
 */
void t6793_inicializar(void);

/**
 * @brief Lee el valor de CO2 del sensor.
 * Actualiza la variable global 't6793_co2'.
 * @return Verdadero si la lectura ha sido correcta
 */
bool t6793_leer(void);

#endif  // T6793_API_H
