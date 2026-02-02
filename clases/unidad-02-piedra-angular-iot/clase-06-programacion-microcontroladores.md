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

# Clase 6: Programación para Microcontroladores
### Arduino IDE y Primeros Programas

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| ⚙️ | Configurar Arduino IDE para ESP32 |
| 🔄 | Estructura básica de programas (setup/loop) |
| 📖 | Leer sensores digitales y analógicos |
| 💡 | Controlar actuadores con código |
| 🐛 | Usar monitor serial para depuración |

### Arquitecturas de MCU

| Arquitectura | MCU Común | Uso Típico |
|--------------|-----------|------------|
| **AVR** | ATmega328P | Arduino Uno |
| **ARM** | STM32, ESP32 | IoT moderno |
| **RISC-V** | ESP32-C3 | Futuro IoT |
| **x86** | Intel Quark | Industrial |

> **Sin código, el hardware es solo metal inerte.**

</div>
</div>

---

## Objetivos de la Clase

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 30px;">

<div>

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| ⚙️ **Configurar** | Arduino IDE para programar ESP32 |
| 🔄 **Entender** | Estructura de programa (setup/loop) |
| 📖 **Leer** | Sensores digitales y analógicos |
| 💡 **Controlar** | LEDs, botones y actuadores básicos |
| 🐛 **Usar** | Monitor serial para depuración |

</div>
<div>

### ⏱️ Estructura de la Clase

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Instalación Arduino IDE + ESP32 | 20 min |
| 2️⃣ | Estructura y funciones básicas | 30 min |
| 3️⃣ | Proyectos: Blink, Botón, LDR, PWM | 40 min |
| 4️⃣ | Sensor DHT11 + Práctica final | 20 min |
| 5️⃣ | Evaluación E2: Presentación proyectos | 10 min |

**Total:** 2 horas

> **💡 Práctica:** Traer ESP32 + cable USB + componentes

</div>
</div>

---

## ¿Por qué Programar Microcontroladores?

<table>
<tr>
<td width="50%">

### Están en TODAS Partes

| Dispositivo | Microcontroladores |
|-------------|-------------------|
| ⌚ Smartwatch | 3-5 MCUs |
| 🚗 Automóvil moderno | 40-100 MCUs |
| 🏠 Smart Home | 10-50 MCUs |
| 📱 Smartphone | 8-15 MCUs |
| 🏭 Fábrica industrial | 1000+ MCUs |

### Oportunidades Laborales Colombia (2026)

| Rol | Salario Mensual | Vacantes |
|-----|-----------------|----------|
| Desarrollador IoT Junior | $3.5M - $5M COP | +2,500 |
| Desarrollador IoT Senior | $6M - $10M COP | +800 |
| Ingeniero de Embarcados | $5M - $8M COP | +600 |
| Arquitecto IoT | $8M - $15M COP | +200 |

> 💡 **Dato:** Colombia tiene déficit de desarrolladores IoT certificados

</td>
<td width="50%">

### ¿Por qué Arduino para Comenzar?

**✅ Ventajas:**
- Curva de aprendizaje muy suave
- IDE gratuito y multiplataforma
- Miles de bibliotecas disponibles
- Comunidad global activa
- Hardware económico ($10-30 USD)
- Documentación extensa en español

**⚠️ Limitaciones:**
- No es un IDE profesional completo
- Gestión de proyectos grandes es difícil
- No tiene debugger integrado
- Para proyectos complejos: usar PlatformIO

**Alternativas:**
- **PlatformIO + VSCode:** Profesional
- **ESP-IDF:** Nativo Espressif
- **MicroPython:** Python para microcontroladores
- **Arduino CLI:** Para automatización

</td>
</tr>
</table>

---

## Instalación y Configuración de Arduino IDE

<table>
<tr>
<td width="50%">

### Paso a Paso: Instalación

