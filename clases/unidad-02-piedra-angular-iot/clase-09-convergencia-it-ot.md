---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 9: Convergencia IT/OT
## Edge Computing y Arquitecturas Híbridas

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Diferenciar** IT y OT en contexto IoT
2. **Explicar** Edge Computing vs Cloud Computing
3. **Diseñar** arquitecturas híbridas IoT
4. **Evaluar** cuándo usar Edge vs Cloud

**Duración:** 2 horas

---
## IT vs OT: Dos Mundos Convergiendo

<table>
<tr>
<td style="background: #dbeafe; padding: 20px; text-align: center; font-weight: bold;" colspan="2">CONVERGENCIA IT/OT</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 15px; width: 50%;">

**🖥️ IT (Information Technology)**

<div style="background: #dcfce7; padding: 10px; border-radius: 8px; margin-top: 10px;">
• 💻 Computadoras<br>
• 🌐 Redes de datos<br>
• 📊 Software<br>
• ☁️ Nube
</div>

</td>
<td style="background: #fef3c7; padding: 15px; width: 50%;">

**🏭 OT (Operational Technology)**

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin-top: 10px;">
• 🏭 Máquinas industriales<br>
• 🔧 Sensores<br>
• ⚡ Sistemas de control<br>
• 🤖 PLCs
</div>

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">

<div style="background: #e0e7ff; padding: 15px; border-radius: 8px; margin: 10px auto; max-width: 300px;">
<strong>📡 IoT CONVERGENCIA</strong><br>
El puente entre IT y OT
</div>

</td>
</tr>
</table>

---

## ¿Por qué es importante la Convergencia IT/OT?

La **Industria 4.0** requiere que los sistemas de información (IT) y los sistemas operacionales (OT) trabajen juntos:

### Ejemplos del mundo real:
- **Manufactura**: Sensores en maquinaria envían datos a sistemas ERP para planificación
- **Energía**: Smart grids conectan plantas generadoras con sistemas de facturación
- **Logística**: Tracking de flotas integrado con sistemas de inventario

### Estadísticas:
- 🔹 70% de empresas industriales planean convergencia IT/OT para 2025
- 🔹 La convergencia reduce costos operativos hasta 30%
- 🔹 Mejora tiempo de respuesta a incidentes en 50%

---

## Diferencias IT vs OT

| Aspecto | IT | OT |
| --------- | ---- | ---- |
| **Prioridad** | Confidencialidad | Disponibilidad |
| **Datos** | Transacciones | Tiempo real |
| **Actualizaciones** | Frecuentes | Raras/planeadas |
| **Vida útil** | 3-5 años | 15-25 años |
| **Interrupción** | Tolerable | Crítica |
| **Seguridad** | Parches frecuentes | Estabilidad |
| **Redes** | TCP/IP | Modbus, OPC, etc. |
| **Personal** | IT/Dev | Ingenieros planta |

---

## IoT: El Puente

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">IoT COMO PUENTE IT-OT</td>
</tr>
<tr>
<td style="background: #fecaca; padding: 15px; width: 50%;">

**❌ ANTES (Silos)**

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin-top: 10px;">
┌────┐ &nbsp;&nbsp;┌────┐<br>
│ IT │ &nbsp;&nbsp;│ OT │<br>
│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│<br>
│────│ &nbsp;&nbsp;│────│<br>
│ &nbsp;&nbsp;│ &nbsp;&nbsp;│ &nbsp;&nbsp;│<br>
└────┘ &nbsp;&nbsp;└────┘<br><br>
<strong>↑</strong>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<strong>↑</strong><br>
Aislados
</div>

</td>
<td style="background: #dcfce7; padding: 15px; width: 50%;">

**✅ DESPUÉS (Convergencia)**

<div style="background: #f0fdf4; padding: 10px; border-radius: 8px; margin-top: 10px;">
┌──────────────────────┐<br>
│ &nbsp;Plataforma IoT &nbsp;&nbsp;│<br>
│ &nbsp;┌────────────────┐ &nbsp;│<br>
│ &nbsp;│ &nbsp;IT &nbsp;│ &nbsp;OT &nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;└────────────────┘ &nbsp;│<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;↕ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;Integrados &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
└──────────────────────┘
</div>

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">

