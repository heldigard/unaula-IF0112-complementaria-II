# Teoría: Evolución de Internet - Detalle

**Clase 1: Evolución de Internet | Unidad 1**

## 1. ARPANET: El Origen de Internet

### 1.1 Contexto Histórico

**A finales de los años 60**, el Departamento de Defensa de Estados Unidos (DARPA) buscaba crear una red de comunicaciones que pudiera sobrevivir a un ataque nuclear. Las redes telefónicas tradicionales dependían de conmutadores centrales; si uno era destruido, toda la comunicación se perdía.

**La solución:** Una red descentralizada donde cada nodo pudiera enrutar datos de forma autónoma.

### 1.2 Packet Switching: Conmutación de Paquetes

#### El Problema de las Redes Tradicionales

En las redes de **conmutación de circuitos** (como las telefonías):
```
A ────────⛔ Central ──────── B
          (único punto de falla)
```

Si la central falla, A y B no pueden comunicarse. Además, el circuito permanece ocupado incluso cuando no hay datos fluyendo.

#### La Solución: Packet Switching

```
Mensaje: "HOLA MUNDO"

Sin Packet Switching:
─────────────────────
A ──[Todo el mensaje]──> B

Con Packet Switching:
─────────────────────
A ──[PKT: HOLA]──> C ──> E ──> B
A ──[PKT: MUNDO]──> D ──> F ──> B
```

**Cómo funciona:**

1. **Fragmentación:** El mensaje se divide en paquetes pequeños
2. **Enrutamiento independiente:** Cada paquete toma su propia ruta
3. **Reensamblaje:** El destino reconstruye el mensaje original

#### Ventajas del Packet Switching

| Ventaja | Explicación |
|:--------|:------------|
| **Resiliencia** 🛡️ | Si un nodo falla, los paquetes usan rutas alternativas |
| **Eficiencia** ⚡ | No hay circuitos dedicados; múltiples conversaciones comparten el enlace |
| **Escalabilidad** 📈 | Fácil agregar nodos sin reconfigurar toda la red |
| **Economía** 💰 | Mejor uso del ancho de banda = menor costo |

> **Analogía:** Imagina enviar un libro por correo. En lugar de enviar todo el libro en un camión directo (conmutación de circuitos), lo divides en páginas y cada página toma diferentes rutas en camiones distintos (packet switching). Si una ruta se bloquea, las páginas usan caminos alternos.

### 1.3 Primera Transmisión ARPANET

**29 de octubre de 1969** - UCLA a Stanford Research Institute:

```
Intento 1: "LO" (se cayó la red antes de "GIN")
Intento 2: "LOGIN" ✓ (transmisión completa)
```

Esta transmisión demostró que:
- La comunicación descentralizada era posible
- Los paquetes podían viajar por múltiples rutas
- La red podría sobrevivir a fallos parciales

## 2. Cronología Detallada de las 4 Eras

### Era 1: ARPANET (1969-1990)

| Año | Hito | Impacto |
|:---:|------|---------|
| 1969 | Primer mensaje ARPANET (4 nodos) | Nace Internet |
| 1971 | Ray Tomlinson crea email (@) | Comunicación personal |
| 1973 | TCP/IP desarrollado | Lenguaje común de redes |
| 1983 | DNS (Domain Name System) | Nombres legibles para humanos |
| 1989 | Tim Berners-Lee propone WWW | La próxima era comienza |

### Era 2: World Wide Web (1991-2003)

| Año | Hito | Impacto |
|:---:|------|---------|
| 1991 | WWW publicada + primer sitio web | Información accesible |
| 1993 | Mosaic (primer navegador gráfico) | No programadores pueden navegar |
| 1994 | Netscape, Yahoo!, Amazon fundados | Comercio electrónico nace |
| 1998 | Google fundado | Búsqueda organizada |
| 1999 | WiFi estandarizado (802.11b) | Internet sin cables |

**Web 1.0特征:**
- Sitios **estáticos** (solo lectura)
- Contenido creado por pocos
- Usuario = consumidor pasivo
- Ejemplo: "Under construction" GIFs

### Era 3: Web 2.0 (2004-2015)

| Año | Hito | Impacto |
|:---:|------|---------|
| 2004 | Facebook, Gmail, "Web 2.0" acuñado | Redes sociales masivas |
| 2005 | YouTube lanzado | Video como medio principal |
| 2006 | Twitter, Amazon EC2 | Microblogging + cloud computing |
| 2007 | iPhone lanzado | Internet en el bolsillo |
| 2010 | Instagram, iPad | Contenido visual móvil |

**Web 2.0特征:**
- Sitios **dinámicos** (lectura-escritura)
- Contenido generado por usuarios
- Usuario = **prosumidor** (productor + consumidor)
- Ejemplo: Blogs, redes sociales, wikis

### Era 4: Internet de las Cosas (2015+)

| Año | Hito | Impacto |
|:---:|------|---------|
| 2015 | AWS IoT, Azure IoT lanzados | IoT accesible para empresas |
| 2016 | MQTT v5.0 estandarizado | Protocolo ligero para IoT |
| 2019 | 5G comercial | Baja latencia para IoT masivo |
| 2022 | Edge AI madura | Inteligencia en el dispositivo |
| 2025+ | 75B+ dispositivos conectados | IoT omnipresente |

