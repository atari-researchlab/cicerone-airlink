/***********************************************************************************************************************
 * @file        SEN5X_API.cpp
 * @brief       Implementación de las funciones para la lectura e inicialización del sensor Sensirion SEN5X.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note        Este módulo es una capa de abstracción sobre la librería SensirionI2CSen5x.
 **********************************************************************************************************************/

#include <SensirionI2CSen5x.h>
#include "SEN5X_API.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_SEN5X  //!< Redefinición del nivel de depuración en la compilación de este archivo fuente
#define DEBUG_TAG "SEN5X_API"    //!< Etiqueta al enviar mensajes de depuración

/**
 * @{
 * @name      Variables globales
 * @details   Aquí se asigna la memoria para las variables globales de los valores del sensor.
 */
float sen5x_mc_1p0 = 0.0f;   //!< Concentración de masa PM1.0
float sen5x_mc_2p5 = 0.0f;   //!< Concentración de masa PM2.5
float sen5x_mc_4p0 = 0.0f;   //!< Concentración de masa PM4.0
float sen5x_mc_10p0 = 0.0f;  //!< Concentración de masa PM10
float sen5x_hum = 0.0f;      //!< Humedad relativa
float sen5x_temp = 0.0f;     //!< Temperatura
float sen5x_voc = 0.0f;      //!< Índice de Compuestos Orgánicos Volátiles (VOC)
float sen5x_nox = 0.0f;      //!< Índice de Óxidos de Nitrógeno (NOx)
/**@}*/

SensirionI2CSen5x sen5x;  //!< Instancia del objeto de la librería de Sensirion para el sensor SEN5X.

/**
 * @brief     Inicializa el sensor SEN5X.
 * @details   Busca el sensor en el bus I2C, lo reinicia y comienza las mediciones.
 */
void sen5x_inicializar(void) {
  Wire.begin();
  sen5x.begin(Wire);  // Inicia la comunicación I2C.

  uint16_t error;

  // Reinicia el sensor para asegurar un estado conocido.
  error = sen5x.deviceReset();
  if (error) {
    DEBUG_ERROR("Error al reiniciar el dispositivo.");
  }

  // Inicia las mediciones. El sensor medirá continuamente en segundo plano.
  error = sen5x.startMeasurement();
  if (error) {
    DEBUG_ERROR("Error al iniciar las mediciones.");
  }

  DEBUG_INFO("Sensor inicializado.");
}

/**
 * @brief   Lee los últimos datos medidos por el sensor y Actualiza las variables globales @c sen5x_* con los nuevos valores.
 * @return  Verdadero si la lectura ha sido correcta
 */
bool sen5x_leer(void) {
  uint16_t error;

  // Lee los valores medidos del sensor
  error = sen5x.readMeasuredValues(
    sen5x_mc_1p0, sen5x_mc_2p5, sen5x_mc_4p0, sen5x_mc_10p0,
    sen5x_hum, sen5x_temp, sen5x_voc, sen5x_nox);

  if (error) {
    DEBUG_ERROR("Error al leer los datos.");
    return false;
  } else {
    // Imprime los valores leídos si el nivel de depuración es alto
    DEBUG_INFO("Temp: %f", sen5x_temp);
    DEBUG_INFO("Hum: %f", sen5x_hum);
    DEBUG_INFO("PM1.0: %f", sen5x_mc_1p0);
    DEBUG_INFO("PM2.5: %f", sen5x_mc_2p5);
    DEBUG_INFO("PM4.0: %f", sen5x_mc_4p0);
    DEBUG_INFO("PM10.0: %f", sen5x_mc_10p0);
    DEBUG_INFO("VOC: %f", sen5x_voc);
    DEBUG_INFO("NOx: %f", sen5x_nox);
    return true;
  }
}
