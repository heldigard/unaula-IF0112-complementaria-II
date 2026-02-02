---
marp: true
theme: default
paginate: true
header: 'IF0112 - Complementaria II (IoT) | Unidad 2'
footer: 'UNAULA - Ingeniería Informática - 2026-I'
style: |
  img { max-width: 70% !important; max-height: 50vh !important; object-fit: contain !important; display: block !important; margin: 0 auto !important; }
---

# Clase 14: Marco Legal y Regulatorio IoT
## Regulación IoT en Colombia

**IF0112 - Complementaria II**
*6° Semestre - Ingeniería Informática*

---

## Objetivos de la Clase

Al finalizar esta clase, el estudiante será capaz de:

1. **Conocer** el marco legal aplicable a IoT en Colombia
2. **Aplicar** principios de protección de datos
3. **Identificar** responsabilidades legales
4. **Diseñar** sistemas cumpliendo normativas

**Duración:** 2 horas

---

## ¿Por Qué Importa el Marco Legal?

```
┌─────────────────────────────────────────────────────────────┐
│              IoT Y LA LEY: ¿POR QUÉ IMPORTA?               │
│                                                             │
│   IoT recolecta DATOS sobre:                               │
│   • Ubicación de personas                                  │
│   • Hábitos de consumo                                     │
│   • Información de salud                                   │
│   • Comportamiento en el hogar                             │
│   • Conversaciones (asistentes de voz)                     │
│                                                             │
│   RIESGOS:                                                  │
│   ⚠️ Violación de privacidad                               │
│   ⚠️ Vigilancia no autorizada                              │
│   ⚠️ Robo de identidad                                     │
│   ⚠️ Discriminación algorítmica                            │
│   ⚠️ Responsabilidad por daños                             │
│                                                             │
│   SIN REGULACIÓN → CAOS                                    │
│   Con REGULACIÓN → Confianza + Adopción                    │
└─────────────────────────────────────────────────────────────┘
```

---

## Marco Legal IoT en Colombia

