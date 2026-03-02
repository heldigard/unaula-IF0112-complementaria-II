/*
 * SESIÓN 5 - IF0112: IoT UNAULA 2026-I
 * Programa: Sensor de luz con LDR (fotorresistencia)
 * Objetivo: Aprender a leer entradas analógicas
 * 
 * Conexiones LDR (Divisor de voltaje):
 * - LDR (pata 1) -> 3.3V
 * - LDR (pata 2) -> GPIO 34 (ADC) + Resistencia 10K a GND
 * 
 * LED indicador:
 * - LED -> Resistencia 220Ω -> GPIO 2
 * - LED -> GND
 * 
 * Principio: Cuando hay más luz, la resistencia del LDR disminuye
 * y el voltaje en el pin ADC aumenta.
 */

#include "DHT.h"

// Pines
#define DHTPIN 4
#define DHTTYPE DHT22
#define LDR_PIN 34    // GPIO34 - Entrada analógica (ADC)
#define LED_PIN 2     // LED indicador

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(LED_PIN, OUTPUT);
  
  // Configurar resolución del ADC (opcional)
  // ESP32 tiene ADC de 12 bits (0-4095)
  analogReadResolution(12);
  
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 5: DHT22 + LDR");
  Serial.println("================================");
  Serial.println("Cubre el LDR para ver cambios");
  Serial.println("");
  
  delay(2000);
}

void loop() {
  // Leer sensores
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();
  int valorLuz = analogRead(LDR_PIN);  // Valor 0-4095
  
  // Verificar DHT
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error leyendo DHT!");
    return;
  }
  
  // Convertir valor LDR a porcentaje (aproximado)
  // 0 = oscuro, 4095 = muy luminoso
  int porcentajeLuz = map(valorLuz, 0, 4095, 0, 100);
  
  // Determinar nivel de luz
  String nivelLuz;
  if (porcentajeLuz < 20) {
    nivelLuz = "Oscuro";
    digitalWrite(LED_PIN, HIGH);  // Encender LED si está oscuro
  } else if (porcentajeLuz < 60) {
    nivelLuz = "Normal";
    digitalWrite(LED_PIN, LOW);
  } else {
    nivelLuz = "Brillante";
    digitalWrite(LED_PIN, LOW);
  }
  
  // Mostrar datos
  Serial.println("┌──────────────────────────────┐");
  Serial.print("│ Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C           │");
  
  Serial.print("│ Humedad:     ");
  Serial.print(humedad);
  Serial.println(" %            │");
  
  Serial.print("│ Luz:         ");
  Serial.print(valorLuz);
  Serial.print(" (");
  Serial.print(porcentajeLuz);
  Serial.print("%)    │");
  Serial.println("");
  
  Serial.print("│ Nivel:       ");
  Serial.print(nivelLuz);
  Serial.println("           │");
  Serial.println("└──────────────────────────────┘");
  Serial.println("");
  
  delay(3000);
}
