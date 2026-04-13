# Seguimiento Académico - IF0112 Complementaria II

**Fecha de corte 1er corte:** 16 de marzo de 2026 (E3)  
**Última actualización:** 2026-04-13

---

## Temáticas del Primer Corte

| # | Temática | % Desarrollo | Estado | Eval |
|---|----------|--------------|--------|------|
| 1 | Fundamentos de IoT y Arquitectura | 100% | ✅ Finalizado | E1 |
| 2 | Hardware y Sensores | 100% | ✅ Finalizado | E2 |
| 3 | Conectividad WiFi y Protocolos IoT | 100% | ✅ Finalizado | E3 |
| 4 | Proyecto SMAI - Fases iniciales | 100% | ✅ Finalizado | E1-E3 |

---

## 1. Fundamentos de IoT y Arquitectura (100%)

**Contenidos:** Evolución de Internet, 4 Pilares IoT (People, Processes, Data, Things), modelo DIKW, transformación inteligente (Industria 4.0, Smart Cities), arquitectura de 4 capas (Percepción, Red, Procesamiento, Aplicación)

**Sesiones:** C1-C4  
**Evaluación:** E1 - Arquitectura IoT (15%)

### Observaciones:
- Comprensión sólida de fundamentos teóricos
- Buena capacidad para relacionar los 4 pilares con casos de aplicación reales
- Dificultades en diferenciación entre capas de procesamiento y aplicación
- Se recomienda reforzar DIKW en el segundo corte

---

## 2. Hardware y Sensores (100%)

**Contenidos:** Microcontroladores (Arduino vs ESP32), sensores digitales (DHT22) y analógicos (LDR), actuadores (LEDs, relés), protocolos (UART, I2C, SPI, 1-Wire), GPIO, ADC, programación Arduino IDE

**Sesiones:** C5, C6  
**Evaluación:** E2 - Prototipo Sensórico (15%)

### Observaciones:
- Dominio satisfactorio del ESP32
- Circuitos funcionales con DHT22 y LDR
- Dificultades en conexión de resistencias pull-up
- Buen manejo de Wokwi; transición a físico con deficiencias en lectura de datasheets

---

## 3. Conectividad WiFi y Protocolos IoT (100%)

**Contenidos:** Redes IoT (PAN/LAN/WAN), HTTP/REST, modo STA WiFi, ThingSpeak, servidor web básico

**Sesiones:** C4 (parcial), C7  
**Evaluación:** E3 - Software IoT (20%)

### Observaciones:
- Conexión WiFi y HTTP GET a ThingSpeak logradas
- Dificultades con `millis()` vs `delay()` — se reforzará en E4
- Configuración de campos ThingSpeak - algunos errores iniciales superados

---

## 4. Proyecto SMAI - Fases Iniciales (100%)

**Contenidos:** Integración de los 3 ejes en el Sistema de Monitoreo Ambiental Inteligente

**Fases completadas:** 1 (Arquitectura) ✅ / 2 (Prototipo sensórico) ✅ / 3 (Conectividad básica) ✅

### Observaciones:
- 80% de estudiantes con avance satisfactorio en fases 1-3
- Coherencia entre arquitectura (E1) y prototipo (E2-E3)
- Integración sensor-actuador-nube funcional en condiciones controladas

---

## Proyección Segundo Corte - Actualizada (Abril 2026)

> **Cambio importante:** El segundo corte fue reorientado para enfocarse en construcción física del proyecto con flujo de datos real: **ESP32 → FastAPI/MQTT → Base de Datos → Visualización**. Se prioriza que los estudiantes construyan infraestructura propia en lugar de depender solo de plataformas IoT externas.

| Eval | Tema | Peso | Fecha | Entregable |
|------|------|------|-------|------------|
| E4 | Firmware mejorado + FastAPI + BD | 15% | 20-abr-2026 | Informe PDF + código ZIP |
| E5 | Demo integración total + Visualización | 15% | 04-may-2026 | Demo en clase + código ZIP |
| E6 | Entrega final del proyecto con sustentación | 20% | 25-may-2026 | Sustentación oral + demo completa + código final |