```
┌─────────────────────────────────────────────────────────────┐
│           PIRÁMIDE NORMATIVA COLOMBIANA                     │
│                                                             │
│                    ┌─────────────┐                          │
│                    │Constitución│                          │
│                    │  Art. 15   │ ← Derecho a intimidad    │
│                    └─────────────┘                          │
│                   /              \                          │
│          ┌──────────┐      ┌──────────┐                    │
│          │Ley 1581  │      │Ley 1273  │                    │
│          │  2012    │      │  2009    │                    │
│          │(Habeas   │      │(Delitos  │                    │
│          │ Data)    │      │informát.)│                    │
│          └──────────┘      └──────────┘                    │
│              │                  │                           │
│              ▼                  ▼                           │
│    Decreto 1377/2013     Resoluciones                      │
│    (Reglamentación)      MinTIC/SIC                        │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

## Ley 1581 de 2012: Habeas Data

### Protección de Datos Personales

```
┌─────────────────────────────────────────────────────────────┐
│              LEY 1581 DE 2012                               │
│         "Ley de Protección de Datos Personales"            │
│                                                             │
│   DATOS PERSONALES: Cualquier información vinculada        │
│   a una persona natural identificada o identificable       │
│                                                             │
│   EN IoT ESTO INCLUYE:                                      │
│   • Dirección MAC del dispositivo                          │
│   • Ubicación GPS                                          │
│   • Consumo de energía/agua                                │
│   • Patrones de uso de dispositivos                        │
│   • Registros de voz                                       │
│   • Datos de salud (wearables)                             │
│   • Imágenes de cámaras                                    │
│                                                             │
│   ⚠️ Si puede identificar a una persona = dato personal   │
└─────────────────────────────────────────────────────────────┘
```

---

## Datos Sensibles en IoT

### Mayor Protección Legal

```
┌─────────────────────────────────────────────────────────────┐
│              DATOS SENSIBLES (Art. 5)                       │
│         Prohibido tratamiento SALVO autorización           │
│                                                             │
│   EN IoT:                                                   │
│                                                             │
│   🩺 SALUD                    📍 UBICACIÓN                  │
│   Wearables, monitores       GPS tracking                  │
│   de signos vitales          continuo                      │
│                                                             │
│   👁️ BIOMÉTRICOS             🗣️ VOZ/IMAGEN                 │
│   Reconocimiento facial,     Asistentes, cámaras          │
│   huellas, iris              de seguridad                  │
│                                                             │
│   ⛪ IDEOLOGÍA/RELIGIÓN       ⚖️ OTROS                      │
│   Si se puede inferir        Orientación sexual,          │
│   de datos IoT               vida sexual                   │
│                                                             │
│   REQUIEREN: Autorización EXPRESA + Finalidad legítima    │
└─────────────────────────────────────────────────────────────┘
```

---

## Principios de la Ley 1581 (1/2)

### Aplicados a IoT

| Principio | Significado | Aplicación IoT |
| ----------- | ------------- | ---------------- |
| **Legalidad** | Base legal para tratamiento | Autorización del usuario |
| **Finalidad** | Propósito específico y legítimo | Declarar uso de datos |
| **Libertad** | Consentimiento previo | Opt-in, no opt-out |
| **Veracidad** | Datos correctos y actualizados | Calibración sensores |

---

## Principios de la Ley 1581 (2/2)

### Tabla de Principios (continuación)

| Principio | Significado | Aplicación IoT |
| ----------- | ------------- | ---------------- |
| **Transparencia** | Informar al titular | Política de privacidad |
| **Seguridad** | Proteger contra acceso no autorizado | Cifrado, autenticación |
| **Confidencialidad** | No divulgar sin autorización | Control de acceso |

### AUTORIZACIÓN VÁLIDA

**Debe ser:**
- ✓ Previa (antes de recolectar)
- ✓ Expresa (afirmativa, no por silencio)
- ✓ Informada (usuario entiende qué y para qué)

**Debe informar:**
1. Qué datos se recolectan
2. Finalidad del tratamiento
3. Derechos del titular (ARCO)
4. Responsable del tratamiento
5. Transferencias a terceros

**Ejemplo IoT:**
"Esta cámara recolecta imágenes para seguridad. Las imágenes se almacenan 30 días en nuestros servidores. Puede solicitar acceso o eliminación escribiendo a privacidad@empresa.com"

---
### Requisitos Legales

---
## Derechos ARCO del Titular

```
┌─────────────────────────────────────────────────────────────┐
│              DERECHOS ARCO                                  │
│                                                             │
│   A - ACCESO                                                │
│       Saber qué datos tiene la empresa sobre mí            │
│       "Muéstrame todos los datos de mi smartwatch"         │
│                                                             │
│   R - RECTIFICACIÓN                                         │
│       Corregir datos incorrectos o incompletos             │
│       "Mi peso registrado es incorrecto"                   │
│                                                             │
│   C - CANCELACIÓN                                           │
│       Eliminar datos cuando ya no son necesarios           │
│       "Borra mi historial de ubicaciones"                  │
│                                                             │
│   O - OPOSICIÓN                                             │
│       Negarse al tratamiento para ciertos fines            │
│       "No quiero que compartan mi consumo energético"      │
│                                                             │
│   Las empresas IoT DEBEN implementar mecanismos            │
│   para ejercer estos derechos                              │
└─────────────────────────────────────────────────────────────┘
```

---

## Responsabilidad por Hackeo

### Aplicación a IoT

```
┌─────────────────────────────────────────────────────────────┐
│              LEY 1273 - DELITOS INFORMÁTICOS               │
│                                                             │
│   ARTÍCULO 269A: Acceso abusivo a sistema informático      │
│   → Hackear un dispositivo IoT: 4-8 años prisión           │
│                                                             │
│   ARTÍCULO 269C: Interceptación de datos                   │
│   → Capturar tráfico MQTT sin autorización                 │
│                                                             │
│   ARTÍCULO 269D: Daño informático                          │
│   → Sabotear sistema IoT industrial                        │
│                                                             │
│   ARTÍCULO 269F: Violación de datos personales             │
│   → Acceder a datos de wearables sin autorización          │
│                                                             │
│   ARTÍCULO 269G: Suplantación de sitios web                │
│   → Crear servidor MQTT falso para robar credenciales      │
│                                                             │
│   ⚠️ Ignorancia no exime responsabilidad                   │
└─────────────────────────────────────────────────────────────┘
```

---

## Regulación Sectorial IoT

### Normas Específicas por Industria

```
┌─────────────────────────────────────────────────────────────┐
│              REGULACIÓN POR SECTOR                          │
│                                                             │
│   🏥 SALUD (IoMT)                                           │
│   • Resolución 2654/2019 (Telemedicina)                    │
│   • Historia clínica electrónica                           │
│   • INVIMA para dispositivos médicos                       │
│                                                             │
│   ⚡ ENERGÍA                                                │
│   • Resolución CREG 030/2018 (Medidores inteligentes)      │
│   • Protección datos de consumo                            │
│                                                             │
│   🚗 VEHÍCULOS                                              │
│   • Ley 769/2002 (Código tránsito)                         │
│   • Resoluciones MinTransporte sobre GPS                   │
│                                                             │
│   📡 TELECOMUNICACIONES                                     │
│   • Ley 1341/2009 (TIC)                                    │
│   • Resoluciones CRC sobre espectro                        │
└─────────────────────────────────────────────────────────────┘
```

---

## GDPR y su Impacto en Colombia

### Regulación Europea con Alcance Global

```
┌─────────────────────────────────────────────────────────────┐
│              GDPR (Unión Europea)                           │
│         ¿Por qué importa en Colombia?                      │
│                                                             │
│   APLICA SI:                                                │
│   • Empresa colombiana vende a usuarios en UE              │
│   • Dispositivo IoT procesa datos de ciudadanos UE         │
│   • Cloud está en servidores europeos                      │
│                                                             │
│   REQUISITOS ADICIONALES:                                   │
│   • Privacy by Design (desde el diseño)                    │
│   • Evaluación de impacto (DPIA)                           │
│   • Oficial de protección de datos (DPO)                   │
│   • Notificación de brechas en 72 horas                    │
│   • Derecho al olvido                                      │
│   • Portabilidad de datos                                  │
│                                                             │
│   MULTAS: Hasta €20M o 4% ingresos globales                │
└─────────────────────────────────────────────────────────────┘
```

---

### Principios de Diseño
┌─────────────────────────────────────────────────────────────┐
│              CADENA DE RESPONSABILIDAD                      │
│                                                             │
│   �icing FABRICANTE                                         │
│   • Seguridad del dispositivo                              │
│   • Actualizaciones de firmware                            │
│   • Defectos de fábrica                                    │
│                                                             │
│   💻 DESARROLLADOR SOFTWARE                                 │
│   • Vulnerabilidades de código                             │
│   • Cifrado de datos                                       │
│   • Autenticación                                          │
│                                                             │
│   ☁️ PROVEEDOR CLOUD                                        │
│   • Seguridad de servidores                                │
│   • Disponibilidad del servicio                            │
│   • Backup de datos                                        │
│                                                             │
│   🏢 OPERADOR/EMPRESA                                       │
│   • Uso adecuado de datos                                  │
│   • Cumplimiento normativo                                 │
│   • Respuesta a incidentes                                 │
└─────────────────────────────────────────────────────────────┘
```