| Paso | Acción | Descripción |
|------|--------|-------------|
| **1️⃣** | Descargar | [arduino.cc](https://www.arduino.cc/en/software) - Windows/Mac/Linux |
| **2️⃣** | Instalar | Ejecutar instalador, aceptar términos |
| **3️⃣** | Configurar ESP32 | File → Preferences → URLs adicionales |
| **4️⃣** | Instalar soporte | Tools → Board → Boards Manager |
| **5️⃣** | Seleccionar placa | Tools → Board → ESP32 Arduino → ESP32 Dev Module |
| **6️⃣** | Puerto COM | Tools → Port → seleccionar puerto correcto |

### URL para ESP32
```
https://dl.espressif.com/dl/package_esp32_index.json
```

### Puertos por Sistema Operativo

| SO | Puerto típico | Driver |
|----|---------------|--------|
| Windows | COM3, COM4, COM5 | CP210x o CH340 |
| Linux | /dev/ttyUSB0 | Incluido |
| Mac | /dev/cu.usbserial | CP210x |

</td>
<td width="50%">

### Interfaz de Arduino IDE

| Zona | Función |
|------|---------|
| **Menú superior** | File, Edit, Sketch, Tools, Help |
| **Barra de herramientas** | Verify, Upload, Serial Monitor |
| **Editor de código** | setup(), loop() y funciones |
| **Consola inferior** | Mensajes de compilación/error |
| **Serial Monitor** | Comunicación con ESP32 |

### Botones Clave

| Botón | Función | Atajo |
|-------|---------|-------|
| ✅ **Verify** | Compilar y chequear errores | Ctrl+R |
| → **Upload** | Subir código al ESP32 | Ctrl+U |
| 📟 **Serial Monitor** | Ver mensajes del ESP32 | Ctrl+Shift+M |

### Flujo de Trabajo

```
1. ESCRIBIR código en editor
       ↓
2. VERIFY (compilar) → ¿Errores?
       ↓ NO
3. UPLOAD → ¿Conectado?
       ↓ SÍ
4. SERIAL MONITOR → Ver resultados
```

</td>
</tr>
</table>

---

## Estructura de un Programa Arduino

<table>
<tr>
<td width="50%">

### Dos Funciones Fundamentales

Todo programa Arduino tiene exactamente **dos funciones obligatorias**:

#### 1. `setup()` - Configuración
- Se ejecuta **una sola vez** al inicio
- Se usa para configurar pines, iniciar comunicación, etc.
- Equivalente al "constructor" o "inicializador"

#### 2. `loop()` - Bucle Principal
- Se ejecuta **infinitamente** después de setup()
- Aquí va la lógica principal del programa
- Cada iteración es un "ciclo" del programa

### Variables Globales
- Se declaran **antes** de setup()
- Son accesibles desde setup() y loop()
- Se mantienen durante toda la ejecución

### Orden de Ejecución

```
ENCENDIDO → setup() → loop() → loop() → loop() → ...
    │                                │
    └──► RESET ────────────────────────┘
```

</td>
<td width="50%">

### Ciclo de Vida del Programa

| Fase | Función | Se Ejecuta |
|------|---------|------------|
| **Inicio** | `setup()` | 1 vez |
| **Bucle** | `loop()` | Infinitamente |
| **Reset** | Vuelve a `setup()` | Cuando se reinicia |

### Analogía con la Vida Real

| Programa Arduino | Cocina |
|-----------------|---------|
| `setup()` | Preparar ingredientes y utensilios |
| `loop()` | Cocinar repetidamente (servir platos) |
| Variables globales | Ingredientes en la mesa |
| `millis()` | Reloj controlando tiempos |

### Flujo Simplificado

```
═════════════════════════════════════════════
            INICIO (Power/Reset)
                    ↓
            ┌───────────────┐
            │   setup()     │
            │  • Configura  │
            │  • Inicializa  │ ◄─── Una sola vez
            └───────┬───────┘
                    ↓
         ┌──────────────────┐
         │     loop()       │
         │  • Lee sensores  │
         │  • Procesa datos │
         │  • Actúa         │ ◄─── Infinitamente
         └────────┬─────────┘
                  │
                  └───────► (Repite)
```

**Nota:** Todo lo que declaras en `setup()` se ejecuta UNA VEZ. Todo en `loop()` se repite mientras el ESP32 tenga energía.

</td>
</tr>
</table>

---

## Ejemplo: Programa Básico (Blink LED)

### Código Completo

```cpp
const int LED_PIN = 2;  // LED integrado

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("ESP32 Iniciado");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

### Explicación

| Función | Descripción |
|---------|-------------|
| `pinMode(pin, OUTPUT)` | Configura pin como salida |
| `digitalWrite(pin, HIGH)` | Escribe 3.3V al pin |
| `digitalWrite(pin, LOW)` | Escribe 0V al pin |
| `delay(ms)` | Pausa en milisegundos |
| `Serial.begin(115200)` | Inicia comunicación serial |

**HIGH = 3.3V (ESP32) | LOW = 0V**

---

## Funciones Básicas de Entrada/Salida

### Configuración y Digital

```cpp
// Configurar pines
pinMode(pin, OUTPUT);        // Salida
pinMode(pin, INPUT);         // Entrada
pinMode(pin, INPUT_PULLUP);  // Con pull-up interno

// Escribir/leer digital
digitalWrite(pin, HIGH);     // 3.3V
digitalWrite(pin, LOW);      // 0V
int valor = digitalRead(pin); // HIGH o LOW
```

### Analógico y PWM

```cpp
// Leer ADC (0-4095 en ESP32)
int valor = analogRead(pin);

// PWM en ESP32
ledcSetup(channel, 5000, 8);  // 5kHz, 8-bit
ledcAttachPin(pin, channel);
ledcWrite(channel, 127);      // 50% brillo
```

### Tiempo y Serial

```cpp
// Pausas
delay(1000);              // 1 segundo (bloquea)
unsigned long t = millis(); // Tiempo desde inicio (no bloquea)

// Serial
Serial.begin(115200);
Serial.println("Valor: " + String(valor));
Serial.printf("Temp: %.2f C\n", temp);
```

---

## Monitor Serial: Herramienta de Depuración

<table>
<tr>
<td width="50%">

### ¿Qué es el Monitor Serial?

Canal de comunicación entre el ESP32 y la computadora que permite:
- Ver valores de sensores en tiempo real
- Enviar comandos al microcontrolador
- Depurar errores en el código
- Visualizar el flujo del programa

### Velocidad (Baud Rate)

| Velocidad | Uso |
|-----------|-----|
| 9600 | Compatible universal |
| 115200 | Estándar ESP32 (rápido) |
| 921600 | Upload rápido |

**IMPORTANTE:** La velocidad en código debe coincidir con la del monitor serial.

### Abrir Monitor Serial

- **Arduino IDE:** Tools → Serial Monitor (Ctrl+Shift+M)
- **Atajo:** Ctrl+Shift+M
- **Configurar:** Seleccionar 115200 baud

</td>
<td width="50%">

### Ejemplos de Uso

```cpp
void setup() {
    Serial.begin(115200);
    Serial.println("=== Sistema iniciado ===");
}

void loop() {
    int sensorValue = analogRead(34);
    
    // Nivel 1: Solo valor
    Serial.println(sensorValue);
    
    // Nivel 2: Con contexto
    Serial.print("Sensor: ");
    Serial.println(sensorValue);
    
    // Nivel 3: Formateado
    Serial.printf("[%lu] Valor: %d\n", 
                  millis(), sensorValue);
    
    // Nivel 4: Con condición
    if (sensorValue > 2000) {
        Serial.println("⚠️ ALERTA: Valor alto!");
    }
    
    delay(1000);
}
```

### Leer desde el Monitor

```cpp
void loop() {
    // Si hay datos disponibles
    if (Serial.available() > 0) {
        // Leer entrada
        String comando = Serial.readString();
        Serial.print("Recibido: ");
        Serial.println(comando);
    }
}
```

</td>
</tr>
</table>

---

## Proyecto 1: LED Blink (El "Hola Mundo" de Hardware)

<table>
<tr>
<td width="50%">

### Versión Básica (con delay)

```cpp
// Pin del LED integrado en ESP32
const int LED_PIN = 2;

void setup() {
    // Configurar pin como salida
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Encender LED
    digitalWrite(LED_PIN, HIGH);
    delay(1000);  // Esperar 1 segundo
    
    // Apagar LED
    digitalWrite(LED_PIN, LOW);
    delay(1000);  // Esperar 1 segundo
}
```

**Problema:** El `delay()` bloquea TODO el programa. Durante ese segundo, el ESP32 no puede hacer nada más.

</td>
<td width="50%">

### Versión Profesional (sin delay)

```cpp
const int LED_PIN = 2;

// Variables para control de tiempo
unsigned long tiempoAnterior = 0;
const long intervalo = 1000;  // 1 segundo
int estadoLED = LOW;

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    // Obtener tiempo actual
    unsigned long tiempoActual = millis();
    
    // Si pasó el intervalo
    if (tiempoActual - tiempoAnterior >= intervalo) {
        // Guardar nuevo tiempo
        tiempoAnterior = tiempoActual;
        
        // Cambiar estado del LED
        estadoLED = !estadoLED;  // Toggle
        digitalWrite(LED_PIN, estadoLED);
    }
    
    // ¡Aquí puedes hacer otras tareas!
    // Leer sensores, checar botones, etc.
}
```

**Ventaja:** No bloquea. Permite multitarea.

</td>
</tr>
</table>

---

## Proyecto 2: Botón Controla LED

### Conexión

| ESP32 | Componente |
|-------|------------|
| GPIO15 | Botón (INPUT_PULLUP) |
| GPIO2 | LED + Resistencia 220Ω |
| GND | Común |

**INPUT_PULLUP**: LOW = presionado, HIGH = suelto

### Código

```cpp
const int LED_PIN = 2;
const int BOTON_PIN = 15;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BOTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(BOTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);  // Presionado
  } else {
    digitalWrite(LED_PIN, LOW);   // Suelto
  }
  delay(100);
}
```

> **Nota:** INPUT_PULLUP usa resistencia interna (~45KΩ) del ESP32

### Componentes Necesarios

| Componente | Cantidad |
|------------|----------|
| ESP32 DevKit | 1 |
| LED | 1 |
| Botón pulsador | 1 |
| Resistencia 220Ω | 1 |
| Protoboard + cables | - |

---

## Proyecto 3: Sensor de Luz (LDR)

### ¿Qué es el LDR?

**LDR (Light Dependent Resistor)** = Fotoresistencia

| Condición | Resistencia |
|-----------|-------------|
| **Oscuro** | Alta (MΩ) |
| **Iluminado** | Baja (Ω) |

### Conexión (Divisor de Voltaje)

**3.3V → LDR → GPIO34 → Resistencia 10KΩ → GND**

Más luz = Mayor valor ADC | Menos luz = Menor valor ADC

### Código

```cpp
const int LDR_PIN = 34;
const int LED_PIN = 2;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int valorLuz = analogRead(LDR_PIN);
  int porcentaje = map(valorLuz, 0, 4095, 0, 100);

  Serial.print("Luz: ");
  Serial.print(porcentaje);
  Serial.println("%");

  // LED se enciende si está oscuro
  digitalWrite(LED_PIN, valorLuz < 1000);
  delay(500);
}
```

| Condición | Valor ADC típico |
|-----------|------------------|
| Oscuro | < 1000 |
| Claro | > 3000 |

---

## Proyecto 4: Control de Brillo con PWM

### ¿Qué es PWM?

**PWM (Pulse Width Modulation)** es una técnica para simular una señal analógica usando pulsos digitales.

### Concepto

```
Duty Cycle = Porcentaje de tiempo en HIGH

 25%        50%        75%       100%
