---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 1'
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

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 40px; align-items: center;">
<div>

# Clase 2: Personas, Procesos, Datos y Cosas
### Los Cuatro Pilares del Internet de las Cosas

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 Objetivos de la Clase

### 📚 Competencias + ⏱️ Estructura

**Competencias:** Identificar 4 pilares | Explicar interacciones | Analizar rol en IoT | Diseñar P-P-D-C

**Estructura:**
| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Modelo de 4 pilares P-P-D-C | 30 min |
| 2️⃣ | DIKW: Datos a Sabiduría | 25 min |
| 3️⃣ | Casos de estudio (Hogar, Agro) | 40 min |
| 4️⃣ | Seguridad, Ley 1581 y Actividad | 25 min |

**Total:** 2 horas

> **💡 Pregunta clave:** ¿Cómo pasar de "cosas conectadas" a "valor real"?

</div>
</div>

---

## Modelo de los Cuatro Pilares

### El Marco Conceptual de IoT

![Los 4 Pilares de IoT: Personas, Procesos, Datos y Cosas](../../../assets/infografias/clase-02-4-pilares-iot.png){: style="max-width: 65%; max-height: 350px; display: block; margin: 0 auto;"}

**¿Qué representa este modelo?**
Los cuatro pilares son los componentes esenciales de cualquier solución IoT. Cada pilar se conecta con los demás para crear valor.

- **Personas**: definen objetivos y reciben el valor
- **Procesos**: convierten datos en decisiones
- **Datos**: evidencian lo que ocurre
- **Cosas**: capturan y actúan en el mundo físico

---
<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px; margin: 20px 0;">

<div style="background: #f0f9ff; padding: 20px; border-radius: 10px; text-align: center;">
<h3>👤 PERSONAS</h3>
<p><strong>Deciden y operan</strong></p>
<p style="font-size: 0.9em;">Definen objetivos y criterios</p>
</div>

<div style="background: #fef3c7; padding: 20px; border-radius: 10px; text-align: center;">
<h3>⚙️ PROCESOS</h3>
<p><strong>Automatizan</strong></p>
<p style="font-size: 0.9em;">Convierten datos en decisiones</p>
</div>

<div style="background: #f0fdf4; padding: 20px; border-radius: 10px; text-align: center;">
<h3>📊 DATOS</h3>
<p><strong>Alimentan e informan</strong></p>
<p style="font-size: 0.9em;">Conectan físico con digital</p>
</div>

<div style="background: #fdf2f8; padding: 20px; border-radius: 10px; text-align: center;">
<h3>📱 COSAS</h3>
<p><strong>Capturan y actúan</strong></p>
<p style="font-size: 0.9em;">Sensores y actuadores físicos</p>
</div>

</div>

> **💡 Idea clave:** El valor de IoT surge cuando los 4 pilares se **interconectan** en un ciclo completo.

---

## Interdependencia de los Pilares

| Conexión | Descripción | Ejemplo |
|----------|-------------|---------|
| **Personas ↔ Procesos** | Las personas definen reglas | Configurar horario de encendido de luces |
| **Procesos ↔ Datos** | Los procesos usan datos para decidir | Si temperatura > 30°C, encender A/C |
| **Datos ↔ Cosas** | Las cosas generan datos | Sensor envía lectura cada 5 minutos |
| **Cosas ↔ Personas** | Las personas usan las cosas | Usuario controla termostato desde app |

> **Principio clave:** Ningún pilar funciona de forma aislada. El valor de IoT surge de sus **interconexiones**.

---

## Pilar 1: PERSONAS 👤

> Las personas son el centro de todo sistema IoT.
> La tecnología debe servir a las personas, no al revés.

### Roles de las Personas en IoT

| Rol | Descripción |
| ----- | ------------- |
| **Usuario Final** | Beneficiario de la solución IoT |
| **Operador** | Gestiona y monitorea el sistema |
| **Desarrollador** | Diseña e implementa soluciones |
| **Tomador de Decisiones** | Actúa basado en información |

### ¿Cómo se conectan las personas?
- Smartphones, tablets, computadores
- Interfaces web y aplicaciones móviles
- Asistentes de voz (Alexa, Google Home)

---

## Pilar 2: PROCESOS ⚙️

