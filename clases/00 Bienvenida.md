# ¡Bienvenidos al Curso de Complementaria II! 🔌

**IF0112 - Internet de las Cosas (IoT)**
**Universidad Autónoma Latinoamericana - UNAULA**
**Semestre 2026-I**

**Docente:** Eldigardo Camacho
**Correo:** eldigardo.camacho3380@unaula.edu.com

---

## Sobre el Curso

**IF0112 - Complementaria II** es un curso de **2 créditos (32 horas)** del **6° semestre** que explora el mundo del **Internet de las Cosas (IoT)** y su aplicación en entornos domóticos, industriales y de ciudades inteligentes.

### Enfoque Práctico: Construiremos un Proyecto IoT Real

Este curso no es solo teoría. **Construiremos juntos un sistema IoT completo** que integra:

```
┌─────────────────────────────────────────────────────────────┐
│                  🏗️ PROYECTO DEL CURSO                       │
│                                                             │
│   Semanas 1-6:  Fundamentos + Hardware básico               │
│   Semanas 7-9:  Conectividad WiFi + Nube                    │
│   Semanas 10-12: Integración + Proyecto final              │
│                                                             │
│   RESULTADO: Un Monitor Ambiental IoT completamente funcional│
└─────────────────────────────────────────────────────────────┘
```

---

## 🎯 ¿Qué Aprenderás?

### Unidad 1: ¿Qué es IoT?
- Evolución de Internet hacia la conectividad de todo
- Personas, procesos, datos y cosas: los 4 pilares del IoT
- Transformación del entorno: hogares, ciudades e industrias
- Redes para IoT: LAN, WAN e Internet

### Unidad 2: La Piedra Angular de IoT
- Hardware: microcontroladores (Arduino, ESP32)
- Conectividad: WiFi, protocolos IoT
- Interacciones M2M, M2P y P2P
- Convergencia IT/OT y el futuro de Internet
- Marco legal y normativo

---

## 🛠️ Proyecto Integrador: Monitor Ambiental IoT

A lo largo del semestre, construirán paso a paso un **sistema de monitoreo ambiental** con las siguientes características:

### Características del Proyecto

| Característica | Descripción |
|----------------|-------------|
| **Sensores** | Temperatura, humedad, luz ambiental |
| **Almacenamiento** | Base de datos local (SPIFFS) |
| **Nube** | Envío de datos a ThingSpeak |
| **Interfaz Web** | Página de monitoreo en tiempo real |
| **Alertas** | Sistema visual con LEDs |
| **WiFi** | Conexión automática y reconexión |

### Flujo de Construcción

```
Semana 2-3:  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
               Lab 0: Arduino IDE              ┃
               Lab 1: LEDs y estructura        ┃
Semana 4:     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃   Fundamentos
               Lab 2: Botones y entradas       ┃   + Hardware
Semana 5:     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
               Lab 3: Sensores analógicos       ┃
Semana 6:     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛
               Lab 4: Sensor DHT temperatura
Semana 7-8:   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓   Conectividad
               Lab 5: WiFi con ESP32           ┃   + Nube
Semana 9:     ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
               Lab 6: ThingSpeak IoT Cloud     ┛
Semana 10:    ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
               Lab 7: Almacenamiento local      ┃   Integración
Semana 11-12: ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫   + Proyecto
               Lab 8: PROYECTO INTEGRADOR       ┛   FINAL
```

---

## 🛠️ Herramientas que Usaremos

### Hardware (demostraciones y laboratorios)

| Componente | Uso en el Proyecto |
|------------|-------------------|
| **ESP32 DevKit** | Microcontrolador principal con WiFi |
| **Sensor DHT11/DHT22** | Temperatura y humedad |
| **LDR + Resistencia** | Sensor de luz ambiental |
| **LEDs + Resistencias** | Indicadores de alerta |
| **Botones** | Control manual |
| **Protoboard + Cables** | Montaje de circuitos |

### Software y Plataformas

| Herramienta | Uso |
|-------------|-----|
| **Arduino IDE** | Programar el ESP32 |
| **ThingSpeak** | Almacenar datos en la nube (gratis) |
| **Tinkercad Circuits** | Simulador online (opcional) |
| **SPIFFS** | Sistema de archivos en ESP32 |

---

## 💡 Enfoque Pedagógico: Aprender Haciendo

Este curso usa **aprendizaje basado en proyectos**:

### Cada laboratorio construye una pieza del proyecto final

