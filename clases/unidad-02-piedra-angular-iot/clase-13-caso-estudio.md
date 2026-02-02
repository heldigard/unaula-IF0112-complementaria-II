---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 13: Casos de Estudio Aplicados
## Evaluación E4 (15%)

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Analizar** casos reales de implementación IoT
2. **Aplicar** frameworks teóricos a casos prácticos
3. **Evaluar** decisiones técnicas y de negocio
4. **Presentar** análisis técnico con sustentación

**Duración:** 2 horas
**Evaluación:** E4 - 15% del curso

---

# PARTE 1: ANÁLISIS DE CASOS REALES (40 min)

---

## Caso 1: EPM - Smart Metering de Agua
### Medellín, Colombia

```
┌─────────────────────────────────────────────────────────────┐
│              EPM - SMART METERING AGUA                      │
│                                                             │
│   PROBLEMA:                                                 │
│   • Pérdidas de agua del 30%                               │
│   • Lectura manual costosa y lenta                         │
│   • Difícil detección de fugas                             │
│   • Facturación imprecisa                                  │
│                                                             │
│   SOLUCIÓN IoT:                                             │
│   🔢 Medidores inteligentes                                │
│       │                                                     │
│       ▼                                                     │
│   📡 Red LPWAN (LoRa)                                      │
│       │                                                     │
│       ▼                                                     │
│   ☁️ Plataforma análisis                                   │
│       │                                                     │
│       ▼                                                     │
│   📱 Dashboard + alertas                                    │
└─────────────────────────────────────────────────────────────┘
```

---
## EPM: Análisis con Modelo P-P-D-C

```
┌─────────────────────────────────────────────────────────────┐
│                  PERSONAS (People)                          │
│   • Técnicos de EPM                                        │
│   • Analistas de pérdidas                                  │
│   • Usuarios residenciales                                 │
│   • Equipo de facturación                                  │
├─────────────────────────────────────────────────────────────┤
│                  PROCESOS (Process)                         │
│   • Lectura automática cada hora                           │
│   • Detección automática de anomalías                      │
│   • Facturación automatizada                               │
│   • Alertas de fugas a técnicos                            │
├─────────────────────────────────────────────────────────────┤
│                    DATOS (Data)                             │
│   • Consumo por hora/día/mes                               │
│   • Patrones de uso                                        │
│   • Alertas de consumo anormal                             │
│   • Históricos para planificación                          │
├─────────────────────────────────────────────────────────────┤
│                   COSAS (Things)                            │
│   • 800,000+ medidores inteligentes                        │
│   • Gateways LoRa en postes                                │
│   • Servidores de procesamiento                            │
│   • Válvulas remotas (piloto)                              │
└─────────────────────────────────────────────────────────────┘
```

---

## EPM: Resultados e Impacto

### Métricas de Éxito:

| Indicador | Antes | Después | Mejora |
|-----------|-------|---------|--------|
| Pérdidas de agua | 30% | 18% | -40% |
| Tiempo lectura | 30 días | Tiempo real | -99% |
| Costo operativo | Alto | -45% | Significativo |
| Satisfacción cliente | Media | Alta | +35% |

### Lecciones Aprendidas:
- ✅ Despliegue gradual por zonas fue clave
- ✅ Capacitación de técnicos crítica
- ✅ Red LPWAN ideal para medidores en sótanos
- ⚠️ Resistencia inicial de usuarios superada con educación

---

## EPM: Tipos de Comunicación

```
┌─────────────────────────────────────────────────────────────┐
│                    EPM - COMUNICACIÓN                       │
│                                                             │
│   M2M:                                                      │
│   🔢 Medidor → 📡 Gateway → ☁️ Cloud                       │
│   (Transmisión automática de lecturas)                     │
│                                                             │
│   M2P:                                                      │
│   ☁️ Análisis → 📱 Alerta técnico                          │
│   "Fuga detectada en sector X"                             │
│                                                             │
│   M2P:                                                      │
│   ☁️ Sistema → 📧 Usuario                                  │
│   "Su consumo este mes: 15m³ - Ahorro: 10%"               │
│                                                             │
│   P2M:                                                      │
│   👤 Técnico → 📱 App → 🔧 Válvula                         │
│   (Cierre remoto en emergencia)                            │
└─────────────────────────────────────────────────────────────┘
```

---

## Caso 2: TransMilenio - Fleet Management
### Bogotá, Colombia