┌──┐      ┌────┐     ┌────┐    ┌────┐
│  │      │    │     │    │    │    │
│  └──┐   │    └──┐  │    │    │    │
│     │   │       │  │    │    │    │
┘     └───┘       └──┘    └────┘    └─

Brillo:   Bajo      Medio     Alto    Máximo
```

### ESP32 PWM

| Parámetro | Valor Típico |
|-----------|--------------|
| Frecuencia | 5000 Hz |
| Resolución | 8 bits (0-255) |
| Canales | 16 disponibles |

</td>
<td width="50%">

### Código: LED Dimmer

```cpp
const int LED_PIN = 2;
const int PWM_CHANNEL = 0;      // Canal 0-15
const int PWM_FREQ = 5000;      // 5 KHz
const int PWM_RESOLUTION = 8;   // 8 bits: 0-255

void setup() {
    // Configurar canal PWM
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RESOLUTION);
    
    // Asociar pin al canal
    ledcAttachPin(LED_PIN, PWM_CHANNEL);
}

void loop() {
    // Fade in (aumentar brillo)
    for (int brillo = 0; brillo <= 255; brillo++) {
        ledcWrite(PWM_CHANNEL, brillo);
        delay(10);  // Pequeña pausa
    }
    
    // Fade out (disminuir brillo)
    for (int brillo = 255; brillo >= 0; brillo--) {
        ledcWrite(PWM_CHANNEL, brillo);
        delay(10);
    }
}
```

### Funciones PWM en ESP32

| Función | Descripción |
|---------|-------------|
| `ledcSetup(ch, freq, res)` | Configura canal |
| `ledcAttachPin(pin, ch)` | Asocia pin a canal |
| `ledcWrite(ch, duty)` | Escribe valor (0-255) |
| `ledcDetachPin(pin)` | Libera pin |

</td>
</tr>
</table>

---

## Proyecto 5: Sensor DHT11 (Temperatura y Humedad)

### Instalación de Librería

Arduino IDE → Sketch → Include Library → Manage Libraries → Buscar "DHT sensor library" (Adafruit)

### Conexión

| ESP32 | DHT11 |
|-------|-------|
| 3.3V | VCC |
| GND | GND |
| GPIO4 ── 10KΩ ──► | DATA |

**Resistencia 10KΩ** entre DATA y VCC (pull-up)

### Especificaciones DHT11

| Parámetro | Valor |
|-----------|-------|
| Rango temperatura | 0°C a 50°C (±2°C) |
| Rango humedad | 20% a 80% RH (±5%) |
| Tiempo entre lecturas | Mínimo 2 segundos |

### Código

```cpp
#include "DHT.h"

