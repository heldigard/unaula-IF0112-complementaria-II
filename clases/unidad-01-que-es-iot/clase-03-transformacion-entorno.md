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

# Clase 3: Transformación del Entorno
### Empresas y Ciudades Inteligentes

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| 🏭 | Empresas Inteligentes e Industria 4.0 |
| 🏙️ | Smart Cities: Componentes y casos |
| 🇨🇴 | Casos reales: Nutresa, EPM, Medellín |
| ⚠️ | Desafíos: técnicos, sociales, económicos |

> **Pregunta clave:** ¿Cómo IoT transforma empresas y ciudades?

</div>
</div>

---

## 💡 ¿Por qué la transformación digital?

**Datos del mundo real:**
- 84% de empresas en transformación digital (Gartner 2025)
- $2.3 trillones en IoT para 2026

**Ejemplos en Colombia:**
- 🚦 Medellín: Semáforos inteligentes con sensores
- 🏭 Grupo Nutresa: Sensores en líneas de producción
- 🏢 EPM: Smart grid para gestión energética

**Analogía:** Una empresa sin IoT es ciega y sorda. Con IoT, **siente y reacciona** en tiempo real.

---

## Conexión con la Clase Anterior: P-P-D-C en Acción

### Los 4 Pilares Aplicados a Transformación Digital

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div>

#### 🔄 Flujo de Valor

| Pilar | Rol en Smart City |
|:------|:------------------|
| **👤 Personas** | Ciudadanos, usuarios, operadores |
| **⚙️ Procesos** | Reglas, flujos, automatizaciones |
| **📊 Datos** | Métricas en tiempo real, analytics |
| **📱 Cosas** | Sensores y actuadores en el entorno |

</div>

<div style="text-align: center;">

#### 🎯 Convergencia P-P-D-C

<div style="display: grid; grid-template-columns: repeat(3, 1fr); gap: 10px; text-align: center; margin-bottom: 15px;">

<div style="background: #dbeafe; padding: 12px; border-radius: 8px;">

**👤 Personas**

Usuarios y ciudadanos

</div>

<div style="background: #fef3c7; padding: 12px; border-radius: 8px;">

**⚙️ Procesos**

Reglas y automatización

</div>

<div style="background: #f0fdf4; padding: 12px; border-radius: 8px;">

**📊 Datos**

Métricas en tiempo real

</div>

</div>

<div style="text-align: center; background: #1e40af; color: white; padding: 15px; border-radius: 8px;">

**📱 Cosas** = Sensores + Actuadores

↓

**🏙️ SMART CITY**

</div>

</div>

</div>

> **Resultado:** Comprender la interacción entre mundo físico (cosas) y mundo virtual (datos/procesos)

---

## Objetivos de la Clase

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| 🏭 **Definir** | Empresas inteligentes e Industria 4.0 |
| 🏙️ **Describir** | Componentes de Smart Cities |
| 📊 **Analizar** | Casos de estudio reales (Colombia) |
| 🎯 **Evaluar** | Impacto de IoT en sectores clave |

### ⏱️ Estructura de la Clase

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Empresas Inteligentes e Industria 4.0 | 30 min |
| 2️⃣ | Casos Colombia: Nutresa, EPM | 40 min |
| 3️⃣ | Smart Cities y Movilidad | 30 min |
| 4️⃣ | Desafíos y actividad práctica | 20 min |

**Total:** 2 horas

> **💡 Evaluación E1 próxima clase:** Ensayo + Quiz (15%)

---

## La Transformación Digital

| Antes | Después |
|-------|---------|
| Procesos manuales | Procesos inteligentes |
| Reactivo | Predictivo |
| Aislado | Conectado |
| Ineficiente | Optimizado |
| Basado en intuición | Basado en datos |

---

## Empresa Inteligente

### Definición

> Una **empresa inteligente** utiliza tecnologías IoT, 
> análisis de datos e inteligencia artificial para optimizar
> operaciones, mejorar la toma de decisiones y crear valor.

### Características

