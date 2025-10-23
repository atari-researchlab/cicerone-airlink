

# File SEN5X\_API.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**SEN5X\_API.h**](SEN5X__API_8h.md)

[Go to the documentation of this file](SEN5X__API_8h.md)


```C++


#ifndef SEN5X_API_H
#define SEN5X_API_H
#include <Arduino.h>
 
extern float sen5x_mc_1p0;
extern float sen5x_mc_2p5;
extern float sen5x_mc_4p0;
extern float sen5x_mc_10p0;
extern float sen5x_hum;
extern float sen5x_temp;
extern float sen5x_voc;
extern float sen5x_nox;

void sen5x_inicializar(void);

bool sen5x_leer(void);

#endif  // SEN5X_API_H
```


