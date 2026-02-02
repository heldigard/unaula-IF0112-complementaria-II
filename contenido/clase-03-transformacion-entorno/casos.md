# Casos de Estudio: Transformación del Entorno

**Clase 3: Transformación del Entorno | Unidad 1**

## Caso 1: Grupo Nutresa - Planta 4.0 Tocancipá 🏭

### Contexto
- Primera planta de alimentos 100% conectada en LATAM
- Inversión: $25M USD (2018-2022)
- Certificación LEED Oro

### Arquitectura IoT Implementada

```
┌─────────────────────────────────────────────────────────┐
│                    CLOUD AWS                            │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐             │
│  │ Analytics│  │  AI/ML   │  │ Dashboard │             │
│  └──────────┘  └──────────┘  └──────────┘             │
└─────────────────────────────────────────────────────────┘
                              ▲
                              │ MQTT/TLS
                              ▼
┌─────────────────────────────────────────────────────────┐
│                   EDGE ON-PREMISE                        │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐             │
│  │ PLCs     │  │  SCADA   │  │  Historian│             │
│  └──────────┘  └──────────┘  └──────────┘             │
└─────────────────────────────────────────────────────────┘
                              ▲
                              │ Industrial Ethernet
                              ▼
┌─────────────────────────────────────────────────────────┐
│                      SENSORES Y ACTUADORES               │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐             │
│  │Temp/Humed│  │ Vibración│  │ Cámaras  │             │
│  │  (50+)   │  │ Motores  │  │  Vision  │             │
│  └──────────┘  └──────────┘  └──────────┘             │
└─────────────────────────────────────────────────────────┘
```

### Tecnologías Específicas

| Área | Tecnología | Proveedor | Resultado |
|------|------------|-----------|-----------|
| Control de procesos | PLC Siemens S7-1500 | Siemens | -40% variabilidad |
| Visión artificial | Cámaras Cognex + Deep Learning | Cognex | -90% empaques defectuosos |
| Sensores vibración | SKF Multilog IMx-16 | SKF | -75% fallos motores |
| Gemelo digital | NVIDIA Omniverse | NVIDIA | -25% prototipado físico |
| Blockchain trazabilidad | Hyperledger Fabric | Accenture | Trazabilidad 100% |

### Procesos IF-THEN Implementados

**Proceso 1: Pasteurización Inteligente**
```
IF: Temperatura < 72°C por >30s
THEN: Alerta operador + reducir velocidad línea
```

**Proceso 2: Control de Humedad (Galletas)**
```
IF: Humedad relativa > 55%
AND: Producto = galletas sensibles
THEN: Activar deshumidificadores zona 3
```

**Proceso 3: Mantenimiento Predictivo**
```
IF: Vibración eje > 4.5 mm/s
OR: Temperatura aceite > 85°C
THEN: Programar mantenimiento en 48h
```

### ROI Detallado

| Inversión | Ahorro Anual | Payback |
|-----------|--------------|---------|
| Sensores IoT ($5M) | $12M | 5 meses |
| Visión artificial ($8M) | $18M | 5.3 meses |
| Analytics ($7M) | $15M | 5.6 meses |
| Infraestructura ($5M) | - | - |
| **TOTAL $25M** | **$45M** | **6.7 meses** |

---

## Caso 2: EPM - Smart Grid 💡

### Infraestructura Desplegada

| Componente | Cantidad | Inversión | Estado |
|------------|----------|-----------|--------|
| Medidores AMI | 2.7M | $180M | 80% cobertura |
| Concentradores | 15,000 | $25M | Operativos |
| Data center | 1 | $35M | Activo |
| App móvil | 2.5M descargas | $5M | Activa |

### Especificaciones Técnicas del Medidor

```
Medidor: Landis+Gyr E450
├── Comunicación: Zigbee (home) + Cellular (backhaul)
├── Frecuencia lectura: 15 min
├── Memoria: 90 días datos
├── Precisión: ±1%
├── Relés: Desconexión remota
└── Seguridad: AES-256 + TLS 1.3
```

### App "EPM Móvil" - Features

| Feature | Descripción | Uso mensual |
|---------|-------------|-------------|
| Consulta consumo | Gráficos diarios/semanales/mensuales | 1.8M usuarios |
| Comparativa | Vs vecinos similares (anonimizada) | 900K usuarios |
| Alertas | Consumo alto, corte programado | 650K notificaciones |
| Simulador ahorro | "¿Qué pasa si...?" | 400K simulaciones |
| Reporte fallas | Georreferenciado + foto | 120K reportes |

### Resultados por Segmento