| Característica | Descripción |
| --------------- | ------------- |
| **Conectada** | Dispositivos y sistemas integrados |
| **Automatizada** | Procesos sin intervención manual |
| **Predictiva** | Anticipa problemas y oportunidades |
| **Adaptativa** | Se ajusta a cambios en tiempo real |
| **Centrada en datos** | Decisiones basadas en evidencia |

---

## Arquitectura IoT: Las 3 Capas

### Arquitectura Empresarial IoT

![Arquitectura IoT de 3 Capas](../../../assets/infografias/clase-03-arquitectura-iot.png){: style="max-width: 55%; max-height: 280px; display: block; margin: 0 auto;"}

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 15px; margin-top: 15px;">

<div style="background: #dbeafe; padding: 15px; border-radius: 8px; text-align: center;">

#### ☁️ Capa 3: Aplicación
**Función:** Interfaz de usuario

| Elemento | Uso |
|:---------|:----|
| Dashboards | Visualizar KPIs |
| Apps | Control remoto |
| Alertas | Notificaciones |

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 8px; text-align: center;">

#### 📡 Capa 2: Red
**Función:** Conectividad

| Elemento | Uso |
|:---------|:----|
| Gateway | Agregar datos |
| Edge | Procesamiento local |
| Protocolos | Transmisión segura |

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 8px; text-align: center;">

#### 🔌 Capa 1: Percepción
**Función:** Interfaz física

| Elemento | Uso |
|:---------|:----|
| Sensores | Capturar datos |
| Actuadores | Ejecutar acciones |
| Hardware | Interfaz mundo real |

</div>

</div>

### Flujo de Datos: Ejemplo en Fábrica

| Paso | Capa | Acción | Ejemplo |
|:----:|:-----|:-------|:--------|
| 1 | Percepción | Sensor detecta | Temperatura = 85°C |
| 2 | Red | Transmite dato | LoRaWAN → Gateway |
| 3 | Aplicación | Alerta usuario | "Sobrecalentamiento" |

> **💡 Principio:** Cada capa tiene responsabilidad única

---

## Industria 4.0 (Manufactura Inteligente)

### Las 4 Revoluciones Industriales

| Revolución | Periodo | Tecnología clave | Resultado |
|-----------|---------|------------------|-----------|
| **1.0** | 1784 | Máquina de vapor | Mecanización |
| **2.0** | 1870 | Electricidad | Producción en masa |
| **3.0** | 1969 | Electrónica + TI | Automatización |
| **4.0** | 2011+ | IoT + IA + Big Data | Sistemas ciberfísicos |

---

## Industria 4.0: Los 9 Pilares Tecnológicos (1/2)

### Tecnologías que Definen la Manufactura Moderna

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 12px;">

| # | Pilar | Descripción |
|:-:|:------|:------------|
| 1 | 🌐 **IoT** | Sensores conectados |
| 2 | 🤖 **Robótica** | Cobots colaborativos |
| 3 | 📊 **Big Data** | Análisis masivo |
| 4 | 🔮 **IA** | Machine Learning |
| 5 | 👓 **AR/VR** | Mantenimiento asistido |
| 6 | ☁️ **Cloud** | Infraestructura escalable |
| 7 | 🛡️ **Ciberseguridad** | Protección de sistemas |
| 8 | 🖨️ **Impresión 3D** | Manufactura aditiva |
| 9 | ⛓️ **Blockchain** | Trazabilidad |

</div>

---

## Industria 4.0: Evolución y Resultados (2/2)

### De Industria 3.0 a 4.0

| Aspecto | Industria 3.0 (1969-2010) | Industria 4.0 (2011+) |
|:--------|:--------------------------|:----------------------|
| **Automatización** | Rígida y fija | Flexible y adaptable |
| **Producción** | En masa, estándar | Personalización masiva |
| **Estructura** | Silos departamentales | Integración total |
| **Mantenimiento** | Correctivo (reparar) | Predictivo (anticipar) |
| **Decisiones** | Centralizadas | Distribuidas en red |

<div style="background: #d1fae5; padding: 15px; border-radius: 8px; margin-top: 15px; text-align: center;">

**🎯 Resultado:** Fábricas más ágiles, eficientes y personalizadas

</div>

---

