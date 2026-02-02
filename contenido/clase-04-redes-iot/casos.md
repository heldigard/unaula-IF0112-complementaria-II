# Casos: Selección de Red IoT

**Clase 4: Redes IoT | Unidad 1**

## Guía de Selección de Tecnología de Red

Use esta matriz para seleccionar la tecnología adecuada según su caso de uso:

### Por Alcance

| Alcance | Tecnologías Recomendadas |
|---------|-------------------------|
| **< 10 m** | BLE, NFC, Zigbee |
| **10-100 m** | WiFi, Zigbee, BLE mesh |
| **100 m - 1 km** | WiFi outdoor, LoRaWAN |
| **1-10 km** | LoRaWAN, NB-IoT, Sigfox |
| **> 10 km** | LoRaWAN rural, 4G/5G, Satélite |

### Por Consumo Energético

| Batería objetivo | Tecnologías |
|-----------------|-------------|
| **Meses** | WiFi, 4G |
| **1-5 años** | BLE, Zigbee, LoRaWAN |
| **5-10 años** | LoRaWAN, NB-IoT, Sigfox |
| **10+ años** | LoRaWAN, Sigfox |

### Por Ancho de Banda

| Datos/día | Tecnologías |
|-----------|-------------|
| **< 1 KB** | Sigfox, LoRaWAN |
| **1 KB - 1 MB** | LoRaWAN, NB-IoT, BLE |
| **1 MB - 1 GB** | WiFi, 4G |
| **> 1 GB** | WiFi, 5G, Ethernet |

## Casos de Uso Recomendados

### Caso 1: Smart Home (Piso/Casa)

**Requisitos:**
- Alcance: 10-50 m
- Dispositivos: 50-200
- Consumo: Bajo
- Interoperabilidad: Importante

**Tecnologías recomendadas:**
1. **Zigbee 3.0** - Principal, para sensores/actuadores
2. **WiFi** - Para cámaras, streaming
3. **BLE** - Para wearables, locks

**Arquitectura típica:**
```
WiFi Router (Internet) ←→ Smart Hub (Zigbee) ←→ Sensores (50+)
```

### Caso 2: Smart Building (Oficina/Edificio)

**Requisitos:**
- Alcance: Hasta 100 m por piso
- Dispositivos: 500-2000
- Fiabilidad: Alta
- Escalabilidad: Crítica

**Tecnologías recomendadas:**
1. **WiFi 6** - Principal (IP devices)
2. **Zigbee** - Sensores/actuadores
3. **Ethernet** - Infraestructura crítica
4. **PoE** - Alimentación + datos

### Caso 3: Agricultura (Campo)

**Requisitos:**
- Alcance: 2-15 km
- Dispositivos: 50-500
- Consumo: Muy bajo (10+ años)
- Conectividad: Limitada

**Tecnologías recomendadas:**
1. **LoRaWAN** - Principal (sensores suelo, clima)
2. **4G/5G** - Drones, cámaras
3. **Satélite** - Comunicación backup

**Arquitectura típica:**
```
Sensores LoRa → Gateway rural → 4G → Cloud → App agricultor
```

### Caso 4: Smart City (Urbano)

**Requisitos:**
- Alcance: Cobertura ciudad
- Dispositivos: Miles
- Fiabilidad: Alta
- Costo: Bajo por nodo

**Tecnologías recomendadas:**
1. **LoRaWAN** - Sensores ambientales, parking, basura
2. **NB-IoT** - Medidores, alarmas
3. **WiFi 6** - Cámaras, hotspots
4. **5G** - Vehículos conectados, crítica

### Caso 5: Industrial (Fábrica)

**Requisitos:**
- Alcance: 10-100 m
- Dispositivos: 100-1000
- Fiabilidad: Crítica
- Latencia: Baja (<10ms)

**Tecnologías recomendadas:**
1. **Ethernet** - Máquinas críticas
2. **WiFi 6** - Flexibilidad
3. **5G** - Mobilidad, AGVs
4. **Zigbee** - Sensores no críticos

## Errores Comunes en Selección

| Error | Consecuencia | Solución |
|-------|--------------|----------|
| **Usar WiFi para todo** | Batteries duran días | Usar Zigbee/LoRa para sensores |
| **Ignorar topología** | Puntos ciegos | Mapear cobertura primero |
| **No considerar densidad** | Congestión | Usar tecnología escalable |
| **Subestimar consumo** | Reemplazo frecuente | Calcular vida batería |
| **Olvidar seguridad** | Vulnerabilidades | Encriptación end-to-end |

## Checklist de Selección

Antes de decidir, responda:

- [ ] ¿Cuál es el alcance requerido?
- [ ] ¿Cuántos dispositivos?
- [ ] ¿Qué frecuencia de transmisión?
- [ ] ¿Cuántos datos por mensaje?
- [ ] ¿Cuál es la vida de batería objetivo?
- [ ] ¿Infraestructura existe o es nueva?
- [ ] ¿Costo máximo por nodo?
- [ ] ¿Requiere movilidad?
- [ ] ¿Latencia máxima aceptable?
- [ ] ¿Interoperabilidad con otros sistemas?

---

**[← Volver a README](README.md) | [Ir a Referencias →](referencias.md)**
