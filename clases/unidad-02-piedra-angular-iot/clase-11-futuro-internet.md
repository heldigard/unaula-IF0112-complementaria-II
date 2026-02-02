---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 11: Futuro de Internet y Tecnologías Emergentes
## 5G, AIoT y Tendencias de Conectividad

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Describir** las capacidades de 5G para IoT
2. **Identificar** tendencias tecnológicas emergentes
3. **Analizar** el impacto de IA en IoT
4. **Proyectar** escenarios futuros de conectividad

**Duración:** 2 horas

---

## ¿Por qué estudiar el Futuro de IoT?

El Internet de las Cosas está evolucionando rápidamente con nuevas tecnologías que cambiarán cómo interactuamos con el mundo:

### Tendencias clave:
- **5G**: Conectividad ultra-rápida y de baja latencia
- **AIoT**: Inteligencia Artificial integrada en dispositivos
- **Edge AI**: Procesamiento de ML directamente en sensores
- **Digital Twins**: Réplicas virtuales de objetos físicos
- **Blockchain IoT**: Seguridad y trazabilidad descentralizada

### Para Colombia:
- 5G ya desplegado en principales ciudades (2024-2025)
- Inversión de $3+ billones en infraestructura digital
- Oportunidades en agricultura, minería y ciudades inteligentes

---

## Internet Hoy: Estadísticas 2024

```
┌─────────────────────────────────────────────────────────────┐
│               INTERNET EN NÚMEROS                           │
│                                                             │
│   👥 5.4 mil millones de usuarios (67% población mundial)  │
│                                                             │
│   📱 16.7 mil millones de dispositivos móviles             │
│                                                             │
│   🌐 30+ mil millones de dispositivos IoT                  │
│                                                             │
│   📊 120 zettabytes de datos generados/año                 │
│                                                             │
│   ⚡ 97% del tráfico pasa por cables submarinos            │
│                                                             │
│   💰 $15+ billones de mercado IoT (proyección 2030)        │
└─────────────────────────────────────────────────────────────┘
```

---

## 5G: La Quinta Generación

### Características Principales

```
┌─────────────────────────────────────────────────────────────┐
│                  ESPECIFICACIONES 5G                        │
│                                                             │
│   VELOCIDAD                                                 │
│   ──────────                                                │
│   Pico: 20 Gbps (teórico)                                  │
│   Real: 1-10 Gbps                                          │
│   4G:   100 Mbps          5G: ████████████████████ 10 Gbps │
│                                                             │
│   LATENCIA                                                  │
│   ────────                                                  │
│   5G: 1 ms (vs 30-50ms en 4G)                              │
│   4G: ████████████████████ 30ms                            │
│   5G: ██ 1ms                                                │
│                                                             │
│   DENSIDAD                                                  │
│   ────────                                                  │
│   1 millón de dispositivos por km²                         │
│   (4G: ~10,000 dispositivos/km²)                           │
└─────────────────────────────────────────────────────────────┘
```

---

## Tres Pilares de 5G

```
┌─────────────────────────────────────────────────────────────┐
│                   CASOS DE USO 5G                           │
│                                                             │
│     eMBB                 URLLC                mMTC          │
│   ────────             ─────────            ────────        │
│   Enhanced             Ultra-Reliable       Massive         │
│   Mobile               Low-Latency          Machine-Type    │
│   Broadband            Communications       Communications  │
│                                                             │
│   📺 Video 4K/8K       🚗 Vehículos         🌡️ Sensores    │
│   🎮 Cloud gaming         autónomos         📍 Medidores   │
│   🕶️ VR/AR             🏥 Cirugía remota   🏭 IoT masivo  │
│   📱 Móvil mejorado    🏭 Control indust.  🌾 Agricultura  │
│                                                             │
│   Velocidad            Latencia ultra       Millones de     │
│   máxima               baja (<1ms)          conexiones      │
└─────────────────────────────────────────────────────────────┘
```

---

## 5G y IoT: Casos de Uso

### Vehículos Conectados (V2X)

```
┌─────────────────────────────────────────────────────────────┐
│              COMUNICACIÓN VEHICULAR                         │
│                                                             │
│                    🚦 Semáforo                              │
│                       │                                     │
│     V2I ────────────────────────── V2I                     │
│                       │                                     │
│   🚗 ─── V2V ─── 🚙 ─── V2V ─── 🚕                         │
│                       │                                     │
│     V2P ────────────────────────── V2P                     │
│                       │                                     │
│                    🚶 Peatón                                │
│                                                             │
│   V2V: Vehicle-to-Vehicle (evitar colisiones)              │
│   V2I: Vehicle-to-Infrastructure (semáforos, señales)      │
│   V2P: Vehicle-to-Pedestrian (alertas peatones)            │
│   V2N: Vehicle-to-Network (nube, servicios)                │
│                                                             │
│   Requiere: <10ms latencia (5G cumple)                     │
└─────────────────────────────────────────────────────────────┘
```