## Caso: Grupo Nutresa - Colombia 🇨🇴 (Parte 1/2)

### Transformación Digital en Alimentos

| Área | Tecnología | Aplicación |
|------|------------|------------|
| **Líneas de Producción** | Sensores IoT | Temperatura pasteurización/horneado |
| | Control humedad | Productos sensibles (galletas) |
| | Visión artificial | Detección empaques defectuosos |
| **Mantenimiento** | Sensores vibración | Monitoreo motores críticos |
| | Análisis lubricantes | Detección temprana desgaste |
| **Resultado:** | **-40% downtime** | |

---

## Caso: Grupo Nutresa - Colombia 🇨🇴 (Parte 2/2)

### Trazabilidad y Gemelos Digitales

**Trazabilidad Blockchain:**

| Etapa | Datos | Tecnología |
|:------|:-----|:-----------|
| 🌾 **Campo** | QR, GPS, clima | Sensores + Blockchain |
| 🏭 **Planta** | Batch, timestamp | IoT + Ledger |
| 📦 **Distribución** | Ruta, temperatura | Sensores + GPS |
| 🏪 **Tienda** | Verificación, caducidad | Escaneo + Validación |

**Gemelos Digitales:**

| Capacidad | Beneficio |
|-----------|-----------|
| Simulación virtual | Probar cambios sin detener |
| Optimización layouts | Maximizar eficiencia |
| Capacitación VR | Entrenar sin riesgos |

<div style="background: #dbeafe; padding: 12px; border-radius: 8px; margin-top: 10px;">

**💡 Beneficio:** Transparencia total desde campo hasta consumidor

</div>

---

## Caso: Grupo Nutresa - Colombia 🇨🇴 (Parte 3)

### Resultados Medidos (2020-2024)

| Métrica | Mejora | Impacto |
|---------|--------|---------|
| Eficiencia operativa | +18% | $45M USD ahorro |
| Desperdicio materia prima | -25% | 12,000 ton menos |
| Consumo energético | -30% | -15,000 ton CO2 |
| Tiempo cambio producto | -50% | +23% capacidad |
| Cumplimiento calidad | 99.5% | -40% reclamos |

### 🏆 Reconocimientos
- Planta 4.0 Tocancipá: Primera de Latinoamérica 100% conectada
- Premio "Fábrica del Futuro" 2023
- Certificación LEED Oro

### 💡 Innovaciones

| Innovación | Descripción | Impacto |
|------------|-------------|---------|
| **🤖 Cobot** | Trabaja con operarios, 150 paq/min | Reduce lesiones |
| **🧠 IA Predicción** | 50+ variables, 94% precisión | -20% inventarios |
| **👓 Realidad Aumentada** | Mantenimiento guiado + supervisión | -60% reparaciones |

---

## Caso: EPM - Transformación Energética 🇨🇴 (Parte 1)

### Smart Grid y Medición Inteligente

**Despliegue de medidores**

| Año | Medidores | Cobertura | Inversión |
|-----|-----------|-----------|-----------|
| 2020 | 500,000 | 15% | $45M USD |
| 2022 | 1,200,000 | 35% | $80M USD |
| 2025 | 2,700,000 | 80% | $180M USD |
| 2027 | 3,500,000 | 100% | $250M USD |

**Capacidades clave**
- Lectura remota cada 15 minutos
- Detección de fraudes en tiempo real
- Reconexión automática remota
- Tarifas dinámicas por hora
- Integración con energías renovables

---

## Caso: EPM - Transformación Energética 🇨🇴 (Parte 2)

### Servicios y Resultados

**App "EPM Móvil"**
- Consulta consumo diario
- Comparativa con vecinos similares
- Alertas de consumo alto
- Simulador de ahorro
- Reporte de fallas

**Resultados medidos**
- -18% pérdidas de energía (de 22% a 18%)
- +30% detección de fraudes
- -15% consumo promedio por usuario
- +95% satisfacción de clientes
- -40% llamadas al call center

**Impacto ambiental**
- 500,000 toneladas CO2 evitadas/año
- Optimización de renovables
- Postergación de nueva planta de generación

---

## Sectores Transformados por IoT en Colombia

