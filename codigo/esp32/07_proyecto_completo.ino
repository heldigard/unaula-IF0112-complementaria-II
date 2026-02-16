/*
 * SESIÓN 14 (E6) - IF0112: IoT UNAULA 2026-I
 * Proyecto: Monitor Ambiental IoT Completo
 * 
 * Caracteristicas:
 * - Lee DHT22 (temperatura/humedad)
 * - Lee LDR (luz)
 * - Conexion WiFi con reconexion automatica
 * - Envio HTTP POST cada 30 segundos
 * - LED indicador de estado
 * - Validacion de datos
 * 
 * Autor: [Tu nombre]
 * Fecha: Mayo 2026
 */

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "DHT.h"

// ==================== CONFIGURACION ====================
// WiFi - CAMBIA ESTOS DATOS
const char* ssid = "NOMBRE_DE_TU_RED";
const char* password = "TU_CLAVE_WIFI";

// Servidor - IP del profesor
const char* serverUrl = "http://192.168.137.1:5000/api/v1/datos";

// Identificador unico
const char* dispositivoId = "esp32_XX";  // Cambia XX por tu numero
// ======================================================

// Pines de hardware
#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34
#define LED_STATUS 2
#define LED_ALERT 15  // Opcional: LED de alerta

// Objetos
DHT dht(DHTPIN, DHTTYPE);

// Constantes
const unsigned long SEND_INTERVAL = 30000;      // 30 segundos
const unsigned long RECONNECT_INTERVAL = 10000; // 10 segundos
const float TEMP_MAX = 50.0;   // Temperatura máxima válida
const float TEMP_MIN = -10.0;  // Temperatura mínima válida

// Variables globales
unsigned long lastSendTime = 0;
unsigned long lastReconnectAttempt = 0;
int enviosExitosos = 0;
int enviosFallidos = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();
  
  // Configurar pines
  pinMode(LED_STATUS, OUTPUT);
  pinMode(LED_ALERT, OUTPUT);
  
  // Configurar ADC
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  
  // Secuencia de inicio
  secuenciaInicio();
  
  // Conectar WiFi
  conectarWiFi();
  
  // Registrar dispositivo en el servidor
  registrarDispositivo();
  
  Serial.println("================================");
  Serial.println("  SISTEMA LISTO PARA SUSTENTACIÓN");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("================================");
}

void secuenciaInicio() {
  Serial.println("");
  Serial.println("╔════════════════════════════════════╗");
  Serial.println("║     UNAULA - IF0112 - IoT          ║");
  Serial.println("║   Sesión 14: Monitor Ambiental     ║");
  Serial.println("╚════════════════════════════════════╝");
  Serial.println("");
  
  // Parpadear LED 3 veces al inicio
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_STATUS, HIGH);
    delay(200);
    digitalWrite(LED_STATUS, LOW);
    delay(200);
  }
}

void conectarWiFi() {
  Serial.print("→ Conectando a WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 30) {
    delay(500);
    Serial.print(".");
    intentos++;
    
    // Parpadear LED rápido mientras conecta
    digitalWrite(LED_STATUS, !digitalRead(LED_STATUS));
  }
  
  Serial.println("");
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("✓ WiFi conectado!");
    Serial.print("  IP: ");
    Serial.println(WiFi.localIP());
    Serial.print("  Senal: ");
    Serial.print(WiFi.RSSI());
    Serial.println(" dBm");
    digitalWrite(LED_STATUS, HIGH);
  } else {
    Serial.println("✗ No se pudo conectar a WiFi");
    Serial.println("  Continuando en modo offline...");
    digitalWrite(LED_STATUS, LOW);
  }
  Serial.println("");
}

void verificarWiFi() {
  if (WiFi.status() != WL_CONNECTED) {
    unsigned long ahora = millis();
    if (ahora - lastReconnectAttempt > RECONNECT_INTERVAL) {
      Serial.println("⚠ WiFi desconectado. Reconectando...");
      WiFi.reconnect();
      lastReconnectAttempt = ahora;
    }
  } else {
    digitalWrite(LED_STATUS, HIGH);
  }
}

void registrarDispositivo() {
  if (WiFi.status() != WL_CONNECTED) return;
  
  Serial.println("→ Registrando dispositivo...");
  
  HTTPClient http;
  String url = String(serverUrl);
  url.replace("/datos", "/dispositivos");
  
  http.begin(url);
  http.addHeader("Content-Type", "application/json");
  
  StaticJsonDocument<256> doc;
  doc["id"] = dispositivoId;
  doc["nombre"] = "ESP32 " + String(dispositivoId);
  doc["estudiante"] = "Estudiante UNAULA";
  doc["ubicacion"] = "Laboratorio UNAULA";
  
  String jsonString;
  serializeJson(doc, jsonString);
  
  int httpCode = http.POST(jsonString);
  if (httpCode == 201 || httpCode == 200) {
    Serial.println("✓ Dispositivo registrado");
  } else {
    Serial.println("⚠ El dispositivo ya existe o error de registro");
  }
  
  http.end();
  Serial.println("");
}

