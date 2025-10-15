/**
 * @file    T67XX.h
 * @brief   This is a library for the Telaire T67XX series miniature CO2 sensor module.
 * @details These sensors use UART and I2C to communicate. This library is designed for the I2C
 * communication option. 2 pins are required for the interface. To enable I2C communication,
 * connect pin CTRL (pin 6 of the module) to GND.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note This module is based on the library by Yaroslav Osadchyy (drug123@gmail.com) with MIT License
 *
 * Copyright (c) 2020 Yaroslav Osadchyy (drug123@gmail.com) https://github.com/drug123/T67XX
 *
 * MIT license, all text above must be included in any redistribution
 */

#ifndef T67XX_H
#define T67XX_H
#include <Arduino.h>
#include <Wire.h>

/**
 * @brief Default I2C address.
 */
#define T67XX_DEFAULT_I2C_ADDR 0x15

/**
 * @brief Value to enable a register.
 */
#define T67XX_REG_VAL_ENABLE 0xFF00

/**
 * @brief Value to disable a register.
 */
#define T67XX_REG_VAL_DISABLE 0x0000

/**
 * @brief Delay between read/write transmissions (manufacturer recommended value).
 */
#define T67XX_READ_DELAY 10

/**
 * @brief Delay between starting PPM measurement and reading the data (manufacturer
 * recommended value).
 */
#define T67XX_MEASURE_DELAY 2250

/**
 * @brief   Modbus function codes.
 * @details The I2C implementation uses the Modbus protocol and encapsulates the message in I2C
 * format; however, in this case CRC is not included. Function codes vary according to the
 * data type and whether a single or multiple read/write is performed.
 *
 * Modbus data model:
 *
 * - Discrete Inputs: 1bit. Read only.
 * - Coils: 1bit. Read/Write.
 * - Input Registers: 16bits. Read only.
 * - Holding Registers: 16bits. Read/Write.
 */
enum Modbus_FC {
  MODBUS_READ_COIL = 0x01,                        //!< Read 1bit _Coil_ type
  MODBUS_READ_DISCRETE_INPUT = 0x02,              //!< Read 1bit _Discrete Input_ type
  MODBUS_READ_MULTIPLE_HOLDING_REGISTERS = 0x03,  //!< Read 1 or more 16bit _Holding Registers_
  MODBUS_READ_INPUT_REGISTERS = 0x04,             //!< Read 1 or more 16bit _Input Registers_
  MODBUS_WRITE_SINGLE_COIL = 0x05,                //!< Write 1 1bit _Coil_
  MODBUS_WRITE_SINGLE_REGISTER = 0x06,            //!< Write 1 16bit _Holding Register_
  MODBUS_WRITE_MULTIPLE_COILS = 0x0F,             //!< Write multiple 1bit _Coils_
  MODBUS_WRITE_MULTIPLE_REGISTERS = 0x10,         //!< Write multiple 16bit _Holding Registers_
};

/**
 * @brief T67XX register addresses.
 */
enum T67XX_Registers {
  T67XX_REG_FIRMWARE = 0x1389,      //!< Device firmware revision (RO)
  T67XX_REG_STATUS = 0x138A,        //!< Device status (RO)
  T67XX_REG_PPM = 0x138B,           //!< Measured CO2 value (RO)
  T67XX_REG_RESET = 0x03E8,         //!< Reset the device (WO)
  T67XX_REG_SPCAL = 0x03EC,         //!< Start single point calibration (WO)
  T67XX_REG_FLASH_UPDATE = 0x03ED,  //!< Save configuration to flash (WO)
  T67XX_REG_ADDRESS = 0x0FA5,       //!< Device I2C address (RW)
  T67XX_REG_ABC_LOGIC = 0x03EE,     //!< Enable or disable ABC autocalibration (RW)
  T67XX_REG_MOD_MODE = 0x100B       //!< Enable or disable measurement on demand (MOD) (RW)
};

/**
 * @brief Class for T67XX CO2 sensor communication.
 */
class T67XX {
public:
  /**
   * @brief T67XX class constructor.
   * @param pWire            Peripheral used for I2C communication.
   * @param deviceAddress    I2C address of the sensor used.
   */
  T67XX(TwoWire* pWire = &Wire, uint8_t deviceAddress = T67XX_DEFAULT_I2C_ADDR)
    : _pWire(pWire), _deviceAddr(deviceAddress){};

  /**
   * @brief T67XX class destructor.
   */
  ~T67XX(){};

  /**
   * @brief Initializes I2C communication.
   * @return True if communication with the module is successful, false if it fails.
   */
  bool begin(void);

  /**
   * @brief Gets the current CO2 value from the sensor in PPM.
   * @return CO2 value in PPM.
   */
  uint16_t readPPM(void);

  /**
   * @brief Gets the current sensor status and stores it in the internal variable.
   * @return Current sensor status.
   */
  uint16_t getStatus(void);

  /**
   * @brief Gets the sensor firmware version.
   * @return Firmware version.
   */
  uint16_t getFirmwareVersion(void);