---

## Casos 5G en Colombia: Medellín 🇨🇴

### Ciudad Inteligente 5G

```
┌─────────────────────────────────────────────────────────────┐
│              MEDELLÍN - CIUDAD 5G                           │
│                                                             │
│   CASOS DE USO PILOTO:                                      │
│                                                             │
│   🚦 SEMÁFOROS INTELIGENTES                                │
│   • 500 intersecciones conectadas                          │
│   • Ajuste dinámico según flujo (IA edge)                  │
│   • Reducción congestión: -25%                             │
│   • Respuesta: <100ms                                       │
│                                                             │
│   📹 VIGILANCIA MASIVA                                     │
│   • 2000 cámaras con análisis en tiempo real                │
│   • Detección de anomalías con IA                           │
│   • Alertas automáticas a centros de comando               │
│                                                             │
│   🚑 EMERGENCIAS MÉDICAS                                   │
│   • Ambulancias con prioridad V2I                           │
│   • Semáforos se liberan automáticamente                    │
│   • Tiempo respuesta: <5 segundos                          │
│                                                             │
│   📱 TURISMO AUMENTADO                                      │
│   • Realidad AR en lugares históricos                       │
│   • Guías virtuales con 5G                                 │
│                                                             │
│   SOCIALIZACIÓN: 2024-2028                                  │
└─────────────────────────────────────────────────────────────┘
```

---

## Casos 5G en Colombia: Minería 🇨🇴

### Smart Mining con 5G

```
┌─────────────────────────────────────────────────────────────┐
│              MINERÍA 5G - CERREJÓN                          │
│                                                             │
│   DESAFÍO:                                                 │
│   • Zonas remotas sin fibra óptica                         │
│   • Operaciones peligrosas underground                     │
│   • Necesidad de monitoreo en tiempo real                  │
│                                                             │
│   SOLUCIÓN 5G:                                             │
│   ┌─────────────────────────────────────────┐                │
│   │                                     │                │
│   │   🏔️ Mina                       ☁️ Nube     │                │
│   │   ┌─────────────────────┐          │                │
│   │   │Camaras 4K+LiDAR      │ 5G      │                │
│   │   │(Monitoreo geológico) │──────────►│                │
│   │   └─────────────────────┘ 1ms lat   │                │
│   │                                     │                │
│   │   🚛 Camiones Autónomos    IA       │                │
│   │   ┌─────────────────────┐          │                │
│   │   │GPS+Sensores          │──────────►│                │
│   │   │(Navegación segura)   │Control   │                │
│   │   └─────────────────────┘Remoto    │                │
│   │                                     │                │
│   │   👷 Operadores                      │                │
│   │   ┌─────────────────────┐          │                │
│   │   │VR Training           │          │                │
│   │   │(Simulación segura)   │          │                │
│   │   └─────────────────────┘          │                │
│   └─────────────────────────────────────────┘                │
│                                                             │
│   RESULTADOS:                                               │
│   • Seguridad: -60% incidentes                              │
│   • Eficiencia: +35% toneladas/día                          │
│   • Costos: -40% transporte personal                        │
└─────────────────────────────────────────────────────────────┘
```

---

## Casos 5G en Colombia: Agricultura 🇨🇴

### Agro 5G en el Valle

```
┌─────────────────────────────────────────────────────────────┐
│              AGRICULTURA 5G - CAÑA DE AZÚCAR                │
│                                                             │
│   CONTEXTO:                                                 │
│   • Ciénaga regiones (poca conectividad)                   │
│   • Cultivos de caña de azúcar                             │
│   • Necesidad de optimizar riego y cosecha                 │
│                                                             │
│   SOLUCIÓN IoT + 5G:                                        │
│                                                             │
│   🌾 CULTIVO                                                │
│   ├── 📡 Sensores humedad suelo (LoRa → Gateway)           │
│   ├── 🌡️ Estaciones meteorológicas                          │
│   ├── 🚁 Drones monitoreo (5G control remoto)              │
│   └── 💧 Sistema riego automatizado                        │
│                                                             │
│       │                                                     │
│       ▼ 5G Private Network                                 │
│                                                             │
│   ☁️ PLATAFORMA EDGE                                        │
│   ├── IA predicción cosecha                                │
│   ├── Optimización riego                                   │
│   ├── Alertas plagas/enfermedades                          │
│   └── Trazabilidad producto                                │
│                                                             │
│   📱 APLICACIÓN PRODUCTOR                                   │
│   ├── Recomendaciones diarias                              │
│   ├── Alertas climáticos                                    │
│   └── Mercado precios en tiempo real                       │
│                                                             │
│   RESULTADOS:                                               │
│   • Ahorro agua: -40%                                       │
│   • Incremento rendimiento: +25%                            │
│   • Reducción agroquímicos: -35%                            │
└─────────────────────────────────────────────────────────────┘
```

