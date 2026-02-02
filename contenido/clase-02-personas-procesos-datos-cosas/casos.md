# Casos de Estudio: P-P-D-C en Acción

**Clase 2: Personas, Procesos, Datos y Cosas | Unidad 1**

## Caso 1: Hogar Inteligente 🏠

### Visión General

Un sistema de domótica completo que integra los 4 pilares para crear un hogar seguro, eficiente y confortable.

### Análisis P-P-D-C

#### 👤 Personas

| Rol | Perfil | Responsabilidades |
|-----|--------|-------------------|
| **Usuario Primario** | Padre de familia | Configura reglas generales |
| **Usuario Secundario** | Madre, hijos | Controla dispositivos |
| **Administrador** | Padre (tech-savvy) | Gestiona sistema, troubleshooting |
| **Visitante** | Familiares, amigos | Acceso limitado (huésped) |

**Interfaces:**
- App móvil (iOS/Android)
- Panel táctil en pared
- Asistente de voz (Alexa/Google)
- Navegador web

#### ⚙️ Procesos

**Proceso 1: Control de Iluminación**
```
IF: Ninguna persona detectada por 10 min
AND: Luces encendidas
THEN: Apagar luces automáticamente
```

**Proceso 2: Modo Noche**
```
IF: Hora >= 22:00
AND: Presencia detectada en pasillo
THEN: Encender luces al 30% (modo ambience)
```

**Proceso 3: Alerta de Seguridad**
```
IF: Puerta/ventana se abre
AND: Sistema armado
AND: No reconocido como "autorizado"
THEN: Activar sirena + notificar + grabar video
```

**Proceso 4: Eficiencia Energética**
```
IF: Temperatura > 28°C
AND: Ventanas cerradas
AND: Horario en casa (no vacaciones)
THEN: Encender A/C hasta temp = 24°C
```

#### 📊 Datos

| Tipo de Dato | Fuente | Frecuencia | Retención |
|--------------|--------|------------|-----------|
| Temperatura | 5 sensores | Cada 5 min | 90 días |
| Humedad | 3 sensores | Cada 5 min | 90 días |
| Presencia | 8 sensores PIR | Evento | 30 días |
| Energía consumo | Smart meter | Cada 1 min | 365 días |
| Eventos seguridad | Cámaras | Evento | 180 días |
| Estado dispositivos | Todos | Cambio de estado | 30 días |

**Flujo de Datos:**
```
Sensores →[Zigbee]→ Gateway →[WiFi]→ Nube →[REST]→ Apps
   ↓                                           ↓
 Local (Edge)                              Dashboard Web
```

#### 📱 Cosas

**Sensores:**
- 5× Sensores temperatura/humedad (DHT22)
- 8× Sensores presencia PIR
- 8× Sensores apertura puertas/ventanas
- 1× Medidor energético (Zigbee)
- 4× Cámaras IP (interior/exterior)

**Actuadores:**
- 12× Bombillas LED RGB (Zigbee)
- 4× Interruptores inteligentes
- 1× Termostato conectado
- 1× Cerradura inteligente
- 2× Enchufes inteligentes
- 1× Sistema de sonido multiroom

**Centrales:**
- 1× Gateway IoT (Zigbee + Z-Wave + WiFi)
- 1× Hub de almacenamiento local (NVR)
- 1× UPS para respaldo

---

## Caso 2: Agricultura Inteligente - Colombia 🌾🇨🇴

### Visión General

Implementación de IoT en el cultivo de arroz en el departamento del Meta, Colombia. Un proyecto conjunto entre FEDEARROZ y productores locales.

### Análisis P-P-D-C

#### 👤 Personas

| Rol | Perfil | Responsabilidades |
|-----|--------|-------------------|
| **Agricultor** | Productor dueño del cultivo | Toma decisiones de riego, siembra |
| **Agrónomo** | Experto contratado | Interpreta datos, hace recomendaciones |
| **Operario** | Trabajador de campo | Ejecuta acciones físicas (riego) |
| **Técnico IoT** | Mantenimiento | Instala, calibra, repara sensores |
| **Analista** | FEDEARROZ | Genera reportes, insights agregados |

#### ⚙️ Procesos

**Proceso 1: Riego Automático**
```
IF: Humedad suelo < 30%
AND: Lluvia pronosticada = NO en 48h
AND: Hora entre 06:00-18:00 (evitar evaporación)
THEN: Activar riego goteo por 15 min
```

**Proceso 2: Alerta de Estrés**
```
IF: NDVI (índice de vegetación) < 0.4
OR: Temperatura > 35°C por >4h
THEN: Notificar agrónomo para evaluación
```

**Proceso 3: Fertilización Variable**
```
IF: Sensor N (nitrógeno) indica deficiencia en zona X
THEN: Ajustar dosis fertilizadora en zona X por +20%
```

