# Teoría: Los 4 Pilares de IoT - Detalle

**Clase 2: Personas, Procesos, Datos y Cosas | Unidad 1**

## 1. Modelo P-P-D-C: Análisis Profundo

### 1.1 Origen del Modelo

El modelo de **Personas, Procesos, Datos y Cosas** fue introducido por **Cisco Systems** como parte de su marco de **Internet of Everything (IoE)**. A diferencia del modelo tradicional de IoT (centrado solo en dispositivos), este modelo reconoce que el verdadero valor surge de la interconexión de los cuatro elementos.

### 1.2 Los Cuatro Pilares Definidos

#### 👤 Personas (People)

Las personas son el **centro** de cualquier solución IoT. Sin personas que definan objetivos, operen sistemas, y se beneficien de los resultados, IoT es solo tecnología sin propósito.

**Roles en IoT:**

| Rol | Función | Ejemplo |
|-----|---------|---------|
| **Usuario Final** | Beneficiario directo | Paciente que recibe monitoreo remoto |
| **Operador** | Gestión día a día | Técnico que monitorea dashboard de sensores |
| **Desarrollador** | Crea la solución | Ingeniero que programa el ESP32 |
| **Tomador de Decisiones** | Usa datos para decidir | Gerente que ajusta producción basado en datos |
| **Analista** | Interpreta patrones | Científico de datos que encuentra insights |

**Puntos de conexión:**
- Smartphones (apps móviles)
- Interfaces web (dashboards)
- Asistentes de voz (Alexa, Google Home)
- Wearables (smartwatch, pulseras)
- Interfaces físicas (pantallas táctiles, botones)

#### ⚙️ Procesos (Processes)

Los procesos son las **reglas de negocio** que determinan cómo se usa la información para crear valor. Sin procesos, los datos son solo números sin significado.

**Tipos de Procesos IoT:**

1. **Automatizados (M2M):** Sin intervención humana
   - Ejemplo: Si temp > 30°C → encender A/C automáticamente

2. **Semi-automatizados (Human-in-the-loop):** Con aprobación
   - Ejemplo: Alerta de fallo → espera confirmación → despacha técnico

3. **Manuales asistidos (Data-driven):** Humano decide con datos
   - Ejemplo: Dashboard de ocupación → administrador decide cerrar aula

**Elementos de un Proceso IoT:**

```
┌─────────────────────────────────────────────────────────┐
│                  COMPONENTE DE PROCESO                  │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  ENTRADA           LÓGICA           SALIDA              │
│  ┌─────────┐      ┌──────────┐     ┌─────────┐         │
│  │  Datos  │ ──→  │ IF-THEN  │ ──→ │ Acción  │         │
│  │sensor   │      │ Reglas   │     │         │         │
│  └─────────┘      └──────────┘     └─────────┘         │
│                                                         │
│  "Temp: 32°C"     "Si T > 30"     "Encender A/C"       │
│                   "entonces..."                          │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Ejemplos de Reglas de Proceso:**

| Condiciones (IF) | Acciones (THEN) | Tipo |
|------------------|-----------------|------|
| Temperatura > 30°C por 10 min | Encender A/C | Automático |
| Movimiento detectado + noche | Grabar video + notificar | Automático |
| Nivel agua < 20% | Enviar alerta a operador | Semi-auto |
| Ocupación > 90% | Sugerir abrir aula adicional | Manual asistido |

#### 📊 Datos (Data)

Los datos son el **combustible** de IoT. Conectan el mundo físico con el digital y permiten que los procesos tomen decisiones informadas.

**Las 4 V de los Datos IoT:**

| V | Descripción | Ejemplo Práctico | Métrica Típica |
|:-:|-------------|------------------|----------------|
| **Volumen** 📊 | Cantidad masiva | 10,000 sensores × 1 lectura/min | TB/día |
| **Velocidad** ⚡ | Rapidez de generación | Alerta en < 100ms | Latencia ms |
| **Variedad** 🎨 | Tipos diversos | Texto, video, numérico, audio | 10+ formatos |
| **Veracidad** ✅ | Calidad/confiabilidad | Calibración de sensor | 95-99% precisión |

#### 📱 Cosas (Things)

Las "cosas" son los **objetos físicos conectados** que capturan datos del mundo real o ejecutan acciones físicas.

**Taxonomía de Dispositivos IoT:**

```
DISPOSITIVOS IoT
├── SENSORES (Input)
│   ├── Ambientales: Temp, humedad, presión, calidad aire
│   ├── Movimiento: Acelerómetro, giroscopio, GPS
│   ├── Biométricos: Pulso, SpO2, temperatura corporal
│   ├── Visuales: Cámara, micrófono, LiDAR
│   └── Presencia: Proximidad, infrarrojo, ultrasonido
│
├── ACTUADORES (Output)
│   ├── Eléctricos: Relés, interruptores, motores
│   ├── Mecánicos: Servos, bombas, válvulas
│   ├── Auditivos: Altavoces, sirenas, buzzers
│   └── Visuales: LEDs, pantallas, proyectores
│
└── HÍBRIDOS (Input + Output)
    ├── Smartphones
    ├── Smartwatches
    ├── Asistentes de voz
    └── Controladores centrales (Hub)
