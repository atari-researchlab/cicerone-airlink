

# File Debug.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Debug.h**](Debug_8h.md)

[Go to the documentation of this file](Debug_8h.md)


```C++


#ifndef DEBUG_H
#define DEBUG_H

#define TEST_MINUTAL 1

#define DEBUG_LEVEL 3    
#define DEBUG_ALARMA 2   
#define DEBUG_SEN5X 2    
#define DEBUG_T6793 2    
#define DEBUG_DS3231M 2  
#define DEBUG_NBIOT 2    

#include <Arduino.h>
#include <stdarg.h>  // Required for va_list, va_start, va_end
#include <stdio.h>   // Required for snprintf

#define DEBUG_PRINTF_BUFFER_SIZE 256                        
static char debug_printf_buffer[DEBUG_PRINTF_BUFFER_SIZE];  

#if DEBUG_LEVEL == 0
#define DEBUG_ERROR(format, ...)
#define DEBUG_WARN(format, ...)
#define DEBUG_INFO(format, ...)
#define DEBUG_VERBOSE(format, ...)

#else  // If debug level is > 0, macros are defined to print to Serial.

#define DEBUG_PRINT_PREFIX(level) \
  Serial.print(F("[")); \
  Serial.print(level); \
  Serial.print(F("][")); \
  Serial.print(millis()); \
  Serial.print(F("][")); \
  Serial.print(DEBUG_TAG); \
  Serial.print(F("] "))


#define DEBUG_ERROR(format, ...) \
  if (DEBUG_LEVEL >= 1) { \
    DEBUG_PRINT_PREFIX("ERROR"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

#define DEBUG_WARN(format, ...) \
  if (DEBUG_LEVEL >= 2) { \
    DEBUG_PRINT_PREFIX("WARN"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

#define DEBUG_INFO(format, ...) \
  if (DEBUG_LEVEL >= 3) { \
    DEBUG_PRINT_PREFIX("INFO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

#define DEBUG_VERBOSE(format, ...) \
  if (DEBUG_LEVEL >= 4) { \
    DEBUG_PRINT_PREFIX("VERBO"); \
    do { \
      snprintf(debug_printf_buffer, DEBUG_PRINTF_BUFFER_SIZE, format, ##__VA_ARGS__); \
      Serial.println(debug_printf_buffer); \
    } while (0); \
  }

#endif  // DEBUG_LEVEL == 0

#endif  // DEBUG_H
```


