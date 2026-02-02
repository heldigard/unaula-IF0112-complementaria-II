# Casos de Estudio: IoT en Acción

**Clase 1: Evolución de Internet | Unidad 1**

## Caso Principal: Medellín, Colombia 🇨🇴

### Visión General

Medellín se ha posicionado como referente en Smart Cities en Latinoamérica, transformándose de la "ciudad más violenta del mundo" (1991) a "Ciudad del Año" según Wall Street Journal (2013).

**Inversión total en IoT 2015-2025:** ~$72.5M USD

---

## 1. Transporte Inteligente: Metro de Medellín

### Especificaciones Técnicas

| Componente | Cantidad | Especificación |
|------------|----------|----------------|
| Buses equipados | 500+ | GPS +_validación tarjeta |
| App Usuarios | 2M+ descargas | Mi Metro, Metro Med |
| Tarjeta Cívica | 4M+ activas | Validación < 300ms |
| Centro control | 1 | Monitoreo 24/7 |

### Arquitectura del Sistema

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│   Bus IoT   │───→│   Gateway   │───→│    Cloud    │
│ (GPS+Valid) │ 4G │   Móvil     │    │  (AWS/Azure)│
└─────────────┘    └─────────────┘    └─────────────┘
                                              │
                    ┌─────────────────────────┘
                    │
           ┌────────▼────────┐
           │  App Usuario    │
           │ (posición real) │
           └─────────────────┘
```

### Impacto Medido

| Métrica | Antes | Después | Mejora |
|---------|-------|---------|--------|
| Tiempo espera promedio | 18 min | 12 min | **-33%** |
| Satisfacción usuarios | 67% | 85% | **+18 pts** |
| Oleadas fraudulentas | 12% | <1% | **-92%** |
| Optimización rutas | Manual | Automática | **+20%** eficiencia |

### ROI del Proyecto

- **Inversión:** $15M USD (2018-2023)
- **Ahorro anual:** $3.5M USD
- **Payback:** 4.3 años
- **Beneficios no monetarios:**
  - +2M usuarios diarios mejor informados
  - -15% emisiones por mejor ruteo
  - +25% usuarios satisfechos

---

## 2. Seguridad: Centro CUIC (Centro Urbano de Información y Control)

### Infraestructura

| Componente | Cantidad | Capacidad |
|------------|----------|-----------|
| Cámaras IA | 800+ | Reconocimiento facial |
| Sensores | 500+ | Movimiento, sonido |
> | Centro de mando | 1 | Sala crisis 24/7 |
| Analistas | 50 | Monitoreo activo |

### Flujo de Detección y Respuesta

```
┌─────────────┐   ┌─────────────┐   ┌─────────────┐
│ Cámara IA   │──→│ Edge Server │──→│   Cloud     │
│ detecta     │   │ analiza     │   │ correlaciona│
│ anomalía    │   │ localmente  │   │ histórico   │
└─────────────┘   └─────────────┘   └─────────────┘
                      │                   │
                      ▼                   ▼
               ┌─────────────┐     ┌─────────────┐
               │  Alerta     │     │  Patrulla   │
               │  inmediata  │     │  despachada │
               └─────────────┘     └─────────────┘
```

### Resultados 2020-2024

| Métrica | 2020 | 2024 | Cambio |
|---------|------|------|--------|
| Homicidios/100k | 12.4 | 8.1 | **-35%** |
| Hurtos | 18,200 | 14,500 | **-20%** |
| Recuperación vehículos | 42% | 67% | **+60%** |
| Tiempo respuesta | 12 min | 4 min | **-67%** |
| Sensación seguridad | 38% | 56% | **+18 pts** |

### ROI del Proyecto

- **Inversión:** $10M USD (2019-2024)
- **Ahorro anual (estimado):** $25M USD
  - Menor tiempo policía
  - Mayor recuperación activos
  - Turismo incremental
- **Payback:** 0.4 años

---

## 3. Servicios Públicos: EPM Smart Grid

### Medidores Inteligentes

| Especificación | Valor |
|----------------|-------|
| Unidades instaladas | 500,000 |
| Tecnologías | Zigbee + PLC |
| Frecuencia lectura | Cada 15 min |
| Vida útil medidor | 15+ años |

### Arquitectura del Smart Grid

```
┌──────────────┐    ┌──────────────┐    ┌──────────────┐
│  Medidor     │    │  Concentrador│    │     EPM      │
│  Zigbee/PLC  │←──→│  (WiFi/4G)   │←──→│     Cloud    │
│  (casa)      │    │  (manzana)   │    │   (AWS)      │
└──────────────┘    └──────────────┘    └──────────────┘
                                              │
                    ┌─────────────────────────┘
                    │
           ┌────────▼────────┐
           │   Usuario App   │
           │  consumo real   │
           └─────────────────┘