> Los procesos son las reglas que determinan cómo se
> usa la información para agregar valor.

### Características de los Procesos IoT

```
┌─────────────────────────────────────────────────────────────┐
│                    PROCESO IoT                              │
│                                                             │
│    ENTRADA         PROCESAMIENTO         SALIDA            │
│  ┌─────────┐      ┌─────────────┐      ┌─────────┐        │
│  │ Datos   │ ───► │  Reglas +   │ ───► │ Acción  │        │
│  │ sensores│      │  Algoritmos │      │         │        │
│  └─────────┘      └─────────────┘      └─────────┘        │
│                                                             │
│   Temperatura          Si T > 30°C          Encender       │
│   = 32°C               entonces...           A/C           │
└─────────────────────────────────────────────────────────────┘
```

### Tipos de Procesos
- **Automatizados:** Sin intervención humana
- **Semi-automatizados:** Con aprobación humana
- **Manuales asistidos:** Humano decide con datos

---

## Pilar 3: DATOS 📊

> Los datos son la información generada por sensores
> y convertida en conocimiento útil.

### Flujo de Datos en IoT: La Pirámide DIKW

![Pirámide DIKW - Datos Información Conocimiento Sabiduría](../../../assets/infografias/clase-02-dikw-pyramid.png){: style="max-width: 50%; max-height: 300px; display: block; margin: 0 auto;"}

**La Pirámide DIKW explica cómo los datos crudos se transforman en valor:**
- Datos sin procesar → Contexto = Información
- Información → Patrones = Conocimiento  
- Conocimiento → Experiencia = Sabiduría

---

## ¿Por qué es importante la jerarquía DIKW?

| Nivel | Definición | Acción | Valor |
|-------|------------|--------|-------|
| **🔢 Datos** | Hechos brutos sin contexto | Capturar | Bajo |
| **📋 Información** | Datos con contexto | Organizar | Medio |
| **📚 Conocimiento** | Patrones identificados | Analizar | Alto |
| **🧠 Sabiduría** | Decisiones basadas en experiencia | Decidir | Máximo |

> **Transformación:** Datos → Contexto = Información → Patrones = Conocimiento → Experiencia = Sabiduría

---

## Las "4 V" de los Datos IoT

| V | Dimensión | Descripción | Métrica |
|:-:|:----------|:------------|:--------|
| 📊 | **Volumen** | Cantidad de datos generados | Terabytes/día |
| ⚡ | **Velocidad** | Rapidez de generación y procesamiento | Milisegundos de latencia |
| 🎨 | **Variedad** | Diferentes tipos de datos | Texto, video, numérico, audio |
| ✅ | **Veracidad** | Calidad y confiabilidad de los datos | Precisión del sensor, fiabilidad |

---

## Modelo DIKW: De Datos a Sabiduría en IoT

### La Pirámide del Conocimiento

<div style="display: grid; grid-template-columns: 1fr; gap: 10px; margin: 20px 0;">

<div style="background: #fef3c7; padding: 15px; border-radius: 10px; text-align: center; border-left: 4px solid #f59e0b;">
<h3>🧠 SABIDURÍA (WISDOM)</h3>
<p><em>"Usar el conocimiento para tomar mejores decisiones"</em></p>
<p style="font-size: 0.9em;">🔮 <strong>Predecir:</strong> "Optimizar riego según patrones de 10 años"</p>
</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px; text-align: center; border-left: 4px solid #22c55e;">
<h3>📚 CONOCIMIENTO (KNOWLEDGE)</h3>
<p><em>"Entender patrones y relaciones"</em></p>
<p style="font-size: 0.9em;">🔍 <strong>Explicar:</strong> "La temperatura sube cuando la humedad baja"</p>
</div>

<div style="background: #f0f9ff; padding: 15px; border-radius: 10px; text-align: center; border-left: 4px solid #3b82f6;">
<h3>📋 INFORMACIÓN (INFORMATION)</h3>
<p><em>"Datos con contexto y significado"</em></p>
<p style="font-size: 0.9em;">📊 <strong>Contextualizar:</strong> "32°C es alta → encender A/C"</p>
</div>