```

### 1.3 Interacciones entre Pilares

| Interacción | Código | Descripción | Ejemplo |
|-------------|--------|-------------|---------|
| Persona ↔ Cosa | **P2M** | Humano controla dispositivo | App enciende luz |
| Cosa ↔ Cosa | **M2M** | Dispositivos se comunican | Sensor temp → A/C |
| Cosa ↔ Persona | **M2P** | Dispositivo notifica humano | Sensor movimiento → Alerta |
| Persona ↔ Persona | **P2P** | Humanos colaboran vía IoT | Telemedicina |

---

## 2. Jerarquía DIKW: De Datos a Sabiduría

### 2.1 Origen del Modelo

La **Jerarquía DIKW** (Data-Information-Knowledge-Wisdom) tiene sus raíces en:
- **T.S. Eliot (1934):** "Where is the wisdom we have lost in knowledge?"
- **Ackoff (1989):** Formalización de la jerarquía
- **Milan Zeleny (1987):** Adición del contexto de creación de valor

### 2.2 Definiciones Detalladas

#### 🔢 Datos (Data)

**Definición:** Hechos brutos, sin procesar, sin contexto.

**Características:**
- Son crudos y objetivamente medibles
- No tienen significado por sí mismos
- Requieren interpretación para tener valor

**Ejemplos IoT:**
```
- "32" (lectura de sensor de temperatura)
- "1" (sensor de presencia activado)
- "15.3" (voltaje en batería)
- "192.168.1.100" (dirección IP)
```

**Analogía:** Es como tener las letras de un alfabeto sin formar palabras.

#### 📋 Información (Information)

**Definición:** Datos con contexto, organizados y estructurados.

**Transformación:** Datos + Contexto = Información

**Características:**
- Tiene significado (responde a "qué", "dónde", "cuándo")
- Está organizada y categorizada
- Permite tomar decisiones básicas

**Ejemplos IoT:**
```
- "32°C" es alta → encender A/C
- "1" = presencia detectada → grabar video
- "15.3V" → batería al 88% de carga
- "192.168.1.100" → sensor ID #45 en Sala A
```

**Analogía:** Es como formar palabras con letras: "C-A-S-A" significa "casa".

#### 📚 Conocimiento (Knowledge)

**Definición:** Información con patrones identificados y relaciones entendidas.

**Transformación:** Información + Patrones = Conocimiento

**Características:**
- Responde a "cómo" funciona algo
- Identifica tendencias y relaciones
- Permite explicaciones y predicciones simples

**Ejemplos IoT:**
```
- "Entre las 2-6 PM, temp sube 15% en promedio"
- "Cuando humedad < 30%, planta requiere riego"
- "Los lunes por la mañana, ocupación es 80% mayor"
- "Batería dura 7 días con 1 lectura/min"
```

**Analogía:** Es como entender gramática: "sujeto + verbo + predicado = oración".

#### 🧠 Sabiduría (Wisdom)

**Definición:** Conocimiento aplicado con experiencia para tomar decisiones óptimas.

**Transformación:** Conocimiento + Experiencia + Juicio = Sabiduría

**Características:**
- Responde a "por qué" y "qué hacer"
- Incluye consideraciones éticas y de largo plazo
- Permite optimización y predicción avanzada

**Ejemplos IoT:**
```
- "Optimizar riego según patrones de 10 años + clima previsto"
- "Predecir falla de máquina 48h antes (mantenimiento preventivo)"
- "Ajustar temperatura según historial personal + preferencias + clima"
- "Reducir consumo energético 20% sin牺牲 confort"
```

**Analogía:** Es como escribir un poema: usa gramática + creatividad + propósito.

### 2.3 Ejemplo Completo: Sensor de Temperatura

```
ESCENARIO: Sistema de HVAC en edificio inteligente

