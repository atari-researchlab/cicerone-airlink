/***********************************************************************************************************************
 * @file        Alarma.cpp
 * @brief       Implementación de las funciones para la gestión de alarmas y promedio de datos.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 **********************************************************************************************************************/

#include "Alarma.h"
#include "Configuracion.h"
#include "Debug.h"
#include "Datetime_helper.h"
#include "SEN5X_API.h"
#include "T6793_API.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_ALARMA  //!< Redefinición del nivel de depuración en la compilación de este archivo fuente
#define DEBUG_TAG "ALARMA"        //!< Etiqueta al enviar mensajes de depuración

/**
 * @{
 * @name      Variables globales
 * @details   Aquí se asigna la memoria para las variables globales declaradas como 'extern' en Alarma.h.
 */
/**
 * @{
 * @name    Banderas de control de alarmas
 */
bool alarma_10min = false;  //!< Se pone a 'true' cuando se cumple el ciclo de 10 minutos.
bool alarma_5s = false;     //!< Se pone a 'true' cuando se cumple el ciclo de 5 segundos.
/**@}*/

/**
 * @{
 * @name    Variables para el temporizador de 5s basado en millis()
 */
unsigned long prev_millis;  //!< Almacena el tiempo de la última activación de la alarma de 5s.
/**@}*/

/**
 * @{
 * @name  Variables para la alarma de 10min basada en RTC
 */
uint8_t minuto_actual;     //!< Guarda el minuto actual leído del RTC.
uint8_t minuto_siguiente;  //!< Calcula y guarda el próximo minuto en el que sonará la alarma (ej. 10, 20, 30...).
/**@}*/

/**
 * @{
 * @name    Contadores para el promedio de datos
 */
uint16_t cont1 = 0;  //!< Contador para el promedio de los primeros grupos de sensores.
uint16_t cont2 = 0;  //!< Contador para el promedio de los segundos grupos de sensores.
/**@}*/

/**
 * @{
 * @name    Acumuladores para promediar las lecturas de los sensores
 */
float sum_sen5x_voc = 0.0f;      //!< Acumulador para el índice VOC del SEN5X.
float sum_sen5x_mc_1p0 = 0.0f;   //!< Acumulador para PM1.0 del SEN5X.
float sum_sen5x_mc_2p5 = 0.0f;   //!< Acumulador para PM2.5 del SEN5X.
float sum_sen5x_mc_4p0 = 0.0f;   //!< Acumulador para PM4.0 del SEN5X.
float sum_sen5x_mc_10p0 = 0.0f;  //!< Acumulador para PM10.0 del SEN5X.
float sum_temp = 0.0f;           //!< Acumulador para la temperatura ambiente.
float sum_hum = 0.0f;            //!< Acumulador para la humedad ambiente.
float sum_sen5x_nox = 0.0f;      //!< Acumulador para el indice NOx del SEN55.
float sum_t6793_co2 = 0.0f;      //!< Acumulador para CO2 del T6793.
/**@}*/

/**
 * @{
 * @name    Variables para almacenar los promedios
 */
float avg_sen5x_voc = 0.0f;      //!< Promedio del índice VOC del SEN5X.
float avg_sen5x_mc_1p0 = 0.0f;   //!< Promedio de PM1.0 del SEN5X.
float avg_sen5x_mc_2p5 = 0.0f;   //!< Promedio de PM2.5 del SEN5X.
float avg_sen5x_mc_4p0 = 0.0f;   //!< Promedio de PM4.0 del SEN5X.
float avg_sen5x_mc_10p0 = 0.0f;  //!< Promedio de PM10.0 del SEN5X.
float avg_temp = 0.0f;           //!< Promedio de la temperatura ambiente.
float avg_hum = 0.0f;            //!< Promedio de la humedad ambiente.
float avg_sen5x_nox = 0.0f;      //!< Promedio del indice NOx del SEN55.
float avg_t6793_co2 = 0.0f;      //!< Promedio de CO2 del T6793.
/**@}*/

/**
 * @{
 * @name    Variables de fecha y hora e instancia del objeto RTC
 */
