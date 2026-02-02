# MicroPython en ESP32

**Clase 6: Programación de Microcontroladores | Unidad 2**

## Ventajas de MicroPython

- Python completo en el microcontrolador
- Sin compilación - código interpretado
- REPL interactivo (como terminal Python)
- Ideal para prototipado rápido

## Instalación en ESP32

1. Descargar firmware: https://micropython.org/download/ESP32
2. Usar esptool para flashear:
```bash
esptool.py --chip esp32 --port COM3 write_flash -z 4MB 0x1000 esp32-micropython.bin
```

## Estructura Básica

```python
# main.py - Se ejecuta al inicio

import machine
import time
from machine import Pin

# Configurar LED
led = Pin(2, Pin.OUT)

# Loop
while True:
    led.on()
    time.sleep(1)
    led.off()
    time.sleep(1)
```

## WiFi con MicroPython

```python
import network

def conectar_wifi(ssid, password):
    sta_if = network.WLAN(network.STA_IF)
    sta_if.active(True)
    sta_if.connect(ssid, password)

    while not sta_if.isconnected():
        print('.', end='')
        time.sleep(0.5)

    print('\nConectado!')
    print('IP:', sta_if.ifconfig()[0])
    return sta_if

# Uso
wifi = conectar_wifi("SSID", "password")
```

## MQTT con MicroPython

```python
from umqttsimple import MQTTClient
import time

def mqtt_callback(topic, msg):
    print(f"Recibido: {topic}: {msg}")

client = MQTTClient("esp32")
client.set_callback(mqtt_callback)
client.connect("broker.hivemq.com")
client.subscribe("sensor/#")

while True:
    client.publish("sensor/temp", "25.5")
    client.check_msg()
    time.sleep(5)
```

## HTTP Request

```python
import urequests

response = urequests.get('http://httpbin.org/get')
print(response.text)
response.close()

# POST con JSON
import ujson
data = ujson.dumps({"valor": 25.5})
response = urequests.post('http://httpbin.org/post', data=data)
print(response.text)
response.close()
```

---

**[← Volver a README](README.md)**
