/***********************************************************************************************************************
 * @file        Transmision_NBIOT.cpp
 * @brief       Implementación de las funciones para la transmisión de datos vía NB-IoT.
 * Este archivo contiene las definiciones de las variables globales y las implementaciones
 * de las funciones declaradas en 'Transmision_NBIOT.h'.
 *
 * @author      [ALD-DSL/ATARI-UCA]
 * @date        [2024-07/Última Modificación]
 * @version     1.0
 * @license     Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-SA 4.0)
 * Este archivo es parte de tu proyecto principal y está bajo la Licencia CC-BY-SA 4.0.
 * Las librerías subyacentes como 'ArduinoJson' están bajo Licencia MIT, compatible con CC-BY-SA 4.0.
 * Para más detalles, consulta: https://creativecommons.org/licenses/by-sa/4.0/
 *
 * @note        Este módulo es fundamental para la conectividad y el envío de datos recopilados
 * por los sensores a una plataforma de monitoreo remoto.
 **********************************************************************************************************************/
#include "Configuracion.h"
#if HABILITAR_NBIOT

/***********************************************************************************************************************
 * INCLUSIÓN DE LIBRERÍAS Y ARCHIVOS DE CABECERA DEL PROYECTO
 **********************************************************************************************************************/
//#include <String.h>
#include <ArduinoJson.h>
#include "Configuracion.h"      // Archivo de configuración central para habilitar/deshabilitar módulos.
#include "Debug.h"              // Contiene las macros para controlar la salida de depuración por Serial.
#include "Transmision_NBIOT.h"  // Incluye la cabecera con las declaraciones de este módulo.
#include "Alarma.h"             // Incluye la cabecera con las declaraciones de este módulo.
#include "SEN5X_API.h"          // Incluye la cabecera para la lectura del sensor SEN5X.
#include "T6793_API.h"          // Incluye la cabecera para la lectura del sensor T6793.
/*
#if HABILITAR_TOS
#include "Tos.h" // Módulo para la detección de tos usando un modelo de Machine Learning (Edge Impulse).
#endif
*/

#define DEBUG_TAG "NBIOT"
#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_NBIOT

/***********************************************************************************************************************
 * DEFINICIONES DE VARIABLES GLOBALES PARA DATOS DE TRANSMISIÓN
 *
 * Aquí se definen (se les asigna memoria) las variables globales declaradas en 'Transmision_NBIOT.h'.
 **********************************************************************************************************************/
String ppm1 = "100";   // Valor de PM1.0 (ejemplo inicial).
String ppm25 = "100";  // Valor de PM2.5 (ejemplo inicial).
String ppm4 = "100";   // Valor de PM4.0 (ejemplo inicial).
String ppm10 = "100";  // Valor de PM10.0 (ejemplo inicial).
String temp = "22";    // Valor de temperatura (ejemplo inicial).
String hum = "70";     // Valor de humedad (ejemplo inicial).
String co2 = "10";     // Valor de CO2 (ejemplo inicial).
String voc = "15";     // Valor de VOC (ejemplo inicial).
// String nox = "100";    // Valor de NOx (ejemplo inicial).
// String tos = "-1";     // Valor de detección de tos (ejemplo inicial, -1 indica no disponible/no detectado).

JsonDocument doc;
String json_data;  // Cadena que contendrá el payload JSON completo.
String hexData;    // Cadena que contendrá los datos JSON en formato hexadecimal.

const char* respuestas[5] = { "", "OK", "NOTOK", "TIMEOUTERR", "RST" };

/***********************************************************************************************************************
 * IMPLEMENTACIONES DE FUNCIONES PÚBLICAS DEL MÓDULO DE TRANSMISIÓN
 **********************************************************************************************************************/

/**
 * @brief Inicializa el módulo NB-IoT (SIM7020).
 * Configura el puerto serie para la comunicación con el módulo y realiza
 * una serie de comandos AT para asegurar que el módulo esté operativo y conectado a la red.
 */