### Transformación Digital por Industria

| Sector | Empresas Líderes | Aplicaciones Clave | Impacto |
|--------|-----------------|-------------------|---------|
| **🏭 Manufactura** | Nutresa, Corona, Ecopetrol | Mantenimiento predictivo, Control calidad automatizado | 💰 -15-30% costos operativos |
| **🏥 Salud** | EPM Salud, Keralty, Sura | Telemedicina + wearables, Gestión inventarios | 📉 -40% readmisiones |
| **🛒 Retail** | Éxito, Falabella, Jumbo | Estanterías inteligentes, Cajas automáticas | 📉 -25% mermas |
| **🚛 Logística** | Servientrega, 4-72 | Flotas GPS, Rutas optimizadas, Cadena de frío | ⛽ -20% combustible |
| **🏦 Financiero** | Bancolombia, Davivienda | Cajeros inteligentes, Detección fraude en tiempo real | 🛡️ -60% fraudes |
| **🌾 Agricultura** | Eje Cafetero, Valle | Riego inteligente, Drones monitoreo | 💧 -40% agua, 📈 +25% producción |

### Estadísticas del Ecosistema IoT Colombia (2024)

| Indicador | Valor |
|-----------|-------|
| 💰 Inversión IoT anual | $850M USD |
| 📱 Dispositivos conectados | 12 millones |
| 🏢 Empresas con proyectos IoT | 35% de medianas y grandes |
| 🏙️ Principales ciudades | Bogotá (40%), Medellín (25%), Cali (15%) |
| 📈 Crecimiento anual del mercado | 18% |

---

## Caso: Fábrica Inteligente

### Siemens Amberg (Alemania)

**Datos**
- 50 millones de registros de proceso/día
- 99.99885% tasa de calidad

**Tecnología**
- 1,000+ estaciones de trabajo automatizadas
- Productos se comunican con máquinas
- Mantenimiento predictivo

**Resultados**
- 75% de la planta automatizada
- Producción aumentó 8x en 25 años
- Mismo espacio, mismo número de empleados

---

## Smart Cities: Ciudades Inteligentes

### Definición

> Una **ciudad inteligente** usa tecnología IoT para mejorar
> la eficiencia de servicios urbanos, la calidad de vida
> y la sostenibilidad ambiental.

### Componentes de una Smart City

- 🚗 Movilidad inteligente
- 💡 Energía inteligente
- 🌳 Ambiente inteligente
- 🏛️ Gobierno inteligente
- 🏥 Salud inteligente
- 🔒 Seguridad inteligente
- 🏠 Edificios inteligentes
- 🚰 Agua inteligente
- 📡 Conectividad (5G / fibra / LPWAN)

---

## Movilidad Inteligente: Componentes

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 🚦 Semáforos Adaptativos
- Ajustan tiempos según tráfico real
- Reducción de congestionamiento
- Respuesta a emergencias

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 10px;">

#### 🅿️ Estacionamiento Inteligente
- Sensores detectan espacios libres
- App guía al conductor
- Pago automatizado

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px;">

#### 🚌 Transporte Público Conectado
- GPS en tiempo real
- Info de llegada en paradas
- Integración multimodal

</div>

<div style="background: #fdf2f8; padding: 15px; border-radius: 10px;">

#### 🚗 Vehículos Conectados
- V2V (Vehículo a Vehículo)
- V2I (Vehículo a Infraestructura)
- Conducción autónoma

</div>

</div>

---

## Energía Inteligente: Smart Grid

### Arquitectura de Red Eléctrica Inteligente

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 15px; text-align: center;">

<div style="background: #fef3c7; padding: 15px; border-radius: 8px;">

#### ☀️ Generación
**Distribuida**

- Solar fotovoltaica
- Eólica
- Generación tradicional

</div>

<div style="background: #dbeafe; padding: 15px; border-radius: 8px;">

#### ⚡ Distribución
**Inteligente**

- Transformadores inteligentes
- Monitoreo en tiempo real
- Balance dinámico

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 8px;">

#### 🏠 Consumo
**Inteligente**

- Medidores smart
- Tarifas dinámicas
- Eficiencia energética

