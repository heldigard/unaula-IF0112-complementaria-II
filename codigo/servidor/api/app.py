"""
API Flask para Servidor IoT UNAULA
IF0112 - Complementaria II - 2026-I

Esta API recibe datos de los ESP32 de los estudiantes y los almacena
en PostgreSQL. También expone endpoints para consultar datos y
generar reportes.

Autor: Docente IF0112
Fecha: Febrero 2026
"""

import os
import logging
from datetime import datetime, timedelta
from typing import Dict, List, Optional

from flask import Flask, request, jsonify
from flask_cors import CORS
import psycopg2
from psycopg2.extras import RealDictCursor, RealDictRow
from psycopg2.pool import SimpleConnectionPool
from dotenv import load_dotenv

# Cargar variables de entorno
load_dotenv()

# Configurar logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    handlers=[
        logging.StreamHandler(),
        logging.FileHandler('api.log')
    ]
)
logger = logging.getLogger(__name__)

# ========================================
# CONFIGURACIÓN
# ========================================

DB_URL = os.getenv('DATABASE_URL', 'postgresql://unaula:unaula2026@postgres:5432/iot_unaula')

# Pool de conexiones a PostgreSQL
try:
    connection_pool = SimpleConnectionPool(
        minconn=1,
        maxconn=10,
        dsn=DB_URL
    )
    logger.info("✓ Pool de conexiones creado exitosamente")
except Exception as e:
    logger.error(f"✗ Error creando pool de conexiones: {e}")
    raise

# ========================================
# APLICACIÓN FLASK
# ========================================

app = Flask(__name__)
CORS(app)  # Habilitar CORS para todas las rutas

# ========================================
# UTILIDADES DE BASE DE DATOS
# ========================================

def get_db_connection():
    """Obtiene una conexión del pool"""
    return connection_pool.getconn()

def release_db_connection(conn):
    """Devuelve una conexión al pool"""
    connection_pool.putconn(conn)

def execute_query(query: str, params: tuple = None, fetch: bool = True) -> List[Dict]:
    """
    Ejecuta una consulta SQL y devuelve los resultados

    Args:
        query: Consulta SQL con placeholders %s
        params: Tupla de parámetros
        fetch: Si True, devuelve resultados. Si False, solo ejecuta

    Returns:
        Lista de diccionarios con los resultados
    """
    conn = get_db_connection()
    try:
        with conn.cursor(cursor_factory=RealDictCursor) as cursor:
            cursor.execute(query, params or ())
            if fetch:
                result = cursor.fetchall()
                return [dict(row) for row in result]
            else:
                conn.commit()
                return []
    except Exception as e:
        conn.rollback()
        logger.error(f"Error en consulta: {e}")
        raise
    finally:
        release_db_connection(conn)

# ========================================
# ENDPOINTS DE DISPOSITIVOS
# ========================================