**Proceso 4: Predicción Cosecha**
```
IF: Datos acumulados durante ciclo
THEN: Estimar fecha cosecha ± 3 días
AND: Notificar agricultor 2 semanas antes
```

#### 📊 Datos

| Tipo de Dato | Fuente | Frecuencia | Retención |
|--------------|--------|------------|-----------|
| Humedad suelo | 50 sensores capacitivos | Cada 15 min | 5 años |
| Temperatura aire | 5 estaciones clima | Cada 5 min | 10 años |
| Precipitación | Estación pluviométrica | Evento | 10 años |
| NDVI | Drones + satélite | Semanal | 10 años |
| GPS maquinaria | tractores equipados | Continuo | 2 años |
| N, P, K suelo | Sensores iónicos | Semanal | 5 años |
| Flujo agua | Medidores caudal | Cada 5 min | 5 años |

**Flujo de Datos:**
```
Sensores →[LoRaWAN]→ Gateway rural →[4G]→ Nube AWS
                                            ↓
                                    Analytics + ML
                                            ↓
                                    App (agricultor)
                                    Dashboard (agrónomo)
                                    Reportes (FEDEARROZ)
```

#### 📱 Cosas

**Sensores:**
- 50× Sensores humedad suelo (capacitivos, 0-100 cm)
- 5× Estaciones climáticas completas
- 1× Estación pluviométrica
- 2× Drones con cámara NDVI
- 10× Sensores de nivel tanque agua
- 5× Sensores NPK en suelo

**Actuadores:**
- 50× Válvulas solenoides (control riego goteo)
- 5× Bombas de riego (VFD)
- 1× Sistema fertirrigación automático
- 3× Drones fumigadores (autónomos)

**Infraestructura:**
- 3× Gateways LoRaWAN (cobertura 15 km)
- 1× Panel solar + batería (gateway rural)
- 1× Router 4G (conexión nube)
- 1× Servidor edge local (backup)

### Resultados Medidos

| Métrica | Antes | Después | Mejora |
|---------|-------|---------|--------|
| Agua por hectárea | 18,000 m³ | 10,800 m³ | **-40%** |
| Producción qq/ha | 15 qq | 19 qq | **+27%** |
| Fertilizante uso | 100% | 70% | **-30%** |
| Costos operativos | $2.5M/ha | $1.7M/ha | **-32%** |
| Horas hombre/ha | 120 h | 80 h | **-33%** |

**ROI:**
- Inversión inicial: $5,000/ha (sensores + infraestructura)
- Ahorro anual: $800,000/ha
- Payback: **6.25 años**

---

## Caso 3: FEDEARROZ - "Arroz Sostenible" 🍚

### Contexto

**FEDEARROZ** (Federación Nacional de Arroceros) implementó un programa masivo de IoT para productores de arroz en Colombia.

### Escala

| Métrica | Valor |
|---------|-------|
| Productores participantes | 500+ |
| Hectáreas monitoreadas | 25,000+ ha |
| Sensores instalados | 2,500+ |
| Departamentos cubiertos | Tolima, Meta, Huila, Córdoba, Cesár |

### Arquitectura Técnica

```
┌─────────────────────────────────────────────────────────────┐
│                    NUBE AWS (SaaS)                          │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐   │
│  │ Dashboard│  │ Analytics│  │  Móvil   │  │ Alertas  │   │
│  │  Web     │  │   ML     │  │   App    │  │ SMS/Push │   │
│  └──────────┘  └──────────┘  └──────────┘  └──────────┘   │
└─────────────────────────────────────────────────────────────┘
                              ▲
                              │ 4G/LTE
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                   GATEWAY RURAL (por finca)                 │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐                  │
│  │ LoRaWAN  │  │  Solar   │  │   Edge   │                  │
│  │ Gateway  │  │  Panel   │  │ Compute  │                  │
│  └──────────┘  └──────────┘  └──────────┘                  │
└─────────────────────────────────────────────────────────────┘
                              ▲
                              │ LoRaWAN (15 km)
                              ▼
┌─────────────────────────────────────────────────────────────┐
│                       SENSORES                              │
│  ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐ ┌─────┐         │
│  │Temp │ │Hum  │ │Lluvi│ │NPK  │ │Nivel│ │GPS  │         │
│  │aire │ │suelo│ │a    │ │suelo│ │agua │ │maq  │         │
│  └─────┘ └─────┘ └─────┘ └─────┘ └─────┘ └─────┘         │
└─────────────────────────────────────────────────────────────┘
```

### Análisis P-P-D-C

#### 👤 Personas

| Rol | Cantidad | Formación | Digital |
|-----|----------|-----------|---------|
| Productores | 500+ | Variada | App móvil |
| Técnicos regionales | 25 | Ingenieros agrónomos | Dashboard |
| Analistas centrales | 5 | Data scientists | Python, SQL |
| Soporte técnico | 10 | Electrónica | Tickets |

#### ⚙️ Procesos

