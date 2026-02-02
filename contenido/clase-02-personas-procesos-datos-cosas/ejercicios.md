# Ejercicios y Actividades

**Clase 2: Personas, Procesos, Datos y Cosas | Unidad 1**

## Actividad Principal: Diseño de Solución IoT con P-P-D-C

### Objetivo

Aplicar el modelo de los 4 pilares para diseñar una solución IoT completa para un escenario del campus universitario.

---

## Paso 1: Formación de Equipos (5 min)

### Distribución

- Grupos de **3 personas**
- Cada grupo selecciona **UN escenario** de la lista
- No puede haber grupos repetidos por escenario

### Escenarios Disponibles

| # | Escenario | Complejidad |
|---|-----------|-------------|
| 1 | Estacionamiento inteligente | Media |
| 2 | Biblioteca inteligente (aforo) | Baja |
| 3 | Sistema de riego jardines | Alta |
| 4 | Monitoreo de aulas | Media |
| 5 | Cafetería inteligente | Media |
| 6 | Gimnasio inteligente | Alta |

---

## Paso 2: Análisis del Escenario (15 min)

### Checklist de Análisis

Use este checklist para entender su escenario:

- [ ] **¿Qué problema se va a resolver?**
  - Problema actual: _____________________________
  - Impacto: _____________________________

- [ ] **¿Quiénes son los usuarios/afectados?**
  - Usuarios primarios: _____________________________
  - Usuarios secundarios: _____________________________

- [ ] **¿Qué datos existen actualmente?**
  - Datos actuales: _____________________________
  - ¿Son digitales?: [ ] Sí [ ] No

- [ ] **¿Qué procesos son manuales hoy?**
  - Proceso 1: _____________________________
  - Proceso 2: _____________________________

---

## Paso 3: Diseño P-P-D-C (40 min)

### Plantilla Completa de Diseño

Copie y complete esta plantilla para su escenario:

---

#### 👤 PERSONAS

| Rol | Nombre/Rol Real | Responsabilidades | Interfaz |
|-----|----------------|-------------------|----------|
| Usuario 1 | | | |
| Usuario 2 | | | |
| Operador | | | |
| Admin | | | |

**Diseño de Interfaz:**
- [ ] App móvil (iOS/Android)
- [ ] Dashboard web
- [ ] Pantallas físicas
- [ ] Asistente de voz
- [ ] Otro: _________

---

#### ⚙️ PROCESOS

Liste **mínimo 3 procesos** automatizados:

**Proceso 1:** _____________________________
```
IF: _____________________________
AND: _____________________________
THEN: _____________________________
```

**Proceso 2:** _____________________________
```
IF: _____________________________
AND: _____________________________
THEN: _____________________________
```

**Proceso 3:** _____________________________
```
IF: _____________________________
AND: _____________________________
THEN: _____________________________
```

**Tipo de automatización:**
- [ ] Totalmente automático (M2M)
- [ ] Semi-automático (con aprobación humana)
- [ ] Manual asistido (datos para decisión)

---

#### 📊 DATOS

| Dato | Fuente (Sensor) | Frecuencia | Tipo | Retención |
|------|-----------------|------------|------|-----------|
| | | | | |
| | | | | |
| | | | | |
| | | | | |

**Aplicación DIKW:**

| Nivel | Pregunta | Respuesta |
|-------|----------|-----------|
| 🔢 Datos | ¿Qué capturamos? | |
| 📋 Información | ¿Qué significa? | |
| 📚 Conocimiento | ¿Qué patrones hay? | |
| 🧠 Sabiduría | ¿Cómo optimizamos? | |

**Almacenamiento:**
- [ ] Base de datos tiempo real: _____________
- [ ] Base de datos histórico: _____________
- [ ] Storage para imágenes/video: _____________

---

#### 📱 COSAS

**Sensores (Input):**

| Sensor | Cantidad | Ubicación | Especificación |
|--------|----------|-----------|----------------|
| | | | |
| | | | |
| | | | |

**Actuadores (Output):**

| Actuador | Cantidad | Ubicación | Acción |
|----------|----------|-----------|--------|
| | | | |
| | | | |
| | | | |

**Dispositivos Híbridos:**

| Dispositivo | Cantidad | Función Input | Función Output |
|-------------|----------|---------------|----------------|
| | | | |

**Infraestructura:**
- [ ] Gateway(s): _____________
- [ ] Protocolo: _____________ (WiFi/Zigbee/LoRaWAN/BLE)
- [ ] Conectividad a nube: _____________
- [ ] Alimentación: _____________

---

#### 🔗 INTERACCIONES

**Mapa de Conexiones:**

```
Persona ──[P2M]──> Dispositivo A
Persona <─[M2P]─── Dispositivo B
Dispositivo A ──[M2M]──> Dispositivo C
Dispositivo C ──[M2P]──> Persona (alerta)
```

**Dibuje su diagrama:**



---

#### 🔒 SEGURIDAD Y PRIVACIDAD

**Datos Personales (Ley 1581):**
- [ ] ¿Se capturan datos personales?: [ ] Sí [ ] No
- [ ] ¿Se requiere autorización?: [ ] Sí [ ] No
- [ ] ¿Se implementa ARCO?: [ ] Sí [ ] No

**Medidas de Seguridad:**

| Capa | Medida Implementada |
|------|---------------------|
| Dispositivo | |
| Comunicación | |
| Plataforma | |
| Aplicación | |

---

## Paso 4: Validación del Diseño (10 min)

### Checklist de Validación

Antes de entregar, verifique:

