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

# Clase 7: Conectividad WiFi
### ESP32 como Dispositivo Conectado

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| 📡 | Conectar ESP32 a red WiFi existente |
| 🌐 | Crear punto de acceso (AP) con ESP32 |
| 💻 | Desarrollar servidor web básico |
| ☁️ | Enviar datos a servicios en la nube |
| 🔄 | Implementar reconexión automática |

### Protocolos de Comunicación

| Protocolo | Uso en IoT | Característica |
|-----------|------------|-------------|
| **HTTP/HTTPS** | APIs REST, web | Cliente-servidor |
| **MQTT** | IoT, telemetry | Pub/Sub, ligero |
| **WebSocket** | Tiempo real | Bidireccional |

> **Pregunta clave:** ¿Cómo hacer que tu ESP32 hable con el mundo?

</div>
</div>

---

## Objetivos de la Clase

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 30px;">

<div>

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| 📡 **Conectar** | ESP32 a red WiFi existente |
| 🌐 **Crear** | Punto de acceso (AP) con ESP32 |
| 💻 **Desarrollar** | Servidor web básico |
| ☁️ **Enviar** | Datos a servicios en la nube |
| 🔄 **Implementar** | Reconexión automática |

</div>
<div>

### ⏱️ Estructura de la Clase

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Modos WiFi (STA, AP, Dual) | 15 min |
| 2️⃣ | Conexión y servidor web | 25 min |
| 3️⃣ | Cliente HTTP y ThingSpeak | 20 min |
| 4️⃣ | Proyecto integrador | 10 min |
| 5️⃣ | **Evaluación E2** (15%) | 60 min |

**Total:** 2 horas

> **💡 Próxima clase:** Protocolos IoT (MQTT, HTTP REST, WebSocket)

</div>
</div>

---

## Conexión WiFi: Modo Estación (STA)

### Código Básico

```cpp
#include <WiFi.h>

const char* ssid = "NombreDeTuRed";
const char* password = "ContrasenaDeRed";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("✓ Conectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
```

### Estados WiFi

| Estado | Significado |
|--------|-------------|
| `WL_CONNECTED` | Conectado |
| `WL_NO_SSID_AVAIL` | Red no encontrada |
| `WL_CONNECT_FAILED` | Contraseña incorrecta |

### Información de Red

```cpp
WiFi.localIP()      // IP local
WiFi.subnetMask()   // Máscara
WiFi.gatewayIP()    // Gateway
WiFi.RSSI()         // Señal (dBm)
```

---

## Reconexión Automática WiFi

<table>
<tr>
<td width="50%">

### El Problema

Las redes WiFi pueden:
- Perder señal temporalmente
- Reiniciar (apagones, mantenimiento)
- Saturarse y desconectar dispositivos

**Sin reconexión automática:** El ESP32 queda "colgado" sin conexión hasta reiniciarlo manualmente.

### La Solución

Verificar periódicamente el estado de conexión y reconectar si es necesario.

</td>
<td width="50%">

### Código de Reconexión

```cpp
#include <WiFi.h>

const char* ssid = "MiRed";
const char* password = "MiClave";

unsigned long ultimoIntento = 0;
const long INTERVALO_RECONEXION = 30000; // 30s

void setup() {
    Serial.begin(115200);
    conectarWiFi();
}

void loop() {
    // Verificar conexión periódicamente
    if (WiFi.status() != WL_CONNECTED) {
        unsigned long ahora = millis();
        
        if (ahora - ultimoIntento >= INTERVALO_RECONEXION) {
            Serial.println("⚠️ Conexión perdida. Reconectando...");
            conectarWiFi();
            ultimoIntento = ahora;
        }
    }
    
    // Tu código principal aquí
}

void conectarWiFi() {
    WiFi.begin(ssid, password);
    
    int intentos = 0;
    while (WiFi.status() != WL_CONNECTED && intentos < 20) {
        delay(500);
        Serial.print(".");
        intentos++;
    }
    
    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n✓ WiFi conectado!");
    } else {
        Serial.println("\n✗ Fallo de conexión");
    }
}
```

</td>
</tr>
</table>

---

## Crear un Servidor Web en ESP32 (1/2)

### Conceptos Básicos

Un **servidor web** en el ESP32 permite:
- Mostrar páginas HTML desde el microcontrolador
- Recibir comandos mediante URLs
- Exponer una API REST
- Controlar hardware desde el navegador

