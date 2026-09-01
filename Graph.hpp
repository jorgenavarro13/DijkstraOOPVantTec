#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        Graph(vector<pair<int,int>> & grafo);
        ~Graph();

        void selectBeggining();
        void selectEnding();

        void fillGraph();
        void findRoute();

    private:
        unordered_map<int> graph;

};