<div style="background: #fdf2f8; padding: 15px; border-radius: 10px; text-align: center; border-left: 4px solid #ec4899;">
<h3>🔢 DATOS (DATA)</h3>
<p><em>"Hechos brutos sin procesar"</em></p>
<p style="font-size: 0.9em;">📈 <strong>Capturar:</strong> "32" (número crudo del sensor)</p>
</div>

</div>

---

### Ejemplo Completo: Sensor de Temperatura

<div style="background: #f8fafc; padding: 20px; border-radius: 10px;">

| Nivel | Ejemplo |
|:------|:--------|
| 🧠 **Sabiduría** | "Optimizar energía según patrones estacionales" |
| 📚 **Conocimiento** | "Entre las 2-6 PM, temperatura sube 15% en promedio" |
| 📋 **Información** | "32°C es alta, encender A/C; 22°C es óptima, apagar" |
| 🔢 **Datos** | "32, 31, 33, 32, 34, 31, 30, 29, 28, 27, 26..." |

</div>

---

## Seguridad y Privacidad de Datos IoT

### Desafíos de Seguridad

| Tipo de Riesgo | Descripción | Ejemplo |
|----------------|-------------|---------|
| **Intercepción** | Datos capturados en tránsito | Hacker lee datos de sensor |
| **Manipulación** | Datos alterados maliciousmente | Falsificar lectura de medidor |
| **Disponibilidad** | Sistema no disponible | DDOS a servicios IoT |
| **Privacidad** | Datos personales expuestos | Venta de hábitos de consumo |

---

## Principios de Seguridad IoT: Capas de Protección

### 🔒 Modelo de Seguridad por 4 Capas

| Capa | Elementos | Tecnologías |
|:----:|:----------|:------------|
| **1. Dispositivo** | Boot seguro, encriptación storage, OTA updates | Secure boot, AES-256 |
| **2. Comunicación** | Datos en tránsito protegidos | TLS/SSL, Certificados, VPN |
| **3. Plataforma** | Autenticación, autorización, encriptación | MFA, RBAC, AES at-rest |
| **4. Aplicación** | Consentimiento, anonimización | OAuth 2.0, GDPR/Ley 1581 |

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 15px; margin-top: 15px;">

<div style="background: #dbeafe; padding: 12px; border-radius: 8px;">

**🛡️ Amenazas Comunes:**
- Intercepción de datos
- Manipulación de sensores
- Ataques DDoS
- Explotación de vulnerabilidades

</div>

<div style="background: #d1fae5; padding: 12px; border-radius: 8px;">

**✅ Buenas Prácticas:**
- Actualizaciones automáticas
- Encriptación end-to-end
- Autenticación multifactor
- Monitoreo continuo

</div>

</div>

---

## Ley 1581: Derechos del Titular (ARCO) 🇨🇴

### Derechos en Protección de Datos Personales

| Derecho | Significado | Aplicación IoT |
|:-------:|:------------|:---------------|
| **A**cceso | Saber qué datos se tienen | Ver datos recolectados por sensores |
| **R**ectificación | Modificar datos errados | Corregir información de perfil |
| **C**ancelación | Eliminar datos | Borrar historial de uso |
| **O**posición | Negar uso de datos | Rechazar compartir datos con terceros |

---

## Ley 1581: Sanciones y Deberes 🇨🇴

### ⚠️ Sanciones por Incumplimiento

| Tipo | Sanción |
|:----:|:--------|
| **Multa** | Hasta 1000 SMLMV |
| **Operativa** | Cierre de servicios |
| **Legal** | Responsabilidad civil/penal |

### 📋 Deberes de Empresas IoT

| Deber | Requisito |
|:-----:|:----------|
| **Política** | Informar privacidad claramente |
| **Autorización** | Consentimiento explícito (opt-in) |
| **Seguridad** | Garantizar protección de datos |
| **Minimización** | Solo recolectar datos necesarios |

> **💡 Importante:** Todo sistema IoT en Colombia debe cumplir con la Ley 1581 de 2012

---

## Pilar 4: COSAS 📱

> Las "cosas" son los objetos físicos conectados
> que capturan datos o ejecutan acciones.

### Tipos de "Cosas"


