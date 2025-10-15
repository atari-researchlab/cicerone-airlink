/**
 * @file    Alarma.h
 * @brief   Header for timed alarm and data averaging management.
 * @details Declares functions and global variables to control periodic tasks
 * (e.g., every 5s, every 10min) and to handle sensor data.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 */

#ifndef ALARMA_H
#define ALARMA_H
 
#include <Arduino.h>
#include "DS3231M.h"

/* Declaration of global variables with the **extern** attribute. This indicates that these
 * variables exist, but are defined (memory is allocated) in another file like Alarma.cpp.
 * This allows them to be accessible from any other module that includes Alarma.h.
 */
extern bool alarma_10min;
extern bool alarma_5s;
extern unsigned long prev_millis;
extern uint8_t minuto_actual;
extern uint8_t minuto_siguiente;
extern float sum_sen5x_voc;
extern float sum_sen5x_mc_1p0;
extern float sum_sen5x_mc_2p5;
extern float sum_sen5x_mc_4p0;
extern float sum_sen5x_mc_10p0;
extern float sum_temp;
extern float sum_hum;
extern float sum_sen5x_nox;
extern float sum_t6793_co2;
extern float avg_sen5x_voc;
extern float avg_sen5x_mc_1p0;
extern float avg_sen5x_mc_2p5;
extern float avg_sen5x_mc_4p0;
extern float avg_sen5x_mc_10p0;
extern float avg_temp;
extern float avg_hum;
extern float avg_sen5x_nox;
extern float avg_t6793_co2;

extern DS3231M rtc;
extern DateTime now;
extern String fecha;
extern String hora;

/**
 * @brief   Initializes the RTC module and configures the first 10-minute alarm.
 * @details Configures the RTC with initial date and time if necessary, or synchronizes it.
 * This function must be called in 'setup()'.
 */
void rtc_alarma_inicializar(void);

/**
 * @brief Checks if 5 seconds have passed using millis(). If so, activates the alarma_5s flag.
 * @note  Must be called continuously in the main loop.
 */
void check_alarma_5s(void);

/**
 * @brief   Reads data from all sensors and accumulates them for averaging.
 * @details Calls the reading functions of the SEN55 and T6793 modules and adds their values
 * to the corresponding \a sum_* accumulators. Increments the averaging counters.
 */
void acumular_datos(void);

/**
 * @brief   Verifies if the 10-minute cycle has completed. If so, activates the alarma_10min flag.
 * @details Checks the RTC time to see if the next 10-minute interval has been reached
 * (e.g., 12:10, 12:20).
 * @note    Must be called continuously in the main loop.
 */
void check_alarma_10min(void);

/**
 * @brief   Processes accumulated data to calculate averages and stores them.
 * @details This function is called at the end of each averaging period (e.g., every 10 minutes)
 * and the averages are stored in the corresponding \a avg_* variables.
 */
void promediar_datos(void);

/**
 * @brief Resets counters and accumulators.
 */
void reset_acumuladores(void);

#endif  // ALARMA_H