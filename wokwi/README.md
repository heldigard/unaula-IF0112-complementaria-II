# Proyectos Wokwi - Simulaciones ESP32

## 📋 Índice de Proyectos

| Clase | Proyecto | Link Wokwi | Archivo |
|-------|---------|------------|---------|
| 2 | Blink LED | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-02-blink-led.md](clase-02-blink-led.md) |
| 3 | LED + Botón | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-03-led-boton.md](clase-03-led-boton.md) |
| 4 | Sensor DHT22 | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-04-sensor-dht.md](clase-04-sensor-dht.md) |
| 5 | Sensor LDR | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-05-sensor-ldr.md](clase-05-sensor-ldr.md) |
| 6 | Integración | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-06-integracion.md](clase-06-integracion.md) |
| 7 | WiFi | [ Abrir en Wokwi ](https://wokwi.com/arduino/projects/new) | [clase-07-wifi.md](clase-07-wifi.md) |

---

## 🎯 CÓMO USAR WOKWI

### Paso 1: Abrir Wokwi

1. Ir a https://wokwi.com
2. Click en "New Arduino Project"
3. Seleccionar "ESP32"

### Paso 2: Agregar Componentes

**Desde el panel izquierdo:**
- Click en "+" para agregar componentes
- Buscar "LED", "DHT22", "LDR", etc.
- Arrastrar al área de trabajo

### Paso 3: Conectar Componentes

**Cablear:**
- Click en un pin del componente
- Arrastrar hacia el pin de destino
- Los cables cambian de color al conectarse

### Paso 4: Escribir Código

**Editor de código:**
- Panel derecho con código .ino
- Autocompletado con Ctrl + Espacio
- Formatear con Ctrl + T

### Paso 5: Ejecutar

**Botón "Run":**
- Compila y ejecuta el código
- Muestra salida en consola
- Simula en tiempo real

---

## 💡 PROYECTO 1: BLINK LED (CLASE 2)

### Diagrama

```
ESP32
  ├── GPIO2 ──── LED (Azul, integrado)
```

### Código

```cpp
#define LED_BUILTIN 2

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
```

### Actividad Estudiantes

1. Abrir el proyecto en Wokwi
2. Ejecutar y ver el LED parpadeando
3. Cambiar el tiempo de delay (100 → 500 ms)
4. Ejecutar de nuevo y ver diferencia
5. Screenshot del resultado

---

## 💡 PROYECTO 2: LED + BOTÓN (CLASE 3)

### Diagrama

```
     ESP32
    ┌──────┐
    │      │
    │ GPIO2├────[220Ω]──[LED+]──┐
    │      │                     │
    │ GPIO4├────[BOTÓN]──────────┘
    │      │                     │
    │  GND ├─────────────────────┘
    └──────┘
```

### Código

```cpp
const int LED = 2;
const int BOTON = 4;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BOTON) == LOW) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
```

---

## 💡 PROYECTO 3: SENSOR DHT22 (CLASE 4)

### Diagrama

```
ESP32                  DHT22
┌──────┐            ┌──────┐
│      │            │      │
│  3V3 ├────────────┤ VCC  │
│      │            │      │
│ GPIO4├────[10K]────┤ DATA │
│      │            │      │
│  GND ├────────────┤ GND  │
│      │            │      │
└──────┘            └──────┘
```

### Código

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("C  Hum: ");
  Serial.print(hum);
  Serial.println("%");

  delay(3000);
}
```

---

## 💡 PROYECTO 4: SENSOR LDR (CLASE 5)

### Diagrama

```
     3.3V
      │
     [LDR]
      │
      ├─── GPIO34 (ADC)
      │
    [10K]
      │
     GND
```

### Código

```cpp
#define LDR_PIN 34

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int luz = analogRead(LDR_PIN);
  int porcentaje = map(luz, 0, 4095, 0, 100);

  Serial.print("Luz: ");
  Serial.print(luz);
  Serial.print(" (");
  Serial.print(porcentaje);
  Serial.println("%)");

  delay(500);
}
```

---

## 💡 PROYECTO 5: WIFI (CLASE 7)

### Diagrama

```
ESP32 en modo Station (STA)
  ├── Conecta a red WiFi
  ├── Obtiene IP
  └── Lista información
