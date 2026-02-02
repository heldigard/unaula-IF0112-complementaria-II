---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 16: Proyecto Integrador Final y Examen

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Integrar** conocimientos del curso en un proyecto
2. **Diseñar** solución IoT completa
3. **Documentar** arquitectura técnica
4. **Sustentar** decisiones de diseño

**Duración:** 2 horas
**Evaluación:** Examen Final - 20% del curso

---
## Estructura del Examen Final

```
┌─────────────────────────────────────────────────────────────┐
│              EXAMEN FINAL - 20%                             │
│                                                             │
│   MODALIDAD: Proyecto de Diseño + Sustentación             │
│                                                             │
│   COMPONENTES:                                              │
│                                                             │
│   ┌──────────────────────────────────────────┐             │
│   │  DOCUMENTO DE DISEÑO (50%)               │             │
│   │  • Arquitectura de solución              │             │
│   │  • Análisis P-P-D-C (Personas, Procesos, Datos, Cosas) │             │
│   │  • Selección de tecnologías              │             │
│   │  • Consideraciones legales               │             │
│   └──────────────────────────────────────────┘             │
│                                                             │
│   ┌──────────────────────────────────────────┐             │
│   │  SUSTENTACIÓN INDIVIDUAL (50%)           │             │
│   │  • Defensa del diseño                    │             │
│   │  • Preguntas sobre decisiones            │             │
│   │  • Conocimiento general del curso        │             │
│   └──────────────────────────────────────────┘             │
│                                                             │
│   TRABAJO EN PAREJAS - SUSTENTACIÓN INDIVIDUAL             │
└─────────────────────────────────────────────────────────────┘
```

---

## Escenarios de Proyecto

### Opción A: Smart Campus UNAULA

```
┌─────────────────────────────────────────────────────────────┐
│              SMART CAMPUS UNAULA                            │
│                                                             │
│   CONTEXTO:                                                 │
│   La universidad quiere implementar IoT para mejorar       │
│   eficiencia energética, seguridad y experiencia estudiantil│
│                                                             │
│   ALCANCE (elegir 2-3):                                     │
│   • Control de iluminación automático                      │
│   • Sensores de ocupación en salones                       │
│   • Control de acceso a laboratorios                       │
│   • Monitoreo de consumo energético                        │
│   • Estacionamiento inteligente                            │
│   • Alertas de seguridad                                   │
│                                                             │
│   RESTRICCIONES:                                            │
│   • Presupuesto moderado (universidad pública)             │
│   • Integración con sistemas existentes                    │
│   • Privacidad de estudiantes                              │
└─────────────────────────────────────────────────────────────┘
```

---

## Escenarios de Proyecto

### Opción B: Agricultura de Precisión

```
┌─────────────────────────────────────────────────────────────┐
│              FINCA INTELIGENTE                              │
│                                                             │
│   CONTEXTO:                                                 │
│   Finca cafetera en Antioquia quiere modernizar            │
│   operaciones con tecnología IoT                           │
│                                                             │
│   ALCANCE (elegir 2-3):                                     │
│   • Monitoreo de humedad del suelo                         │
│   • Estación meteorológica                                 │
│   • Control de riego automático                            │
│   • Seguimiento de fermentación                            │
│   • Trazabilidad de cosecha                                │
│   • Alertas de plagas/enfermedades                         │
│                                                             │
│   RESTRICCIONES:                                            │
│   • Cobertura celular limitada                             │
│   • Sin electricidad en algunas zonas                      │
│   • Personal con baja alfabetización digital               │
└─────────────────────────────────────────────────────────────┘
```

---

## Escenarios de Proyecto

### Opción C: Retail Inteligente