void nbiot_inicializar() {

  SIM7020board.begin(SIM7020baud);  // Inicia la comunicación serie con el módulo NB-IoT.
  delay(100);                       // Pequeña espera para estabilización.

  SIM7020begin();

  // Envía comandos AT y espera respuestas "OK" para verificar la comunicación y el estado del módulo.
  SIM7020command("AT", "OK", "yy", 3000, 2);  // Comando AT básico para verificar la conexión.
  delay(500);

  SIM7020command("AT+CSQ", "OK", "yy", 3000, 2);  // Verifica la calidad de la señal.
  delay(500);

  SIM7020command("AT+CFUN=0", "OK", "yy", 5000, 2);  // Apagar la radio del módulo
  delay(1000);

  SIM7020command("AT*MCGDEFCONT=\"IP\",\"" APN_NBIOT "\"", "OK", "yy", 3000, 1);  // Set Default PSD Connection Settings
  delay(1000);

  SIM7020command("AT+CFUN=1", "OK", "yy", 5000, 2);  // Activar la radio del módulo
  delay(3000);
  SIM7020command("AT+CGATT?", "OK", "yy", 5000, 2);  // Verifica el estado de conexión al GPRS/NB-IoT.
  delay(500);
  SIM7020command("AT+CGCONTRDP=?", "OK", "yy", 5000, 2);
  delay(500);
}

bool SIM7020begin() {
  uint16_t reintentos = 0;
  byte hi;  // 1: registered, home network ; 5: registered, roaming

  do {
    SIM7020board.println("AT+CREG?");
    hi = SIM7020waitFor("0,", "1,", 2500);
    reintentos += 1;
    if (reintentos > 1000) {
      while (1 == 1) {
        digitalWrite(LED_BUILTIN, 1);
        delay(500);
        digitalWrite(LED_BUILTIN, 0);
        delay(500);
      };
    }
  } while (hi != OK);

  if (SIM7020command("AT&F0", "OK", "yy", 5000, 2) == OK) {                   // Reset to factory settings
    if (SIM7020command("ATE0", "OK", "yy", 5000, 2) == OK) {                  // disable Echo
      if (SIM7020command("AT+CMEE=2", "OK", "yy", 5000, 2) == OK) return OK;  // Habilita informes de error extendidos.
      else return NOTOK;
    }
  }
  return NOTOK;
}

String SIM7020read(void) {
  String reply = "";
  if (SIM7020board.available()) {
    reply = SIM7020board.readString();
  }
  return reply;
}

/**
 * @brief Envía un comando AT al módulo SIM7020 y espera una respuesta específica.
 * @param command El comando AT a enviar.
 * @param response1 La cadena de respuesta esperada para considerar el comando exitoso.
 * @param response2 Cadena a buscar si no se espera una respuesta "OK".
 * @param timeout Tiempo máximo de espera para la respuesta en milisegundos.
 * @param repetitions Número de reintentos si la respuesta no es la esperada.
 * @return OK si la respuesta es la esperada, NOTOK si no, TIMEOUTERR si se agota el tiempo.
 */
byte SIM7020command(String command, String response1, String response2, unsigned long timeout, uint16_t repetitions) {
  byte returnValue = RST;
  uint16_t count = 0;
  DEBUG_INFO("Comando enviado: %s", command.c_str());
  while (count < repetitions && returnValue != OK) {
    SIM7020board.println(command);
    if (SIM7020waitFor(response1, response2, timeout) == OK) {
      returnValue = OK;
    } else
      returnValue = NOTOK;
    count++;
  }
  DEBUG_INFO("Ans: %s", respuestas[returnValue]);
  return returnValue;
}

/**
 * @brief Función de espera una respuesta específica con tiempo máximo.
 * @param response1 La cadena de respuesta esperada para considerar el comando exitoso.
 * @param response2 Cadena a buscar si no se espera una respuesta "OK".
 * @param timeout Tiempo máximo de espera para la respuesta en milisegundos.
 * @return OK si la respuesta es la esperada, NOTOK si no, TIMEOUTERR si se agota el tiempo.
 */
byte SIM7020waitFor(String response1, String response2, unsigned long timeout) {
  unsigned long millis0 = millis();
  String reply;
  byte retVal = RST;
  do {
    reply = SIM7020board.readString();  //SIM7020read();
    if (reply != "") {
      reply.replace('\n', ' ');
      DEBUG_VERBOSE("Ans: %s in %u ms", reply.c_str(), (millis() - millis0));
    }
  } while ((reply.indexOf(response1) + reply.indexOf(response2) == -2) && (millis() - millis0) < timeout);

  if ((millis() - millis0) >= timeout) {
    retVal = TIMEOUTERR;
  } else {
    if (reply.indexOf(response1) + reply.indexOf(response2) > -2)
      retVal = OK;
    else
      retVal = NOTOK;
  }

  return retVal;
}