const int DHT_PIN = 4;
DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error DHT11!");
    delay(2000);
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("°C  Hum: ");
  Serial.print(h);
  Serial.println("%");
  delay(2000);
}
```

### Troubleshooting DHT11

| Problema | Solución |
|----------|----------|
| Lecturas "nan" | Verificar resistencia 10KΩ |
| Siempre 0°C | Revisar conexiones DATA/VCC |
| Lecturas erráticas | Esperar 2s entre lecturas |

---

## Buenas Prácticas de Programación

### ✅ HACER

```cpp
// Constantes para pines
const int LED_PIN = 2;

// Nombres descriptivos
float temperaturaActual;

// millis() en lugar de delay()
unsigned long t = millis();
if (t - tiempoAnterior >= 1000) {
  // Ejecutar cada 1s sin bloquear
}

// Verificar errores
if (isnan(temp)) {
  return;  // Sensor no responde
}
```

### ❌ EVITAR

```cpp
// Números mágicos
digitalWrite(2, HIGH);  // ❌

// Delay excesivo
delay(10000);  // ❌ Bloquea todo

// Variables sin nombre descriptivo
int x, y, z;  // ❌

// No validar datos
int valor = analogRead(34);  // ❌ Sin validar
```

---

## Troubleshooting: Problemas Comunes

<table>
<tr>
<td width="50%">

### Error: "Failed to connect to ESP32"

**Causas y Soluciones:**

| Causa | Solución |
|-------|----------|
| Puerto incorrecto | Verificar Tools → Port |
| Cable de solo carga | Usar cable de datos USB |
| Drivers faltantes | Instalar CP2102 o CH340 |
| Modo bootloader | Presionar BOOT al subir |

**Secuencia de subida:**
1. Mantener presionado BOOT
2. Clic en Upload
3. Soltar BOOT cuando diga "Connecting..."

### Error: Caracteres raros en Serial Monitor

**Solución:**
1. Verificar baud rate = 115200
2. Ambos lados deben usar misma velocidad
3. Seleccionar "Both NL & CR" en monitor

</td>
<td width="50%">

### Error: DHT11 devuelve "nan"

**Causas y Soluciones:**

| Causa | Solución |
|-------|----------|
| Sin resistencia pull-up | Agregar 10KΩ entre DATA y VCC |
| Tiempo insuficiente | Esperar 2 segundos entre lecturas |
| Sensor dañado | Reemplazar sensor |
| Pin incorrecto | Verificar conexión GPIO |
| Voltaje incorrecto | Usar 3.3V o 5V según datasheet |

### Error: Lecturas erráticas del LDR

**Soluciones:**
1. Verificar divisor de voltaje
2. Usar resistor de 10KΩ
3. Probar diferentes pines ADC
4. Promediar múltiples lecturas:
```cpp
int promedio = 0;
for (int i = 0; i < 10; i++) {
    promedio += analogRead(LDR_PIN);
    delay(10);
}
promedio = promedio / 10;
```

</td>
</tr>
</table>

---

## PlatformIO: Alternativa Profesional

<table>
<tr>
<td width="50%">

### Comparativa

| Característica | Arduino IDE | PlatformIO |
|----------------|-------------|------------|
| Curva aprendizaje | ⭐ Muy fácil | ⭐⭐⭐ Media |
| Gestión librerías | Básica | Avanzada |
| IntelliSense | ❌ No | ✅ Sí |
| Autocompletado | ❌ No | ✅ Sí |
| Debug | ❌ No | ✅ Sí |
| Multi-plataforma | ❌ Arduino | ✅ 1000+ placas |
| Unit Testing | ❌ No | ✅ Sí |

### ¿Cuándo usar cada uno?

**Arduino IDE:**
- ✅ Aprendiendo
- ✅ Proyectos simples
- ✅ Clases y tutoriales

**PlatformIO:**
- ✅ Proyectos profesionales
- ✅ Equipos de desarrollo
- ✅ CI/CD
- ✅ Debugging complejo

</td>
<td width="50%">

### Instalación de PlatformIO

**Requisitos:**
- VSCode instalado
- Extensión PlatformIO IDE

**Pasos:**
1. Abrir VSCode
2. Extensiones → Buscar "PlatformIO IDE"
3. Instalar
4. Reiniciar VSCode

**Crear proyecto:**
```
PIO Home → New Project
→ Name: mi_proyecto
→ Board: Espressif ESP32 Dev Module
→ Framework: Arduino
→ Finish
```

**Estructura del proyecto:**
```
mi_proyecto/
├── src/
│   └── main.cpp          ← Código aquí
├── lib/                  ← Librerías locales
├── include/              ← Headers
├── platformio.ini        ← Configuración
└── .pio/                 ← Compilados
```

</td>
</tr>
</table>

---

## Actividad Práctica: Sistema de Alerta de Temperatura

### Descripción

Crear un sistema que:
1. **Mida** temperatura con DHT11
2. **Indique** estado con LEDs:
   - 🔴 **Rojo:** > 30°C (Calor)
   - 🟢 **Verde:** 20-30°C (Normal)
   - 🔵 **Azul:** < 20°C (Frío)
3. **Muestre** valores en Monitor Serial

### Materiales

| Componente | Pin ESP32 |
|------------|-----------|
| DHT11 | GPIO4 |
| LED Rojo | GPIO18 |
| LED Verde | GPIO19 |
| LED Azul | GPIO21 |

### Pseudocódigo

```
Configurar LEDs como salida
Iniciar DHT11

