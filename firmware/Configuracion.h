/**
 * @file    Configuracion.h
 * @brief   Global configuration file for the Airlink project.
 * @details This file centralizes all options that can be adjusted to change the 
 * firmware behavior without modifying the source code.
 *
 * @author    [ALD-DSL/ATARI_RESEARCH_LAB]
 * @date      [2024-07-22/2025-10-15]
 * @version   2.0
 *
 * @copyright GNU General Public License version 3 or later
 *
 * @note  Modify this file to change the program behavior without altering the main code.
 */

#ifndef CONFIGURACION_H
#define CONFIGURACION_H

/**
 * @brief     Device identification
 * @details   Defines a unique ID for this device.
 */
#define ID_USUARIO "AIRLINK_01"

/**
 * @brief     Uncomment to enable data transmission via NB-IoT.
 * @details   Comment or uncomment these lines to include or exclude functionalities from the final program.
 * This is useful to save memory and power if not all modules are used.
 */
#define HABILITAR_NBIOT 1

/**
 * @name      Server configuration for NB-IoT transmission
 * @details   Defines the IP address and port of the server where data will be sent, as well as the API endpoint.
 * @{
 */
#define SERVIDOR_IP "http://direccion.servidor.com"   //!< Server IP where data will be sent
#define SERVIDOR_PUERTO "64340"                       //!< Server port
#define SERVIDOR_API "/aqindoor"          //!< API location for HTTP transmissions
//!@}

/**
 * @brief   Internet provider APN.
 * @details Enter the internet provider APN. Some providers do not require an APN to be entered.
 * 
 * Examples:
 * 
 * @code{.cpp}
 * #define APN_NBIOT ""             // No APN
 * #define APN_NBIOT "iot.1nce.net" // 1NCE APN
 * #define APN_NBIOT "TM"           // ThingMobile APN
 * @endcode
 */
#define APN_NBIOT "iot.1nce.net"

#endif  // CONFIGURACION_H
