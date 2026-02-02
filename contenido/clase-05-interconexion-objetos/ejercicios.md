# Ejercicios: Conexiones IoT

**Clase 5: Interconexión de Objetos | Unidad 2**

## Actividad: Conectar Sensor DHT22 a ESP32

### Conexión Física

| Pin DHT22 | Pin ESP32 | Nota |
|-----------|-----------|------|
| VCC | 3.3V | Rojo |
| DATA | GPIO 4 | Amarillo (con pull-up 10KΩ) |
| NC | - | No conectado |
| GND | GND | Negro |

### Código (Arduino Framework)

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
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error leyendo DHT");
    return;
  }

  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print("%  Temperatura: ");
  Serial.print(t);
  Serial.println("°C");

  delay(2000); // DHT22 es lento, mínimo 2 seg
}
```

## Checklist de Conexión

Antes de conectar cualquier componente:
- [ ] Verificar voltaje del componente vs MCU
- [ ] Usar resistencias cuando sea necesario
- [ ] Conectar GND primero
- [ ] Usar protoboard para pruebas
- [ ] Verificar polaridad en LEDs y capacitores

---

**[← Volver a README](README.md)**
