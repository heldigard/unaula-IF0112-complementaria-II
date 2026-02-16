/*
 * SESIÓN 3 - IF0112: IoT UNAULA 2026-I
 * Programa: Blink LED - Primer programa ESP32
 * Objetivo: Verificar instalación y hacer parpadear el LED integrado
 * 
 * Conexiones:
 * - No requiere conexiones externas (usa LED integrado en GPIO 2)
 */

// Definición del pin del LED integrado
const int LED = 2;

void setup() {
  // Inicializar comunicación serial para ver mensajes
  Serial.begin(115200);
  
  // Configurar el pin del LED como salida
  pinMode(LED, OUTPUT);
  
  // Mensaje de bienvenida
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 3: Primer programa");
  Serial.println("================================");
  Serial.println("");
  Serial.println("El LED deberia parpadear cada segundo");
  Serial.println("");
}

void loop() {
  // Encender LED
  digitalWrite(LED, HIGH);
  Serial.println("LED: ENCENDIDO ✓");
  
  // Esperar 1 segundo
  delay(1000);
  
  // Apagar LED
  digitalWrite(LED, LOW);
  Serial.println("LED: APAGADO ✗");
  
  // Esperar 1 segundo
  delay(1000);
}
