---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 15: Estándares y Compatibilidad IoT
## Evaluación E5 (15%)

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Conocer** los principales estándares aplicables a IoT
2. **Identificar** requisitos de certificación
3. **Aplicar** estándares a diseño de soluciones
4. **Evaluar** cumplimiento de estándares en proyectos

**Duración:** 2 horas
**Evaluación:** E5 - 15% del curso

---

## ¿Por Qué Estandarizar IoT?

```
┌─────────────────────────────────────────────────────────────┐
│           EL PROBLEMA SIN ESTÁNDARES                        │
│                                                             │
│   DISPOSITIVO A         DISPOSITIVO B                       │
│   (Fabricante X)        (Fabricante Y)                     │
│        🔌                    🔌                             │
│        │                     │                              │
│        │ Protocolo X         │ Protocolo Y                 │
│        │                     │                              │
│        └─────────?───────────┘                              │
│                  │                                          │
│              NO SE ENTIENDEN                                │
│                                                             │
│   CONSECUENCIAS:                                            │
│   • Ecosistemas cerrados (vendor lock-in)                  │
│   • Duplicación de esfuerzos                               │
│   • Seguridad inconsistente                                │
│   • Dificultad de integración                              │
│   • Mayores costos para el consumidor                      │
└─────────────────────────────────────────────────────────────┘
```

---
## Panorama de Estándares IoT

```
┌─────────────────────────────────────────────────────────────┐
│              ECOSISTEMA DE ESTÁNDARES                       │
│                                                             │
│   COMUNICACIÓN:                                             │
│   IEEE 802.15.4 (Zigbee base)                              │
│   IEEE 802.11 (WiFi)                                       │
│   Bluetooth SIG                                            │
│   LoRa Alliance                                            │
│                                                             │
│   PROTOCOLOS:                                               │
│   IETF (CoAP, MQTT standards)                              │
│   W3C (Web of Things)                                      │
│   OASIS (MQTT oficial)                                     │
│                                                             │
│   SEGURIDAD:                                                │
│   ISO/IEC 27001 (Seguridad información)                    │
│   NIST Cybersecurity Framework                             │
│   ETSI EN 303 645 (Seguridad IoT)                         │
│                                                             │
│   INTEROPERABILIDAD:                                        │
│   OCF (Open Connectivity Foundation)                       │
│   CSA (Matter/Thread)                                      │
│   oneM2M                                                   │
└─────────────────────────────────────────────────────────────┘
```

---

# ESTÁNDARES DE SEGURIDAD

---
### Sistema de Gestión de Seguridad de la Información


```
┌─────────────────────────────────────────────────────────────┐
│              ISO/IEC 27001:2022                             │
│                                                             │
│   OBJETIVO: Establecer, implementar, mantener y mejorar    │
│   continuamente un SGSI (Sistema de Gestión de             │
│   Seguridad de la Información)                             │
│                                                             │
│   ESTRUCTURA (Ciclo PDCA):                                  │
│                                                             │
│       ┌─────────┐      ┌─────────┐                         │
│       │  PLAN   │ ───▶ │   DO    │                         │
│       │(Planear)│      │(Hacer)  │                         │
│       └────┬────┘      └────┬────┘                         │
│            │                │                               │
│            ▲                ▼                               │
│       ┌────┴────┐      ┌────┴────┐                         │
│       │   ACT   │ ◀─── │  CHECK  │                         │
│       │(Actuar) │      │(Verificar)                        │
│       └─────────┘      └─────────┘                         │
│                                                             │
│   APLICACIÓN IoT: Gestión de riesgos en dispositivos       │
└─────────────────────────────────────────────────────────────┘
```

---

## ISO 27001: Controles Relevantes para IoT

| Control | Descripción | Aplicación IoT |
| --------- | ------------- | ---------------- |
| **A.8.1** | Inventario de activos | Lista de todos los dispositivos IoT |
| **A.8.9** | Gestión de configuración | Configuración segura por defecto |
| **A.8.20** | Seguridad de redes | Segmentación de red IoT |
| **A.8.24** | Uso de criptografía | Cifrado de comunicaciones |
| **A.8.28** | Codificación segura | Desarrollo seguro de firmware |
| **A.8.32** | Gestión de cambios | Control de actualizaciones |

---

## ETSI EN 303 645

### Estándar Europeo de Seguridad IoT

