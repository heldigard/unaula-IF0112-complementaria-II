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

# Clase 10: Examen Parcial (E3)
## Evaluación del Primer Seguimiento - 20%

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---


## 🎯 Objetivos del Examen Parcial

Evaluar la comprensión de:
1. Conceptos fundamentales de IoT
2. Arquitectura de sistemas IoT
3. Programación de microcontroladores
4. Protocolos de comunicación
5. Conectividad y redes


---

## Información del Examen

| Aspecto | Detalle |
| --------- | --------- |
| **Tipo** | Examen escrito |
| **Modalidad** | Individual, sin consulta |
| **Duración** | 90 minutos |
| **Peso** | 20% de la nota final |
| **Fecha límite** | Antes del 27 de marzo |

---

## Estructura del Examen

| Sección | Puntos | Preguntas |
| --------- | -------- | ----------- |
| **Selección múltiple** | 30 | 15 preguntas (2 pts c/u) |
| **Verdadero/Falso** | 10 | 10 preguntas (1 pt c/u) |
| **Desarrollo corto** | 30 | 3 preguntas (10 pts c/u) |
| **Caso de análisis** | 30 | 1 caso completo |
| **Total** | **100** |  |

---

## Temas a Evaluar

### Unidad 1: ¿Qué es IoT?
- Evolución de Internet (ARPANET → IoT)
- Pilares: Personas, Procesos, Datos, Cosas
- Empresas y ciudades inteligentes
- Redes: LAN, WAN, LPWAN

### Unidad 2: La piedra angular de IoT
- Microcontroladores (Arduino, ESP32)
- Sensores y actuadores
- Protocolos (HTTP, MQTT)
- Edge vs Cloud Computing

---

## Ejemplo: Selección Múltiple

**1. ¿Cuál es la característica principal de MQTT?**

a) Modelo request-response
b) Modelo publish-subscribe ✓
c) Solo funciona con HTTP
d) Requiere conexión permanente a Internet

**2. Un sensor DHT11 se comunica mediante:**

a) Protocolo I2C
b) Protocolo SPI
c) Pin digital con protocolo propietario ✓
d) Conexión analógica

---

## Ejemplo: Verdadero/Falso

**Indique V o F:**

1. ___ Edge Computing procesa datos más cerca de la fuente que Cloud Computing. **(V)**

2. ___ El ESP32 tiene WiFi y Bluetooth integrado. **(V)**

3. ___ MQTT usa el puerto 80 por defecto. **(F - usa 1883)**

4. ___ Un actuador captura datos del mundo físico. **(F - ejecuta acciones)**

5. ___ LoRaWAN es ideal para transmitir video en tiempo real. **(F - baja velocidad)**

---

## Ejemplo: Desarrollo Corto

**Pregunta 1 (10 puntos):**

Explique las diferencias entre los niveles de QoS en MQTT (QoS 0, 1 y 2). Para cada nivel, indique un caso de uso apropiado.

**Respuesta esperada:**
- QoS 0: "At most once" - mensaje puede perderse. Uso: lecturas frecuentes de sensores.
- QoS 1: "At least once" - mensaje puede duplicarse. Uso: comandos importantes.
- QoS 2: "Exactly once" - entrega garantizada única. Uso: transacciones críticas.

---

## Ejemplo: Caso de Análisis

**Caso: Sistema de Riego Inteligente (30 puntos)**

Una finca de café requiere un sistema de riego automatizado con:
- 20 sensores de humedad del suelo
- 5 estaciones meteorológicas
- 10 válvulas de riego controlables
- Monitoreo desde una app móvil
- Operación incluso sin Internet

**Preguntas:**
1. (10 pts) Diseñe la arquitectura del sistema indicando dispositivos, Edge y Cloud.
2. (10 pts) Justifique la selección de protocolo de comunicación.
3. (10 pts) Explique cómo manejaría la operación sin Internet.

---

## Recomendaciones para el Examen

### Antes del examen:
- Revisar todas las presentaciones (clases 1-9)
- Estudiar los diagramas de arquitectura
- Repasar protocolos y sus diferencias
- Practicar diseño de sistemas IoT

### Durante el examen:
- Leer todas las preguntas primero
- Distribuir el tiempo por sección
- En desarrollo, ser conciso pero completo
- En el caso, usar diagramas si ayuda

---

## Distribución del Tiempo Sugerida

```
┌─────────────────────────────────────────────────────────────┐
│              DISTRIBUCIÓN DE 90 MINUTOS                     │
│                                                             │
│   0:00 - 0:05   Lectura general del examen (5 min)         │
│                                                             │
│   0:05 - 0:20   Selección múltiple (15 min)                │
│                                                             │
│   0:20 - 0:30   Verdadero/Falso (10 min)                   │
│                                                             │
│   0:30 - 0:55   Desarrollo corto (25 min)                  │
│                                                             │
│   0:55 - 1:25   Caso de análisis (30 min)                  │
│                                                             │
│   1:25 - 1:30   Revisión final (5 min)                     │
└─────────────────────────────────────────────────────────────┘
```

---

## Conceptos Clave para Repasar

### Dispositivos
- Arduino vs ESP32 vs Raspberry Pi
- Sensores: DHT11, ultrasónico, PIR, LDR
- Actuadores: LED, relé, motor, servo

### Redes
- PAN, LAN, WAN, LPWAN
- WiFi, LoRaWAN, NB-IoT, Bluetooth
- Selección de red según caso de uso

### Protocolos
- HTTP (request-response)
- MQTT (publish-subscribe, QoS, topics)
- Comparación y cuándo usar cada uno

### Arquitecturas
- Edge vs Cloud vs Fog
- Gateway y sus funciones
- Cuándo usar cada enfoque

---

## Fórmulas/Datos Útiles

### Puertos por Defecto
- HTTP: 80
- HTTPS: 443
- MQTT: 1883
- MQTT TLS: 8883

### ESP32 ADC
- Resolución: 12 bits
- Rango: 0-4095
- Voltaje: 0-3.3V

### DHT11 Especificaciones
- Temperatura: 0-50°C (±2°C)
- Humedad: 20-80% (±5%)
- Muestreo: 1 lectura/segundo

---

## Reglas del Examen

### Permitido:
- Bolígrafo azul o negro
- Calculadora básica (no programable)
- Diccionario español-inglés (si aplica)

### No permitido:
- Celulares (deben estar apagados)
- Apuntes o libros
- Comunicación con compañeros
- Cualquier dispositivo electrónico

### Penalizaciones:
- Copia: 0.0 para ambos estudiantes
- Uso de celular: retiro del examen

---

## Después del Examen

### Revisión de notas
- Publicación: 5 días hábiles después
- Reclamaciones: 3 días hábiles
- Retroalimentación en clase siguiente

### Temas pendientes (Segundo Seguimiento)
- Conexiones M2M, M2P, P2P
- Futuro de IoT y 5G
- Marco legal y normativo
- Proyecto aplicado

---

## ¡Éxitos!

### Recuerden:

- Llegar 10 minutos antes
- Traer documento de identidad
- Descansar bien la noche anterior
- Confiar en su preparación

---

# EXAMEN

## Inicio: [Hora]
## Duración: 90 minutos

**Instrucciones:**
1. Escriba su nombre completo y código
2. Use bolígrafo, no lápiz
3. Respuestas claras y legibles
4. No se permiten preguntas durante el examen
5. Al terminar, entregue todas las hojas

**¡Pueden comenzar!**
