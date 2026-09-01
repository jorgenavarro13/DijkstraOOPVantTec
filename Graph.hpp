#include <bits/stdc++.h>
#include "./Node.hpp"
using namespace std;

/*
    Graph class for representing a graph and finding the shortest path between two nodes.

    The implementation takes in consideration a weighted and directed graph
*/

class Graph {
    public:
        Graph(){};
        /*

        The construction of the graph based on a vector with the nodes, edges and weight uses this form
        connections[i] = (ui, vi, wi)

        u-> The node that points to v
        v-> Node pointed by u
        w-> Weight of the connection between them

        */

        ~Graph()= default;

        void selectBeginning();
        void selectEnd();

        // User filling the graph manually
        vector<vector<int>> fillWeightedGraph();
        vector<vector<int>> fillUnweightedGraph();

        // Reading the input from static files for demonstration
        vector<vector<int>> readWeightedGraphFile(string file_route);
        vector<vector<int>> readUnweightedGraphFile(string file_route);

        void fillGraph(vector<vector<int>> connections);

        void findRoute();
        
        private:
        int dijkstra();
        unordered_map<int, vector<Node> > graph; 
        int begin;
        int end;  // By default we select the lower v for begin and the higher for end

        /*
            This implementation uses a graph as the memory source for the graph
            It can be implemented using a vector but, the cons of using this data structure is that deletion costs more
            in case we need it, so to keep it scalabe the desition was to use a map.


            graph[i] -> returns the  vector of nodes that are connected to the node i

            vector<pair<int,int>> 
            
        */
};