```
Lab 0-1:  Estructura básica       →  Fundamento de código
Lab 2-3:  Entradas y salidas       →  Sensores y actuadores
Lab 4:     Sensores ambientales    →  Adquisición de datos
Lab 5:     Conexión WiFi           →  Comunicación
Lab 6:     ThingSpeak              →  Almacenamiento en nube
Lab 7:     SPIFFS                  →  Almacenamiento local
Lab 8:     INTEGRACIÓN              →  PROYECTO COMPLETO
```

### Al finalizar el curso:

1. ✅ Tendrás un **sistema IoT funcionando** que construiste tú mismo
2. ✅ Entenderás **cada componente** del sistema
3. ✅ Podrás **explicar y defender** tu proyecto
4. ✅ Tendrás una **base sólida** para crear tus propios proyectos IoT

---

## 📚 Contenido del Curso

### Bloque 1: Fundamentos (Semanas 1-6)

**Teoría:**
- Evolución de Internet hacia IoT
- Los 4 pilares: Personas, Procesos, Datos, Cosas
- Redes y protocolos de comunicación
- Transformación del entorno con IoT

**Práctica:**
- Introducción a Arduino IDE y ESP32
- Control de LEDs y botones
- Sensores analógicos (LDR)
- Sensores digitales (DHT temperatura)

### Bloque 2: Conectividad (Semanas 7-9)

**Teoría:**
- Hardware y software embebido
- Protocolos de comunicación IoT
- Interacciones M2M, M2P, P2P
- Arquitecturas IoT

**Práctica:**
- Conexión WiFi con ESP32
- Envío de datos a ThingSpeak
- Visualización de datos en la nube

### Bloque 3: Integración (Semanas 10-12)

**Teoría:**
- Convergencia IT/OT
- Marco legal y normativo
- Estándares IoT
- Casos de estudio reales

**Práctica:**
- Almacenamiento local (SPIFFS)
- Sincronización de datos
- **PROYECTO INTEGRADOR FINAL**

---

## 🎯 Metas del Curso

Al finalizar, serás capaz de:

1. ✅ Explicar qué es IoT y su impacto en la sociedad
2. ✅ Identificar oportunidades de aplicación de IoT en diferentes contextos
3. ✅ Conocer la arquitectura y componentes de una solución IoT
4. ✅ Analizar casos de estudio reales de implementaciones IoT
5. ✅ **HABER CONSTRUIDO un sistema IoT completo y funcional**
6. ✅ Entender el marco legal y normativo aplicable

---

## 🛒 Componentes Necesarios

### Kit Básico (para el proyecto)

- 1x ESP32 DevKit
- 1x Sensor DHT11 o DHT22
- 1x LDR (fotorresistencia)
- 3x LEDs (rojo, amarillo, verde)
- Resistencias (220Ω, 1KΩ, 10KΩ)
- 1x Protoboard
- Cables jumper

**Costo aproximado:** $60.000 - $80.000 COP

**Dónde comprar en Medellín:**
- Electrónica JNC
- Centro (San Alejo)
- Tiendas online (MercadoLibre)

---

## 💡 Consejos para el Éxito

- 🎯 **Sé constante** - Cada laboratorio construye sobre el anterior
- 🤝 **Trabaja en equipo** - Los mejores proyectos IoT son colaborativos
- 💻 **Practica con simuladores** - Tinkercad para probar sin hardware
- 📖 **Investiga casos reales** - Smart cities, industria 4.0, domótica
- ❓ **Pregunta todo** - No hay preguntas tontas

---

## 🚀 ¡Comencemos este Viaje!

El Internet de las Cosas está transformando nuestro mundo. Desde hogares inteligentes hasta ciudades completas conectadas, IoT es una de las tecnologías más relevantes del siglo XXI.

### Lo que construiremos juntos:

```
┌─────────────────────────────────────────────┐
│  🌡️ MONITOR AMBIENTAL IoT                   │
│                                              │
│  - Lee temperatura y humedad                │
│  - Detecta nivel de luz                     │
│  - Guarda datos localmente                  │
│  - Envía a la nube                          │
│  - Interfaz web de monitoreo                │
│  - Sistema de alertas                       │
│                                              │
│  ¡Un sistema real que funciona!            │
└─────────────────────────────────────────────┘
```

No necesitas ser experto en electrónica o programación para este curso. Solo necesitas:
- ✨ Curiosidad por la tecnología
- 💪 Interés en aprender cómo el mundo se está conectando
- 🧠 Pensamiento analítico
- 🤝 Disposición para trabajar en equipo

**¡Nos vemos en la Clase 1!** 🔌✨
