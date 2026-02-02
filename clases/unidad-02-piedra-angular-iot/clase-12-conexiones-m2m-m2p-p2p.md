---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 12: Conexiones M2M, M2P, P2P
## Modelos de Comunicación en Internet de las Cosas

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Diferenciar** los tipos de comunicación IoT
2. **Diseñar** sistemas con diferentes interacciones
3. **Seleccionar** el modelo apropiado para cada caso
4. **Implementar** comunicación M2M básica

**Duración:** 2 horas

---

## ¿Por qué importan los modelos de comunicación?

En IoT, entender **quién se comunica con quién** es fundamental para diseñar sistemas eficientes:

### Impacto en el diseño:
- **M2M** → Requiere automatización y reglas claras
- **M2P** → Necesita interfaces de usuario y notificaciones
- **P2P** → Implica experiencia de usuario y privacidad

### Casos reales:
| Modelo | Ejemplo | Latencia requerida |
|--------|---------|-------------------|
| M2M | Control industrial | < 10ms |
| M2P | Alerta de seguridad | < 1 segundo |
| P2P | Compartir fitness | Minutos |

### Tendencia 2025+:
Los sistemas modernos combinan los tres modelos en arquitecturas híbridas.

---

## Tipos de Comunicación en IoT

```
┌─────────────────────────────────────────────────────────────┐
│           MODELOS DE COMUNICACIÓN IoT                       │
│                                                             │
│   M2M                    M2P                    P2P         │
│   ───                    ───                    ───         │
│   Machine               Machine                Person       │
│   to                    to                     to           │
│   Machine               Person                 Person       │
│                                                             │
│   🤖 ──── 🤖           🤖 ──── 👤           👤 ──── 👤    │
│                                                             │
│   Automático            Notificación          Colaboración │
│   Sin humanos           Alertas, info         Vía IoT      │
│                                                             │
│   Ejemplo:              Ejemplo:              Ejemplo:      │
│   Sensor → Relé         Sensor → App          Wearable     │
│   auto encender         avisa usuario         compartir    │
└─────────────────────────────────────────────────────────────┘
```

---

## M2M: Machine-to-Machine

### Comunicación Entre Dispositivos

```
┌─────────────────────────────────────────────────────────────┐
│                       M2M                                   │
│        "Dispositivos que hablan entre sí"                  │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Sin intervención humana directa                        │
│   • Automatización de decisiones                           │
│   • Respuesta en tiempo real                               │
│   • Escala masiva posible                                  │
│                                                             │
│   ARQUITECTURAS:                                            │
│                                                             │
│   DIRECTA:        VÍA CLOUD:          VÍA BROKER:         │
│   🤖 ←→ 🤖        🤖 → ☁️ → 🤖        🤖 → 📫 → 🤖        │
│   (Local)         (Centralizado)      (Pub/Sub)           │
│                                                             │
│   WiFi/BLE        HTTP/REST           MQTT                 │
│   Mesh            WebSocket           AMQP                 │
└─────────────────────────────────────────────────────────────┘
```

---

## Ejemplo M2M: Sistema de Riego

```
┌─────────────────────────────────────────────────────────────┐
│              SISTEMA DE RIEGO AUTOMATIZADO                  │
│                                                             │
│   🌡️ Sensor Humedad                                         │
│       │                                                     │
│       │ Humedad < 30%                                       │
│       ▼                                                     │
│   🖥️ Controlador (ESP32)                                   │
│       │                                                     │
│       │ Activar riego                                       │
│       ▼                                                     │
│   🚿 Válvula de Riego                                       │
│       │                                                     │
│       │ Regar por 10 minutos                               │
│       ▼                                                     │
│   ⏰ Timer                                                  │
│       │                                                     │
│       │ Tiempo cumplido                                     │
│       ▼                                                     │
│   🚫 Apagar válvula                                         │
│                                                             │
│   TODO AUTOMÁTICO - SIN INTERVENCIÓN HUMANA                │
└─────────────────────────────────────────────────────────────┘
```

---

### Código M2M con MQTT

```cpp
#include <PubSubClient.h>

```cpp
// Dispositivo 1: Sensor (Publica)

void loop() {
    int humedad = analogRead(SENSOR_PIN);
    
    // Publicar lectura
    char msg[10];
    sprintf(msg, "%d", humedad);
    client.publish("jardin/humedad", msg);
    
    delay(5000);
}

