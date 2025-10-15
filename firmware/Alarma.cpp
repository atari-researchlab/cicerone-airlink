/**
 * @file        Alarma.cpp
 * @brief       Implementation of functions for alarm management and data averaging.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2025-07-22]
 * @version     2.0
 *
 * @copyright   GNU General Public License version 3 or later
 */

#include "Alarma.h"
#include "Configuracion.h"
#include "Debug.h"
#include "Datetime_helper.h"
#include "SEN5X_API.h"
#include "T6793_API.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_ALARMA  //!< Redefinition of debug level for this source file.
#define DEBUG_TAG "ALARMA"        //!< Tag when sending debug messages.

/**
 * @defgroup  gVarGlobales  Global variables
 * @details   Definition and memory allocation of global variables used by other modules.
 * @{
 */
/**
 * @name  Alarm control flags
 * @{
 */
bool alarma_10min = false;  //!< Set to 'true' when the 10-minute cycle is completed.
bool alarma_5s = false;     //!< Set to 'true' when the 5-second cycle is completed.
//!@}

/**
 * @name  Variables for 5s timer based on millis()
 * @{
 */
unsigned long prev_millis;  //!< Stores the time of the last 5s alarm activation.
//!@}

/**
 * @name  Variables for 10min alarm based on RTC
 * @{
 */
uint8_t minuto_actual;     //!< Stores the current minute read from RTC.
uint8_t minuto_siguiente;  //!< Calculates and stores the next minute when the alarm will trigger (e.g., 10, 20, 30...).
//!@}

/**
 * @name  Counters for data averaging
 * @{
 */
uint16_t cont1 = 0;  //!< Counter for averaging the first sensor groups.
uint16_t cont2 = 0;  //!< Counter for averaging the second sensor groups.
//!@}

/**
 * @name  Accumulators for averaging sensor readings
 * @{
 */
float sum_sen5x_voc = 0.0f;      //!< Accumulator for SEN5X VOC index.
float sum_sen5x_mc_1p0 = 0.0f;   //!< Accumulator for SEN5X PM1.0.
float sum_sen5x_mc_2p5 = 0.0f;   //!< Accumulator for SEN5X PM2.5.
float sum_sen5x_mc_4p0 = 0.0f;   //!< Accumulator for SEN5X PM4.0.
float sum_sen5x_mc_10p0 = 0.0f;  //!< Accumulator for SEN5X PM10.0.
float sum_temp = 0.0f;           //!< Accumulator for ambient temperature.
float sum_hum = 0.0f;            //!< Accumulator for ambient humidity.
float sum_sen5x_nox = 0.0f;      //!< Accumulator for SEN55 NOx index.
float sum_t6793_co2 = 0.0f;      //!< Accumulator for T6793 CO2.
//!@}

/**
 * @name  Variables to store averages
 * @{
 */
float avg_sen5x_voc = 0.0f;      //!< Average of SEN5X VOC index.
float avg_sen5x_mc_1p0 = 0.0f;   //!< Average of SEN5X PM1.0.
float avg_sen5x_mc_2p5 = 0.0f;   //!< Average of SEN5X PM2.5.
float avg_sen5x_mc_4p0 = 0.0f;   //!< Average of SEN5X PM4.0.
float avg_sen5x_mc_10p0 = 0.0f;  //!< Average of SEN5X PM10.0.
float avg_temp = 0.0f;           //!< Average of ambient temperature.
float avg_hum = 0.0f;            //!< Average of ambient humidity.
float avg_sen5x_nox = 0.0f;      //!< Average of SEN55 NOx index.
float avg_t6793_co2 = 0.0f;      //!< Average of T6793 CO2.
//!@}

/**
 * @name  Date and time variables and RTC object instance
 * @{
 */
DS3231M rtc;   //!< RTC object instance
DateTime now;  //!< Structure to store current date and time
String fecha;  //!< String to store current date (e.g., "YYYY-MM-DD").
String hora;   //!< String to store current time (e.g., "HH:MM:SS").
//!@}
//!@}