```
┌─────────────────────────────────────────────────────────────┐
│            TRANSMILENIO - FLEET MANAGEMENT                  │
│                                                             │
│   COMPONENTES IoT:                                          │
│                                                             │
│   🚌 Bus articulado                                         │
│   ├── 📍 GPS tiempo real                                   │
│   ├── 👥 Contador pasajeros                                │
│   ├── 🔧 Sensores diagnóstico                              │
│   └── 📹 Cámaras seguridad                                 │
│                                                             │
│       │                                                     │
│       ▼ 4G/LTE                                             │
│                                                             │
│   🖥️ Centro de Control                                     │
│   ├── Mapa flota en tiempo real                            │
│   ├── Predicción llegadas                                  │
│   ├── Detección incidentes                                 │
│   └── Optimización rutas                                   │
│                                                             │
│       │                                                     │
│       ▼                                                     │
│   📱 App pasajeros + 📺 Pantallas estaciones               │
└─────────────────────────────────────────────────────────────┘
```

---

## TransMilenio: Análisis con Modelo P-P-D-C

| Pilar | Elementos |
| ------- | ----------- |
| **Personas** | Conductores, pasajeros, operadores centro control, técnicos mantenimiento |
| **Procesos** | Tracking flota, predicción demanda, mantenimiento predictivo, respuesta incidentes |
| **Datos** | Posición GPS, conteo pasajeros, telemetría vehículo, tiempos de viaje |
| **Cosas** | 2,200 buses, sensores, gateways, servidores, pantallas informativas |

---

## TransMilenio: Resultados e Impacto

| Métrica | Antes | Después | Mejora |
| --------- | ------- | --------- | -------- |
| Tiempo espera promedio | 15 min | 8 min | -47% |
| Precisión llegada | 60% | 92% | +53% |
| Incidentes no reportados | 40% | 12% | -70% |
| Satisfacción pasajeros | 3.5/5 | 4.2/5 | +20% |
| Optimización rutas | Manual | Automática | Tiempo real |

---

## TransMilenio: Tipos de Comunicación

```
┌─────────────────────────────────────────────────────────────┐
│                 TRANSMILENIO - COMUNICACIÓN                  │
│                                                             │
│   M2M:                                                      │
│   🚌 Bus → ☁️ Cloud                                        │
│   (Telemetría automática cada 30 seg)                       │
│                                                             │
│   M2P:                                                      │
│   ☁️ Sistema → 📱 App pasajero                             │
│   "Su bus llega en 3 minutos a la parada"                   │
│                                                             │
│   M2P:                                                      │
│   ☁️ Alerta → 🔧 Técnico mantenimiento                     │
│   "Bus 1234 requiere revisión de frenos"                    │
│                                                             │
│   P2M:                                                      │
│   👤 Operador → 🖥️ Panel de control                        │
│   (Reruteo manual de buses en emergencias)                  │
└─────────────────────────────────────────────────────────────┘
```

---

## Caso 3: Argos - Concrete IoT

### Problema Identificado
- Concreto se daña si llega tarde
- Desperdicio de material costoso
- Coordinación compleja en obras grandes

### Solución IoT Implementada

| Componente | Función |
|------------|----------|
| **Mixer GPS** | Rastreo de vehículos de concreto |
| **Sensor rotación** | Monitorea calidad del mezclado |
| **Sensor temperatura** | Control de curado del concreto |
| **Tablet coordinador** | Alertas de llegada en tiempo real |

### Plataforma Cloud
- Optimización de rutas de entrega
- Predicción de tiempos
- Calidad de concreto asegurada

**Resultado:** Reducción del 15% en desperdicio de concreto

---

## Lecciones Aprendidas en IoT

### Patrones de Éxito en Proyectos IoT

| Principio | Descripción |
|-----------|-------------|
| **1. Problema Claro** | Pérdidas medibles, ineficiencia cuantificable |
| **2. Datos → Valor** | No solo recolectar, sino generar insights |
| **3. Integración** | IoT no aislado, conectado a procesos existentes |
| **4. Escalabilidad** | Diseño para crecer (miles de dispositivos) |
| **5. ROI Medible** | Ahorro o ingreso cuantificable |
| **6. Personas Primero** | Tecnología al servicio de personas |

### Claves del Éxito
- Definir métricas de éxito desde el inicio
- Involucrar usuarios finales en el diseño
- Iterar rápidamente basado en datos reales
- Considerar mantenimiento y soporte desde el inicio

---

## Evaluación E4: Instrucciones

---

## Evaluación E4: Análisis de Caso IoT
### 15% del Curso - Trabajo en Parejas

**Metodología:** Sustentación oral + documento escrito

---

## Instrucciones E4

### Formato de Trabajo

**Trabajo en parejas** - Sustentación individual

**Entregables:**
1. **Documento escrito** (4-6 páginas)
2. **Presentación** (10 minutos por pareja)
3. **Sustentación** (preguntas individuales)

---
### Estructura Obligatoria


