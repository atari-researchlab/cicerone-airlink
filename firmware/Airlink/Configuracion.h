/***********************************************************************************************************************
 * @file        Configuracion.h
 * @brief       Archivo de configuración global para el proyecto Airlink.
 * Este archivo centraliza todas las opciones que se pueden ajustar para
 * cambiar el comportamiento del firmware sin modificar el código fuente principal.
 *
 * @author      [ALD-DSL/ATARI-UCA]
 * @date        [2024-07/Última Modificación]
 * @version     1.0
 * @license     Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-SA 4.0)
 * Este archivo es parte de tu proyecto principal y está bajo la Licencia CC-BY-SA 4.0.
 * Para más detalles, consulta: https://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Modifica este archivo para cambiar el comportamiento del programa sin alterar
 * el código principal.
 **********************************************************************************************************************/

#ifndef CONFIGURACION_H
#define CONFIGURACION_H

/***********************************************************************************************************************
 * IDENTIFICACIÓN DEL DISPOSITIVO
 **********************************************************************************************************************/
// Define un ID único para este dispositivo.
#define ID_USUARIO "AIRLINK_01"

/***********************************************************************************************************************
 * HABILITACIÓN DE MÓDULOS DE FUNCIONALIDAD
 * Comenta o descomenta estas líneas para incluir o excluir funcionalidades del programa final.
 * Esto es útil para ahorrar memoria y potencia si no se usan todos los módulos.
 **********************************************************************************************************************/
// Descomenta la siguiente línea para habilitar la transmisión de datos por NB-IoT.
#define HABILITAR_NBIOT 1

// Descomenta la siguiente línea para habilitar la detección de tos con Edge Impulse.
// #define HABILITAR_TOS 1

/***********************************************************************************************************************
 * CONFIGURACIÓN DE SERVIDOR PARA TRANSMISIÓN NB-IoT
 *
 * Define la dirección IP y el puerto del servidor al que se enviarán los datos.
 **********************************************************************************************************************/
// Configuracion del servidor de envío de datos
#define SERVIDOR_IP "http://nbiot.alara.org.es"
#define SERVIDOR_PUERTO "4430"
#define SERVIDOR_API "/adquisicion/aqindoor"

// Introducir APN del proveedor de internet
// #define APN_NBIOT ""  //Hay proveedores para los que no es necesario introducir el APN
#define APN_NBIOT "iot.1nce.net"
// #define APN_NBIOT "TM" //APN de ThingMobile

#endif // CONFIGURACION_H
