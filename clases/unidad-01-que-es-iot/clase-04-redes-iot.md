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

# Clase 4: Redes IoT
### LAN, WAN e Internet + Evaluación E1 (15%)

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

</div>
<div>

## 🎯 En esta clase aprenderás:

| Concepto | Qué exploraremos |
|----------|------------------|
| 🌐 | Diferenciar PAN, LAN, WAN e Internet |
| 📡 | Tecnologías de red para IoT |
| ⚖️ | Comparar protocolos según caso de uso |
| 🎯 | Seleccionar la red apropiada |

### Tipos de Redes para IoT

| Tipo | Alcance | Tecnologías |
|------|---------|-------------|
| **PAN** | < 10m | Bluetooth, NFC, ZigBee |
| **LAN** | < 1km | WiFi, Ethernet |
| **WAN** | > 1km | LoRaWAN, NB-IoT, 4G/5G |

> **Sin redes adecuadas, IoT es islas sin comunicación.**

</div>
</div>

---

## Estructura de la Sesión

| Tiempo | Actividad |
| -------- | ----------- |
| 0:00 - 0:50 | Contenido: Redes para IoT |
| 0:50 - 1:00 | Descanso |
| 1:00 - 1:30 | Evaluación E1 - Quiz (10%) |
| 1:30 - 2:00 | Revisión de Ensayos (5%) |

---

## Objetivos de la Clase

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 30px;">

<div>

### 📚 Competencias a Desarrollar

| Competencia | Descripción |
|-------------|-------------|
| 🌐 **Diferenciar** | PAN, LAN, WAN e Internet |
| 🔍 **Identificar** | Tecnologías de red para IoT |
| ⚖️ **Comparar** | Protocolos según caso de uso |
| 🎯 **Seleccionar** | Red apropiada para cada escenario |

</div>
<div>

### ⏱️ Estructura + Evaluación E1

| Bloque | Tema | Duración |
|--------|------|----------|
| 1️⃣ | Redes para IoT | 50 min |
| 2️⃣ | Quiz (10%) | 30 min |
| 3️⃣ | Revisión Ensayos (5%) | 30 min |
| 4️⃣ | Práctica: Selección de red | 10 min |

**Total:** 2 horas

> **💡 Evaluación:** Quiz + Ensayo (15% del curso)

</div>
</div>

---

## Conexión con el Resultado de Aprendizaje

> **Resultado:** Comprende la interacción de los dispositivos IoT a través de las redes e Internet

### ¿Por qué importan las redes en IoT?

- **Dispositivo IoT:** genera datos (bajo consumo)
- **Red IoT:** transporta datos (seguro y eficiente)
- **Internet/Nube:** procesa, almacena y analiza

**Idea clave:** Sin red adecuada, no hay IoT.

---

## Tipos de Redes: Visión General

| Tipo | Alcance típico | Ejemplos |
|------|---------------|----------|
| **PAN** | < 10 m | Bluetooth, NFC, Zigbee |
| **LAN** | < 1 km | WiFi, Ethernet |
| **WAN** | > 1 km | LoRaWAN, NB‑IoT, 4G/5G |
| **Internet** | Global | TCP/IP |

---

## PAN: Personal Area Network

### Redes de Corto Alcance (< 10 metros)

**Características**
- Muy corto alcance (1–10 m)
- Bajo consumo energético
- Ideal para wearables y domótica

---

## LAN: Local Area Network

### Redes de Área Local (edificio, campus)

**Características**
- Cobertura edificio/campus
- Alta velocidad (100 Mbps–10 Gbps)
- Requiere infraestructura local

---

## WiFi para IoT

### Estándares WiFi

| Estándar | Nombre | Velocidad | Rango | Uso IoT |
| ---------- | -------- | ----------- | ------- | --------- |
| 802.11n | WiFi 4 | 150-600 Mbps | 70m | Cámaras |
| 802.11ac | WiFi 5 | 433-6933 Mbps | 35m | Video HD |
| 802.11ax | WiFi 6 | 9.6 Gbps | 30m | Alta densidad |
| 802.11ah | HaLow | 150 Kbps | 1km | IoT bajo consumo |

### Pros y Contras para IoT

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #d1fae5; padding: 15px; border-radius: 10px;">

#### ✅ Ventajas
- Infraestructura existente
- Alta velocidad de datos
- Fácil configuración
- Compatibilidad universal

</div>

<div style="background: #fecaca; padding: 15px; border-radius: 10px;">

#### ❌ Desventajas
- Alto consumo de energía
- Congestión en redes densas
- Requiere infraestructura
- Alcance limitado

