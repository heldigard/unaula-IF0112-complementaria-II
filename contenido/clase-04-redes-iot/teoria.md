# Teoría: Redes para IoT

**Clase 4: Redes IoT | Unidad 1**

## 1. Clasificación de Redes por Alcance

| Tipo | Alcance | Velocidad | Consumo | Tecnologías |
|------|---------|-----------|---------|-------------|
| **PAN** | < 10 m | 1-100 Mbps | Bajo-Medio | Bluetooth, NFC, Zigbee, Infrared |
| **LAN** | < 1 km | 100 Mbps-10 Gbps | Alto | WiFi, Ethernet, Powerline |
| **WAN** | > 1 km | 10 Kbps-100 Mbps | Bajo | LoRaWAN, NB-IoT, Sigfox, 4G/5G |
| **Internet** | Global | Variable | Variable | TCP/IP, Satélite |

## 2. Tecnologías PAN Detalladas

### Bluetooth (Clásico y BLE)

| Parámetro | Bluetooth Clásico | Bluetooth Low Energy (BLE) |
|-----------|-------------------|---------------------------|
| Versión | 3.0+ | 4.0+ / 5.0+ |
| Velocidad | 1-3 Mbps | 1 Mbps |
| Consumo | Alto | Muy bajo |
| Alcance | 10-100 m | 10-50 m |
| Uso IoT | Audio, streaming | Sensores, wearables, beacons |

**Casos de uso:**
- Wearables (smartwatch, pulseras)
- Home Automation (interruptores, sensores)
- Beacons (retail, museos)
- Audio (altavoces)

### Zigbee

| Parámetro | Valor |
|-----------|-------|
| Estándar | IEEE 802.15.4 |
| Frecuencia | 2.4 GHz (global) |
| Velocidad | 250 Kbps |
| Alcance | 10-100 m |
| Topología | Mesh |
| Consumo | Muy bajo |
| Nodos por red | 65,000+ |

**Casos de uso:**
- Domótica (Philips Hue)
- Industrial (sensores)
- Building automation

### NFC (Near Field Communication)

| Parámetro | Valor |
|-----------|-------|
| Alcance | < 10 cm |
| Frecuencia | 13.56 MHz |
| Velocidad | 106-848 Kbps |
| Modos | Lectura/Escritura, Peer-to-Peer, Card Emulation |

**Casos de uso:**
- Pagos móviles (Apple Pay, Google Pay)
- Access control (tarjetas)
- Tags NFC (logística)

## 3. WiFi para IoT

### Estándares WiFi

| Estándar | Nombre | Velocidad | Rango | Frecuencia | Uso IoT |
|----------|--------|-----------|-------|------------|---------|
| 802.11n | WiFi 4 | 150-600 Mbps | 70m | 2.4/5 GHz | Cámaras IP |
| 802.11ac | WiFi 5 | 433-6933 Mbps | 35m | 5 GHz | Video HD |
| 802.11ax | WiFi 6 | 9.6 Gbps | 30m | 2.4/5/6 GHz | Alta densidad |
| 802.11ah | WiFi HaLow | 150 Kbps | 1km | 900 MHz | IoT rural |
| 802.11az | WiFi 7 | 30 Gbps | 20m | 2.4/5/6 GHz | Futuro |

### Pros y Contras

✅ **Ventajas:**
- Infraestructura existente
- Alta velocidad
- Compatibilidad universal
- Fácil configuración

❌ **Desventajas:**
- Alto consumo energético
- Requiere potencia continua
- Congestión en redes densas
- No ideal para baterías

## 4. Tecnologías WAN IoT

### LoRaWAN (Long Range Wide Area Network)

| Parámetro | Valor |
|-----------|-------|
| Estándar | LoRa Alliance |
| Frecuencia | 868 MHz (EU), 915 MHz (US) |
| Velocidad | 0.3-50 Kbps |
| Alcance | 2-15 km (rural), 2-5 km (urbano) |
| Topología | Star-of-Mesh |
| Consumo | Muy bajo (10+ años) |
| Costo | Bajo ($5-10/nodo) |

**Casos de uso:**
- Agricultura (riego, sensores suelo)
- Smart cities (parking, basura)
- Industria (activos, máquinas)
- Minería

### NB-IoT (Narrowband IoT)

| Parámetro | Valor |
|-----------|-------|
| Estándar | 3GPP Release 13 |
| Frecuencia | Bandas LTE (700-900 MHz) |
| Velocidad | 20-250 Kbps |
| Alcance | 10+ km |
| Latencia | 1.6-10 segundos |
| Consumo | Muy bajo |
| Movilidad | Limitada |

**Casos de uso:**
- Medidores inteligentes
- Tracking de activos
- Seguridad (alarmas)
- Smart agriculture

### Sigfox

| Parámetro | Valor |
|-----------|-------|
| Estándar | Propietario (UNB) |
| Frecuencia | 868 MHz (EU), 915 MHz (US) |
| Velocidad | 100 bps (down), 600 bps (up) |
| Alcance | 10-50 km rural |
| Mensajes/día | 140 (up), 4 (down) |

**Casos de uso:**
- Sensores periódicos (temp, humedad)
- Tracking simple
- Alertas

### 4G/5G para IoT

| Tecnología | 4G LTE-M | 5G IoT |
|-------------|----------|--------|
| Velocidad | 1 Mbps | 10+ Mbps |
| Latencia | 10-100 ms | 1-10 ms |
| Consumo | Medio | Medio-Alto |
| Costo | Medio | Alto |
| Casos | Video, tracking | V2X, crítica |

## 5. Matriz de Comparación

| Tecnología | Velocidad | Alcance | Consumo | Costo nodo | Mensaje/día |
|-------------|-----------|---------|---------|------------|------------|
| BLE | 1 Mbps | 50 m | Bajo | $2-5 | Ilimitado |
| Zigbee | 250 Kbps | 100 m | Bajo | $3-8 | Ilimitado |
| WiFi | 100 Mbps+ | 50 m | Alto | $5-15 | Ilimitado |
| LoRaWAN | 50 Kbps | 15 km | Muy bajo | $5-10 | Ilimitado |
| NB-IoT | 250 Kbps | 10+ km | Muy bajo | $10-20 | Ilimitado |
| Sigfox | 600 bps | 50 km | Muy bajo | $5-10 | 140 |
| 4G LTE-M | 1 Mbps | 10+ km | Medio | $20-50 | Ilimitado |

## 6. Protocolos de Aplicación IoT

| Protocolo | Uso | Características |
|-----------|-----|----------------|
| **MQTT** | Messaging | Pub/Sub, ligero, QoS |
| **HTTP/REST** | Web | Stateless, on-demand |
| **CoAP** | IoT | UDP, REST-like, bajo consumo |
| **AMQP** | Enterprise | Mensajería confiable |
| **LwM2M** | M2M | OMA, gestión de dispositivos |
| **WebSocket** | Tiempo real | Bidireccional |

---

**[← Volver a README](README.md) | [Ir a Casos →](casos.md)**
