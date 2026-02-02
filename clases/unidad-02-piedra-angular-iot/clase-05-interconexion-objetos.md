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

# Clase 5: Interconexión de Objetos
### Hardware para IoT: Microcontroladores

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| 🔧 | Identificar componentes hardware para IoT |
| ⚖️ | Comparar microcontroladores populares |
| 🔌 | Describir sensores y actuadores comunes |
| ⚡ | Conectar componentes básicos al MCU |

### Hardware Clave

| Tipo | Ejemplo | Uso |
|------|---------|-----|
| **MCU** | ESP32, Arduino | Cerebro del sistema |
| **Sensores** | DHT11, PIR | Capturan mundo físico |
| **Actuadores** | Relé, Servo | Ejecutan acciones |

> **Pregunta clave:** ¿Cómo conectar lo físico con lo digital?

</div>
</div>

---

## Objetivos de la Clase

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 30px;">

<div>

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| 🔍 **Identificar** | Componentes hardware para IoT |
| ⚖️ **Comparar** | Microcontroladores populares |
| 🔌 **Describir** | Sensores y actuadores comunes |
| ⚡ **Conectar** | Componentes básicos al MCU |

</div>
<div>

### ⏱️ Estructura de la Clase

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Microcontroladores (ESP32, Arduino, RPi) | 40 min |
| 2️⃣ | Sensores y Actuadores | 40 min |
| 3️⃣ | Protocolos I2C, SPI, UART | 30 min |
| 4️⃣ | Demo práctica + Actividad | 10 min |

**Total:** 2 horas

> **💡 Próxima clase:** Programación de Microcontroladores (código)

</div>
</div>

---

## Conexión con Resultados de Aprendizaje

> **Resultado:** Comprende la interacción entre el mundo físico y el mundo virtual

### La Interfaz Físico-Digital: El MCU como Puente

<table>
<tr>
<td width="33%">

#### 📥 ENTRADA (Mundo Físico → Digital)
| Paso | Componente | Acción |
|------|------------|--------|
| 1 | **Sensores** | Capturan señales físicas |
| 2 | **ADC** | Convierte analógico → digital |
| 3 | **MCU** | Procesa y analiza datos |

</td>
<td width="33%">

#### 🔄 PROCESAMIENTO
| Función | Descripción |
|----------|-------------|
| **CPU** | Ejecuta lógica del programa |
| **Memoria** | Almacena datos temporales |
| **Decisión** | Compara con umbrales |
| **Comunicación** | Envía/recibe datos |

</td>
<td width="34%">

#### 📤 SALIDA (Digital → Mundo Físico)
| Paso | Componente | Acción |
|------|------------|--------|
| 1 | **MCU** | Toma decisión |
| 2 | **DAC/PWM** | Genera señal de control |
| 3 | **Actuadores** | Ejecutan acción física |

**Ejemplo:** Detección de movimiento → Activar iluminación

</td>
</tr>
</table>

### Flujo Completo: Sensores ↔ MCU ↔ Actuadores

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 15px; text-align: center; margin: 15px 0;">

<div style="background: #dbeafe; padding: 15px; border-radius: 8px;">

#### 🌡️ ENTRADA
**Sensores**

Capturan señal física

↓ ADC

Señal Digital

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 8px;">

#### 📊 PROCESAMIENTO
**MCU**

Procesa datos

Toma decisiones

↓ Comunicación

(WiFi/Bluetooth)

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 8px;">

#### ⚡ SALIDA
**Actuadores**

Reciben señal

↓ DAC/PWM

Acción física

</div>

</div>

---

## Evolución de la Computación: De Mainframes a IoT

| Era | Equipo | Tamaño/Uso | Costo | Paradigma |
|-----|--------|------------|-------|-----------|
| **1960s** | Mainframe | Habitación / Empresas | $1,000,000+ | Un equipo, muchos usuarios |
| **1980s** | PC | Mesa / Hogares | ~$3,000 | Un usuario, un equipo |
| **2000s** | Laptop | Móvil / Personal | ~$1,500 | Computación portátil |
| **2010s** | Smartphone | Bolsillo / Individual | ~$500 | Computación ubicua |
| **2020s** | MCU IoT | Chip / Objetos | $2–5 | Computación invisible |

> **Insight:** La tendencia es hacia la **miniaturización**, **democratización** y **ubiquitación** de la computación.

---

## ¿Qué es un Microcontrolador (MCU)?

> **Definición:** Una computadora completa en un solo chip que integra CPU, memoria, puertos de entrada/salida y periféricos.

### Arquitectura Interna de un MCU

<table>
<tr>
<td width="50%">

#### 🧠 NÚCLEO DE PROCESAMIENTO
| Componente | Función |
|------------|---------|
| **CPU** | Ejecuta instrucciones del programa |
| **Clock** | Marca el ritmo de ejecución (MHz) |

#### 💾 MEMORIA
| Tipo | Función | Capacidad Típica |
|------|---------|------------------|
| **Flash/ROM** | Almacena el programa | 32 KB - 4 MB |
| **RAM** | Memoria volátil temporal | 2 KB - 520 KB |

#### 🔌 PUERTOS DE E/S
| Tipo | Función |
|------|---------|
| **GPIO** | Pines digitales de propósito general |
| **ADC** | Lectura de señales analógicas |
| **DAC** | Generación de señales analógicas |
| **PWM** | Control de intensidad/velocidad |

</td>
<td width="50%">

#### 📡 COMUNICACIÓN Y PERIFÉRICOS
| Protocolo | Uso Principal |
|-----------|---------------|
| **UART** | Comunicación serial (TX/RX) |
| **I2C** | Múltiples sensores en 2 cables |
| **SPI** | Alta velocidad con dispositivos |
| **Timers** | Control de tiempo y eventos |
| **WiFi/BLE*** | Conectividad inalámbrica |

