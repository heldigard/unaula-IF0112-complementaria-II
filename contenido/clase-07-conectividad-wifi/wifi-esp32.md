# WiFi en ESP32 - Detalle

**Clase 7: Conectividad WiFi | Unidad 2**

## Modos de Operación WiFi

### Modo STA (Station)

El ESP32 se conecta a un router existente.

```cpp
#include <WiFi.h>

const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD";

void setup() {
  Serial.begin(115200);

  // Modo STA
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  Serial.print("RSSI: ");
  Serial.println(WiFi.RSSI()); // Señal en dBm
}

void loop() {
  // Reconexión automática si se pierde
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Reconectando...");
    WiFi.reconnect();
  }
  delay(10000);
}
```

### Modo AP (Access Point)

El ESP32 crea su propia red WiFi.

```cpp
#include <WiFi.h>

const char* apSSID = "ESP32-AP";
const char* apPassword = "12345678";

void setup() {
  Serial.begin(115200);

  // Configurar AP
  WiFi.softAP(apSSID, apPassword);
  // O sin contraseña: WiFi.softAP(apSSID);

  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  // Mostrar dispositivos conectados
  Serial.print("AP MAC: ");
  Serial.println(WiFi.softAPmacAddress());
}

void loop() {
  Serial.print("Dispositivos conectados: ");
  Serial.println(WiFi.softAPgetStationNum());
  delay(5000);
}
```

### Modo AP + STA (Simultáneo)

```cpp
WiFi.mode(WIFI_AP_STA);

// Configurar STA
WiFi.begin(ssid, password);

// Configurar AP
WiFi.softAP(apSSID, apPassword);
```

## Escaneo de Redes WiFi

```cpp
#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
}

void loop() {
  Serial.println("Escaneando redes...");

  int n = WiFi.scanNetworks();
  Serial.println("Escaneo completo!");

  if (n == 0) {
    Serial.println("No se encontraron redes");
  } else {
    Serial.print(n);
    Serial.println(" redes encontradas:");

    for (int i = 0; i < n; ++i) {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print("dBm)");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }

  Serial.println("");
  delay(5000);
}
```

## WiFi Events

```cpp
#include <WiFi.h>

WiFiEventId_t eventID;

void WiFiEvent(WiFiEvent_t event, WiFiEventInfo_t info) {
  switch (event) {
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.println("Conectado al AP");
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("Desconectado del AP");
      break;
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.print("IP obtenida: ");
      Serial.println(IPAddress(info.got_ip.ip_info.ip.addr));
      break;
  }
}

void setup() {
  Serial.begin(115200);

  // Registrar callback de eventos
  eventID = WiFi.onEvent(WiFiEvent);

  WiFi.begin(ssid, password);
}

void loop() {
  delay(100);
}
```

## WiFi Multi (Para APs redundantes)

```cpp
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

void setup() {
  Serial.begin(115200);

  // Agregar múltiples APs (prioridad por orden)
  wifiMulti.addAP("AP_Principal", "pass1");
  wifiMulti.addAP("AP_Secundario", "pass2");
  wifiMulti.addAP("AP_Backup", "pass3");
}

void loop() {
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("No conectado a ningún AP");
    delay(1000);
    return;
  }

  Serial.println("Conectado a: " + WiFi.SSID());
  delay(10000);
}
```

---

**[← Volver a README](README.md)**