BUCLE:
  Leer temperatura

  SI temp > 30 → LED Rojo
  SINO SI temp >= 20 → LED Verde
  SINO → LED Azul

  Mostrar en Serial
  Esperar 2s
```

<div style="background: #fef3c7; padding: 10px; border-radius: 6px; margin-top: 10px;">
<strong>Nota:</strong> Resistencia pull-up de 10KΩ entre DATA y VCC del DHT11
</div>

### Tabla de Control de LEDs

| Temperatura | LED Activo | Estado GPIO |
|-------------|-------------|--------------|
| **< 20°C** | Azul (GPIO21) | HIGH |
| **20-30°C** | Verde (GPIO19) | HIGH |
| **> 30°C** | Rojo (GPIO18) | HIGH |

**Nota:** Solo un LED debe estar encendido a la vez. Apagar los otros antes de activar el correspondiente.

### Expansión del Proyecto

Opcionalmente puedes agregar:
- 🌐 **WiFi:** Enviar datos a la nube
- 🔊 **Buzzer:** Alarma sonora en calor extremo
- 📊 **Display OLED:** Mostrar temperatura localmente
- 📱 **Notificación:** Alerta al celular

</td>
</tr>
</table>

---

## Solución de Referencia

```cpp
#include "DHT.h"

const int DHT_PIN = 4;
const int LED_ROJO = 18;
const int LED_VERDE = 19;
const int LED_AZUL = 21;

DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(115200);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Error de sensor");
    delay(2000);
    return;
  }

  // Apagar todos
  digitalWrite(LED_ROJO, LOW);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);

  // Activar LED correspondiente
  if (temp > 30.0) {
    digitalWrite(LED_ROJO, HIGH);
    Serial.println("Calor extremo");
  }
  else if (temp >= 20.0) {
    digitalWrite(LED_VERDE, HIGH);
    Serial.println("Temperatura normal");
  }
  else {
    digitalWrite(LED_AZUL, HIGH);
    Serial.println("Frío");
  }

  delay(2000);
}
```

---

## Glosario de Términos

<table>
<tr>
<td width="33%">

### Hardware

| Término | Significado |
|---------|-------------|
| **ADC** | Analog-to-Digital Converter. Convierte voltaje a número digital |
| **PWM** | Pulse Width Modulation. Simula analógico con pulsos digitales |
| **GPIO** | General Purpose Input/Output. Pines de propósito general |
| **Pull-up/Pull-down** | Resistencias internas para definir estado por defecto |
| **Baud Rate** | Velocidad de comunicación serial (bits/segundo) |
| **Duty Cycle** | Porcentaje de tiempo en HIGH en señal PWM |

</td>
<td width="33%">

### Protocolos

| Término | Significado |
|---------|-------------|
| **I2C** | Inter-Integrated Circuit. Protocolo serial de 2 cables |
| **SPI** | Serial Peripheral Interface. Protocolo serial de alta velocidad |
| **UART** | Universal Async Receiver-Transmitter. Comunicación TX/RX |
| **1-Wire** | Protocolo de 1 cable (ej: DS18B20) |
| **TX/RX** | Transmit/Receive. Pines de comunicación serial |

</td>
<td width="34%">

### Software

| Término | Significado |
|---------|-------------|
| **Sketch** | Nombre de Arduino para un programa |
| **Library** | Colección de código pre-escrito |
| **IDE** | Integrated Development Environment |
| **Compiler** | Traduce código a lenguaje máquina |
| **Upload** | Subir programa al microcontrolador |
| **Flash** | Memoria no volátil donde se guarda el programa |

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
| **setup()** | Función que se ejecuta una vez al inicio |
| **loop()** | Función que se repite infinitamente |
| **pinMode()** | Configura un pin como entrada o salida |
| **digitalWrite()** | Escribe HIGH (3.3V) o LOW (0V) |
| **digitalRead()** | Lee el estado de un pin digital |
| **analogRead()** | Lee valor analógico (0-4095 en ESP32) |
| **Serial.begin()** | Inicia comunicación serial |
| **Serial.print()** | Imprime texto al monitor serial |
| **delay()** | Pausa la ejecución (milisegundos) |
| **millis()** | Retorna tiempo desde inicio (sin bloquear) |

</td>
<td width="50%">

### Proyectos Realizados

1. ✅ **LED Blink:** Parpadeo básico con delay y millis
2. ✅ **Botón + LED:** Entrada digital con pull-up
3. ✅ **LDR:** Lectura analógica de luz
4. ✅ **PWM:** Control de brillo con fade
5. ✅ **DHT11:** Sensor de temperatura/humedad
6. ✅ **Sistema de Alerta:** Integración completa

### Próximos Pasos

- 🔄 Conectividad WiFi (Clase 7)
- 🌐 Servidor web en ESP32
- 📡 Protocolos IoT (MQTT, HTTP)
- 🔧 Proyecto integrador

</td>
</tr>
</table>

---

## Evaluación E2 (15%) - Próxima Clase

<table>
<tr>
<td width="50%">

### Presentación: Interacción Mundo Físico-Virtual

**Objetivo:** Diseñar y explicar un proyecto IoT completo

**Requisitos:**
1. **Mínimo 2 sensores** diferentes
2. **Mínimo 1 actuador**
3. **Diagrama de conexiones** claro
4. **Pseudocódigo o código** funcional
5. **Aplicación práctica** contextualizada

**Formato de Entrega:**
- Grupos de 3 personas
- Presentación 10 minutos
- Diapositivas (opcional pero recomendado)
- Demostración física si es posible

</td>
<td width="50%">

### Ideas de Proyectos para Colombia

| Proyecto | Sensores | Actuador | Contexto |
|----------|----------|----------|----------|
| 🌾 Invernadero inteligente | DHT11, Humedad suelo | Bomba agua | Zona rural |
| 🏠 Alarma residencial | PIR, Magnético | Sirena | Seguridad |
| 💧 Detector fugas | Sensor agua, Humedad | Válvula | Hogar |
| 🚗 Parqueadero inteligente | Ultrasónico, LDR | Display | Urbano |
| 🌡️ Incubadora avícola | DHT22 | Calefactor | Emprendimiento |
| 🌱 Monitoreo cultivos | Temperatura, Luz | Ventilador | Agricultura |

### Rúbrica de Evaluación

| Criterio | % |
|----------|---|
| Claridad conceptual | 30% |
| Diagrama de conexiones | 25% |
| Código/pseudocódigo | 25% |
| Aplicación práctica | 20% |

</td>
</tr>
</table>

---

## Tarea para la Próxima Clase

### Preparación Obligatoria

<table>
<tr>
<td width="50%">

**1. Terminar Proyecto de Evaluación**
- [ ] Definir idea con el grupo
- [ ] Diseñar diagrama de conexiones
- [ ] Escribir pseudocódigo o código
- [ ] Preparar presentación (10 min)
- [ ] Revisar rúbrica de evaluación

**2. Material de Apoyo**
- Diagrama impreso o en tablet/laptop
- Código en GitHub o USB
- Lista de componentes necesarios

</td>
<td width="50%">

**3. Lectura Previa**
- Revisar apuntes de clases 5 y 6
- Investigar sobre WiFi en ESP32
- Leer sobre protocolos HTTP básicos

**4. Recursos Online**
- Arduino Reference: arduino.cc/reference
- ESP32 Arduino Core: docs.espressif.com
- Random Nerd Tutorials: randomnerdtutorials.com

</td>
</tr>
</table>

---

## Próxima Clase

# Clase 7: Conectividad WiFi

### Temas a Cubrir

- 📡 Configuración WiFi en ESP32 (modo STA y AP)
- 🌐 Servidor web básico con ESP32
- 📊 Envío de datos a la nube
- 🔐 Seguridad básica en redes IoT

### Evaluación E2

**¡No olviden traer su presentación lista!**

---

**¡Gracias! ¿Preguntas?**

📧 Contacto: [profesor@unaula.edu.co]
💻 Repositorio: GitHub del curso
💬 Discord/Teams: Canal del curso
