# Ejercicios y Actividades

**Clase 3: Transformación del Entorno | Unidad 1**

## Actividad Principal: Diseño de Componente Smart City

### Objetivo
Diseñar un componente IoT para la ciudad de Medellín que mejore la calidad de vida de sus habitantes.

---

## Guía Paso a Paso

### Paso 1: Selección de Escenario (5 min)

Elija UNO de los siguientes escenarios:

| # | Escenario | Complejidad | Impacto Potencial |
|---|-----------|-------------|-------------------|
| 1 | Parqueaderos inteligentes | Media | Alto |
| 2 | Monitoreo calidad del aire por barrio | Alta | Muy Alto |
| 3 | Gestión inteligente de residuos | Media | Medio |
| 4 | Alerta temprana inundaciones | Alta | Alto |

### Paso 2: Análisis de Problema (10 min)

Para su escenario seleccionado, responda:

**Problema actual:**
- ¿Qué problema se va a resolver?
- ¿A quién afecta?
- ¿Cuál es el impacto actual (sin solución)?

**Solución propuesta:**
- ¿Cómo IoT resuelve este problema?
- ¿Qué valor aporta?

### Paso 3: Diseño de Arquitectura (20 min)

**Plantilla de Arquitectura:**

```
┌─────────────────────────────────────────────────────────┐
│                  CAPA DE APLICACIÓN                     │
│  - Dashboard: _____________________________________      │
│  - App móvil: ______________________________________     │
│  - Alertas: ________________________________________     │
└─────────────────────────────────────────────────────────┘
                              ▲
                              │
                              ▼
┌─────────────────────────────────────────────────────────┐
│                     CAPA DE RED                         │
│  - Protocolo: _____________ (WiFi/LoRa/4G/NB-IoT)      │
│  - Gateway: ________________________________________    │
│  - Edge computing: [ ] Sí [ ] No                       │
└─────────────────────────────────────────────────────────┘
                              ▲
                              │
                              ▼
┌─────────────────────────────────────────────────────────┐
│                   CAPA DE PERCEPCIÓN                    │
│  Sensores:                                             │
│    1. _______________ (cantidad: _____)                │
│    2. _______________ (cantidad: _____)                │
│    3. _______________ (cantidad: _____)                │
│  Actuadores:                                           │
│    1. _______________ (cantidad: _____)                │
│    2. _______________ (cantidad: _____)                │
└─────────────────────────────────────────────────────────┘
```

### Paso 4: Especificaciones Técnicas (15 min)

**Sensores:**

| Sensor | Especificación | Costo unitario | Cantidad | Total |
|--------|----------------|----------------|----------|-------|
| | | | | |
| | | | | |

**Conectividad:**
- Protocolo: _________ (justificación: ___________)
- Frecuencia de transmisión: _________
- Gateway: _________ (costo: $_______)

**Plataforma:**
- Proveedor: _________ (AWS/Azure/Google/On-premise)
- Costo mensual estimado: $_______
- Escalabilidad: _________ dispositivos

### Paso 5: Beneficios y Métricas (10 min)

**KPIs (Key Performance Indicators):**

| KPI | Línea base | Meta 1 año | Métrica |
|-----|------------|------------|---------|
| | | | |
| | | | |
| | | | |

**Beneficios cualitativos:**
1. _____________________________
2. _____________________________
3. _____________________________

### Paso 6: Desafíos y Riesgos (10 min)

**Técnicos:**
- [ ] Interoperabilidad
- [ ] Escalabilidad
- [ ] Mantenimiento
- Otro: _________

**Sociales:**
- [ ] Privacidad
- [ ] Aceptación ciudadana
- [ ] Brecha digital
- Otro: _________

**Económicos:**
- [ ] ROI incierto
- [ ] Costo operación
- [ ] Financiamiento
- Otro: _________

**Mitigaciones:**
Para cada riesgo identificado, proponga al menos una mitigación.

### Paso 7: Consideraciones de Privacidad (10 min)

**Datos recopilados:**

| Dato | ¿Es personal? | ¿Requiere consentimiento? | ¿Cómo se protege? |
|------|---------------|---------------------------|------------------|
| | | | |

**Cumplimiento Ley 1581:**
- [ ] Política de privacidad
- [ ] Autorización explícita
- [ ] Derechos ARCO implementados
- [ ] Minimización de datos

---

## Rúbrica de Evaluación

| Criterio | 4 - Excelente | 3 - Bueno | 2 - Aceptable | 1 - Insuficiente |
|----------|---------------|-----------|---------------|------------------|
| **Arquitectura** | Diagrama completo con capas claras | Diagrama básico | Diagrama incompleto | Sin diagrama |
| **Tecnología** | Sensores/actuadores específicos y apropiados | Lista genérica | Tecnología limitada | Sin especificación |
| **Beneficios** | 3+ métricas cuantificables | 2 métricas cualitativas | 1 beneficio genérico | Sin beneficios |
| **Desafíos** | Técnicos, sociales y económicos con mitigaciones | 1-2 tipos de desafíos | Solo desafíos obvios | Sin análisis |
| **Privacidad** | Análisis profundo de riesgos y mitigaciones | Menciona privacidad básica | Mínima consideración | Sin mención |
| **Contexto Medellín** | Específico con datos locales | Menciona contexto genérico | Sin contexto local | Desconectado |

**Calificación:** Suma / 24 × 100%

---

## Ejemplo Resumido: Monitoreo Calidad Aire

### Resumen Ejecutivo

Red de 200 sensores IoT para monitoreo hiperlocal de calidad del aire en Medellín. Resolución de 500m (vs 5km actual), con alertas tempranas a ciudadanía y autoridades.

### Arquitectura Resumida

```
Sensores (PM2.5, PM10, O3, NO2) → LoRaWAN → Gateway → AWS → App + Dashboard
    |                                                            |
    ↓                                                            ↓
Solar + batería (7 días)                          API pública + Alertas push
```

### Beneficios

| KPI | Línea base | Meta |
|-----|------------|------|
| Cobertura comunas | 50% | 100% |
| Alertas anticipación | 30 min | 2 horas |
| Consultas respiratorias | - | -20% |
| Costo estación | $500K | $30K |

### Costos

| Fase | Inversión |
|------|-----------|
| Piloto (20 nodos) | $3M COP |
| Expansión (180 nodos) | $27M COP |
| Plataforma | $15M COP |
| Mantenimiento/año | $30M COP |
| **TOTAL** | **$75M COP** |

### ROI

Ahorro en salud: ≈ $200M COP/año
Payback: **4.5 meses**

---

**[← Volver a README](README.md) | [Ir a Referencias →](referencias.md)**