---
### ¿Quién Responde si Algo Sale Mal?

---

## Caso: Responsabilidad por Hackeo

### Escenario Hipotético

```
┌─────────────────────────────────────────────────────────────┐
│              CASO: HACKEO DE CERRADURA INTELIGENTE          │
│                                                             │
│   HECHOS:                                                   │
│   1. Usuario compra cerradura "SmartLock Pro"              │
│   2. Hacker explota vulnerabilidad y entra a casa          │
│   3. Roban objetos de valor                                │
│                                                             │
│   POSIBLES RESPONSABLES:                                    │
│                                                             │
│   🏭 Fabricante: ¿Vulnerabilidad conocida y no parcheada?  │
│   📱 App: ¿Almacenaba credenciales en texto plano?         │
│   ☁️ Cloud: ¿Permitió acceso no autorizado?                │
│   👤 Usuario: ¿Usó contraseña débil? ¿Ignoró updates?      │
│                                                             │
│   ANÁLISIS LEGAL:                                           │
│   • Garantía legal (Estatuto del Consumidor)               │
│   • Responsabilidad por producto defectuoso                │
│   • Diligencia en la protección de datos                   │
└─────────────────────────────────────────────────────────────┘
```

---

## Checklist Legal para Proyecto IoT
┌─────────────────────────────────────────────────────────────┐
│              PRIVACY BY DESIGN                              │
│         (Privacidad desde el Diseño)                       │
│                                                             │
│   1. PROACTIVO, NO REACTIVO                                │
│      Anticipar problemas de privacidad                     │
│                                                             │
│   2. PRIVACIDAD COMO CONFIGURACIÓN PREDETERMINADA          │
│      Máxima privacidad por defecto                         │
│                                                             │
│   3. PRIVACIDAD INTEGRADA EN EL DISEÑO                     │
│      No como añadido posterior                             │
│                                                             │
│   4. FUNCIONALIDAD COMPLETA                                │
│      Privacidad Y funcionalidad, no o/o                    │
│                                                             │
│   5. SEGURIDAD DE EXTREMO A EXTREMO                        │
│      Protección durante todo el ciclo de vida              │
│                                                             │
│   6. VISIBILIDAD Y TRANSPARENCIA                           │
│      Auditable y verificable                               │
│                                                             │
│   7. RESPETO POR EL USUARIO                                │
│      Usuario tiene el control                              │
└─────────────────────────────────────────────────────────────┘
```

---
### Principios de Diseño

---
## Checklist Legal para Proyecto IoT

```
┌─────────────────────────────────────────────────────────────┐
│              CHECKLIST CUMPLIMIENTO LEGAL                   │
│                                                             │
│   ANTES DEL DESPLIEGUE:                                     │
│   □ Política de privacidad clara y accesible              │
│   □ Mecanismo de autorización para datos personales        │
│   □ Registro ante SIC si aplica                           │
│   □ Evaluación de impacto en privacidad                    │
│   □ Cifrado de datos en tránsito y reposo                 │
│   □ Mecanismos para ejercer derechos ARCO                 │
│                                                             │
│   DURANTE OPERACIÓN:                                        │
│   □ Logs de acceso a datos                                 │
│   □ Actualizaciones de seguridad                           │
│   □ Respuesta a solicitudes de titulares                  │
│   □ Notificación de brechas de seguridad                  │
│                                                             │
│   AL FINALIZAR:                                             │
│   □ Eliminación segura de datos                           │
│   □ Notificación a usuarios                               │
│   □ Documentación de destrucción                          │
└─────────────────────────────────────────────────────────────┘
```

---

## Tendencias Regulatorias

### El Futuro del Marco Legal IoT

```
┌─────────────────────────────────────────────────────────────┐
│              TENDENCIAS REGULATORIAS                        │
│                                                             │
│   🌍 GLOBAL:                                                │
│   • Cyber Resilience Act (UE) - Seguridad obligatoria     │
│   • California IoT Security Law                            │
│   • UK PSTI Act - Prohibe contraseñas por defecto         │
│                                                             │
│   🇨🇴 COLOMBIA:                                              │
│   • Actualización Ley 1581 en discusión                   │
│   • Sandbox regulatorio para IoT (CONPES)                  │
│   • Regulación específica para vehículos autónomos        │
│   • Marco para ciudades inteligentes                       │
│                                                             │
│   HACIA DÓNDE VAMOS:                                        │
│   • Certificación obligatoria de seguridad                │
│   • Responsabilidad del fabricante más estricta           │
│   • Derecho a reparar dispositivos                        │
│   • Interoperabilidad obligatoria                         │
└─────────────────────────────────────────────────────────────┘
```

---

## Actividad: Análisis de Política de Privacidad

### Ejercicio Práctico (30 min)

**Instrucciones:**
1. Buscar política de privacidad de un dispositivo IoT (Alexa, Fitbit, Ring, etc.)
2. Analizar:
   - ¿Qué datos recolecta?
   - ¿Para qué los usa?
   - ¿Con quién los comparte?
   - ¿Cómo ejercer derechos ARCO?
3. Evaluar cumplimiento con Ley 1581

**Discusión:** ¿Es fácil para el usuario entender sus derechos?

---

## Resumen de la Clase

| Marco Legal | Aplicación IoT |
| ------------- | ---------------- |
| **Ley 1581/2012** | Protección datos personales recolectados por sensores |
| **Ley 1273/2009** | Delitos por hackeo, interceptación, sabotaje |
| **Derechos ARCO** | Usuarios pueden acceder, rectificar, cancelar datos |
| **GDPR** | Aplica si hay usuarios en UE |
| **Privacy by Design** | Diseñar pensando en privacidad desde el inicio |

---

## Próxima Clase

### Clase 15: Estándares Internacionales + E5 (15%)
- ISO/IEC 27001
- IEEE y estándares técnicos
- Evaluación E5: Análisis de estándares

### Preparación
- Revisar norma ISO 27001 (conceptos básicos)
- Preparar sustentaciones E4 (si quedaron pendientes)

**¡Nos vemos!**
