# Othello (Reversi) – Terminal Edition

A fully playable **Othello/Reversi** game written in C for the terminal.

Features:
- Human vs Human
- Human vs Computer (basic AI)
- Interactive terminal menu (arrow key navigation)
- ANSI color support
- Cross-platform build scripts (Windows + Linux/macOS)

---

## 📦 Requirements

- GCC (or compatible C compiler)
- UTF-8 capable terminal
- ANSI escape code support

---

## 🚀 Quick Start

### Linux / macOS

Install GCC if needed:

```bash
# Ubuntu / Debian
sudo apt install build-essential

# Fedora
sudo dnf install gcc

# Arch
sudo pacman -S gcc

# macOS (Homebrew)
brew install gcc
```

Build and run:

```bash
chmod +x build.sh run.sh
./build.sh
./run.sh
```

---

### Windows

Install GCC via:
- MinGW
- MSYS2
- WSL (recommended)

Verify installation:

```bash
gcc --version
```

Build:

```bat
build.bat
```

Run:

```bat
run.bat
```

---

## 🎮 Controls

### Menu
- ↑ / ↓ Arrow Keys → Navigate
- Enter → Confirm

### Gameplay
- Enter board coordinates (e.g. `A1`)
- Valid moves are shown automatically
- Turns skip if no valid moves
- Game ends when no moves remain

---

## 🧠 Technical Details

- Modular structure (`board`, `logic`, `menu`)
- ANSI escape codes for screen control
- `termios` raw mode for real-time input
- AI selects move based on maximum immediate gain
- Score validation and integrity checks included

---

## 📁 Project Structure

```
.
├── main.c
├── board.c
├── logic.c
├── menu.c
├── board.h
├── logic.h
├── menu.h
├── build.sh
├── build.bat
├── run.sh
├── run.bat
└── README.md
```

---

## ⚠ Notes

- Raw mode input requires a POSIX-compatible terminal.
- Windows users are recommended to use Windows Terminal or WSL.
- ANSI colors may not display properly in legacy terminals.

---

## 📜 License

This project is for educational purposes.