**Recomendación de Riego (IA):**
```
INPUT: Humedad suelo (30% a 100 cm) + Clima (48h pronóstico) +
       Fenología del cultivo + Variedad de arroz

PROCESO: Random Forest entrenado con 10 años de datos históricos

OUTPUT: Recomendación:
  - "No regar hoy (lluvia esperada)"
  - "Riego 15 mm mañana amanecer"
  - "Riego 20 mm hoy noche (no hay lluvia)"
```

**Alerta de Plaga:**
```
IF: Condiciones favorables a plaga X (temp + humedad)
AND: Modelo predictivo indica riesgo > 60%
THEN: Notificar productor + técnico regional
     + Recomendar acción preventiva
```

#### 📊 Datos

| Dataset | Registros | Frecuencia | Uso |
|---------|-----------|------------|-----|
| Clima (10 años) | 2.6M | 5 min | Entrenamiento IA |
| Suelo (2 años) | 870K | 15 min | Riego en tiempo real |
| Satellite NDVI | 15K | Semanal | Salud cultivo |
| Producción | 2.5K | Por cosecha | Validación modelos |

#### 📱 Cosas

**Costo por hectárea:**
- Sensores: $150 (5 sensores/ha)
- Gateway: $500 (compartido, ~100 ha)
- Instalación: $50
- **Total:** ~$200/ha

**Especificaciones técnicas:**
- Sensores: LoRaWAN Class A (batería 5+ años)
- Gateway: LoRaWAN + 4G + solar
- App: Android 6+ (offline mode)

### Impacto Medido

| KPI | Valor | Fuente |
|-----|-------|--------|
| Ahorro agua | 35% promedio | Medidores caudal |
| Aumento producción | 18% promedio | Rendimiento qq/ha |
| Reducción costos | $800K/ha/año | OpEx |
| ROI productor | 18 meses | Encuesta |
| Satisfacción | 85% | NPS |
| Adopción | 500 → 800 (2024-2026) | Activaciones |

---

## Caso 4: FNC - "Cosecha Bluetooth" ☕

### Contexto

La **Federación Nacional de Cafeteros de Colombia** implementó IoT para pequeños productores de café.

### Desafío

- **Productores:** 500,000 (80% con < 5 ha)
- **Distribución:** Rural, zonas montañosas
- **Conectividad:** Limitada
- **Presupuesto:** Bajo (< $200/productor)

### Solución

**App móvil + Bluetooth Low Energy (BLE)**

```
┌─────────────────┐          ┌─────────────────┐
│   Productor     │          │   Cafetero      │
│   (campo)       │  BLE     │   (recibe)      │
│                 │  <─────> │                 │
│  ┌───────────┐  │          │  ┌───────────┐  │
│  │   App     │  │          │  │   App     │  │
│  │ Móvil     │  │          │  │ Móvil     │  │
│  └───────────┘  │          │  └───────────┘  │
│       ↓         │                      ↓     │
│  ┌───────────┐  │               ┌──────────┐ │
│  │  Sensores │  │               │ Pago     │ │
│  │  BLE      │  │               │ Nequi    │ │
│  └───────────┘  │               └──────────┘ │
└─────────────────┘          └─────────────────┘
```

### Análisis Simplificado P-P-D-C

| Pilar | Implementación |
|-------|----------------|
| 👤 **Personas** | Productor (datos) + Cafetero (compra) |
| ⚙️ **Procesos** | "Si calidad > 85 → precio premium" |
| 📊 **Datos** | Peso, humedad, variedad, GPS, fecha |
| 📱 **Cosas** | Báscula Bluetooth + Sensor humedad + Smartphone |

### Resultados

| Métrica | Resultado |
|---------|-----------|
| Fincas conectadas | 10,000+ |
| Precisión predicción cosecha | 85% |
| Incremento precio | 8-12% (calidad certificada) |
| Transparencia | +40% vs tradicional |

---

## Matriz de Análisis: Viabilidad de Proyectos IoT

Use esta matriz para evaluar proyectos IoT antes de implementar:

| Criterio | Peso | Proyecto A | Proyecto B | Proyecto C |
|----------|------|------------|------------|------------|
| **Impacto Social** | 25% | 8 | 6 | 9 |
| **Viabilidad Técnica** | 20% | 7 | 9 | 4 |
| **ROI Financiero** | 20% | 8 | 5 | 7 |
| **Sostenibilidad** | 15% | 6 | 7 | 8 |
| **Escalabilidad** | 10% | 5 | 8 | 3 |
| **Riesgo Legal** | 10% | 9 | 7 | 6 |
| **TOTAL** | 100% | **7.3** | **6.7** | **6.6** |

**Escala de evaluación:**
- 9-10: Excelente, proceder
- 7-8: Bueno, con ajustes
- 5-6: Aceptable, requiere análisis adicional
- < 5: No recomendado

---

**[← Volver a README](README.md) | [Ir a Ejercicios →](ejercicios.md)**
