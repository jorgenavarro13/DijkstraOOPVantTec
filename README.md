## Dijkstra OOP

Jorge Arturo Montiel Navarro | A01278612

This project consists on an implementation of Dijkstras's algorithm with an OOP paradigm to showcase the mastery of this skill in order to join VantTec as a software developer

### Tech stack 
This project was mainly developed in C++, using the standard of C++ 11 but it also includes other tools for the correct deployment and visualization as:

- CMake
- Bat (Windows)
- Sh (Linux)
- Graphviz


## How to initialize this project?
1.- Make sure you have installed a recent compiler of C++, you can use the following commands on your terminal:

```
g++ --version
gcc --version
```

It none of them shows you the version of a compiler installed, install it.

2.- Clone the repo and go into it
```
git clone https://github.com/jorgenavarro13/DijkstraOOPVantTec.git
cd  DijkstraOOPVantTec
```

3.- Once you are there, depending on your OS you can execute the following commands:

On Windows:
```
  ./launch.bat
```

On Unix like OS:
```
chmod +x ./launch.sh && ./launch.sh
```

**Note:** If you want to visualize the images, a library called graphviz is used, you can install it using the following commands

On linux:
```
sudo apt update
sudo apt install graphviz
```

On windows:
```
pip install graphviz
```

By now, you should be able to see a terminal with the program running and asking for the input.
You will be able to choose between running an predefined example or just type and insert your own graph

Follow the instructions to see the output, you have some inputs to experiment and see the result or you can construct your own graph :)


### The process of though behind the algorithm
1.- OOP  This repository was intentionally generated to put in practice several concepts of oriented object solutions,
using different access specifiers to mantain the logic encapsulated

2.- The dijkstra's algorithm implementation relies on subjacent OOP data structure class Node, and is used across several methods, using specialized comparison data specifier to compare (useful in priority queues)

3.- Dijstra's was implemented backwards, with a parent unodered_map, in order to keep track of the previous elements taken before reaching an specific destination, allowing us to reconstruct the path.

4.- For deployment was used launch files to alert and build the solution for the final user of this repo, so they can focus on the review of the tool, this repo is planned to be compatible across Winows and Unix OS's

5.-CMakeLists is a enterprise level solution for complex codebases allowing to target different build types with different purposes, in this case,was a showcase of how a solution like this one can have such an good level even for the basics

6- The different graphExercises are mainly there to give the user a much better experience, just by selecting pre-stablished graphs and explore easily, this feature is important in Graph class with it's respective methods for this

For the commitee who's reviewing this solution, I hope this can show the abilities I can provide to the team and I'll be happy to see your response