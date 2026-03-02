# Progress - Clases IoT UNAULA

## Estado Actual (2026-03-01)

### Clases Revisadas y Corregidas
- ✅ **Clase 05**: Hardware IoT - CORREGIDA Y COMITEADA
  - SVG pinout ESP32 actualizado con ADC1/ADC2, DAC, colores por función
  - Diagrama DHT22+LDR simplificado con instrucciones texto
  - Explicaciones mejoradas de GPIO, ADC, DAC, PWM
  - Sensores digitales/analógicos con diferencias
  - LDR definido con `<abbr>` y explicar divisor de voltaje
  - **Commit:** `75e10ec`

### Pendiente de Revisar (Agentes en progreso)
- ⏳ Clase 01: Evolución de Internet (agente corriendo)
- ⏳ Clase 02: 4 Pilares de IoT (agente corriendo)
- ⏳ Clase 03: Arquitectura IoT (agente corriendo)
- ⏳ Clase 04: Redes IoT (agente corriendo)
- ⏳ Clase 06: Programación Arduino (agente corriendo)
- ⏳ Clases 07-14: (agente corriendo)

### Problemas Pendientes
- ⚠️ **Push falló**: Permisos SSH denegados para git@github.com
  - Solución: Verificar SSH key o usar HTTPS

### Patrones Identificados
- Usar `<abbr>` para acrónimos técnicos
- Incluir explicaciones de "¿Para qué sirve?"
- Diagramas SVG sin código, con instrucciones texto aparte
- Colores consistentes para funciones:
  - ADC1 (WiFi OK): Cyan (#06b6d4)
  - ADC2 (No WiFi): Púrpura (#a855f7)
  - DAC: Violeta (#8b5cf6)
  - GPIO: Azul (#3b82f6)
  - SPI: Rojo (#ef4444)
  - I2C: Verde (#10b981)
  - Boot/Reset: Amarillo (#f59e0b)

### Correcciones Comunes Aplicadas
1. ✅ Resistencia pull-up DHT22 obligatoria (4.7K-10KΩ)
2. ✅ ADC2 no funciona con WiFi activo
3. ✅ GPIO 34,35,36,39 son solo entrada
4. ✅ LDR requiere divisor de voltaje con 10KΩ
5. ✅ Instrucciones de conexión en texto antes del diagrama

### Archivos Modificados
- `clases-html/clase-05.html`
- `assets/diagrams/esp32-pinout.svg`
- `assets/diagrams/dht22-ldr-connections.svg`
- `.memory-bank/progress.md` (nuevo)

### Próximos Pasos
1. Resolver problema de push SSH
2. Revisar resultados de agentes
3. Aplicar correcciones a otras clases
4. Commit y push de todas las mejoras
