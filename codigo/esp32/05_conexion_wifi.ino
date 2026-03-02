/*
 * SESIÓN 7 - IF0112: IoT UNAULA 2026-I
 * Programa: Conexión WiFi del ESP32
 * Objetivo: Conectar el ESP32 a una red WiFi
 * 
 * IMPORTANTE: Cambia ssid y password con los datos de tu red
 */

#include <WiFi.h>
#include "DHT.h"

// ==================== CONFIGURACIÓN WiFi ====================
// ⚠️ CAMBIA ESTOS VALORES con tu red WiFi
const char* ssid = "NOMBRE_DE_TU_RED";
const char* password = "TU_CLAVE_WIFI";
// =============================================================

// Pines de sensores
#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34

DHT dht(DHTPIN, DHTTYPE);

// Variables para reconexión
unsigned long lastReconnectAttempt = 0;
const unsigned long RECONNECT_INTERVAL = 10000; // 10 segundos

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 7: Conexion WiFi");
  Serial.println("================================");
  Serial.println("");
  
  // Iniciar conexión WiFi
  conectarWiFi();
  
  Serial.println("");
  Serial.println("Sistema listo! Enviando datos...");
  Serial.println("================================");
}

void conectarWiFi() {
  Serial.print("Conectando a WiFi: ");
  Serial.println(ssid);
  
  // Iniciar conexión
  WiFi.begin(ssid, password);
  
  // Esperar conexión con timeout
  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 20) {
    delay(500);
    Serial.print(".");
    intentos++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("✓ WiFi CONECTADO!");
    Serial.print("  IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("  Mascara: ");
    Serial.println(WiFi.subnetMask());
    Serial.print("  Gateway: ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("  RSSI: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
  } else {
    Serial.println("");
    Serial.println("✗ No se pudo conectar a WiFi");
    Serial.println("Verifica las credenciales");
  }
}

void verificarWiFi() {
  // Verificar si está conectado
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("⚠ WiFi desconectado!");
    
    // Intentar reconexión cada RECONNECT_INTERVAL
    unsigned long ahora = millis();
    if (ahora - lastReconnectAttempt > RECONNECT_INTERVAL) {
      Serial.println("Intentando reconectar...");
      WiFi.reconnect();
      lastReconnectAttempt = ahora;
    }
  }
}

void loop() {
  // Verificar conexión WiFi
  verificarWiFi();
  
  // Leer sensores
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  int luz = analogRead(LDR_PIN);
  
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error leyendo sensores!");
    delay(2000);
    return;
  }
  
  // Mostrar datos y estado WiFi
  Serial.println("┌──────────────────────────────┐");
  Serial.print("│ WiFi: ");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("CONECTADO    │");
  } else {
    Serial.print("DESCONECTADO │");
  }
  Serial.println("");
  
  Serial.print("│ IP: ");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print(WiFi.localIP());
  } else {
    Serial.print("---.---.---.---");
  }
  Serial.println(" │");
  
  Serial.print("│ Temp: ");
  Serial.print(temperatura);
  Serial.println(" C            │");
  
  Serial.print("│ Hum:  ");
  Serial.print(humedad);
  Serial.println(" %            │");
  Serial.println("└──────────────────────────────┘");
  Serial.println("");
  
  delay(5000);
}
