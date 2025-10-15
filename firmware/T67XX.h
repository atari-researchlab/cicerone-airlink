/**
 * @file    T67XX.h
 * @brief   Esta es una biblioteca para el módulo sensor de CO2 miniatura de la serie Telaire T67XX.
 * @details Estos sensores utilizan UART e I2C para comunicarse. Esta biblioteca está diseñada para la opción de
 * comunicación I2C. Se requieren 2 pines para la interfaz. Para habilitar la comunicación I2C, conecte el pin
 * CTRL (pin 6 del módulo) a GND.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note Este módulo se basa en la librería de Yaroslav Osadchyy (drug123@gmail.com) con MIT License
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
 * @brief Dirección I2C por defecto.
 */
#define T67XX_DEFAULT_I2C_ADDR 0x15

/**
 * @brief Valor para habilitar un registro.
 */
#define T67XX_REG_VAL_ENABLE 0xFF00

/**
 * @brief Valor para deshabilitar un registro.
 */
#define T67XX_REG_VAL_DISABLE 0x0000

/**
 * @brief Retardo entre transmisiones de lectura/escritura (valor recomendado por el fabricante).
 */
#define T67XX_READ_DELAY 10

/**
 * @brief Retardo entre el inicio de la medición en PPM y la lectura del dato (valor recomendado
 * por el fabricante).
 */
#define T67XX_MEASURE_DELAY 2250

/**
 * @brief   Códigos de función del protocolo Modbus.
 * @details La implementación de I2C utiliza el protocolo Modbus y encapsula el mensaje en formato
 * I2C; sin embargo, en este caso no se incluye el CRC. Los códigos de función varían segun el 
 * tipo de dato y si se realiza una lectura o escritura, simple o múltiple.
 *
 * Modelo de datos de Modbus:
 *
 * - Discrete Inputs: 1bit. Solo lectura.
 * - Coils: 1bit. Lectura/Escritura.
 * - Input Registers: 16bits. Solo lectura.
 * - Holding Registers: 16bits. Lectura/Escritura.
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
 * @brief Direcciones de los registros del T67XX.
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
 * @brief Clase para la comunicación del sensor de CO2 T67XX.
 */
class T67XX {
  /**
   * @brief Constructor de la clase T67XX.
   * @param pWire            Periférico utilizado para la comunicación I2C.
   * @param deviceAddress    Dirección I2C del sensor utilizado.
   */
  T67XX(TwoWire* pWire = &Wire, uint8_t deviceAddress = T67XX_DEFAULT_I2C_ADDR)
    : _pWire(pWire), _deviceAddr(deviceAddress){};

  /**
   * @brief Destructor de la clase T67XX.
   */
  ~T67XX(){};

  /**
   * @brief Inicializa la comunicación I2C.
   * @return Verdadero si tiene éxito la comunicación con el módulo, falso si es errónea.
   */
  bool begin(void);

  /**
   * @brief Obtiene el valor de CO2 actual del sensor en PPM.
   * @return Valor de CO2 en PPM.
   */
  uint16_t readPPM(void);

  /**
   * @brief Obtiene el estado actual del sensor y lo almacena en la variable interna.
   * @return Estado actual del sensor.
   */
  uint16_t getStatus(void);

  /**
   * @brief Obtiene la versión de firmware del sensor.
   * @return Versión del firmware.
   */
  uint16_t getFirmwareVersion(void);

  /**
   * @brief Reinicia el sensor.
   */
  void reset(void);
  /**
   * @brief   Habilitar autocalibración ABC.
   * @details La Lógica Automática de Fondo (Automatic Background Logic), es una técnica de
   * autocalibración patentada diseñada para usarse en aplicaciones donde las concentraciones
   * descienden a las condiciones ambientales exteriores (400 ppm) al menos una vez (15 minutos) en
   * un período de 7 días, lo cual suele ocurrir durante periodos desocupados.
   *
   * Se logra una precisión completa utilizando la Lógica ABC. Con la Lógica ABC activada, el sensor
   * generalmente alcanza su precisión operativa después de 25 horas de funcionamiento continuo,
   * siempre que haya estado expuesto a niveles ambientales de referencia de aire de 400 ppm ±10ppm
   * de CO2. El sensor mantendrá las especificaciones de precisión con la Lógica ABC activada,
   * siempre que esté  expuesto al valor de referencia al menos una vez cada 7 días, y este valor
   * de referencia sea la concentración más baja a la que está expuesto el sensor.
   *
   * @note La Lógica ABC requiere el funcionamiento continuo del sensor en incrementos de al menos
   * 4 horas cada uno.
   *
   * @warning No es recomendable en aplicaciones donde el sensor no esté expuesto regularmente a
   * aire fresco (400 ppm de CO2).
   */
  void enableABCMode(void);