```
┌─────────────────────────────────────────────────────────────┐
│                    TIPOS DE DISPOSITIVOS                    │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  SENSORES (Capturan datos)                                  │
│  ├── 🌡️ Temperatura, humedad                               │
│  ├── 📍 GPS, acelerómetros                                  │
│  ├── 📷 Cámaras, micrófonos                                │
│  └── 💡 Luz, proximidad                                     │
│                                                             │
│  ACTUADORES (Ejecutan acciones)                             │
│  ├── 🔌 Relés, interruptores                               │
│  ├── 🔊 Altavoces, sirenas                                 │
│  ├── 🚿 Válvulas, bombas                                   │
│  └── 🤖 Motores, servos                                    │
│                                                             │
│  HÍBRIDOS (Ambos)                                           │
│  └── 📱 Smartphones, smartwatches                          │
└─────────────────────────────────────────────────────────────┘
```

---

## Interacciones entre Pilares 🔗

### P2M | M2M | P2P

**P2M (Persona ↔ Cosa):** Usuario → "Enciende luz" → Alexa | App móvil | Interruptores

**M2M (Cosa ↔ Cosa):** Sensor temp 32°C → Actuador enfría | Movimiento → Alarma | Sin humanos

**P2P (Persona ↔ Persona):** Paciente ⌚ → Cloud → Doctor 📊

| P2P Casos | Beneficio |
|-----------|-----------|
| Telemedicina | Consulta remota datos reales |
| Adulto mayor | Alerta caídas inmediata |
| Empresas | Reserva sala inteligente |

> **Clave:** IoT mediado por tecnología, datos contextuales, síncrono/asíncrono

---
## Caso Hogar Inteligente: P-P-D-C 🏠

### 👤 Personas + 📱 Cosas

**Personas:** Familia (usuarios) | App móvil (control)

**Sensores:** Termostato | Puertas/ventanas | Cámaras movimiento

**Actuadores:** Luces conectadas | Cerradura | Asistente voz

**Funciones:** Configurar reglas | Monitorear remoto | Alertas eventos

### 📊 Datos + ⚙️ Procesos

**Datos:** Temperatura (5min) | Energía (1min) | Patrones | Eventos seguridad

**Procesos:**
| IF | THEN |
|----|------|
| Nadie en casa + luces on | Apagar todo |
| Noche + movimiento | Luces ext + grabar |
| Puerta abre < 19:00 | Temp 22°C + luz sala |
---

## Caso Agricultura: Personas + Cosas 🌾👨‍🌾

### Roles + Dispositivos

**Personas:** Agricultor (decisiones) | Agrónomo (análisis) | Operador (ejecuta)

**Sensores:** Humedad suelo | Estación clima | Drones NDVI | GPS tractores

**Actuadores:** Riego goteo | Fertilizadora variable | Drones fumigadores

---

## Caso Agricultura: Datos + Procesos + Impacto 📊🇨🇴

### Datos + Procesos

**Datos:** Humedad (15min) | Clima (5min) | NDVI (semanal) | GPS (continuo)

**Procesos IF→THEN:**
| Condición | Acción |
|-----------|--------|
| Humedad < 30% | Riego 15min |
| NDVI bajo | Alerta agrónomo |
| Suelo bajo N | Ajustar dosis |

### Impacto Colombia

| Cultivo | Ahorro | Resultado |
|---------|--------|-----------|
| Arroz (Meta) | 💧 -40% agua | 7,200 m³/ha |
| Café (Eje) | 📈 +25% prod | 19 qq/ha |
| Maíz (Llanos) | 💰 -30% costos | $800K/ha/año |

---

---

## Referencia Nacional: Programas IoT en Colombia 🇨🇴

### Federaciones Implementando IoT

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px; border-left: 4px solid #22c55e;">

#### 🌾 FEDEARROZ
**Programa: "Arroz Sostenible"**

| Métrica | Valor |
|:--------|:-----:|
| Productores | 500+ |
| Ahorro de agua | 35% promedio |
| ROI | 18 meses |
| Tecnología | Sensores de humedad |

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 10px; border-left: 4px solid #f59e0b;">

#### ☕ FNC - Cafeteros
**Programa: "Cosecha Bluetooth"**

| Métrica | Valor |
|:--------|:-----:|
| Fincas conectadas | 10,000+ |
| Precisión predicción | 85% |
| Target | Pequeños productores |
| Herramienta | App + sensores |

