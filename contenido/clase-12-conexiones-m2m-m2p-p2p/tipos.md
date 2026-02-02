# Tipos de Conexión IoT

**Clase 12: Conexiones M2M-M2P-P2P | Unidad 2**

## Clasificación de Conexiones

```
         Persona (P)                  Máquina (M)
           │                            │
           │                            │
    ┌──────┴──────┐              ┌─────┴─────┐
    │            │              │           │
  P2M          M2P            M2M          P2P
(Persona-   (Máquina-      (Máquina-   (Persona-
Máquina)   Persona)       Máquina)   Persona)
```

## 1. P2M (Persona a Máquina)

### Definición
Un humano controla o interactúa directamente con un dispositivo IoT.

### Ejemplos

| Caso | P → M | Descripción |
|------|------|-------------|
| **Smart Home** | App enciende luz | Usuario toca botón en app |
| **Vehículo** | Conductor activa calefacción | Botón físico en panel |
| **Industrial** | Operario ajusta parámetros | HMI panel táctil |
| **Wearable** | Usuario consulta reloj | Tap en pantalla |

### Características

- **Latencia:** < 100ms (feedback inmediato)
- **Confianza:** Alta (humano en el loop)
- **Complejidad:** Baja
- **Ejemplo Código:**

```cpp
// App envía comando al ESP32
void loop() {
  if (Serial.available()) {
    char comando = Serial.read();
    if (comando == '1') {
      digitalWrite(LED_PIN, HIGH); // Encender luz
    }
  }
}
```

## 2. M2M (Máquina a Máquina)

### Definición
Dos o más dispositivos IoT se comunican sin intervención humana.

### Ejemplos

| Caso | M → M | Descripción |
|------|------|-------------|
| **Domótica** | Sensor movimiento → Cámara | Movimiento detectado activa grabación |
| **Industrial** | Sensor vibración → Motor | Vibración alta para motor automáticamente |
| **Agricultura** | Sensor humedad → Válvula | Suelo seco abre riego |
| **Smart Grid** | Medidor → Interruptor | Demanda alta carga se apaga |

### Características

- **Latencia:** Variable (ms a segundos)
- **Autonomía:** Completa
- **Complejidad:** Media-Alta
- **Ejemplo Código:**

```cpp
// ESP32 (M1) publica, ESP32 (M2) recibe y actúa
// Emisor (M1)
void loop() {
  float temp = dht.readTemperature();
  if (temp > 30) {
    client.publish("casa/living/alerta", "TEMP_ALTA");
  }
}

// Receptor (M2)
void callback(char* topic, byte* payload, unsigned int length) {
  if (strcmp((char*)payload, "TEMP_ALTA") == 0) {
    digitalWrite(AIRE_PIN, HIGH); // Encender A/C
  }
}
```

## 3. M2P (Máquina a Persona)

### Definición
Un dispositivo IoT notifica o entrega información a un humano.

### Ejemplos

| Caso | M → P | Descripción |
|------|------|-------------|
| **Wearable** | Reloj → Usuario | Alerta de frecuencia cardíaca |
| **Smart Home** | Sensor → App | Notificación "Puerta abierta" |
| **Industrial** | Máquina → Operario | "Mantenimiento requerido en 48h" |
| **Smart City** | Semáforo → Conductor | "Luz roja en 10s" |

### Características

- **Latencia:** Segundos aceptable
- **Formato:** Push, email, dashboard
- **Confianza:** Media (requiere verificación)
- **Ejemplo Código:**

```cpp
// ESP32 notifica al usuario via Push
void enviarNotificacionPush(String mensaje) {
  HTTPClient http;
  http.begin("https://push.example.com/api");
  http.addHeader("Content-Type", "application/json");

  String payload = "{\"message\":\"" + mensaje + "\"}";
  int httpCode = http.POST(payload);

  http.end();
}

void loop() {
  if (alguienDetectada()) {
    enviarNotificacionPush("Movimiento en sala");
  }
}
```

## 4. P2P (Persona a Persona vía IoT)

### Definición
Personas se comunican entre sí, mediado por tecnología IoT.

### Ejemplos

| Caso | P → [IoT] → P | Descripción |
|------|---------------|-------------|
| **Telemedicina** | Paciente → Cloud → Doctor | Datos vitales transmitidos |
| **Adulto mayor** | Abuelo → Alerta → Familia | Caída detectada |
| **Colaborativo** | Usuario 1 → Shared → Usuario 2 | Edificio de oficina compartido |
| **Social** | Jugador → Plataforma → Amigos | Videojuego AR |

### Características

- **Latencia:** Baja (< 1s para sensación de inmediatez)
- **Interactividad:** Bidireccional
- **Enriquecimiento:** Datos contextuales
- **Ejemplo Código:**

```cpp
// Paciente (P1) → Cloud → Doctor (P2)
// Emisor (P1 con sensor)
void enviarVitals() {
  String payload = "{\"hr\":85, \"spo2\":98, \"temp\":36.5}";
  client.publish("paciente/123/vitals", payload);
}

// Receptor (P2 - Doctor dashboard)
// Suscrito a "paciente/+/vitals"
void callback(char* topic, byte* payload, unsigned int length) {
  // Parsear JSON y mostrar en dashboard
  StaticJsonDocument<200> doc;
  deserializeJson(doc, payload);

  int hr = doc["hr"];
  displayHeartRate(patientID, hr); // Mostrar en UI
}
```

## Comparativa de Tipos de Conexión

| Aspecto | P2M | M2M | M2P | P2P |
|---------|-----|-----|-----|-----|
| **Iniciativa** | Humano | Automático | Automático | Humanos |
| **Feedback** | Inmediato | Variable | Diferido | Rápido |
| **Confianza** | Alta | Media | Media | Media |
| **Complejidad** | Baja | Media | Media | Alta |
| **Ejemplo IoT** | App → Luz | Sensor → Aire | Sensor → Push | Reloj → Cloud → App |

---

**[← Volver a README](README.md)**