\*En MCUs avanzados (ESP32, ESP8266)

### ⚡ Flujo de Datos en un MCU

<div style="background: #f8fafc; padding: 20px; border-radius: 10px;">

#### 🔽 ENTRADA → PROCESAMIENTO → SALIDA

| Paso | Componente | Función |
|:----:|:-----------|:--------|
| 1 | **GPIO** | Lee señales digitales |
| 2 | **ADC** | Convierte analógico → digital |
| 3 | **CPU** | Procesa los datos |
| 4 | **RAM** | Almacena temporalmente |
| 5 | **GPIO** | Actúa sobre el mundo físico |

#### 📡 Comunicación

| Protocolo | Uso |
|:----------|:-----|
| **I2C/SPI/UART** | Sensores y displays |
| **WiFi/BLE** | Conectividad inalámbrica |

</div>

**Clave:** El MCU es el "cerebro" que conecta lo físico (sensores/actuadores) con lo digital (programa/conectividad).

</td>
</tr>
</table>

---

## Microcontrolador vs Microprocesador

<table>
<tr>
<td width="50%">

### Microcontrolador (MCU)
**"Sistema completo en un chip"**

✅ **Ventajas:**
- Todo integrado (memoria, I/O)
- Bajo consumo energético
- Costo muy bajo ($2-10)
- Ideal para tareas dedicadas
- Arranque inmediato

⚠️ **Limitaciones:**
- Memoria limitada (KB)
- Velocidad moderada (MHz)
- No ejecuta sistemas operativos completos

**Ejemplos:** ESP32, Arduino, STM32

</td>
<td width="50%">

### Microprocesador (MPU)
**"Solo el cerebro, necesita componentes externos"**

✅ **Ventajas:**
- Alta velocidad (GHz)
- Memoria ampliable (GB)
- Ejecuta sistemas operativos completos
- Multitarea avanzada
- Flexible y potente

⚠️ **Limitaciones:**
- Requiere RAM, storage externos
- Mayor consumo energético
- Costo elevado ($50-500+)
- Más complejo de implementar

**Ejemplos:** Intel i7, AMD Ryzen, ARM Cortex-A

</td>
</tr>
</table>

---

## Arduino: La Revolución del Hardware Libre

<table>
<tr>
<td width="50%">

### ¿Qué es Arduino?
Plataforma de desarrollo open-source que combina:
- **Hardware:** Placas con microcontroladores
- **Software:** IDE simple y accesible
- **Comunidad:** Millones de usuarios y proyectos

### Ventajas
| Aspecto | Beneficio |
|---------|-----------|
| Curva de aprendizaje | Muy suave |
| Documentación | Extensa y gratuita |
| Costo | $5-25 USD |
| Bibliotecas | Miles disponibles |
| Comunidad | Global y activa |
| Hardware | Open-source |

</td>
<td width="50%">

### Limitaciones a Considerar

| Aspecto | Limitación |
|---------|------------|
| Conectividad | Sin WiFi nativo* |
| Memoria | 2 KB RAM, 32 KB Flash |
| Procesamiento | Un solo núcleo |
| Velocidad | 16 MHz |

*Excepto modelos específicos como Arduino MKR WiFi

### ¿Cuándo usar Arduino?
- ✅ Aprendizaje de electrónica
- ✅ Prototipos rápidos
- ✅ Proyectos simples sin conectividad
- ✅ Interfaz con muchos sensores
- ❌ Proyectos IoT con WiFi (usar ESP32)

</td>
</tr>
</table>

---

## Familia Arduino: Opciones para Cada Proyecto

| Placa | MCU | Flash | RAM | Digital I/O | Analógico | Precio | Uso Ideal |
|-------|-----|-------|-----|-------------|-----------|--------|-----------|
| **Uno** | ATmega328P | 32KB | 2KB | 14 | 6 | $25 | Aprendizaje estándar |
| **Nano** | ATmega328P | 32KB | 2KB | 14 | 8 | $20 | Espacios reducidos |
| **Mega** | ATmega2560 | 256KB | 8KB | 54 | 16 | $45 | Muchos pines I/O |
| **Micro** | ATmega32U4 | 32KB | 2.5KB | 20 | 12 | $20 | USB nativo |
| **Leonardo** | ATmega32U4 | 32KB | 2.5KB | 20 | 12 | $22 | Emular teclado/mouse |

---

## Arduino UNO: La Placa de Referencia

### 📊 Especificaciones Técnicas

| Parámetro | Valor |
|-----------|-------|
| **Procesador** | ATmega328P @ 16 MHz |
| **Memoria Flash** | 32 KB |
| **SRAM** | 2 KB |
| **EEPROM** | 1 KB |
| **Voltaje operación** | 5V |
| **Voltaje entrada** | 7-12V recomendado |

### 🔌 Distribución de Pines

#### Digitales (0-13)
| Pines | Características |
|-------|-----------------|
| 0, 1 | RX/TX (Serial) |
| 3, 5, 6, 9, 10, 11 | PWM (~) |
| 2, 3 | Interrupciones externas |
| 13 | LED integrado |

#### Analógicos (A0-A5)
| Característica | Valor |
|----------------|-------|
| Canales ADC | 6 |
| Resolución | 10-bit (0-1023) |
| Voltaje ref | 0-5V |

#### Alimentación
| Pin | Voltaje | Uso |
|-----|---------|-----|
| 3.3V | 3.3V | Sensores baja potencia |
| 5V | 5V | Circuitos estándar |
| GND | 0V | Tierra |
| Vin | 7-12V | Alimentación externa |

---

## ESP32: El Estándar de Facto para IoT

<table>
<tr>
<td width="55%">

### ¿Por qué ESP32 domina IoT?

