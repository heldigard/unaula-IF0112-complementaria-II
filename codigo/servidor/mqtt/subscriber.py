"""
MQTT Subscriber + SQLite para proyecto IoT IF0112
Alternativa para quienes prefieran MQTT sobre HTTP directo.

Este script se suscribe a un topic, recibe JSON del ESP32 y guarda en SQLite.

Para correr:
  python subscriber.py

Dependencias:
  pip install paho-mqtt
"""

import json
import sqlite3
from datetime import datetime

import paho.mqtt.client as mqtt

DB_NAME = "sensores_mqtt.db"
BROKER = "broker.hivemq.com"  # Broker publico gratuito
PORT = 1883
TOPIC = "unaula/if0112/sensores"


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


def guardar_dato(temp: float, hum: float, luz: float) -> None:
    conn = sqlite3.connect(DB_NAME)
    cursor = conn.cursor()
    cursor.execute(
        """
        INSERT INTO sensores (temperatura, humedad, luz, timestamp)
        VALUES (?, ?, ?, ?)
        """,
        (temp, hum, luz, datetime.now().isoformat()),
    )
    conn.commit()
    conn.close()


def on_connect(client, userdata, flags, rc):
    if rc == 0:
        print(f"Conectado al broker MQTT. Suscrito a: {TOPIC}")
        client.subscribe(TOPIC)
    else:
        print(f"Error de conexion. Codigo: {rc}")


def on_message(client, userdata, msg):
    try:
        payload = json.loads(msg.payload.decode())
        temp = payload.get("temperatura")
        hum = payload.get("humedad")
        luz = payload.get("luz")

        if temp is None or hum is None or luz is None:
            print("JSON incompleto recibido:", payload)
            return

        guardar_dato(temp, hum, luz)
        print(f"[GUARDADO] T={temp}C  H={hum}%  L={luz}%")
    except json.JSONDecodeError:
        print("Error decodificando JSON:", msg.payload.decode())
    except Exception as e:
        print("Error procesando mensaje:", e)


if __name__ == "__main__":
    init_db()
    client = mqtt.Client()
    client.on_connect = on_connect
    client.on_message = on_message

    print(f"Conectando a {BROKER}:{PORT}...")
    client.connect(BROKER, PORT, 60)
    client.loop_forever()