**IoT特征:**
- Objetos **inteligentes** y conectados
- Comunicación máquina-a-máquina (M2M)
- Usuario = diseñador de ecosistemas
- Ejemplo: Casas, ciudades, fábricas inteligentes

## 3. Drivers Tecnológicos de IoT

### 3.1 Análisis de los 5 Drivers

#### 💰 Hardware: Abaratamiento de Sensores

```
Costo de un sensor de temperatura típico:
2010: $5.00
2015: $2.00
2020: $0.80
2025: $0.50
```

**Efecto:** A $0.50, es viable colocar sensores en casi cualquier objeto.

#### 📡 Conectividad: Redes Universales

| Tecnología | Uso | Costo aproximado | Cobertura |
|------------|-----|-----------------|-----------|
| WiFi | Hogares, oficinas | $2/mes/dispositivo | Local |
| 4G/5G | Móvil, vehículos | $5-15/mes | Nacional |
| LoRaWAN | IoT rural | $0.10/año/dispositivo | 15km rural |
| NB-IoT | Ciudades | $1/mes/dispositivo | Urbana denso |

**Efecto:** Conectividad para cada caso de uso.

#### ☁️ Cloud Computing: Escala Infinita

Antes de cloud (2010):
- Servidor físico: $5,000 + mantenimiento
- Escalabilidad limitada
- Meses para desplegar

Con cloud (2025):
- Pago por uso: $0.0001/hora por 1000 dispositivos
- Escala elástica automática
- Minutos para desplegar

**Efecto:** Cualquiera puede construir plataformas IoT.

#### 🧠 Inteligencia Artificial: De Big Data a Smart Data

```
Evolución capacidades IA:

2010: Big Data (almacenar todo)
2015: Analytics (encontrar patrones)
2020: Machine Learning (predecir)
2025: Edge AI (decidir en el dispositivo)
```

**Efecto:** Los dispositivos no solo capturan datos; entienden y actúan.

#### 🔋 Energía: Baterías de Larga Duración

| Batería | Densidad (Wh/kg) | Duración típica IoT |
|---------|-----------------|---------------------|
| NiMH (2010) | 60-80 | 3-6 meses |
| Li-ion (2015) | 150-200 | 1-2 años |
| Li-S (2025) | 400-500 | 5-10 años |

**Efecto:** Dispositivos que funcionan años sin mantenimiento.

### 3.2 Ley de Moore Aplicada a IoT

```
Transistores por dólar (escala logarítmica):

$1 en 1970 = 2,300 transistores (Intel 4004)
$1 en 1990 = 100,000 transistores
$1 en 2010 = 10,000,000 transistores
$1 en 2025 = 200,000,000 transistores (ESP32 equivalente)
```

**Resultado:** Un microcontrolador WiFi completo cuesta $3 en 2025.

## 4. IoT vs IoE: Diferencias Fundamentales

### 4.1 Definiciones

**IoT (Internet of Things):** La tecnología de conectar dispositivos físicos a Internet.

**IoE (Internet of Everything):** La convergencia de personas, procesos, datos y cosas para crear valor de negocio.

### 4.2 Comparación Detallada

| Dimensión | IoT | IoE |
|-----------|-----|-----|
| **Foco** | Conectar dispositivos | Crear ecosistemas de valor |
| **Componentes** | Cosas | Personas + Procesos + Datos + Cosas |
| **Objetivo** | Recolección de datos | Transformación del negocio |
| **KPI (Key Performance Indicator — métrica cuantificable)** | Número de dispositivos | ROI, eficiencia, satisfacción |
| **Dueño** | IT/Engineering | Toda la organización |

### 4.3 Ejemplo Práctico: Logística

**Enfoque IoT:**
- Sensor GPS en camión
- Envía ubicación cada 5 min
- Dashboard con mapa

**Enfoque IoE:**
- **Personas:** Cliente recibe notificación precisa
- **Procesos:** Ruta optimizada automáticamente
- **Datos:** Histórico predice retrasos
- **Cosas:** Sensores GPS + temperatura + peso
- **Resultado:** Cliente más satisfecho, menor combustible

## 5. Matriz de Impacto de IoT por Sector

| Sector | Dispositivos típicos | KPIs afectados | ROI típico |
|--------|---------------------|----------------|-----------|
| **Manufactura** | Sensores de振动, temperatura | OEE, downtime, calidad | 15-25% mejora |
| **Salud** | Wearables, monitores | Readmisiones, resultados | 20-30% reducción costos |
| **Transporte** | GPS, telemetría | Combustible, rutas | 10-20% ahorro |
| **Energía** | Smart meters, grid | Pérdidas, demanda | 5-15% eficiencia |
| **Retail** | Beacons, inventario | Stock, conversión | 5-10% aumento ventas |
| **Agricultura** | Sensores suelo, clima | Rendimiento, agua | 15-30% mejora |

---

**[← Volver a README](README.md) | [Ir a Demos →](demos.md)**
