# MQTT para IoT - Guía Completa

**Clase 8: Protocolos IoT | Unidad 2**

## ¿Qué es MQTT?

MQTT (Message Queuing Telemetry Transport) es un protocolo de mensajería ligero, publish/subscribe, diseñado para dispositivos IoT con recursos limitados.

## Características

| Característica | Valor |
|----------------|-------|
| **Arquitectura** | Pub/Sub (desacoplado) |
| **Transporte** | TCP (port 1883), TLS (8883) |
| **Overhead** | Mínimo (2 bytes header) |
| **QoS** | 3 niveles (0, 1, 2) |
| **Tamaño mensaje** | Hasta 256 MB |
| **Uso típico** | Sensores, actuadores, M2M |

## Modelo Pub/Sub

```
                ┌─────────┐
                │  BROKER │
                │ (Server)│
                └────┬────┘
                     │
        ┌────────────┼────────────┐
        │            │            │
    ┌───▼───┐   ┌───▼───┐   ┌───▼───┐
    │ PUB   │   │ SUB   │   │ SUB   │
    │Sensor1│   │App    │   │DB     │
    └───────┘   └───────┘   └───────┘

Sensor1 ──[publish]──> broker/temperatura
                             │
                 App ◄─[subscribe]─┘
                 DB ◄─[subscribe]─┘
```

## MQTT en ESP32 (Arduino)

### Publicar

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

const char* mqtt_server = "broker.hivemq.com";
const char* topic = "sensor/temperatura";

WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32Client")) {
      Serial.println("conectado");
    } else {
      Serial.print("fallo, rc=");
      Serial.println(client.state());
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // Publicar temperatura cada 5 seg
  static unsigned long lastMsg = 0;
  unsigned long now = millis();

  if (now - lastMsg > 5000) {
    lastMsg = now;
    float temp = 25.5; // Leer sensor real
    char msg[50];
    snprintf(msg, 50, "%.2f", temp);
    client.publish(topic, msg);
    Serial.print("Publicado: ");
    Serial.println(msg);
  }
}
```

### Suscribir y Recibir

```cpp
#include <PubSubClient.h>

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("]: ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Procesar payload
  // Ejemplo: Encender LED si payload = "ON"
  if (strcmp((char*)payload, "ON") == 0) {
    digitalWrite(LED_PIN, HIGH);
  }
}

void setup() {
  // ... configuración WiFi

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback); // Registrar callback
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("casa/living/luces"); // Suscribirse
      client.subscribe("casa/alarma/#"); // Wildcard
    }
  }
}
```

## Calidad de Servicio (QoS)

| QoS | Descripción | Uso típico |
|-----|-------------|------------|
| **0** | Fire and forget (sin confirmación) | Telemetría frecuente |
| **1** | Al menos una vez (confirmado) | Mensajes críticos |
| **2** | Exactamente una vez (garantizado) | Transacciones |

```cpp
// Publicar con QoS 1 (retained message)
client.publish("sensor/estado", "online", true); // QoS 1, retained = true

// Suscribirse con QoS 2
client.subscribe("comandos/#", 2); // QoS 2
```

## Tópicos MQTT - Estructura

### Jerarquía de Tópicos

```
casa/                 (raíz)
├── living/           (sala)
│   ├── temperatura
│   ├── humedad
│   └── luces
├── cocina/
│   ├── temperatura
│   └── gases
└── jardin/
    ├── humedad_suelo
    └── riego
```

### Wildcards

```cpp
// Suscribirse a todos los subtemas
client.subscribe("casa/living/#");  // casa/living/temperatura, casa/living/luces/...

// Suscribirse a un nivel específico
client.subscribe("casa/+/temperatura"); // casa/living/temperatura, casa/cocina/temperatura
```

## MQTT Seguro (TLS)

```cpp
#include <WiFiClientSecure.h>

WiFiClientSecure espClient;
PubSubClient client(espClient);

const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 8883; // Puerto TLS

// Certificado CA (opcional para producción)
const char* ca_cert = \
"-----BEGIN CERTIFICATE-----\n" \
"...\n" \
"-----END CERTIFICATE-----\n";

void setup() {
  espClient.setCACert(ca_cert);
  client.setServer(mqtt_server, mqtt_port);
}
```

---

**[← Volver a README](README.md)**