```
┌─────────────────────────────────────────────────────────────┐
│              ETSI EN 303 645                                │
│         "Cybersecurity for Consumer IoT"                   │
│                                                             │
│   13 REQUISITOS BÁSICOS:                                    │
│                                                             │
│   1. No contraseñas por defecto universales               │
│   2. Implementar mecanismo de reporte de vulnerabilidades  │
│   3. Mantener software actualizado                         │
│   4. Almacenar credenciales de forma segura               │
│   5. Comunicaciones seguras                                │
│   6. Minimizar superficies de ataque                       │
│   7. Asegurar integridad del software                      │
│   8. Asegurar datos personales                            │
│   9. Sistemas resilientes a interrupciones                │
│   10. Examinar telemetría del sistema                      │
│   11. Facilitar eliminación de datos del usuario          │
│   12. Facilitar instalación y mantenimiento               │
│   13. Validar datos de entrada                            │
└─────────────────────────────────────────────────────────────┘
```

---
### Marco de Ciberseguridad


```
┌─────────────────────────────────────────────────────────────┐
│              NIST CSF - 5 FUNCIONES                         │
│                                                             │
│   1. IDENTIFY (Identificar)                                │
│      ├── ¿Qué dispositivos IoT tengo?                      │
│      ├── ¿Qué datos manejan?                               │
│      └── ¿Cuáles son los riesgos?                          │
│                                                             │
│   2. PROTECT (Proteger)                                     │
│      ├── Control de acceso                                 │
│      ├── Cifrado                                           │
│      └── Capacitación                                      │
│                                                             │
│   3. DETECT (Detectar)                                      │
│      └── Monitoreo continuo de anomalías                   │
│                                                             │
│   4. RESPOND (Responder)                                    │
│      └── Plan de respuesta a incidentes                    │
│                                                             │
│   5. RECOVER (Recuperar)                                    │
│      └── Plan de continuidad de negocio                    │
└─────────────────────────────────────────────────────────────┘
```

---

# ESTÁNDARES DE COMUNICACIÓN

---

### IEEE 802.15.4: Base para Zigbee, Thread, 6LoWPAN


```
┌─────────────────────────────────────────────────────────────┐
│              IEEE 802.15.4                                  │
│         "Low-Rate Wireless Personal Area Networks"         │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Banda: 2.4 GHz (mundial), 868 MHz (EU), 915 MHz (US)  │
│   • Velocidad: 20-250 kbps                                 │
│   • Alcance: 10-100 metros                                 │
│   • Bajo consumo energético                                │
│   • Topologías: Estrella, árbol, mesh                      │
│                                                             │
│   CONSTRUIDO SOBRE ESTO:                                    │
│                                                             │
│   ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐      │
│   │  Zigbee │  │  Thread │  │6LoWPAN  │  │WirelessHART     │
│   └─────────┘  └─────────┘  └─────────┘  └─────────┘      │
│        │            │            │            │            │
│        └────────────┴────────────┴────────────┘            │
│                          │                                  │
│                    IEEE 802.15.4                           │
└─────────────────────────────────────────────────────────────┘
```

---
### Estándares Bluetooth para IoT


```
┌─────────────────────────────────────────────────────────────┐
│              BLUETOOTH SPECIAL INTEREST GROUP               │
│                                                             │
│   BLUETOOTH CLASSIC                                         │
│   • Audio, transferencia archivos                          │
│   • Mayor consumo energético                               │
│   • Velocidad hasta 3 Mbps                                 │
│                                                             │
│   BLUETOOTH LOW ENERGY (BLE)                                │
│   • Optimizado para IoT                                    │
│   • Ultra bajo consumo                                     │
│   • Velocidad 1-2 Mbps                                     │
│   • Perfiles específicos:                                  │
│     - GATT (Generic Attribute Profile)                     │
│     - Heart Rate Profile                                   │
│     - Proximity Profile                                    │
│     - etc.                                                 │
│                                                             │
│   BLUETOOTH MESH                                            │
│   • Redes mesh sobre BLE                                   │
│   • Hasta 32,000 dispositivos                              │
│   • Ideal para iluminación, edificios                      │
└─────────────────────────────────────────────────────────────┘
```

---
### LoRaWAN Specification


```
┌─────────────────────────────────────────────────────────────┐
│              LoRa ALLIANCE                                  │
│         LoRaWAN Specification                              │
│                                                             │
│   VERSIÓN ACTUAL: LoRaWAN 1.0.4                            │
│                                                             │
│   CLASES DE DISPOSITIVOS:                                   │
│                                                             │
│   CLASE A (Baseline)                                        │
│   • Solo recibe después de transmitir                      │
│   • Menor consumo energético                               │
│   • Para sensores simples                                  │
│                                                             │
│   CLASE B (Beacon)                                          │
│   • Ventanas de recepción programadas                      │
│   • Latencia predecible                                    │
│                                                             │
│   CLASE C (Continuous)                                      │
│   • Siempre escuchando                                     │
│   • Mayor consumo                                          │
│   • Para actuadores                                        │
│                                                             │
│   SEGURIDAD: AES-128 cifrado de extremo a extremo         │
└─────────────────────────────────────────────────────────────┘
```