### Librerías Necesarias

```cpp
#include <WiFi.h>
#include <WebServer.h>  // Servidor web
```

### Configuración del Servidor

```cpp
// Crear servidor en puerto 80 (HTTP)
WebServer server(80);

void setup() {
    // Conectar WiFi...

    // Definir rutas (endpoints)
    server.on("/", handleRoot);
    server.on("/led/on", handleLedOn);
    server.on("/led/off", handleLedOff);

    // Iniciar servidor
    server.begin();
    Serial.println("Servidor iniciado");
}

void loop() {
    // Atender peticiones de clientes
    server.handleClient();
}
```

---

## Crear un Servidor Web en ESP32 (2/2)

### Manejadores de Rutas

```cpp
const int LED_PIN = 2;

// Página principal
void handleRoot() {
    String html = "<html><body>";
    html += "<h1>Control ESP32</h1>";
    html += "<a href='/led/on'>Encender LED</a><br>";
    html += "<a href='/led/off'>Apagar LED</a>";
    html += "</body></html>";

    server.send(200, "text/html", html);
}

// Encender LED
void handleLedOn() {
    digitalWrite(LED_PIN, HIGH);
    server.sendHeader("Location", "/");
    server.send(303);  // Redirect
    Serial.println("LED encendido");
}

// Apagar LED
void handleLedOff() {
    digitalWrite(LED_PIN, LOW);
    server.sendHeader("Location", "/");
    server.send(303);
    Serial.println("LED apagado");
}
```

---

## API REST con JSON

<table>
<tr>
<td width="50%">

### ¿Qué es una API REST?

**API** (Application Programming Interface): Interfaz para que programas se comuniquen.

**REST** (Representational State Transfer): Estilo de arquitectura usando HTTP.

### Métodos HTTP Comunes

| Método | Acción | Ejemplo |
|--------|--------|---------|
| GET | Obtener datos | `/api/sensores` |
| POST | Crear/enviar datos | `/api/datos` |
| PUT | Actualizar datos | `/api/config` |
| DELETE | Eliminar datos | `/api/alarma` |

### Formato JSON

JSON = JavaScript Object Notation

```json
{
  "temperatura": 24.5,
  "humedad": 60.0,
  "timestamp": 123456789
}
```

</td>
<td width="50%">

### Código: API REST en ESP32

```cpp
#include <ArduinoJson.h>  // Librería JSON

void handleSensorData() {
    // Leer sensores reales
    float temperatura = dht.readTemperature();
    float humedad = dht.readHumidity();
    
    // Crear documento JSON
    StaticJsonDocument<200> doc;
    doc["temperatura"] = temperatura;
    doc["humedad"] = humedad;
    doc["timestamp"] = millis();
    doc["dispositivo"] = "ESP32-Sala";
    
    // Serializar a String
    String jsonResponse;
    serializeJson(doc, jsonResponse);
    
    // Enviar respuesta
    server.send(200, "application/json", jsonResponse);
}

// En setup():
// server.on("/api/sensores", handleSensorData);
```

**Respuesta:**
```json
{
  "temperatura": 24.5,
  "humedad": 60,
  "timestamp": 12456789,
  "dispositivo": "ESP32-Sala"
}
```

</td>
</tr>
</table>

---

## Cliente HTTP: Enviar Datos a la Nube

<table>
<tr>
<td width="50%">

### Concepto

El ESP32 puede actuar como **cliente** HTTP para enviar datos a servidores externos.

**Flujo:**
1. Leer sensor
2. Crear JSON con datos
3. Enviar POST a servidor
4. Esperar respuesta
5. Manejar errores

### Librería HTTPClient

```cpp
#include <HTTPClient.h>
```

</td>
<td width="50%">

### Código: Enviar Datos

```cpp
void enviarDatos(float temp, float hum) {
    // Verificar WiFi conectado
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Error: Sin conexión WiFi");
        return;
    }
    
    HTTPClient http;
    
    // Configurar URL del servidor
    http.begin("http://api.ejemplo.com/datos");
    
    // Agregar headers
    http.addHeader("Content-Type", "application/json");
    
    // Crear JSON
    String json = "{";
    json += "\"temperatura\":" + String(temp) + ",";
    json += "\"humedad\":" + String(hum) + ",";
    json += "\"fecha\":\"" + String(millis()) + "\"";
    json += "}";
    
    // Enviar POST
    int httpCode = http.POST(json);
    
    // Verificar respuesta
    if (httpCode > 0) {
        String respuesta = http.getString();
        Serial.println("Datos enviados: " + respuesta);
    } else {
        Serial.println("Error HTTP: " + http.errorToString(httpCode));
    }
    
    // Liberar recursos
    http.end();
}
```

