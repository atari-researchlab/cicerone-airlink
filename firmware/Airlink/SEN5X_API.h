/***********************************************************************************************************************
 * @file        SEN5X_API.h
 * @brief       Cabecera para la API del sensor Sensirion SEN5X.
 * Declara las funciones y variables globales para interactuar con el sensor.
 *
 * @author      [TALD-DSL/ATARI-UCA]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Este módulo depende de la librería I2C de Sensirion.
 * Asegúrate de dar la atribución correspondiente a Sensirion AG.
 **********************************************************************************************************************/

#ifndef SEN5X_API_H
#define SEN5X_API_H

/***********************************************************************************************************************
 * DECLARACIONES 'EXTERN' DE VARIABLES GLOBALES
 * Estas variables almacenan las últimas lecturas del sensor y son accesibles
 * desde otros módulos que incluyan este archivo.
 **********************************************************************************************************************/

extern float sen5x_mc_1p0;   // Concentración de masa PM1.0
extern float sen5x_mc_2p5;   // Concentración de masa PM2.5
extern float sen5x_mc_4p0;   // Concentración de masa PM4.0
extern float sen5x_mc_10p0;  // Concentración de masa PM10
extern float sen5x_hum;      // Humedad relativa
extern float sen5x_temp;     // Temperatura
extern float sen5x_voc;      // Índice de Compuestos Orgánicos Volátiles (VOC)
extern float sen5x_nox;      // Índice de Óxidos de Nitrógeno (NOx)

/***********************************************************************************************************************
 * DECLARACIÓN DE FUNCIONES PÚBLICAS
 **********************************************************************************************************************/

/**
 * @brief Inicializa el sensor SEN5X.
 * Busca el sensor en el bus I2C, lo reinicia y comienza las mediciones.
 * @return void
 */
void sen5x_inicializar(void);

/**
 * @brief Lee los últimos datos medidos por el sensor.
 * Actualiza las variables globales 'sen5x_...' con los nuevos valores.
 * @return Verdadero si la lectura ha sido correcta
 */
bool sen5x_leer(void);

#endif  // SEN5X_API_H