**Beneficios:** Visibilidad unificada • Análisis conjunto • Automatización end-to-end • Decisiones mejores

</td>
</tr>
</table>

---

## Cloud Computing para IoT

### Arquitectura Centralizada

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">☁️ CLOUD COMPUTING - Arquitectura Centralizada</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 15px; width: 50%; text-align: center;">

🌡️🌡️🌡️🌡️🌡️ **Sensores**

<div style="background: #dbeafe; padding: 10px; border-radius: 8px; margin-top: 10px;">
│<br>
│ TODOS los datos<br>
│ ▼<br>
══════<br>
**Internet**
</div>

</td>
<td style="background: #fef3c7; padding: 15px; width: 50%; text-align: center;">

**☁️ NUBE**

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin-top: 10px;">
┌─────────────────┐<br>
│ • Almacenamiento│<br>
│ • Procesamiento │<br>
│ • Machine Learning│<br>
│ • Dashboards &nbsp;&nbsp;│<br>
│ • APIs &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
└─────────────────┘
</div>

</td>
</tr>
<tr>
<td style="background: #dcfce7; padding: 10px;">

**✅ VENTAJAS:**
• Escala infinita
• Recursos ilimitados
• Sin mantenimiento HW
• ML/AI avanzado

</td>
<td style="background: #fecaca; padding: 10px;">

**❌ DESVENTAJAS:**
• Latencia (100-500ms)
• Depende de Internet
• Costos por uso
• Privacidad datos

</td>
</tr>
</table>

---

## Edge Computing

### Procesamiento en el Borde

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">⚡ EDGE COMPUTING - "Procesamiento cerca de la fuente"</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 15px; text-align: center;" colspan="2">

🌡️🌡️🌡️🌡️🌡️ **Sensores**

<div style="background: #dbeafe; padding: 15px; border-radius: 8px; margin-top: 10px; max-width: 400px; margin-left: auto; margin-right: auto;">
│<br>
│ Datos crudos<br>
│ ▼<br>
┌───────────────────────┐<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;EDGE DEVICE &nbsp;&nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;┌─────────────────┐ &nbsp;│<br>
│ &nbsp;│ • Filtrado &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;│ • Agregación &nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;│ • Decisiones &nbsp;&nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;│ &nbsp;&nbsp;locales &nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;│<br>
│ &nbsp;└─────────────────┘ &nbsp;│<br>
│ &nbsp;&nbsp;Gateway/RPi/PC &nbsp;&nbsp;&nbsp;│<br>
└───────────────────────┘<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
└───────────────────────────► ☁️ Nube<br><br>
Solo datos relevantes
</div>

</td>
</tr>
</table>

---
## Edge vs Cloud: Latencia

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">⏱️ COMPARACIÓN DE LATENCIA</td>
</tr>
<tr>
<td style="background: #dcfce7; padding: 15px; width: 50%;">

**⚡ EDGE**
<br>─────

Sensor → Edge: **1-10 ms**

<div style="background: #f0fdf4; padding: 10px; border-radius: 8px; margin-top: 10px;">
EDGE ████<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;10ms
</div>

</td>
<td style="background: #fef3c7; padding: 15px; width: 50%;">

**☁️ CLOUD**
<br>──────

Sensor → Cloud: **100-500 ms**

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin-top: 10px;">
CLOUD ██████████████████████████████████████<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;500ms
</div>

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">

**CASOS CRÍTICOS:**
• Vehículos autónomos: < 10ms necesario
• Control industrial: < 50ms necesario
• Monitoreo médico: < 100ms preferido

</td>
</tr>
</table>

---

## Arquitectura de 3 Capas

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🏗️ ARQUITECTURA IoT DE 3 CAPAS</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 12px; text-align: center;" colspan="2">

<strong>CAPA 1: DISPOSITIVOS (Device Layer)</strong>
──────────────────────────────────
🌡️ 💡 📹 📡 Sensores, actuadores
│
▼

<strong>CAPA 2: EDGE/FOG (Processing Layer)</strong>
────────────────────────────────
<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 10px auto; max-width: 350px;">
┌─────────────────────────────────────┐<br>
│ Gateway │ Filtrado, agregación &nbsp;│<br>
│ RPi/PC │ Decisiones locales &nbsp;&nbsp;&nbsp;│<br>
└─────────────────────────────────────┘
</div>
│
▼