| Característica | Especificación |
|----------------|----------------|
| **CPU** | Xtensa dual-core @ 240 MHz |
| **RAM** | 520 KB |
| **Flash** | 4 MB (externa) |
| **WiFi** | 802.11 b/g/n (2.4 GHz) |
| **Bluetooth** | Classic + BLE |
| **GPIO** | 34 pines programables |
| **ADC** | 18 canales (12-bit) |
| **DAC** | 2 canales (8-bit) |
| **Precio** | $3-8 USD |

### Ventajas Clave
- 🌐 **Conectividad integrada:** WiFi + BT sin shield adicional
- ⚡ **Potencia:** Dual-core a 240 MHz
- 💰 **Precio:** Más barato que Arduino con WiFi shield
- 🔋 **Eficiencia:** Modos de bajo consumo
- 📡 **Alcance:** Amplia comunidad y ejemplos

</td>
<td width="45%">

### ESP32 vs Competencia

<div style="background: #f8fafc; padding: 20px; border-radius: 10px;">

#### Comparativa Precio/Funcionalidad

| Plataforma | Precio | Relación Valor |
|:-----------|:------:|:--------------:|
| Arduino UNO + WiFi Shield | $45 | ⭐⭐ |
| Arduino MKR WiFi 1010 | $35 | ⭐⭐⭐ |
| Raspberry Pi Zero W | $15 | ⭐⭐⭐⭐ |
| **ESP32 DevKit** | **$5** | ⭐⭐⭐⭐⭐ **Winner!** |

<div style="background: #d1fae5; padding: 12px; border-radius: 8px; margin-top: 10px; text-align: center;">

**💡 ESP32 ofrece 3-5x más valor que alternativas tradicionales**

</div>

</div>

### Casos de Uso Ideal
- Sensores conectados a la nube
- Automatización del hogar
- Wearables
- Prototipos IoT rápidos
- Producción en masa

</td>
</tr>
</table>

---

## Raspberry Pi: Microcomputador vs Microcontrolador

<table>
<tr>
<td width="50%">

### Raspberry Pi 4: Un Computador Completo

| Especificación | Valor |
|----------------|-------|
| **CPU** | ARM Cortex-A72 (quad-core) 1.5 GHz |
| **RAM** | 1 / 2 / 4 / 8 GB |
| **Almacenamiento** | microSD |
| **Sistema Operativo** | Linux (Raspberry Pi OS) |
| **WiFi** | Dual-band 802.11ac |
| **Bluetooth** | 5.0 BLE |
| **Ethernet** | Gigabit |
| **GPIO** | 40 pines HAT |
| **Precio** | $35-75 USD |

### Capacidades Únicas
- Ejecuta Linux completo
- Soporte para múltiples lenguajes
- Interfaz gráfica
- Puertos USB, HDMI, Ethernet
- Ideal como gateway IoT

</td>
<td width="50%">

### Diferencia Fundamental

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 🔧 MCU (ESP32/Arduino)

| Característica | Valor |
|:---------------|:------|
| Ejecución | Programa único, bucle infinito |
| Respuesta | Tiempo real |
| Consumo | Bajo (mA) |
| Arranque | Instantáneo (< 1s) |
| **Ideal para** | Control sensores/actuadores |

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px;">

#### 🖥️ Microcomputador (Raspberry Pi)

| Característica | Valor |
|:---------------|:------|
| Sistema | OS completo (Linux) |
| Capacidad | Multitarea, multiusuario |
| Consumo | Mayor (600+ mA) |
| Arranque | ~30 segundos |
| **Ideal para** | Gateway, servidor, procesamiento |

</div>

</div>

</td>
</tr>
</table>

---

## Guía de Selección: ¿Qué Placa Elegir?

<table>
<tr>
<td width="33%">

### 🎓 Arduino UNO
**Elige cuando:**
- Estás aprendiendo electrónica
- Necesitas muchas bibliotecas
- Proyecto simple sin WiFi
- Prototipo rápido de bajo riesgo

**No elijas si:**
- Necesitas conectividad WiFi
- Requieres procesamiento intensivo
- El espacio es crítico

</td>
<td width="33%">

### 🌐 ESP32
**Elige cuando:**
- Proyecto IoT con WiFi/Bluetooth
- Necesitas buena potencia ($5)
- Batería con conectividad
- Producción en masa
- Muchos pines I/O

**No elijas si:**
- Necesitas Linux completo
- Requieres interfaz gráfica
- Procesamiento de video/audio pesado

</td>
<td width="34%">

### 🖥️ Raspberry Pi
**Elige cuando:**
- Necesitas Linux completo
- Gateway/bridge IoT
- Procesamiento de datos pesado
- Múltiples interfaces (USB, HDMI)
- Servidor web local

**No elijas si:**
- Energía es limitada (batería)
- Necesitas respuesta en tiempo real
- Costo debe ser mínimo

</td>
</tr>
</table>

### Árbol de Decisión Rápido

<div style="background: #f8fafc; padding: 20px; border-radius: 10px;">

| Pregunta | Respuesta SÍ | Respuesta NO |
|:---------|:-------------|:-------------|
| **¿Necesitas Linux?** | → Raspberry Pi | Continuar... |
| **¿Necesitas WiFi?** | → ESP32 (mejor valor) | Continuar... |
| **¿Es para aprender?** | → Arduino UNO | → ESP32 (más potente) |

<div style="background: #fef3c7; padding: 12px; border-radius: 8px; margin-top: 15px; text-align: center;">

**🎯 Recomendación general:** ESP32 es la mejor opción para la mayoría de proyectos IoT

</div>

</div>

---

## Hardware IoT en Colombia 🇨🇴

<table>
<tr>
<td width="50%">

### Proveedores Locales