// Dispositivo 2: Actuador (Suscribe y actúa)
void callback(char* topic, byte* payload, unsigned int length) {
    String mensaje = "";
    for (int i = 0; i < length; i++) {
        mensaje += (char)payload[i];
    }
    
    int humedad = mensaje.toInt();
    
    // Decisión automática M2M
    if (humedad < 300) {  // Suelo seco
        digitalWrite(VALVULA_PIN, HIGH);
        delay(600000);  // Regar 10 min
        digitalWrite(VALVULA_PIN, LOW);
    }
}
```

---

## Ejemplo M2P: Sistema de Seguridad

### Dispositivos Informando a Personas

```
┌─────────────────────────────────────────────────────────────┐
│                       M2P                                   │
│       "Dispositivos que informan a personas"               │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Notificaciones y alertas                               │
│   • Dashboards y visualizaciones                           │
│   • Información contextual                                 │
│   • Humano toma la decisión                                │
│                                                             │
│   CANALES M2P:                                              │
│                                                             │
│   📱 Push           📧 Email           📺 Dashboard        │
│   notificaciones    alertas            tiempo real         │
│                                                             │
│   📞 Llamada        💬 SMS/WhatsApp    🔊 Voz              │
│   emergencias       notificaciones     asistentes          │
└─────────────────────────────────────────────────────────────┘
```

---
## Ejemplo M2P: Sistema de Seguridad

```
┌─────────────────────────────────────────────────────────────┐
│              SISTEMA DE SEGURIDAD HOGAR                     │
│                                                             │
│   📹 Cámara detecta movimiento                              │
│       │                                                     │
│       ▼                                                     │
│   🖥️ Procesamiento Edge                                    │
│       │                                                     │
│       │ ¿Persona conocida?                                 │
│       │                                                     │
│   ┌───┴───┐                                                │
│   │       │                                                │
│   SÍ      NO                                               │
│   │       │                                                │
│   │   📱 Notificación al usuario                           │
│   │       "Persona desconocida en puerta"                  │
│   │       + Foto                                            │
│   │       │                                                │
│   │       ▼                                                │
│   │   👤 Usuario decide                                    │
│   │       [Ignorar] [Ver cámara] [Llamar policía]         │
│   │                                                        │
│   └── Log silencioso                                       │
└─────────────────────────────────────────────────────────────┘
```

---

### Código M2P - Notificación Push

```cpp
#include <HTTPClient.h>

```cpp
// Enviar notificación push via IFTTT

const char* iftttKey = "TU_CLAVE_IFTTT";
const char* event = "alerta_movimiento";

void enviarAlerta(String mensaje) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        
        String url = "http://maker.ifttt.com/trigger/";
        url += event;
        url += "/with/key/";
        url += iftttKey;
        
        http.begin(url);
        http.addHeader("Content-Type", "application/json");
        
        String json = "{\"value1\":\"" + mensaje + "\"}";
        
        int httpCode = http.POST(json);
        
        if (httpCode > 0) {
            Serial.println("Notificación enviada");
        }
        
---
        http.end();
    }
}

// En el loop:
if (digitalRead(PIR_PIN) == HIGH) {
    enviarAlerta("Movimiento detectado en sala");
}
```

---

## Comparación de Modelos

### Comunicación Humana Facilitada por IoT

```
┌─────────────────────────────────────────────────────────────┐
│                       P2P via IoT                           │
│       "Personas comunicándose a través de dispositivos"    │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Dispositivos como intermediarios                       │
│   • Comunicación enriquecida con datos                     │
│   • Colaboración remota                                    │
│   • Compartir experiencias                                 │
│                                                             │
│   EJEMPLOS:                                                 │
│                                                             │
│   ⌚ Fitness        🎮 Gaming         🏥 Telemedicina       │
│   compartir        multijugador      doctor-paciente       │
│   actividad        vía IoT           con datos vitales     │
│                                                             │
│   🏠 Smart Home    👶 Baby Monitor   🚗 Carpool            │
│   familia          padres-cuidador   conductores           │
│   coordinada       conectados        coordinados           │
└─────────────────────────────────────────────────────────────┘
```

---
## Ejemplo P2P: Compartir Actividad Fitness

```
┌─────────────────────────────────────────────────────────────┐
│              CHALLENGE FITNESS ENTRE AMIGOS                 │
│                                                             │
│   👤 Usuario A                    👤 Usuario B              │
│      ⌚ Smartwatch                   ⌚ Smartwatch           │
│      │                               │                      │
│      │ Pasos: 8,500                 │ Pasos: 6,200         │
│      │ Ritmo: 120 bpm               │ Ritmo: 115 bpm       │
│      │                               │                      │
│      └───────────┬───────────────────┘                      │
│                  │                                          │
│                  ▼                                          │
│            ┌──────────┐                                     │
│            │   ☁️     │                                     │
│            │  CLOUD   │                                     │
│            └────┬─────┘                                     │
│                 │                                           │
│                 ▼                                           │
│   ┌──────────────────────────────────────┐                 │
│   │   📱 App muestra competencia         │                 │
│   │   "¡Usuario A lleva ventaja!"        │                 │
│   │   [Enviar ánimo] [Ver progreso]      │                 │
│   └──────────────────────────────────────┘                 │
└─────────────────────────────────────────────────────────────┘
```

