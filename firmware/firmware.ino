/***********************************************************************************************************************
 * @file        firmware.ino
 * @brief       Código principal para un sistema de monitoreo de calidad del aire ("Airlink").
 * @details     Este programa integra lecturas de diversos sensores y gestiona su funcionamiento
 * a través de temporizadores no bloqueantes (millis). Incluye módulos opcionales
 * para transmisión de datos por NB-IoT y para detección de tos mediante Edge Impulse.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22 / Última Modificación]
 * @version     1.0-rc1
 *
 * @copyright   GNU General Public License version 3 or later
 * @warning     Se debe configurar correctamente los valores del servidor y APN para poder utilizar el módulo de IoT.
 * @see         Configuracion.h
 **********************************************************************************************************************/

#include "Configuracion.h"  // Archivo de configuración central para habilitar/deshabilitar módulos.
#include "Debug.h"          // Contiene las macros para controlar la salida de depuración por Serial.
#include "Alarma.h"         // Módulo propio para la gestión de temporizadores (alarmas periódicas).
#include "SEN5X_API.h"      // API para el manejo del sensor Sensirion SEN5X.
#include "T6793_API.h"      // API para el manejo del sensor de CO2 T6793-5K.

// --- Inclusión condicional de módulos (controlado desde Configuracion.h) ---
#if HABILITAR_NBIOT
#include "Transmision_NBIOT.h"  // Módulo para la transmisión de datos vía Narrowband IoT.
#endif

#define DEBUG_TAG "MAIN"  //!< Etiqueta al enviar mensajes de depuración

/**
 * @brief Inicializa las comunicaciones, los sensores y los módulos del sistema.
 * Se ejecuta una sola vez al encender o reiniciar el microcontrolador.
 */
void setup() {
  // Inicialización del puerto serie si la depuración está habilitada en Configuracion.h
#if (DEBUG_LEVEL >= 1)
  Serial.begin(115200);
  // En algunas placas (como ESP32), es útil esperar a que el puerto serie se conecte.
  while (!Serial) {
    ;  // Bucle de espera
  }
#endif

  DEBUG_INFO("**********************************************");
  DEBUG_INFO("*       Sistema de Monitoreo AIRLINK         *");
  DEBUG_INFO("**********************************************");
  DEBUG_INFO("Inicializando sistema...");

  // Inicializa el RTC (Reloj de Tiempo Real) y las alarmas periódicas
  rtc_alarma_inicializar();
  DEBUG_INFO("RTC y Alarmas inicializadas.");

  // Inicializa el sensor T6793
  t6793_inicializar();
  DEBUG_INFO("Sensor T6793 inicializado.");

  // Inicializa el sensor SEN5X
  sen5x_inicializar();
  DEBUG_INFO("Sensor SEN5X inicializado.");

  // Inicialización condicional de los módulos
#if HABILITAR_NBIOT
  nbiot_inicializar();
  DEBUG_INFO("Módulo NB-IoT inicializado.");
#endif

  DEBUG_INFO("Inicializacion completada. Iniciando bucle principal.");
}

/**
 * @brief Se ejecuta repetidamente después de que setup() ha terminado.
 * Es el corazón del programa, donde se comprueban y ejecutan las tareas periódicas.
 */
void loop() {
  // Comprueba si se ha activado la alarma de 5 segundos para leer los sensores.
  // Esta función es no bloqueante y se basa en millis().
  check_alarma_5s();

  // Comprueba si se ha activado la alarma de 10 minutos para promediar y enviar datos.
  // Esta función se basa en el reloj RTC.
  check_alarma_10min();

  // Si la bandera de 5 segundos está activa, ejecuta las lecturas.
  if (alarma_5s) {
    DEBUG_VERBOSE("Alarma 5s activada. Leyendo sensores...");

    // Acumula los datos leídos para su posterior promedio
    acumular_datos();

    // Reinicia la bandera para la siguiente iteración
    alarma_5s = false;
  }

  // Si la bandera de 10 minutos está activa, ejecuta el promedio y la transmisión.
  if (alarma_10min) {
    DEBUG_INFO("Alarma 10min activada. Procesando y enviando datos...");

    // Calcula el promedio de las lecturas acumuladas
    promediar_datos();

// Transmite los datos promediados si el módulo está habilitado
#if HABILITAR_NBIOT
    nbiot_enviar();
#endif

    // Reinicia la bandera para la siguiente iteración
    alarma_10min = false;
  }
}