@app.route('/api/v1/dispositivos', methods=['GET'])
def get_dispositivos():
    """
    GET /api/v1/dispositivos

    Obtiene lista de todos los dispositivos registrados

    Query params:
        - activo: filter by active status (true/false)
    """
    try:
        activo = request.args.get('activo')
        query = "SELECT * FROM dispositivos"
        params = []

        if activo is not None:
            query += " WHERE activo = %s"
            params.append(activo.lower() == 'true')

        query += " ORDER BY fecha_registro DESC"

        dispositivos = execute_query(query, tuple(params))
        return jsonify({
            'status': 'success',
            'count': len(dispositivos),
            'data': dispositivos
        }), 200
    except Exception as e:
        logger.error(f"Error obteniendo dispositivos: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


@app.route('/api/v1/dispositivos', methods=['POST'])
def registrar_dispositivo():
    """
    POST /api/v1/dispositivos

    Registra un nuevo dispositivo

    Body:
        - dispositivo_id: ID único del ESP32 (ej: esp32_01)
        - nombre: Nombre del dispositivo
        - estudiante: Nombre del estudiante
        - ubicacion: Ubicación del dispositivo
    """
    try:
        data = request.get_json()

        # Validar datos requeridos
        if not data or 'dispositivo_id' not in data:
            return jsonify({'status': 'error', 'message': 'dispositivo_id es requerido'}), 400

        query = """
        INSERT INTO dispositivos (dispositivo_id, nombre, estudiante, ubicacion)
        VALUES (%s, %s, %s, %s)
        ON CONFLICT (dispositivo_id) DO UPDATE
        SET nombre = COALESCE(EXCLUDED.nombre, dispositivos.nombre),
            estudiante = COALESCE(EXCLUDED.estudiante, dispositivos.estudiante),
            ubicacion = COALESCE(EXCLUDED.ubicacion, dispositivos.ubicacion)
        RETURNING *
        """

        params = (
            data['dispositivo_id'],
            data.get('nombre'),
            data.get('estudiante'),
            data.get('ubicacion')
        )

        result = execute_query(query, params)

        logger.info(f"Dispositivo registrado/actualizado: {data['dispositivo_id']}")
        return jsonify({
            'status': 'success',
            'message': 'Dispositivo registrado exitosamente',
            'data': result[0] if result else None
        }), 201

    except Exception as e:
        logger.error(f"Error registrando dispositivo: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


@app.route('/api/v1/dispositivos/<dispositivo_id>', methods=['GET'])
def get_dispositivo(dispositivo_id: str):
    """Obtiene información de un dispositivo específico"""
    try:
        query = "SELECT * FROM dispositivos WHERE dispositivo_id = %s"
        result = execute_query(query, (dispositivo_id,))

        if not result:
            return jsonify({'status': 'error', 'message': 'Dispositivo no encontrado'}), 404

        return jsonify({'status': 'success', 'data': result[0]}), 200

    except Exception as e:
        logger.error(f"Error obteniendo dispositivo: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500

# ========================================
# ENDPOINTS DE DATOS DE SENSORES
# ========================================

@app.route('/api/v1/datos', methods=['POST'])
def recibir_datos():
    """
    POST /api/v1/datos

    Recibe datos de sensores de un ESP32

    Body:
        - dispositivo_id: ID del dispositivo
        - temperatura: Temperatura en °C
        - humedad: Humedad relativa en %
        - luz: Nivel de luz (0-4095)
    """
    try:
        data = request.get_json()

        # Validar datos requeridos
        required_fields = ['dispositivo_id', 'temperatura', 'humedad', 'luz']
        missing = [field for field in required_fields if field not in data]

        if missing:
            return jsonify({
                'status': 'error',
                'message': f'Campos faltantes: {", ".join(missing)}'
            }), 400

        # Validar rangos
        try:
            temp = float(data['temperatura'])
            hum = float(data['humedad'])
            luz = int(data['luz'])

            if not (-20 <= temp <= 60):
                return jsonify({'status': 'error', 'message': 'Temperatura fuera de rango válido'}), 400
            if not (0 <= hum <= 100):
                return jsonify({'status': 'error', 'message': 'Humedad fuera de rango válido'}), 400
            if not (0 <= luz <= 4095):
                return jsonify({'status': 'error', 'message': 'Luz fuera de rango válido'}), 400

        except (ValueError, TypeError):
            return jsonify({'status': 'error', 'message': 'Tipos de datos inválidos'}), 400

        # Insertar datos
        query = """
        INSERT INTO datos_sensores (dispositivo_id, temperatura, humedad, luz)
        VALUES (%s, %s, %s, %s)
        RETURNING *
        """

        params = (data['dispositivo_id'], temp, hum, luz)
        result = execute_query(query, params)

        logger.info(f"Datos recibidos de {data['dispositivo_id']}: T={temp}°C, H={hum}%, L={luz}")

        return jsonify({
            'status': 'success',
            'message': 'Datos recibidos exitosamente',
            'data': result[0]
        }), 201

    except Exception as e:
        logger.error(f"Error recibiendo datos: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


@app.route('/api/v1/datos', methods=['GET'])
def get_datos():
    """
    GET /api/v1/datos

    Obtiene datos de sensores con filtros opcionales

    Query params:
        - dispositivo_id: Filtrar por dispositivo
        - desde: Fecha inicio (ISO 8601)
        - hasta: Fecha fin (ISO 8601)
        - limit: Número máximo de registros (default: 100)
    """
    try:
        dispositivo_id = request.args.get('dispositivo_id')
        desde = request.args.get('desde')
        hasta = request.args.get('hasta')
        limit = min(int(request.args.get('limit', 100)), 1000)

        query = "SELECT * FROM datos_sensores WHERE 1=1"
        params = []

        if dispositivo_id:
            query += " AND dispositivo_id = %s"
            params.append(dispositivo_id)

        if desde:
            query += " AND timestamp >= %s"
            params.append(desde)

        if hasta:
            query += " AND timestamp <= %s"
            params.append(hasta)

        query += " ORDER BY timestamp DESC LIMIT %s"
        params.append(limit)

        datos = execute_query(query, tuple(params))

        return jsonify({
            'status': 'success',
            'count': len(datos),
            'data': datos
        }), 200

    except Exception as e:
        logger.error(f"Error obteniendo datos: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


@app.route('/api/v1/datos/<dispositivo_id>/ultimas', methods=['GET'])
def get_ultimas_lecturas(dispositivo_id: str):
    """Obtiene las últimas N lecturas de un dispositivo"""
    try:
        limit = min(int(request.args.get('limit', 10)), 100)

        query = """
        SELECT * FROM datos_sensores
        WHERE dispositivo_id = %s
        ORDER BY timestamp DESC
        LIMIT %s
        """

        datos = execute_query(query, (dispositivo_id, limit))

        return jsonify({
            'status': 'success',
            'count': len(datos),
            'data': datos
        }), 200

    except Exception as e:
        logger.error(f"Error obteniendo últimas lecturas: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


@app.route('/api/v1/datos/<dispositivo_id>/promedio', methods=['GET'])
def get_promedio(dispositivo_id: str):
    """
    Obtiene promedios de un dispositivo en un rango de tiempo

    Query params:
        - horas: Número de horas hacia atrás (default: 24)
    """
    try:
        horas = int(request.args.get('horas', 24))

        query = """
        SELECT
            COUNT(*) as cantidad,
            AVG(temperatura) as temp_promedio,
            MIN(temperatura) as temp_minima,
            MAX(temperatura) as temp_maxima,
            AVG(humedad) as humedad_promedio,
            MIN(humedad) as humedad_minima,
            MAX(humedad) as humedad_maxima,
            AVG(luz) as luz_promedio
        FROM datos_sensores
        WHERE dispositivo_id = %s
            AND timestamp >= NOW() - INTERVAL '%s hours'
        """

        result = execute_query(query, (dispositivo_id, horas))

        if result and result[0]['cantidad'] > 0:
            return jsonify({'status': 'success', 'data': result[0]}), 200
        else:
            return jsonify({'status': 'error', 'message': 'No hay datos en el rango especificado'}), 404

    except Exception as e:
        logger.error(f"Error obteniendo promedio: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500

# ========================================
# ENDPOINTS DE REPORTES
# ========================================

@app.route('/api/v1/reportes/resumen', methods=['GET'])
def get_resumen():
    """
    Obtiene un resumen general del sistema

    Incluye:
        - Total de dispositivos activos
        - Total de lecturas
        - Últimas 24 horas de actividad
    """
    try:
        # Dispositivos activos
        query_activos = "SELECT COUNT(*) as count FROM dispositivos WHERE activo = true"
        activos = execute_query(query_activos)[0]['count']

        # Total de lecturas
        query_total = "SELECT COUNT(*) as count FROM datos_sensores"
        total = execute_query(query_total)[0]['count']

        # Dispositivos con datos en las últimas 24h
        query_ultimas_24h = """
        SELECT COUNT(DISTINCT dispositivo_id) as count
        FROM datos_sensores
        WHERE timestamp >= NOW() - INTERVAL '24 hours'
        """
        ultimas_24h = execute_query(query_ultimas_24h)[0]['count']

        # Última lectura de cada dispositivo
        query_ultimas = """
        SELECT d.dispositivo_id, d.nombre, d.estudiante,
               ds.temperatura, ds.humedad, ds.luz, ds.timestamp
        FROM dispositivos d
        LEFT JOIN LATERAL (
            SELECT temperatura, humedad, luz, timestamp
            FROM datos_sensores
            WHERE dispositivo_id = d.dispositivo_id
            ORDER BY timestamp DESC
            LIMIT 1
        ) ds ON true
        WHERE d.activo = true
        ORDER BY d.dispositivo_id
        """
        ultimas = execute_query(query_ultimas)

        return jsonify({
            'status': 'success',
            'data': {
                'dispositivos_activos': activos,
                'total_lecturas': total,
                'activos_ultimas_24h': ultimas_24h,
                'ultimas_lecturas': ultimas
            }
        }), 200

    except Exception as e:
        logger.error(f"Error obteniendo resumen: {e}")
        return jsonify({'status': 'error', 'message': str(e)}), 500


# ========================================
# ENDPOINTS DE SALUD
# ========================================

@app.route('/health', methods=['GET'])
def health_check():
    """Verifica el estado de la API y la conexión a BD"""
    try:
        # Verificar conexión a BD
        execute_query("SELECT 1")

        return jsonify({
            'status': 'healthy',
            'service': 'iot-api',
            'database': 'connected',
            'timestamp': datetime.now().isoformat()
        }), 200
    except Exception as e:
        return jsonify({
            'status': 'unhealthy',
            'service': 'iot-api',
            'database': 'disconnected',
            'error': str(e),
            'timestamp': datetime.now().isoformat()
        }), 503


@app.route('/', methods=['GET'])
def index():
    """Página principal de la API"""
    return jsonify({
        'service': 'IoT API UNAULA',
        'version': '1.0.0',
        'endpoints': {
            'dispositivos': '/api/v1/dispositivos',
            'datos': '/api/v1/datos',
            'reportes': '/api/v1/reportes/resumen',
            'health': '/health'
        }
    }), 200


# ========================================
# MANEJO DE ERRORES
# ========================================

@app.errorhandler(404)
def not_found(error):
    return jsonify({'status': 'error', 'message': 'Recurso no encontrado'}), 404


@app.errorhandler(500)
def internal_error(error):
    logger.error(f"Error interno: {error}")
    return jsonify({'status': 'error', 'message': 'Error interno del servidor'}), 500


# ========================================
# MAIN (para desarrollo local)
# ========================================

if __name__ == '__main__':
    logger.info("Iniciando servidor Flask en modo desarrollo...")
    app.run(host='0.0.0.0', port=5000, debug=True)