<strong>CAPA 3: CLOUD (Business Layer)</strong>
────────────────────────────
<div style="background: #dbeafe; padding: 10px; border-radius: 8px; margin: 10px auto; max-width: 350px;">
┌─────────────────────────────────────┐<br>
│ AWS/Azure│ ML, Almacenamiento &nbsp;&nbsp;│<br>
│ GCP &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ Análisis histórico &nbsp;&nbsp;&nbsp;│<br>
└─────────────────────────────────────┘
</div>

</td>
</tr>
</table>

---

## Fog Computing

### Entre Edge y Cloud

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🌫️ FOG COMPUTING - "Nube extendida hasta el edge"</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 12px; text-align: center;" colspan="2">

☁️ **CLOUD**
│
│ Análisis global, ML training
▼
<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 10px auto; max-width: 400px;">
┌─────────────────────────────────────┐<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;FOG LAYER &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
│ ┌──────────┐ ┌──────────┐ ┌──────┐│<br>
│ │ Fog Node │ │ Fog Node │ │ Fog &nbsp;││<br>
│ │ (Router) │ │ (Server) │ │ Node ││<br>
│ └────┬─────┘ └────┬─────┘ └──┬───┘│<br>
└───────┼────────────┼──────────┼────┘<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
┌───────▼────┐ ┌─────▼────┐ ┌──▼─────┐<br>
│Edge Devices│ │Edge Devs │ │Edge Devs│<br>
└────────────┘ └──────────┘ └─────────┘
</div>

</td>
</tr>
</table>

---

## ¿Cuándo Usar Edge vs Cloud?

### Usar EDGE cuando:

```
✅ Latencia crítica (< 100ms)
✅ Operación sin Internet requerida
✅ Volumen de datos muy alto
✅ Privacidad de datos sensible
✅ Costos de transferencia altos
✅ Decisiones locales inmediatas
```

### Usar CLOUD cuando:

```
✅ Análisis histórico a largo plazo
✅ Machine Learning complejo
✅ Visualización centralizada
✅ Integración multi-sitio
✅ Recursos computacionales altos
✅ Almacenamiento masivo
```

---
## Caso: Fábrica Inteligente

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🏭 FÁBRICA INTELIGENTE</td>
</tr>
<tr>
<td style="background: #fef3c7; padding: 12px;" colspan="2">

☁️ **CLOUD (AWS/Azure)**
├── Dashboard gerencial
├── Predicción de demanda (ML)
├── Optimización producción
└── Históricos (años)
│
│ Resúmenes cada hora
▼

⚡ **EDGE (Servidor local)**
├── Monitoreo tiempo real
├── Detección anomalías
├── Control de calidad
└── Buffer si Internet falla
│
│ Datos cada segundo
▼

🔧 **DISPOSITIVOS**
├── Sensores de vibración
├── Cámaras de inspección
├── Medidores de energía
└── PLCs de control

</td>
</tr>
</table>

---

## Caso: Convergencia IT/OT en Colombia 🇨🇴

### Celsia (Grupo EPM) - Smart Grid

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">⚡ CELSIA - SMART GRID CONVERGENCIA</td>
</tr>
<tr>
<td style="background: #fecaca; padding: 12px; width: 50%;">

**❌ ANTES (Silos):**
<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin-top: 10px;">
┌─────────┐ &nbsp;&nbsp;&nbsp;&nbsp;┌─────────┐<br>
│ &nbsp;OT &nbsp;&nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;IT &nbsp;&nbsp;&nbsp;│<br>
│ SCADA &nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ SAP ERP │<br>
│ (Redes) │ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│(Nómina) │<br>
└─────────┘ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└─────────┘<br><br>
NO compartían datos
</div>

</td>
<td style="background: #dcfce7; padding: 12px; width: 50%;">