</div>

</div>

> **💡 Impacto:** IoT está transformando la agricultura colombiana a gran escala

---

## El Flujo Completo P-P-D-C

### Diagrama de Interacción entre Pilares

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 25px;">

<div>

#### 🔄 Ciclo de Valor

| Paso | Descripción |
|:-----|:------------|
| **1. Personas** 👤 | Definen objetivos y criterios |
| **2. Cosas** 📱 | Capturan datos del mundo físico |
| **3. Datos** 📊 | Se procesan y analizan |
| **4. Procesos** ⚙️ | Aplican reglas y lógica |
| **5. Acción** 💡 | Se ejecuta respuesta |
| **→** | Retroalimentación a Personas |

</div>

<div style="text-align: center;">

#### 🎯 Interconexión

```
        ┌───────────┐
        │  PERSONAS │
        │    👤     │
        └─────┬─────┘
              │
    ┌─────────┼─────────┐
    ▼         ▼         ▼
┌──────┐  ┌──────┐  ┌────────┐
│COSAS │↔︎│DATOS │↔︎│PROCESOS│
│ 📱   │  │ 📊   │  │  ⚙️    │
└──┬───┘  └──────┘  └───┬────┘
   │                    │
   └────────┬───────────┘
            ▼
       ┌─────────┐
       │ ACCIÓN  │
       │   💡    │
       └─────────┘
```

</div>

</div>

> **💡 Insight:** El valor surge cuando los 4 pilares se conectan en un ciclo continuo

---

## El Valor de IoT: Sin vs Con 🔗

| Pilar | ❌ Sin IoT | ✅ Con IoT |
|:------|:-----------|:-----------|
| 👤 Personas | Deciden sin datos | Decisiones basadas en datos |
| ⚙️ Procesos | Manuales, lentos | Automatizados, rápidos |
| 📊 Datos | No existen | Tiempo real, visibilidad |
| 📱 Cosas | No conectadas | Inteligentes, acción auto |

**Ejemplo Mantenimiento:** Antes: Falla → Reparir costoso | Después: Sensores → IA alerta → Preventivo

> **Beneficios:** Eficiencia ↑ | Costos ↓ | Decisiones óptimas | Conveniencia

---

## Diseñando con P-P-D-C: Metodología

### 5 Pasos para Crear Soluciones IoT

| Paso | Acción | Pregunta Clave | Ejemplo |
|:----:|:-------|:---------------|:--------|
| **1** | 👤 Identificar **PERSONAS** | ¿Quién se beneficia y opera? | Estudiantes, administradores |
| **2** | ⚙️ Definir **PROCESOS** | ¿Qué reglas se necesitan? | Si cupo libre → notificar |
| **3** | 📊 Determinar **DATOS** | ¿Qué información capturar? | Estado cupo, tiempo ocupación |
| **4** | 📱 Seleccionar **COSAS** | ¿Qué sensores/actuadores? | Sensores inductivos, semáforos |
| **5** | 🔗 Diseñar **CONEXIONES** | ¿Cómo se comunican? | LoRaWAN → Cloud → App |

<div style="background: #fef3c7; padding: 15px; border-radius: 8px; margin-top: 15px; text-align: center;">

**🎯 Éxito = Cuando los 4 pilares trabajan juntos en un ciclo continuo**

</div>

---

## Actividad en Clase (40 min)

### Diseño de Solución IoT con P-P-D-C

En grupos de 3 personas, seleccionar UN escenario:

1. **Estacionamiento inteligente** en el campus
2. **Biblioteca inteligente** con control de aforo
3. **Sistema de riego** para jardines del campus
4. **Monitoreo de aulas** (ocupación, temperatura, iluminación)

### Criterios de Evaluación

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| Completitud | 30% | Los 4 pilares bien definidos |
| Interacciones | 25% | Flujo entre pilares claro |
| Viabilidad | 25% | Tecnología disponible hoy |
| Innovación | 20% | Propuesta creativa y útil |

### Entregable (formato P-P-D-C)

| Pilar | Descripción para el escenario |
| ------- | ------------------------------- |
| Personas |  |
| Procesos |  |
| Datos |  |
| Cosas |  |

---