</div>

</div>

---

## WAN: Wide Area Network

### Redes de Área Amplia (ciudades, países)

**Características**
- Conecta sedes o zonas geográficas amplias
- Usa infraestructura de operadores o enlaces dedicados

**Tecnologías comunes**
- Fibra óptica, DSL, MPLS
- Celular (4G/5G)
- VPN sobre Internet

---

## Redes Celulares para IoT

### Evolución

| Generación | Tecnología | Velocidad | Latencia | Uso típico |
|-----------|------------|-----------|----------|------------|
| **2G** | GPRS | 50 kbps | 500 ms | Telemetría básica |
| **3G** | HSPA | 2 Mbps | 100 ms | Datos móviles |
| **4G** | LTE | 100 Mbps | 30 ms | Video y apps |
| **5G** | NR | 10 Gbps | 1 ms | IoT masivo y crítico |

**IoT específico**
- **LTE‑M (Cat‑M1):** movilidad, ~1 Mbps
- **NB‑IoT:** sensores fijos, ~100 kbps, 10 años de batería

---

## LPWAN: Low-Power Wide-Area Networks

### Redes IoT de Largo Alcance

**Características**
- Rango: 2–15 km (urbano), hasta 40 km (rural)
- Batería: 5–10 años
- Velocidad: 0.3–50 kbps
- Costo bajo por dispositivo

| Tecnología | Modelo | Ventaja clave |
|-----------|--------|---------------|
| **LoRaWAN** | Abierto | Bidireccional |
| **Sigfox** | Propietario | Muy bajo consumo |
| **NB‑IoT** | Operadores | Buena cobertura indoor |

---

## LoRaWAN en Detalle

### Arquitectura

**Flujo**
- Nodos (sensores) → Gateway → Network Server → Application Server

**Clases de dispositivos**
- **Clase A:** mínimo consumo, envía y escucha brevemente
- **Clase B:** ventanas de escucha programadas
- **Clase C:** escucha continua (alto consumo)

---

## Comparativa de Tecnologías IoT

| Tecnología | Rango | Velocidad | Batería | Costo |
| ------------ | ------- | ----------- | --------- | ------- |
| **Bluetooth LE** | 100m | 2 Mbps | 2-5 años | Bajo |
| **ZigBee** | 100m | 250 kbps | 2-5 años | Bajo |
| **WiFi** | 100m | 150+ Mbps | Horas | Medio |
| **LoRaWAN** | 15km | 50 kbps | 10 años | Bajo |
| **NB-IoT** | 10km | 100 kbps | 10 años | Bajo |
| **4G LTE** | 30km | 100 Mbps | Horas | Alto |
| **5G** | 1km | 10 Gbps | Horas | Alto |

---

## Selección de Red: Árbol de Decisión

**Regla rápida de selección**
1. **Alcance corto (<100 m)** → BLE/ZigBee (bajo consumo) o WiFi (alta velocidad)
2. **Alcance medio (hasta 15 km)** → LPWAN (LoRaWAN / NB‑IoT)
3. **Alcance alto (>15 km)** → Celular (4G/5G)

---
## Casos de Uso por Tecnología

| Escenario | Tecnologías recomendadas |
|-----------|---------------------------|
| **Hogar inteligente** | WiFi (cámaras), ZigBee/BLE (sensores, luces) |
| **Fábrica** | Ethernet, WiFi industrial, 5G privado |
| **Agricultura** | LoRaWAN, NB‑IoT |
| **Ciudad inteligente** | LoRaWAN (medidores), LTE‑M (vehículos) |
| **Vehículos** | 4G/5G, V2X |
| **Wearables** | Bluetooth LE |

### Casos Reales en Colombia 🇨🇴

| Proyecto | Tecnología | Ubicación |
|----------|------------|-----------|
| Medidores EPM | LoRaWAN/NB-IoT | Medellín |
| SIATA (Calidad aire) | LoRaWAN | Valle de Aburrá |
| Monitoreo agrícola | LoRaWAN | Eje Cafetero |
| Encicla | 4G + GPS | Medellín |

---

## El Futuro: 5G para IoT

### Características de 5G

| Perfil 5G | Enfoque | Ejemplos |
|-----------|---------|----------|
| **eMBB** | Altas velocidades (hasta 10 Gbps) | Video 4K/8K, VR |
| **URLLC** | Ultra baja latencia (≈1 ms) | Cirugía remota, vehículos autónomos |
| **mMTC** | 1M dispositivos/km² | IoT masivo, smart cities |

---

## Resumen: Redes para IoT