### Fases del Proyecto SMAI - Segundo Corte

| Fase | Contenido | Eval | Estado |
|------|-----------|------|--------|
| 4 | Firmware mejorado + API + BD | E4 | 🔄 Planificado |
| 5 | Integración total + Visualización | E5 | 🔄 Planificado |
| 6 | Sustentación sistema completo (FastAPI o MQTT) | E6 | 🔄 Planificado |

### Contenidos por sesión (2do corte):

| Sesión | Fecha | Tema |
|--------|-------|------|
| C10 | 20-abr-2026 | FastAPI + SQLite + Primera API IoT |
| C11 | 27-abr-2026 | API REST completa + MQTT opcional + Persistencia |
| C12 | 04-may-2026 | Integración total del sistema + Demo E5 |
| C13 | 11-may-2026 | Preparación sustentación + Tendencias IoT (5G, AIoT, TinyML) |
| C14 | 25-may-2026 | E6 Sustentación proyecto final |

### Stack técnico del segundo corte:
- **Firmware:** ESP32 con `millis()`, máquina de estados, histéresis, HTTP POST JSON
- **API:** FastAPI local en Windows (principal) | MQTT broker público (alternativa)
- **Base de datos:** SQLite recomendado | MySQL opcional
- **Visualización:** HTML+JS con `fetch()` a la API, Grafana, o dashboard propio
- **Endpoints mínimos:** `POST /datos`, `GET /datos`, `GET /datos/latest`

---

## Resumen de Observaciones (para formulario PANDORA)

### Respecto a contenido y duración:
Cumplido 100% del primer corte. Temáticas 1-4 completamente finalizadas. Segundo corte reestructurado con enfoque práctico en construcción de infraestructura propia (FastAPI + BD) y flujo completo de datos IoT.

### Logros obtenidos:
- Diseño de arquitectura IoT de 4 capas (E1)
- Prototipo funcional ESP32 + DHT22 + LDR (E2)
- Conexión básica ThingSpeak vía WiFi (E3)

### Logros no obtenidos:
- Dashboard propio (queda para E5)
- Control remoto del sistema (queda para E5-E6)
- Dominio completo de protocolos MQTT/CoAP (MQTT es opcional en nuevo enfoque)

### Aspectos favorables:
- Alta motivación por el enfoque práctico
- Uso efectivo del simulador Wokwi
- Buena comprensión de arquitectura IoT
- Trabajo autónomo en proyecto integrador

### Aspectos negativos:
- Dificultades en transición simulador → hardware físico
- Errores en conexiones de resistencias pull-up
- Problemas con tiempos no bloqueantes (millis)
- Dificultades en lectura de datasheets técnicos

### Consideraciones del trabajo del estudiante:
**IMPORTANTE (2026-04-07):** Se han hecho los trabajos prácticos en grupo, sin embargo dentro de los grupos se nota como algunos no aportan tanto al grupo de trabajo. Se harán sustentaciones grupales en E5 y E6 para involucrar más a los integrantes.

### Recomendaciones:
- Ampliar prácticas de troubleshooting en hardware físico
- Reforzar programación asíncrona (millis)
- Implementar sesiones de revisión de código grupal
- Establecer hitos intermedios para el proyecto SMAI
- Mantener sustentaciones grupales para evaluar participación individual

---

## Notas para Reportes Futuros

1. **Mantener coherencia:** Las 4 temáticas del primer corte están 100% finalizadas
2. **El proyecto SMAI es el hilo conductor** - las 3 fases iniciales completadas = base para E4-E5-E6
3. **Sustentaciones grupales:** Implementar en E5 (demo) y E6 (sustentación final) para evaluar participación individual
4. **Nuevo enfoque 2do corte:** Documentar el cambio de orientación hacia FastAPI/MQTT + BD como fortaleza pedagógica