---

## 5G en Colombia

### Estado de Despliegue (2024)

```
┌─────────────────────────────────────────────────────────────┐
│              5G EN COLOMBIA                                 │
│                                                             │
│   OPERADORES CON 5G:                                        │
│   • Claro Colombia (2021)                                  │
│   • Movistar Colombia (2022)                               │
│   • WOM Colombia (2023)                                    │
│   • Tigo Colombia (piloto)                                 │
│                                                             │
│   CIUDADES CON COBERTURA:                                  │
│   🏙️ Bogotá    ████████████ 60%                           │
│   🏙️ Medellín  ████████ 40%                               │
│   🏙️ Cali      ██████ 30%                                 │
│   🏙️ Otras     ████ 20%                                   │
│                                                             │
│   DESAFÍOS:                                                 │
│   • Subasta de espectro                                    │
│   • Infraestructura en zonas rurales                       │
│   • Adopción de dispositivos compatibles                   │
└─────────────────────────────────────────────────────────────┘
```

---

## AIoT: Inteligencia Artificial en IoT

### Convergencia AI + IoT

```
┌─────────────────────────────────────────────────────────────┐
│                        AIoT                                 │
│           "AI + IoT = Sistemas Autónomos"                  │
│                                                             │
│   IoT                 +                 AI                  │
│   ───                                   ──                  │
│   Datos               →          Inteligencia              │
│   Sensores                       Decisiones                 │
│   Conectividad                   Predicción                 │
│   Actuadores                     Automatización             │
│                                                             │
│   EJEMPLOS:                                                 │
│   • Cámaras con reconocimiento facial                      │
│   • Termostatos que aprenden patrones                      │
│   • Mantenimiento predictivo en máquinas                   │
│   • Asistentes de voz (Alexa, Google Home)                │
│   • Robots autónomos en almacenes                          │
└─────────────────────────────────────────────────────────────┘
```

---

## TinyML: Machine Learning en Microcontroladores

```cpp
#include "model_data.h"

// TinyML: ML en microcontroladores

// Modelo entrenado (convertido a array de bytes)

tflite::MicroInterpreter* interpreter;

void setup() {
    // Cargar modelo
    const tflite::Model* model = tflite::GetModel(model_data);
    
    // Crear intérprete
    static tflite::MicroMutableOpResolver<10> resolver;
    resolver.AddConv2D();
    resolver.AddMaxPool2D();
    resolver.AddFullyConnected();
    
    static tflite::MicroInterpreter static_interpreter(
        model, resolver, tensor_arena, kTensorArenaSize);
    interpreter = &static_interpreter;
}

void loop() {
    // Ejecutar inferencia localmente
    interpreter->Invoke();
    
---
    // Obtener resultado
    float* output = interpreter->output(0)->data.f;
    Serial.printf("Predicción: %.2f\n", output[0]);
}
```

---

## Digital Twin Avanzado

```
┌─────────────────────────────────────────────────────────────┐
│              DIGITAL TWIN AVANZADO                          │
│                                                             │
│   MUNDO FÍSICO                   GEMELO DIGITAL            │
│   ┌───────────────┐             ┌───────────────┐          │
│   │    🏭        │             │   SIMULACIÓN   │          │
│   │   Fábrica    │  ◄────────► │   3D + Datos  │          │
│   │   Real       │   tiempo    │   tiempo real │          │
│   └───────────────┘   real     └───────────────┘          │
│                                        │                    │
│                                        ▼                    │
│                               ┌───────────────┐            │
│                               │  ANÁLISIS AI  │            │
│                               │ • Predicción  │            │
│                               │ • Optimización│            │
│                               │ • What-if     │            │
│                               └───────────────┘            │
│                                                             │
│   APLICACIONES:                                             │
│   • Ciudades (Singapur Virtual Singapore)                  │
│   • Fábricas (BMW, Siemens)                                │
│   • Edificios (gestión energética)                         │
│   • Humanos (salud, medicina personalizada)                │
└─────────────────────────────────────────────────────────────┘
```

---

## Metaverso e IoT

### Convergencia de Mundos

