

# File Transmision\_NBIOT.cpp

[**File List**](files.md) **>** [**firmware**](dir_d9edf6c004b4a7ff14fe9ae7a92214ee.md) **>** [**Transmision\_NBIOT.cpp**](Transmision__NBIOT_8cpp.md)

[Go to the documentation of this file](Transmision__NBIOT_8cpp.md)


```C++


#include "Configuracion.h"

#if HABILITAR_NBIOT

#include <ArduinoJson.h>
#include "Debug.h"
#include "Transmision_NBIOT.h"
#include "Alarma.h"

#undef DEBUG_LEVEL
#define DEBUG_LEVEL DEBUG_NBIOT  
#define DEBUG_TAG "NBIOT"        

String ppm1 = "100";   
String ppm25 = "100";  
String ppm4 = "100";   
String ppm10 = "100";  
String temp = "22";    
String hum = "70";     
String co2 = "10";     
String voc = "15";     
String nox = "100";    
JsonDocument doc;      
String json_data;      
String hexData;        

const char* respuestas[5] = { "", "OK", "NOTOK", "TIMEOUTERR", "RST"};

void nbiot_inicializar(void) {

  SIM7020board.begin(SIM7020baud);  // Starts serial communication with the NB-IoT module.
  delay(100);                       // Small wait for stabilization.

  SIM7020begin();

  // Sends AT commands and waits for "OK" responses to verify communication and module status.
  SIM7020command("AT", "OK", "yy", 3000, 2);  // Basic AT command to verify connection.
  delay(500);

  SIM7020command("AT+CSQ", "OK", "yy", 3000, 2);  // Checks signal quality.
  delay(500);

  SIM7020command("AT+CFUN=0", "OK", "yy", 5000, 2);  // Turn off module radio
  delay(1000);

  SIM7020command("AT*MCGDEFCONT=\"IP\",\"" APN_NBIOT "\"", "OK", "yy", 3000, 1);  // Set Default PSD Connection Settings
  delay(1000);

  SIM7020command("AT+CFUN=1", "OK", "yy", 5000, 2);  // Turn on module radio
  delay(3000);
  SIM7020command("AT+CGATT?", "OK", "yy", 5000, 2);  // Checks GPRS/NB-IoT connection status.
  delay(500);
  SIM7020command("AT+CGCONTRDP=?", "OK", "yy", 5000, 2);
  delay(500);

  DEBUG_INFO("NB-IoT module initialized.");
}

void nbiot_enviar(void) {
  nbiot_paquete();     // Calls the function to create the JSON payload
  nbiot_transmitir();  // Calls the function to perform the HTTP POST request
}

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

  serializeJsonPretty(doc, json_data);
  DEBUG_INFO("JSON: %s", json_data.c_str());  // Prints the JSON for debugging.

  // Converts the JSON to hexadecimal data
  hexData = jsonToHex(doc);
  DEBUG_VERBOSE("hexData: %s", hexData.c_str());
}

void nbiot_transmitir(void) {
  byte ans = NOTOK;

  ans = SIM7020command("AT+CHTTPCREATE=\"" + String(SERVIDOR_IP) + ":" + String(SERVIDOR_PUERTO) + "\"", "OK", "yy", 3000, 2);
  delay(500);
  DEBUG_INFO("Creating connection (AT+CHTTPCREATE)... %s", respuestas[ans]);

  ans = SIM7020command("AT+CHTTPCON=0", "OK", "yy", 5000, 2);
  if (ans != OK) {
    DEBUG_ERROR("Connecting to server (AT+CHTTPCON)... %s", respuestas[ans]);
    delay(5000);
    ReiniciarDispositivo();
  }
  DEBUG_INFO("Connecting to server (AT+CHTTPCON)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPSEND=0,1,\"" SERVIDOR_API "\",,\"application/json\"," + hexData, "OK", "yy", 5000, 2);
  if (ans != OK) {
    DEBUG_ERROR("Sending data (AT+CHTTPSEND)... %s", respuestas[ans]);
    delay(5000);
    ReiniciarDispositivo();
  }
  DEBUG_INFO("Sending data (AT+CHTTPSEND)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPDISCON=0", "OK", "yy", 5000, 2);
  DEBUG_INFO("Disconnecting (AT+CHTTPDISCON)... %s", respuestas[ans]);
  delay(500);

  ans = SIM7020command("AT+CHTTPDESTROY=0", "OK", "yy", 5000, 2);
  DEBUG_INFO("Destroying connection (AT+CHTTPDESTROY)... %s", respuestas[ans]);
}

bool SIM7020begin(void) {
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
      if (SIM7020command("AT+CMEE=2", "OK", "yy", 5000, 2) == OK) return OK;  // Enables extended error reports.
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

byte SIM7020command(String command, String response1, String response2, unsigned long timeout, uint16_t repetitions) {
  byte returnValue = RST;
  uint16_t count = 0;
  DEBUG_INFO("Command sent: %s", command.c_str());
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

byte SIM7020waitFor(String response1, String response2, unsigned long timeout) {
  unsigned long millis0 = millis();
  String reply;
  byte retVal = RST;
  do {
    reply = SIM7020board.readString();  //SIM7020read();
    if (reply != "") {
      reply.replace('\n', ' ');
      DEBUG_VERBOSE("Ans: %s in %lu ms", reply.c_str(), (millis() - millis0));
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

String jsonToHex(const JsonDocument& doc) {
  String hexString = "";
  serializeJson(doc, json_data);

  // Iterates over each character of the JSON string
  for (uint8_t i = 0; i < json_data.length(); i++) {
    hexString += String(json_data[i], HEX);
  }

  return hexString;  // Returns the hexadecimal string
}

#endif  // HABILITAR_NBIOT
```


