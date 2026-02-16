# Materiales del Curso IF0112 - Complementaria II (IoT)
## Kit Oficial para Proyecto Integrador 2026-I

**Segunda Clase:** Lunes 9 de Febrero de 2026
**Compra recomendada:** Antes del primer laboratorio (Miércoles 11-feb)

---

## Lista de Materiales OBLIGATORIOS

### 1. Placa de Desarrollo (1 unidad)

| Componente | Especificación | Precio estimado (COP) | Alternativa |
|------------|----------------|----------------------|-------------|
| **ESP32** | DevKit V1 o WROOM-32 | $25.000 - $35.000 | LOLIN D32, FireBeetle |
| Cable USB | USB-A a Micro-USB (con datos) | $10.000 - $15.000 | Verificar que transmita datos |

**Por qué ESP32:**
- WiFi + Bluetooth integrado
- Compatible con Arduino IDE
- 40MHz a 240MHz, 520KB RAM
- Entradas ADC para sensores analógicos

---

### 2. Sensores (Kit básico)

| Sensor | Función | Precio (COP) | Notas |
|--------|---------|--------------|-------|
| **DHT22** | Temperatura + Humedad | $8.000 - $12.000 | Preciso, digital |
| **LDR** (Fotoresistencia) | Luz ambiental | $1.000 - $2.000 | Analógico |
| Sensor de agua/nivel | Detección de líquidos | $3.000 - $5.000 | Opcional |

**Conexión DHT22:**
- VCC → 3.3V o 5V
- GND → GND
- DATA → GPIO (ej. pin 4)

**Conexión LDR:**
- Divisor de voltaje con resistencia 10kΩ
- Salida → pin ADC (ej. pin 34)

---

### 3. Componentes Electrónicos Básicos

| Componente | Cantidad | Precio unitario (COP) | Total |
|------------|----------|----------------------|-------|
| Protoboard (830 puntos) | 1 | $12.000 | $12.000 |
| LEDs (rojo, verde, azul) | 10 | $200 | $2.000 |
| Resistencias 220Ω | 10 | $100 | $1.000 |
| Resistencias 10kΩ | 10 | $100 | $1.000 |
| Resistencias 330Ω | 10 | $100 | $1.000 |
| Botones pulsadores | 5 | $300 | $1.500 |
| Cables dupont (macho-macho) | 40 | $150 | $6.000 |
| Cables dupont (macho-hembra) | 20 | $150 | $3.000 |
| Zócalo para ESP32 | 1 | $3.000 | $3.000 |

---

### 4. Herramientas Recomendadas

| Herramienta | Uso | Precio (COP) |
|-------------|-----|--------------|
| Multímetro básico | Medición de voltaje, continuidad | $25.000 - $40.000 |
| Pelacables (opcional) | Preparar cables | $8.000 - $15.000 |
| Fuente de alimentación 5V/2A | Alternativa a USB | $15.000 - $25.000 |

---

## Costo Total Estimado

| Categoría | Mínimo | Recomendado |
|-----------|--------|-------------|
| ESP32 | $25.000 | $35.000 |
| Sensores | $12.000 | $20.000 |
| Componentes electrónicos | $30.000 | $40.000 |
| Herramientas (compartibles) | $0 | $50.000 |
| **TOTAL** | **$67.000** | **$145.000** |

---

## Dónde Comprar (Colombia)

### Tiendas Físicas y Online
1. **Electrónika** (Medellín) - electronika.com
2. **Ci-Ka** (Bogotá) - ci-ka.com
3. **MercaChip** (Nacional) - mercachip.com.co
4. **Arduino Colombia** - arduino.cl
5. **Amazon.com** (con envío a Colombia) - buscar "ESP32 development kit"

### Alternativas de Precio
- **Mercado Libre Colombia:** Buscar "kit ESP32 inicial"
- **AliExpress:** Envío más lento (3-6 semanas), precios 50% menores

---

## Software Necesario (GRATIS)

| Software | Descripción | Enlace |
|----------|-------------|--------|
| **Arduino IDE** | Entorno de programación | arduino.cc/en/software |
| **Driver CH340/CP2102** | Para reconocer ESP32 | Según modelo de tu placa |
| **ThingSpeak** | Plataforma IoT (cuenta gratuita) | thingspeak.com |
| **Grafana** | Dashboard (opcional, cloud gratuito) | grafana.com |

---

## Verificación del Kit (Antes del LAB 1)

Checklist para estudiantes antes del primer laboratorio:

- [ ] ESP32 reconocido por el computador (verificar en Administrador de dispositivos)
- [ ] Arduino IDE instalado y configurado para ESP32
- [ ] Driver de puerto serial instalado
- [ ] Protoboard funcional
- [ ] LEDs funcionando (con resistencia)
- [ ] Botón funcionando
- [ ] Cables dupont organizados

---

## Soporte Técnico

- **Foro Arduino:** forum.arduino.cc
- **Documentación ESP32:** docs.espressif.com
- **YouTube:** Buscar "ESP32 Arduino IDE tutorial español"

---

*Documento para segunda clase - 9 de febrero de 2026*
*Universidad Autónoma Latinoamericana (UNAULA)*
