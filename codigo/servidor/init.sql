-- Script de Inicialización de Base de Datos
-- IF0112 - Complementaria II - IoT UNAULA
-- PostgreSQL 15

-- ========================================
-- TABLA: dispositivos
-- Almacena información de los ESP32 registrados
-- ========================================
CREATE TABLE IF NOT EXISTS dispositivos (
    id SERIAL PRIMARY KEY,
    dispositivo_id VARCHAR(50) UNIQUE NOT NULL,
    nombre VARCHAR(100),
    estudiante VARCHAR(100),
    ubicacion VARCHAR(100),
    fecha_registro TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    ultimo_reporte TIMESTAMP,
    activo BOOLEAN DEFAULT TRUE
);

-- ========================================
-- TABLA: datos_sensores
-- Almacena las lecturas de sensores enviadas por los ESP32
-- ========================================
CREATE TABLE IF NOT EXISTS datos_sensores (
    id SERIAL PRIMARY KEY,
    dispositivo_id VARCHAR(50) NOT NULL,
    temperatura NUMERIC(5,2) NOT NULL,
    humedad NUMERIC(5,2) NOT NULL,
    luz INTEGER NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (dispositivo_id) REFERENCES dispositivos(dispositivo_id)
);

-- ========================================
-- TABLA: eventos
-- Registra eventos del sistema (alertas, errores)
-- ========================================
CREATE TABLE IF NOT EXISTS eventos (
    id SERIAL PRIMARY KEY,
    dispositivo_id VARCHAR(50),
    tipo_evento VARCHAR(20) NOT NULL, -- 'alerta', 'error', 'info'
    mensaje TEXT NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (dispositivo_id) REFERENCES dispositivos(dispositivo_id)
);

-- ========================================
-- ÍNDICES para optimizar consultas
-- ========================================
CREATE INDEX IF NOT EXISTS idx_datos_dispositivo ON datos_sensores(dispositivo_id);
CREATE INDEX IF NOT EXISTS idx_datos_timestamp ON datos_sensores(timestamp DESC);
CREATE INDEX IF NOT EXISTS idx_datos_dispositivo_timestamp ON datos_sensores(dispositivo_id, timestamp DESC);
CREATE INDEX IF NOT EXISTS idx_eventos_timestamp ON eventos(timestamp DESC);

-- ========================================
-- VISTAS útiles para consultas comunes
-- ========================================

-- Vista: Última lectura de cada dispositivo
CREATE OR REPLACE VIEW v_ultima_lectura AS
SELECT DISTINCT ON (d.dispositivo_id)
    d.dispositivo_id,
    d.nombre,
    d.estudiante,
    ds.temperatura,
    ds.humedad,
    ds.luz,
    ds.timestamp as ultima_lectura
FROM dispositivos d
LEFT JOIN datos_sensores ds ON d.dispositivo_id = ds.dispositivo_id
WHERE d.activo = TRUE
ORDER BY d.dispositivo_id, ds.timestamp DESC;

-- Vista: Promedios por dispositivo (últimas 24 horas)
CREATE OR REPLACE VIEW v_promedios_24h AS
SELECT
    d.dispositivo_id,
    d.nombre,
    d.estudiante,
    AVG(ds.temperatura) as temp_promedio,
    AVG(ds.humedad) as humedad_promedio,
    AVG(ds.luz) as luz_promedio,
    MIN(ds.temperatura) as temp_minima,
    MAX(ds.temperatura) as temp_maxima,
    COUNT(*) as num_lecturas
FROM dispositivos d
JOIN datos_sensores ds ON d.dispositivo_id = ds.dispositivo_id
WHERE ds.timestamp >= NOW() - INTERVAL '24 hours'
    AND d.activo = TRUE
GROUP BY d.dispositivo_id, d.nombre, d.estudiante;

-- ========================================
-- TRIGGERS para actualizar último_reporte
-- ========================================
CREATE OR REPLACE FUNCTION actualizar_ultimo_reporte()
RETURNS TRIGGER AS $$
BEGIN
    UPDATE dispositivos
    SET ultimo_reporte = NEW.timestamp
    WHERE dispositivo_id = NEW.dispositivo_id;
    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_actualizar_reporte
    AFTER INSERT ON datos_sensores
    FOR EACH ROW
    EXECUTE FUNCTION actualizar_ultimo_reporte();

-- ========================================
-- DATOS DE EJEMPLO (opcional - comentar en producción)
-- ========================================

-- Dispositivo de prueba
-- INSERT INTO dispositivos (dispositivo_id, nombre, estudiante, ubicacion)
-- VALUES ('esp32_test', 'ESP32 de Prueba', 'Docente', 'Laboratorio');

-- Datos de ejemplo (últimas 24 horas)
-- INSERT INTO datos_sensores (dispositivo_id, temperatura, humedad, luz, timestamp)
-- SELECT
--     'esp32_test',
--     22 + (random() * 6)::numeric(5,2),
--     60 + (random() * 20)::numeric(5,2),
--     (random() * 4095)::integer,
--     NOW() - (random() * INTERVAL '24 hours')
-- FROM generate_series(1, 100);

-- ========================================
-- COMENTARIOS en tablas
-- ========================================
COMMENT ON TABLE dispositivos IS 'Registro de dispositivos ESP32 del curso';
COMMENT ON TABLE datos_sensores IS 'Lecturas de temperatura, humedad y luz de los ESP32';
COMMENT ON TABLE eventos IS 'Registro de eventos del sistema';

COMMENT ON COLUMN datos_sensores.temperatura IS 'Temperatura en grados Celsius';
COMMENT ON COLUMN datos_sensores.humedad IS 'Humedad relativa en porcentaje';
COMMENT ON COLUMN datos_sensores.luz IS 'Nivel de luz (0-4095) del ADC';

-- ========================================
-- Finalización
-- ========================================
-- Mostrar resumen
SELECT 'Base de datos inicializada correctamente' as status;
SELECT COUNT(*) as dispositivos_registrados FROM dispositivos;
SELECT COUNT(*) as lecturas_totales FROM datos_sensores;