**✅ DESPUÉS (Convergencia):**
<div style="background: #f0fdf4; padding: 10px; border-radius: 8px; margin-top: 10px;">
┌─────────────────────────────────────────┐<br>
│ &nbsp;&nbsp;&nbsp;Plataforma IoT Integrada &nbsp;&nbsp;&nbsp;│<br>
│ ┌──────────┐ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;┌──────────┐ &nbsp;│<br>
│ │ Medidores│────────│ Cloud &nbsp;│ &nbsp;│<br>
│ │ &nbsp;IoT &nbsp;&nbsp;│ Datos │ Analytics│ &nbsp;│<br>
│ └──────────┘ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└─────┬────┘ &nbsp;│<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
│ ┌──────────┐ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;┌─────▼────┐ &nbsp;│<br>
│ │ &nbsp;SCADA &nbsp;│◄───────►│ &nbsp;ERP &nbsp;&nbsp;│ &nbsp;│<br>
│ │ (Control) │ Datos │(Negocio) │ &nbsp;│<br>
│ └──────────┘ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└──────────┘ &nbsp;│<br>
└─────────────────────────────────────────┘
</div>

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">

**RESULTADOS:**
• Detección de fraudes: -35%
• Restauración servicio: -60% tiempo
• Balance energía: Automático

</td>
</tr>
</table>

---

## Caso: Fabrica de Lácteos - Alpina 🇨🇴

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🥛 ALPINA - INDUSTRIA 4.0 CONVERGENCIA</td>
</tr>
<tr>
<td style="background: #fef3c7; padding: 12px;" width: 50%;">

**OT (Sistemas de Producción):**
• PLCs Siemens en líneas de producción
• Controladores de temperatura
• Sistema SCADA (monitoreo planta)

</td>
<td style="background: #f0fdf4; padding: 12px;" width: 50%;">

**IT (Sistemas de Información):**
• SAP ERP (gestión negocio)
• Salesforce (clientes)
• Data Warehouse (analytics)

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 12px; text-align: center;" colspan="2">

**INTEGRACIÓN (IoT Gateway):**
<div style="background: #e0e7ff; padding: 10px; border-radius: 8px; margin: 10px auto; max-width: 400px;">
Edge Computing (Kepware + OPC UA)<br>
• Traducción de protocolos<br>
• Buffer local (48 horas)<br>
• Filtrado de datos (solo cambios)
</div>

**FLUJO DE DATOS:**
Sensores → Edge → Cloud → SAP → Dashboards<br>
(1 segundo) (filtrado) (analíticas) (gerencia)

**BENEFICIOS:**
• OEE: +22%
• Detección de calidad: Tiempo real (antes: 4 horas)
• Predicción de demanda: 95% precisión

</td>
</tr>
</table>

---

### Técnicas Comunes


```cpp
// 1. FILTRADO - Eliminar ruido
float filtrarLecturas(float nuevaLectura) {
    static float buffer[5];
    static int indice = 0;
    
    buffer[indice] = nuevaLectura;
    indice = (indice + 1) % 5;
    
    // Promedio móvil
    float suma = 0;
    for (int i = 0; i < 5; i++) suma += buffer[i];
    return suma / 5;
}

// 2. AGREGACIÓN - Resumir datos
void enviarResumen() {
    static float minTemp = 100, maxTemp = -100, sumaTemp = 0;
    static int conteo = 0;
    
    // Cada 60 segundos, enviar resumen en lugar de 60 lecturas
    if (conteo >= 60) {
        float promedio = sumaTemp / conteo;
        enviarACloud(minTemp, maxTemp, promedio);
        // Reset
        minTemp = 100; maxTemp = -100; sumaTemp = 0; conteo = 0;
    }
}
```

---

### Funciones del Gateway

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🔌 GATEWAY IoT</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 12px;" colspan="2">

<strong>FUNCIONES:</strong>

<div style="background: #dcfce7; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>1. TRADUCCIÓN DE PROTOCOLOS</strong><br>
Zigbee → MQTT → HTTP<br>
Modbus → JSON
</div>

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>2. PREPROCESAMIENTO</strong><br>
Filtrado, agregación, normalización
</div>

<div style="background: #e0e7ff; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>3. ALMACENAMIENTO LOCAL</strong><br>
Buffer cuando no hay conexión
</div>

<div style="background: #dcfce7; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>4. SEGURIDAD</strong><br>
Firewall, cifrado, autenticación
</div>

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>5. GESTIÓN DE DISPOSITIVOS</strong><br>
Actualizaciones OTA, configuración
</div>

