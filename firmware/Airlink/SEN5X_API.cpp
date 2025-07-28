/***********************************************************************************************************************
 * @file        SEN5X_API.cpp
 * @brief       Implementación de las funciones para la lectura e inicialización del sensor Sensirion SEN5X.
 *
 * @author      [ALD-DSL/ATARI-UCA] (Basado en la integración de la librería Sensirion)
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Este módulo utiliza la librería 'SensirionI2CSen5x' de Sensirion.
 * Copyright (c) 2021, Sensirion AG
 * Licencia: BSD-3-Clause
 **********************************************************************************************************************/
#include <Arduino.h>
#include <SensirionI2CSen5x.h>  // Librería de Sensirion. Licencia: BSD-3-Clause.
#include "SEN5X_API.h"
#include "Debug.h"              // Contiene las macros para controlar la salida de depuración por Serial.

// Etiqueta para los mensajes de depuración de este módulo.
#define DEBUG_TAG "SEN5X_API"
#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_SEN5X

// Instancia del objeto de la librería de Sensirion para el sensor SEN5X.
SensirionI2CSen5x sen5x;

/***********************************************************************************************************************
 * DEFINICIÓN DE VARIABLES GLOBALES
 * Asignación de memoria para las variables declaradas como 'extern' en el .h
 **********************************************************************************************************************/
float sen5x_mc_1p0, sen5x_mc_2p5, sen5x_mc_4p0, sen5x_mc_10p0, sen5x_hum, sen5x_temp, sen5x_voc, sen5x_nox;

/***********************************************************************************************************************
 * IMPLEMENTACIÓN DE FUNCIONES
 **********************************************************************************************************************/

/**
 * @brief Inicializa el sensor SEN5X.
 */
void sen5x_inicializar(void) {
  Wire.begin();
  sen5x.begin(Wire);  // Inicia la comunicación I2C.

  uint16_t error;
  char errorMessage[256];

  // Reinicia el sensor para asegurar un estado conocido.
  error = sen5x.deviceReset();
  if (error) {
    DEBUG_ERROR("Error al reiniciar el dispositivo SEN5X.");
  }

  // Inicia las mediciones. El sensor medirá continuamente en segundo plano.
  error = sen5x.startMeasurement();
  if (error) {
    DEBUG_ERROR("Error al iniciar las mediciones del SEN5X.");
  }
}

/**
 * @brief Lee los datos del sensor y los almacena en las variables globales.
 */
bool sen5x_leer(void) {
  uint16_t error;

  // Lee los valores medidos del sensor.
  error = sen5x.readMeasuredValues(
    sen5x_mc_1p0, sen5x_mc_2p5, sen5x_mc_4p0, sen5x_mc_10p0,
    sen5x_hum, sen5x_temp, sen5x_voc, sen5x_nox);

  if (error) {
    DEBUG_ERROR("Error al leer los datos del SEN5X.");
    return false;
  } else {
    // Imprime los valores leídos si el nivel de depuración es alto.
    DEBUG_INFO("Temp: %f", sen5x_temp);
    DEBUG_INFO("Hum: %f", sen5x_hum);
    DEBUG_INFO("PM1.0: %f", sen5x_mc_1p0);
    DEBUG_INFO("PM2.5: %f", sen5x_mc_2p5);
    DEBUG_INFO("PM4.0: %f", sen5x_mc_4p0);
    DEBUG_INFO("PM10.0: %f", sen5x_mc_10p0);
    DEBUG_INFO("VOC: %f", sen5x_voc);
    // DEBUG_INFO("NOx: %f", sen5x_nox);
    return true;
  }
  
}