**Tiendas Online Colombianas:**
| Tienda | URL | Especialidad |
|--------|-----|--------------|
| HeTica | hetica.co | Kits educativos |
| MC-Hackers | mchackers.co | Componentes |
| Robotizados | robotizados.com | Robótica |
| Electrón Panamericana | electronpanamericana.com | Industrial |

**Tiendas Físicas (Bogotá):**
- 📍 **San Alejo** (Calle 22) - Zona de electrónica
- 📍 **El Cerezo** (Calle 22) - Componentes
- 📍 **Tecnoparts** (Chapinero) - Profesional
- 📍 **Rapsodia** (Chapinero) - Maker

**Marketplaces:**
- MercadoLibre
- Linio
- Amazon (importación)

</td>
<td width="50%">

### Precios Aproximados 2026 (COP)

| Componente | Local | Importado | Notas |
|------------|-------|-----------|-------|
| Arduino Uno Original | $120K | $80K | Clones: $25K |
| ESP32 DevKit | $45K | $30K | Mejor valor |
| Raspberry Pi 4 (4GB) | $280K | $220K | Escasez ocasional |
| DHT11 | $12K | $8K | Sensor temperatura |
| Kit IoT Básico (10 sensores) | $80K | $50K | Local + rápido |
| Protoboard 830 pts | $15K | $8K | Esencial |
| Jumpers M-M/M-F | $10K | $5K | 40 piezas |

💡 **Consejo:** Comprar local para primeros proyectos (soporte, garantía). Importar para producción en masa.

</td>
</tr>
</table>

---

## Tu Primer Kit IoT: Recomendación

### Kit Básico (~$150K - $200K COP)

<table>
<tr>
<td width="33%">

**🖥️ Microcontrolador**
- ESP32 DevKit V1: ~$45K
- Cable microUSB: incluido

**Ventaja:** WiFi integrado desde el inicio

</td>
<td width="33%">

**🌡️ Sensores (5 esenciales)**
- DHT11 (Temp/Hum): ~$8K
- HC-SR04 (Distancia): ~$8K
- LDR (Luz): ~$2K
- PIR HC-SR501 (Movimiento): ~$8K
- BMP280 (Presión): ~$10K

</td>
<td width="34%">

**⚡ Actuadores y Componentes**
- LED pack (5 colores): ~$5K
- Buzzer pasivo: ~$3K
- Servo SG90: ~$12K
- Relé 5V: ~$8K
- Protoboard 830: ~$15K
- Jumpers (40x3): ~$15K
- Resistencias pack: ~$8K
- LCD 16x2 I2C: ~$18K

</td>
</tr>
</table>

### Próximas Compras Sugeridas
| Prioridad | Componente | Precio | Proyecto |
|-----------|------------|--------|----------|
| Alta | Módulo relay 4 canales | $15K | Control luces |
| Alta | Sensor de agua | $8K | Detector fugas |
| Media | Motor DC + puente H | $20K | Robótica básica |
| Media | RFID RC522 | $12K | Control acceso |
| Baja | Cámara ESP32-CAM | $35K | Visión computacional |

---

## Sensores: Los "Sentidos" de IoT

### Taxonomía de Sensores por Función - Parte 1

#### 🌡️ AMBIENTE
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **DHT11/DHT22** | Temp + Humedad | Invernaderos, clima |
| **BMP280** | Presión + Altitud | Estación meteorológica |
| **MQ-2/MQ-135** | Gas, humo, CO2 | Calidad del aire |

#### 📍 POSICIÓN Y MOVIMIENTO
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **GPS/GNSS** | Ubicación global | Rastreo, navegación |
| **MPU6050** | Acel + Giro | Robótica, drones |
| **HC-SR04** | Distancia | Parking, nivel |
| **PIR HC-SR501** | Movimiento | Seguridad |

#### 💡 ÓPTICOS Y LUMINOSOS
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **LDR** | Intensidad luz | Cortinas automáticas |
| **TSL2561** | Lux visible | Iluminación inteligente |
| **Sensor UV** | Radiación UV | Alerta solar |

#### 🔊 SONIDO Y VIBRACIÓN
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **Micrófono MEMS** | Sonido | Asistente voz |
| **Detector de ruido** | Decibeles | Alerta ambiental |
| **Sensor vibración** | Vibraciones | Mantenimiento predictivo |

Continúa en Parte 2...

---

## Sensores: Los "Sentidos" de IoT - Parte 2

### Taxonomía de Sensores por Función - Parte 2

#### 👁️ PRESENCIA Y PROXIMIDAD
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **Reed switch** | Campo magnético | Puertas abiertas |
| **HC-SR04** | Distancia 2-400cm | Estacionamiento |
| **APDS-9960** | Gestos, proximidad | Interfaz gestual |

#### 💧 LÍQUIDOS Y FLUIDOS
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **YL-69** | Humedad suelo | Riego automático |
| **Sensor nivel** | Nivel líquido | Tanques, cisternas |
| **YF-S201** | Caudal (L/min) | Medidor consumo agua |

#### 🔥 TEMPERATURA ESPECIALIZADA
| Sensor | Rango | Característica |
|--------|-------|----------------|
| **DS18B20** | -55°C a 125°C | Waterproof |
| **MLX90614** | -70°C a 380°C | No contacto (IR) |

#### 👆 TÁCTIL Y ELÉCTRICOS
| Sensor | Mide | Aplicación |
|--------|------|------------|
| **Botón pulsador** | ON/OFF | Control manual |
| **Touch capacitivo** | Tocar | Interruptores modernos |
| **ACS712** | Corriente AC/DC | Monitoreo energía |

> **💡 Consejo:** Empezar con sensores digitales (DHT, BMP, MPU) para mayor precisión. Analógicos (LDR, YL-69) requieren calibración.

---

## Sensores Esenciales para Principiantes