</div>

</div>

<div style="background: #1e40af; color: white; padding: 15px; border-radius: 8px; margin-top: 15px; text-align: center;">

#### 🎯 Centro de Control
Monitoreo en tiempo real | Detección de fallas | Balance oferta/demanda | Integración renovables

</div>

---

## Medidores Inteligentes (Smart Meters)

### Beneficios

| Para el Usuario | Para la Empresa |
| ----------------- | ----------------- |
| Facturación exacta | Lectura remota automática |
| Ver consumo en tiempo real | Detección de fraude |
| Tarifas por horario | Pronóstico de demanda |
| Alertas de consumo alto | Reducción de pérdidas |

### Despliegue en Colombia

<div style="background: #dbeafe; padding: 20px; border-radius: 10px;">

#### EPM (Empresas Públicas de Medellín)

| Métrica | Valor |
|---------|-------|
| 📱 Medidores inteligentes | 2.7 millones (meta 2025) |
| ⏱️ Frecuencia de lectura | Cada 15 minutos |
| 📲 App móvil | Consulta de consumo en tiempo real |

</div>

---

## Agua Inteligente: Gestión del Recurso

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div>

### Flujo del Agua IoT

| Etapa | Sensores | Función |
|:------|:---------|:--------|
| 💧 **Captación** | Nivel en embalses | Control de reservas |
| 🚰 **Tratamiento** | pH, turbidez, cloro | Calidad del agua |
| 📡 **Distribución** | Presión, flujo | Detección de fugas |
| 🏠 **Consumo** | Medidores smart | Facturación y alertas |

</div>

<div style="background: #dbeafe; padding: 20px; border-radius: 10px; text-align: center;">

#### 📊 Impacto Medido

<span style="font-size: 3em;">📉</span>

**Reducción de pérdidas:**

# 15-30%

*Ahorro significativo en infraestructura hídrica*

</div>

</div>

---

## Seguridad Ciudadana Inteligente

### Tecnologías IoT para Seguridad

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### 📷 Cámaras Inteligentes
- Reconocimiento facial
- Detección de comportamiento anómalo
- Lectura de placas vehiculares

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 10px;">

#### 🚨 Botones de Pánico
- Ubicación GPS automática
- Notificación inmediata
- Integración con autoridades

</div>

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 📱 Apps Ciudadanas
- Reportes de incidentes
- Alertas georreferenciadas
- Comunicación bidireccional

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px;">

#### 🔊 Sensores Acústicos
- Detección de disparos (ShotSpotter)
- Identificación de sonidos
- Localización precisa

</div>

</div>

---

## Caso de Estudio: Singapur 🇸🇬

### La Ciudad Más Inteligente del Mundo

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 25px;">

<div>

#### 🎯 Iniciativas Clave

| Iniciativa | Descripción |
|:-----------|:------------|
| 🏙️ **Virtual Singapore** | Gemelo digital de la ciudad |
| 🏥 **Smart Health** | Telemedicina + wearables |
| 🚌 **Smart Mobility** | Taxis autónomos |
| 💳 **E-Payments** | Ciudad casi sin efectivo |
| 📡 **SenseOps** | Red de sensores masiva |

</div>

<div style="background: #d1fae5; padding: 20px; border-radius: 10px; text-align: center;">

#### 📊 Resultados

| Métrica | Valor |
|:--------|:-----:|
| Ranking Smart City | **#1 Mundial** |
| Hogares con banda ancha | **95%** |
| Transacciones sin efectivo | **50%** |

</div>

</div>

---

## Caso de Estudio: Barcelona

### Iniciativas IoT Destacadas

| Área | Implementación |
| ------ | ---------------- |
| **Iluminación** | 1,100+ farolas LED conectadas, ahorro 30% |
| **Riego** | Sensores de humedad, ahorro 25% agua |
| **Basuras** | Contenedores con sensores de nivel |
| **Parking** | 400+ sensores en vía pública |
| **Bicing** | Sistema de bicicletas compartidas IoT |

**Plataforma Sentilo:**
- Código abierto
- Integra todos los sensores de la ciudad
- Datos abiertos para desarrolladores

---