```
┌─────────────────────────────────────────────────────────────┐
│              TIENDA CONECTADA                               │
│                                                             │
│   CONTEXTO:                                                 │
│   Cadena de tiendas de conveniencia quiere implementar     │
│   IoT para mejorar operaciones y experiencia del cliente   │
│                                                             │
│   ALCANCE (elegir 2-3):                                     │
│   • Refrigeración inteligente                              │
│   • Inventario automático                                  │
│   • Análisis de flujo de clientes                          │
│   • Digital signage personalizado                          │
│   • Self-checkout                                          │
│   • Prevención de pérdidas                                 │
│                                                             │
│   RESTRICCIONES:                                            │
│   • 50 tiendas a nivel nacional                            │
│   • Personal rotativo                                      │
│   • Cumplimiento de protección de datos                    │
└─────────────────────────────────────────────────────────────┘
```

---
### Opción D: Salud Conectada


```
┌─────────────────────────────────────────────────────────────┐
│              CLÍNICA IoT                                    │
│                                                             │
│   CONTEXTO:                                                 │
│   Clínica de atención primaria quiere implementar          │
│   monitoreo remoto de pacientes crónicos                   │
│                                                             │
│   ALCANCE (elegir 2-3):                                     │
│   • Monitoreo de signos vitales en casa                    │
│   • Recordatorios de medicamentos                          │
│   • Alertas a familiares/médicos                           │
│   • Teleconsulta integrada                                 │
│   • Gestión de citas automática                            │
│   • Seguimiento de rehabilitación                          │
│                                                             │
│   RESTRICCIONES:                                            │
│   • Pacientes adultos mayores                              │
│   • Datos sensibles de salud                               │
│   • Regulación INVIMA                                      │
│   • Historia clínica electrónica                           │
└─────────────────────────────────────────────────────────────┘
```

---
### Requisitos Obligatorios del Documento

