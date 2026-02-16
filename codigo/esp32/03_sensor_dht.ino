/*
 * SESIÓN 5 - IF0112: IoT UNAULA 2026-I
 * Programa: Lectura de temperatura y humedad con DHT22
 * Objetivo: Aprender a usar sensores digitales
 * 
 * INSTALACION DE LIBRERIA:
 * 1. Ir a Sketch -> Include Library -> Manage Libraries
 * 2. Buscar "DHT sensor library" by Adafruit
 * 3. Instalar (también instalará Adafruit Unified Sensor)
 * 
 * Conexiones DHT22:
 * - Pin 1 (VCC)  -> 3.3V o 5V
 * - Pin 2 (DATA) -> GPIO 4 + Resistencia 10K a VCC (pull-up)
 * - Pin 3 (NC)   -> No conectar
 * - Pin 4 (GND)  -> GND
 * 
 * NOTA: Algunos módulos DHT22 ya traen la resistencia pull-up incluida
 */

#include "DHT.h"

// Configuración del sensor
#define DHTPIN 4        // Pin donde está conectado el DHT22
#define DHTTYPE DHT22   // Tipo de sensor (DHT22 o DHT11)

// Crear objeto DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializar serial
  Serial.begin(115200);
  
  // Inicializar sensor DHT
  dht.begin();
  
  Serial.println("================================");
  Serial.println("  UNAULA - IF0112 - IoT 2026-I");
  Serial.println("  Sesión 5: Sensor DHT22");
  Serial.println("================================");
  Serial.println("Iniciando sensor...");
  Serial.println("");
  
  // Esperar un momento para que el sensor se estabilice
  delay(2000);
}

void loop() {
  // Leer temperatura y humedad
  float temperatura = dht.readTemperature();  // En grados Celsius
  float humedad = dht.readHumidity();          // En porcentaje
  
  // Verificar si las lecturas son válidas
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("ERROR: No se pudo leer el sensor DHT!");
    Serial.println("Verifica las conexiones...");
    delay(2000);
    return;
  }
  
  // Calcular sensación térmica (heat index)
  float sensacionTermica = dht.computeHeatIndex(temperatura, humedad, false);
  
  // Mostrar datos en el monitor serial con formato
  Serial.println("┌──────────────────────────────┐");
  Serial.print("│ Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C           │");
  
  Serial.print("│ Humedad:     ");
  Serial.print(humedad);
  Serial.println(" %            │");
  
  Serial.print("│ Sensacion:   ");
  Serial.print(sensacionTermica);
  Serial.println(" °C           │");
  Serial.println("└──────────────────────────────┘");
  Serial.println("");
  
  // El DHT22 necesita al menos 2 segundos entre lecturas
  delay(3000);
}