```
┌─────────────────────────────────────────────────────────────┐
│                   METAVERSO + IoT                           │
│                                                             │
│   FÍSICO ─────────── IoT ─────────── VIRTUAL               │
│                                                             │
│   🏠 Casa real      🌡️ Sensores      🏠 Casa virtual       │
│                         │                                   │
│                         ▼                                   │
│                  SINCRONIZACIÓN                             │
│                  BIDIRECCIONAL                              │
│                                                             │
│   EJEMPLOS:                                                 │
│   • Controlar dispositivos físicos desde VR                │
│   • Entrenamiento con gemelos digitales                    │
│   • Colaboración remota en espacios virtuales              │
│   • Comercio: probar productos virtuales                   │
│                                                             │
│   TECNOLOGÍAS:                                              │
│   VR/AR + 5G + IoT + Blockchain + AI                       │
└─────────────────────────────────────────────────────────────┘
```

---

## Blockchain para IoT

### Problemas IoT vs Soluciones Blockchain

| Problema IoT | Solución Blockchain |
|-------------|-------------------|
| Centralización | Descentralización |
| Falta de confianza | Inmutabilidad de datos |
| Vulnerabilidades | Criptografía avanzada |
| Privacidad de datos | Smart contracts |

### Casos de Uso
- **Cadena de suministro:** Trazabilidad completa
- **Energía P2P:** Venta entre vecinos
- **Identidad de dispositivos:** Autenticación única
- **Mercados de datos IoT:** Monetización segura

### Proyectos Destacados
| Proyecto | Enfoque |
|----------|---------|
| **IOTA** | Sin fees, diseñado para IoT |
| **Helium** | Red LoRaWAN descentralizada |
| **VeChain** | Supply chain management |

---

## Satélites LEO para IoT

### ¿Qué son los Satélites LEO?

**Características:**
- Altitud: 500-2000 km (vs 36,000 km geoestacionarios)
- Latencia: 20-40 ms (vs 600+ ms geoestacionarios)
- Cobertura global con constelaciones

### Constelaciones Principales

| Proyecto | Satélites | Estado |
|----------|-----------|--------|
| **Starlink** (SpaceX) | 5,000+ | 🟢 Operativo |
| **Kuiper** (Amazon) | 3,200+ | 🟡 Planeado |
| **OneWeb** | 600+ | 🟢 Operativo |

### Aplicaciones IoT Satellite

| Aplicación | Descripción |
|------------|-------------|
| **Agricultura remota** | Monitoreo de cultivos sin cobertura terrestre |
| **Monitoreo marítimo** | Seguridad de flotas y pesqueras |
| **Áreas remotas** | Conectividad donde no llega fibra |

### Proyectos IoT Satelital
- **Swarm Technologies:** Satélites del tamaño de un sandwich
- **Lacuna Space:** LoRaWAN desde el espacio

---

## Computación Cuántica e IoT

### Futuro a Largo Plazo

```
┌─────────────────────────────────────────────────────────────┐
│           QUANTUM COMPUTING + IoT                           │
│                                                             │
│   IMPACTO EN SEGURIDAD:                                     │
│   • Criptografía actual será vulnerable                    │
│   • Necesidad de criptografía post-cuántica                │
│   • Riesgo para datos IoT almacenados hoy                  │
│                                                             │
│   OPORTUNIDADES:                                            │
│   • Optimización de redes IoT                              │
│   • Procesamiento de datos masivos                         │
│   • Simulación avanzada                                    │
│   • Machine Learning cuántico                              │
│                                                             │
│   LÍNEA TEMPORAL:                                           │
│   2024: Computadoras cuánticas experimentales              │
│   2030: Aplicaciones específicas viables                   │
│   2040+: Impacto masivo en IoT                             │
└─────────────────────────────────────────────────────────────┘
```

---

## Actividad: Visión del Futuro (30 min)

### Ejercicio de Prospectiva

En grupos, imaginen Colombia en 2035:

**Preguntas:**
1. ¿Qué dispositivos IoT serán comunes en hogares?
2. ¿Cómo será el transporte urbano?
3. ¿Qué rol tendrá la IA en la vida diaria?
4. ¿Qué trabajos nuevos existirán en IoT?
5. ¿Qué desafíos éticos enfrentaremos?

**Entregable:** Presentación de 5 min con visión del grupo

---

## Resumen: Tecnologías Emergentes

| Tecnología | Impacto en IoT |
| ------------ | ---------------- |
| **5G** | Latencia ultra baja, IoT masivo |
| **AIoT** | Dispositivos inteligentes autónomos |
| **TinyML** | IA en el edge, privacidad |
| **Digital Twin** | Simulación y optimización |
| **Blockchain** | Seguridad, descentralización |
| **Satélites LEO** | Cobertura global |
| **6G (2030+)** | Terabits/segundo, 0.1ms |

---

## Próxima Clase

### Clase 12: Conexiones M2M, M2P, P2P
- Tipos de comunicación IoT
- Casos de uso empresariales
- Estándares de interoperabilidad

**¡Nos vemos!**
