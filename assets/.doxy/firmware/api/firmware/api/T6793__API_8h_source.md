

# File T6793\_API.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T6793\_API.h**](T6793__API_8h.md)

[Go to the documentation of this file](T6793__API_8h.md)


```C++


#ifndef T6793_API_H
#define T6793_API_H

#include <Arduino.h>

extern uint16_t t6793_co2;

void t6793_inicializar(void);

bool t6793_leer(void);

#endif  // T6793_API_H
```