```

### Código

```cpp
#include <WiFi.h>

const char* ssid = "TU_RED_WIFI";
const char* password = "TU_CLAVE";

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("RSSI: ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}

void loop() {
  delay(1000);
}
```

---

## 🎮 ACTIVIDADES POR CLASE

### Clase 2: Introducción

**Objetivo:** Familiarizarse con el entorno

1. Abrir Wokwi
2. Crear proyecto Blink
3. Ejecutar y modificar
4. Entender: setup(), loop(), delay()

### Clase 3: Entradas Digitales

**Objetivo:** Controlar LED con botón

1. Agregar botón al circuito
2. Conectar correctamente
3. Usar INPUT_PULLUP
4. Entender: HIGH/LOW, pinMode()

### Clase 4: Sensores Digitales

**Objetivo:** Leer temperatura y humedad

1. Agregar DHT22
2. Conectar con pull-up
3. Instalar librería DHT
4. Entender: librerías, objetos, funciones

### Clase 5: Sensores Analógicos

**Objetivo:** Leer nivel de luz

1. Crear divisor de voltaje
2. Conectar LDR
3. Usar ADC
4. Entender: ADC, map(), conversión

### Clase 7: Conectividad WiFi

**Objetivo:** Conectar a red WiFi

1. Simular WiFi
2. Ver IP asignada
3. Entender: WiFi.mode(), WiFi.begin(), WiFi.status()

---

## 📚 VENTAJAS PEDAGÓGICAS DE WOKWI

| Ventaja | Descripción |
|---------|-------------|
| **Sin hardware** | Practicar sin tener el kit físico |
| **Inmediato** | Sin tiempos de compilación/subida |
| **Seguro** | No se puede dañar nada |
| **Visible** | Ver flujo de electricidad |
| **Compartible** | URL para compartir proyectos |
| **Accesible** | Funciona en navegador (celular/tablet) |

---

## ⚠️ LIMITACIONES DE WOKWI

| Limitación | Solución |
|------------|----------|
| No todos los sensores | Usar equivalentes cuando sea posible |
| WiFi simulado | Funciona pero no es real |
| Sin timings exactos | Para lógica, no para medición precisa |
| Sin interrupciones complejas | Mantener código simple |

---

## 📞 SOPORTE

- **Wokwi Documentation:** https://docs.wokwi.com/
- **Wokwi Discord:** https://discord.gg/wokwi
- **Report bugs:** https://github.com/wokwi/wokwi/issues

---

## 🎯 FLUJO DE CLASE CON WOKWI

```
┌─────────────────────────────────────────────────────┐
│              ESTRUCTURA DE CLASE                     │
├─────────────────────────────────────────────────────┤
│                                                     │
│  0:00 - 0:15  │ Teoría del concepto                │
│               │ (Ej: Entradas digitales)            │
│                                                     │
│  0:15 - 0:30  │ Demo docente en Wokwi              │
│               │ (Proyectar y explicar código)       │
│                                                     │
│  0:30 - 1:00  │ Práctica estudiantes               │
│               │ (Replican en sus laptops/celulares) │
│                                                     │
│  1:00 - 1:15  │ Compartir y discutir               │
│               │ (URL del proyecto, dudas)           │
│                                                     │
└─────────────────────────────────────────────────────┘
```

---

## ✅ CHECKLIST DOCENTE

### Antes de la Clase

- [ ] Crear proyecto Wokwi de ejemplo
- [ ] Copiar URL del proyecto
- [ ] Probar código
- [ ] Preparar variaciones para estudiantes

### Durante la Clase

- [ ] Proyectar Wokwi en pantalla grande
- [ ] Explicar código paso a paso
- [ ] Dar tiempo para práctica (20-30 min)
- [ ] Circular ayudando estudiantes

### Después de la Clase

- [ ] Compartir URL en grupo
- [ ] Publicar código en GitHub
- [ ] Asignar actividad práctica para casa

---

**¡Wokwi es el puente perfecto entre teoría y práctica! 🌉**

**Guía preparada para:** IF0112 - Complementaria II
**Institución:** UNAULA
**Fecha:** Febrero 2026