| Sensor | Mide | Interfaz | Precio | Precisión | Uso Común |
|--------|------|----------|--------|-----------|-----------|
| **DHT11** | Temp + Humedad | Digital | $2-3 | ±2°C, ±5% | Invernaderos, hogar |
| **DHT22** | Temp + Humedad | Digital | $4-6 | ±0.5°C, ±2-5% | Mejor que DHT11 |
| **DS18B20** | Temperatura | 1-Wire | $2-3 | ±0.5°C | Líquidos, preciso |
| **HC-SR04** | Distancia | Digital | $2-3 | ±3mm | Estacionamiento, nivel |
| **PIR HC-SR501** | Movimiento | Digital | $2-3 | 7m, 120° | Seguridad, ahorro energía |
| **BMP280** | Presión + Altitud | I2C/SPI | $3-5 | ±1 hPa | Estación meteorológica |
| **MPU6050** | Acel + Giro | I2C | $3-5 | 16-bit | Robótica, wearables |
| **MQ-2** | Gas/Humo | Analógico | $3-4 | Cualitativo | Detección fugas |
| **LDR** | Luz | Analógico | $0.5-1 | Variable | Cortinas automáticas |
| **YL-69** | Humedad suelo | Analógico | $2-3 | Cualitativo | Riego automático |

---

## DHT11: Sensor de Temperatura y Humedad

<table>
<tr>
<td width="50%">

### Especificaciones Técnicas

| Parámetro | Valor |
|-----------|-------|
| **Rango temperatura** | 0°C a 50°C |
| **Precisión temperatura** | ±2°C |
| **Rango humedad** | 20% a 80% RH |
| **Precisión humedad** | ±5% RH |
| **Tiempo de respuesta** | 1 segundo |
| **Voltaje** | 3.3V - 5V |
| **Corriente** | 0.5mA - 2.5mA |
| **Interfaz** | Digital (single-wire) |

### Conexión al ESP32

| DHT11 | Conexión |
|-------|----------|
| VCC | 3.3V o 5V |
| DATA | GPIO4 + Resistencia 10KΩ a VCC |
| NC | No conectar |
| GND | GND |

⚠️ **Nota:** La resistencia pull-up (10KΩ) es esencial para comunicación estable.

</td>
<td width="50%">

### Diagrama de Conexión

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #dbeafe; padding: 15px; border-radius: 8px;">

#### ESP32 → DHT11

| ESP32 | → | DHT11 |
|:-----:|:-:|:-----|
| 3.3V | → | VCC |
| GND | → | GND |
| GPIO4 | → | DATA |
| *(con pull-up 10KΩ a 3.3V)* | | |

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 8px;">

#### ⚠️ Nota Importante

La resistencia pull-up de **10KΩ** es esencial para comunicación estable. Conectar entre DATA y VCC.

</div>

</div>

### Código Arduino Básico
```cpp
#include "DHT.h"
#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  Serial.println("Temp: " + String(temp) + "°C");
  Serial.println("Hum: " + String(hum) + "%");
  delay(2000);
}
```

</td>
</tr>
</table>

---

## Actuadores: Actuando sobre el Mundo

### Taxonomía de Actuadores por Función

#### 💡 ILUMINACIÓN
| Actuador | Características | Uso Típico |
|----------|----------------|------------|
| **LED simple** | 5mm, diversos colores | Indicador estado |
| **LED RGB** | 4 pines (PWM) | Efectos de color |
| **Tira WS2812B** | Neopixel, direccionable | Iluminación decorativa |
| **LCD 16x2** | Caracteres alfanuméricos | Mostrar datos |
| **OLED 128x64** | Alto contraste, bajo consumo | Gráficos |

#### 🔊 SONIDO
| Actuador | Características | Uso Típico |
|----------|----------------|------------|
| **Buzzer activo** | Genera tono fijo | Alarmas simples |
| **Buzzer pasivo** | Requiere PWM | Melodías variables |
| **Altavoz 8Ω** | Con amplificador | Audio, música |

#### ⚙️ MOVIMIENTO MECÁNICO
| Actuador | Características | Uso Típico |
|----------|----------------|------------|
| **Servo SG90** | 0°-180°, 5V | Brazos robóticos |
| **Motor DC** | Velocidad variable | Vehículos, ventiladores |
| **Motor paso a paso** | Posición precisa | Impresoras 3D, CNC |
| **Driver L298N** | Control 2 motores DC | Robots diferenciales |

#### ⚡ CONMUTACIÓN DE POTENCIA
| Actuador | Características | Uso Típico |
|----------|----------------|------------|
| **Relé 5V** | 10A @ 250V AC | Luces, electrodomésticos |
| **MOSFET IRFZ44N** | 49A @ 55V | Motores DC, LEDs |
| **Transistor TIP120** | Darlington, 5A | Cargas medias |

### 🔌 Niveles de Control de Potencia

| Nivel | Componente | Capacidad | Uso Típico |
|:-----:|:-----------|:----------|:-----------|
| **Directo** | LED | ≤20mA | Indicadores |
| **Transistor BJT** | 2N2222, BC547 | ≤500mA | Buzzer, ventilador |
| **MOSFET** | IRFZ44N | ≤5A | Motores DC, tiras LED |
| **Relé** | Módulo 5V | ≤10A @ 250V AC | Lámparas, electrodomésticos |

> **⚠️ Regla de Oro:** Nunca conectar cargas de potencia directamente al GPIO. Usar transistor/MOSFET/relé según la corriente requerida.

---

## Relé: Controlando Alto Voltaje con Bajo Voltaje

<table>
<tr>
<td width="50%">

### ¿Qué es un Relé?

Interruptor electromecánico controlado electrónicamente que permite:
- **Entrada:** Señal de 3.3V/5V DC del microcontrolador
- **Salida:** Control de 110V/220V AC o hasta 30V DC
- **Aislamiento:** Separación galvánica entre circuitos

