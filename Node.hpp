#include <bits/stdc++.h>
using namespace std;

/*
    Node class represents each of the nodes in a graph
*/

class Node{
    public:
        Node(int v, int w); // For weighted graphs
        Node(int v); // For unweighted graphs

        // Accessing the elements of the node as the attributes are private
        int getWeight();
        int getValue();
        pair<int,int> getNode();
        ~Node();

    private:
        int V; // Value of the node, identifier
        int W; // Weight of the connection with an specific other node
};