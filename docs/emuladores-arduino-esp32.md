# Guía de Emuladores y Simuladores Arduino/ESP32
## Para Clases Teóricas - Curso IF0112 Complementaria II (IoT)

**Actualizado:** Febrero 2026

---

## 1. Introducción

Para las clases teóricas donde no se tiene acceso al laboratorio,
se pueden usar emuladores que permiten:
- Practicar programación sin hardware real
- Probar código antes de subirlo al ESP32
- Enseñar conceptos de IoT de forma interactiva

---

## 2. Emuladores Recomendados

### Opción 1: Wokwi (RECOMENDADO)

**Plataforma:** web-based (gratuito)
**Enlace:** https://wokwi.com/

| Característica | Detalle |
|----------------|---------|
| ESP32 | ✅ Soportado |
| Arduino UNO | ✅ Soportado |
| Sensores | DHT11, DHT22, LDR, y más |
| Precio | Gratis (plan básico) |
| Offline | ❌ Requiere internet |

**Ventajas:**
- No requiere instalación
- Comunidad activa
- Diagramas compartibles
- Simulación en tiempo real

**Cómo usar:**
1. Ir a wokwi.com
2. Crear nuevo proyecto "ESP32"
3. Agregar componentes (DHT22, LED, etc.)
4. Escribir código en editor
5. Presionar "Play" para simular

**Ejemplo de código para Wokwi:**

```cpp
/*
 * Simulación ESP32 con Wokwi
 * LED parpadeante + DHT22
 */

#define LED_PIN 2
#define DHT_PIN 4

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  delay(1000);
}
```

---

### Opción 2: Tinkercad Circuits (Autodesk)

**Plataforma:** web-based
**Enlace:** https://www.tinkercad.com/circuits

| Característica | Detalle |
|----------------|---------|
| Arduino UNO | ✅ Excelente |
| ESP32 | ⚠️ Limitado |
| Sensores | Básicos |
| Precio | Gratis (cuenta Autodesk) |
| Offline | ❌ Requiere internet |

**Limitación:** Soporte básico para ESP32, mejor para Arduino UNO.

---

### Opción 3: PlatformIO con SimulIDE

**Plataforma:** Desktop (Windows/Mac/Linux)
**Enlace:** https://simulide.com/

| Característica | Detalle |
|----------------|---------|
| Arduino | ✅ Excelente |
| ESP32 | ⚠️ Experimental |
| Precio | Gratis (open source) |
| Offline | ✅ Sí |

**Instalación:**
1. Descargar SimulIDE
2. Instalar PlatformIO extension en VS Code
3. Configurar para Arduino

---

### Opción 4: Arduino Web Editor (Oficial)

**Plataforma:** web-based
**Enlace:** https://create.arduino.cc/

| Característica | Detalle |
|----------------|---------|
| Arduino | ✅ Excelente |
| ESP32 | ✅ Soportado |
| Sensores | ✅ Bibliotecas |
| Precio | Gratis (con cuenta) |
| Offline | ⚠️ Requiere plugin |

**Ventaja:** Acceso a bibliotecas oficiales de Arduino.

---

## 3. Comparativa de Emuladores

| Característica | Wokwi | Tinkercad | SimulIDE | Arduino Web |
|----------------|-------|-----------|----------|-------------|
| ESP32 | ✅ Excelente | ⚠️ Básico | ⚠️ Experimental | ✅ Bueno |
| DHT22 | ✅ Sí | ✅ Sí | ✅ Sí | ✅ Sí |
| LDR | ✅ Sí | ✅ Sí | ✅ Sí | ✅ Sí |
| WiFi | ✅ Sí | ❌ No | ❌ No | ⚠️ Limitado |
| Precio | Gratis | Gratis | Gratis | Gratis |
| Offline | ❌ No | ❌ No | ✅ Sí | ⚠️ No |
| Facilidad | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐ | ⭐⭐⭐ | ⭐⭐⭐⭐ |

