# Estándares IoT Importantes

**Clase 15: Estándares | Unidad 2**

## Estándares IEEE

### IEEE 802.15.4 (PHY/MAC para WPAN)

**Base de:** Zigbee, Thread, WirelessHART

| Parámetro | Valor |
|-----------|-------|
| **Frecuencias** | 868 MHz (EU), 915 MHz (US), 2.4 GHz (global) |
| **Velocidad** | 20-250 Kbps |
| **Topología** | Star, Mesh |
| **Direcciones** | 16-bit (65,536 nodos) |

### IEEE 802.11 (WiFi)

| Estándar | Año | Velocidad | Frecuencia | Uso IoT |
|----------|-----|-----------|-----------|---------|
| 802.11n | 2009 | 600 Mbps | 2.4/5 GHz | Cámaras IP |
| 802.11ac | 2013 | 6.93 Gbps | 5 GHz | Streaming 4K |
| 802.11ax | 2019 | 9.6 Gbps | 2.4/5/6 GHz | Densidad alta |
| 802.11ah | 2016 | 150 Kbps | 900 MHz | IoT rural |
| 802.11az | 2024 | 30 Gbps | 2.4/5/6 GHz | Future IoT |

## Estándares IoT de Aplicación

### MQTT v5.0 (OASIS)

| Característica | Descripción |
|----------------|-------------|
| **Publicador/Suscriptor** | Desacoplamiento completo |
| **QoS 3 niveles** | 0 (fire & forget), 1 (1 vez), 2 (exactamente 1 vez) |
| **Retained messages** | Broker guarda último mensaje |
| **Will messages** | Mensaje de desconexión |
| **TLS** | Puerto 8883 para MQTT seguro |

### CoAP (IETF RFC 7252)

| Característica | Descripción |
|----------------|-------------|
| **Transporte** | UDP (no TCP) |
| **REST-like** | GET, POST, PUT, DELETE |
| **Discovery** | Recursos .well-known/core |
| **Observación** | Observe resource para cambios |
| **Bloques** | Transferencia confiable sobre UDP |

### LwM2M (OMA)

| Característica | Descripción |
|----------------|-------------|
| **Arquitectura** | Cliente - Servidor |
| **Objetos** | Definidos en IPSO Alliance |
| **Interfaces** | Bootstrap, Read, Write, Execute |
| **Comunicación** | CoAP sobre UDP |

## Estándares de Seguridad

### OWASP IoT Top 10 (2024)

1. **Weak, guessable, or hardcoded passwords**
2. **Insecure network services**
3. **Insecure ecosystem interfaces**
4. **Lack of secure update mechanism**
5. **Use of insecure or outdated components**
6. **Insufficient privacy protection**
7. **Insecure data transfer**
8. **Lack of device management**
9. **Insecure default settings**
10. **Lacking physical hardening**

## Certificaciones Importantes

### AWS IoT Core

- **Device Defender:** Seguridad de dispositivos
- **IoT Device Management:** OTA, configuración
- **FreeRTOS:** OS para microcontroladores

### Azure IoT

- **Azure Certified for IoT:** Dispositivos verificados
- **IoT Plug and Play:** Auto-descubrimiento

### Google Cloud IoT

- **Cloud IoT Core:** Registro de dispositivos
- **Device SDK:** C/C++, Embedded C, Python

## Certificaciones de Dispositivos

### FCC (EE.UU.)

- **Part 15:** Bajo potencia (IoT, WiFi, Bluetooth)
- **Part 18:** Industria, ciencia

### CE (Europa)

- **EMC Directiva:** Compatibilidad electromagnética
- **REACH:** Sustancias químicas
- **RoHS:** Plomo, mercurio, cadmio

### ICONTEC (Colombia)

- **NTC 6001:** Guía implementación IoT

## Normatividad Colombiana IoT

| Norma | Descripción |
|-------|-------------|
| **NTC 6001** | Guía implementación IoT en Colombia |
| **NTC-ISO/IEC 27001** | Seguridad de información |
| **NTC-ISO/IEC 30141** | Arquitectura de referencia IoT |

---

**[← Volver a README](README.md)**
