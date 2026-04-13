"""
API FastAPI + SQLite para proyecto IoT IF0112
Ejemplo docente - UNAULA Complementaria II

Endpoints:
  POST /datos        → Recibe JSON del ESP32 y guarda en BD
  GET  /datos        → Lista todos los registros
  GET  /datos/latest → Ultimo registro insertado
  GET  /             → Mensaje de bienvenida

Documentacion interactiva (Swagger):
  http://localhost:8000/docs

Para correr:
  uvicorn main:app --host 0.0.0.0 --port 8000 --reload
"""

import sqlite3
from contextlib import asynccontextmanager
from datetime import datetime

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel

DB_NAME = "sensores.db"

# ---------------------------------------------------------------------------
# Modelo Pydantic: valida el JSON que envia el ESP32
# ---------------------------------------------------------------------------
class LecturaSensores(BaseModel):
    temperatura: float
    humedad: float
    luz: float


# ---------------------------------------------------------------------------
# Inicializacion de la base de datos SQLite
# ---------------------------------------------------------------------------
def init_db() -> None:
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute(
        """
        CREATE TABLE IF NOT EXISTS sensores (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            temperatura REAL NOT NULL,
            humedad REAL NOT NULL,
            luz REAL NOT NULL,
            timestamp TEXT NOT NULL
        )
        """
    )
    conn.commit()
    conn.close()


# ---------------------------------------------------------------------------
# Guardar una lectura en la BD
# ---------------------------------------------------------------------------
def guardar_dato(lectura: LecturaSensores) -> None:
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute(
        """
        INSERT INTO sensores (temperatura, humedad, luz, timestamp)
        VALUES (?, ?, ?, ?)
        """,
        (
            lectura.temperatura,
            lectura.humedad,
            lectura.luz,
            datetime.now().isoformat(),
        ),
    )
    conn.commit()
    conn.close()


# ---------------------------------------------------------------------------
# Obtener todos los registros (mas recientes primero)
# ---------------------------------------------------------------------------
def obtener_datos(limit: int = 100) -> list[dict]:
    conn = sqlite3.connect(DB_NAME)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    cursor.execute(
        "SELECT * FROM sensores ORDER BY timestamp DESC LIMIT ?",
        (limit,),
    )
    rows = [dict(row) for row in cursor.fetchall()]
    conn.close()
    return rows


# ---------------------------------------------------------------------------
# Obtener el ultimo registro
# ---------------------------------------------------------------------------
def obtener_ultimo_dato() -> dict | None:
    conn = sqlite3.connect(DB_NAME)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    cursor.execute(
        "SELECT * FROM sensores ORDER BY timestamp DESC LIMIT 1"
    )
    row = cursor.fetchone()
    conn.close()
    return dict(row) if row else None


# ---------------------------------------------------------------------------
# Lifespan: inicializa la BD al arrancar el servidor
# ---------------------------------------------------------------------------
@asynccontextmanager
async def lifespan(app: FastAPI):
    init_db()
    yield


app = FastAPI(
    title="API Sensores IoT",
    description="API para recibir y consultar datos del ESP32",
    version="1.0.0",
    lifespan=lifespan,
)

# CORS habilitado: permite que un dashboard web (E5) consulte la API
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)


# ---------------------------------------------------------------------------
# Endpoints
# ---------------------------------------------------------------------------
@app.get("/")
def root() -> dict:
    return {
        "mensaje": "API IoT IF0112 funcionando",
        "docs": "/docs",
        "endpoints": ["/datos", "/datos/latest"],
    }


@app.post("/datos")
def recibir_datos(lectura: LecturaSensores) -> dict:
    """Recibe datos del ESP32 y los almacena en SQLite."""
    guardar_dato(lectura)
    return {"status": "ok", "recibido": lectura.model_dump()}


@app.get("/datos")
def listar_datos(limit: int = 100) -> dict:
    """Devuelve el historial de lecturas almacenadas."""
    return {"datos": obtener_datos(limit)}


@app.get("/datos/latest")
def ultimo_dato() -> dict:
    """Devuelve la lectura mas reciente."""
    dato = obtener_ultimo_dato()
    return {"dato": dato}