/**
 * @brief Transmite los datos de los sensores al servidor.
 * Esta función es la principal para la transmisión de datos.
 * Construye el JSON, lo convierte a hexadecimal y realiza la solicitud HTTP POST.
 */
void nbiot_enviar(void) {
  nbiot_paquete();     // Llama a la función para crear el payload JSON.
  nbiot_transmitir();  // Llama a la función para realizar la solicitud HTTP POST.
}

/**
 * @brief Crea el payload JSON con los datos actuales de los sensores.
 * Los datos se obtienen de las variables globales y se formatean en una cadena JSON.
 */
void nbiot_paquete(void) {

  doc["id"] = ID_USUARIO;
  doc["fecha"] = fecha;
  doc["hora"] = hora;
  doc["ppm1"] = String(avg_sen5x_mc_1p0);
  doc["ppm25"] = String(avg_sen5x_mc_2p5);
  doc["ppm4"] = String(avg_sen5x_mc_4p0);
  doc["ppm10"] = String(avg_sen5x_mc_10p0);
  doc["temp"] = String(avg_temp);
  doc["hum"] = String(avg_hum);
  doc["co2"] = String(avg_t6793_co2);
  doc["voc"] = String(avg_sen5x_voc);
  //doc["nox"] = String(avg_sen5x_nox);
  //doc["tos"] = HABILITAR_TOS ? String(tTos) : "0";

  serializeJsonPretty(doc, json_data);
  DEBUG_INFO("JSON: %s", json_data.c_str());  // Imprime el JSON para depuración.

  // Convierte el JSON a datos hexadecimales
  hexData = jsonToHex(doc);
  DEBUG_VERBOSE("hexData: %s", hexData.c_str());
}

/**
 * @brief Convierte un objeto JSON a una cadena hexadecimal.
 * @param doc El objeto DynamicJsonDocument a convertir.
 * @return Cadena que representa el JSON en formato hexadecimal.
 */
String jsonToHex(const JsonDocument& doc) {
  String hexString = "";
  serializeJson(doc, json_data);

  // Itera sobre cada carácter de la cadena JSON.
  for (int i = 0; i < json_data.length(); i++) {
    hexString += String(json_data[i], HEX);
  }

  return hexString;  // Retorna la cadena hexadecimal.
}

/**
 * @brief Realiza una solicitud HTTP POST al servidor.
 * Utiliza comandos AT específicos del módulo SIM7020 para crear una conexión HTTP
 * y enviar los datos hexadecimales como payload.
 */
void nbiot_transmitir(void) {
  byte ans = NOTOK;

  ans = SIM7020command("AT+CHTTPCREATE=\"" + String(SERVIDOR_IP) + ":" + String(SERVIDOR_PUERTO) + "\"", "OK", "yy", 3000, 2);
  delay(500);
  DEBUG_INFO("Creando conexion (AT+CHTTPCREATE)... %s", respuestas[ans]);

  ans = SIM7020command("AT+CHTTPCON=0", "OK", "yy", 5000, 2);
  if (ans != OK) {
    DEBUG_ERROR("Conectando al servidor (AT+CHTTPCON)... %s", respuestas[ans]);
    delay(5000);
    Reiniciar_Dispositivo();
  }
  DEBUG_INFO("Conectando al servidor (AT+CHTTPCON)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPSEND=0,1,\"" SERVIDOR_API "\",,\"application/json\"," + hexData, "OK", "yy", 5000, 2);
  if (ans != OK) {
    DEBUG_ERROR("Enviando datos (AT+CHTTPSEND)... %s", respuestas[ans]);
    delay(5000);
    Reiniciar_Dispositivo();
  }
  DEBUG_INFO("Enviando datos (AT+CHTTPSEND)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPDISCON=0", "OK", "yy", 5000, 2);
  DEBUG_INFO("Desconectando (AT+CHTTPDISCON)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPDESTROY=0", "OK", "yy", 5000, 2);
  DEBUG_INFO("Destruyendo conexion (AT+CHTTPDESTROY)... %s", respuestas[ans]);
}

#endif  // HABILITAR_NBIOT