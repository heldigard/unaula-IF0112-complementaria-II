---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  section { font-size: 20px; overflow: hidden; }
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
  section h1 { font-size: 1.8em; }
  section h2 { font-size: 1.4em; }
  section h3 { font-size: 1.2em; }
  section ul, section ol { font-size: 0.9em; margin-left: 1em; }
  section li { margin-bottom: 0.3em; }
  section pre { font-size: 0.7em; max-height: 60vh; overflow-y: auto; }
  section code { font-size: 0.85em; }
  section table { width: 100%; font-size: 0.85em; border-collapse: collapse; margin: 0.5em auto; }
  section th { background-color: #1e40af; color: white; padding: 0.4em 0.6em; border: 1px solid #ddd; }
  section td { padding: 0.4em 0.6em; border: 1px solid #ddd; }
  section tbody tr:nth-child(even) { background-color: #f8f9fa; }
---

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 40px; align-items: center;">
<div>

# Clase 8: Protocolos IoT
### MQTT, HTTP y Comunicación en la Nube

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| 📡 | Diferencias entre HTTP y MQTT |
| 🔄 | Modelo publish/subscribe de MQTT |
| 🔐 | QoS y seguridad en protocolos IoT |
| ⚙️ | Implementar MQTT en ESP32 |

> **Pregunta clave:** ¿Por qué MQTT es el protocolo estándar para IoT?

</div>
</div>

---

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 30px;">
<div>

### 📚 Competencias

| Competencia | Descripción |
|-------------|-------------|
| **Comparar** protocolos HTTP vs MQTT | Ventajas y desventajas |
| **Implementar** MQTT pub/sub | Código en ESP32 |
| **Diseñar** topics jerárquicos | Estructura lógica |
| **Seleccionar** protocolo adecuado | Según caso de uso |

</div>
<div>

### ⏱️ Estructura

| Bloque | Tema | Duración |
|--------|------|----------|
| **Teoría** | Desafíos IoT, HTTP vs MQTT | 60 min |
| **Práctica** | Implementación MQTT ESP32 | 30 min |
| **Evaluación** | Sistema pub/sub completo | --- |

> **Nota:** Traer MQTT Explorer instalado para práctica

</div>
</div>

---

## Desafíos de Comunicación en IoT

<table>
<tr>
<td width="50%">

### 📡 Conectividad

| Problema | Impacto | Solución |
|----------|---------|----------|
| Redes inestables | Pérdida de datos | Protocolos con QoS |
| Ancho de banda limitado | Lentitud | Protocolos ligeros |
| Alta latencia | Respuesta lenta | Push nativo (MQTT) |
| Conexiones intermitentes | Desconexiones frecuentes | Reconexión automática |

### 🔋 Energía

| Desafío | Requerimiento |
|---------|---------------|
| Dispositivos con batería | Mínimo tiempo de transmisión |
| Wake-up frecuentes | Conexiones rápidas |
| Overhead de protocolo | Menor consumo energético |

</td>
<td width="50%">

### 📊 Escala

| Aspecto | Característica IoT |
|---------|-------------------|
| Cantidad de dispositivos | Miles a millones |
| Frecuencia de mensajes | Muy alta |
| Tamaño de mensajes | Pequeños (bytes) |
| Patrón de comunicación | Muchos a muchos |

### 🔒 Seguridad

| Limitación | Implicación |
|------------|-------------|
| Recursos computacionales limitados | Cifrado ligero necesario |
| Memoria reducida | Certificados pequeños |
| CPU lenta | Handshakes optimizados |

</td>
</tr>
</table>

---

## HTTP: El Protocolo de la Web

<table>
<tr>
<td width="50%">

### Modelo Request-Response

<table>
<tr>
<td width="50%">

#### 📤 CLIENTE (ESP32)
| Acción | Detalle |
|--------|---------|
| **Inicia** | Siempre el cliente |
| **Envía** | GET /api/temperatura |
| **Espera** | Respuesta del servidor |
| **Procesa** | JSON con datos |

</td>
<td width="50%">

#### 📥 SERVIDOR (API)
| Acción | Detalle |
|--------|---------|
| **Recibe** | Petición HTTP |
| **Procesa** | Lógica de negocio |
| **Responde** | HTTP 200 OK |
| **Envía** | {"temp": 25.5} |

</td>
</tr>
</table>

**Flujo:** Cliente → Request → Servidor → Response → Cliente

### Características Clave

| Aspecto | Descripción |
|---------|-------------|
| **Iniciador** | Siempre el cliente |
| **Conexión** | Una por petición (HTTP/1.1) |
| **Modelo** | Síncrono (espera respuesta) |
| **Push server** | No (requiere polling) |
| **Overhead** | Alto (~800 bytes headers) |

</td>
<td width="50%">

### ✅ Ventajas HTTP

- Familiar y universalmente soportado
- Debugging fácil (Postman, curl, navegador)
- HTTPS integrado para seguridad
- Compatible con firewalls/proxies
- Infraestructura madura

### ❌ Desventajas para IoT

- Overhead considerable (headers)
- No soporta push del servidor
- Polling consume batería
- Una conexión por petición
- No ideal para tiempo real

### Mejor Uso

- APIs REST tradicionales
- Actualizaciones de firmware
- Peticiones ocasionales
- Comunicación con servicios web existentes

</td>
</tr>
</table>

---

## MQTT: El Protocolo Estrella de IoT

<table>
<tr>
<td width="50%">

### Message Queuing Telemetry Transport

Protocolo diseñado específicamente para IoT por IBM en 1999.

<table>
<tr>
<td width="50%">

#### 🔄 MODELO PUB/SUB

| Componente | Rol | Acción |
|------------|-----|--------|
| **Broker** | Centro de mensajes | Enruta mensajes |
| **Publicador** | Productor de datos | Envía a topics |
| **Suscriptor** | Consumidor de datos | Recibe de topics |

#### 📡 TOPIC Y MENSAJE

| Elemento | Ejemplo |
|----------|---------|
| **Topic** | casa/sala/temperatura |
| **Mensaje** | "25.5" |

</td>
<td width="50%">

#### ⚙️ FLUJO DE DATOS

<table>
<tr>
<td style="background: #dbeafe; padding: 12px; text-align: center; font-weight: bold;" colspan="3">FLUJO MQTT PUB/SUB</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 10px; text-align: center;">
<strong>📤 PUBLICADOR</strong><br>
(Sensor)
</td>
<td style="background: #fef3c7; padding: 10px; text-align: center;">
<strong>🔄 BROKER MQTT</strong><br>
(Routing)
</td>
<td style="background: #dcfce7; padding: 10px; text-align: center;">
<strong>📥 SUSCRIPTOR</strong><br>
(App)
</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 10px; text-align: center;">
publish("casa/sala/temperatura", "25.5")<br>
↓
</td>
<td style="background: #fef3c7; padding: 10px; text-align: center;">
┌─────────┐<br>
│ BROKER  │<br>
│  MQTT   │<br>
└─────────┘<br>
↓ Enruta mensaje
</td>
<td style="background: #dcfce7; padding: 10px; text-align: center;">
subscribe("casa/sala/temperatura")<br>
↓<br>
Recibe mensaje
</td>
</tr>
</table>

<div style="background: #fef3c7; padding: 10px; border-radius: 6px; margin-top: 10px; text-align: center;">
<strong>Desacoplamiento:</strong> Publicador y suscriptor no se conocen directamente
</div>

</td>
</tr>
</table>

</td>
<td width="50%">

### Características Clave

| Aspecto | Descripción |
|---------|-------------|
| **Modelo** | Publish/Subscribe |
| **Iniciador** | Ambos (bidireccional) |
| **Conexión** | Persistente (TCP) |
| **Push server** | Sí (nativo) |
| **Overhead** | Muy bajo (~2 bytes) |
| **QoS** | 3 niveles de entrega |

### ¿Por qué MQTT para IoT?

- ✅ Overhead mínimo (ahorro energía)
- ✅ Push nativo (tiempo real)
- ✅ Desacoplamiento (pub/sub)
- ✅ Escalable (millones de dispositivos)
- ✅ QoS garantizado
- ✅ Retained messages
- ✅ Last Will and Testament

</td>
</tr>
</table>

---

## Conceptos Fundamentales de MQTT

<table>
<tr>
<td width="50%">

### Topics (Temas)

Estructura jerárquica usando `/` como separador:

```
casa/sala/temperatura
casa/sala/humedad
casa/sala/luz/estado
casa/cocina/temperatura
casa/cocina/luz
casa/dormitorio/temperatura

oficina/piso1/sala1/temperatura
oficina/piso1/sala1/humedad
oficina/piso2/servidor/cpu

edificio/sectorA/piso3/oficina12/aire
```

### Wildcards (Comodines)

| Símbolo | Significado | Ejemplo |
|---------|-------------|---------|
| `+` | Un nivel | `casa/+/temperatura` |
| `#` | Múltiples niveles | `casa/#` |

**Ejemplo `+`:**
- `casa/+/temperatura` captura:
  - `casa/sala/temperatura`
  - `casa/cocina/temperatura`
  - `casa/dormitorio/temperatura`

</td>
<td width="50%">

### Mensajes y Propiedades

| Propiedad | Descripción |
|-----------|-------------|
| **Payload** | Contenido del mensaje (string, JSON, binario) |
| **Retain** | Último mensaje guardado para nuevos suscriptores |
| **QoS** | Quality of Service (calidad de entrega) |
| **Client ID** | Identificador único del cliente |
| **Keep Alive** | Intervalo de ping para mantener conexión |

### Last Will and Testament (LWT)

Mensaje que se publica automáticamente si el cliente se desconecta inesperadamente.

```
Uso: Notificar cuando un sensor deja de responder

Ejemplo:
  • Cliente se conecta con LWT configurado
  • Topic: "casa/sala/sensor/status"
  • Mensaje LWT: "offline"
  • Si el sensor pierde conexión → 
    Broker publica "offline" automáticamente
```

</td>
</tr>
</table>

---

## Niveles de QoS (Quality of Service)

### QoS 0: At Most Once (Fire and Forget)

| Característica | Valor |
|----------------|-------|
| Confirmación | ❌ Sin ACK |
| Pérdida | ⚠️ Puede perderse |
| Velocidad | Más rápido |
| Uso | Datos frecuentes, temperatura en tiempo real |

### QoS 1: At Least Once (Entrega garantizada)

| Característica | Valor |
|----------------|-------|
| Confirmación | ✅ ACK (PUBACK) |
| Duplicados | ⚠️ Posibles |
| Balance | Confiabilidad/overhead |
| Uso | Comandos importantes, alarmas |

### QoS 2: Exactly Once (Entrega exacta)

| Característica | Valor |
|----------------|-------|
| Handshake | 4-way completo |
| Duplicados | ❌ Sin duplicados |
| Overhead | Mayor |
| Uso | Transacciones críticas, pagos |

---

## HTTP vs MQTT: Comparación Detallada

<table>
<tr>
<td width="50%">

### Tabla Comparativa

| Aspecto | HTTP | MQTT |
|---------|------|------|
| **Modelo** | Request-Response | Publish-Subscribe |
| **Iniciador** | Cliente | Bidireccional |
| **Overhead** | Alto (~800 bytes) | Bajo (~2 bytes) |
| **Conexión** | Por petición | Persistente |
| **Push server** | No (polling) | Sí (nativo) |
| **QoS** | No | 3 niveles |
| **Tiempo real** | Difícil | Fácil |
| **Escalabilidad** | Media | Alta |
| **Batería** | Alto consumo | Bajo consumo |
| **Complejidad** | Menor | Mayor (broker) |
| **Seguridad** | HTTPS/TLS | TLS/SSL + auth |
| **Firewall** | Fácil (puerto 80/443) | Configurable (1883/8883) |

</td>
<td width="50%">

### Cuándo Usar Cada Uno

**Usar HTTP cuando:**
- ✅ Integración con APIs web existentes
- ✅ Comunicación ocasional
- ✅ Actualizaciones de firmware (OTA)
- ✅ Clientes necesitan request/response
- ✅ Infraestructura HTTP ya existe

**Usar MQTT cuando:**
- ✅ Muchos dispositivos (escala)
- ✅ Comunicación tiempo real
- ✅ Push desde servidor necesario
- ✅ Dispositivos con batería
- ✅ Alta frecuencia de mensajes
- ✅ Arquitectura pub/sub apropiada

### Ejemplo de Decisión

| Escenario | Protocolo | Razón |
|-----------|-----------|-------|
| Sensor de temperatura cada 5s | MQTT | Eficiencia, push |
| App consulta datos históricos | HTTP | Request/response |
| Control de luces en tiempo real | MQTT | Push rápido |
| Actualización firmware | HTTP | Archivos grandes |

</td>
</tr>
</table>

---

## Brokers MQTT: Opciones Disponibles

<table>
<tr>
<td width="50%">

### Gratuitos / Open Source

| Broker | Características | Uso |
|--------|-----------------|-----|
| **Mosquitto** | Ligero, muy popular | Self-hosted, Raspberry Pi |
| **HiveMQ CE** | Java, alta disponibilidad | Empresas, clusters |
| **EMQX** | Escalable, cloud native | Grandes despliegues |
| **RabbitMQ** | Multi-protocolo | Enterprise |

### Servicios Cloud

| Servicio | Plan Gratuito | Características |
|----------|---------------|-----------------|
| **HiveMQ Cloud** | 100 conexiones | Fácil setup, TLS gratis |
| **CloudMQTT** | 5 conexiones | SSL incluido |
| **AWS IoT Core** | 12 meses free | Integración AWS |
| **Azure IoT Hub** | 8000 msg/día | Microsoft ecosystem |
| **Adafruit IO** | 10 feeds | Maker-friendly |

</td>
<td width="50%">

### Broker Público para Pruebas

```
🌐 broker.hivemq.com

• Puerto: 1883 (sin TLS)
• Puerto: 8883 (con TLS)
• WebSocket: 8000

⚠️ Solo para pruebas/educación
❌ No usar en producción
❌ Sin garantía de privacidad
```

### Instalación Local (Mosquitto)

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install mosquitto mosquitto-clients
sudo systemctl start mosquitto
```

**Verificar instalación:**
```bash
# Suscriptor
mosquitto_sub -h localhost -t "test/topic"

# Publicador (en otra terminal)
mosquitto_pub -h localhost -t "test/topic" -m "Hola"
```

</td>
</tr>
</table>

---

## Implementación MQTT en ESP32

### Librería PubSubClient

Arduino IDE → Sketch → Include Library → Manage Libraries → Buscar "PubSubClient"

### Código: Publicador MQTT

```cpp
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "TU_RED";
const char* password = "TU_PASS";
const char* mqtt_server = "broker.hivemq.com";
const char* topic_temp = "unaula/sala/temperatura";

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

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publicar cada 5s
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 5000) {
    lastMsg = millis();
    float temp = 25.5;
    char msg[50];
    snprintf(msg, 50, "%.1f", temp);
    client.publish(topic_temp, msg);
  }
}
```

---

## Suscriptor MQTT con Callback

### Función Callback

Se ejecuta cuando llega un mensaje a un topic suscrito.

```cpp
void callback(char* topic, byte* payload, unsigned int length) {
  String mensaje = "";
  for (int i = 0; i < length; i++) {
    mensaje += (char)payload[i];
  }

  if (String(topic) == "unaula/sala/luz") {
    if (mensaje == "ON") {
      digitalWrite(LED_PIN, HIGH);
    } else if (mensaje == "OFF") {
      digitalWrite(LED_PIN, LOW);
    }
  }
}
```

### Setup con Suscripción

```cpp
void setup() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void reconnect() {
  if (client.connect("ESP32-Sub")) {
    client.subscribe("unaula/sala/luz");
  }
}
```

### Estados MQTT

| Código | Significado |
|--------|-------------|
| `-4` | Timeout |
| `0` | Conectado |

---

## JSON en MQTT

### Publicar JSON

```cpp
#include <ArduinoJson.h>

void publicarJSON(float temp, float hum) {
  StaticJsonDocument<256> doc;
  doc["temperatura"] = temp;
  doc["humedad"] = hum;
  doc["timestamp"] = millis();

  char buffer[256];
  serializeJson(doc, buffer);
  client.publish("unaula/sala/datos", buffer);
}
```

**Resultado:**
```json
{"temperatura":24.5,"humedad":60,"timestamp":12345678}
```

### Recibir JSON

```cpp
void callback(char* topic, byte* payload, unsigned int length) {
  StaticJsonDocument<256> doc;
  deserializeJson(doc, payload, length);

  const char* comando = doc["comando"];
  int valor = doc["valor"];

  if (strcmp(comando, "brillo") == 0) {
    ledcWrite(0, valor);
  }
}
```

---

## Seguridad en MQTT

<table>
<tr>
<td width="50%">

### Autenticación con Usuario/Password

```cpp
void reconnect() {
    while (!client.connected()) {
        Serial.print("Conectando...");
        
        // Conectar con credenciales
        if (client.connect(
            "ESP32Client",           // Client ID
            "usuario_mqtt",          // Username
            "password_mqtt"          // Password
        )) {
            Serial.println("conectado");
        } else {
            Serial.print("fallo, rc=");
            Serial.println(client.state());
            delay(5000);
        }
    }
}
```

### TLS/SSL (Puerto 8883)

```cpp
#include <WiFiClientSecure.h>

WiFiClientSecure espClientSecure;
PubSubClient client(espClientSecure);

// Certificado CA del broker (ejemplo)
const char* ca_cert = R"(
-----BEGIN CERTIFICATE-----
MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZH...
-----END CERTIFICATE-----
)";

