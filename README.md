# 🐉 so_long

**so_long** es un pequeño videojuego 2D desarrollado en C con la librería gráfica **MLX42**. El protagonista es un **dragón** que debe moverse por un mapa, **recolectar todos los fuegos 🔥** y finalmente **llegar a la puerta de salida 🚪**, que solo se abrirá si todos los fuegos han sido recogidos.

---

## 🎮 Objetivo del juego

- Controlar al **dragón** con las teclas `W`, `A`, `S`, `D`.
- Comer todos los fuegos (`C`) para que se habilite la salida (`E`).
- Al llegar a la salida con todos los fuegos recogidos, **ganas la partida**.

---

## 🧩 Estructura del mapa

El mapa es un archivo `.ber` que contiene los siguientes caracteres:

| Símbolo | Descripción                  |
|---------|------------------------------|
| `1`     | Pared (obstáculo)            |
| `0`     | Suelo (camino libre)         |
| `P`     | Posición inicial del dragón  |
| `C`     | Fuego (coleccionable)        |
| `E`     | Puerta de salida             |

---

## ⚙️ Compilación

Este proyecto requiere **MLX42**, **libft**, **ft_printf** y **get_next_line**. Asegúrate de tener todas las dependencias correctamente integradas en tu repositorio.

Para compilar el proyecto, ejecuta:

```bash
make
```

▶️ Ejecución
Para iniciar el juego, usa:

```
./so_long maps/ejemplo.ber
Reemplaza maps/ejemplo.ber con el nombre del mapa que desees jugar.
```

🧑‍💻 Autora
Marcela Jimenez

---

📛 Login: ingjimen

---
💡 Notas

- El juego muestra mensajes en la terminal sobre los movimientos del dragón y el estado del juego.

- Si el mapa no es válido o falta algún elemento obligatorio (P, C, E), se mostrará un mensaje de error.
