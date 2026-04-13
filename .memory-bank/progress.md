# Progress - IF0112 IoT UNAULA

**Última actualización:** 2026-04-13

## Estado Actual

| Campo | Valor |
|-------|-------|
| **Corte actual** | 1er Corte (50%) - ✅ Completado |
| **Fecha corte** | 16-mar-2026 |
| **Próximo corte** | 2do Corte (50%) - 🔄 En preparación |

---

## Primer Corte - Completado ✅

| Evaluación | Fecha | Estado | Entregable |
|------------|-------|--------|------------|
| E1 - Arquitectura IoT | 23-feb-2026 | ✅ Entregada | PDF con arquitectura de 4 capas |
| E2 - Prototipo Sensórico | 09-mar-2026 | ✅ Entregada | ESP32 + DHT22 + LDR funcional |
| E3 - Software IoT | 16-mar-2026 | ✅ Entregada | HTTP GET a ThingSpeak |

### Temáticas Cubiertas

| # | Temática | % | Estado |
|---|----------|---|--------|
| 1 | Fundamentos de IoT y Arquitectura | 100% | ✅ Finalizado |
| 2 | Hardware y Sensores | 100% | ✅ Finalizado |
| 3 | Conectividad WiFi y Protocolos | 100% | ✅ Finalizado |
| 4 | Proyecto SMAI (fases 1-3) | 100% | ✅ Finalizado |

---

## Segundo Corte - Reestructurado 🔄

> **Nota (2026-04-13):** El profesor reorientó el segundo corte para enfocarse en construcción física del proyecto con flujo de datos real: **ESP32 → FastAPI/MQTT → Base de Datos → Visualización**. Se prioriza infraestructura propia sobre dependencia exclusiva de plataformas IoT externas.

| Evaluación | Tema | Peso | Fecha |
|------------|------|------|-------|
| E4 | Firmware mejorado + FastAPI + BD | 15% | 20-abr-2026 |
| E5 | Demo integración total + Visualización | 15% | 04-may-2026 |
| E6 | Entrega final del proyecto con sustentación | 20% | 25-may-2026 |

### Progresión Coherente E4 → E5 → E6

```
E4 (20-abr)         E5 (04-may)              E6 (25-may)
┌──────────────┐    ┌──────────────┐         ┌──────────────┐
│ Firmware     │    │ + Visualizac.│         │ Sistema      │
│ mejorado     │───►│ + Integración│────────►│ completo     │
│ + API básica │    │   en vivo    │         │ + Sustentac. │
│ + BD inicial │    │ + Dashboard  │         │ + Funcional  │
└──────────────┘    └──────────────┘         └──────────────┘
```

**Principio:** Cada evaluación construye sobre la anterior. Nada se descarta entre entregas.

### Contenidos por sesión:
- **C10 (20-abr):** FastAPI + SQLite + Primera API IoT + E4
- **C11 (27-abr):** API REST completa + MQTT opcional + Persistencia
- **C12 (04-may):** Integración total del sistema + Demo E5
- **C13 (11-may):** Preparación sustentación + Tendencias IoT (5G, AIoT, TinyML)
- **C14 (25-may):** E6 Sustentación proyecto final

### Stack técnico estudiantes:
- **API:** FastAPI local en Windows (principal) | MQTT broker público (alternativa)
- **BD:** SQLite recomendado | MySQL opcional
- **Firmware:** ESP32 con `millis()`, máquina de estados, histéresis, HTTP POST JSON
- **Visualización:** HTML+JS con `fetch()` a la API, o Grafana

---

## Materiales Actualizados (2026-04-13)

### Guías de evaluación
- ✅ `evaluaciones/guia-E4.html` — Cimientos del proyecto (FastAPI + SQLite + firmware)
- ✅ `evaluaciones/guia-E5.html` — Demo de integración total del sistema
- ✅ `evaluaciones/guia-E6.html` — Sustentación del sistema completo

### Clases reescritas
- ✅ `clases-html/clase-10.html` — FastAPI + SQLite + E4
- ✅ `clases-html/clase-11.html` — API completa + MQTT opcional
- ✅ `clases-html/clase-12.html` — Integración total + Demo E5
- ✅ `clases-html/clase-13.html` — Preparación sustentación + Tendencias IoT
- ✅ `clases-html/clase-14.html` — E6 Sustentación final