---

# ESTÁNDARES DE INTEROPERABILIDAD

---
### Matter: El Estándar Unificador para Smart Home


```
┌─────────────────────────────────────────────────────────────┐
│              MATTER (Connectivity Standards Alliance)       │
│                                                             │
│   ANTES: Project CHIP (Connected Home over IP)             │
│   FUNDADORES: Apple, Google, Amazon, Samsung               │
│                                                             │
│   COMPONENTES:                                              │
│                                                             │
│   ┌─────────────────────────────────────────────────┐      │
│   │              Aplicación Matter                   │      │
│   ├─────────────────────────────────────────────────┤      │
│   │           Modelo de datos                        │      │
│   ├─────────────────────────────────────────────────┤      │
│   │           Seguridad (CASE, PASE)                │      │
│   ├─────────────────────────────────────────────────┤      │
│   │              Transporte IP                       │      │
│   ├─────────┬─────────┬─────────┬───────────────────┤      │
│   │  WiFi   │ Thread  │Ethernet │                   │      │
│   └─────────┴─────────┴─────────┴───────────────────┘      │
│                                                             │
│   CATEGORÍAS: Iluminación, HVAC, cerraduras, sensores      │
└─────────────────────────────────────────────────────────────┘
```

---
### oneM2M: Estándar para Plataformas IoT


```
┌─────────────────────────────────────────────────────────────┐
│              oneM2M                                         │
│         Plataforma de Servicios Comunes                    │
│                                                             │
│   ARQUITECTURA:                                             │
│                                                             │
│   ┌─────────────────────────────────────────────────┐      │
│   │          Capa de Aplicación                      │      │
│   │   (Aplicaciones IoT verticales)                 │      │
│   └─────────────────────────────────────────────────┘      │
│                        │                                    │
│                        ▼                                    │
│   ┌─────────────────────────────────────────────────┐      │
│   │    CSE (Common Services Entity)                 │      │
│   │    • Gestión de datos                           │      │
│   │    • Seguridad                                  │      │
│   │    • Suscripción/notificación                  │      │
│   │    • Gestión de dispositivos                   │      │
│   └─────────────────────────────────────────────────┘      │
│                        │                                    │
│                        ▼                                    │
│   ┌─────────────────────────────────────────────────┐      │
│   │          Capa de Red/Transporte                 │      │
│   └─────────────────────────────────────────────────┘      │
└─────────────────────────────────────────────────────────────┘
```

---
### OCF: IoTivity Framework


```
┌─────────────────────────────────────────────────────────────┐
│              OCF (Open Connectivity Foundation)             │
│                                                             │
│   MIEMBROS: Intel, Samsung, LG, Qualcomm, Microsoft        │
│                                                             │
│   FRAMEWORK: IoTivity (Open Source)                         │
│                                                             │
│   CARACTERÍSTICAS:                                          │
│   • Descubrimiento automático de dispositivos              │
│   • Modelo de datos común (JSON)                           │
│   • Seguridad integrada                                    │
│   • Soporte para múltiples transportes                     │
│                                                             │
│   PROCESO DE CERTIFICACIÓN:                                 │
│                                                             │
│   1. Auto-certificación con herramientas OCF               │
│   2. Testing en laboratorio autorizado                     │
│   3. Certificación oficial OCF                             │
│   4. Uso del logo OCF Certified                            │
│                                                             │
│   Compatible con Matter para smart home                    │
└─────────────────────────────────────────────────────────────┘
```

---

## Comparación de Estándares de Interoperabilidad

| Aspecto | Matter | oneM2M | OCF |
| --------- | -------- | -------- | ----- |
| **Enfoque** | Smart Home | Plataforma general | Interoperabilidad |
| **Transporte** | WiFi, Thread | Cualquiera | CoAP sobre IP |
| **Seguridad** | CASE/PASE | Múltiples niveles | DTLS |
| **Adopción** | Masiva (2022+) | Telecom | Moderada |
| **Open Source** | Sí | Parcial | IoTivity |
| **Casos de uso** | Consumidor | Industrial, ciudades | General |

---

# EVALUACIÓN E5 (15%)

---

## Evaluación E5: Análisis de Estándares
### Trabajo en Parejas - Sustentación Individual

**Metodología:** Presentación + Sustentación oral

---

## Instrucciones E5

### Asignación de Estándares

Cada pareja analizará UN estándar:

1. **ISO/IEC 27001** - Seguridad de información
2. **ETSI EN 303 645** - Seguridad IoT consumidor
3. **IEEE 802.15.4** - Comunicación LPWAN
4. **LoRaWAN** - Redes de largo alcance
5. **Matter** - Interoperabilidad smart home
6. **oneM2M** - Plataforma de servicios
7. **NIST CSF** - Marco de ciberseguridad
8. **Bluetooth SIG (BLE Mesh)** - Mesh networking

---
## Estructura de Presentación (15 min)

```
┌─────────────────────────────────────────────────────────────┐
│              ESTRUCTURA PRESENTACIÓN                        │
│                                                             │
│   1. INTRODUCCIÓN (2 min)                                   │
│      • ¿Qué organismo lo desarrolló?                       │
│      • ¿Cuándo se publicó?                                 │
│      • ¿Cuál es su objetivo?                               │
│                                                             │
│   2. CONTENIDO TÉCNICO (5 min)                              │
│      • Principales componentes/requisitos                  │
│      • Arquitectura o estructura                           │
│      • Proceso de certificación (si aplica)                │
│                                                             │
│   3. APLICACIÓN PRÁCTICA (5 min)                            │
│      • Caso real de implementación                         │
│      • Empresas que lo usan                                │
│      • Ventajas y desventajas                              │
│                                                             │
│   4. CONCLUSIONES (3 min)                                   │
│      • ¿Cuándo usar este estándar?                         │
│      • Relación con otros estándares                       │
│      • Tendencias futuras                                  │
└─────────────────────────────────────────────────────────────┘
```

---

## Rúbrica de Evaluación E5

| Criterio | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (1-2) |
| ---------- | --------------- | ----------- | ------------- | ------------------ |
| **Dominio técnico** (30%) | Explica con precisión y profundidad | Explica correctamente | Explicación básica | Errores conceptuales |
| **Aplicación práctica** (25%) | Caso real detallado y relevante | Caso adecuado | Caso genérico | Sin caso o irrelevante |
| **Calidad presentación** (20%) | Clara, visual, bien organizada | Buena organización | Aceptable | Desorganizada |
| **Sustentación** (25%) | Responde todo con seguridad | Responde bien mayoría | Respuestas básicas | No puede responder |

---

## Preguntas de Sustentación (Ejemplos)

### Generales
- ¿Qué problema resuelve este estándar?
- ¿Por qué una empresa debería adoptarlo?
- ¿Cuánto cuesta la certificación?

### Técnicas
- ¿Qué capas del modelo OSI cubre?
- ¿Cómo maneja la seguridad?
- ¿Es compatible con [otro estándar]?

### Comparativas
- ¿Cuál es la diferencia con [estándar similar]?
- ¿En qué casos usarías uno vs otro?
- ¿Se pueden usar juntos?

---

## Tiempo de Trabajo (30 min)

### Actividad en Clase

1. **Asignación de estándares** (5 min)
   - Sorteo o selección
   - Evitar repeticiones

2. **Investigación inicial** (25 min)
   - Documentación oficial
   - Casos de implementación
   - Empresas certificadas

3. **Preparación de presentación**
   - Fecha: Próxima clase

---

## Cronograma E5

| Actividad | Fecha |
| ----------- | ------- |
| **Hoy** | Asignación de estándares |
| **Clase 16** | Presentaciones y sustentaciones |
| **Clase 16** | Retroalimentación |

**Formato:** Presentación en clase (PowerPoint, Google Slides, Canva)
**Duración:** 15 minutos por pareja + preguntas

---

## Recursos Recomendados

### Documentación Oficial
- ISO: www.iso.org
- ETSI: www.etsi.org
- IEEE: standards.ieee.org
- LoRa Alliance: lora-alliance.org
- CSA/Matter: csa-iot.org
- oneM2M: www.onem2m.org
- NIST: www.nist.gov/cyberframework

### Tutoriales y Guías
- IoT Standards Guide (Postscapes)
- Matter Developer Portal
- LoRaWAN Academy

---

## Resumen de la Clase

| Categoría | Estándares Clave |
| ----------- | ------------------ |
| **Seguridad** | ISO 27001, ETSI EN 303 645, NIST CSF |
| **Comunicación** | IEEE 802.15.4, BLE, LoRaWAN |
| **Interoperabilidad** | Matter, oneM2M, OCF |
| **Por qué importan** | Compatibilidad, seguridad, confianza |

---

## Próxima Clase

### Clase 16: Proyecto Final + Sustentaciones E5
- Presentaciones E5 (estándares)
- Introducción proyecto final (Examen 20%)
- Asignación de proyectos

### Preparación
- Completar presentación de estándares
- Ambos integrantes listos para sustentar
- Ideas para proyecto final

**¡Nos vemos!**
