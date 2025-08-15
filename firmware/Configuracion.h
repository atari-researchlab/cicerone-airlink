/***********************************************************************************************************************
 * @file        Configuracion.h
 * @brief       Archivo de configuración global para el proyecto Airlink.
 * @details     Este archivo centraliza todas las opciones que se pueden ajustar para
 * cambiar el comportamiento del firmware sin modificar el código fuente principal.
 *
 * @author      [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date        [2024-07/Última Modificación]
 * @version     1.0
 *
 * @copyright   GNU General Public License version 3 or later
 *
 * @note        Modifica este archivo para cambiar el comportamiento del programa sin alterar
 * el código principal.
 **********************************************************************************************************************/

#ifndef CONFIGURACION_H
#define CONFIGURACION_H

/**
 * @def       ID_USUARIO
 * @brief     Identificación del dispositivo
 * @details   Define un ID único para este dispositivo.
 */
#define ID_USUARIO "AIRLINK_01"

/**
 * @def       HABILITAR_NBIOT
 * @brief     Descomentar para habilitar la transmisión de datos mediante NB-IoT.
 * @details   Comenta o descomenta estas líneas para incluir o excluir funcionalidades del programa final.
 * Esto es útil para ahorrar memoria y potencia si no se usan todos los módulos.
 */
#define HABILITAR_NBIOT 1

/**
 * @{
 * @name      Configuración del servidor para la transmisión mediante NB-IoT
 * @details   Define la dirección IP y el puerto del servidor al que se enviarán los datos, así como el punto de acceso
 * a la API.
 */
#define SERVIDOR_IP "http://direccion.servidor.com"  //!< IP del servidor donde se enviarán los datos
#define SERVIDOR_PUERTO "1234"                   //!< Puerto del servidor
#define SERVIDOR_API "/aqindoor"     //!< Ubicación de la API para realizar los envios mediante HTTP
/**@}*/

/**
 * @def     APN_NBIOT
 * @brief   APN del proveedor de internet.
 * @details Introducir el APN del proveedor de internet. Hay proveedores para los que no es necesario introducir el APN.
 * Ejemplos:
 * @code{.cpp}
   #define APN_NBIOT ""             // Sin APN
   #define APN_NBIOT "iot.1nce.net" // APN de 1NCE
   #define APN_NBIOT "TM"           // APN de ThingMobile
 * @endcode
 */
#define APN_NBIOT "iot.1nce.net"

#endif  // CONFIGURACION_H