---

### Sistemas Reales Combinan Modelos

| Aspecto | M2M | M2P | P2P |
| --------- | ----- | ----- | ----- |
| **Iniciador** | Máquina | Máquina | Persona |
| **Receptor** | Máquina | Persona | Persona |
| **Decisión** | Automática | Humana | Colaborativa |
| **Latencia** | Crítica | Tolerante | Variable |
| **Volumen** | Alto | Medio | Bajo |
| **Ejemplo** | Termostato auto | Alerta incendio | Chat por app |
| **Protocolo** | MQTT, CoAP | Push, Email | WebSocket, MQTT |

```
┌─────────────────────────────────────────────────────────────┐
│            SISTEMA COMPLETO: HOGAR INTELIGENTE              │
│                                                             │
│   M2M                                                       │
│   ───                                                       │
│   🌡️ Termostato ←→ 💨 A/C                                  │
│   (Auto regulación de temperatura)                         │
│                                                             │
│   M2P                                                       │
│   ───                                                       │
│   🔔 Timbre → 📱 Notificación usuario                      │
│   (Aviso de visita)                                        │
│                                                             │
│   P2M                                                       │
│   ───                                                       │
│   👤 Usuario → 📱 App → 💡 Luces                           │
│   (Control remoto)                                         │
│                                                             │
│   P2P                                                       │
│   ───                                                       │
│   👤 Esposo ←→ 👤 Esposa (vía app del hogar)              │
│   (Coordinación familiar)                                  │
└─────────────────────────────────────────────────────────────┘
```

---

## Estándares de Interoperabilidad

### El Problema de los Silos

```
┌─────────────────────────────────────────────────────────────┐
│                PROBLEMA: ECOSISTEMAS CERRADOS               │
│                                                             │
│   ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐  │
│   │  Apple   │  │  Google  │  │  Amazon  │  │ Samsung  │  │
│   │ HomeKit  │  │   Home   │  │  Alexa   │  │SmartThings│  │
│   └────┬─────┘  └────┬─────┘  └────┬─────┘  └────┬─────┘  │
│        │             │             │             │         │
│        └─────────────┴─────────────┴─────────────┘         │
│                          │                                  │
│                    ❌ NO COMPATIBLES                        │
│                                                             │
│   SOLUCIÓN: ESTÁNDARES ABIERTOS                            │
│   • Matter (antes Project CHIP)                            │
│   • Thread (red mesh para IoT)                             │
│   • Zigbee 3.0                                             │
│   • OCF (Open Connectivity Foundation)                     │
└─────────────────────────────────────────────────────────────┘
```

---

## Matter: El Estándar Unificador

```
┌─────────────────────────────────────────────────────────────┐
│                     MATTER                                  │
│           "Un estándar para gobernarlos a todos"           │
│                                                             │
│   Respaldado por:                                           │
│   Apple + Google + Amazon + Samsung + 200+ empresas        │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Un dispositivo Matter funciona con CUALQUIER app       │
│   • Comunicación local (no depende de nube)                │
│   • Seguridad integrada                                    │
│   • Basado en IP (WiFi, Thread, Ethernet)                  │
│                                                             │
│   ANTES:                      DESPUÉS:                     │
│   💡 Bombilla Philips        💡 Bombilla Matter           │
│   → Solo Philips Hue         → Apple Home                  │
│   → Necesita bridge          → Google Home                 │
│                              → Alexa                        │
│                              → SmartThings                  │
└─────────────────────────────────────────────────────────────┘
```

---

## Actividad Práctica (40 min)

### Diseño de Sistema con M2M, M2P, P2P

**Escenario:** Gimnasio Inteligente

**Requisitos:**
- Sensores de ocupación en máquinas
- Reserva de equipos via app
- Alertas de disponibilidad
- Social features entre usuarios

**Tareas:**
1. Identificar interacciones M2M
2. Identificar interacciones M2P
3. Identificar interacciones P2P
4. Diagramar el sistema completo
5. Seleccionar protocolos para cada tipo

---

## Resumen de la Clase

| Tipo | Descripción | Ejemplo |
| ------ | ------------- | --------- |
| **M2M** | Máquina a máquina, automático | Sensor → Actuador |
| **M2P** | Máquina a persona, notificación | Alerta a app |
| **P2M** | Persona a máquina, control | App → Dispositivo |
| **P2P** | Persona a persona via IoT | Social fitness |
| **Matter** | Estándar de interoperabilidad | Smart home unificado |

---

## Próxima Clase

### Clase 13: Caso de Estudio Aplicado + E4 (15%)
- Análisis de proyecto IoT real
- Presentación de caso y sustentación

### Preparación
- Investigar un proyecto IoT real en Colombia o Latinoamérica
- Analizar con modelo P-P-D-C y tipos de comunicación

**¡Nos vemos!**
