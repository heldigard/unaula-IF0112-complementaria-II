# IF0112 - Complementaria II: Internet de las Cosas (IoT)

**Programa:** Ingeniería Informática  
**Semestre:** 6° (2026-I)  
**Créditos:** 2  
**Horario oficial:** Lunes 06:00 - 08:00 (2 horas)  
**Modalidad:** Híbrido (clases teóricas + 5 laboratorios concentrados + proyecto integrador)

---

## Modelo del Curso 2026-I

El curso está organizado para construir de forma progresiva un proyecto único de semestre:

**Proyecto integrador:** Sistema de Monitoreo Ambiental IoT con ESP32, sensores (DHT22/LDR), conectividad WiFi, backend y visualización.

### Arquitectura objetivo del proyecto
- **Percepción:** ESP32 + DHT22 + LDR
- **Red:** WiFi + HTTP/MQTT
- **Procesamiento:** API + almacenamiento de datos
- **Aplicación:** Dashboard de visualización (Ubidots STEM, ThingSpeak, Arduino Cloud, Blynk)

**Nota sobre plataformas:** El curso soporta múltiples plataformas IoT gratuitas. Ver [Guía de Plataformas](docs/plataformas-iot-gratuitas.md).

---

## Estructura del Repositorio

- `clases-html/`: clases oficiales para estudiantes (14 clases efectivas)
- `laboratorios-html/`: guías oficiales de laboratorios (5 laboratorios)
- `ejercicios-simulador/`: ejercicios interactivos para Wokwi
- `evaluaciones/`: rúbricas detalladas E1-E6
- `planificacion/cronograma-actualizado-2026.md`: calendario y evaluaciones oficiales
- `memory-bank/`: memoria del proyecto con contexto actualizado

---

## Cronograma Académico (Resumen)

| Sesión | Fecha | Clase | Evaluación |
|--------|-------|-------|------------|
| 1 | 02-feb | C1: Evolución de Internet | - |
| 2 | 09-feb | C2: Personas, Procesos, Datos, Cosas | - |
| 3 | 16-feb | C3: Transformación del Entorno | - |
| 4 | 23-feb | C4: Empresas y Ciudades Inteligentes | **E1 Investigación (15%)** |
| 5 | 02-mar | C5: LAN, WAN e Internet | - |
| 6 | 09-mar | C6: Predecir el Futuro | **E2 Prototipo (15%)** |
| 7 | 16-mar | C7: Interconexión de Computadoras | **E3 Software (20%)** |
| - | 23-mar | **FESTIVO: San José** | NO HAY CLASE |
| - | 30-mar | **RECESO: Semana Santa** | NO HAY CLASE |
| 8 | 06-abr | C8: Hardware y Software IoT | - |
| 9 | 13-abr | C9: Microcontroladores | - |
| 10 | 20-abr | C10: Sistemas Operativos IoT | **E4 Informe (15%)** |
| 11 | 27-abr | C11: Conexiones M2M/M2P/P2P | - |
| 12 | 04-may | C12: Caso SIATA + Marco Legal | **E5 Escrito (15%)** |
| 13 | 11-may | C13: El Futuro de Internet | - |
| - | 18-may | **FESTIVO: Ascensión del Señor** | NO HAY CLASE |
| 14 | 25-may | C14: Integración Final | **E6 Proyecto (20%)** |

---

## Prácticas con Simulador Wokwi

| Ejercicios | Fechas | Tema | Relación Evaluativa |
|------------|--------|------|---------------------|
| Ejercicios 1-3 | Feb | Fundamentos ESP32: LED + botón | E1 (15%) |
| Ejercicios 4-6 | Mar | Hardware ESP32 + Sensores DHT22/LDR | E2 (15%) |
| Ejercicios 7-9 | Abr | Programación ESP32 + WiFi | E3 (20%), E4 (15%) |
| Ejercicios 10-13 | May | Dashboard + Integración | E5 (15%), E6 (20%) |

**Nota:** Los laboratorios se realizan con simulador Wokwi (gratis online) + trabajo autónomo.

---

## Sistema de Evaluación

| Evaluación | Peso | Fecha | Modalidad | RA |
|------------|------|-------|-----------|-----|
| E1 | 15% | 23-feb-2026 | Investigación | Telecomunicaciones, Internet, conectividad |
| E2 | 15% | 09-mar-2026 | Prototipo | Interacción físico-virtual |
| E3 | 20% | 16-mar-2026 | Software | Dispositivos IoT, redes, protocolos |
| E4 | 15% | 20-abr-2026 | Informe | Gestión domótica y IoT |
| E5 | 15% | 04-may-2026 | Escrito | Marco legal regulatorio |
| E6 | 20% | 25-may-2026 | Proyecto | Normalización y estándares |
| **Total** | **100%** | | | |

---

## Requisitos Base del Estudiante

- Kit personal ESP32 (aprox. COP $56.500 - $65.000 por equipo).
- Laptop para clases y laboratorios.
- Acceso a emulador Wokwi (gratis online).
- Participación en actividades teóricas, prácticas y de proyecto.

> **⚠️ Festivos 2026 (Lunes):** San José 23-mar, Semana Santa 30-mar, Ascensión 18-may. NO HAY CLASE estos días.
> **📅 Seguimientos de notas:** 27-mar (50%), 15-may (80%), 28-may (100%).
> **📊 Total clases:** 14 clases × 2h = 28h (4h compensadas con trabajo autónomo).

---

## Referencia Rápida

- **Clases:** `clases-html/index.html` (14 clases efectivas)
- **Laboratorios:** `laboratorios-html/index.html` (5 laboratorios)
- **Ejercicios Simulador:** `ejercicios-simulador/index.html` (13 ejercicios Wokwi)
- **Evaluaciones:** `evaluaciones/rubrica-E*.md` (rúbricas E1-E6)
- **Cronograma:** `cronograma-oficial-2026-I.md`
- **Materiales:** `clases-html/clase-02-materiales.html`

> **💡 Emulador Wokwi:** [https://wokwi.com/esp32](https://wokwi.com/esp32) - Gratis, sin registro necesario