```
1. RESUMEN EJECUTIVO (1/2 página)
   - Empresa/Proyecto analizado
   - Problema y solución
   - Resultados clave

2. ANÁLISIS P-P-D-C (1-2 páginas)
   - Personas involucradas y roles
   - Procesos automatizados/mejorados
   - Datos generados y su uso
   - Cosas (dispositivos, sensores, etc.)

3. ANÁLISIS DE COMUNICACIÓN (1 página)
   - Identificar interacciones M2M
   - Identificar interacciones M2P
   - Identificar interacciones P2P
   - Diagrama de flujo de datos

4. EVALUACIÓN CRÍTICA (1-2 páginas)
   - Fortalezas del proyecto
   - Debilidades o riesgos
   - Mejoras propuestas
   - Lecciones aprendidas

---
### Estructura Obligatoria

5. REFERENCIAS
   - Mínimo 3 fuentes verificables
```

---

## Rúbrica de Evaluación

| Criterio | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (1-2) |
| ---------- | --------------- | ----------- | ------------- | ------------------ |
| **Análisis P-P-D-C** (30%) | Completo, profundo, bien justificado | Completo con análisis adecuado | Incompleto o superficial | Ausente o erróneo |
| **Comunicación M2M/M2P/P2P** (25%) | Identifica todos los tipos correctamente | Identifica mayoría | Confusión entre tipos | No identifica |
| **Evaluación crítica** (25%) | Análisis profundo con mejoras viables | Análisis adecuado | Superficial | Sin análisis |
| **Sustentación** (20%) | Domina el tema, responde todo | Responde bien mayoría | Respuestas básicas | No puede responder |

---

## Casos Sugeridos para Análisis

### Colombia
- **Celsia**: Smart grids y medición inteligente
- **Bavaria/ABInBev**: Cervecería conectada
- **Bancolombia**: IoT en cajeros y sucursales
- **ETB**: Smart cities Bogotá
- **Codensa**: Red eléctrica inteligente

### Latinoamérica
- **CEMEX** (México): Concreto IoT
- **Itaú** (Brasil): Banca IoT
- **Metro Santiago** (Chile): Transporte inteligente

### Global (aplicable localmente)
- **Siemens**: Industria 4.0
- **John Deere**: Agricultura de precisión
- **Philips**: Hospitales conectados

---

## Preguntas de Sustentación (Ejemplos)

### Conceptuales
- ¿Por qué este proyecto necesitaba IoT?
- ¿Qué pasaría si falla la conectividad?
- ¿Cómo maneja la seguridad de datos?

### Técnicas
- ¿Qué protocolo usarías y por qué?
- ¿Edge o Cloud computing? ¿Por qué?
- ¿Cómo escala a más dispositivos?

### Críticas
- ¿Qué mejorarías del proyecto?
- ¿Cuáles son los riesgos principales?
- ¿Qué pasa si la empresa quiebra?

---

## Tiempo de Trabajo (40 min)

### Actividad en Clase

1. **Formar parejas** (5 min)
2. **Seleccionar caso** (5 min)
   - Validar con el docente
   - No repetir casos entre parejas
3. **Investigación inicial** (30 min)
   - Buscar información del caso
   - Identificar componentes P-P-D-C
   - Bosquejar estructura del documento

---

## Cronograma de Entrega

| Actividad | Fecha |
| ----------- | ------- |
| **Hoy** | Selección de caso y pareja |
| **Clase 14** | Entrega documento escrito |
| **Clase 14** | Sustentaciones (10 min/pareja) |

**Formato entrega:** PDF por Classroom
**Nombre archivo:** `E4_Apellido1_Apellido2_CasoXX.pdf`

---

## Criterios de Honestidad Académica

```
┌─────────────────────────────────────────────────────────────┐
│              ⚠️ IMPORTANTE ⚠️                               │
│                                                             │
│   ✓ Pueden usar IA como herramienta de búsqueda           │
│   ✓ Pueden consultar cualquier fuente                      │
│   ✓ Deben citar todas las fuentes                         │
│                                                             │
│   ✗ NO pueden presentar trabajo de otros                   │
│   ✗ NO pueden copiar sin citar                             │
│                                                             │
│   La SUSTENTACIÓN INDIVIDUAL valida el aprendizaje        │
│   Ambos integrantes deben poder responder TODO            │
│                                                             │
│   Calificación: Si la sustentación evidencia que          │
│   no conoce el trabajo, la nota individual es 1.0         │
└─────────────────────────────────────────────────────────────┘
```

---

## Resumen de la Clase

| Tema | Puntos Clave |
| ------ | -------------- |
| **EPM** | Smart metering, LoRa, reducción pérdidas |
| **TransMilenio** | Fleet management, GPS, predicción |
| **Argos** | Supply chain IoT, calidad concreto |
| **Patrones** | Problema claro, datos→valor, escalabilidad |
| **E4** | Análisis de caso real, parejas, sustentación |

---

## Próxima Clase

### Clase 14: Marco Legal y Normativo + Sustentaciones E4
- Regulación IoT en Colombia
- Protección de datos (Ley 1581)
- Sustentaciones de la Evaluación E4

### Preparación
- Completar documento de análisis
- Preparar presentación de 10 minutos
- Ambos integrantes listos para sustentar

**¡Nos vemos!**
