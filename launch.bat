@echo off
where cmake >nul 2>nul
if %errorlevel%==0 (
    REM Running with cmake
    REM Clear the current terminal, specify the current directory as . and the build directory as build, then run the output
    cls && cmake -S . -B build && cmake --build build && build\Output.exe
) else (
    cls && mkdir build && g++ main.cpp Graph.cpp Node.cpp -o build\Output.exe && build\Output.exe
)
