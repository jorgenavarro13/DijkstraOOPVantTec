#include <bits/stdc++.h>
#include "./Node.hpp"
using namespace std;

/*
    Graph class for representing a graph and finding the shortest path between two nodes.
    The implementation takes in consideration a weighted and directed graph
*/


struct CompareNodeWeight {
    bool operator()(Node& n1, Node& n2) {
        return n1.getWeight() > n2.getWeight(); // Min-heap
    }
};
/* This data structure is necessary because of the use of a custom of 
a priority queue, allowing the comparison between nodes possible
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
        /*
        Method to encapsulate the logic regarding to the finding, reconstruction, generation of images when finding
        the path on a specific graph
        */
        void drawGraph(); // Writes graph+route to route.dot and creates route.png via Graphviz
        
        private:
        unordered_map<int,int> dijkstra();
        /*
        This implementation of dijkstra's algorithm, uses a backwards tracking for reconstruction of the path taken
        until the end of the graph, and also uses a priority queue with a special constructor for applying direct 
        comparison between Node types
        Priority queue was prefered to optimize the time efficiency to  (O((V + E) log V))
        */


        unordered_map<int, vector<Node> > graph;
        /*
        Here we store the connection that each node has with others in the graph, using a unordered map allow us to 
        access in constant time and find in constant time, against a vector, finding an element is more efficient, but we
        sacrifice a little bit the size of the structure used
        */

        unordered_map<int,int> parent; 
        /*
        This data structure allow us to represent the way backwards once the objective is reached, so we can mark 
        the way back on the image.  It was decided this way because it's time efficient and we only need to acces all
        the elements parents recursively until begin is reached

        parent[v] = node dijkstra reached v from on the best path so far
        */
    

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
