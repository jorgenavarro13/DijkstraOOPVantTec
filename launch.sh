# This part is to alert the user if it has installed graphviz
DOT_PATH=$(command -v dot)

# If not found, then send an alert to the user
if [ -z "$DOT_PATH" ]; then
    notify-send -i dialog-error "Falta Dependencia" "Graphviz is not installed, install it crack"
    
    echo "Error: Graphviz not installed." >&2
    exit 1
fi

echo "Graphviz is succesfully installed in: $DOT_PATH"


if command -v cmake &> /dev/null; then
    # Running with cmake
    # Clear the current terminal, specify the current directory as . and the build directory as build, then run the output
    clear && cmake -S . -B build && cmake --build build && ./build/Output
else
    clear && mkdir build && g++ main.cpp Graph.cpp Node.cpp -o ./build/Output.exe &&  ./build/Output.exe
fi