| Red | Cuándo Usar |
| ----- | ------------- |
| **BLE/ZigBee** | Dispositivos personales, sensores indoor |
| **WiFi** | Cámaras, dispositivos con energía constante |
| **LoRaWAN** | Sensores outdoor, agricultura, medidores |
| **NB-IoT** | Cobertura indoor, áreas con red celular |
| **4G/5G** | Aplicaciones móviles, alta velocidad |

---

# EVALUACIÓN E1 (15%)

## Componentes

| Componente | Peso | Formato |
| ------------ | ------ | --------- |
| Quiz | 10% | Individual, 30 min |
| Ensayo | 5% | Individual, entregado previamente |

---

## Quiz: Instrucciones

### Duración: 30 minutos

1. **10 preguntas** de selección múltiple
2. **5 preguntas** de verdadero/falso
3. Temas:
   - Evolución de Internet
   - Pilares IoT (P-P-D-C)
   - Empresas y ciudades inteligentes
   - Redes para IoT

### Reglas
- Individual, sin consulta
- Un intento
- Resultados al finalizar

---

## Ensayo: Revisión

### Tema del Ensayo
> "El impacto de IoT en Colombia: oportunidades y desafíos"

### Criterios de Evaluación

| Criterio | Puntos |
| ---------- | -------- |
| Argumentación clara | 1.5 |
| Casos colombianos específicos | 1.0 |
| Análisis crítico (pros/contras) | 1.5 |
| Redacción y formato | 1.0 |
| **Total** | **5.0** |

---

## 💻 Actividad Práctica: Selección de Red IoT

### Objetivo
Aplicar los conocimientos de redes IoT seleccionando la tecnología apropiada para cada caso.

---

### Ejercicio: Análisis de Casos (30 min)

**Instrucciones:**
En grupos de 3, analizar los siguientes escenarios y seleccionar la tecnología de red más adecuada.

---

#### Escenario 1: Sensor en Finca Cafetera

**Contexto:**
- Ubicación: Montaña del Eje Cafetero
- Altitud: 1800 msnm
- Sin electricidad cercana
- Lluvia frecuente
- Distancia a punto de conexión: 8 km

**Requerimientos:**
- Enviar datos de humedad del suelo 2x/día
- Temperatura cada hora
- Batería solar

**Preguntas:**
1. ¿Qué tecnología de red usas? ¿Por qué?
2. ¿Qué gateway necesitas?
3. ¿Cómo garantizas conexión en temporada de lluvias?

---

#### Escenario 2: Smart Building

**Contexto:**
- Edificio de 10 pisos en El Poblado, Medellín
- 500 sensores de temperatura
- 200 actuadores de HVAC
- 50 cámaras de seguridad
- Infraestructura Ethernet existente

**Requerimientos:**
- Monitoreo continuo de temperatura
- Control de HVAC en tiempo real
- Video HD para seguridad

**Preguntas:**
1. ¿Usas la misma red para todo? ¿Por qué sí/no?
2. ¿Dónde colocarías los gateways?
3. ¿Cómo manejas la congestión de red?

---

#### Escenario 3: Monitoreo de Pacientes

**Contexto:**
- Hospital con 200 camas
- Wearables para signos vitales
- Alertas críticas en <5 segundos
- Privacidad de datos médicos

**Requerimientos:**
- Monitoreo continuo de ritmo cardíaco
- Oxígeno en sangre
- Ubicación dentro del hospital

**Preguntas:**
1. ¿Qué tecnología garantiza latencia <5s?
2. ¿Cómo aseguras privacidad (Ley 1581)?
3. ¿Qué pasa si el paciente sale del hospital?

---

#### Plantilla de Análisis

| Aspecto | Escenario 1 | Escenario 2 | Escenario 3 |
|---------|-------------|-------------|-------------|
| **Tecnología seleccionada** |  |  |  |
| **Justificación principal** |  |  |  |
| **Gateway requerido** |  |  |  |
| **Consumo energético** |  |  |  |
| **Costo estimado/dispositivo** |  |  |  |
| **Alternativa considerada** |  |  |  |
| **Riesgo principal** |  |  |  |

---

## Seguridad en Redes IoT

### Principales Amenazas

1. **Intercepción de datos** → Mitigación: WPA3, TLS/SSL  
2. **Botnets IoT** (Mirai, Mozi) → Credenciales únicas, actualizaciones  
3. **Falsificación de señal** → Autenticación mutua, firmas digitales  
4. **Denegación de servicio** → Rate limiting, firewalls  
5. **Jamming** → Frequency hopping, redundancia de enlaces