## Caso de Estudio: Medellín 🇨🇴

### Centro de Control y Comando - C4 + SIATA

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 15px;">

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### 🔒 Seguridad (C4)
- 5,000+ cámaras en la ciudad
- Integración con Policía
- Monitoreo de transporte

</div>

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 🌧️ Ambiente (SIATA)
- Sensores calidad del aire
- Estaciones meteorológicas
- Alertas tempranas

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 10px;">

#### 🚌 Movilidad
- Metro con GPS
- Encicla con IoT
- App integrada

</div>

</div>

### Impacto Medible en la Ciudad

| Área | Métrica | Valor |
|:-----|:--------|:-----:|
| 🔒 **Seguridad** | Reducción delictiva | **15%** en zonas con cámaras |
| 🌧️ **Ambiente** | Alertas tempranas | **30 min** antes de emergencias |
| 🚌 **Movilidad** | Eficiencia transporte | **20%** reducción tiempos espera |

---

## Desafíos Técnicos de Smart Cities 🔧

<div style="display: grid; grid-template-columns: 1fr 1fr 1fr; gap: 20px;">

<div style="background: #fef3c7; padding: 15px; border-radius: 10px;">

#### 🔌 Interoperabilidad
- Múltiples fabricantes
- Protocolos diferentes
- Sistemas legacy

</div>

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### 🔒 Ciberseguridad
- Infraestructura crítica
- Miles de vulnerabilidades
- Ataques sofisticados

</div>

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 📈 Escalabilidad
- Crecimiento exponencial
- Mantenimiento masivo
- Costos operativos

</div>

</div>

---

## Desafíos Sociales y Económicos

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 25px;">

<div>

### 👥 Desafíos Sociales

| Desafío | Descripción |
|:--------|:------------|
| 👁️ **Privacidad** | ¿Quién accede a mis datos? |
| 🌍 **Brecha Digital** | No todos tienen acceso igual |
| 🤝 **Aceptación** | Confianza en la tecnología |
| ⚠️ **Dependencia** | ¿Qué pasa si falla el sistema? |

</div>

<div>

### 💰 Desafíos Económicos

| Desafío | Descripción |
|:--------|:------------|
| 💵 **Costo Inicial** | Inversión millonaria |
| 📊 **ROI** | Retorno a largo plazo |
| 🔄 **Sostenibilidad** | Modelo de negocio viable |

</div>

</div>

---

## Privacidad en Ciudades Inteligentes

### El Dilema: Seguridad vs Privacidad

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #d1fae5; padding: 15px; border-radius: 10px;">

#### ✅ Más Seguridad
- 📷 Más cámaras
- 🔒 Menos crimen
- 🚨 Respuesta rápida

</div>

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### ⚠️ Menos Privacidad
- 👁️ Vigilancia masiva
- 🗃️ Datos ciudadanos
- 🤖 Perfilamiento

</div>

</div>

### 🎯 Principios para el Equilibrio

| Principio | Aplicación |
|:----------|:-----------|
| 🔍 **Transparencia** | Informar qué datos se recopilan |
| ✅ **Consentimiento** | Opt-in donde sea posible |
| 📉 **Minimización** | Solo datos necesarios |
| ⏱️ **Retención Limitada** | Borrar cuando no se necesiten |
| 🔎 **Auditorías** | Revisiones independientes |

---

## Actividad en Clase (40 min)

### Diseño de Componente Smart City

En grupos de 4, diseñar un componente IoT para Medellín:

**Opciones:**
1. Sistema de parqueaderos inteligentes
2. Monitoreo de calidad del aire en barrios
3. Gestión inteligente de residuos (basuras)
4. Sistema de alerta temprana de inundaciones

**Entregable:**
- Diagrama de arquitectura
- Lista de sensores/actuadores
- Beneficios esperados
- Desafíos identificados
- Consideraciones de privacidad

---

## Rúbrica de Evaluación