┌─────────────────────────────────────────────────────────────┐
│ NIVEL       │ EJEMPLO                  │ ACCIÓN ASOCIADA     │
├─────────────────────────────────────────────────────────────┤
│ 🧠 SABIDURÍA │ "Optimizar energía según  │ Programar horarios  │
│             │  patrones estacionales"   │  estacionales       │
├─────────────────────────────────────────────────────────────┤
│ 📚 CONOCI-  │ "Entre 2-6 PM, temp sube │ Pre-enfriar antes   │
│   MIENTO    │  15% en promedio"         │  de las 2 PM        │
├─────────────────────────────────────────────────────────────┤
│ 📋 INFORMA- │ "32°C es alta, 22°C      │ Encender/apagar A/C │
│   CIÓN      │  es óptima"               │  según umbral       │
├─────────────────────────────────────────────────────────────┤
│ 🔢 DATOS    │ "32, 31, 33, 32, 34..."   │ Capturar lecturas   │
│             │  (números crudos)         │  cada 5 min         │
└─────────────────────────────────────────────────────────────┘
```

### 2.4 Aplicando DIKW en Diseño IoT

**Preguntas guía para cada nivel:**

| Nivel | Pregunta Clave | Output en Diseño |
|-------|----------------|------------------|
| 🔢 Datos | ¿Qué capturamos? | Especificación de sensores |
| 📋 Información | ¿Qué significa? | Umbral y alertas |
| 📚 Conocimiento | ¿Qué patrones hay? | Análisis histórico |
| 🧠 Sabiduría | ¿Cómo optimizamos? | Automatización inteligente |

---

## 3. Ley 1581 de 2012: Guía para Desarrolladores IoT

### 3.1 Contexto Legal

Colombia fue pionera en América Latina con la **Ley 1581 de 2012**, que regula el tratamiento de datos personales. Todo proyecto IoT que capture datos de personas debe cumplirla.

### 3.2 Derechos ARCO Explicados

#### Acceso (A)

**Derecho del titular:** Conocer qué datos tiene la empresa.

**Implementación IoT:**
```
Requisito técnico:
- Endpoint API: GET /api/v1/user/data
- Autenticación: OAuth 2.0 + MFA
- Respuesta: JSON con todos los datos del usuario
- Formato: Human-readable + machine-readable

Ejemplo:
GET /api/v1/user/data
Authorization: Bearer <token>

Response 200:
{
  "user_id": "12345",
  "data_collected": {
    "temperature_readings": 1450,
    "location_history": "enabled",
    "voice_recordings": 23
  },
  "third_parties": ["Google Analytics"],
  "retention_period": "2 years"
}
```

#### Rectificación (R)

**Derecho del titular:** Corregir datos errados o incompletos.

**Implementación IoT:**
```
Requisito técnico:
- Endpoint API: PUT /api/v1/user/data
- Validación: Confirmar identidad con 2FA
- Log: Audit log de cambios

Ejemplo:
PUT /api/v1/user/data/profile
{
  "field": "email",
  "old_value": "old@email.com",
  "new_value": "new@email.com",
  "reason": "Correo actualizado"
}

Response 200:
{
  "status": "updated",
  "timestamp": "2026-02-01T10:30:00Z",
  "audit_id": "AUD-2026-0201-001"
}
```

#### Cancelación (S) / Supresión

**Derecho del titular:** Eliminar datos cuando no sean necesarios.

**Implementación IoT:**
```
Requisito técnico:
- Endpoint API: DELETE /api/v1/user/data
- Política: Retención por X años, luego purge
- Excepción: Datos requeridos por ley (impuestos, salud)