  /**
   * @brief Resets the sensor.
   */
  void reset(void);
  /**
   * @brief   Enable ABC autocalibration.
   * @details Automatic Background Logic (ABC) is a patented autocalibration technique designed
   * for use in applications where concentrations drop to outdoor ambient conditions (400 ppm) at
   * least once (15 minutes) in a 7-day period, which typically occurs during unoccupied periods.
   *
   * Full accuracy is achieved using ABC Logic. With ABC Logic enabled, the sensor generally
   * reaches its operational accuracy after 25 hours of continuous operation, provided it has been
   * exposed to reference ambient air levels of 400 ppm ±10ppm CO2. The sensor will maintain
   * accuracy specifications with ABC Logic enabled, as long as it is exposed to the reference
   * value at least once every 7 days, and this reference value is the lowest concentration to
   * which the sensor is exposed.
   *
   * @note ABC Logic requires continuous sensor operation in increments of at least 4 hours each.
   *
   * @warning Not recommended for applications where the sensor is not regularly exposed to
   * fresh air (400 ppm CO2).
   */
  void enableABCMode(void);

  /**
   * @brief Disable ABC autocalibration.
   * @see enableABCMode()
   */
  void disableABCMode(void);
  /**
   * @brief   Modifies the sensor's internal I2C address.
   * @details Configures a new sensor I2C address and resets it to apply the changes.
   *
   * @param   newAddress    New sensor I2C address
   * @return  True if communication with the module at the new address is successful,
   * false if it fails.
   *
   * @warning This change is permanent when the sensor is reset.
   */
  uint8_t setSlaveAddress(uint8_t newAddress);

  /**
   * @brief Saves configuration to flash.
   */
  void flashUpdate(void);

  /**
   * @brief     Starts the single point calibration routine.
   * @details   The single point calibration routine is generally performed at room temperature
   * (~500 ppm, 25 °C) and takes several minutes to complete after starting (approximately
   * 6 minutes). During this time, the sensor status and current ppm gas readings can be queried.
   * The user can check the calibration status by reading the status register and noting if the
   * single point calibration bit is active. Calibration can be stopped before it finishes.
   *
   * @param   waitForCompletion   Optional: Wait for calibration to finish (disabled by default).
   * @return  True if calibration has finished.
   */
  bool beginCalibration(bool waitForCompletion = false);

  /**
   * @brief Stops the single point calibration routine.
   */
  void endCalibration(void);

  /**
   * @brief Genera un mensaje con el estado actual del sensor.
   * @return Cadena con el estado actual del sensor.
   */
  String getStatusMsg(void);

  /**
   * @brief Each bit represents the status of a device function or error.
   * @details Allows verification of device status and the different errors that can occur.
   *
   * Under error conditions, a "1" indicates an error; a "0" indicates no error. A Flash error
   * is fatal (i.e., no recovery). Calibration errors can be cleared by running the calibration
   * procedure again with correct results.
   *
   * Under calibration conditions, a "1" indicates that the calibration cycle is in progress.
   * No other calibration cycle can be started while one is in progress and the Modbus response
   * will report an error to the new calibration request.
   *
   * If the warmup bit (_WARMUP_) is active, the sensor is in a mode where internal registers
   * and gas data (ppm) are being initialized and are not necessarily correct.
   */
  union StatusRegister {

    /**
     * @brief Access to the complete 16-bit status.
     */
    uint16_t raw_value;

    /**
     * @brief Access to individual bits.
     */
    struct {
      uint16_t ERROR : 1;              //!< Bit 0
      uint16_t FLASH_ERROR : 1;        //!< Bit 1
      uint16_t CALIBRATION_ERROR : 1;  //!< Bit 2
      uint16_t : 7;                    //!< Bits 3-9 (unused, ignored)
      uint16_t REBOOT : 1;             //!< Bit 10
      uint16_t WARMUP : 1;             //!< Bit 11
      uint16_t : 3;                    //!< Bits 12-14 (unused)
      uint16_t SINGLE_POINT_CAL : 1;   //!< Bit 15
    } bits;
  };

private:
  /**
   * @brief Array to store data read from device.
   */
  uint8_t _data[6];

  /**
   * @brief Reads the current value of an 8-bit register.
   * @param registerAddress Address of the register to write.
   * @return Value of the register read.
   */
  uint8_t read8(uint16_t registerAddress);

  /**
   * @brief Reads the current value of a 16-bit register.
   * @param registerAddress Address of the register to write.
   * @return Value of the register read.
   */
  uint16_t read16(uint16_t registerAddress);

  /**
   * @brief Writes data to an 8-bit register.
   * @param registerAddress Address of the register to write.
   * @param data Data to write.
   * @return Register value after writing.
   */
  uint8_t write8(uint16_t registerAddress, uint8_t data);

  /**
   * @brief Writes data to a 16-bit register.
   * @param registerAddress Address of the register to write.
   * @param data Data to write.
   * @return Register value after writing.
   */
  uint16_t write16(uint16_t registerAddress, uint16_t data);

  /**
   * @brief Pointer to the I2C peripheral used.
   */
  TwoWire* _pWire;

  /**
   * @brief Last status read from device.
   */
  StatusRegister _status;

  /**
   * @brief I2C address of the T67XX module.
   */
  uint8_t _deviceAddr;
};

#endif  // T67XX_H
