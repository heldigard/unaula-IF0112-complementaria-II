# Servidor IoT - IF0112 Complementaria II

Servidor completo para recibir y visualizar datos de los ESP32 de los estudiantes.

---

## 📋 Componentes

| Servicio | Puerto | Descripción |
|----------|--------|-------------|
| **PostgreSQL** | 5432 | Base de datos para almacenar lecturas |
| **API Flask** | 5000 | Servidor REST para recibir datos de ESP32 |
| **Grafana** | 3000 | Dashboard para visualizar datos |

---

## 🚀 Instalación Rápida (5 minutos)

### Requisitos Previos

- Docker Desktop instalado y corriendo
- 8GB de RAM mínimo
- Windows 10/11, macOS, o Linux

### Pasos de Instalación

#### 1. Verificar Docker

```bash
docker --version
docker-compose --version
```

Si Docker no está instalado, descargar de [docker.com](https://www.docker.com/products/docker-desktop)

#### 2. Descargar Archivos

Asegúrate de tener esta carpeta completa con:
- `docker-compose.yml`
- `init.sql`
- `api/` (con Dockerfile, app.py, requirements.txt)
- `grafana/` (con configuraciones)

#### 3. Iniciar Servidores

```bash
# Abrir terminal en esta carpeta
cd F:\UNAULA\IF0112-complementaria-II\codigo\servidor

# Iniciar todos los servicios
docker-compose up -d

# Verificar que estén corriendo
docker-compose ps
```

#### 4. Verificar Funcionamiento

```bash
# Ver logs de la API
docker-compose logs -f api

# Probar health check
curl http://localhost:5000/health
```

Debería ver:
```json
{
  "status": "healthy",
  "service": "iot-api",
  "database": "connected"
}
```

---

## 🔧 Configuración de Red

### Opción A: Hotspot WiFi (Recomendado para Laboratorios)

1. **En Windows:**
   - Configuración > Red e Internet > Zona móvil
   - Activar "Compartir mi conexión a Internet"
   - Nombre de red: `UNAULA_IOT_LAB`
   - Contraseña de red: `iot2026unaula`

2. **Obtener IP del servidor:**
   ```bash
   ipconfig
   # Buscar "IPv4" en "Adaptador de Wi-Fi"
   # Ejemplo: 192.168.137.1
   ```

3. **Usar esta IP en los ESP32:**
   ```cpp
   const char* serverUrl = "http://192.168.137.1:5000/api/v1/datos";
   ```

### Opción B: Red del Aula/Universidad

- Usar el WiFi de la universidad
- Todos deben estar en la misma red
- Anotar la IP del servidor

---

## 📊 Uso de Grafana

### Acceso

1. Abrir navegador: http://localhost:3000
2. Usuario: `admin`
3. Contraseña: `unaula2026`

### Configurar DataSource PostgreSQL

1. Settings (⚙️) > Data sources > Add data source
2. Seleccionar PostgreSQL
3. Configurar:
   - Host: `postgres:5432`
   - Database: `iot_unaula`
   - User: `unaula`
   - Password: `unaula2026`
   - SSL mode: Disable
4. Click "Save & Test"

### Importar Dashboard

1. Dashboards (➕) > Import
2. Pegar el JSON del dashboard o subir archivo
3. Seleccionar DataSource PostgreSQL
4. Click "Import"

---

## 🛠️ Comandos Útiles

```bash
# Iniciar servicios
docker-compose up -d

# Ver logs en tiempo real
docker-compose logs -f

# Ver logs de servicio específico
docker-compose logs -f api
docker-compose logs -f postgres
docker-compose logs -f grafana

# Detener servicios
docker-compose down

# Reiniciar un servicio
docker-compose restart api

# Eliminar todo (incluyendo datos)
docker-compose down -v

# Verificar contenedores corriendo
docker ps

# Entrar a un contenedor (debugging)
docker exec -it iot-api bash
docker exec -it iot-postgres psql -U unaula -d iot_unaula
```

---

## 📡 API Endpoints

### Dispositivos

| Método | Endpoint | Descripción |
|--------|----------|-------------|
| GET | `/api/v1/dispositivos` | Listar todos los dispositivos |
| POST | `/api/v1/dispositivos` | Registrar nuevo dispositivo |
| GET | `/api/v1/dispositivos/{id}` | Obtener dispositivo específico |

### Datos de Sensores

| Método | Endpoint | Descripción |
|--------|----------|-------------|
| POST | `/api/v1/datos` | Recibir datos de ESP32 |
| GET | `/api/v1/datos?dispositivo_id=X` | Obtener datos con filtros |
| GET | `/api/v1/datos/{id}/ultimas?limit=N` | Últimas N lecturas |
| GET | `/api/v1/datos/{id}/promedio?horas=24` | Promedios en rango |

### Reportes

| Método | Endpoint | Descripción |
|--------|----------|-------------|
| GET | `/api/v1/reportes/resumen` | Resumen general del sistema |

### Salud

| Método | Endpoint | Descripción |
|--------|----------|-------------|
| GET | `/health` | Verificar estado del servidor |

---

## 🧪 Testing de la API

### Con cURL

```bash
# Health check
curl http://localhost:5000/health

# Registrar dispositivo
curl -X POST http://localhost:5000/api/v1/dispositivos \
  -H "Content-Type: application/json" \
  -d '{"dispositivo_id":"esp32_test","nombre":"ESP32 de Prueba"}'

# Enviar datos
curl -X POST http://localhost:5000/api/v1/datos \
  -H "Content-Type: application/json" \
  -d '{"dispositivo_id":"esp32_test","temperatura":25.5,"humedad":65.0,"luz":2000}'

# Obtener últimos datos
curl http://localhost:5000/api/v1/datos?dispositivo_id=esp32_test&limit=10

# Resumen del sistema
curl http://localhost:5000/api/v1/reportes/resumen
```

### Con Python

```python
import requests

# Enviar datos
data = {
    "dispositivo_id": "esp32_01",
    "temperatura": 24.5,
    "humedad": 60.0,
    "luz": 1500
}

response = requests.post(
    "http://localhost:5000/api/v1/datos",
    json=data
)
print(response.json())
```

---

## 🔍 Troubleshooting

### "Port 5000 already in use"

**Problema:** Otro programa usa el puerto 5000

**Solución:**
```bash
# En Windows: encontrar el proceso
netstat -ano | findstr :5000

# Terminar el proceso (reemplazar PID)
taskkill /PID <PID> /F
```

### "Cannot connect to PostgreSQL"

**Problema:** PostgreSQL no está listo

**Solución:**
```bash
# Verificar contenedor
docker-compose ps postgres

# Ver logs
docker-compose logs postgres

# Reiniciar
docker-compose restart postgres
```

### "ESP32 no puede conectar al servidor"

**Problemas posibles:**
1. No están en la misma red WiFi
2. Firewall bloqueando conexiones
3. IP incorrecta en el código

**Soluciones:**
```bash
# 1. Verificar IP del servidor
ipconfig  # Windows
ifconfig  # macOS/Linux

# 2. Desactivar firewall temporalmente (Windows)
# Configuración > Actualización y Seguridad > Seguridad de Windows > Firewall

# 3. Permitir puerto en firewall
netsh advfirewall firewall add rule name="IoT API" dir=in action=allow protocol=TCP localport=5000
```

### "Grafana no puede conectar a PostgreSQL"

**Solución:**
1. Verificar que PostgreSQL esté corriendo
2. Configurar DataSource en Grafana:
   - Host: `postgres:5432` (no localhost)
   - Database: `iot_unaula`
   - User: `unaula`
   - Password: `unaula2026`

---

## 📝 Consultas SQL Útiles

```sql
-- Conectar a la base de datos
docker exec -it iot-postgres psql -U unaula -d iot_unaula

-- Ver todos los dispositivos
SELECT * FROM dispositivos;

-- Ver últimas 10 lecturas
SELECT * FROM datos_sensores ORDER BY timestamp DESC LIMIT 10;

-- Ver promedios por dispositivo (últimas 24h)
SELECT
    dispositivo_id,
    AVG(temperatura) as temp_prom,
    AVG(humedad) as hum_prom,
    COUNT(*) as num_lecturas
FROM datos_sensores
WHERE timestamp >= NOW() - INTERVAL '24 hours'
GROUP BY dispositivo_id;

-- Dispositivos que han enviado datos hoy
SELECT DISTINCT dispositivo_id
FROM datos_sensores
WHERE DATE(timestamp) = CURRENT_DATE;
```

---

## 🔄 Backup y Restore

### Backup de Base de Datos

```bash
# Crear backup
docker exec iot-postgres pg_dump -U unaula iot_unaula > backup_$(date +%Y%m%d).sql

# Restaurar backup
docker exec -i iot-postgres psql -U unaula iot_unaula < backup_20260201.sql
```

---

## 📚 Recursos Adicionales

- [Documentación PostgreSQL](https://www.postgresql.org/docs/)
- [Documentación Flask](https://flask.palletsprojects.com/)
- [Documentación Grafana](https://grafana.com/docs/)

---

## 📞 Soporte

Si tienes problemas:
1. Revisar logs: `docker-compose logs`
2. Verificar contenedores: `docker-compose ps`
3. Consultar a docente en grupo de WhatsApp

---

**Autor:** Docente IF0112
**Fecha:** Febrero 2026
**Versión:** 1.0
