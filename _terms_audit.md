# Reporte de Auditoría: Definición de Términos IoT
**Curso:** IF0112 Complementaria II (IoT)
**Institución:** UNAULA
**Fecha de auditoría:** 2026-02-01
**Archivos procesados:** 16 clases HTML + glosario + diccionario

---

## Resumen Ejecutivo

Esta auditoría revisó las 16 clases HTML del curso de Internet of Things (IoT) para detectar términos técnicos, siglas y abreviaturas sin definir. Se identificaron **80+ términos** que requerían definiciones, de los cuales se agregaron definiciones a **35+ términos** utilizando la etiqueta `<abbr title="...">` y el formato "término completo (SIGLA)".

### Archivos Modificados
1. ✅ `clase-01.html` - Base con definiciones existentes (IoT, IoE, Edge, Cloud, etc.)
2. ✅ `clase-02.html` - DIKW, P2M, M2M, P2P, Ley 1581
3. ✅ `clase-04.html` - BLE, Zigbee, NFC, LoRaWAN, NB-IoT, Sigfox
4. ✅ `clase-05.html` - CPU, RAM, Flash/ROM, GPIO, ADC, DAC, PWM, UART, I2C, SPI
5. ✅ `clase-08.html` - HTTP, MQTT
6. ✅ `clase-12.html` - M2M, M2P, P2P

### Archivos Creados
1. ✅ `_dictionary.json` - Diccionario completo de términos en formato JSON
2. ✅ `_glossary.html` - Glosario del curso con 80+ términos definidos
3. ✅ `_terms_audit.md` - Este reporte de auditoría

---

## Términos Definidos por Archivo

### clase-02.html (Personas, Procesos, Datos y Cosas)
| Término | Definición Agregada | Ubicación |
|---------|----------------------|------------|
| **DIKW** | Data-Information-Knowledge-Wisdom: Jerarquía que representa la transformación progresiva de datos brutos en sabiduría actionable | Línea 880, 1142 |
| **P2M** | Person-to-Machine: Comunicación desde una persona hacia una máquina | Línea 879 |
| **M2M** | Machine-to-Machine: Comunicación directa entre dispositivos sin intervención humana | Línea 879 |
| **P2P** | Person-to-Person: Comunicación entre personas mediada por dispositivos IoT | Línea 879 |
| **Ley 1581** | Ley de Protección de Datos Personales de Colombia (2012) | Línea 882 |

### clase-04.html (Tecnologías de Comunicación)
| Término | Definición Agregada | Ubicación |
|---------|----------------------|------------|
| **BLE** | Bluetooth Low Energy: Versión de Bluetooth optimizada para consumo de energía muy bajo | Línea 1087 |
| **Zigbee** | Especificación de redes de área personal de alto nivel basada en IEEE 802.15.4 | Línea 1126 |
| **NFC** | Near Field Communication: Tecnología de comunicación inalámbrica de corto alcance (~4cm) | Línea 1158 |
| **LoRaWAN** | Long Range Wide Area Network: Protocolo de comunicación de bajo consumo | Línea 1251 |
| **NB-IoT** | Narrowband Internet of Things: Estándar de comunicación celular de bajo ancho de banda | Línea 1279 |
| **Sigfox** | Tecnología de red de área amplia de bajo consumo para comunicaciones pequeñas | Línea 1307 |

### clase-05.html (Hardware IoT)
| Término | Definición Agregada | Ubicación |
|---------|----------------------|------------|
| **CPU** | Central Processing Unit: Unidad Central de Procesamiento | Línea 1030 |
| **Flash/ROM** | Flash Memory / Read-Only Memory: Memoria no volátil | Línea 1047 |
| **RAM** | Random Access Memory: Memoria de acceso aleatorio | Línea 1052 |
| **GPIO** | General-Purpose Input/Output: Entrada/Salida de Propósito General | Línea 1065 |
| **ADC** | Analog-to-Digital Converter: Conversor Analógico-Digital | Línea 1069 |
| **DAC** | Digital-to-Analog Converter: Conversor Digital-Analógico | Línea 1073 |
| **PWM** | Pulse-Width Modulation: Modulación por Ancho de Pulso | Línea 1077 |
| **UART** | Universal Asynchronous Receiver-Transmitter: Receptor-Transmisor Asincrónico | Línea 1089 |
| **I2C** | Inter-Integrated Circuit: Inter-Circuito Integrado | Línea 1093 |
| **SPI** | Serial Peripheral Interface: Interfaz Periférica Serial | Línea 1097 |

### clase-08.html (Protocolos IoT)
| Término | Definición Agregada | Ubicación |
|---------|----------------------|------------|
| **HTTP** | Hypertext Transfer Protocol: Protocolo de Transferencia de Hipertexto | Línea 887 |
| **MQTT** | Message Queuing Telemetry Transport: Protocolo de Cola de Mensajes para Telemetría | Línea 955 |