void setup() {
    // Configurar certificado
    espClientSecure.setCACert(ca_cert);
    
    // Conectar a puerto seguro
    client.setServer(mqtt_server, 8883);
}
```

</td>
<td width="50%">

### Mejores Prácticas de Seguridad

| Aspecto | Recomendación |
|---------|---------------|
| **TLS/SSL** | Siempre usar puerto 8883 en producción |
| **Autenticación** | Usar usuario/password fuertes |
| **Client ID** | Único por dispositivo |
| **Topics** | Evitar wildcards excesivas |
| **ACLs** | Restringir pub/sub por cliente |
| **Credenciales** | No hardcodear, usar almacenamiento seguro |

### Estructura de Topics Segura

```
❌ INSEGURO:
  empresa/sensor1/datos
  (cualquiera puede publicar)

✅ SEGURO:
  empresa/dispositivo/ABC123/datos
  (dispositivo ABC123 específico)
  
  empresa/usuario/juan/sala/temperatura
  (usuario juan controla su sala)
```

</td>
</tr>
</table>

---

## CoAP: Protocolo para Dispositivos Restringidos

### CoAP vs HTTP

| Aspecto | HTTP | CoAP |
|---------|------|------|
| Transporte | TCP | UDP |
| Overhead | ~800 bytes | ~10 bytes |
| Formato | Texto | Binario |

### Ventajas CoAP

- ✅ Overhead mínimo (~10 bytes)
- ✅ UDP más ligero
- ✅ Métodos similares a HTTP (GET, POST, PUT, DELETE)
- ✅ Diseñado para IoT restringido

### Limitaciones

- ❌ Menos compatibilidad web
- ❌ UDP no garantiza entrega

### Métodos CoAP

| Método | Uso |
|--------|-----|
| GET | Obtener recurso |
| POST | Crear recurso |
| PUT | Actualizar recurso |

### ¿Cuándo usar CoAP?

- Dispositivo < 100 KB RAM
- Red limitada (6LoWPAN, ZigBee)
- Overhead mínimo crítico

---

```cpp
// Librería: coap-simple-library
#include <coap-simple.h>