</td>
</tr>
</table>

---

## ThingSpeak: Plataforma IoT Gratuita

<table>
<tr>
<td width="50%">

### ¿Qué es ThingSpeak?

Plataforma de IoT en la nube que permite:
- Almacenar datos de sensores
- Visualizar datos en gráficos
- Analizar datos con MATLAB
- Activar alertas
- API simple basada en HTTP

### Configuración

**Paso 1:** Crear cuenta en [thingspeak.com](https://thingspeak.com)

**Paso 2:** Crear un nuevo "Channel"

**Paso 3:** Configurar campos:
- Field 1: Temperatura
- Field 2: Humedad

**Paso 4:** Obtener **Write API Key**

**Paso 5:** Guardar API Key para usar en código

</td>
<td width="50%">

### Código para ThingSpeak

```cpp
#include <HTTPClient.h>

const char* apiKey = "TU_API_KEY_AQUI";  // Write API Key

void enviarAThingSpeak(float temp, float hum) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Sin WiFi");
        return;
    }
    
    HTTPClient http;
    
    // Construir URL
    String url = "http://api.thingspeak.com/update?api_key=";
    url += apiKey;
    url += "&field1=" + String(temp);   // Temperatura
    url += "&field2=" + String(hum);    // Humedad
    
    Serial.println("Enviando: " + url);
    
    http.begin(url);
    int httpCode = http.GET();
    
    if (httpCode == 200) {
        String respuesta = http.getString();
        Serial.println("✓ Datos enviados. Entry: " + respuesta);
    } else {
        Serial.println("✗ Error: " + String(httpCode));
    }
    
    http.end();
}

// En loop():
// enviarAThingSpeak(temperatura, humedad);
// IMPORTANTE: ThingSpeak permite enviar 
// datos cada 15 segundos (mínimo en cuenta gratuita)
```

</td>
</tr>
</table>

---

## Proyecto Integrador: Estación Meteorológica Web

<table>
<tr>
<td width="50%">

### Descripción

Estación meteorológica con:
- Sensor DHT11 (temperatura y humedad)
- Servidor web integrado
- Dashboard visual
- Actualización automática

### Componentes

| Componente | Pin ESP32 |
|------------|-----------|
| DHT11 | GPIO4 |
| LED Status | GPIO2 |

### Librerías

```cpp
#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"
```

</td>
<td width="50%">

### Diagrama de Arquitectura

<table>
<tr>
<td width="50%">

#### 📥 CAPA DE SENSORES

| Componente | Función |
|------------|---------|
| **DHT11** | Lee temperatura y humedad |
| GPIO4 | Conexión al ESP32 |

#### ⚙️ CAPA DE PROCESAMIENTO

| Componente | Función |
|------------|---------|
| **ESP32** | Procesador principal |
| • Lee datos | Adquisición de sensores |
| • Servidor web | WebServer en puerto 80 |

</td>
<td width="50%">

#### 📡 CAPA DE CONECTIVIDAD

| Componente | Función |
|------------|---------|
| **WiFi** | Conexión a red local |
| • IP dinámica | Asignada por DHCP |
| • Puerto 80 | HTTP estándar |

#### 🖥️ CAPA DE USUARIO

| Componente | Función |
|------------|---------|
| **Navegador** | Acceso vía web |
| • Dashboard | Visualización de datos |
| • Auto-refresh | Actualización cada 5s |

</td>
</tr>
</table>

### Flujo de Datos

1. ESP32 lee DHT11 cada 2 segundos
2. Servidor web atiende peticiones
3. Página HTML muestra datos actuales
4. JavaScript actualiza cada 5 segundos

</td>
</tr>
</table>

---

## Código Completo: Estación Meteorológica (1/2)

### Configuración y Setup

```cpp
#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

const char* ssid = "TU_RED_WIFI";
const char* password = "TU_PASSWORD";

const int DHT_PIN = 4;
DHT dht(DHT_PIN, DHT11);
WebServer server(80);

float temperatura = 0;
float humedad = 0;

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/api/datos", handleApiDatos);
  server.begin();
}
```

### Loop Principal

```cpp
void loop() {
  // Leer cada 2s
  if (millis() - ultimaLectura > 2000) {
    temperatura = dht.readTemperature();
    humedad = dht.readHumidity();
    ultimaLectura = millis();
  }

  server.handleClient();
}
```

---

## Código Completo: Estación Meteorológica (2/2)

### Manejador: Página HTML

```cpp
void handleRoot() {
  String html = "<html><head>";
  html += "<meta charset='UTF-8'>";
  html += "<style>body{font-family:Arial;text-align:center;padding:20px;}";
  html += ".temp{color:#e74c3c;font-size:48px;}";
  html += ".hum{color:#3498db;font-size:48px;}</style>";
  html += "</head><body>";
  html += "<h1>🌤️ Estación Meteorológica</h1>";

  html += "<div class='card'>";
  html += "🌡️ " + String(temperatura, 1) + "°C<br>";
  html += "💧 " + String(humedad, 1) + "%";
  html += "</div>";

  html += "<script>setTimeout(()=>location.reload(),5000);</script>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}
```

### API JSON

```cpp
void handleApiDatos() {
  String json = "{";
  json += "\"temp\":" + String(temperatura, 2) + ",";
  json += "\"hum\":" + String(humedad, 2);
  json += "}";

  server.send(200, "application/json", json);
}
```

---

## Seguridad en WiFi IoT

### ❌ Prácticas Inseguras

```cpp
// Credenciales hardcodeadas
const char* ssid = "MiRedCasa";
const char* password = "ClaveSecreta123";

// HTTP sin cifrar
http.begin("http://api.ejemplo.com/datos");

// API Keys visibles
String url = "?api_key=ABC123XYZ";
```

### Niveles de Seguridad WiFi

| Protocolo | Seguridad |
|-----------|-----------|
| Abierto | ❌ Nunca usar |
| WEP | ❌ Obsoleto |
| WPA | ⚠️ Vulnerable |
| WPA2 | ✅ Seguro |
| WPA3 | ✅✅ Más seguro |

</td>
<td width="50%">

### ✅ Mejores Prácticas

```cpp
// 1. Credenciales en archivo separado
// config.h (no subir a git)
#include "config.h"
// config.h contiene:
// const char* ssid = "...";
// const char* password = "...";

// 2. Usar HTTPS cuando sea posible
http.begin("https://api.seguro.com/datos");

// 3. API Key en variables de entorno
const char* apiKey = API_KEY;  // Definida en config.h

// 4. WPA2 mínimo
// Configurar router con WPA2 o superior

// 5. Portal de configuración
// Crear AP temporal para configurar WiFi
// sin hardcodear credenciales

// 6. Validar conexiones
if (WiFi.status() == WL_CONNECTED) {
    // Verificar IP válida
    if (WiFi.localIP().toString() != "0.0.0.0") {
        // Proceder
    }
}
```

</td>
</tr>
</table>

---

## Modos de Ahorro de Energía

<table>
<tr>
<td width="33%">

### Light Sleep

**CPU pausada, WiFi activo**

```cpp
// Dormir 5 segundos
esp_sleep_enable_timer_wakeup(5 * 1000000);
esp_light_sleep_start();

// Consumo: ~0.8 mA
// Wake-up: < 3 ms
```

**Uso ideal:** Pausas breves entre lecturas

</td>
<td width="33%">

### Deep Sleep

**CPU y WiFi apagados**

```cpp
// Dormir 60 segundos
esp_sleep_enable_timer_wakeup(60 * 1000000);
esp_deep_sleep_start();

// Al despertar: reboot completo

// Consumo: ~10 µA
// Wake-up: 100+ ms
```

**Uso ideal:** Sensores de batería

</td>
<td width="34%">

### Modem Sleep

**WiFi apagado entre transmisiones**

```cpp
// Activar modo sleep
WiFi.setSleep(true);

// ESP32 gestiona automáticamente
// el encendido/apagado del WiFi

// Consumo: Variable
// Según intervalo de transmisión
```

**Uso ideal:** Balance energía/conectividad

</td>
</tr>
</table>

### Comparación de Consumo

| Modo | Consumo | Uso Típico | Ejemplo |
|------|---------|------------|---------|
| Activo (transmitiendo) | 160-260 mA | Streaming de datos | Cámara IP |
| Activo (idle) | 80-120 mA | Servidor web activo | Dashboard en tiempo real |
| Light Sleep | 0.8 mA | Lecturas periódicas | Sensor de temperatura cada 10s |
| Deep Sleep | 0.01 mA | Reportes horarios | Estación meteorológica |

---

## Troubleshooting WiFi

### Problemas Comunes

| Síntoma | Causa | Solución |
|---------|-------|----------|
| No conecta | SSID/Password incorrectos | Verificar credenciales |
| IP 0.0.0.0 | Sin DHCP | Reiniciar router |
| Desconexiones | Señal débil (RSSI < -80) | Acercar al router |
| Timeout | Firewall | Revisar configuración |

### Calidad de Señal (RSSI)

| RSSI (dBm) | Calidad |
|------------|---------|
| -30 a -60 | Excelente/ Muy buena |
| -60 a -70 | Buena |
| -70 a -80 | Regular |
| < -80 | Mala - cambiar ubicación |

### Diagnóstico

```cpp
void diagnosticoWiFi() {
  Serial.print("Estado: ");
  Serial.println(WiFi.status());
  Serial.print("RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}
```

---

## Resumen: Funciones Clave WiFi

<table>
<tr>
<td width="50%">

### Conexión y Estado

| Función | Descripción |
|---------|-------------|
| `WiFi.begin(ssid, pass)` | Iniciar conexión |
| `WiFi.status()` | Estado de conexión |
| `WiFi.localIP()` | IP asignada al ESP32 |
| `WiFi.RSSI()` | Intensidad de señal |
| `WiFi.macAddress()` | Dirección MAC |
| `WiFi.SSID()` | Nombre de red conectada |

### Modos de Operación

| Función | Descripción |
|---------|-------------|
| `WiFi.mode(WIFI_STA)` | Modo estación |
| `WiFi.mode(WIFI_AP)` | Modo access point |
| `WiFi.mode(WIFI_AP_STA)` | Modo dual |
| `WiFi.softAP(ssid, pass)` | Crear red WiFi |
| `WiFi.softAPIP()` | IP del AP |

</td>
<td width="50%">

### Servidor Web

| Función | Descripción |
|---------|-------------|
| `WebServer server(80)` | Crear servidor en puerto 80 |
| `server.on("/", handler)` | Definir ruta |
| `server.send(code, type, content)` | Enviar respuesta |
| `server.handleClient()` | Atender peticiones |
| `server.begin()` | Iniciar servidor |

### Cliente HTTP

| Función | Descripción |
|---------|-------------|
| `HTTPClient http` | Crear cliente |
| `http.begin(url)` | Configurar URL |
| `http.GET()` | Enviar petición GET |
| `http.POST(data)` | Enviar petición POST |
| `http.addHeader()` | Agregar headers |
| `http.getString()` | Obtener respuesta |
| `http.end()` | Cerrar conexión |

</td>
</tr>
</table>

---

# Evaluación E2 (15%)

## Presentación: Interacción Mundo Físico-Virtual

### Estructura de la Evaluación

<table>
<tr>
<td width="50%">

### Formato

| Aspecto | Detalle |
|---------|---------|
| **Grupos** | 2-3 personas |
| **Tiempo** | 10 min presentación + 3 min preguntas |
| **Modalidad** | Presentación oral + soporte visual |
| **Evaluadores** | Docente + compañeros (peer review) |

### Entregables

- [ ] **Diagrama de arquitectura** del proyecto
- [ ] **Código o pseudocódigo** de los componentes clave
- [ ] **Demostración** (si es posible) o video corto
- [ ] **Presentación** (slides opcional pero recomendado)

</td>
<td width="50%">

### Rúbrica de Evaluación

| Criterio | % | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (2) |
|----------|---|---------------|-----------|-------------|----------------|
| **Diseño técnico** | 40% | Completo y coherente | Correcto | Incompleto | Incorrecto |
| **Explicación** | 30% | Clara y precisa | Clara | Confusa | No explica |
| **Materiales** | 20% | Diagrama+código+demo | Diagrama+código | Solo diagrama | Sin materiales |
| **Preguntas** | 10% | Responde todo | Parcial | Dificultad | No responde |

**Nota:** Se redondea al entero más cercano. Mínimo para aprobar: 3.0

</td>
</tr>
</table>

---

## Ideas de Proyectos para Presentación

<table>
<tr>
<td width="33%">

### 🏠 Hogar Inteligente

**Alarma de seguridad**
- Sensores: PIR, magnético de puerta
- Actuador: Sirena, LED
- Conectividad: Notificaciones WiFi

**Control de iluminación**
- Sensor: LDR (luz ambiental)
- Actuador: Relé (luces)
- Conectividad: App web

**Detector de fugas**
- Sensor: Agua, humedad
- Actuador: Válvula solenoide
- Conectividad: Alertas Telegram

</td>
<td width="33%">

### 🌾 Agricultura

**Invernadero automatizado**
- Sensores: DHT11, humedad suelo, LDR
- Actuadores: Bomba agua, ventilador
- Conectividad: Dashboard web

**Monitoreo de cultivos**
- Sensores: Temperatura, humedad, luz
- Actuador: Display LCD
- Conectividad: ThingSpeak

**Sistema de riego**
- Sensor: Humedad suelo
- Actuador: Válvula/bomba
- Conectividad: Control remoto

</td>
<td width="34%">

### 🏭 Industria/Ciudad

**Contador de vehículos**
- Sensor: Ultrasónico
- Actuador: Display LED
- Conectividad: Base de datos

**Monitoreo de calidad del aire**
- Sensores: MQ-135, temperatura
- Actuador: Ventilador
- Conectividad: Alertas web

**Control de acceso**
- Sensor: RFID
- Actuador: Relé (puerta)
- Conectividad: Logs en cloud

</td>
</tr>
</table>

---

## Preguntas de Evaluación (Ejemplos)

Durante las presentaciones, el docente o compañeros pueden hacer preguntas como:

| Tema | Pregunta |
|------|----------|
| **Sensores** | ¿Por qué eligieron ese sensor específico y no otro? |
| **Conectividad** | ¿Cómo manejan la pérdida de conexión WiFi? |
| **Tiempo** | ¿Cada cuánto leen los sensores y por qué ese intervalo? |
| **Protocolos** | ¿Qué protocolo usarían para comunicación con la nube? |
| **Escalabilidad** | ¿Cómo escalaría este proyecto a 100 dispositivos? |
| **Seguridad** | ¿Qué consideraciones de seguridad implementaron? |
| **Energía** | ¿Cómo manejan el consumo de energía? |
| **Costos** | ¿Cuál sería el costo aproximado en producción? |

---

## Próxima Clase

### Clase 8: Protocolos IoT

**Temas a cubrir:**
- 📡 MQTT: Protocolo publish/subscribe
- 🌐 HTTP REST APIs
- 📊 Comparación de protocolos IoT
- 🔧 Hands-on: MQTT con ESP32

### Preparación

- Instalar **MQTT Explorer** o **MQTT.fx** en el computador
- Leer sobre conceptos publish/subscribe
- Revisar documentación de **HiveMQ** o **Mosquitto**

---

## Recursos Adicionales

<table>
<tr>
<td width="50%">

### Documentación Oficial

- [ESP32 WiFi Library](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/network/esp_wifi.html)
- [Arduino WiFi Reference](https://www.arduino.cc/reference/en/libraries/wifi/)
- [ThingSpeak Docs](https://www.mathworks.com/help/thingspeak/)

### Librerías Útiles

| Librería | Función |
|----------|---------|
| `WiFi.h` | Conexión WiFi básica |
| `WebServer.h` | Servidor web |
| `HTTPClient.h` | Cliente HTTP |
| `ArduinoJson.h` | Manejo de JSON |

</td>
<td width="50%">

### Herramientas de Diagnóstico

| Herramienta | Uso |
|-------------|-----|
| **WiFi Analyzer** (Android) | Ver canales y señal |
| **Wireshark** | Capturar tráfico de red |
| **Postman** | Probar APIs REST |
| **MQTT.fx** | Cliente MQTT de prueba |
| **Fing** | Escanear dispositivos en red |

### Comunidades

- **Reddit:** r/esp32, r/arduino
- **Stack Overflow:** etiqueta esp32
- **Foro ESP32:** esp32.com

</td>
</tr>
</table>

---

**¡Éxitos en sus presentaciones!**

📧 Contacto: [profesor@unaula.edu.co]
💻 Repositorio: GitHub del curso
💬 Discord/Teams: Canal del curso