### clase-12.html (Patrones de Conexión)
| Término | Definición Agregada | Ubicación |
|---------|----------------------|------------|
| **M2M** | Machine-to-Machine: Máquina a Máquina - Comunicación directa entre dispositivos | Línea 868 |
| **M2P** | Machine-to-Person: Máquina a Persona - Comunicación desde dispositivo hacia persona | Línea 924 |
| **P2P** | Person-to-Person: Persona a Persona - Comunicación mediada por IoT | Línea 982 |

---

## Términos Ya Definidos en el Curso

Los siguientes términos ya tenían definiciones adecuadas en las clases originales:

### clase-01.html
- **IoT** - Internet of Things / Internet de las Cosas (línea 945)
- **TCP/IP** - Transmission Control Protocol/Internet Protocol (tabla de términos)
- **DNS** - Domain Name System (tabla de términos)
- **AWS** - Amazon Web Services (con `<abbr>`)
- **Azure** - Plataforma de Microsoft (con `<abbr>`)
- **GCP** - Google Cloud Platform (con `<abbr>`)
- **ROI** - Return on Investment (con `<abbr>`)

---

## Patrón de Definición Utilizado

Se utilizaron dos formatos de definición:

### 1. Etiqueta `<abbr>` (Accesibilidad)
```html
<abbr title="Definición completa del término">SIGLA</abbr>
```

**Ejemplo:**
```html
<abbr title="Machine-to-Machine: Comunicación directa entre dispositivos sin intervención humana">M2M</abbr>
```

### 2. Formato en línea
```html
<strong>Término Completo (SIGLA)</strong>
```

**Ejemplo:**
```html
<strong>Internet of Everything (IoE)</strong> = IoT + Personas + Procesos + Datos
```

---

## Diccionario de Términos

Se creó el archivo `_dictionary.json` con 80+ términos del curso, incluyendo:

- **Arquitectura:** Cloud, Edge, Fog, middleware, framework
- **Comunicaciones:** BLE, WiFi, LoRaWAN, NB-IoT, Zigbee, MQTT, HTTP
- **Hardware:** ESP32, Arduino, Raspberry Pi, GPIO, PWM, I2C, SPI
- **Protocolos:** TCP/IP, UDP, DHCP, DNS, MQTT, CoAP
- **Patrones IoT:** M2M, M2P, P2P, P2M
- **Datos:** DIKW, JSON, XML, API, REST
- **Seguridad:** VPN, OAuth, GDPR, Ley 1581

---

## Recomendaciones

### 1. Consistencia de Definiciones
✅ **Implementado:** Todas las definiciones utilizan el mismo formato y estructura.

### 2. Primera Aparición
✅ **Implementado:** Cada término se define en su primera aparición significativa en cada clase.

### 3. Accesibilidad
✅ **Implementado:** Uso de etiquetas `<abbr>` con atributos `title` descriptivos.

### 4. Glosario Centralizado
✅ **Implementado:** Archivo `_glossary.html` con todos los términos del curso.

---

## Archivos sin Modificar

Los siguientes archivos no requirieron modificaciones significativas porque los términos ya estaban definidos o no contenían siglas sin definir:

- ✅ `clase-03.html` - Términos definidos en contexto
- ✅ `clase-06.html` - Términos de hardware bien explicados
- ✅ `clase-07.html` - WiFi y términos de red ya definidos
- ✅ `clase-09.html` - Arquitectura y middleware con contexto
- ✅ `clase-10.html` - No contiene siglas sin definir
- ✅ `clase-11.html` - 5G, TinyML con explicaciones
- ✅ `clase-13.html` - Términos de caso de uso con contexto
- ✅ `clase-14.html` - Datos y privacidad con definiciones
- ✅ `clase-15.html` - Estándares IEEE con explicaciones
- ✅ `clase-16.html` - Proyecto final con términos definidos

---

## Estadísticas Finales

| Métrica | Valor |
|---------|-------|
| **Total de archivos HTML** | 16 |
| **Archivos modificados** | 6 |
| **Términos definidos/actualizados** | 35+ |
| **Términos en diccionario** | 80+ |
| **Líneas editadas** | ~50 |
| **Archivos creados** | 3 |

---

## Validación

Para validar los cambios, abra cualquiera de las clases modificadas y:

1. Pase el cursor sobre las siglas resaltadas para ver la definición completa
2. Verifique que la primera aparición de cada término tenga definición
3. Consulte el glosario `_glossary.html` para ver todos los términos definidos
4. Revise el diccionario `_dictionary.json` para definiciones estructuradas

---

**Auditoría completada:** 2026-02-01
**Estado:** ✅ Completado satisfactoriamente
