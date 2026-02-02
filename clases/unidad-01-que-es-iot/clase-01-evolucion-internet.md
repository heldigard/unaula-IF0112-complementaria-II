---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 1'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  section {
    font-size: 20px;
    overflow: hidden;
  }
  img {
    max-width: 70% !important;
    max-height: 50vh !important;
    object-fit: contain !important;
    display: block !important;
    margin: 0 auto !important;
  }
  section h1 { font-size: 1.8em; }
  section h2 { font-size: 1.4em; }
  section h3 { font-size: 1.2em; }
  section ul, section ol { font-size: 0.9em; margin-left: 1em; }
  section li { margin-bottom: 0.3em; }
  section pre { font-size: 0.7em; max-height: 60vh; overflow-y: auto; }
  section code { font-size: 0.85em; }
  section p { margin: 0.5em 0; }
  section table { width: 100%; font-size: 0.85em; border-collapse: collapse; margin: 0.5em auto; }
  section th { background-color: #1e40af; color: white; padding: 0.4em 0.6em; border: 1px solid #ddd; }
  section td { padding: 0.4em 0.6em; border: 1px solid #ddd; }
  section tbody tr:nth-child(even) { background-color: #f8f9fa; }
---

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 40px; align-items: center;">
<div>

# Clase 1: Evolución de Internet
### De ARPANET al Internet de las Cosas

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 Objetivos de la Clase

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| 🕰️ **Histórica** | Describir las 4 eras de la evolución de Internet |
| 🔀 **Transición** | Explicar cómo llegamos de ARPANET a IoT |
| ⚙️ **Tecnológica** | Identificar los 5 drivers del cambio |
| 📊 **Impacto** | Visualizar efectos económicos y sociales |

### ⏱️ Estructura

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Evolución de Internet | 40 min |
| 2️⃣ | Drivers tecnológicos | 30 min |
| 3️⃣ | Impacto y casos | 30 min |
| 4️⃣ | Debate | 20 min |

**Total:** 2 horas | **💡 Pregunta:** ¿Cómo conectó personas y ahora conecta TODO?

</div>
</div>

---

## ¿Qué es Internet de las Cosas?

> **IoT** es la interconexión de objetos físicos cotidianos
> con Internet, permitiéndoles enviar y recibir datos.

<!-- _class: lead -->

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px; text-align: center; margin-top: 20px;">

<div style="background: #f0f9ff; padding: 15px; border-radius: 8px;">
<h3>🌍 MUNDO FÍSICO</h3>
<p style="font-size: 2em; margin: 10px 0;">🚗 🏠 👕 🌡️ 💡</p>
<p><strong>Sensores y Actuadores</strong></p>
<p style="font-size: 0.85em;">Recogen datos del entorno</p>
</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 8px; display: flex; flex-direction: column; justify-content: center;">
<h3>🔗 CONECTIVIDAD</h3>
<p style="font-size: 1.5em; margin: 10px 0;">📡</p>
<p><strong>WiFi · 5G · LoRa · BT</strong></p>
<p style="font-size: 0.85em;">Transmisión de datos</p>
</div>

</div>

---

## ¿Qué es IoT? (2/2)

### La Conexión de Mundos

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px; text-align: center; margin-top: 20px;">

<div style="background: #f0fdf4; padding: 15px; border-radius: 8px;">
<h3>☁️ MUNDO DIGITAL</h3>
<p style="font-size: 2em; margin: 10px 0;">☁️ 📊 🤖 📱</p>
<p><strong>Nube, Analytics e IA</strong></p>
<p style="font-size: 0.85em;">Procesamiento y acción</p>
</div>

<div style="background: #dbeafe; padding: 15px; border-radius: 8px;">
<h3>🔄 CICLO DE DATOS</h3>
<p style="font-size: 1.5em; margin: 10px 0;">📡 ➜ ☁️ ➜ 🤖 ➜ ⚡</p>
<p><strong>Sensor → Nube → Análisis → Acción</strong></p>
<p style="font-size: 0.85em;">Todo sin intervención humana</p>
</div>

</div>

> **💡 Insight:** IoT convierte objetos cotidianos en dispositivos inteligentes que **actúan automáticamente**

---

## Componentes de un Sistema IoT

### ¿Qué hace posible esta conexión?

| Componente | Función | Ejemplo Cotidiano |
|:----------:|:--------|:------------------|
| **📡 Sensores** | Capturan datos del mundo físico | Termostato que mide temperatura |
| **📶 Conectividad** | Transmiten datos a la nube | WiFi que envía datos al servidor |
| **🧠 Procesamiento** | Analizan y toman decisiones | IA que ajusta la temperatura |
| **⚡ Actuadores** | Ejecutan acciones físicas | Aire acondicionado se enciende |

---

## Ejemplo Real: Refrigerador Inteligente 🧊

<div style="background: #f8fafc; padding: 15px; border-radius: 10px; border-left: 4px solid #3b82f6;">

**Flujo de funcionamiento paso a paso:**

<table style="width: 100%; border-collapse: collapse; margin: 10px 0;">
<tr>
<td style="background: #dbeafe; padding: 10px; border-radius: 8px; text-align: center; width: 20%;">📡<br><strong>Sensor</strong><br><small>Detecta falta de leche</small></td>
<td style="text-align: center; font-size: 1.5em; color: #3b82f6;">→</td>
<td style="background: #fef3c7; padding: 10px; border-radius: 8px; text-align: center; width: 20%;">📶<br><strong>Envío</strong><br><small>Datos a la nube</small></td>
<td style="text-align: center; font-size: 1.5em; color: #3b82f6;">→</td>
<td style="background: #fce7f3; padding: 10px; border-radius: 8px; text-align: center; width: 20%;">🧠<br><strong>Análisis</strong><br><small>IA procesa</small></td>
<td style="text-align: center; font-size: 1.5em; color: #3b82f6;">→</td>
<td style="background: #d1fae5; padding: 10px; border-radius: 8px; text-align: center; width: 20%;">📱<br><strong>Acción</strong><br><small>Notifica usuario</small></td>
</tr>
</table>

<table style="width: 100%; border-collapse: collapse; margin-top: 10px;">
<tr>
<td style="text-align: center; font-size: 1.5em; color: #3b82f6;">↓</td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td style="text-align: center; font-size: 1.5em; color: #3b82f6;">↓</td>
</tr>
<tr>
<td style="background: #fef3c7; padding: 8px; border-radius: 8px; text-align: center;">🛒 <strong>Agrega</strong><br><small>Lista de compras</small></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td></td>
<td style="background: #fecaca; padding: 8px; border-radius: 8px; text-align: center;">🚚 <strong>Ordena</strong><br><small>Automáticamente</small></td>
</tr>
</table>

</div>

> **💡 Insight:** IoT convierte objetos cotidianos en dispositivos inteligentes que **actúan automáticamente** sin intervención humana.

---

## Flujo Básico de un Sistema IoT

```
Sensor ──► Gateway ──► Nube ──► Analítica ──► Acción
```

### ¿Qué ocurre en cada paso?

| Etapa | Qué hace | Ejemplo |
|-------|----------|---------|
| **Sensor** | Mide una variable física | Temperatura de una nevera |
| **Gateway** | Agrupa y envía datos | Router WiFi |
| **Nube** | Almacena y procesa | Plataforma IoT |
| **Analítica** | Detecta patrones | Alerta de falla |
| **Acción** | Ejecuta respuesta | Ajuste automático |

---

## Línea del Tiempo de Internet

### Las 4 Eras de la Conectividad Digital

```
1969 ──────────────────────────────────────────────────────────────► 2030+

    ERA 1           ERA 2            ERA 3           ERA 4
   ARPANET          WWW            Web 2.0           IoT
  ┌────────┐    ┌────────┐      ┌────────┐      ┌────────┐
  │ 4      │    │ 1M     │      │ 1,000M │      │ 75,000M│
  │ nodos  │ →  │ páginas│  →   │ usuarios│  →  │devices │
  └────────┘    └────────┘      └────────┘      └────────┘
     1969         1991            2004            2025+
```

| Era | Año | Hito Tecnológico | Impacto |
|-----|-----|------------------|---------|
| **ARPANET** | 1969 | Primer mensaje entre 4 universidades | Nace Internet |
| **WWW** | 1991 | HTML y navegadores | Internet para todos |
| **Web 2.0** | 2004-2007 | Facebook, iPhone | Todos producen contenido |
| **IoT** | 2015+ | AWS IoT, 6G, Edge AI | Todo inteligente conectado |

> **Insight:** Cada era aumentó exponencialmente los nodos conectados

---

## Era 1: ARPANET (1969-1990) 🌐

### Los Inicios + Packet Switching

**Timeline:** 1969 (4 universidades) → 1971 (email) → 1973 (TCP/IP) → 1983 (DNS)

**Packet Switching:** Mensaje → Paquetes → Rutas independientes → Reensamblaje

| Ventaja | Beneficio |
|:--------|----------|
| 🛡️ **Resiliencia** | Rutas alternativas si falla nodo |
| ⚡ **Eficiencia** | Sin circuitos dedicados |
| 🔒 **Seguridad** | Sobrevive ataques militares |

> 💡 **Clave:** La red funciona incluso si partes son destruidas

---

## Era 1: ARPANET - Latinoamérica y Colombia

<div style="display: grid; grid-template-columns: 1.2fr 1fr; gap: 30px;">

<div>

### Conexión Regional: Timeline

| Año | País | Detalle |
|:---:|:-----|:--------|
| **1988** | 🇧🇷 Brasil | Primer país latinoamericano conectado |
| **1989** | 🇲🇽 México | Conexión al backbone de Internet |
| **1990** | 🇨🇱 Chile<br>🇦🇷 Argentina | Conexión simultánea |
| **1991** | 🇨🇴 Colombia | Eduardo Santoja - Uniandes (64 Kbps) |
| **1992** | 🇻🇪 Venezuela<br>🇵🇪 Perú | Expansión regional |

</div>

<div>

### 🇨🇴 Colombia: Pioneros Digitales

| Hito | Año | Detalle |
|------|-----|---------|
| Primer email | 1991 | Enviado desde Uniandes |
| Conexión Internet | 1991 | 64 Kbps vs ~100 Mbps actual |
| Primer sitio web | 1994 | www.uniandes.edu.co |
| ISP comercial | 1995 | Colomsat, EPM Internet |

<div style="background: #dbeafe; padding: 15px; border-radius: 8px; margin-top: 15px;">

**🎯 Dato clave:**
Colombia fue uno de los primeros 5 países latinoamericanos en conectarse.

</div>

</div>

</div>

---

## Era 2: World Wide Web (1991-2003)

### La Web se Vuelve Accesible

- **1991:** Tim Berners-Lee inventa la WWW
- **1993:** Mosaic - primer navegador gráfico
- **1994:** Netscape, Yahoo!, Amazon
- **1995:** Internet Explorer, eBay
- **1998:** Google revoluciona la búsqueda

```
┌─────────────────────────────────────────────────────────────┐
│    ┌────────────────────────────────────────────────────┐   │
│    │ 🌐 http://www.ejemplo.com                    ▼ │   │
│    ├────────────────────────────────────────────────────┤   │
│    │                                                    │   │
│    │           ¡Bienvenido a mi página!                │   │
│    │                                                    │   │
│    │           [Contador de visitas: 000127]           │   │
│    │                                                    │   │
│    └────────────────────────────────────────────────────┘   │
│           La Web 1.0 era principalmente lectura             │
└─────────────────────────────────────────────────────────────┘
```

---

## Era 3: Web 2.0 (2004-2015)

### La Web Social

**📅 Hitos Clave:**
- **2004:** Facebook, Gmail, Web 2.0
- **2005:** YouTube
- **2006:** Twitter, AWS
- **2007:** iPhone - Internet en el bolsillo
- **2010:** Instagram, IoT comienza a crecer

**🔄 El Prosumidor:** Usuario = Creador + Consumidor

---

## Web 2.0: Producción vs Consumo

| 📝 **PRODUCIR** | 📖 **CONSUMIR** |
|:----------------|:----------------|
| Blogs | Leer noticias |
| Videos (YouTube) | Ver contenido |
| Redes sociales | Comentar, compartir |
| Fotos (Instagram) | Like, follow |

> **💡 Concepto clave:** En Web 2.0, todos somos **prosumidores** - creamos y consumimos contenido simultáneamente.

---

## Era 4: Internet de las Cosas (2015+)

### Las Cosas se Conectan

**📈 Crecimiento de Dispositivos:**

| Año | Dispositivos |
|:---:|:------------:|
| 2015 | 15 mil millones |
| 2020 | 30 mil millones |
| 2025 | 75+ mil millones |
| 2030 | Hacia IoE |

---

## Era 4: ¿Por qué el Crecimiento Exponencial? 📈

### Factores que impulsan IoT

| Factor | 2010 | 2025 | Cambio |
|:-------|:----:|:----:|:------:|
| 💰 Costo sensor | $5.00 | $0.50 | **-90%** |
| 📡 Conectividad | $50/mes | $2/mes | **-96%** |
| ⚡ Potencia cómputo | 1x | 100x | **+10,000%** |
| 🔋 Batería | 1 mes | 10 años | **+12,000%** |

### Crecimiento Dispositivos

| Año | Dispositivos |
|:---:|:------------:|
| 2010 | 15B |
| 2015 | 30B |
| 2020 | 50B |
| 2025 | **75B** |

> **Insight:** De 15B a 75B dispositivos en 15 años (**5x**)

---

## Drivers Tecnológicos de IoT 🚀

### Los 5 Drivers + Capacidades IA

| Driver | Evolución | Impacto |
|--------|-----------|--------|
| **💰 Hardware** | Arduino $30 → ESP32 $5 | Entrada ↓ 90% |
| **📡 Conectividad** | WiFi/4G/LoRa/NB-IoT | Cobertura universal |
| **☁️ Cloud** | AWS/Azure/GCP IoT | Enterprise accesible |
| **🧠 IA** | AlexNet → Edge LLMs | Ve, oye, predice, decide |
| **🔋 Energía** | Baterías +300% | Autónomos 10 años |

**IA en dispositivos:** 👁️ Ver cámaras | 👂 Oír voz | 🔮 Predecir fallas | ⚡ Decidir autónomo

---

## Ley de Moore + ESP32: El Game Changer 💻

### Convergencia + Microprocesador

> "5 tecnologías maduras → efecto **multiplicativo**" — Chris Anderson

| Año | Procesador | Transistores | Costo |
|:---:|:-----------|:------------:|:-----:|
| 1971 | Intel 4004 | 2,300 | $60 |
| 2010 | ARM Cortex-A9 | 26M | $10 |
| 2020 | **ESP32** | ~160K | **$3** |

**🎯 A $3, IoT masivo es posible**

---

## De Internet de Personas a Internet de Cosas

### 👤➡️📱 Internet Tradicional | 🤖➡️☁️ Internet de las Cosas

| Aspecto | Internet Tradicional | IoT |
|---------|---------------------|-----|
| **Iniciador** | Humano (clic) | Sensor (auto) |
| **Frecuencia** | Baja (bajo demanda) | Alta (24/7) |
| **Datos** | Texto, video | Temp, humedad |
| **Respuesta** | Pantalla | Acción física |
| **Escala** | Miles de millones | **Billones** |

**Tradicional:** Persona ↔ PC/Móvil ↔ Servidor (petición-respuesta)
**IoT:** Sensor ↔ Datos continuos ↔ Máquina (M2M automático)

---

## Internet de Todo (IoE): El Siguiente Nivel

> **Internet of Everything (IoE)** = IoT + Personas + Procesos + Datos

### IoT vs IoE

| Aspecto | IoT | IoE |
|:--------|:-----|:-----|
| **Enfoque** | Conectar dispositivos | Conectar ecosistema completo |
| **Actores** | Máquinas ↔ Máquinas | Personas + Procesos + Datos + Cosas |
| **Valor** | Recolección de datos | Transformación del negocio |

### Los 4 Pilares

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 15px;">

<div style="background: #f0f9ff; padding: 10px; border-radius: 8px; text-align: center;">
<h3>👤 Personas</h3>
<p style="font-size: 0.85em;">Creadores y consumidores</p>
</div>

<div style="background: #fef3c7; padding: 10px; border-radius: 8px; text-align: center;">
<h3>⚙️ Procesos</h3>
<p style="font-size: 0.85em;">Flujos automatizados</p>
</div>

<div style="background: #f0fdf4; padding: 10px; border-radius: 8px; text-align: center;">
<h3>📊 Datos</h3>
<p style="font-size: 0.85em;">Combustible de decisiones</p>
</div>

<div style="background: #fdf2f8; padding: 10px; border-radius: 8px; text-align: center;">
<h3>📱 Cosas</h3>
<p style="font-size: 0.85em;">Sensores y actuadores</p>
</div>

</div>

> **💡 Insight:** IoT es la tecnología, IoE es el **resultado de negocio**

---

## IoE en Acción: Hospital Inteligente

| Pilar | Rol | Ejemplo |
|:-----:|:----|:---------|
| **👤 Personas** | Creadores y consumidores | Médico recibe alerta de paciente |
| **⚙️ Procesos** | Flujos automatizados | Si temp > 4°C → alerta + reenvío |
| **📊 Datos** | Combustible de decisiones | Historial predice fallas |
| **📱 Cosas** | Sensores y actuadores | Termostato ajusta temperatura |

**IoT (Dispositivo):** Pulsera mide signos vitales → **IoE (Ecosistema):** Alerta automática → reserva ascensor → prepara sala → notifica familia

---

## Drivers Tecnológicos de IoT

---

## Impacto Económico y Social de IoT 💰

### 📊 Mercado Mundial | Sectores Principales

| Año | Valor | Dispositivos |
|:---:|:-----:|:------------:|
| 2020 | $742M | ~15B |
| 2025 | $1.5B | ~30B |
| 2030 | $3+B | ~75B |

**CAGR: 16%** | 🚀 **4x en 10 años**

### ROI por Sector

| Sector | % | ROI |
|:------:|:-:|:----|
| 🏭 Manufactura | 35% | +15% eficiencia |
| 🏥 Salud | 20% | -30% readmisiones |
| 🚗 Transporte | 15% | -15% combustible |
| 🏢 Smart Cities | 12% | -25% agua |
| 🏠 Hogar | 10% | Comodidad |
| 🌾 Agricultura | 8% | +20% cultivos |

---

## Impacto Social: Beneficios y Riesgos ⚖️

### Beneficios para la Sociedad

| Área | Beneficio | Ejemplo |
|------|-----------|---------|
| 🏥 **Salud** | Monitoreo remoto de pacientes | Pacientes crónicos en casa |
| 🛡️ **Seguridad** | Ciudades más seguras | Alertas tempranas de emergencia |
| ⚡ **Eficiencia** | Reducción de consumo energético | Edificios inteligentes |
| ♿ **Accesibilidad** | Tecnología para discapacitados | Casas adaptadas por voz |
| 📈 **Productividad** | Automatización de tareas | Fábricas sin intervención humana |

> **Dato:** Se estima que IoT puede reducir el consumo energético mundial en un 20%

---

## Impacto Social de IoT: Desafíos ⚠️

### Riesgos a Considerar

| Desafío | Descripción | Impacto |
|---------|-------------|---------|
| 🔒 **Privacidad** | ¿Quién tiene mis datos? | Vigilancia masiva |
| 🛡️ **Seguridad** | Vulnerabilidades de dispositivos | Hackeo de infraestructura |
| 👷 **Empleo** | Automatización reemplaza trabajos | Desempleo estructural |
| 🌍 **Brecha digital** | Acceso desigual | Mayor desigualdad |
| ♻️ **Sostenibilidad** | Basura electrónica | Contaminación |

> **Reflexión:** Como ingenieros, debemos diseñar soluciones éticas y sostenibles

---

## Caso Medellín: Movilidad y Seguridad 🇨🇴

### 🚌 Transporte Inteligente

| Componente | Impacto |
|------------|---------|
| GPS flota (500+ buses) | Espera **-30%** |
| App Metro (2M+ descargas) | Satisfacción **85%** |
| Tarjeta Cívica | Validación < 300ms |

### 🔒 Seguridad - Centro CUIC

| Componente | Resultado |
|------------|-----------|
| Cámaras IA (800+) | Recuperación **+40%** |
| Sala crisis 24/7 | Respuesta **4 min** |
| Análisis predictivo | Criminalidad **-25%** |

**Sensación seguridad:** +18 puntos (2020-2024)

---

## Caso Medellín: Servicios Públicos 💧🌳

### EPM - Medidores Inteligentes (500K unidades)

| Aspecto | Valor |
|---------|-------|
| **Inversión** | $45M USD |
| **Ahorro** | $12M USD/año, 15% consumo |
| **ROI** | 3.75 años |

### SIATA - Alertas Tempranas

| Componente | Especificación | Impacto |
|------------|----------------|---------|
| **Estaciones** | 50 (aire + clima) | Datos /15 min |
| **Radar** | Predicción 48h | Alertas 2-4h antes |
| **App** | 500K usuarios | $8M USD/año evitados |
| **Protección** | 2.5M habitantes | $2.5M USD inversión |

---

## Caso Medellín: Factores de Éxito 🏆

### Métricas 2020-2025

| Proyecto | Inversión | Impacto |
|----------|-----------|---------|
| SIATA | $2.5M | Protege 2.5M personas |
| EPM | $45M | Ahorra $12M/año |
| Metro | $15M | +20% eficiencia |
| CUIC | $10M | -25% criminalidad |

### ✅ Claves del Éxito

| Factor | Detalle |
|:-------|:---------|
| 🤝 **Alianza** | EPM + Metro + Alcaldía + Ruta N |
| 🔌 **Infraestructura** | Fibra óptica desde 2000s |
| 👨‍💻 **Talento** | Universidades locales |
| 📱 **Adopción** | Apps con alta penetración |

> **Wall Street Journal 2013:** "Ciudad del Año" - Referente Smart City en LATAM

---

## Caso Medellín: Visión 2030

### Visión 2030 Medellín

| Área | 2025 | 2030 |
|:-----|:----:|:----:|
| 🌫️ Aire | 50 | 200 estaciones |
| 🚌 Transporte | 500 buses | 100% IoT |
| 💡 Energía | 500K | 1.5M medidores |
| 🚗 Movilidad | Apps | IA predictiva |
| 🏥 Salud | Pilotos | Telemedicina masiva |

---

## Smart Cities Latinoamericanas 🌎

| Ciudad | Proyecto | Impacto |
|:------:|:---------|:--------|
| 🇧🇷 **Rio** | Centro de Operações (900 cámaras) | Alertas desastres |
| 🇲🇽 **CDMX** | SEDEMA (4K sensores ozono) | Alertas 7M habitantes |
| 🇦🇷 **Buenos Aires** | BA Electrónica | Rutas **-30%** |
| 🇨🇱 **Santiago** | Metro Inteligente | Alerta sismos 60s |

**Claves:** 🤝 Inversión público-privada | 📊 Datos abiertos | 🔌 Integración | 📱 Apps ciudadanas

---

## Actividad: Debate "IoT: ¿Oportunidad o Amenaza?" 🗣️

**Grupo A 🟢 (Defensores):** Salud (-70% costos), Agricultura (+25% prod), Seguridad (-35% hurtos)
**Grupo B 🔴 (Escépticos):** Privacidad (¿datos?), Empleo (40% riesgo), Brecha digital (67% sin internet)

### Rúbrica

| Criterio | 4 | 3 | 2 | 1 |
|----------|---|---|---|---|
| **Argumentación** | Datos verificables | Algunos datos | Básicos | Sin argumentos |
| **Investigación** | 3+ fuentes | 2 fuentes | 1 genérica | Sin investigación |
| **Contexto CO** | Ejemplos locales | Menciona local | Genérico | Sin contexto |

**Calificación:** Suma / 12 × 100%

---

## Resumen y Reflexión 💭

> **Kevin Ashton (1999):** "La mejor forma de predecir el futuro es crearlo."

### Resumen Clase 01

| Concepto | Clave |
|----------|-------|
| **Eras Internet** | ARPANET → WWW → Web 2.0 → IoT |
| **IoT** | Objetos conectados, sensores, M2M |
| **IoE** = IoT | + Personas + Procesos + Datos |
| **Drivers** | Hardware barato, conectividad, nube, IA |
| **Impacto** | $3B billones 2030, cambio social |

**Como ingenieros:** Diseñan sistemas → Definen funcionamiento → Deciden ética

---

## Tarea para la Próxima Clase

### Lectura
- Capítulo 1 del curso Cisco Networking Academy IoT

### Investigación
Preparar ficha de un dispositivo IoT:
- ¿Qué hace?
- ¿Cómo se conecta?
- ¿Qué datos recopila?
- ¿Qué beneficio ofrece?
- ¿Qué riesgos tiene?

---

## Próxima Clase

### Clase 2: Personas, Procesos, Datos y Cosas
Los cuatro pilares del Internet de las Cosas

**¡Nos vemos!**
