# Progress - Clases IoT UNAULA

## Estado Actual (2026-03-01)

### Completado ✅

#### Ejercicios de Simulador Mejorados (2026-03-01)
- ✅ **Ejercicio 08-DHT22**: NUEVO - Creado con diagrama SVG detallado, instrucciones paso a paso, tabla de troubleshooting
  - Conexión de pines VCC, DATA, NC, GND explicada
  - Resistencia pull-up de 10kΩ destacada como OBLIGATORIA
  - Referencias desde ejercicio 07 y hacia ejercicio 09
  - **Commit:** `333f561`

- ✅ **Guía E2**: Agregada sección "Diagrama de Conexión Completo"
  - Tabla detallada con conexiones de DHT22, LDR, LEDs
  - Explicaciones de resistencia pull-up y divisor de voltaje
  - Referencias a ejercicios del simulador para diagramas visuales
  - **Commit:** `d58e567`

- ✅ **Ejercicios 01-07**: Verificados - Tienen diagramas SVG y explicaciones detalladas

#### Clases Revisadas y Corregidas
- ✅ **Clase 05**: Hardware IoT - CORREGIDA Y COMITEADA
  - SVG pinout ESP32 actualizado con ADC1/ADC2, DAC, colores por función
  - Diagrama DHT22+LDR simplificado con instrucciones texto
  - Explicaciones mejoradas de GPIO, ADC, DAC, PWM
  - **Commit:** `75e10ec`

- ✅ **Clases 06-14**: Revisadas y corregidas
  - Clase 6: Ya tenía Prism.js correctamente implementado
  - Clase 7: Prism.js correcto
  - Clase 8: Corregido formato de bloques de código (`<pre><code class="language-cpp">`)
  - Clase 9: Prism.js presente (clase teórica)
  - Clase 10: Agregado Prism.js CSS y JS
  - Clases 11-14: Agregado Prism.js CSS y JS, clase 11 con language-cpp
  - **Commit:** `b779312`

#### Ejercicios de Simulador
- ✅ **Ejercicios 01-16**: Agregado Prism.js para resaltado de sintaxis
  - CSS: prism-tomorrow.min.css
  - JS: prism.min.js + prism-cpp.min.js
  - Clase `language-cpp` agregada a todos los bloques de código
  - Removido color de texto fijo que anulaba los colores de Prism
  - **Commit:** `cd8e52b`

### En Progreso 🔄
- 🔄 **Revisión detallada de conexiones** en ejercicios del simulador
- 🔄 **Revisión de evaluaciones** (guías E1-E6)

### Pendiente 📋
- ⏳ Revisar clases 01-04 (resultados de agentes)
- ⏳ Verificar diagramas en ejercicios 12-16 del simulador
- ⏳ Agregar diagrama SVG completo a ejercicio 11 (ThingSpeak con DHT22+LDR)
- ⏳ Mejorar ejercicio 02 con diagrama SVG (tiene solo ASCII)

### Problemas Resueltos ✅
- ✅ Prism.js ahora funciona correctamente en todos los ejercicios
- ✅ Clases 7-14 tienen Prism.js correctamente implementado

### Problemas Pendientes ⚠️
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
6. ✅ Prism.js para resaltado de sintaxis en todos los ejercicios

### Archivos Modificados
- `clases-html/clase-05.html` a `clase-14.html`
- `ejercicios-simulador/ejercicio-01-led-blink.html` a `ejercicio-16-m2m-simulation.html`
- `ejercicios-simulador/ejercicio-simulador-01.html`
- `assets/diagrams/esp32-pinout.svg`
- `assets/diagrams/dht22-ldr-connections.svg`
- `.memory-bank/progress.md`

### Próximos Pasos
1. Revisar ejercicios del simulador para explicaciones detalladas de conexiones
2. Revisar evaluaciones (guías E1-E6)
3. Resolver problema de push SSH
4. Commit y push de todas las mejoras
