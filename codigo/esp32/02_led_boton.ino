/*
 * SESIÓN 3 - IF0112: IoT UNAULA 2026-I
 * Programa: LED controlado por botón
 * Objetivo: Aprender entradas digitales y control básico
 * 
 * Conexiones:
 * - LED externo: Anodo (pata larga) -> Resistencia 220Ω -> GPIO 2
 * - LED externo: Catodo (pata corta) -> GND
 * - Botón: Un lado -> GPIO 4
 * - Botón: Otro lado -> GND
 * - NOTA: Usamos INPUT_PULLUP, no necesita resistencia externa
 */

// Definición de pines
const int PIN_LED = 2;
const int PIN_BOTON = 4;

void setup() {
  // Inicializar serial
  Serial.begin(115200);
  
  // Configurar LED como salida
  pinMode(PIN_LED, OUTPUT);
  
  // Configurar botón como entrada con pull-up interno
  // INPUT_PULLUP: El pin está en HIGH por defecto, LOW cuando se presiona
  pinMode(PIN_BOTON, INPUT_PULLUP);
  
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 3: LED + Boton");
  Serial.println("================================");
  Serial.println("Presiona el boton para encender el LED");
  Serial.println("");
}

void loop() {
  // Leer estado del botón
  // LOW = botón presionado (por el pull-up)
  // HIGH = botón suelto
  int estadoBoton = digitalRead(PIN_BOTON);
  
  if (estadoBoton == LOW) {
    // Botón presionado - Encender LED
    digitalWrite(PIN_LED, HIGH);
    Serial.println("Boton PRESIONADO -> LED ENCENDIDO");
  } else {
    // Botón suelto - Apagar LED
    digitalWrite(PIN_LED, LOW);
    Serial.println("Boton suelto -> LED apagado");
  }
  
  // Pequeña espera para estabilidad
  delay(100);
}
