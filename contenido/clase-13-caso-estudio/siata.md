# Caso SIATA - Análisis Completo

**Clase 13: Caso de Estudio | Unidad 2**

## Visión General

**SIATA** = Sistema de Alerta Temprana de Medellín y Valle de Aburrá

### Contexto

- **Ubicación:** Medellín y 9 municipios del Valle de Aburrá
- **Población protegida:** 2.5 millones de habitantes
- **Inversión total:** $2.5M USD (fase 1) + $8M USD (fases 2-3)
- **Operador:** Área Metropolitana del Valle de Aburrá (AMVA)

## Arquitectura Técnica

### Infraestructura de Sensores

```
┌─────────────────────────────────────────────────────────────┐
│                     SIATA - NUBE (AWS)                        │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐  ┌──────────┐  │
│  │ Portal   │  │  API     │  │ Analytics│  │  Móvil   │  │
│  │  Web     │  │  Pública │  │  (ML)    │  │   App    │  │
│  └──────────┘  └──────────┘  └──────────┘  └──────────┘  │
└─────────────────────────────────────────────────────────────┘
                              ▲ 4G/LTE
                              │
┌─────────────────────────────────────────────────────────────┐
│                    GATEWAYS SIATA (6)                      │
│  Gateway ──[4G]──> Nube                                    │
│    LoRa                                                  │
└─────────────────────────────────────────────────────────────┘
                              ▲ LoRaWAN (15 km)
                              │
┌─────────────────────────────────────────────────────────────┐
│                    RED DE SENSORES                         │
│  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐    │
│  │Estación │  │ Estación│  │  Radar  │  │Hidro    │    │
│  │clima    │  │calidad │  │meteo    │  │sensores │    │
│  │ (50)    │  │aire (20)│  │ (2)     │  │ (30)    │    │
│  └─────────┘  └─────────┘  └─────────┘  └─────────┘    │
└─────────────────────────────────────────────────────────────┘
```

### Especificaciones de Sensores

| Tipo | Modelo | Parámetros | Frecuencia | Ubicación |
|------|--------|------------|------------|-----------|
| **Estación climática** | Davis Vantage Pro 2 | Temp, HR, presión, lluvia, viento | Cada 1 min | 50 sitios |
| **Calidad aire** | MetOne ES-642 | PM10, PM2.5, O3, NO2, SO2, CO | Cada 15 min | 20 sitios |
| **Radar meteorológico** | EEC Meteor 600S | Reflevidadidad, velocidad viento | Cada 5 min | 2 torres |
| **Nivel quebradas** | Sensor nivel presión | Altura agua (cm) | Cada 5 min | 30 quebradas |

## Caso de Éxito: Alerta de Inundación 23 Mayo 2022

### Cronología

| Hora | Evento | Acción SIATA |
|------|--------|---------------|
| 22:30 | Sensor quebrada Santa Elena detecta nivel crítico | Edge AI confirma patrón de crecida |
| 22:32 | Algoritmo predice desbordamiento en 45 min | Alerta masiva (App + SMS + sirenas) |
| 22:35 | 2,500 personas evacuadas | 0 víctimas vs 12 en evento similar 2015 |
| 22:45 | Quebrada se desborda | Daños minimizados |
| 23:30 | Nivel baja | Fin alerta |

### ROI del Evento

| Métrica | Valor |
|---------|-------|
| Vidas salvadas | 2,500 (potencialmente) |
| Daños evitados | $8M USD |
| Costo operación | $500 USD |
| ROI del evento | 16,000x |

## Análisis de Datos SIATA

### Dataset Histórico (2017-2024)

```
Años de datos: 7
Registros totales: 2.6 billones
Tamaño: 45 TB
Frecuencia de actualización: 15 min - 1 hora
```

### Modelo Predictivo de Inundación

```python
# Simplificado
from sklearn.ensemble import RandomForestClassifier

# Features
features = [
    'nivel_quebrada_1h_antes',
    'nivel_quebrada_2h_antes',
    'precipitacion_24h',
    'saturacion_suelo',
    'caudal_río'
]

# Modelo entrenado (2017-2022)
model = RandomForestClassifier(n_estimators=100)
model.train(datos_historicos)

# Predicción en tiempo real
def predecir_riesgo(nivel_actual, precipitacion):
    riesgo = model.predict_proba([[nivel_actual, precipitacion, ...]])
    return riesgo[1]  # Probabilidad de inundación 0-1
```

**Precisión:** 94% (sensibilidad), 89% (especificidad)

## Lecciones Aprendidas

### Éxitos

1. **Sensorización densa:** 50 estaciones vs 10 tradicionales
2. **Edge AI:** Predicción local antes de enviar a nube
3. **Multi-canal:** App, SMS, sirenas, radio
4. **Colaboración:** AMVA + EPM + Ruta N + SIATA

### Desafíos Superados

1. **Conectividad rural:** LoRaWAN con 15 km de alcance
2. **Calibración sensores:** Protocolo manual vs automático
3. **Adopción ciudadana:** Campañas educativas
4. **Sostenibilidad financiera:** Modelo público-privado

## Aplicabilidad a Otras Ciudades

### Checklist para Replicar SIATA

| Componente | ¿Esencial? | Alternativa |
|-------------|-------------|-------------|
| **Red de sensores** | Sí | Menos densa al inicio |
| **Radar meteorológico** | Deseable | Datos de terceros |
| **Edge AI** | Sí | Cloud AI (mayor latencia) |
| **App ciudadana** | Sí | SMS solos |
| **Sirenas** | Sí | Solo alerta digital |
| **Modelo predictivo** | Sí | Umbrales simples |

---

**[← Volver a README](README.md)**
