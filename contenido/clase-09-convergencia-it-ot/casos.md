# Casos: Convergencia IT-OT en Colombia

**Clase 9: Convergencia IT-OT | Unidad 2**

## Caso 1: Ecopetrol - Campo Llanito 🛢️

### Contexto

- **Ubicación:** Campo Llanito, Puerto Boyacá, Colombia
- **Producción:** 35,000 barriles/día
- **Inversión IT-OT:** $12M USD (2018-2022)

### Antes de Convergencia

| Aspecto | Situación |
|---------|-----------|
| Datos producción | Reportes manuales |
| Mantenimiento | Preventivo (calendario) |
| Decisiones | Basadas en experiencia |
| Conectividad | Radio limitada |

### Solución Implementada

```
┌─────────────────────────────────────────────────┐
│              CLOUD AWS                          │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐     │
│  │  SAP APO │  │ Analytics│  │ Mobile   │     │
│  └──────────┘  └──────────┘  └──────────┘     │
└─────────────────────────────────────────────────┘
              ▲
              │ Starlink (35 Mbps)
              ▼
┌─────────────────────────────────────────────────┐
│           EDGE GATEWAY (Planta)                 │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐     │
│  │ SCADA    │  │ Historian│  │ Pred.Mant.│     │
│  └──────────┘  └──────────┘  └──────────┘     │
└─────────────────────────────────────────────────┘
              ▲
              │ Modbus, Profibus
              ▼
┌─────────────────────────────────────────────────┐
│            PLENA (POZO)                          │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐     │
│  │ PLCs     │  │ Sensores │  │ VFD      │     │
│  └──────────┘  └──────────┘  └──────────┘     │
└─────────────────────────────────────────────────┘
```

### Resultados

| KPI | Antes | Después | Mejora |
|-----|-------|---------|--------|
| Uptime pozos | 92% | 97% | +5% |
| Mantenimiento no planificado | 25% | 8% | -68% |
| Tiempo detección falla | 24-48h | 4-8h | -80% |
| Producción | 32,000 b/d | 35,000 b/d | +9% |

## Caso 2: Cervecería Bavaria - Corona

### Contexto

- **Ubicación:** Tocancipá, Colombia
- **Capacidad:** 10 millones HL/año
- **Inversión IT-OT:** $8M USD

### Solución

| Componente IT | Componente OT | Integración |
|----------------|----------------|-------------|
| SAP ERP | PLCs Siemens | OPC UA |
| Power BI | SCADA | SQL Server |
| Mobile Apps | HMI panel | MQTT + REST |

### Resultados

- **OEE:** 78% → 87% (+11%)
- **Rechazo producto:** 2.5% → 0.8% (-68%)
- **Costo calidad:** -$1.2M/año

## Caso 3: Cementos Argos - Sogamoso

### Contexto

- **Ubicación:** Sogamoso, Boyacá
- **Producción:** 1.5M toneladas/año

### Convergencia IT-OT

```
Sensores de vibración → Modbus TCP → Edge Dell → AWS
                                                     ↓
                                           Machine Learning
                                                     ↓
                                           Predicción fallas
                                                     ↓
                                     Orden de mantenimiento
```

### Resultados

| Métrica | Valor |
|---------|-------|
| Disponibilidad molinos | +7% |
| Costo mantenimiento | -15% |
- ROI | 18 meses |

---

**[← Volver a README](README.md)**
