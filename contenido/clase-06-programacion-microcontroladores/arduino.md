# Framework Arduino - Guía Completa

**Clase 6: Programación de Microcontroladores | Unidad 2**

## Estructura Básica

```cpp
// 1. Importación de librerías
#include <WiFi.h>
#include "DHT.h"

// 2. Definición de constantes
#define LED_PIN 2
#define DHT_PIN 4

// 3. Variables globales
float temperatura;
bool estadoLed = false;

// 4. Creación de objetos
DHT dht(DHT_PIN, DHT22);

// 5. setup() - Se ejecuta UNA vez al inicio
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();

  // Conectar WiFi
  WiFi.begin("SSID", "password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi conectado");
}

// 6. loop() - Se ejecuta continuamente
void loop() {
  temperatura = dht.readTemperature();

  if (temperatura > 30) {
    digitalWrite(LED_PIN, HIGH);
    estadoLed = true;
  } else {
    digitalWrite(LED_PIN, LOW);
    estadoLed = false;
  }

  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.print("°C LED: ");
  Serial.println(estadoLed);

  delay(2000);
}
```

## Funciones Esenciales

### GPIO (Entrada/Salida)

```cpp
// Configurar pin
pinMode(pin, OUTPUT);   // Salida
pinMode(pin, INPUT);    // Entrada
pinMode(pin, INPUT_PULLUP); // Entrada con pull-up

// Escribir
digitalWrite(pin, HIGH); // 3.3V/5V
digitalWrite(pin, LOW);  // 0V/GND

// Leer
int valor = digitalRead(pin); // HIGH o LOW
int valorAnalog = analogRead(pin); // 0-4095 (ESP32)
```

### PWM (Modulación por Ancho de Pulso)

```cpp
// Configurar PWM
ledcSetup(channel, freq, resolution); // canal 0-15, freq Hz, res 1-16 bits
ledcAttachPin(pin, channel);

// Escribir duty cycle (0-255 para 8 bits)
ledcWrite(channel, 128); // 50% duty cycle
```

### Comunicación Serial

```cpp
// Inicializar
Serial.begin(115200);

// Escribir
Serial.print("Hola");
Serial.println(" con salto de línea");
Serial.print("Valor: ");
Serial.println(valor);

// Leer
if (Serial.available() > 0) {
  char dato = Serial.read();
  String linea = Serial.readStringUntil('\n');
}
```

### WiFi (ESP32)

```cpp
#include <WiFi.h>

// Conectar
WiFi.begin("SSID", "password");
while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
}

// Info de conexión
Serial.println(WiFi.localIP());
Serial.println(WiFi.macAddress());

// Modo AP (Access Point)
WiFi.softAP("MiESP32", "password123");
Serial.println(WiFi.softAPIP());
```

### Deep Sleep (Ahorro Energía)

```cpp
// Dormir por 10 segundos
esp_sleep_enable_timer_wakeup(10 * 1000000);
esp_deep_sleep_start();

// Dormir hasta que el pin GPIO 34 se active
esp_sleep_enable_ext0_wakeup(GPIO_NUM_34, LOW);
esp_deep_sleep_start();
```

## Ejemplo Completo: Estación MQTT

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SSID";
const char* password = "PASS";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  client.setServer(mqtt_server, 1883);
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("fallo, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publicar cada 5 segundos
  static unsigned long lastMsg = 0;
  unsigned long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;
    client.publish("sensor/temperatura", "25.5");
  }
}
```

---

**[← Volver a README](README.md)**
