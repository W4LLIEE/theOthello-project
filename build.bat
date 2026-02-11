@echo off
where gcc >nul 2>nul
if %errorlevel% neq 0 (
    echo GCC not found.
    echo Install MinGW or MSYS2 and add gcc to PATH.
    pause
    exit /b
)

echo Compiling...
gcc -Wall -Wextra -o othello.exe main.c board.c logic.c menu.c

echo Build complete!
pause
