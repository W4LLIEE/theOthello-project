#!/bin/bash

if ! command -v gcc &> /dev/null
then
    echo "GCC not found."
    echo "Install it with:"
    echo "Ubuntu/Debian: sudo apt install build-essential"
    echo "Fedora: sudo dnf install gcc"
    echo "Arch: sudo pacman -S gcc"
    exit 1
fi

echo "Compiling..."
gcc -Wall -Wextra main.c board.c logic.c menu.c -o othello

echo "Build complete!"
