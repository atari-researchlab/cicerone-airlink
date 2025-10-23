

# File T67XX.cpp

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**T67XX.cpp**](T67XX_8cpp.md)

[Go to the documentation of this file](T67XX_8cpp.md)


```C++


#include "T67XX.h"
#include "Debug.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_T6793  
#define DEBUG_TAG "T67XX"        

bool T67XX::begin(void) {
  _pWire->begin();
  delay(100);
  _pWire->beginTransmission(_deviceAddr);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
}

uint16_t T67XX::readPPM(void) {
  DEBUG_VERBOSE("Reading CO2 value [PPM]...");
  return this->read16(T67XX_REG_PPM);
};

uint16_t T67XX::getStatus(void) {
  DEBUG_VERBOSE("Reading sensor status...");

  _status.raw_value = this->read16(T67XX_REG_STATUS);

  DEBUG_INFO("Status: %u", _status.raw_value);
  DEBUG_VERBOSE("FEDCBA9876543210");
  String sStatus = String("0000000000000000") + String(_status.raw_value, BIN);
  sStatus.remove(0, sStatus.length() - 16);
  DEBUG_VERBOSE("%s", sStatus.c_str());
  DEBUG_VERBOSE("Flags: %s", this->getStatusMsg().c_str());

  return _status.raw_value;
};

uint16_t T67XX::getFirmwareVersion(void) {
  DEBUG_VERBOSE("Reading firmware version...");
  uint16_t firmware_version = this->read16(T67XX_REG_FIRMWARE);
  DEBUG_VERBOSE("Firmware: 0x%04X", firmware_version);
  return firmware_version;
};

void T67XX::reset(void) {
  DEBUG_VERBOSE("Resetting...");
  this->write16(T67XX_REG_RESET, T67XX_REG_VAL_ENABLE);
};

void T67XX::enableABCMode(void) {
  DEBUG_VERBOSE("Enabling ABC autocalibration");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_ENABLE);
};

void T67XX::disableABCMode(void) {
  DEBUG_VERBOSE("Disabling ABC autocalibration");
  this->write16(T67XX_REG_ABC_LOGIC, T67XX_REG_VAL_DISABLE);
};

uint8_t T67XX::setSlaveAddress(uint8_t newAddress) {
  DEBUG_VERBOSE("Setting new I2C address to 0x%02X", newAddress);
  _deviceAddr = newAddress;
  this->write8(T67XX_REG_ADDRESS, newAddress);
  this->reset();
  delay(1000);
  _pWire->beginTransmission(newAddress);
  if (_pWire->endTransmission() == 0)
    return true;
  else
    return false;
};

void T67XX::flashUpdate(void) {
  DEBUG_VERBOSE("Saving configuration to flash...");
  this->write16(T67XX_REG_FLASH_UPDATE, T67XX_REG_VAL_ENABLE);
}

bool T67XX::beginCalibration(bool waitForCompletion) {
  DEBUG_VERBOSE("Starting single point calibration %s wait...", waitForCompletion ? "with" : "without");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_ENABLE);
  do {
    _status.raw_value = this->getStatus();
    delay(100);
  } while (waitForCompletion && _status.bits.SINGLE_POINT_CAL);

  return !_status.bits.SINGLE_POINT_CAL;
};

void T67XX::endCalibration(void) {
  DEBUG_VERBOSE("Terminating single point calibration");
  this->write16(T67XX_REG_SPCAL, T67XX_REG_VAL_DISABLE);
};

uint8_t T67XX::read8(uint16_t registerAddress) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_READ_INPUT_REGISTERS);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 4);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Byte count = %u", _data[1]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[2] << 8) | _data[3]);
  return _data[3];
}

uint16_t T67XX::read16(uint16_t registerAddress) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_READ_INPUT_REGISTERS);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(0x01);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 4);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Byte count = %u", _data[1]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[2] << 8) | _data[3]);
  return ((_data[2] << 8) | _data[3]);
}

uint8_t T67XX::write8(uint16_t registerAddress, uint8_t data) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_WRITE_SINGLE_REGISTER);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(0x00);
  Wire.write(data);
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Reg. Address = 0x%04X", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[3] << 8) | _data[4]);
  return _data[4];
}

uint16_t T67XX::write16(uint16_t registerAddress, uint16_t data) {
  Wire.beginTransmission(_deviceAddr);
  Wire.write(MODBUS_WRITE_SINGLE_COIL);
  Wire.write(byte(registerAddress >> 8));
  Wire.write(byte(registerAddress & 0xFF));
  Wire.write(byte(data >> 8));
  Wire.write(byte(data & 0xFF));
  Wire.endTransmission();

  delay(T67XX_READ_DELAY);

  Wire.requestFrom(int(_deviceAddr), 5);
  _data[0] = Wire.read();
  _data[1] = Wire.read();
  _data[2] = Wire.read();
  _data[3] = Wire.read();
  _data[4] = Wire.read();
  DEBUG_VERBOSE("Ret. Fun. Code = 0x%02X", _data[0]);
  DEBUG_VERBOSE("Ret. Reg. Address = 0x%04X", (_data[1] << 8) | _data[2]);
  DEBUG_VERBOSE("Ret. Data = 0x%04X", (_data[3] << 8) | _data[4]);
  return ((_data[3] << 8) | _data[4]);
}

String T67XX::getStatusMsg(void) {
  String statusString = "";

  if (_status.raw_value) {
    if (_status.bits.ERROR)
      statusString.concat("GENERAL ERROR; ");
    if (_status.bits.CALIBRATION_ERROR)
      statusString.concat("CALIBRATION ERROR; ");
    if (_status.bits.FLASH_ERROR)
      statusString.concat("FLASH ERROR; ");
    if (_status.bits.REBOOT)
      statusString.concat("REBOOT; ");
    if (_status.bits.WARMUP)
      statusString.concat("WARMUP; ");
    if (_status.bits.SINGLE_POINT_CAL)
      statusString.concat("CALIBRATING");
  } else
    statusString = "OK";

  return statusString;
}
```


