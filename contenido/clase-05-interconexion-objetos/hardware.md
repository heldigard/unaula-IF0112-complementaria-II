# Hardware para IoT - Detalle

**Clase 5: Interconexión de Objetos | Unidad 2**

## 1. Microcontroladores IoT

### Comparativa MCU Populares

| MCU | Arquitectura | Flash | RAM | WiFi/BT | Pines |Precio | Uso recomendado |
|-----|--------------|-------|-----|---------|-------|--------|-----------------|
| **ESP32** | Xtensa LX6 dual-core | 4MB | 520KB | Sí | 30 | $3-5 | IoT general |
| **ESP8266** | Xtensa L106 | 4MB | 80KB | WiFi | 16 | $2-3 | IoT básico |
| **Arduino Uno** | ATmega328P | 32KB | 2KB | No | 20 | $20 | Aprendizaje |
| **RP2040** | ARM Cortex-M0+ dual | 2MB | 264KB | No | 30 | $1 | Bare metal |
| **Raspberry Pi Pico** | RP2040 | 2MB | 264KB | No | 40 | $4 | Prototipado |
| **Raspberry Pi 4** | ARM Cortex-A72 | - | 1-8GB | Sí | 40 | $35-75 | Edge computing |

### ESP32: El MCU IoT por Excelencia

**Especificaciones:**
- CPU: Xtensa LX6 dual-core @ 240 MHz
- Memoria: 520KB SRAM, 4MB Flash
- Conectividad: WiFi 802.11 b/g/n, Bluetooth 4.2 BLE
- Periféricos: ADC, DAC, SPI, I2C, UART, I2S, CAN
- Consumo: 80-240 mA activo, 10-150 µA deep sleep
- Voltaje: 2.3V - 3.6V

**Ventajas:**
- Bajo costo ($3-5)
- Excelente soporte comunitario
- Frameworks: ESP-IDF, Arduino, MicroPython
- Bajo consumo en deep sleep

**Limitaciones:**
- 1 ADC compartido (multiplexado)
- No hay DAC de alta precisión
- Documentación compleja

## 2. Sensores IoT Comunes

### Sensores Digitales (I2C)

| Sensor | Parámetro | Precisión | I2C Addr | Precio |
|--------|-----------|-----------|----------|--------|
| **BME280** | Temp, humedad, presión | ±1°C, ±3% | 0x76/77 | $3-5 |
| **DHT22** | Temp, humedad | ±0.5°C, ±2% | Propietario | $2-3 |
| **BH1750** | Luz (lux) | ±20% | 0x23 | $1-2 |
| **TSL2561** | Luz (lux/IR) | Alta | 0x39 | $2-3 |

### Sensores Analógicos

| Sensor | Parámetro | Rango | Salida | Precio |
|--------|-----------|-------|--------|--------|
| **LM35** | Temperatura | -55 to 150°C | 10mV/°C | $1 |
| **MQ-2** | Gas (humo, LP, CO) | 200-10000ppm | 0-5V | $3 |
| **Soil Moisture** | Humedad suelo | 0-100% | Resistivo | $1-2 |

## 3. Actuadores IoT Comunes

| Actuador | Control | Voltaje | Corriente | Driver |
|-----------|---------|---------|-----------|--------|
| **LED** | PWM/GPIO | 2-3V | 20mA | Resistencia |
| **Relé** | GPIO | 5-12V | 20-100mA | Transistor/Módulo |
| **Servo SG90** | PWM | 5V | 500mA | Directo |
| **Stepper** | H-bridge | 5-12V | 500mA/phase | A4988 |
| **Bomba DC** | PWM/Relé | 5-12V | 100-500mA | MOSFET/Relé |

## 4. Protocolos de Comunicación MCU

| Protocolo | Pines | Velocidad | Topología | Uso |
|-----------|-------|-----------|------------|-----|
| **I2C** | 2 (SDA, SCL) | 100-400 kHz | Bus (multi-master) | Sensores |
| **SPI** | 4 (MOSI, MISO, SCK, CS) | Mbps | Maestro-esclavo | Displays, SD |
| **UART** | 2 (TX, RX) | 1-5 Mbps | Punto a punto | GPS, módulos |
| **1-Wire** | 1 (Data) | 15.4 kbps | Bus | DS18B20 |
| **ADC** | 1 (Analog) | - | - | Sensores análogos |

---

**[← Volver a README](README.md)**