### Módulo Relé 5V

| Pin | Función |
|-----|---------|
| **VCC** | Alimentación 5V |
| **GND** | Tierra |
| **IN** | Señal de control (GPIO) |
| **NO** | Normalmente Abierto |
| **NC** | Normalmente Cerrado |
| **COM** | Común (línea AC/DC) |

### Estados del Relé
| IN (GPIO) | Estado | COM conectado a |
|-----------|--------|-----------------|
| LOW | Apagado | NC |
| HIGH | Encendido | NO |

</td>
<td width="50%">

### Conexión: Controlando una Lámpara con Relé

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div>

#### Circuito de Control (Bajo Voltaje)

| ESP32 | → | Módulo Relé |
|:-----:|:-:|:------------|
| 5V | → | VCC |
| GND | → | GND |
| GPIO5 | → | IN |

#### Circuito de Potencia (Alto Voltaje)

| Fuente | → | Relé | → | Carga |
|:-------|:-:|:-----|:-:|:------|
| Fase 110V | → | COM | | |
| | | NO* | → | Lámpara |
| Neutro | → | | → | Lámpara |

*NO = Normalmente Abierto

</div>

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### ⚠️ Advertencias de Seguridad

- **Nunca** tocar terminales cuando está energizado
- Usar **caja aislante** para el relé
- Verificar capacidad de corriente (usualmente 10A)
- Asegurar conexiones firmes
- Usar fusible de protección

<div style="text-align: center; font-size: 2em; margin: 10px 0;">
⚡ 🛡️ ⚡
</div>

</div>

</div>

⚠️ **ADVERTENCIA DE SEGURIDAD:**
- Nunca tocar terminales cuando está energizado
- Usar caja aislante para el relé
- Verificar capacidad de corriente ( usualmente 10A)

</td>
</tr>
</table>

---

## Protocolos de Comunicación: El "Idioma" del Hardware

### Protocolos Seriales Comparados

| Protocolo | Cables | Dispositivos | Velocidad | Características |
|-----------|--------|--------------|-----------|-----------------|
| **UART** | 2 (TX/RX) | 1 a 1 | Hasta 1 Mbps | Punto a punto |
| **I2C** | 2 (SDA/SCL) | Hasta 127 | 100-400 KHz | Bus compartido |
| **SPI** | 4+ | Hasta 4* | Hasta 50 Mbps | Alta velocidad |
| **1-Wire** | 1 | Hasta 100 | 16 Kbps | Distancia larga |

\*Con selectores de chip adicionales

### ¿Cuándo Usar Cada Protocolo?

| Situación | Protocolo |
|-----------|-----------|
| Sensor único simple | GPIO digital/analógico |
| Comunicación MCU/PC | UART |
| Múltiples sensores mismo bus | I2C |
| Alta velocidad | SPI |
| Distancia larga (>5m) | RS485, 1-Wire |

> **💡 Regla:** I2C para múltiples sensores con pocos pines. SPI para velocidad máxima. UART para comunicación con otros microcontroladores.

---

## I2C: El Protocolo Estrella de IoT (1/2)

### ¿Por qué I2C es tan popular?

| Característica | Beneficio |
|----------------|-----------|
| **Solo 2 cables** | SDA (datos) + SCL (reloj) |
| **Múltiples dispositivos** | Hasta 127 en mismo bus |
| **Direccionamiento** | Cada dispositivo tiene ID única |
| **Velocidad** | 100-400 KHz (suficiente para sensores) |
| **Arquitectura** | Un maestro, múltiples esclavos |

### Funcionamiento Básico

1. **Maestro** (ESP32/Arduino) inicia comunicación
2. Envía **dirección** del esclavo + modo (leer/escribir)
3. **Esclavo** responde con ACK (acknowledge)
4. Se transfiere **dato** (8 bits a la vez)
5. Proceso se repite hasta finalizar

### Dispositivos Comunes I2C
| Dirección | Dispositivo |
|-----------|-------------|
| 0x27 / 0x3F | LCD 16x2 (I2C adapter) |
| 0x3C / 0x3D | OLED Display 128x64 |
| 0x76 / 0x77 | BMP280 (presión atmosférica) |
| 0x68 | MPU6050 (acelerómetro) |
| 0x40 | PCA9685 (driver PWM 16 canales) |
| 0x57 | AT24C32 (EEPROM 32Kb) |

> **⚠️ Importante:** Siempre conectar resistencias pull-up (4.7KΩ - 10KΩ) en SDA y SCL a VCC.

---

## I2C: El Protocolo Estrella de IoT (2/2)

### Diagrama de Conexión I2C

<div style="background: #dbeafe; padding: 15px; border-radius: 8px;">

#### ESP32 (Maestro) ↔ Dispositivos I2C (Esclavos)

| ESP32 | → | Todos los dispositivos |
|:-----:|:-:|:---------------------|
| 3.3V | → | VCC |
| GND | → | GND |
| GPIO21 | → | SDA |
| GPIO22 | → | SCL |

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 8px; margin-top: 10px;">

#### Dispositivos en el Bus I2C

| Dispositivo | Dirección |
|:-----------|:--------:|
| BMP280 | 0x76 |
| OLED Display | 0x3C |
| LCD 16x2 | 0x27 |

*Nota: Usar resistencias pull-up de 4.7KΩ a 10KΩ en SDA y SCL*

</div>

### Código Básico Arduino

```cpp
#include <Wire.h>  // Librería I2C

void setup() {
  Wire.begin();           // Iniciar I2C (maestro)
  Serial.begin(115200);
}

void loop() {
  // Escribir al dispositivo
  Wire.beginTransmission(0x76); // Dirección BMP280
  Wire.write(0xF4);             // Registro ctrl
  Wire.write(0x27);             // Valor
  Wire.endTransmission();

  // Leer del dispositivo
  Wire.requestFrom(0x76, 2);    // Leer 2 bytes
  while(Wire.available()) {
    byte data = Wire.read();
    Serial.println(data, HEX);
  }
  delay(1000);
}
```