Coap coap;

void callback(CoapPacket &packet, IPAddress ip, int port) {
    char payload[packet.payloadlen + 1];
    memcpy(payload, packet.payload, packet.payloadlen);
    payload[packet.payloadlen] = '\0';
    
    Serial.println("CoAP recibido: ");
    Serial.println(payload);
}

void setup() {
    coap.start();
    coap.server(callback, "temperatura");
}
```

</td>
</tr>
</table>

---

## Comparación de Protocolos IoT

### Tabla Comparativa

| Protocolo | Transporte | Overhead | Latencia | Uso |
|-----------|------------|----------|----------|-----|
| **HTTP** | TCP | Alto | 100-500ms | APIs web |
| **MQTT** | TCP | Bajo | 10-50ms | IoT general |
| **CoAP** | UDP | Muy bajo | 5-30ms | Dispositivos restringidos |
| **WebSocket** | TCP | Medio | 5-20ms | Dashboard real-time |
| **AMQP** | TCP | Alto | 10-100ms | Enterprise |

### Recomendaciones

| Escenario | Protocolo |
|-----------|-----------|
| Sensor temperatura | MQTT |
| Dashboard real-time | WebSocket/MQTT |
| Sensor 50KB RAM | CoAP |
| API REST | HTTP |

---
</table>

---

## Actividad Práctica: Sistema Pub/Sub con MQTT

<table>
<tr>
<td width="50%">

### Objetivo

Crear un sistema completo con múltiples ESP32 comunicándose vía MQTT.

### Configuración

| Rol | ESP32 | Función |
|-----|-------|---------|
| **Grupo A** | ESP32 #1 | Publicador de temperatura |
| **Grupo B** | ESP32 #2 | Publicador de humedad |
| **Grupo C** | ESP32 #3 | Suscriptor + LED indicador |

### Topics a Usar

```
aula/iot/grupo1/temperatura
aula/iot/grupo1/humedad
aula/iot/grupo1/led/comando
aula/iot/+/estado
```

### Broker

```
broker.hivemq.com (público para pruebas)
```

</td>
<td width="50%">

### Tareas por Grupo

**Grupo A (Temperatura):**
- Leer DHT11 cada 5 segundos
- Publicar en `aula/iot/grupoX/temperatura`
- QoS 1

**Grupo B (Humedad):**
- Leer DHT11 cada 5 segundos
- Publicar en `aula/iot/grupoX/humedad`
- Incluir JSON con timestamp

**Grupo C (Control):**
- Suscribirse a `aula/iot/+/temperatura`
- Suscribirse a `aula/iot/+/humedad`
- Encender LED si temp > 30°C
- Publicar estado en `aula/iot/grupoX/estado`

### Pruebas con MQTT.fx

1. Abrir MQTT.fx
2. Conectar a broker.hivemq.com
3. Suscribirse a `aula/iot/#`
4. Ver mensajes en tiempo real

