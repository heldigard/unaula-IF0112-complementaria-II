# Códigos Fuente - Proyecto IoT UNAULA

Esta carpeta contiene todos los códigos fuente necesarios para el curso IF0112 - Complementaria II (IoT).

## 📁 Estructura

```
codigo/
├── README.md                     # Este archivo
├── esp32/                        # Códigos para el ESP32
│   ├── 01_blink_led.ino         # Clase 2: Primer programa
│   ├── 02_led_boton.ino         # Clase 3: Entradas digitales
│   ├── 03_sensor_dht.ino        # Clase 4: Sensor DHT22
│   ├── 04_ldr_luz.ino           # Clase 5: LDR + integración
│   ├── 05_conexion_wifi.ino     # Clase 7: WiFi
│   ├── 06_enviar_datos_http.ino # Clase 8: HTTP POST
│   └── 07_proyecto_completo.ino # Clase 16: Proyecto final
├── servidor/                     # Códigos del servidor docente
│   ├── docker-compose.yml       # Configuración Docker
│   ├── init.sql                 # Script de base de datos
│   └── api/                     # API Flask
│       ├── Dockerfile
│       ├── requirements.txt
│       └── app.py
└── diagramas/                    # Diagramas de conexión
    ├── fritzing/
    └── conexiones.png
```

## 🚀 Cómo usar

### Para Estudiantes

1. **Instalar Arduino IDE:**
   - Descargar desde [arduino.cc](https://www.arduino.cc/en/software)
   - Instalar drivers ESP32: [Guía oficial](https://docs.espressif.com/projects/arduino-esp32/)

2. **Instalar librerías necesarias:**
   - `DHT sensor library` by Adafruit
   - `ArduinoJson` by Benoit Blanchon

3. **Subir código al ESP32:**
   - Abrir archivo `.ino` en Arduino IDE
   - Seleccionar placa: "ESP32 Dev Module"
   - Seleccionar puerto COM correcto
   - Click en "Upload" (▶️)
   - Si falla: mantener presionado botón BOOT mientras sube

### Para Docente

1. **Configurar servidor:**
   ```bash
   cd servidor
   docker-compose up -d
   ```

2. **Verificar servicios:**
   - API: http://localhost:5000
   - Grafana: http://localhost:3000

## 📚 Progresión del curso

| Archivo | Clase | Conceptos |
|---------|-------|-----------|
| `01_blink_led.ino` | 2 | Estructura Arduino, GPIO, Serial |
| `02_led_boton.ino` | 3 | Entradas digitales, pull-up |
| `03_sensor_dht.ino` | 4 | Sensores, librerías, I2C |
| `04_ldr_luz.ino` | 5 | ADC, integración de sensores |
| `05_conexion_wifi.ino` | 7 | WiFi, redes, IP |
| `06_enviar_datos_http.ino` | 8 | HTTP, REST API, JSON |
| `07_proyecto_completo.ino` | 16 | Proyecto integrador |

## 📝 Notas importantes

- Todos los códigos incluyen comentarios explicativos
- Los pines GPIO pueden variar según la versión del ESP32
- Los valores de WiFi deben configurarse antes de usar
- El servidor debe estar corriendo antes de probar los códigos HTTP

## 🔧 Troubleshooting

### "Failed to connect to ESP32"
- Mantener presionado botón BOOT al subir código
- Verificar cable USB (algunos solo cargan, no transmiten datos)
- Instalar drivers CP2102 o CH340

### "Error leyendo DHT"
- Verificar resistencia pull-up de 10K entre DATA y VCC
- Verificar conexiones (VCC, GND, DATA)
- El DHT22 necesita 2 segundos entre lecturas

### "WiFi no conecta"
- Verificar SSID y password
- Verificar que la red sea 2.4GHz (no 5GHz)
- Verificar señal WiFi (RSSI > -70 dBm)

### "Error HTTP -1"
- Verificar que el servidor esté corriendo
- Verificar IP del servidor en el código
- Verificar firewall de Windows

## 📄 Licencia

Código desarrollado para fines educativos en UNAULA.
Uso libre para estudiantes del curso IF0112.
