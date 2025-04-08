# 🕹️ so_long – 42 Project

`so_long` is a simple 2D game built using the [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx) graphical library.  
This project is part of the École 42 common core and introduces the basics of game development, event handling, and rendering graphics in C.

---

## 🎯 Project Goals

- Parse and validate a **map file** from `.ber` format
- Render a **2D tile-based game** using MiniLibX
- Handle **user input** (keyboard arrows / WASD)
- Track **player movements** and **win/lose conditions**
- Manage **images**, **events**, and **memory** cleanly

---

## 🗺️ Game Overview

The game consists of:

- A rectangular map loaded from a file
- A player (`P`) who must collect all coins (`C`) and reach the exit (`E`)
- Walls (`1`) and walkable ground (`0`)
- Optional enemies or animations in the bonus version 👾

---

## 🧩 Map Rules

- Must be rectangular
- Surrounded by walls (`1`)
- Must contain **1 player**, **1 exit**, and **at least 1 collectible**
- Only valid characters: `0`, `1`, `C`, `E`, `P`
- File extension must be `.ber`

---

## 🎮 Controls

| Key        | Action         |
|------------|----------------|
| W / ↑      | Move Up        |
| A / ←      | Move Left      |
| S / ↓      | Move Down      |
| D / →      | Move Right     |
| ESC        | Exit Game      |

The game displays the number of moves the player makes.

---

## 📁 Project Structure

```
so_long/
├── src/                # Core game logic
│   ├── main.c
│   ├── game.c
│   ├── map.c
│   ├── render.c
│   └── input.c
├── includes/           # Headers
│   └── so_long.h
├── assets/             # Images (XPM format)
│   └── player.xpm ...
├── maps/               # Example .ber maps
├── Makefile
└── README.md
```

---

## 🧪 How to Run

### ✅ Compile:

```bash
make
```

### 🚀 Launch:

```bash
./so_long maps/example.ber
```

---


## 🖼 Dependencies

- MiniLibX (included in project or installed via 42)
- X11 or macOS system libraries

> Make sure you're running this on a Linux or macOS machine with graphical support.

---

## 📚 Useful Resources

- [MiniLibX documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [`man open`, `man read`, `man close`]
- 42 subject PDF & peer reviews

---

## 👤 Author
  
**42 Login**: hsilverb
**Contact**: [LinkedIn](https://www.linkedin.com/in/henrik-silverbage/)

---

## 📝 License

This project was developed as part of the 42 School curriculum.  
For educational and personal use only.
