# Ejemplos de Proyectos Exitosos

**Clase 16: Proyecto Final | Unidad 2**

## Proyecto 1: Sistema de Riego Inteligente para Balcones

### Estudiante
- Juan Pérez (2024)

### Descripción
Sistema automatizado de riego para plantas en balcones/terrazas que monitorea humedad del suelo, temperatura y luz, activando riego solo cuando es necesario.

### Componentes

| Componente | Modelo | Cantidad |
|------------|-------|----------|
| ESP32 | DevKit V1 | 1 |
| Sensor humedad suelo | Capacitivo | 1 |
| Sensor temperatura | DHT22 | 1 |
| Bomba agua | Mini bomba DC 5V | 1 |
| Módulo relé | 1 canal | 1 |
| App móvil | Blynk | 1 |

### Características

- **Modos:** Manual, Automático, Calendario
- **Alertas:** Push notification cuando humedad < 30%
- **Ahorro:** 40% agua vs riego manual
- **Costo total:** ~$45 USD

### Código

```cpp
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "DHT.h"

#define DHTPIN 4
#define BOMBA_PIN 2
#define HUMEDAD_PIN 34

DHT dht(DHTPIN, DHT22);
BlynkTimer timer;

char auth[] = "TuTokenBlynk";

void checkHumedad() {
  int humedad = analogRead(HUMEDAD_PIN);
  humedad = map(humedad, 0, 4095, 0, 100);

  if (humedad < 30) {
    digitalWrite(BOMBA_PIN, HIGH);
    Blynk.notify("Riego activado");
  } else if (humedad > 60) {
    digitalWrite(BOMBA_PIN, LOW);
  }

  Blynk.virtualWrite(V0, humedad);
}

void setup() {
  pinMode(BOMBA_PIN, OUTPUT);
  Blynk.begin(auth);
  timer.setInterval(10000L, checkHumedad);
  dht.begin();
}

void loop() {
  Blynk.run();
  timer.run();
}
```

### Resultados

- **Innovación:** Calibración automática según tipo de planta
- **Escalabilidad:** Puede manejar hasta 4 macetas
- **Sostenibilidad:** Ahorra ~1500 litros agua/mes

---

## Proyecto 2: Monitor de Calidad del Aire para Interiores

### Estudiantes
- María González + Pedro Martínez (2024)

### Descripción
Sistema portátil que monitorea PM2.5, CO2, temperatura y humedad en interiores, con alertas cuando los niveles superan límites saludables.

### Componentes

| Componente | Modelo | Cantidad |
|------------|-------|----------|
| ESP32 | DevKit V1 | 1 |
| Sensor PM2.5 | Plantower PMS5003 | 1 |
| Sensor CO2 | SCD30 | 1 |
| DHT22 | DHT22 | 1 |
| OLED Display | 128x64 | 1 |
| Buzzer | Pasivo | 1 |
| Batería | 18650 + cargador | 1 |

### Características

- **Visualización:** Display OLED muestra valores en tiempo real
- **Alertas:** Buzzer + App cuando PM2.5 > 25 µg/m³
- **Registro:** SD card para datos históricos
- **Calibración:** Auto-calibración cada 24h

### Arquitectura

```
┌─────────────┐
│   ESP32     │
│  ┌─────────┐│
│  │ PM2.5   ││ UART
│  │ CO2     ││ I2C
│  │ DHT22   ││
│  └─────────┘│
│      │       │
│  ┌───┴───┐   │
│  │ OLED │   │ SD
│  │ Beeper│  │ Card
│  └──────┘   │
└──────┬───────┘
       │
    WiFi │
       ↓
   Thingspeak
```

### Resultados

- **Precisión:** ±15% vs estación profesional
- **Autonomía:** 8 horas continuas
- **Costo:** $85 USD (vs $500 comerciales)

---

## Proyecto 3: Cerradura Inteligente con Keypad

### Estudiantes
- Carlos Rodríguez + Ana López (2025)

### Descripción
Cerradura inteligente con teclado numérico que permite acceso por código, huella dactilar o app móvil, con registro de intentos de acceso.

### Componentes

| Componente | Modelo | Cantidad |
|------------|-------|----------|
| ESP32 | DevKit V1 | 1 |
| Teclado matricial | 4x4 | 1 |
| Servo motor | MG996R | 1 |
| Sensor huella | FPM10A | 1 |
| Relé | 5V | 1 |
| Buzzer | Pasivo | 1 |

### Características

- **Múltiples auth:** Código (4 dígitos), huella, App
- **Registro:** Intentos fallidos con timestamp
- **Alerta:** Push notification cuando acceso no autorizado
- **Offline:** Funciona con código sin internet

### Características de Seguridad

- **Anti-hammering:** 3 intentos = bloqueo 1 min
- **One-time codes:** Código cambia cada 24h (Opcional)
- **Logs inmutables:** SD card con registro intocable
- **Encrypted communication:** TLS 1.3

### Código (extracto)

```cpp
void verificarClave(int clave) {
  if (clave == CLAVE_MAESTRA) {
    abrirCerradura();
    logAcceso("Exitoso", "Clave maestra");
  } else if (verificarClaveUsuario(clave)) {
    abrirCerradura();
    logAcceso("Exitoso", "Usuario");
  } else {
    intentosFallidos++;
    logAcceso("Fallido", String(clave));
    if (intentosFallidos >= 3) {
      bloquearTemporal();
      intentosFallidos = 0;
    }
  }
}

void abrirCerradura() {
  for (int pos = 90; pos >= 0; pos -= 5) {
    miServo.write(pos);
    delay(20);
  }
}

void logAcceso(String resultado, String detalle) {
  String logEntry = String(millis()) + "," + resultado + "," + detalle;
  appendFile(SD_CS, "/accesos.txt", logEntry.c_str());
}
```

---

## Proyecto 4: Seguimiento de Mascotas con GPS

### Estudiantes
- Luisa Fernández + David Suárez (2025)

### Descripción

Collar GPS para mascotas que permite monitorear ubicación en tiempo real, alertar si sale de zona segura, y cuenta actividad física.

### Componentes

| Componente | Modelo | Cantidad |
|------------|-------|----------|
| ESP32 | WROVER | 1 |
| GPS | NEO-6M | 1 |
| Acelerómetro | MPU6050 | 1 |
| Batería | 18650 + TP4056 | 1 |
| Vibración | Motor vibración | 1 |
| LGPS antenna | Activa | 1 |

### Características

- **Geofencing:** Alerta si sale de zona (radio configurable)
- **Actividad:** Cuenta pasos, detecta sueño, juego
- **Batería:** 8 días autonomía
- **Peso:** <80g collar incluido
- **Resistente:** IP67 (agua/polvo)

### Arquitectura

```
┌───────────────┐
│    COLLAR     │
│ ┌───────────┐ │
│ │ ESP32     │◄────────────┐
│ │           │              │
│ │ GPS       │      Thingspeak│
│ │ Acelerómetro│              │
│ │ Vibración  │              │
│ └───────────┘              │
└───────┬─────────────────────┘
        │
     WiFi │
        ↓
    Casa (WiFi)
```

### Resultados

- **Precisión GPS:** 5 metros en abierto, 10 metros en ciudad
- **Autonomía:** 8 días (1 envío/hora)
- **Geofence:** < 10 segundos detecta salida de zona
- **Costo:** $65 USD (vs $150 comerciales)

---

**[← Volver a README](README.md)**
