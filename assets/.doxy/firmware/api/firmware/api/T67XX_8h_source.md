

# File T67XX.h

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T67XX.h**](T67XX_8h.md)

[Go to the documentation of this file](T67XX_8h.md)


```C++


#ifndef T67XX_H
#define T67XX_H
#include <Arduino.h>
#include <Wire.h>

#define T67XX_DEFAULT_I2C_ADDR 0x15

#define T67XX_REG_VAL_ENABLE 0xFF00

#define T67XX_REG_VAL_DISABLE 0x0000

#define T67XX_READ_DELAY 10

#define T67XX_MEASURE_DELAY 2250

enum Modbus_FC {
  MODBUS_READ_COIL = 0x01,                        
  MODBUS_READ_DISCRETE_INPUT = 0x02,              
  MODBUS_READ_MULTIPLE_HOLDING_REGISTERS = 0x03,  
  MODBUS_READ_INPUT_REGISTERS = 0x04,             
  MODBUS_WRITE_SINGLE_COIL = 0x05,                
  MODBUS_WRITE_SINGLE_REGISTER = 0x06,            
  MODBUS_WRITE_MULTIPLE_COILS = 0x0F,             
  MODBUS_WRITE_MULTIPLE_REGISTERS = 0x10,         
};

enum T67XX_Registers {
  T67XX_REG_FIRMWARE = 0x1389,      
  T67XX_REG_STATUS = 0x138A,        
  T67XX_REG_PPM = 0x138B,           
  T67XX_REG_RESET = 0x03E8,         
  T67XX_REG_SPCAL = 0x03EC,         
  T67XX_REG_FLASH_UPDATE = 0x03ED,  
  T67XX_REG_ADDRESS = 0x0FA5,       
  T67XX_REG_ABC_LOGIC = 0x03EE,     
  T67XX_REG_MOD_MODE = 0x100B       
};

class T67XX {
public:
  T67XX(TwoWire* pWire = &Wire, uint8_t deviceAddress = T67XX_DEFAULT_I2C_ADDR)
    : _pWire(pWire), _deviceAddr(deviceAddress){};

  ~T67XX(){};

  bool begin(void);

  uint16_t readPPM(void);

  uint16_t getStatus(void);

  uint16_t getFirmwareVersion(void);

  void reset(void);
  void enableABCMode(void);

  void disableABCMode(void);
  uint8_t setSlaveAddress(uint8_t newAddress);

  void flashUpdate(void);

  bool beginCalibration(bool waitForCompletion = false);

  void endCalibration(void);

  String getStatusMsg(void);

  union StatusRegister {

    uint16_t raw_value;

    struct {
      uint16_t ERROR : 1;              
      uint16_t FLASH_ERROR : 1;        
      uint16_t CALIBRATION_ERROR : 1;  
      uint16_t : 7;                    
      uint16_t REBOOT : 1;             
      uint16_t WARMUP : 1;             
      uint16_t : 3;                    
      uint16_t SINGLE_POINT_CAL : 1;   
    } bits;
  };

private:
  uint8_t _data[6];

  uint8_t read8(uint16_t registerAddress);

  uint16_t read16(uint16_t registerAddress);

  uint8_t write8(uint16_t registerAddress, uint8_t data);

  uint16_t write16(uint16_t registerAddress, uint16_t data);

  TwoWire* _pWire;

  StatusRegister _status;

  uint8_t _deviceAddr;
};

#endif  // T67XX_H
```