| Segmento | Antes | Después | Mejora |
|----------|-------|---------|--------|
| Pérdidas técnicas | 22% | 18% | -18% relativo |
| Detección fraudes | 2,500/mes | 6,200/mes | +148% |
| Satisfacción | 72% | 95% | +23 puntos |
| Llamadas call center | 180K/mes | 108K/mes | -40% |

---

## Caso 3: Siemens Amberg - Fábrica Perfecta 🏭

### Especificaciones

| Métrica | Valor |
|---------|-------|
| Productos por día | 50M variantes |
| Tasa de defectos | 0.00115% (99.99885% calidad) |
| Automatización | 75% |
| Empleados | 1,100 (mismo desde 1989) |
| Producción | 8x en 25 años |

### "Productos que Hablan"

Cada PLC (Programmable Logic Controller) Siemens producido:
- Tiene código único
- Se identifica en cada etapa de producción
- Transmite datos a su propio "gemelo digital"
- Si detecta anomalía, se reporta a sí mismo

### Proceso de Producción

```
Orden de producción → Gemelo digital simula → Plan optimizado
                                              ↓
                    Componentes ←→ RFID tracking
                                              ↓
                    Ensamblaje ←→ 1,000 estaciones automatizadas
                                              ↓
                    Pruebas ←→ Auto-test + validación
                                              ↓
                    Empaque ←→ Etiquetado automático
                                              ↓
                    Envío ←→ Integración logistics
```

---

## Caso 4: Singapur - Smart City 🇸🇬

### Smart Nation Initiative

| Iniciativa | Descripción | Inversión |
|------------|-------------|-----------|
| **Virtual Singapore** | Gemelo digital 3D de toda la ciudad | $73M |
| **Smart Health** | Telemedicina + monitoreo crónicos | $150M |
| **Smart Mobility** | Autonomous vehicles + ERP 2.0 | $500M |
| **National Digital Identity** | SingPass | $50M |
| **SenseOps** | Red de 100K+ sensores | $100M |

### SenseOps: Red de Sensores Masiva

```
Categorías de sensores:
├── Ambiente: PM2.5, PM10, O3, NO2, SO2, CO
├── Clima: Temperatura, humedad, lluvia, viento
├── Tráfico: Flujo vehicular, velocidad, ocupación
├── Agua: Nivel canales, calidad, presión
├── Energía: Consumo por edificio, smart meter
└── Seguridad: Cámaras, botones pánico, disparos

Total: 110,000 sensores (2024)
Meta: 200,000 sensores (2030)
```

### Datos Abiertos (data.gov.sg)

- 1,600+ datasets disponibles
- 200,000+ descargas mensuales
- APIs para desarrolladores
- Hackathones trimestrales

---

## Caso 5: Barcelona - Smart City Europe 🇪🇸

### Plataforma Sentilo

**Arquitectura Open Source:**
```
┌─────────────────────────────────────────────────┐
│              APLICACIONES (Apps)                 │
├─────────────────────────────────────────────────┤
│              Sentilo (Platform)                  │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐     │
│  │  API     │  │  Pub/Sub │  │ Almacenar │     │
│  └──────────┘  └──────────┘  └──────────┘     │
├─────────────────────────────────────────────────┤
│              PROTOCOL ADAPTERS                   │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐     │
│  │  HTTP    │  │  MQTT    │  │  CoAP    │     │
│  └──────────┘  └──────────┘  └──────────┘     │
├─────────────────────────────────────────────────┤
│              SENSORES Y ACTUADORES               │
└─────────────────────────────────────────────────┘
```

### Proyectos Destacados

| Proyecto | Sensores | Ahorro | Impacto |
|----------|----------|--------|---------|
| **Farolas LED** | 1,100 | 30% energía | $2.5M/año |
| **Riego inteligente** | 300 humedad | 25% agua | 100K m³ |
| **Contenedores basura** | 500 nivel | -20% recolección | -10% camiones |
| **Aparcamiento** | 400 inductivos | -20% tráfico | +30% rotación |
| **Bicing IoT** | 6,000 bicis | 50K viajes/día | 0 emisiones |

---

## Matriz de Comparación: Smart Cities

| Ciudad | Población | Inversión | Proyectos clave | Ranking 2024 |
|--------|-----------|-----------|-----------------|---------------|
| Singapur | 5.7M | $2B+ | Gemelo digital, e-ID | #1 Mundial |
| Barcelona | 1.6M | $300M | Sentilo, bicing | #3 Europa |
| Medellín | 2.5M | $180M | SIATA, C4, Metro | #1 LATAM |
| Seúl | 9.7M | $1.2B | 5G, Songdo | #2 Asia |

---

**[← Volver a README](README.md) | [Ir a Ejercicios →](ejercicios.md)**
