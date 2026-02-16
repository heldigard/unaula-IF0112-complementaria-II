/*
 * SESIÓN 8 - IF0112: IoT UNAULA 2026-I
 * Programa: Enviar datos de sensores al servidor vía HTTP POST
 * Objetivo: Integrar ESP32 con backend REST API
 * 
 * INSTALACION DE LIBRERIAS:
 * - ArduinoJson by Benoit Blanchon (v6.x)
 * 
 * CONFIGURACION NECESARIA:
 * 1. Cambiar ssid y password del WiFi
 * 2. Cambiar serverUrl con la IP del servidor docente
 * 3. Cambiar dispositivoId con tu identificador
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "DHT.h"

// ==================== CONFIGURACION ====================
// WiFi
const char* ssid = "NOMBRE_DE_TU_RED";
const char* password = "TU_CLAVE_WIFI";

// Servidor
// Reemplaza con la IP que te de el profesor
const char* serverUrl = "http://192.168.137.1:5000/api/v1/datos";

// Identificador único de tu dispositivo
// Usa: esp32_XX donde XX es tu número de estudiante
const char* dispositivoId = "esp32_01";
// ======================================================

// Sensores
#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34

DHT dht(DHTPIN, DHTTYPE);

// Intervalo de envío (30 segundos)
const unsigned long SEND_INTERVAL = 30000;
unsigned long lastSendTime = 0;

// LED indicador de envío
#define LED_PIN 2

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 8: HTTP Client");
  Serial.println("================================");
  Serial.println("");
  
  // Conectar WiFi
  conectarWiFi();
  
  Serial.println("Sistema iniciado!");
  Serial.print("Enviando a: ");
  Serial.println(serverUrl);
  Serial.println("================================");
}

void conectarWiFi() {
  Serial.print("Conectando a WiFi");
  WiFi.begin(ssid, password);
  
  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 30) {
    delay(500);
    Serial.print(".");
    intentos++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("✓ WiFi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("");
    Serial.println("✗ Error de conexion WiFi");
  }
}

void enviarDatos(float temp, float hum, int luz) {
  // Verificar conexión WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("⚠ No hay WiFi, no se pueden enviar datos");
    return;
  }
  
  // Crear documento JSON
  StaticJsonDocument<256> doc;
  doc["dispositivo_id"] = dispositivoId;
  doc["temperatura"] = temp;
  doc["humedad"] = hum;
  doc["luz"] = luz;
  
  // Serializar JSON a String
  String jsonString;
  serializeJson(doc, jsonString);
  
  // Indicador visual de envío
  digitalWrite(LED_PIN, HIGH);
  
  // Enviar HTTP POST
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
  
  Serial.print("Enviando datos... ");
  int httpResponseCode = http.POST(jsonString);
  
  if (httpResponseCode > 0) {
    Serial.print("✓ OK! Codigo: ");
    Serial.println(httpResponseCode);
    
    // Leer respuesta del servidor
    String response = http.getString();
    Serial.print("Respuesta: ");
    Serial.println(response);
  } else {
    Serial.print("✗ Error: ");
    Serial.println(httpResponseCode);
  }
  
  http.end();
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  unsigned long ahora = millis();
  
  // Verificar si es hora de enviar datos
  if (ahora - lastSendTime >= SEND_INTERVAL) {
    
    // Leer sensores
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();
    int luz = analogRead(LDR_PIN);
    
    // Validar lecturas
    if (isnan(temperatura) || isnan(humedad)) {
      Serial.println("Error leyendo DHT!");
      lastSendTime = ahora;
      return;
    }
    
    // Mostrar datos locales
    Serial.println("┌──────────────────────────────┐");
    Serial.print("│ Temp: ");
    Serial.print(temperatura);
    Serial.println(" C              │");
    Serial.print("│ Hum:  ");
    Serial.print(humedad);
    Serial.println(" %              │");
    Serial.print("│ Luz:  ");
    Serial.print(luz);
    Serial.println("               │");
    Serial.println("└──────────────────────────────┘");
    
    // Enviar al servidor
    enviarDatos(temperatura, humedad, luz);
    
    Serial.println("Esperando 30 segundos...");
    Serial.println("");
    
    lastSendTime = ahora;
  }
  
  // Pequeña espera para no saturar el CPU
  delay(100);
}