```

### Casos de Uso

1. **Detección de fugas:** Alerta si consumo > patrón habitual
2. **Factura precisa:** Sin lecturas manuales
3. **Gestión demanda:** Apagado remoto durante picos

### Resultados

| Métrica | Antes | Después | Mejora |
|---------|-------|---------|--------|
| Pérdidas técnicas | 18% | 15% | **-17% relativo** |
| Lecturas manuales | 100% | 0% | **-100%** |
| Quejas facturación | 2,500/mes | 400/mes | **-84%** |
| Consumo promedio | 220 kWh/mes | 190 kWh/mes | **-14%** |

### ROI del Proyecto

- **Inversión:** $45M USD (2015-2020)
- **Ahorro anual:** $12M USD
  - $8M pérdidas reducidas
  - $3M lecturas eliminadas
  - $1M detección fraudes
- **Payback:** 3.75 años
- **Beneficio adicional:** Usuarios reducen consumo 14%

---

## 4. Alertas Tempranas: SIATA (Sistema de Alerta Temprana de Medellín)

### Componentes del Sistema

| Componente | Cantidad | Cobertura |
|------------|----------|-----------|
| Estaciones calidad aire | 50 | Toda ciudad |
| Estaciones climáticas | 40 | Valle Aburrá |
| Radares meteorológicos | 2 | 100km radio |
| Hidro sensores | 30 | Quebradas |
| Usuarios app | 500,000 | 2.5M habitantes |

### Arquitectura SIATA

```
┌─────────────┐    ┌─────────────┐    ┌─────────────┐
│   Sensores  │───→│  Edge       │───→│    Cloud    │
│ (distribui- │ LoRa│  Analytics  │ 4G │  (AWS)     │
│  dos)       │    │  local      │    │            │
└─────────────┘    └─────────────┘    └─────────────┘
                                            │
                      ┌─────────────────────┘
                      │
         ┌────────────▼─────────────┐
         │  Múltiples Canales       │
         ├────────┬────────┬─────────┤
         │   App  │   SMS  │   Web  │
         │  500K  │   1M   │  100K  │
         └────────┴────────┴─────────┘
```

### Caso de Éxito: Alerta de Inundación

**Evento 23 mayo 2022:**

1. **22:30** - Sensor quebrada Santa Elena detecta nivel crítico
2. **22:32** - Edge AI confirma patrón de crecida
3. **22:33** - Alerta masiva a zona (App + SMS + altavoces)
4. **22:45** - 2,500 personas evacuadas
5. **23:15** - Quebrada se desborda
6. **Resultado:** 0 víctimas vs 12 en evento similar 2015

### Resultados Globales

| Métrica | Valor |
|---------|-------|
| Inversión | $2.5M USD |
| Daños evitados/año | $8M USD |
| Alertas enviadas/año | 2.5M+ |
| Precipitación detectada | 48h antes |
| Tiempo anticipación | 2-4 horas antes |
| Habitantes protegidos | 2.5M |

### ROI del Proyecto

- **Inversión:** $2.5M USD
- **Beneficio anual:** $8M USD (daños evitados)
- **Payback:** 0.3 años
- **Intangible:** Vidas salvadas (incalculable)

---

## 5. Comparativa: Smart Cities Latinoamericanas

### Métricas Comparativas

| Ciudad | Población | Inversión IoT | Proyectos clave | ROI estimado |
|:------:|:---------:|:-------------:|-----------------|:------------:|
| 🇧🇷 Rio | 6.7M | $120M | Centro de Operações, iluminación | 3.2 años |
| 🇲🇽 CDMX | 9.2M | $85M | SEDEMA aire, Semáforos AI | 4.1 años |
| 🇦🇷 BA | 3.1M | $65M | BA Electrónica, sensores sonido | 3.8 años |
| 🇨🇱 Santiago | 6.1M | $45M | Metro inteligente, alerta sismos | 2.9 años |
| 🇨🇴 Medellín | 2.5M | $72.5M | SIATA, CUIC, EPM | 2.8 años |

### Factores de Éxito Comunes

| Factor | Descripción | Ejemplo |
|--------|-------------|---------|
| **Alianzas** 🤝 | Público-privado-academia | Medellín: EPM + Ruta N + Universidades |
| **Datos abiertos** 📊 | Transparencia + innovación | CDMX: API abierta calidad aire |
| **Infraestructura** 🔌 | Fibra, 4G/5G desde antes | Santiago: fibra desde 2000s |
| **Adopción ciudadana** 📱 | Apps con alta penetración | Rio: 1.5M usuarios apps ciudadanas |
| **Liderazgo político** 🏛️ | Continuidad más de 1 administración | Medellín: 4 alcaldías consecutivas |

---

## Matriz de Análisis: Viabilidad de Proyectos IoT

Use esta matriz para evaluar proyectos IoT municipales:

| Criterio | Peso | Medellín (ejemplo) | Cómo evaluar |
|----------|------|-------------------|--------------|
| **Impacto social** | 30% | 9/10 | Número beneficiados |
| **Viabilidad técnica** | 25% | 8/10 | Infraestructura existente |
| **ROI financiero** | 20% | 9/10 | Payback < 5 años |
| **Sostenibilidad política** | 15% | 8/10 | Apoyo multi-partido |
| **Escalabilidad** | 10% | 7/10 | Posible replicar |

**Puntuación total:** (Peso × Nota) / 100
- > 8.0: Prioridad alta
- 6.0-8.0: Viable con ajustes
- < 6.0: No recomendado

---

**[← Volver a README](README.md) | [Ir a Ejercicios →](ejercicios.md)**