- [ ] Los **4 pilares** están completos
- [ ] Hay **mínimo 3 procesos** IF-THEN
- [ ] Se identifican **5+ sensores/actuadores**
- [ ] El **flujo de datos** es claro
- [ ] Las **interacciones** P2M/M2M/M2P están definidas
- [ ] Se considera **seguridad y privacidad**
- [ ] El diseño es **viable técnicamente** (tecnología existe hoy)
- [ ] El **valor** para el usuario es claro

### Preguntas de Validación

1. **¿El sistema funciona si no hay Internet?**
   - [ ] Sí, tiene modo offline
   - [ ] No, requiere conexión continua
   - Mitigación: _____________________________

2. **¿Qué pasa si un sensor falla?**
   - Mitigación: _____________________________

3. **¿El sistema es escalable?**
   - [ ] Sí, fácil agregar más dispositivos
   - [ ] No, requiere re-diseño

4. **¿Cuál es el ROI aproximado?**
   - Inversión: $___________
   - Ahorro/Beneficio: $___________
   - Payback: ___________ meses/años

---

## Paso 5: Presentación (10 min por grupo)

### Formato de Presentación

**Duración:** 5 min presentación + 5 min preguntas

**Estructura sugerida:**

1. **Escenario (30 seg)**
   - Problema: _____________________________
   - Usuarios afectados: _____________________________

2. **Solución P-P-D-C (3 min)**
   - Personas involucradas
   - Procesos clave (2-3)
   - Datos principales
   - Cosas (sensores/actuadores)

3. **Valor (30 seg)**
   - Beneficio principal: _____________________________
   - ROI estimado: _____________________________

4. **Demo/Visualización (1 min)**
   - Diagrama de flujo
   - Mockup de interfaz (opcional)

---

## Rúbrica de Evaluación

### Criterios y Puntos

| Criterio | Puntos | Descripción |
|----------|--------|-------------|
| **Completitud** | 30 | Los 4 pilares bien definidos con 5+ elementos cada uno |
| **Interacciones** | 25 | Flujo claro entre pilares, P2M/M2M/M2P identificados |
| **Viabilidad** | 25 | Tecnología disponible hoy, arquitectura coherente |
| **Innovación** | 20 | Propuesta creativa, valor real diferenciado |
| **TOTAL** | 100 | |

### Escala de Calificación

| Rango | Calificación | Calificativo |
|-------|--------------|--------------|
| 90-100 | 4.5 - 5.0 | Excelente |
| 80-89 | 4.0 - 4.4 | Muy Bueno |
| 70-79 | 3.5 - 3.9 | Bueno |
| 60-69 | 3.0 - 3.4 | Aceptable |
| < 60 | < 3.0 | Insuficiente |

### Feedback Template

```
FORTALEZAS:
- _______________________________________________________
- _______________________________________________________

ÁREAS DE MEJORA:
- _______________________________________________________
- _______________________________________________________

RECOMENDACIÓN:
- _______________________________________________________
```

---

## Ejemplo Completado: Estacionamiento Inteligente

### 👤 Personas

| Rol | Nombre Real | Responsabilidades | Interfaz |
|-----|-------------|-------------------|----------|
| Usuario | Estudiantes | Buscar cupo | App móvil |
| Usuario | Visitantes | Pagar estacionamiento | App + QR |
| Operador | Seguridad | Monitorear incidents | Dashboard |
| Admin | Facilities | Configurar tarifas | Web portal |

### ⚙️ Procesos

**Proceso 1: Detección de cupo**
```
IF: Sensor inductivo activado
THEN: Marcar cupo como ocupado
AND: Actualizar contador en tiempo real
```

**Proceso 2: Guía al usuario**
```
IF: Usuario busca cupo + Cupo libre disponible
THEN: Enviar push notification
AND: Mostrar ubicación en mapa
```

**Proceso 3: Control de tiempo**
```
IF: Vehículo > 15 minutos en mismo cupo
THEN: Registrar hora inicio
AND: Iniciar cobro (según tarifa)
```

### 📊 Datos

| Dato | Sensor | Frecuencia | Tipo | Retención |
|------|--------|------------|------|-----------|
| Estado cupo | Inductivo | Evento | Boolean | 30 días |
| Ocupación | Cámara IA | 5 min | Conteo | 90 días |
| Flujo vehicular | Cámara | Evento | Video + Metadata | 30 días |

### 📱 Cosas

| Dispositivo | Cantidad | Tipo | Función |
|-------------|----------|------|---------|
| Sensor inductivo | 200 | Sensor | Detecta vehículo |
| Cámara IA | 20 | Híbrido | LEE placas + cuenta |
| LED indicador | 200 | Actuador | Verde/rojo |
| Barrera | 4 | Actuador | Control acceso |
| Pantalla | 5 | Display | Disponibilidad |

### 🔗 Interacciones

```
Estudiante (App) ──[P2M]──> Barrera (entrada)
Cámara IA ──[M2M]──> LED (ocupación)
Sensor ──[M2P]──> Estudiante (push notification)
Estudiante ──[P2M]──> Barrera (salida, pago)
```

---

## Tarea para Casa: Expansión del Diseño

### Entregable

Usando el escenario trabajado en clase:

1. **Expandir cada pilar** con 5+ elementos adicionales
2. **Dibujar diagrama** de arquitectura (herramientas: draw.io, Lucidchart)
3. **Identificar 3 procesos** con lógica IF-THEN detallada
4. **Listar datos** con frecuencia, formato y almacenamiento
5. **Documentar seguridad** según 4 capas

**Formato:** Documento PDF, 3-5 páginas

**Entrega:** Próxima clase (inicio del clase)

---

**[← Volver a README](README.md) | [Ir a Referencias →](referencias.md)**