---

## 4. Guía para el Docente

### Clase Teórica sin Laboratorio

**Actividad sugerida con Wokwi:**

1. **Demostración en vivo (15 min)**
   - Proyectar Wokwi
   - Mostrar código funcionando
   - Cambiar parámetros en tiempo real

2. **Ejercicio práctico (30 min)**
   - Estudiantes acceden a Wokwi
   - Modifican código dado
   - Observan resultados

3. **Discusión (15 min)**
   - Preguntas sobre código
   - Conexión con temas de clase

### Código Base para Demostraciones

**Ejemplo 1: Blink básico**

```cpp
// Blink simple en ESP32
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

**Ejemplo 2: Lectura de sensor (simulado)**

```cpp
// Lectura simulada de DHT22
#define DHT_PIN 4

float temperatura = 25.0;
float humedad = 60.0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Simular variación
  temperatura += random(-5, 5) / 10.0;
  humedad += random(-10, 10) / 10.0;

  Serial.printf("Temp: %.1f°C, Hum: %.1f%%\n", temperatura, humedad);
  delay(2000);
}
```

**Ejemplo 3: Control por botón (simulado)**

```cpp
// Control de LED por botón simulado
#define LED_PIN 2
#define BOTON_PIN 13

bool ledEstado = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BOTON_PIN, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BOTON_PIN) == LOW) {
    ledEstado = !ledEstado;
    digitalWrite(LED_PIN, ledEstado);
    delay(200);  // Antirrebote
  }
}
```

---

## 5. Recursos para Estudiantes

### Para Practicar en Casa

| Recurso | Enlace | Uso |
|---------|--------|-----|
| Wokwi | wokwi.com | Práctica principal |
| Arduino Web | create.arduino.cc | Alternativa online |
| Docs ESP32 | docs.espressif.com | Documentación |
| Ejemplos | examples.arduino.cc | Códigos de referencia |

### Videos Tutoriales

1. "Wokwi ESP32 Tutorial en Español"
2. "Simular Arduino Online"
3. "Programación ESP32 desde cero"

---

## 6. Limitaciones de los Emuladores

### Lo que NO pueden simular:

| Aspecto | Reality | Emulador |
|---------|---------|----------|
| Precisión de sensores | ✅ Lecturas reales | ❌ Valores aproximados |
| Ruido eléctrico | ✅ Sí | ❌ No |
| Temperatura ambiente | ✅ Afecta lecturas | ❌ No |
| WiFi real | ✅ Conexión a red | ⚠️ Simulado |
| Batería | ✅ Descarga real | ❌ No |

### Lo que SÍ pueden simular:

- Lógica de programación
- Flujo del código
- Pines digitales
- Comunicación serial
- Comportamiento básico de sensores

---

## 7. Recomendaciones para el Curso

### Clases 1-4 (Teóricas)
- **Wokwi** para demostraciones
- No se necesita hardware real
- Enseñar conceptos sin distracciones de hardware

### Clase 5+ (LAB 1+)
- Usar emulador como "ensayo" antes del laboratorio
- Estudiantes practican código en Wokwi
- Llegan preparados al LAB

### Proyecto Final
- Emular pruebas antes de implementar
- Probar código complejo sin arriesgar hardware

---

## 8. Acceso Rápido para Estudiantes

```
┌─────────────────────────────────────────────────────────┐
│           ACCESO RÁPIDO - EMULADORES                    │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  1️⃣  WOKWI (RECOMENDADO)                              │
│      👉 https://wokwi.com/esp32-new                    │
│                                                         │
│  2️⃣  ARDUINO WEB EDITOR                                │
│      👉 https://create.arduino.cc/editor               │
│                                                         │
│  3️⃣  TINKERCAD CIRCUITS                                │
│      👉 https://www.tinkercad.com/circuits              │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

---

*Documento creado para la segunda clase - 9 de febrero de 2026*
*Universidad Autónoma Latinoamericana (UNAULA)*