/**
 * @brief Prints the current time to the serial port (for debugging).
 * @note  Private function (no prototype).
 */
static inline void imprimir_hora(void) {
  DEBUG_VERBOSE("%04d-%02d-%02d\t%02d:%02d:%02d", now.year(), now.month(), now.day(),
                now.hour(), now.minute(), now.second());
}

void rtc_alarma_inicializar(void) {
  while (!rtc.begin()) {
    DEBUG_ERROR("RTC: initialization error. Check that the connection is correct...");
    delay(1000);
  }

  // Adjust date and time if auxiliary power was lost
  if (rtc.lostPower()) {
    DEBUG_WARN("RTC: auxiliary power lost. Setting date/time to compile time");

    // Set time using macros from Datetime_helper.h
    rtc.setRTCTime(BUILD_YEAR, BUILD_MONTH, BUILD_DAY, BUILD_HOUR, BUILD_MIN, BUILD_SEC);
  }

  DEBUG_INFO("RTC and Alarms initialized.");

  now = rtc.getRTCTime();
  // Configure the first 10-minute alarm
  minuto_actual = now.minute();
  minuto_siguiente = (minuto_actual / 10 + 1) * 10;
  if (minuto_siguiente >= 60) {
    minuto_siguiente = 0;
  }
#if TEST_MINUTAL
  minuto_siguiente = now.minute() + 1;  // Per-minute average
  if (minuto_siguiente > 59) {
    minuto_siguiente = 0;
  }
#else
  minuto_siguiente = ((now.minute() / 10) + 1) * 10;
  if (minuto_siguiente > 50) {
    minuto_siguiente = 0;
  }
#endif
  DEBUG_INFO("Next 10min alarm scheduled for minute: %u", minuto_siguiente);
}

void check_alarma_5s(void) {
  unsigned long current_millis = millis();
  if (current_millis - prev_millis >= 5000) {  // 5000 ms = 5s
    prev_millis = current_millis;
    alarma_5s = true;
  }
}

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
    DEBUG_VERBOSE("Accumulated SEN5X samples: %u", cont1);

  } else {
    DEBUG_WARN("Error reading SEN5X.");
  }

  if (t6793_leer()) {
    sum_t6793_co2 += t6793_co2;
    cont2 += 1;
    DEBUG_VERBOSE("Accumulated T6793 samples: %u", cont2);

  } else {
    DEBUG_WARN("Error reading T6793.");
  }
}

void check_alarma_10min(void) {
  now = rtc.getRTCTime();
  // Configure the first 10-minute alarm
  minuto_actual = now.minute();
  if (minuto_actual == minuto_siguiente) {
    alarma_10min = true;
    minuto_siguiente = (minuto_actual / 10 + 1) * 10;
    if (minuto_siguiente >= 60) {
      minuto_siguiente = 0;
    }
#if TEST_MINUTAL
    minuto_siguiente = now.minute() + 1;  // Per-minute average
    if (minuto_siguiente > 59) {
      minuto_siguiente = 0;
    }
#else
    minuto_siguiente = ((now.minute() / 10) + 1) * 10;
    if (minuto_siguiente > 50) {
      minuto_siguiente = 0;
    }
#endif

    // Update date and time strings
    char buffer[25];
    snprintf(buffer, 25, "%04d-%02d-%02d", now.year(), now.month(), now.day());
    fecha = String(buffer);
    snprintf(buffer, 25, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
    hora = String(buffer);
    DEBUG_INFO("Next 10min alarm scheduled for minute: %u", minuto_siguiente);
  }
}

void promediar_datos(void) {
  if (cont1 > 0) {  // Avoid division by zero
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
  DEBUG_INFO("%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f", avg_temp, avg_hum, avg_sen5x_mc_1p0,
             avg_sen5x_mc_2p5, avg_sen5x_mc_4p0, avg_sen5x_mc_10p0, avg_sen5x_voc, avg_t6793_co2);
  reset_acumuladores();
}

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
  DEBUG_INFO("Accumulators reset");
}