Ejemplo:
DELETE /api/v1/user/data
{
  "categories": ["voice_recordings", "location"],
  "reason": "withdraw_consent"
}

Response 200:
{
  "status": "deleted",
  "data_deleted": 450,
  "data_retained": ["billing_records"],
  "retained_reason": "legal_requirement"
}
```

#### Oposición (O)

**Derecho del titular:** Negar el uso de datos para ciertos fines.

**Implementación IoT:**
```
Requisito técnico:
- Endpoint API: POST /api/v1/user/consent
- Granularidad: Por tipo de dato y por propósito
- Revocabilidad: Opt-out debe ser tan fácil como opt-in

Ejemplo:
POST /api/v1/user/consent
{
  "data_type": "location",
  "purpose": "third_party_sharing",
  "consent": false
}

Response 200:
{
  "status": "opposition_recorded",
  "effective_date": "2026-02-01T10:30:00Z",
  "third_parties_notified": ["partner_a", "partner_b"]
}
```

### 3.3 Deberes de Empresas IoT

| Deber | Requisito Técnico | Implementación |
|-------|-------------------|----------------|
| **Información** | Política de privacidad clara | UI/UX en onboarding + link persistente |
| **Autorización** | Opt-in explícito | Checkbox no pre-marcado + confirmación |
| **Seguridad** | Protección adecuada | Encriptación TLS 1.3 + AES-256 at-rest |
| **Minimización** | Solo datos necesarios | Revisión periódica de collected data |
| **Confidencialidad** | No compartir sin consentimiento | Contracts con terceros + audit |

### 3.4 Sanciones

| Tipo | Sanción Máxima | Caso Típico |
|------|----------------|-------------|
| **Multa** | 1000 SMLMV (~$260M USD) | Fuga de datos masiva |
| **Operativa** | Cierre de servicios | No cumplir con solicitud ARCO |
| **Legal** | Responsabilidad civil/penal | Venta de datos sin consentimiento |

> **SMLMV 2025:** ~$260,000 USD
> **1000 SMLMV:** ~$260,000,000 USD

---

## 4. Seguridad IoT por Capas

### 4.1 Modelo de 4 Capas

```
┌─────────────────────────────────────────────────────────┐
│ CAPA 4: APLICACIÓN                                      │
│ - OAuth 2.0, GDPR/Ley 1581, consent management          │
├─────────────────────────────────────────────────────────┤
│ CAPA 3: PLATAFORMA                                      │
│ - MFA, RBAC, AES-256 at-rest, audit logs               │
├─────────────────────────────────────────────────────────┤
│ CAPA 2: COMUNICACIÓN                                    │
│ - TLS/SSL, Certificados X.509, VPN                      │
├─────────────────────────────────────────────────────────┤
│ CAPA 1: DISPOSITIVO                                     │
│ - Secure boot, AES-256 storage, OTA updates             │
└─────────────────────────────────────────────────────────┘
```

### 4.2 Checklist de Seguridad por Capa

**Capa 1 - Dispositivo:**
- [ ] Secure boot habilitado
- [ ] Encriptación de storage (AES-256)
- [ ] Actualizaciones OTA seguras (firmas digitales)
- [ ] Hardening (eliminar servicios innecesarios)
- [ ] JTAG/UART deshabilitados en producción

**Capa 2 - Comunicación:**
- [ ] TLS 1.3 mínimo (no SSL/TLS < 1.2)
- [ ] Certificados X.509 válidos
- [ ] Mutual authentication (mTLS)
- [ ] VPN para comunicaciones internas

**Capa 3 - Plataforma:**
- [ ] MFA obligatorio para admin
- [ ] RBAC (role-based access control)
- [ ] Encriptación at-rest (AES-256)
- [ ] Audit logs inmutables

**Capa 4 - Aplicación:**
- [ ] OAuth 2.0 / OpenID Connect
- [ ] Consent management (GDPR/Ley 1581)
- [ ] Rate limiting
- [ ] Input validation

---

**[← Volver a README](README.md) | [Ir a Casos →](casos.md)**
