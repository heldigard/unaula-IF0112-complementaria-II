# Seguridad WiFi

**Clase 7: Conectividad WiFi | Unidad 2**

## Tipos de Seguridad WiFi

| Tipo | Seguridad | Longitud clave | ¿Crackeable? |
|------|------------|----------------|---------------|
| **Open** | Ninguna | - | Sí, trivial |
| **WEP** | WEP | 40/104 bits | Sí, en minutos |
| **WPA** | TKIP | 64-256 bits | Sí, con diccionario |
| **WPA2** | AES | 64-256 bits | Difícil |
| **WPA3** | SAE | 128-256 bits | Muy difícil |

## WPA2-Enterprise vs WPA2-Personal

| Característica | Personal | Enterprise |
|----------------|----------|------------|
| **Autenticación** | PSK (pre-shared key) | 802.1X / RADIUS |
| **Cifrado** | AES-CCMP | AES-CCMP |
| **Uso** | Hogares, pequeñas oficinas | Empresas, instituciones |
| **Manejo de claves** | Contraseña compartida | Certificados digitales |

## Conexión Segura en ESP32

### Conexión Básica (WPA2-Personal)

```cpp
const char* ssid = "TU_SSID";
const char* password = "TU_PASSWORD"; // Mínimo 8 caracteres

WiFi.begin(ssid, password);
```

### Conexión con Certificados (WPA2-Enterprise)

```cpp
#include <WiFi.h>
#include <WiFiClientSecure.h>

// Certificado CA (en formato PEM)
const char* ca_cert = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDxTCCAq2gAwIBAgIQAqxcJmoLQ......\n" \
"-----END CERTIFICATE-----\n";

void setup() {
  WiFi.mode(WIFI_STA);

  // Configurar seguridad Enterprise
  WiFiClientSecure client;
  client.setCACert(ca_cert);

  // Conectar con certificado
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  strcpy(config.ssid, "ENTERPRISE_SSID");

  esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)"user", 0);
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)"user", 0);
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)"password", 0);

  esp_wifi_sta_wpa2_ent_enable();
  WiFi.begin();
}
```

## Mejores Prácticas de Seguridad

1. **Usar siempre WPA2 o superior**
   ```cpp
   // Verificar tipo de encriptación al escanear
   if (WiFi.encryptionType(i) != WIFI_AUTH_OPEN) {
     // Red segura
   }
   ```

2. **No exponer credenciales en el código**
   - Usar secrets.h o configuración externa
   - Nunca subir passwords a GitHub

3. **Usar HTTPS para comunicaciones**
   ```cpp
   #include <WiFiClientSecure.h>
   WiFiClientSecure client;
   client.setCACert(root_ca); // Validar certificado
   ```

4. **Actualizar firmware regularmente**
   - Parches de seguridad
   - Corrección de bugs

5. **Desactivar servicios no usados**
   - AP mode si solo se usa STA
   - Bluetooth si no se usa

---

**[← Volver a README](README.md)**
