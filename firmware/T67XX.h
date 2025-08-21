/***********************************************************************************************************************
 * @file        T67XX.h
 * @brief       Esta es una biblioteca para el módulo sensor de CO2 miniatura de la serie Telaire T67XX.
 * @details Estos sensores utilizan UART e I2C para comunicarse. Esta biblioteca está diseñada para la opción de
 * comunicación I2C. Se requieren 2 pines para la interfaz. Para habilitar la comunicación I2C, conecte el pin
 * CTRL (pin 6 del módulo) a GND.
 *
 * @author      [ALD/ATARI_RESEARCH_LAB]
 * @date        2024
 * @version     1.1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note Este módulo se basa en la librería de Yaroslav Osadchyy (drug123@gmail.com) con MIT License
 *
 * Copyright (c) 2020 Yaroslav Osadchyy (drug123@gmail.com)
 *
 * MIT license, all text above must be included in any redistribution
 *
 * URL: https://github.com/drug123/T67XX
 **********************************************************************************************************************/

#ifndef T67XX_H
#define T67XX_H
#include <Arduino.h>
#include <Wire.h>

#define T67XX_DEFAULT_I2C_ADDR 0x15   //!< Dirección I2C por defecto
#define T67XX_REG_VAL_ENABLE 0xFF00   //!< Valor para habilitar un registro
#define T67XX_REG_VAL_DISABLE 0x0000  //!< Valor para deshabilitar un registro
#define T67XX_READ_DELAY 10           //!< Retardo entre transmisiones de lectura/escritura (valor recomendado por el fabricante)
#define T67XX_MEASURE_DELAY 2250      //!< Retardo entre el inicio de la medición en PPM y la lectura del dato (valor recomendado por el fabricante)

/**
 * @enum Modbus_FC
 * @brief Códigos de función del protocolo Modbus.
 * @details La implementación de I2C utiliza el protocolo Modbus y encapsula el mensaje en 
 * formato I2C; sin embargo, en este caso no se incluye el CRC. Los códigos de función varían
 * segun el tipo de dato y si se realiza una lectura o escritura, simple o múltiple.
 *
 * Modelo de datos de Modbus:
 *  - Discrete Inputs: 1bit - Solo lectura
 *  - Coils: 1bit - Lectura/Escritura
 *  - Input Registers: 16bits - Solo lectura
 *  - Holding Registers: 16bits - Lectura/Escritura
 */
enum Modbus_FC {
  MODBUS_READ_COIL = 0x01,                        //!< Lectura de 1bit de tipo _Coil_
  MODBUS_READ_DISCRETE_INPUT = 0x02,              //!< Lectura de 1bit de tipo _Discrete Input_
  MODBUS_READ_MULTIPLE_HOLDING_REGISTERS = 0x03,  //!< Lectura de 1 o varios _Holding Registers_ de 16bits
  MODBUS_READ_INPUT_REGISTERS = 0x04,             //!< Lectura de 1 o varios _Input Registers_ de 16bits
  MODBUS_WRITE_SINGLE_COIL = 0x05,                //!< Escritura de 1 _Coil_ de 1 bit
  MODBUS_WRITE_SINGLE_REGISTER = 0x06,            //!< Escritura de 1 _Holding Registers_ de 16bits
  MODBUS_WRITE_MULTIPLE_COILS = 0x0F,             //!< Escritura de múltiples _Coil_ de 1 bit
  MODBUS_WRITE_MULTIPLE_REGISTERS = 0x10,         //!< Escritura de múltiples _Holding Registers_ de 16bits
};

/**
 * @enum T67XX_Registers
 * @brief Direcciones de los registros del T67XX
 */
enum T67XX_Registers {
  T67XX_REG_FIRMWARE = 0x1389,      //!< Revisión del firmware del dispositivo (RO)
  T67XX_REG_STATUS = 0x138A,        //!< Estado del dispositivo (RO)
  T67XX_REG_PPM = 0x138B,           //!< Valor de CO2 medido (RO)
  T67XX_REG_RESET = 0x03E8,         //!< Reiniciar el dispositivo (WO)
  T67XX_REG_SPCAL = 0x03EC,         //!< Iniciar la calibración de punto único (WO)
  T67XX_REG_FLASH_UPDATE = 0x03ED,  //!< Guardar la configuración en la flash (WO)
  T67XX_REG_ADDRESS = 0x0FA5,       //!< Dirección I2C del dispositivo (RW)
  T67XX_REG_ABC_LOGIC = 0x03EE,     //!< Habilita o deshabilita la autocalibración ABC (RW)
  T67XX_REG_MOD_MODE = 0x100B       //!< Habilita o deshabilita la medición bajo demanda (MOD) (RW)
};

/**
 * @class T67XX
 * @brief Clase para la comunicación del sensor de CO2 T67XX.
 */
class T67XX {
public:
  /**
    * @brief Constructor de la clase T67XX.
    * @param pWire            Periférico utilizado para la comunicación I2C
    * @param deviceAddress    Dirección I2C del sensor utilizado
    */
  T67XX(TwoWire* pWire = &Wire, uint8_t deviceAddress = T67XX_DEFAULT_I2C_ADDR)
    : _pWire(pWire), _deviceAddr(deviceAddress){};

  /**
    * @brief Destructor de la clase T67XX.
    */
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

  /**
    * @union StatusRegister
    * @brief Cada bit representa el estado de una función o error del dispositivo.
    * @details Permite la verificación del estado del dispositivo y los diferentes errores que
    * pueden ocurrir.
    *
    * En condiciones de error, un "1" indica un error; un "0" indica que no hay error. Un error
    * de Flash es fatal (es decir, no hay recuperación). Los errores de calibración se pueden
    * eliminar ejecutando el procedimiento de calibración de nuevo con resultados correctos.
    *
    * En condiciones de calibración, un "1" indica que el ciclo de calibración está en curso.
    * No se puede iniciar ningún otro ciclo de calibración mientras uno esté en curso y la
    * respuesta Modbus informará un error a la nueva solicitud de calibración.
    *
    * Si el bit de calentamiento (_WARMUP_) está activo, el sensor se encuentra en un modo en el
    * que se están inicializando los registros internos y los datos de gas (ppm) no son
    * necesariamente correctos.
    */
  union StatusRegister {

    /**
     * @brief Acceso al estado completo de 16 bits
     */
    uint16_t raw_value;

    /**
     * @brief Acceso a los bits individuales
     */
    struct {
      uint16_t ERROR : 1;              //!< Bit 0
      uint16_t FLASH_ERROR : 1;        //!< Bit 1
      uint16_t CALIBRATION_ERROR : 1;  //!< Bit 2
      uint16_t : 7;                    //!< Bits 3-9 (sin usar, se ignoran)
      uint16_t REBOOT : 1;             //!< Bit 10
      uint16_t WARMUP : 1;             //!< Bit 11
      uint16_t : 3;                    //!< Bits 12-14 (sin usar)
      uint16_t SINGLE_POINT_CAL : 1;   //!< Bit 15
    } bits;
  };

private:
  uint8_t _data[6];  //!< Array para almacenar los datos leidos del dispositivo
  uint8_t read8(uint16_t registerAddress);
  uint16_t read16(uint16_t registerAddress);
  uint8_t write8(uint16_t registerAddress, uint8_t data);
  uint16_t write16(uint16_t registerAddress, uint16_t data);

  TwoWire* _pWire;         //!< Puntero al periferico I2C utilizado
  StatusRegister _status;  //!< Último estado leido del dispositivo
  uint8_t _deviceAddr;     //!< Dirección I2C del módulo RTC
};

#endif  // T67XX_H