bool validarDatos(float temp, float hum) {
  // Validar que no sean NaN
  if (isnan(temp) || isnan(hum)) {
    Serial.println("✗ Error: Datos NaN del sensor");
    return false;
  }
  
  // Validar rangos razonables
  if (temp < TEMP_MIN || temp > TEMP_MAX) {
    Serial.print("✗ Error: Temperatura fuera de rango: ");
    Serial.println(temp);
    return false;
  }
  
  if (hum < 0 || hum > 100) {
    Serial.print("✗ Error: Humedad fuera de rango: ");
    Serial.println(hum);
    return false;
  }
  
  return true;
}

void enviarDatos(float temp, float hum, int luz) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("⚠ Sin WiFi - datos no enviados");
    enviosFallidos++;
    return;
  }
  
  // Crear JSON
  StaticJsonDocument<256> doc;
  doc["dispositivo_id"] = dispositivoId;
  doc["temperatura"] = round(temp * 100) / 100;  // Redondear a 2 decimales
  doc["humedad"] = round(hum * 100) / 100;
  doc["luz"] = luz;
  
  String jsonString;
  serializeJson(doc, jsonString);
  
  // Enviar HTTP POST
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");
  http.setTimeout(10000);  // 10 segundos timeout
  
  Serial.print("→ Enviando datos... ");
  int httpCode = http.POST(jsonString);
  
  if (httpCode == 201) {
    Serial.println("✓ Enviado!");
    enviosExitosos++;
    
    // Parpadear LED rápido indicando éxito
    digitalWrite(LED_STATUS, LOW);
    delay(100);
    digitalWrite(LED_STATUS, HIGH);
  } else {
    Serial.print("✗ Error HTTP: ");
    Serial.println(httpCode);
    enviosFallidos++;
    
    // LED de alerta
    digitalWrite(LED_ALERT, HIGH);
    delay(500);
    digitalWrite(LED_ALERT, LOW);
  }
  
  http.end();
}

void mostrarEstadisticas(float temp, float hum, int luz) {
  Serial.println("┌──────────────────────────────────┐");
  Serial.println("│      ESTADISTICAS DEL SISTEMA    │");
  Serial.println("├──────────────────────────────────┤");
  
  // WiFi
  Serial.print("│ WiFi: ");
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("ONLINE   ");
  } else {
    Serial.print("OFFLINE  ");
  }
  
  // IP
  Serial.print("IP: ");
  if (WiFi.status() == WL_CONNECTED) {
    String ip = WiFi.localIP().toString();
    Serial.print(ip.substring(ip.lastIndexOf('.') + 1));
  } else {
    Serial.print("---");
  }
  Serial.println("      │");
  
  // Sensores
  Serial.print("│ Temp: ");
  Serial.print(temp, 1);
  Serial.print("°C  Hum: ");
  Serial.print(hum, 1);
  Serial.println("%    │");
  
  Serial.print("│ Luz: ");
  Serial.print(luz);
  Serial.print("     ID: ");
  Serial.print(dispositivoId);
  Serial.println(" │");
  
  // Estadísticas de envío
  Serial.println("├──────────────────────────────────┤");
  Serial.print("│ Envios OK: ");
  Serial.print(enviosExitosos);
  Serial.print("  Fallos: ");
  Serial.print(enviosFallidos);
  Serial.println("    │");
  Serial.println("└──────────────────────────────────┘");
}

void loop() {
  // Verificar conexión WiFi
  verificarWiFi();
  
  unsigned long ahora = millis();
  
  // Enviar datos periódicamente
  if (ahora - lastSendTime >= SEND_INTERVAL) {
    
    // Leer sensores
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();
    int luz = analogRead(LDR_PIN);
    
    // Mostrar estadísticas
    mostrarEstadisticas(temperatura, humedad, luz);
    
    // Validar y enviar
    if (validarDatos(temperatura, humedad)) {
      enviarDatos(temperatura, humedad, luz);
    }
    
    Serial.print("Proximo envio en ");
    Serial.print(SEND_INTERVAL / 1000);
    Serial.println(" segundos...");
    Serial.println("");
    
    lastSendTime = ahora;
  }
  
  delay(100);
}