DS3231M rtc;   //!< Instancia del objeto RTC
DateTime now;  //!< Estructura para almacenar la fecha y hora actuales
String fecha;  //!< Cadena para almacenar la fecha actual (ej. "YYYY-MM-DD").
String hora;   //!< Cadena para almacenar la hora actual (ej. "HH:MM:SS").
/**@}*/
/**@}*/

/**
 * @brief   Imprime la hora actual en el puerto serie (para depuración).
 * @note    Función privada (sin prototipo).
 */
void inline imprimir_hora(void) {
  DEBUG_VERBOSE("%04d-%02d-%02d\t%02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());
}

/**
 * @brief     Inicializa el módulo RTC y configura la primera alarma de 10 minutos.
 * @details   Configura el RTC con una fecha y hora iniciales si es necesario, o lo sincroniza.
 * Esta función debe ser llamada en 'setup()'.
 */
void rtc_alarma_inicializar(void) {
  while (!rtc.begin()) {
    DEBUG_ERROR("RTC: error al inicializar. Compruebe que la conexión es correcta...");
    delay(1000);
  }

  // Ajusta la fecha y hora si se perdió la alimentación auxiliar
  if (rtc.lostPower()) {
    DEBUG_WARN("RTC: alimentación auxiliar perdida. Estableciendo fecha/hora a la fecha/hora de compilación");
    // Ajusta la hora usando las macros de Datetime_helper.h
    rtc.setRTCTime(BUILD_YEAR, BUILD_MONTH, BUILD_DAY, BUILD_HOUR, BUILD_MIN, BUILD_SEC);
  }

  DEBUG_INFO("RTC y Alarmas inicializadas.");

  now = rtc.getRTCTime();
  // Configura la primera alarma de 10 minutos
  minuto_actual = now.minute();
  minuto_siguiente = (minuto_actual / 10 + 1) * 10;
  if (minuto_siguiente >= 60) {
    minuto_siguiente = 0;
  }
#if TEST_MINUTAL
  minuto_siguiente = now.minute() + 1;  //Promedio minutal
  if (minuto_siguiente > 59) {
    minuto_siguiente = 0;
  }
#else
  minuto_siguiente = ((now.minute() / 10) + 1) * 10;
  if (minuto_siguiente > 50) {
    minuto_siguiente = 0;
  }
#endif
  DEBUG_INFO("Proxima alarma de 10min programada para el minuto: %lu", minuto_siguiente);
}

/**
 * @brief   Comprueba si han pasado 5 segundos utilizando millis(). Si es así, activa la bandera alarma_5s.
 * @note    Debe llamarse continuamente en el loop principal.
 */
void check_alarma_5s(void) {
  unsigned long current_millis = millis();
  if (current_millis - prev_millis >= 5000) {  // 5000 ms = 5s
    prev_millis = current_millis;
    alarma_5s = true;
  }
}

/**
 * @brief     Lee los datos de todos los sensores y los acumula para el promedio.
 * @details   Llama a las funciones de lectura de los módulos SEN55 y T6793 y suma sus valores
 * a los acumuladores \a sum_* correspondientes. Incrementa los contadores de promedio.
 */
void acumular_datos(void) {
  if (sen5x_leer()) {
    sum_sen5x_voc += sen5x_voc;
    sum_sen5x_mc_1p0 += sen5x_mc_1p0;
    sum_sen5x_mc_2p5 += sen5x_mc_2p5;
    sum_sen5x_mc_4p0 += sen5x_mc_4p0;
    sum_sen5x_mc_10p0 += sen5x_mc_10p0;
    sum_temp += sen5x_temp;
    sum_hum += sen5x_hum;
    //sum_sen5x_nox += sen5x_nox;
    cont1 += 1;
    DEBUG_VERBOSE("Muestras acumuladas SEN5X: %u", cont1);
  } else {
    DEBUG_WARN("Error al leer el SEN5X.");
  }

  if (t6793_leer()) {
    sum_t6793_co2 += t6793_co2;
    cont2 += 1;
    DEBUG_VERBOSE("Muestras acumuladas T6793: %u", cont2);
  } else {
    DEBUG_WARN("Error al leer el T6793.");
  }
}

/**
 * @brief     Verifica si se ha completado el ciclo de 10 minutos. Si es así, activa la bandera alarma_10min.
 * @details   Comprueba la hora del RTC para ver si se ha alcanzado el siguiente intervalo de 10
 * minutos (ej: 12:10, 12:20).
 * @note      Debe llamarse continuamente en el loop principal.
 */
void check_alarma_10min(void) {
  now = rtc.getRTCTime();
  // Configura la primera alarma de 10 minutos
  minuto_actual = now.minute();
  if (minuto_actual == minuto_siguiente) {
    alarma_10min = true;
    minuto_siguiente = (minuto_actual / 10 + 1) * 10;
    if (minuto_siguiente >= 60) {
      minuto_siguiente = 0;
    }
#if TEST_MINUTAL
    minuto_siguiente = now.minute() + 1;  //Promedio minutal
    if (minuto_siguiente > 59) {
      minuto_siguiente = 0;
    }
#else
    minuto_siguiente = ((now.minute() / 10) + 1) * 10;
    if (minuto_siguiente > 50) {
      minuto_siguiente = 0;
    }
#endif
    //Actualizar cadenas de fecha y hora
    char buffer[25];
    snprintf(buffer, 25, "%04d-%02d-%02d", now.year(), now.month(), now.day());
    fecha = String(buffer);
    snprintf(buffer, 25, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    hora = String(buffer);
    DEBUG_INFO("Proxima alarma de 10min programada para el minuto: %lu", minuto_siguiente);
  }
}

/**
 * @brief     Procesa los datos acumulados para calcular los promedios y los almacena.
 * @details   Esta función se llama al final de cada período de promedio (ej. cada 10 minutos)
 * y los promedios se guardan en las variables \a avg_* correspondientes.
 */
void promediar_datos(void) {
  if (cont1 > 0) {  // Evitar división por cero
    avg_sen5x_voc = sum_sen5x_voc / cont1;
    avg_sen5x_mc_1p0 = sum_sen5x_mc_1p0 / cont1;
    avg_sen5x_mc_2p5 = sum_sen5x_mc_2p5 / cont1;
    avg_sen5x_mc_4p0 = sum_sen5x_mc_4p0 / cont1;
    avg_sen5x_mc_10p0 = sum_sen5x_mc_10p0 / cont1;
    avg_temp = sum_temp / cont1;
    avg_hum = sum_hum / cont1;
    avg_sen5x_nox = sum_sen5x_nox / cont1;
  }

  if (cont2 > 0) {
    avg_t6793_co2 = sum_t6793_co2 / cont2;
  }

  imprimir_hora();
  DEBUG_VERBOSE("Avg. Temp: %f", avg_temp);
  DEBUG_VERBOSE("Avg. RH: %f", avg_hum);
  DEBUG_VERBOSE("Avg. PM1: %f", avg_sen5x_mc_1p0);
  DEBUG_VERBOSE("Avg. PM2: %f", avg_sen5x_mc_2p5);
  DEBUG_VERBOSE("Avg. PM4: %f", avg_sen5x_mc_4p0);
  DEBUG_VERBOSE("Avg. PM10: %f", avg_sen5x_mc_10p0);
  DEBUG_VERBOSE("Avg. VOC: %f", avg_sen5x_voc);
  DEBUG_VERBOSE("Avg. NOx: %f", avg_sen5x_nox);
  DEBUG_VERBOSE("Avg. CO2: %f", avg_t6793_co2);
  DEBUG_INFO("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f",
             avg_temp, avg_hum,
             avg_sen5x_mc_1p0, avg_sen5x_mc_2p5,
             avg_sen5x_mc_4p0, avg_sen5x_mc_10p0,
             avg_sen5x_voc, avg_t6793_co2);

  reset_acumuladores();
}

/**
 * @brief   Reinicia los contadores y acumuladores.
 */
void reset_acumuladores(void) {
  sum_sen5x_voc = 0;
  sum_sen5x_mc_1p0 = 0;
  sum_sen5x_mc_2p5 = 0;
  sum_sen5x_mc_4p0 = 0;
  sum_sen5x_mc_10p0 = 0;
  sum_temp = 0;
  sum_hum = 0;
  sum_sen5x_nox = 0;
  sum_t6793_co2 = 0;
  cont1 = 0;
  cont2 = 0;
  DEBUG_INFO("Acumuladores reiniciados");
}
