# Progress - Clases IoT UNAULA

## Estado Actual (2026-03-01)

### Clases Revisadas
- ✅ **Clase 05**: Hardware IoT - Corregida
  - SVG pinout ESP32 actualizado con ADC1/ADC2, DAC
  - Diagrama DHT22+LDR simplificado con instrucciones texto
  - Explicaciones mejoradas de GPIO, ADC, DAC, PWM
  - Sensores digitales/analógicos con diferencias
  - LDR definido correctamente

### Pendiente de Revisar
- [ ] Clase 00: Introducción
- [ ] Clase 01: Evolución de Internet
- [ ] Clase 02: 4 Pilares de IoT
- [ ] Clase 02-materiales
- [ ] Clase 03: Arquitectura IoT
- [ ] Clase 04: Redes IoT
- [ ] Clase 06: Programación Arduino
- [ ] Clase 07-14: Por verificar contenido

### Patrones Identificados
- Usar `<abbr>` para acrónimos técnicos
- Incluir explicaciones de "¿Para qué sirve?"
- Diagramas SVG sin código, con instrucciones texto aparte
- Colores consistentes para funciones (ADC1=cyan, ADC2=púrpura, GPIO=azul)

### Correcciones Comunes
1. Resistencia pull-up DHT22 obligatoria (4.7K-10KΩ)
2. ADC2 no funciona con WiFi activo
3. GPIO 34,35,36,39 son solo entrada
4. LDR requiere divisor de voltaje con 10KΩ
