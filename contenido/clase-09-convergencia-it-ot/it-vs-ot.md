# IT vs OT - Convergencia

**Clase 9: Convergencia IT-OT | Unidad 2**

## Definiciones

### IT (Information Technology)

- **Enfoque:** Datos, software, redes corporativas
- **Responsable:** CIO, departamento de sistemas
- **Prioridad:** Confidencialidad, integridad de datos
- **Tecnologías:** Servidores, bases de datos, ERP, CRM
- **Cultura:** Iterativa, ágil, innovación constante

### OT (Operational Technology)

- **Enfoque:** Control físico, maquinaria, procesos
- **Responsible:** Director de operaciones, ingeniería
- **Prioridad:** Seguridad, continuidad, producción
- **Tecnologías:** PLC, SCADA, DCS, sensores industriales
- **Cultura:** Estable, probada, "si funciona, no lo cambies"

## Historia de Separación

```
1980-2000: Mundos separados
┌─────────────┐          ┌─────────────┐
│     IT      │          │     OT      │
│  (Oficina)  │          │ (Planta)    │
│  Servidores  │          │   PLCs      │
│  ERP, CRM   │   <--->   │   SCADA     │
│  Red office │          │  Red planta │
└─────────────┘          └─────────────┘
     Manual                     Aislada
```

## Convergencia IT-OT con IoT

```
2000-Hoy: Convergencia con IoT
┌─────────────────────────────────────┐
│         CONVERGENCIA IT-OT          │
│                                     │
│  IT + OT = IIoT (Industrial IoT)    │
│                                     │
│  ┌──────────┐      ┌──────────┐     │
│  │ Cloud    │<────>│  Edge    │     │
│  │ (ERP)    │  MQTT│ Gateway  │     │
│  └──────────┘      └────┬─────┘     │
│                          │           │
│                     ┌────┴─────┐     │
│                     │ Sensores │     │
│                     │ Actuad.  │     │
│                     └──────────┘     │
└─────────────────────────────────────┘
```

## Desafíos de la Convergencia

### Desafíos Técnicos

| Desafío | IT | OT | Solución |
|---------|----|----|----------|
| **Protocolos** | TCP/IP | Modbus, Profibus | Gateways |
| **Latencia** | Segundos aceptables | Milisegundos críticos | Edge computing |
| **Ciclos actualización** | Semanal | Diario | Cloud sync |
| **Seguridad** | Firewalls, VPN | Aislada fisicamente | DMZ industrial |

### Desafíos Culturales

| Aspecto | IT | OT | Fricción |
|---------|----|----|----------|
| **Cambio** | Ágil, rápido | Conservador | "¿Por qué cambiar?" |
| **Riesgo** | Data loss | Safety | "¿Podemos parar producción?" |
| **Responsabilidad** | SLAinterno | Uptime crítico | ¿Quién paga cuando falla? |
| **Lenguaje** | "Nube", "API" | "PLC", "ladder" | Barrera comunicacional |

## Arquitectura de Convergencia

### Niveles de la Pirámide ISA-95

```
┌─────────────────────────────────────────────────┐
│  Nivel 4: Negocio (ERP, CRM)         <-- IT     │
├─────────────────────────────────────────────────┤
│  Nivel 3: Operaciones (MES, Historian)  <-- Convergencia │
├─────────────────────────────────────────────────┤
│  Nivel 2: Control (SCADA, HMI)        <-- OT     │
├─────────────────────────────────────────────────┤
│  Nivel 1: Proceso (Sensores, PLC)      <-- OT     │
├─────────────────────────────────────────────────┤
│  Nivel 0: Físico (Máquinas, actuadores) <-- OT   │
└─────────────────────────────────────────────────┘
```

### Bridging IT y OT

```cpp
// Edge Gateway que conecta OT con IT
// Lee del PLC (OT) y publica a cloud (IT)

#include <ModbusMaster.h>
#include <PubSubClient.h>

ModbusMaster node;
PubSubClient mqttClient;

void setup() {
  // Configurar Modbus (OT)
  node.begin(1, Serial); // RTU sobre Serial

  // Configurar MQTT (IT)
  WiFi.begin(ssid, password);
  mqttClient.setServer mqtt_server, 1883);
}

void loop() {
  // Leer del PLC (holding register 0)
  uint8_t result = node.readHoldingRegisters(0, 1);

  if (result == node.ku8MBSuccess) {
    float valor = node.getResponseBuffer(0) / 10.0;

    // Publicar al cloud (IT)
    char msg[20];
    dtostrf(valor, 2, 1, msg);
    mqttClient.publish("planta/maquina1/temp", msg);
  }

  mqttClient.loop();
  delay(5000);
}
```

---

**[← Volver a README](README.md)**
