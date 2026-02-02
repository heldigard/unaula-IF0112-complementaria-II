# Ejercicios: Programación IoT

**Clase 6: Programación de Microcontroladores | Unidad 2**

## Ejercicio 1: Blink con LED

### Objetivo
Hacer parpadear un LED cada segundo.

### Código Arduino

```cpp
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```

### Código MicroPython

```python
from machine import Pin
import time

led = Pin(2, Pin.OUT)

while True:
    led.on()
    time.sleep(1)
    led.off()
    time.sleep(1)
```

## Ejercicio 2: Lectura de Potenciómetro

### Objetivo
Leer un potenciómetro y mostrar valor en serial.

### Código Arduino

```cpp
const int POT_PIN = 34; // ADC1_CH6

void setup() {
  Serial.begin(115200);
  analogReadResolution(12); // 12 bits (0-4095)
}

void loop() {
  int valor = analogRead(POT_PIN);
  float voltaje = (valor / 4095.0) * 3.3;

  Serial.print("ADC: ");
  Serial.print(valor);
  Serial.print(" Voltaje: ");
  Serial.println(voltaje);

  delay(500);
}
```

## Ejercicio 3: Control de Servo

### Objetivo
Mover servo de 0 a 180 grados.

### Código Arduino

```cpp
#include <Servo.h>

Servo miServo;

void setup() {
  miServo.attach(18); // GPIO 18
}

void loop() {
  for (int pos = 0; pos <= 180; pos += 1) {
    miServo.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    miServo.write(pos);
    delay(15);
  }
}
```

## Ejercicio 4: Sensor de Temperatura con Alerta

### Objetivo
Leer temperatura y encender LED si > 30°C.

### Requisitos
- DHT22 conectado al GPIO 4
- LED conectado al GPIO 2

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();

  if (isnan(t)) {
    Serial.println("Error");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println(" *C");

  if (t > 30) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ALERTA: Temperatura alta!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  delay(2000);
}
```

---

**[← Volver a README](README.md)**