### Código de ejemplo creado
- ✅ `codigo/servidor/api/main.py` — FastAPI + SQLite + CORS completo
- ✅ `codigo/servidor/api/requirements.txt` — `fastapi`, `uvicorn[standard]`, `pydantic`
- ✅ `codigo/esp32/esp32-http-post-api.ino` — Sketch ESP32 con HTTP POST JSON
- ✅ `codigo/servidor/mqtt/subscriber.py` — MQTT subscriber alternativo

### Planificación
- ✅ `planificacion/cronograma.html` — Actualizado con nuevos contenidos C10-C14 y E5

### Correcciones de coherencia descubiertas en auditoría (2026-04-13)
- ✅ `evaluaciones/rubricas-evaluacion.html` — Rúbricas E4-E6 reescritas para el nuevo enfoque FastAPI/MQTT+BD; anclas `#e4`, `#e5`, `#e6` agregadas
- ✅ `evaluaciones/index.html` — Títulos y descripciones de tarjetas E4-E6 actualizados
- ✅ `clases-html/index.html` — Sesiones 10-12 y tarjetas de evaluación corregidas
- ✅ `clases-html/clase-00.html` — Tabla de evaluación E5 corregida de "Escrito" a "Demo"
- ✅ `clases-html/clase-02.html` — Forward-reference a E5 como evaluación de normatividad eliminado
- ✅ `clases-html/clase-08.html` / `clase-09.html` — Referencias a "LAB 4 Grafana" y "E4 Informe de Gestión" corregidas al nuevo enfoque FastAPI+SQLite
- ✅ `admin/concertacion.html` — E5 corregido de "Escrito" a "Demo"; descripción actualizada a integración en vivo
- ✅ `docs/proyecto-integrador-2026-I.html` — Tabla de evaluaciones E4-E6 corregida
- ✅ `laboratorios-html/index.html` — LAB 4 desacoplado de Clase 10/E4; etiquetado como apoyo opcional para E5/E6
- ✅ `laboratorios-html/lab-oficial-04-dashboard-grafana.html` — Enlace de evaluación ajustado a E5/E6

---

## Tareas Pendientes

- [x] Reestructurar guías E4, E5, E6 para enfoque FastAPI/MQTT + BD
- [x] Reescribir clases 10-14 con progresión coherente
- [x] Crear código de ejemplo funcional (API + ESP32 + MQTT)
- [x] Actualizar cronograma y navegación del curso
- [ ] Implementar sustentaciones grupales E5/E6 para evaluar participación individual
- [ ] Preparar reporte de seguimiento académico del 2do corte
- [ ] Monitorear avance físico de proyectos en clase (troubleshooting hardware)

---

## Reportes de Seguimiento

| Fecha | Corte | Estado |
|-------|-------|--------|
| 16-mar-2026 | 1er Corte | ✅ Completado |
| (por definir) | 2do Corte | 🔄 En preparación |

---

## Observaciones Importantes

1. **Reestructuración 2do corte (abr-2026):** Enfoque cambió a "Construcción de infraestructura propia API+BD". E6 es la entrega final del proyecto presentada con sustentación oral y demo en vivo. FastAPI y MQTT son ambos válidos como flujo principal. ThingSpeak/Ubidots son opcionales.
2. **Trabajo en grupo:** Se mantienen sustentaciones grupales para E5 y E6 para evaluar participación individual.
3. **Hardware:** Se requiere que el producto físico esté encapsulado para E6 (caja/gabinete, sin cables sueltos).
4. **Programación:** Se reforzó `millis()` vs `delay()` en E4; se espera dominio de máquina de estados e histéresis.
5. **Conectividad:** PC y ESP32 deben estar en la misma red WiFi; CORS habilitado para visualización web.

---

## Commit Históricos (referencia)

```
9c34723 Fix outdated references to old E5 and Clase 10 structure
62c016d Fix concertacion.html: E5 is Demo, not Escrito
db077d2 Fix lab index coherence: decouple Grafana lab from Clase 10/E4
d0afa65 Add hands-on activities and day-of guidance to classes 10-14
4a67e18 Add .serena/ and screencapture files to .gitignore
d85ad86 Restructure 2nd cut for FastAPI/MQTT + BD focus (E4-E6)
09bd56d Improve E3 evaluation guide for better student understanding
cd86d14 Fix broken links in main index for GitHub Pages
b10764b Add ThingSpeak introduction for students
315e5e7 Enrich class 07 (WiFi connectivity) with comprehensive improvements
e494458 Docs: Improve exercises 11-12 with troubleshooting and detailed instructions
```