| Criterio | Excelente (4) | Bueno (3) | Aceptable (2) | Insuficiente (1) |
|----------|---------------|-----------|---------------|------------------|
| **Arquitectura** | Diagrama completo con capas claramente definidas | Diagrama básico sin algunos detalles | Diagrama incompleto | Sin diagrama |
| **Tecnología** | Sensores/actuadores específicos y apropiados | Lista genérica de tecnología | Tecnología limitada/inapropiada | Sin especificación |
| **Beneficios** | 3+ métricas cuantificables | 2 métricas cualitativas | 1 beneficio genérico | Sin beneficios claros |
| **Desafíos** | Identifica técnicos, sociales y económicos | 1-2 tipos de desafíos | Solo desafíos obvios | Sin análisis de desafíos |
| **Privacidad** | Análisis profundo de riesgos y mitigaciones | Menciona privacidad básica | Mínima consideración | Sin mención |
| **Contexto Medellín** | Específico para ciudad con datos locales | Menciona contexto genérico | Sin contexto local | Desconectado de realidad |

**Calificación:** Suma de puntos / 24 × 100%

---

## Ejemplo de Entregable: Monitoreo Calidad Aire

### Componente: Red de Sensores de Calidad del Aire

**Objetivo**
- Monitorear calidad del aire en 16 comunas
- Resolución 500 m (vs 5 km actual)

**Alcance**
- 200 sensores distribuidos por barrio
- Alertas hiperlocales para ciudadanía y alcaldía

---

## Arquitectura Propuesta

**Flujo general**
- Sensores por cuadra (PM2.5, PM10, O3, NO2, Temp/Humedad)
- Gateway LoRaWAN por comuna
- Plataforma IoT (AWS IoT Core)
- App ciudadana + Dashboard alcaldía

**Responsables clave**
- Operación: Secretaría de Medio Ambiente
- Tecnología: Integrador IoT + operador LoRa

---

## Especificaciones y Beneficios

| Especificación | Valor |
|---------------|-------|
| Sensor | Plantower PMS5003 (PM2.5/PM10) |
| Precisión | ±10% vs equipos profesionales |
| Muestreo | Cada 10 segundos |
| Energía | Solar + batería (7 días) |
| Costo por nodo | ~$150 USD |

**Beneficios esperados**
- Cobertura 100% comunas con 200 sensores
- Alertas 15 min antes de picos de contaminación
- -20% consultas respiratorias en zonas críticas
- Costo $30K vs $500K estaciones tradicionales

---

## Desafíos, Privacidad y Costos

**Desafíos técnicos**
- Calibración trimestral de sensores
- Vandalismo en zonas críticas
- Conectividad LoRa en alta densidad

**Privacidad y datos**
- Datos anónimos (sin geolocalización exacta)
- Agregación por barrio (≥1000 habitantes)
- Acceso público vía API
- Cumplimiento Ley 1581

**Costos estimados**
- Fase 1 (piloto): 20 nodos - $3M COP
- Fase 2 (expansión): 180 nodos - $27M COP
- Plataforma + desarrollo: $15M COP
- Mantenimiento anual: $30M COP
- ROI: Ahorro en salud ≈ $200M COP/año

---

## Resumen de la Clase

| Concepto | Descripción |
| ---------- | ------------- |
| **Empresa Inteligente** | Usa IoT para optimizar operaciones |
| **Industria 4.0** | Manufactura con IoT, IA, Big Data |
| **Smart City** | Ciudad que usa IoT para mejorar servicios |
| **Smart Grid** | Red eléctrica inteligente |
| **Smart Mobility** | Transporte conectado y eficiente |
| **Desafíos** | Interoperabilidad, seguridad, privacidad |

---

## Tarea para la Próxima Clase

### Investigación

Seleccionar una ciudad inteligente del mundo y preparar:

1. **Ficha técnica** (3 iniciativas IoT destacadas)
2. **Resultados medibles** (métricas, estadísticas)
3. **Lecciones aprendidas** para Colombia
4. **Presentación de 5 minutos** para compartir

**Ciudades sugeridas:** Ámsterdam, Dubái, Seúl, Copenhague, Helsinki

---

## Próxima Clase

### Clase 4: Redes para IoT
- LAN, WAN e Internet
- Protocolos de comunicación IoT
- Evaluación E1 (15%): Ensayo + Quiz

**¡Nos vemos!**
