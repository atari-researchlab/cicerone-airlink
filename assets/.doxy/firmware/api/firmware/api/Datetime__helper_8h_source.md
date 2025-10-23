

# File Datetime\_helper.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Datetime\_helper.h**](Datetime__helper_8h.md)

[Go to the documentation of this file](Datetime__helper_8h.md)


```C++


#ifndef DATETIME_HELPER_H
#define DATETIME_HELPER_H

#define BUILD_YEAR \
  ( \
    (__DATE__[7] - '0') * 1000 + \
    (__DATE__[8] - '0') * 100 +  \
    (__DATE__[9] - '0') * 10 +   \
    (__DATE__[10] - '0')         \
   )

#define BUILD_DAY \
  ( \
    ((__DATE__[4] >= '0') ? (__DATE__[4] - '0') * 10 : 0) + (__DATE__[5] - '0'))

#define BUILD_MONTH \
  ( \
    (__DATE__[0] == 'J' && __DATE__[1] == 'a' && __DATE__[2] == 'n') ? 1  : \
    (__DATE__[0] == 'F')                                             ? 2  : \
    (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'r') ? 3  : \
    (__DATE__[0] == 'A' && __DATE__[1] == 'p')                       ? 4  : \
    (__DATE__[0] == 'M' && __DATE__[1] == 'a' && __DATE__[2] == 'y') ? 5  : \
    (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'n') ? 6  : \
    (__DATE__[0] == 'J' && __DATE__[1] == 'u' && __DATE__[2] == 'l') ? 7  : \
    (__DATE__[0] == 'A' && __DATE__[1] == 'u')                       ? 8  : \
    (__DATE__[0] == 'S')                                             ? 9  : \
    (__DATE__[0] == 'O')                                             ? 10 : \
    (__DATE__[0] == 'N')                                             ? 11 : \
    (__DATE__[0] == 'D')                                             ? 12 : \
                                                                       0    \
  )

#define BUILD_HOUR ((__TIME__[0] - '0') * 10 + (__TIME__[1] - '0'))

#define BUILD_MIN ((__TIME__[3] - '0') * 10 + (__TIME__[4] - '0'))

#define BUILD_SEC ((__TIME__[6] - '0') * 10 + (__TIME__[7] - '0'))

#endif  // DATETIME_HELPER_H
```


