# This part is to alert the user if it has installed graphviz
$DOT_PATH = (Get-Command dot -ErrorAction SilentlyContinue).Source

# If not found, then send an alert to the user
if (-not $DOT_PATH) {
    # Send native Windows visual toast notification
    $noti = New-Object -ComObject Wscript.Shell
    $noti.Popup("Graphviz is not installed, install it crack", 0, "Falta Dependencia", 16) | Out-Null
    
    Write-Error "Error: Graphviz not installed."
    Exit 1
}

Write-Host "Graphviz is succesfully installed in: $DOT_PATH"

@echo off
where cmake >nul 2>nul
if %errorlevel%==0 (
    REM Running with cmake
    REM Clear the current terminal, specify the current directory as . and the build directory as build, then run the output
    cls && cmake -S . -B build && cmake --build build && build\Output.exe
) else (
    cls && mkdir build && g++ main.cpp Graph.cpp Node.cpp -o build\Output.exe && build\Output.exe
)