### Escáner de Dispositivos I2C
```cpp
// Escanea 0x03 a 0x77 encontrando dispositivos
for(byte addr = 1; addr < 127; addr++) {
  Wire.beginTransmission(addr);
  if(Wire.endTransmission() == 0) {
    Serial.print("Dispositivo encontrado: 0x");
    Serial.println(addr, HEX);
  }
}
```

---

## Anatomía de un Proyecto IoT Completo (1/2)

### 🔽 CAPA DE PERCEPCIÓN (Sensores)
| Componente | Función | Ejemplos |
|------------|---------|----------|
| **Sensores** | Capturan datos del mundo físico | DHT11, LDR, PIR, HC-SR04 |
| **Frecuencia** | Cada 1-60 segundos según necesidad | Temperatura: 60s, Movimiento: 0.5s |
| **Conexión** | GPIO, ADC, I2C, SPI | Directos al MCU |

### 📊 CAPA DE PROCESAMIENTO (Edge)
| Componente | Función | ESP32 |
|------------|---------|-------|
| **MCU** | Cerebro del sistema | Dual-core 240 MHz |
| **Memoria** | Buffer temporal | 520 KB RAM |
| **Lógica** | Decisiones locales | If temp > 30 → encender fan |
| **Filtrado** | Eliminar ruido | Promedio móvil |
| **Compresión** | Ahorrar ancho de banda | JSON compacto |

### 📤 CAPA DE ACTUACIÓN
| Componente | Función | Ejemplos |
|------------|---------|----------|
| **Relé** | Interruptor 110V/220V | Luces, electrodomésticos |
| **Servo** | Posición angular | Persianas, válvulas |
| **LEDs** | Indicadores visuales | Alertas, estado |
| **Display** | Información local | OLED, LCD |
| **Buzzer** | Alertas sonoras | Alarmas |

---

## Anatomía de un Proyecto IoT Completo (2/2)

### 📱 CAPA USUARIO
| Interfaz | Uso | Ejemplo |
|----------|-----|---------|
| **Móvil** | Control remoto, notificaciones | App Android/iOS |
| **Web** | Dashboard, configuración | React, Vue |
| **Voice** | Asistente por voz | Alexa, Google Home |
| **SMS** | Alertas críticas | Twilio, msg91 |

### 🌐 CAPA DE CONECTIVIDAD
| Protocolo | Uso | Alcance |
|-----------|-----|---------|
| **WiFi** | Conexión a router | Dentro del hogar |
| **BLE** | Comunicación móvil | 10-100m |
| **MQTT** | Mensajes ligeros | Cloud |
| **HTTP/REST** | API estándar | Web services |

### ☁️ CAPA NUBE (Cloud)
| Plataforma | Características |
|------------|----------------|
| **ThingsBoard** | Open-source, dashboards |
| **AWS IoT** | Escalable, integración AWS |
| **Blynk (plataforma no-code para crear apps móviles IoT)** | Fácil, móvil primero |
| **Firebase** | Realtime database |

### 📐 Arquitectura en Capas

<div style="background: #f8fafc; padding: 15px; border-radius: 10px;">

<div style="text-align: center; background: #1e40af; color: white; padding: 8px; border-radius: 6px; margin-bottom: 8px;">
📱 USUARIO (App/Web/Voz)
</div>

<div style="text-align: center; background: #3b82f6; color: white; padding: 8px; border-radius: 6px; margin-bottom: 8px;">
☁️ NUBE (MQTT/HTTP)
</div>

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 12px; text-align: center; margin-bottom: 8px;">
<div style="background: #dbeafe; padding: 8px; border-radius: 6px; font-size: 0.85em;">📡 WiFi</div>
<div style="background: #fef3c7; padding: 8px; border-radius: 6px; font-size: 0.85em;">📊 ESP32</div>
<div style="background: #f0fdf4; padding: 8px; border-radius: 6px; font-size: 0.85em;">⚡ Actuadores</div>
</div>

<div style="text-align: center; background: #22c55e; color: white; padding: 8px; border-radius: 6px; font-size: 0.9em;">
🌡️ SENSORES
</div>

</div>

### 🔄 Flujo de Datos

| Flujo | Descripción |
|:------|:-----------|
| Sensor → ADC → MCU → WiFi → MQTT → Cloud | Datos hacia la nube |
| Cloud → App → Usuario | Visualización y control |
| MCU → Actuador | Decisión local |

### 📐 Diseño por Capas: Ventajas

| Enfoque | Beneficio |
|---------|-----------|
| **Desacoplado** | Cambiar sensor sin afectar cloud |
| **Escalable** | Agregar 10 sensores = mismo código |
| **Resiliente** | Fallo de WiFi → sigue funcionando localmente |
| **Mantenible** | Debug por capas, no todo junto |

---

## Demo Práctica: ESP32 + DHT11 (1/2)

### Diagrama de Conexión

| ESP32 | → | DHT11 |
|:-----:|:-:|:-----|
| 3.3V | → | VCC |
| GND | → | GND |
| GPIO4 | → | DATA |
| *(con pull-up 10KΩ)* | | |

### Lista de Materiales
| Componente | Cantidad |
|------------|----------|
| ESP32 DevKit | 1 |
| DHT11 | 1 |
| Resistencia 10KΩ | 1 |
| Cables jumper | 4 |
| Protoboard | 1 |

---

## Demo Práctica: ESP32 + DHT11 (2/2)

### Código Completo (Arduino)