  /**
   * @brief Deshabilitar autocalibración ABC.
   * @see enableABCMode()
   */
  void disableABCMode(void);
  /**
   * @brief   Modifica la dirección I2C interna del sensor.
   * @details Configura una nueva dirección I2C del sensor y lo reinicia para aplicar los cambios.
   *
   * @param   newAddress    Nueva dirección I2C del sensor
   * @return  Verdadero si tiene éxito la comunicación con el módulo en la nueva dirección,
   * falso si es errónea.
   *
   * @warning Este cambio es permanente al reiniciar el sensor.
   */
  uint8_t setSlaveAddress(uint8_t newAddress);

  /**
   * @brief Guarda la configuración en la flash.
   */
  void flashUpdate(void);

  /**
   * @brief     Inicia la rutina de calibración de punto único.
   * @details   La rutina de calibración de punto único se realiza generalmente a temperatura
   * ambiente (~500 ppm, 25 °C) y tarda varios minutos en completarse tras su inicio
   * (aproximadamente 6 minutos). Durante este tiempo, se puede consultar el estado del sensor
   * y las lecturas actuales de ppm del gas. El usuario puede comprobar el estado de la
   * calibración leyendo el registro de estado y anotando si el bit de calibración de punto
   * único está activado. La calibración se puede detener antes de que finalice.
   *
   * @param   waitForCompletion   Opcional: Espera a que finalice la calibración (deshabilitada
   *                              por defecto).
   * @return  Verdadero si ha finalizado la calibración.
   */
  bool beginCalibration(bool waitForCompletion = false);

  /**
   * @brief Detiene la rutina de calibración de punto único.
   */
  void endCalibration(void);

  /**
   * @brief Genera un mensaje con el estado actual del sensor.
   * @return Cadena con el estado actual del sensor.
   */
  String getStatusMsg(void);

  /**
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
     * @brief Acceso al estado completo de 16 bits.
     */
    uint16_t raw_value;

    /**
     * @brief Acceso a los bits individuales.
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
    /**
     * @brief Array para almacenar los datos leidos del dispositivo.
     */
    uint8_t _data[6];

    /**
     * @brief Lee el valor actual de un registro de 8bits.
     * @param registerAddress Dirección del registro a escribir.
     * @return Valor del registro leido.
     */
    uint8_t read8(uint16_t registerAddress);

    /**
     * @brief Lee el valor actual de un registro de 16bits.
     * @param registerAddress Dirección del registro a escribir.
     * @return Valor del registro leido.
     */
    uint16_t read16(uint16_t registerAddress);

    /**
     * @brief Escribe un dato en un registro de 8bits.
     * @param registerAddress Dirección del registro a escribir.
     * @param data Dato a escribir.
     * @return Valor del registro tras la escritura.
     */
    uint8_t write8(uint16_t registerAddress, uint8_t data);

    /**
     * @brief Escribe un dato en un registro de 16bits.
     * @param registerAddress Dirección del registro a escribir.
     * @param data Dato a escribir.
     * @return Valor del registro tras la escritura.
     */
    uint16_t write16(uint16_t registerAddress, uint16_t data);

    /**
     * @brief Puntero al periferico I2C utilizado.
     */
    TwoWire* _pWire;

    /**
     * @brief Último estado leido del dispositivo.
     */
    StatusRegister _status;

    /**
     * @brief Dirección I2C del módulo T67XX.
     */
    uint8_t _deviceAddr;
};

#endif  // T67XX_H
