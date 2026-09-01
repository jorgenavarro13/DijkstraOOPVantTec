if command -v cmake &> /dev/null; then
    # Running with cmake
    # Clear the current terminal, specify the current directory as . and the build directory as build, then run the output
    clear && cmake -S . -B build && cmake --build build && ./build/Output
else
    clear && mkdir build && g++ main.cpp Graph.cpp Node.cpp -o ./build/Output.exe &&  ./build/Output.exe
fi