<div style="background: #dbeafe; padding: 10px; border-radius: 8px; margin: 8px 0;">
<strong>Hardware típico:</strong> Raspberry Pi, Mini PC industrial
</div>

</td>
</tr>
</table>

---

## Buffer local

```python
import paho.mqtt.client as mqtt
import json
from datetime import datetime

local_broker = "localhost"
cloud_broker = "broker.hivemq.com"

buffer = []

def on_message_local(client, userdata, msg):
    """Recibe datos de sensores locales"""
    datos = json.loads(msg.payload)
    
    # Agregar timestamp
    datos['timestamp'] = datetime.now().isoformat()
    
    # Almacenar en buffer
    buffer.append(datos)
    
    # Cada 10 lecturas, enviar resumen a la nube
    if len(buffer) >= 10:
        resumen = calcular_resumen(buffer)
        cloud_client.publish("fabrica/linea1/resumen", json.dumps(resumen))
        buffer.clear()

---
# Buffer local

def calcular_resumen(datos):
    temps = [d['temperatura'] for d in datos]
    return {
        'min': min(temps),
        'max': max(temps),
        'promedio': sum(temps)/len(temps),
        'cantidad_lecturas': len(datos)
    }
```

---
## Digital Twin (Gemelo Digital)

<table>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center; font-weight: bold;" colspan="2">🔮 DIGITAL TWIN - "Réplica digital de un objeto físico"</td>
</tr>
<tr>
<td style="background: #f0fdf4; padding: 12px;" width: 50%;">

**MUNDO FÍSICO**
────────────────
<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 10px auto;">
┌─────────────┐<br>
│ &nbsp;&nbsp;🏭 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;Máquina &nbsp;&nbsp;│<br>
│ &nbsp;Real &nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
└─────────────┘
</div>

</td>
<td style="background: #e0e7ff; padding: 12px;" width: 50%;">

**MUNDO DIGITAL**
─────────────────
<div style="background: #dbeafe; padding: 10px; border-radius: 8px; margin: 10px auto;">
┌─────────────┐<br>
│ &nbsp;&nbsp;MODEL &nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;Digital &nbsp;│<br>
│ &nbsp;de la &nbsp;&nbsp;&nbsp;│<br>
│ &nbsp;Máquina &nbsp;│<br>
└─────────────┘<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;▼<br>
┌─────────────┐<br>
│ Simulación &nbsp;│<br>
│ Predicción &nbsp;│<br>
│ Optimización│<br>
└─────────────┘
</div>

</td>
</tr>
<tr>
<td style="background: #dbeafe; padding: 15px; text-align: center;" colspan="2">

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; margin: 10px auto;">
<strong>Aplicaciones:</strong> Mantenimiento predictivo • Diseño • Entrenamiento • Optimización
</div>

</td>
</tr>
</table>

---

## Actividad en Clase (30 min)

### Diseño de Arquitectura IoT

**Escenario:** Sistema de monitoreo para edificio de oficinas

**Requerimientos:**
- 50 sensores de temperatura/humedad
- 20 sensores de ocupación
- 10 medidores de energía
- Dashboard tiempo real
- Alertas instantáneas
- Históricos de 1 año

**Tareas:**
1. Diagramar arquitectura de 3 capas
2. Decidir qué procesar en Edge vs Cloud
3. Definir flujo de datos
4. Justificar decisiones

---

## Resumen de la Clase

| Concepto | Descripción |
| ---------- | ------------- |
| **IT** | Tecnología de información (datos) |
| **OT** | Tecnología operacional (control) |
| **Edge Computing** | Procesamiento cerca de sensores |
| **Cloud Computing** | Procesamiento centralizado |
| **Fog Computing** | Capa intermedia distribuida |
| **Gateway** | Dispositivo puente Edge-Cloud |
| **Digital Twin** | Réplica digital de objeto físico |

---

## Próxima Clase

### Clase 10: Examen Parcial E3 (20%)

**Temas a Evaluar:**
- Dispositivos IoT (sensores, MCU)
- Redes (WiFi, LoRa, celular)
- Protocolos (HTTP, MQTT)
- Arquitecturas (Edge, Cloud, Fog)

**Formato:**
- Preguntas de selección múltiple
- Preguntas de desarrollo corto
- Caso de análisis

**¡Estudien los materiales de las clases 1-9!**