</td>
</tr>
</table>

---

## Resumen de la Clase

<table>
<tr>
<td width="50%">

### Conceptos Fundamentales

| Concepto | Descripción |
|----------|-------------|
| **HTTP** | Protocolo web request-response, alto overhead |
| **MQTT** | Protocolo IoT pub/sub, ligero, tiempo real |
| **Broker** | Servidor que enruta mensajes MQTT |
| **Topic** | Canal de comunicación jerárquico |
| **Publish** | Enviar mensaje a un topic |
| **Subscribe** | Recibir mensajes de un topic |
| **QoS 0** | At most once (mejor esfuerzo) |
| **QoS 1** | At least once (confirmado) |
| **QoS 2** | Exactly once (transaccional) |
| **Retain** | Guardar último mensaje para nuevos suscriptores |
| **LWT** | Last Will and Testament |

</td>
<td width="50%">

### Funciones Clave (PubSubClient)

| Función | Descripción |
|---------|-------------|
| `setServer(host, port)` | Configurar broker |
| `setCallback(fn)` | Configurar función de recepción |
| `connect(clientID)` | Conectar al broker |
| `connect(ID, user, pass)` | Conectar con auth |
| `publish(topic, msg)` | Publicar mensaje |
| `subscribe(topic)` | Suscribirse a topic |
| `loop()` | Mantener conexión |
| `connected()` | Verificar estado |
| `state()` | Código de error |

### Decisiones de Protocolo

- ✅ **MQTT:** IoT con push, escala, batería
- ✅ **HTTP:** APIs REST, OTA, compatibilidad
- ✅ **CoAP:** Dispositivos muy limitados
- ✅ **WebSocket:** Dashboards tiempo real

</td>
</tr>
</table>

---

## Próxima Clase

### Clase 9: Convergencia IT/OT

**Temas a cubrir:**
- 🖥️ Edge Computing vs Cloud Computing
- 🏭 Tecnologías Operacionales (OT)
- 🔗 Integración IT/OT
- ⚡ Arquitecturas híbridas

### Preparación para Examen E3 (20%)

**Semana 10: Examen Parcial**

Temas a evaluar:
- Dispositivos IoT y hardware
- Redes y conectividad
- Protocolos de comunicación
- Arquitecturas IoT

---

**¡Nos vemos!**

📧 Contacto: [profesor@unaula.edu.co]
💻 Repositorio: GitHub del curso
💬 Discord/Teams: Canal del curso