---

## Seguridad en Redes IoT (Continuación)

### Mejores Prácticas

**Dispositivo**
- Cambiar credenciales por defecto
- Deshabilitar servicios no usados
- Actualizar firmware regularmente
- Usar arranque seguro (secure boot)

**Comunicación**
- TLS 1.3+ y certificados digitales
- VPN para redes privadas
- Segmentación de red (VLANs)

**Plataforma**
- MFA y mínimo privilegio
- Logs y auditoría
- Backups encriptados

**Cumplimiento (Colombia)**
- Ley 1581 de 2013 (Habeas Data)
- Ley 1273 de 2009 (Delitos informáticos)
- ISO 27001 (seguridad de información)

---

## Tabla Comparativa de Redes IoT (Parte 1)

### Redes de Corto Alcance (< 100m)

| Tecnología | Rango | Velocidad | Consumo | Costo/Módulo | Mejor Uso |
|:-----------|:------|:----------|:--------|:-------------|:----------|
| **BLE 5.0** | 10-100m | 2 Mbps | 10-50 mA | $5 USD | Wearables, beacons |
| **Zigbee 3.0** | 10-100m | 250 kbps | 10-30 mA | $5 USD | Hogar inteligente |
| **Z-Wave** | 10-100m | 100 kbps | 10-30 mA | $15 USD | Hogar (mercado US) |
| **Thread** | 10-100m | 250 kbps | 10-30 mA | $8 USD | Hogar (Matter/HomeKit) |
| **WiFi 6** | 50-100m | 9.6 Gbps | 200-800mA | $10 USD | Cámaras HD, video |
| **WiFi HaLow** | 1km | 150 Kbps | 50-100mA | $10 USD | IoT rural, bajo consumo |

### Características Comunes

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #d1fae5; padding: 15px; border-radius: 10px;">

#### ✅ Ventajas
- Bajo costo de implementación
- Bajo consumo energético
- Fácil configuración
- Mesh networking disponible

</div>

<div style="background: #fef3c7; padding: 15px; border-radius: 10px;">

#### ⚠️ Limitaciones
- Alcance limitado (< 100m)
- Penetración en paredes
- Requieren gateway
- Interferencia en 2.4GHz

</div>

</div>

---

## Tabla Comparativa de Redes IoT (Parte 2)

### Redes de Largo Alcance (> 1km)

| Tecnología | Rango | Velocidad | Batería | Costo/Módulo | Costo/Datos | Mejor Uso |
|:-----------|:------|:----------|:--------|:-------------|:------------|:----------|
| **LoRaWAN** | 2-15km | 50 kbps | 10 años | $20 USD | $0.001/msg | Sensores outdoor |
| **Sigfox** | 10-50km | 100 bps | 10 años | $15 USD | $0.003/msg | Sensores simples |
| **NB-IoT** | 10km+ | 100 kbps | 10 años | $10 USD | ~$1/GB | Sensores celular |
| **LTE-M** | 10km+ | 1 Mbps | 5-10 años | $20 USD | ~$2/GB | Vehículos, móviles |
| **4G LTE** | 30km | 100 Mbps | Horas | $30 USD | ~$5/GB | Video móvil |
| **5G** | 1km | 10 Gbps | Horas | $50 USD | ~$5/GB | Vehículos autónomos |

### ¿Cuándo usar LPWAN vs Celular?

<div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">

<div style="background: #dbeafe; padding: 15px; border-radius: 10px;">

#### 📡 Usar LPWAN cuando:
| Criterio | Condición |
|:---------|:----------|
| Datos | < 1 KB/día |
| Batería | Años sin cambio |
| Energía | No hay disponible |
| Costo operativo | Mínimo requerido |

**Tecnologías:** LoRaWAN, NB-IoT, Sigfox

</div>

<div style="background: #f0fdf4; padding: 15px; border-radius: 10px;">

#### 📶 Usar Celular cuando:
| Criterio | Condición |
|:---------|:----------|
| Datos | Video, audio, muchos |
| Latencia | Baja requerida |
| Movilidad | Importante |
| Infraestructura | Ya existe cobertura |

**Tecnologías:** 4G LTE, 5G

</div>

</div>

> **Costos Colombia 2026:** Estimados en COP. Los costos de datos celulares varían según operador (Claro, Movistar, Tigo) y plan contratado.

---

## Próxima Clase

### Clase 5: Interconexión de Objetos
- Microcontroladores (Arduino, ESP32)
- Electrónica básica para IoT
- Primera práctica hands-on

**¡Éxitos en la evaluación!**

---
