/*
  ESP32 → HTTP POST a API FastAPI local
  UNAULA - IF0112 Complementaria II

  Hardware:
    - ESP32 DevKit
    - DHT22 en GPIO 4
    - LDR en GPIO 34 (ADC)

  Librerias necesarias:
    - WiFi (incluida en ESP32 core)
    - HTTPClient (incluida)
    - ArduinoJson by Benoit Blanchon
    - DHT sensor library by Adafruit

  Ajustar:
    - ssid / password
    - api_host (IP de tu PC Windows)
    - intervalo_ms
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>

// -------------------- CONFIGURACION --------------------
const char* ssid     = "TU_SSID";
const char* password = "TU_PASSWORD";

// IP de tu PC Windows donde corre FastAPI (puerto 8000)
const char* api_host = "192.168.1.XX";
const int   api_port = 8000;

const unsigned long intervalo_ms = 5000;  // Enviar cada 5 segundos

#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// -------------------- VARIABLES GLOBALES --------------------
unsigned long ultimo_envio = 0;

// -------------------- SETUP --------------------
void setup() {
  Serial.begin(115200);
  delay(1000);

  dht.begin();
  analogReadResolution(12);  // 0-4095

  Serial.println("Conectando a WiFi...");
  WiFi.begin(ssid, password);

  int intentos = 0;
  while (WiFi.status() != WL_CONNECTED && intentos < 30) {
    delay(500);
    Serial.print(".");
    intentos++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi conectado");
    Serial.print("IP ESP32: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nERROR: No se pudo conectar a WiFi");
  }
}

// -------------------- LOOP --------------------
void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi desconectado. Reintentando...");
    WiFi.reconnect();
    delay(2000);
    return;
  }

  unsigned long ahora = millis();
  if (ahora - ultimo_envio >= intervalo_ms) {
    ultimo_envio = ahora;

    float temperatura = dht.readTemperature();
    float humedad     = dht.readHumidity();
    int   luz_raw     = analogRead(34);
    float luz         = mapearLuz(luz_raw);

    if (isnan(temperatura) || isnan(humedad)) {
      Serial.println("ERROR: Fallo lectura DHT22");
      return;
    }

    enviarDatos(temperatura, humedad, luz);
  }
}

// -------------------- FUNCIONES AUXILIARES --------------------

// Mapea el valor ADC del LDR a un rango aproximado 0-100%
float mapearLuz(int raw) {
  float porcentaje = (raw / 4095.0) * 100.0;
  return porcentaje;
}

void enviarDatos(float temp, float hum, float luz) {
  StaticJsonDocument<256> doc;
  doc["temperatura"] = temp;
  doc["humedad"]     = hum;
  doc["luz"]         = luz;

  String payload;
  serializeJson(doc, payload);

  String url = "http://";
  url += api_host;
  url += ":";
  url += api_port;
  url += "/datos";

  HTTPClient http;
  http.begin(url);
  http.addHeader("Content-Type", "application/json");

  int httpCode = http.POST(payload);

  if (httpCode > 0) {
    String respuesta = http.getString();
    Serial.print("HTTP ");
    Serial.print(httpCode);
    Serial.print(" -> ");
    Serial.println(respuesta);
  } else {
    Serial.print("Error en POST: ");
    Serial.println(http.errorToString(httpCode));
  }

  http.end();
}
