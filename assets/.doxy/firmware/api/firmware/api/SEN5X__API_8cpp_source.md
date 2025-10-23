

# File SEN5X\_API.cpp

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**SEN5X\_API.cpp**](SEN5X__API_8cpp.md)

[Go to the documentation of this file](SEN5X__API_8cpp.md)


```C++


#include <SensirionI2CSen5x.h>
#include "SEN5X_API.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_SEN5X  
#define DEBUG_TAG "SEN5X_API"    

float sen5x_mc_1p0 = 0.0f;   
float sen5x_mc_2p5 = 0.0f;   
float sen5x_mc_4p0 = 0.0f;   
float sen5x_mc_10p0 = 0.0f;  
float sen5x_hum = 0.0f;      
float sen5x_temp = 0.0f;     
float sen5x_voc = 0.0f;      
float sen5x_nox = 0.0f;      

SensirionI2CSen5x sen5x;  

void sen5x_inicializar(void) {
  Wire.begin();
  sen5x.begin(Wire);  // Start I2C communication.

  uint16_t error;

  // Reset the sensor to ensure a known state.
  error = sen5x.deviceReset();
  if (error) {
    DEBUG_ERROR("Error resetting device.");
  }

  // Start measurements. The sensor will measure continuously in the background.
  error = sen5x.startMeasurement();
  if (error) {
    DEBUG_ERROR("Error starting measurements.");
  }

  DEBUG_INFO("Sensor initialized.");
}

bool sen5x_leer(void) {
  uint16_t error;

  // Read measured values from the sensor
  error = sen5x.readMeasuredValues(
    sen5x_mc_1p0, sen5x_mc_2p5, sen5x_mc_4p0, sen5x_mc_10p0,
    sen5x_hum, sen5x_temp, sen5x_voc, sen5x_nox);

  if (error) {
    DEBUG_ERROR("Error reading data.");
    return false;
  } else {
    // Print the read values if debug level is high
    DEBUG_INFO("Temp: %f", sen5x_temp);
    DEBUG_INFO("Hum: %f", sen5x_hum);
    DEBUG_INFO("PM1.0: %f", sen5x_mc_1p0);
    DEBUG_INFO("PM2.5: %f", sen5x_mc_2p5);
    DEBUG_INFO("PM4.0: %f", sen5x_mc_4p0);
    DEBUG_INFO("PM10.0: %f", sen5x_mc_10p0);
    DEBUG_INFO("VOC: %f", sen5x_voc);
    DEBUG_INFO("NOx: %f", sen5x_nox);
    return true;
  }
}
```