```cpp
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Error leyendo DHT11!");
    return;
  }

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("°C  Hum: ");
  Serial.print(h);
  Serial.println("%");
}
```

---

## Actividad Práctica: Identificación de Componentes

### Instrucciones (30 minutos)

<table>
<tr>
<td width="50%">

#### Parte 1: Exploración (15 min)
En equipos de 3 personas:

1. **Identificar** 5 sensores diferentes del kit
2. **Clasificar** cada sensor por tipo:
   - Ambiente (temperatura, humedad)
   - Posición (distancia, movimiento)
   - Luz
   - Otros

3. **Investigar** el protocolo de comunicación:
   - Digital (GPIO)
   - Analógico (ADC)
   - I2C
   - SPI
   - 1-Wire

4. **Buscar** la hoja de datos (datasheet) de cada sensor

</td>
<td width="50%">

#### Parte 2: Propuesta de Proyecto (15 min)

Diseñar un proyecto IoT que use **mínimo 3 sensores** y **1 actuador**.

**Ejemplos de proyectos para contexto colombiano:**

| Proyecto | Sensores | Actuador | Aplicación |
|----------|----------|----------|------------|
| 🌾 **Invernadero** | DHT11, LDR, Humedad suelo | Bomba agua | Agricultura |
| 🏠 **Alarma** | PIR, Magnético, LDR | Sirena/Buzzer | Seguridad |
| 💧 **Fugas** | Agua, Humedad | Válvula/Válvula | Prevención |
| 🚗 **Parking** | Ultrasónico, LDR | Display LED | Control |
| 🌡️ **Incubadora** | DHT22 | Calefactor | Avicultura |

</td>
</tr>
</table>

### Entregable

Crear una tabla como esta:

| Sensor | Tipo | Protocolo | Proyecto Propuesto | Rol en el Proyecto |
|--------|------|-----------|-------------------|-------------------|
| DHT11 | Ambiente | Digital | Invernadero | Monitorear clima |
| LDR | Luz | Analógico | Invernadero | Controlar iluminación |
| YL-69 | Humedad | Analógico | Invernadero | Activar riego |
| Relé 5V | Actuador | Digital | Invernadero | Controlar bomba |

---

## Resumen: Conceptos Clave de la Clase

<table>
<tr>
<td width="25%">

### Microcontrolador
Computadora completa en un chip: CPU, memoria, I/O, comunicación.

**Ejemplos:** ESP32, Arduino, STM32

</td>
<td width="25%">

### Arduino
Plataforma de aprendizaje con gran comunidad. Fácil pero limitado en conectividad.

**Uso:** Prototipos, aprendizaje

</td>
<td width="25%">

### ESP32
MCU con WiFi y Bluetooth integrados. Mejor relación costo/beneficio para IoT.

**Uso:** IoT conectado, producción

</td>
<td width="25%">

### Raspberry Pi
Microcomputador con Linux. Potente pero más complejo y consumo alto.

**Uso:** Gateway, servidor, procesamiento

</td>
</tr>
</table>

<table>
<tr>
<td width="33%">

### Sensores
Capturan datos del mundo físico: temperatura, luz, movimiento, distancia, etc.

**Tipos:** DHT11, PIR, HC-SR04, LDR, BMP280

</td>
<td width="33%">

### Actuadores
Ejecutan acciones físicas: LEDs, motores, relés, displays, buzzers.

**Tipos:** Relé (alto voltaje), Servo (posición), LED (indicación)

</td>
<td width="34%">

### Protocolos
"Idiomas" de comunicación entre dispositivos.

**Tipos:** GPIO (digital), I2C (multi-dispositivo), SPI (velocidad), UART (punto a punto)

</td>
</tr>
</table>

---

## Tarea: Preparación para la Próxima Clase

<table>
<tr>
<td width="50%">

### Instalación de Software

1. **Arduino IDE**
   - Descargar de: arduino.cc
   - Instalar versión 1.8.x o 2.x
   - Configurar ESP32 (ver guía)

2. **Soporte ESP32**
   - File → Preferences → Additional Board URLs
   - Agregar: `https://dl.espressif.com/dl/package_esp32_index.json`
   - Tools → Board → Boards Manager → ESP32

3. **Librerías necesarias**
   - DHT sensor library (Adafruit)
   - Adafruit Unified Sensor

### Recursos de Apoyo
- 📺 Tutorial instalación: youtube.com/arduino
- 📄 Guía ESP32: docs.espressif.com
- 💬 Foro: forum.arduino.cc

</td>
<td width="50%">

### Investigación Previa

Seleccionar **un sensor** del kit y preparar ficha técnica:

| Sección | Contenido |
|---------|-----------|
| **Especificaciones** | Rangos, precisión, voltaje, corriente |
| **Diagrama** | Conexión al ESP32 |
| **Código ejemplo** | Sketch Arduino básico |
| **Aplicaciones** | 3 casos de uso reales en Colombia |
| **Limitaciones** | Qué NO puede hacer |
| **Alternativas** | Otros sensores similares |

### Fecha de entrega
**Próxima clase** - Traer instalado y funcionando

</td>
</tr>
</table>

---

## Próxima Clase

# Clase 6: Programación de Microcontroladores

### Temas a Cubrir

- Arduino IDE y alternativas (PlatformIO)
- Estructura de un programa Arduino
- Manejo de pines GPIO (entrada/salida)
- Lectura de sensores analógicos y digitales
- Control de actuadores (PWM, digital)
- Comunicación serial para depuración
- Mejores prácticas de código

### Demo Práctico
Programaremos el ESP32 para leer múltiples sensores y enviar datos por WiFi.

---

**¡Gracias! ¿Preguntas?**

📧 Contacto: [profesor@unaula.edu.co]
📚 Recursos: GitHub del curso
💬 Canal: Discord/Teams del curso