```
┌─────────────────────────────────────────────────────────────┐
│         DOCUMENTO DE DISEÑO (10-15 páginas)                │
│                                                             │
│   1. RESUMEN EJECUTIVO (1 página)                          │
│      • Problema a resolver                                 │
│      • Solución propuesta                                  │
│      • Beneficios esperados                                │
│                                                             │
│   2. ANÁLISIS P-P-D-C (Personas, Procesos, Datos, Cosas) (2 páginas)                          │
│      • Personas: roles e interacciones                     │
│      • Procesos: flujos automatizados                      │
│      • Datos: qué se recolecta y cómo se usa              │
│      • Cosas: dispositivos y sensores                      │
│                                                             │
│   3. ARQUITECTURA TÉCNICA (3-4 páginas)                    │
│      • Diagrama de arquitectura                            │
│      • Selección de hardware                               │
│      • Protocolos de comunicación                          │
│      • Plataforma cloud/edge                               │
│      • Modelo de datos                                     │
│                                                             │
│   (Continúa...)                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## Estructura del Documento (Parte 2)

```
┌─────────────────────────────────────────────────────────────┐
│                                                             │
│   4. TIPOS DE COMUNICACIÓN (1-2 páginas)                   │
│      • Identificar interacciones M2M                       │
│      • Identificar interacciones M2P                       │
│      • Identificar interacciones P2P (si aplica)           │
│      • Diagrama de flujo de datos                          │
│                                                             │
│   5. SEGURIDAD Y CUMPLIMIENTO (2 páginas)                  │
│      • Análisis de riesgos                                 │
│      • Medidas de seguridad                                │
│      • Cumplimiento Ley 1581                               │
│      • Estándares aplicables                               │
│                                                             │
│   6. ANÁLISIS DE COSTOS (1 página)                         │
│      • Hardware                                            │
│      • Software/licencias                                  │
│      • Conectividad                                        │
│      • Mantenimiento anual                                 │
│                                                             │
│   7. CONCLUSIONES Y TRABAJO FUTURO                         │
│                                                             │
│   8. REFERENCIAS (mínimo 5)                                │
└─────────────────────────────────────────────────────────────┘
```

---
## Ejemplo: Diagrama de Arquitectura

```
┌─────────────────────────────────────────────────────────────┐
│                 ARQUITECTURA SMART CAMPUS                   │
│                                                             │
│   CAPA DISPOSITIVOS:                                        │
│   🌡️ DHT22    📍 PIR      💡 Relay    📸 ESP32-CAM         │
│      │           │           │           │                  │
│      └───────────┴───────────┴───────────┘                  │
│                      │                                      │
│                   WiFi/LoRa                                │
│                      │                                      │
│   CAPA EDGE:         ▼                                      │
│   ┌─────────────────────────────────────────┐              │
│   │          Gateway / Raspberry Pi          │              │
│   │     Procesamiento local + Buffer        │              │
│   └─────────────────────────────────────────┘              │
│                      │                                      │
│                   HTTPS/MQTT                               │
│                      │                                      │
│   CAPA CLOUD:        ▼                                      │
│   ┌─────────────────────────────────────────┐              │
│   │           AWS IoT / Azure IoT            │              │
│   │    Base de datos + Análisis + APIs      │              │
│   └─────────────────────────────────────────┘              │
│                      │                                      │
│   CAPA APLICACIÓN:   ▼                                      │
│   📱 App Móvil    🖥️ Dashboard    📧 Alertas               │
└─────────────────────────────────────────────────────────────┘
```

---

## Rúbrica de Evaluación - Documento

| Criterio | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (1-2) |
| ---------- | --------------- | ----------- | ------------- | ------------------ |
| **Análisis P-P-D-C** (20%) | Completo, profundo, bien justificado | Completo y adecuado | Incompleto o superficial | Ausente o erróneo |
| **Arquitectura técnica** (25%) | Detallada, coherente, justificada | Correcta con algunas lagunas | Básica o incompleta | Incorrecta |
| **Seguridad/Legal** (20%) | Análisis exhaustivo | Cubre aspectos principales | Superficial | Omitido |
| **Viabilidad** (15%) | Costos realistas, plan factible | Aceptable | Poco realista | Sin análisis |
| **Presentación** (10%) | Profesional, bien estructurado | Buena calidad | Aceptable | Pobre |
| **Referencias** (10%) | 5+ fuentes pertinentes | 3-4 fuentes | 1-2 fuentes | Sin referencias |

---

## Rúbrica de Evaluación - Sustentación

| Criterio | Excelente (5) | Bueno (4) | Regular (3) | Deficiente (1-2) |
| ---------- | --------------- | ----------- | ------------- | ------------------ |
| **Dominio del diseño** (40%) | Explica y defiende todas las decisiones | Domina mayoría de aspectos | Conocimiento básico | No puede explicar |
| **Respuestas técnicas** (30%) | Responde correcta y profundamente | Responde bien | Respuestas superficiales | Respuestas incorrectas |
| **Conceptos del curso** (30%) | Aplica todos los conceptos | Aplica conceptos principales | Conocimiento limitado | No aplica conceptos |

**IMPORTANTE:** Si la sustentación evidencia desconocimiento del proyecto, la nota individual será 1.0

---

## Preguntas de Sustentación (Ejemplos)

### Arquitectura
- ¿Por qué eligieron ese protocolo y no otro?
- ¿Qué pasa si el gateway se desconecta?
- ¿Cómo escala si duplican los dispositivos?

### Seguridad
- ¿Cómo protegen los datos en tránsito?
- ¿Qué pasa si hackean un sensor?
- ¿Cómo cumplen con el derecho al olvido?

### Conceptos del Curso
- Explique cómo aplica el modelo P-P-D-C
- ¿Dónde hay comunicación M2M en su diseño?
- ¿Qué estándares aplicarían a esta solución?

---

## Cronograma del Proyecto Final

| Semana | Actividad |
| -------- | ----------- |
| **Hoy** | Selección de escenario y pareja |
| **Semana 17** | Trabajo autónomo en documento |
| **Semana 18** | Entrega documento + Sustentaciones |
| **Semana 19** | Sustentaciones (continuación si necesario) |
| **Semana 20** | Publicación de notas finales |

---

## Entregables y Formato

```
┌─────────────────────────────────────────────────────────────┐
│              ENTREGABLES                                    │
│                                                             │
│   DOCUMENTO:                                                │
│   • Formato: PDF                                           │
│   • Nombre: EXAMEN_Apellido1_Apellido2_EscenarioX.pdf      │
│   • Entrega: Classroom antes de sustentación               │
│                                                             │
│   DIAGRAMAS:                                                │
│   • Incluir en documento                                   │
│   • Herramientas sugeridas:                                │
│     - Draw.io (gratuito)                                   │
│     - Lucidchart                                           │
│     - PlantUML                                             │
│     - Cualquier herramienta profesional                    │
│                                                             │
│   SUSTENTACIÓN:                                             │
│   • 15 minutos presentación                                │
│   • 10 minutos preguntas (individual)                      │
│   • Ambos integrantes deben poder responder TODO           │
└─────────────────────────────────────────────────────────────┘
```

---

## Recursos y Referencias

### Arquitecturas de Referencia
- AWS IoT Architecture
- Azure IoT Reference Architecture
- Google Cloud IoT

### Estimación de Costos
- AWS IoT Pricing Calculator
- Azure IoT Pricing
- Cotizaciones de hardware en MercadoLibre/Amazon

### Documentación de Estándares
- IEEE, ETSI, ISO (vistos en clase 15)

---

## Actividad: Selección y Planificación (30 min)

### Pasos

1. **Formar parejas** (5 min)
   - Máximo 2 personas

2. **Seleccionar escenario** (10 min)
   - Elegir A, B, C, o D
   - Registrar con el docente
   - Evitar repeticiones si es posible

3. **Definir alcance** (15 min)
   - Seleccionar 2-3 sub-sistemas del escenario
   - Identificar restricciones específicas
   - Bosquejar arquitectura inicial

---

## Honestidad Académica

```
┌─────────────────────────────────────────────────────────────┐
│              ⚠️ HONESTIDAD ACADÉMICA ⚠️                     │
│                                                             │
│   PERMITIDO:                                                │
│   ✓ Usar IA como herramienta de investigación             │
│   ✓ Consultar documentación y referencias                  │
│   ✓ Basar diseño en arquitecturas de referencia           │
│   ✓ Pedir retroalimentación al docente                    │
│                                                             │
│   PROHIBIDO:                                                │
│   ✗ Copiar trabajos de otros grupos                        │
│   ✗ Presentar trabajo ajeno como propio                    │
│   ✗ Sustentar sin conocer el contenido                     │
│                                                             │
│   CONSECUENCIAS:                                            │
│   • Copia = nota 0.0 para ambos grupos                     │
│   • Sustentación fallida = nota individual 1.0             │
│                                                             │
│   La sustentación VALIDA el aprendizaje                    │
└─────────────────────────────────────────────────────────────┘
```

---

## Resumen: Distribución de Notas del Curso

| Evaluación | Peso | Tipo | Estado |
| ------------ | ------ | ------ | -------- |
| **E1** | 15% | Análisis P-P-D-C | ✅ |
| **E2** | 15% | Laboratorio WiFi | ✅ |
| **E3** | 20% | Examen parcial | ✅ |
| **E4** | 15% | Caso de estudio | ✅ |
| **E5** | 15% | Análisis estándares | Pendiente |
| **Examen Final** | 20% | Proyecto diseño | Pendiente |
| **TOTAL** | 100% |  |  |

---

## Resumen de la Clase

| Tema | Puntos Clave |
| ------ | -------------- |
| **Proyecto Final** | 20% del curso, diseño + sustentación |
| **Escenarios** | Campus, Agricultura, Retail, Salud |
| **Documento** | 10-15 páginas, arquitectura completa |
| **Sustentación** | Individual, valida aprendizaje |
| **Plazo** | 2 semanas para documento |

---

## Conclusión del Curso

### IF0112 - Complementaria II (IoT)

**Lo que aprendimos:**
- Qué es IoT y el modelo P-P-D-C
- Tecnologías de comunicación (WiFi, LoRa, MQTT)
- Convergencia IT/OT y arquitecturas
- Marco legal y estándares internacionales
- Diseño de soluciones IoT completas

**Próximo paso:** Aplicar esto en el mundo real

**¡Éxitos en su proyecto final!**
