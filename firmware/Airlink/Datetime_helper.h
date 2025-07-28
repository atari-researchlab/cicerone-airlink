/***********************************************************************************************************************
 * @file        Datetime_helper.h
 * @brief       Macros de preprocesador para convertir las macros __DATE__ y __TIME__
 * en valores numéricos para el RTC.
 *
 * @author      [Adaptado de varias fuentes en línea, por ejemplo, de la comunidad de Adafruit/Arduino]
 * @date        [2024-07-22]
 * @version     1.0
 *
 * @license     Este código fuente está licenciado bajo CC-BY-SA 4.0.
 * http://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Este archivo es una utilidad que permite establecer la hora del reloj RTC
 * automáticamente a la hora en que se compiló el programa. No es necesario modificarlo.
 * Ejemplo de __DATE__: "Jul 22 2024"
 * Ejemplo de __TIME__: "18:30:00"
 **********************************************************************************************************************/

#ifndef DATETIME_HELPER_H
#define DATETIME_HELPER_H

// Extrae el año de la cadena __DATE__ (ej. "Jul 22 2024" -> 2024)
#define BUILD_YEAR \
    ( \
        (__DATE__[ 7] - '0') * 1000 + \
        (__DATE__[ 8] - '0') * 100 + \
        (__DATE__[ 9] - '0') * 10 + \
        (__DATE__[10] - '0') \
    )

// Extrae el día de la cadena __DATE__ (ej. "Jul 22 2024" -> 22)
// Maneja el caso en que el día tiene un solo dígito (ej. "Jul  7 2024")
#define BUILD_DAY \
    ( \
        ((__DATE__[4] >= '0') ? (__DATE__[4] - '0') * 10 : 0) + \
        (__DATE__[5] - '0') \
    )

// Convierte el mes de texto a número (ej. "Jan" -> 1, "Feb" -> 2, etc.)
#define BUILD_MONTH \
    ( \
        (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n') ? 1 : \
        (__DATE__[0] == 'F') ? 2 : \
        (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r') ? 3 : \
        (__DATE__[0] == 'A' && __DATE__[1] == 'p') ? 4 : \
        (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y') ? 5 : \
        (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n') ? 6 : \
        (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l') ? 7 : \
        (__DATE__[0] == 'A' && __DATE__[1] == 'u') ? 8 : \
        (__DATE__[0] == 'S') ? 9 : \
        (__DATE__[0] == 'O') ? 10 : \
        (__DATE__[0] == 'N') ? 11 : \
        (__DATE__[0] == 'D') ? 12 : \
        0 \
    )

// Extrae la hora de la cadena __TIME__ (ej. "18:30:00" -> 18)
#define BUILD_HOUR ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))
// Extrae el minuto de la cadena __TIME__ (ej. "18:30:00" -> 30)
#define BUILD_MIN ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))
// Extrae el segundo de la cadena __TIME__ (ej. "18:30:00" -> 00)
#define BUILD_SEC ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))


#endif // DATETIME_HELPER_H
