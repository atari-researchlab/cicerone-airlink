

# File Alarma.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Alarma.h**](Alarma_8h.md)

[Go to the documentation of this file](Alarma_8h.md)


```C++


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

void rtc_alarma_inicializar(void);

void check_alarma_5s(void);

void acumular_datos(void);

void check_alarma_10min(void);

void promediar_datos(void);

void reset_acumuladores(void);

#endif  // ALARMA_H
```


