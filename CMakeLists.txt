# Minimum CMake version this file relies on (features/syntax used below need at least this).
cmake_minimum_required(VERSION 3.10)

# Declares the project name and which language(s) it uses.
project(DijkstraOOP CXX)

# Equivalent to g++'s -std=c++11, applied to every target below.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# A "target" is a thing to build. This one is an executable named Output,
# built from these three translation units (mirrors your launch.sh command).
add_executable(Output
    main.cpp
    Graph.cpp
    Node.cpp
)