## Ejemplo: Estacionamiento Inteligente 👤⚙️📊📱

### Roles + Procesos

**Personas:** Estudiantes (usuarios) | Admin (gestión) | Mantenimiento (alertas)

**Procesos IF→THEN:**
| Condición | Acción |
|-----------|--------|
| Vehículo detectado | Marcar cupo |
| >5 libres | 🟢 LED |
| Cupo libre + espera | Push notif |
| >15 min | Cargo auto |

### Datos + Cosas

**Datos:** Estado (5s) | Tiempo (1min) | Flujo (1min) | Tarifas

**Almacenamiento:** Redis (real-time) | PostgreSQL (histórico) | S3 (backup)

**Sensores:** Cámaras IA | Inductivos | Barreras | Lector placas

**Actuadores:** LEDs | Barreras | Pantallas | Alertas sonoras

---

## Ejemplo: Estacionamiento - Arquitectura 🔗

### Interfaces + Flujo

**Interfaces:** App móvil (búsqueda) | Portal admin (monitoreo) | Pantallas campus (disponibilidad)

**Comunicación:**
```
Sensores →[LoRaWAN]→ Gateway →[MQTT]→ Plataforma →[REST]→ Apps
```

**Capas:**
```
┌─────────────────────────────┐
│  Apps + Portal              │
├─────────────────────────────┤
│  Plataforma IoT             │
├─────────────────────────────┤
│  Gateway LoRaWAN            │
├─────────────────────────────┤
│  Sensores + Actuadores      │
└─────────────────────────────┘
```

> **💡:** Múltiples protocolos según distancia/velocidad

---

---

## Plantilla para Entregable: Personas y Procesos

| Pilar | Mi Diseño: [ESCENARIO ELEGIDO] |
|-------|--------------------------------|
| **PERSONAS** | Usuarios: <br>Administradores: <br>Operadores: |
| **PROCESOS** | Proceso 1: <br>Proceso 2: <br>Proceso 3: |

---

## Plantilla para Entregable: Datos y Cosas

| Pilar | Mi Diseño: [ESCENARIO ELEGIDO] |
|-------|--------------------------------|
| **DATOS** | Datos a capturar: <br>Frecuencia: <br>Almacenamiento: |
| **COSAS** | Sensores: <br>Actuadores: <br>Interfaces: |
| **INTERACCIONES** | P ↔ M: Persona controla qué: <br>M ↔ M: Qué dispositivos se comunican: <br>M ↔ P: Cómo se notifica al usuario: |
| **SEGURIDAD** | 🔒 Medidas de seguridad: <br>🛡️ Protección de datos: |

---

## Reflexión: El Humano en el Centro

> "La tecnología IoT es solo una herramienta.
> El verdadero valor está en cómo mejora la vida de las personas."

### Preguntas Clave para Diseñadores IoT

1. ¿Esta solución **realmente** mejora la vida del usuario?
2. ¿Los datos recopilados son **necesarios** o excesivos?
3. ¿Las automatizaciones dan **control** o lo quitan?
4. ¿Las personas **confían** en el sistema?

---

## Resumen de la Clase

| Pilar | Rol en IoT |
| ------- | ------------ |
| **Personas** | Usuarios, operadores, tomadores de decisiones |
| **Procesos** | Reglas, automatizaciones, workflows |
| **Datos** | Información capturada, procesada, almacenada |
| **Cosas** | Sensores, actuadores, dispositivos conectados |

### Tipos de Interacciones
- **P2M:** Persona controla dispositivo
- **M2M:** Dispositivos se comunican entre sí
- **M2P:** Dispositivo notifica a persona
- **P2P:** Personas colaboran vía IoT

---

## Tarea para la Próxima Clase

### Completar el Diseño P-P-D-C

Usando el escenario de la actividad en clase:

1. **Expandir** cada pilar con 5+ elementos
2. **Dibujar** diagrama de conexiones
3. **Identificar** 3 procesos automatizados específicos
4. **Listar** datos a capturar con frecuencia

**Formato:** Documento Word, 2-3 páginas

---

## Próxima Clase

### Clase 3: La Transformación del Entorno
- Empresas inteligentes
- Ciudades inteligentes (Smart Cities)
- Casos de estudio reales

**¡Nos vemos!**
