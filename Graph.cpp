#include <bits/stdc++.h>
#include "./Graph.hpp"
using namespace std;

void Graph::selectBeginning(){
    cout<<"Select the beggining of the map, this node represents the beggining of the search for the other nodes"<<endl;
    cout<<"Your options are the following ones:"<<endl;
    for(auto it=graph.begin(); it!=graph.end(); it++){
        cout<<it->first<<", ";
    }
    cout<<"\nSelect one of them by typing the number, (ex: 1)):\n";
    
    int number;

    while (!(cin >> number) || graph.find(number)==graph.end()) {
        cout << "Error: No valid number\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again:\n";
    }

    begin = number;
    cout<<"The beggining of your graph was succesfully updated"<<endl;
}

void Graph::selectEnd(){
    cout<<"Select the end of the map, this node represents the final destination of the search"<<endl;
    cout<<"Your options are the following ones:"<<endl;
    for(auto it=graph.begin(); it!=graph.end(); it++){
        cout<<it->first<<", ";
    }
    cout<<"\nSelect one of them by typing the number, (ex: 1)):\n";
    
    int number;

    while (!(cin >> number) || graph.find(number)==graph.end()) {
        cout << "Error: No valid number\n";
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again:\n";
    }

    end = number;
    cout<<"The end of your graph was succesfully updated"<<endl;
}


vector<vector<int>> Graph::fillWeightedGraph(){
    cout<<"You are going to insert the map one connection at a time in the following format"<<endl;
    cout<<" u   v   w,  where u is the source node, v is the target node, and w the weight of the connection"<<endl;
    cout<<"\n Note: The values must be positive integers for each (u,v,w)"<<endl;
    cout<<"\nHow many connections of this type is going to have your graph? (Type the number)"<<endl;

    int number;
    while (!(cin >> number) || number<0) {
        cout << "Error: No valid number, try again:\n";
        cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    vector<vector<int>> connections;
    while(number--){
        vector<int> temp;
        for(int i=0; i<3;i++){
            int nu;
            while (!(cin >> nu) || nu<0) {
                cout << "Error: No valid number, try again:\n";
                cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            temp.push_back(nu);
            if(temp.size()==3) connections.push_back(temp);
        }
    }

    cout<<"Done, your graph is constructed "<<endl;
    return connections;
}

vector<vector<int>> Graph::fillUnweightedGraph(){
    cout<<"You are going to insert the map one connection at a time in the following format"<<endl;
    cout<<" u   v ,  where u is the source node, v is the target node"<<endl;
    cout<<"\n Note: The values must be positive integers for each (u,v)"<<endl;
    cout<<"\nHow many connections of this type is going to have your graph? (Type the number)"<<endl;

    int number;
    while (!(cin >> number) || number<0) {
        cout << "Error: No valid number, try again:\n";
        cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    vector<vector<int>> connections;

    while(number--){
        for(int i=0; i<2;i++){
            vector<int> temp;
            int nu;
            while (!(cin >> nu) || nu<0) {
                cout << "Error: No valid number, try again:\n";
                cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            temp.push_back(nu);
            if(temp.size()==2) connections.push_back(temp);
        }
    }

    cout<<"Done, your graph is constructed "<<endl;
    return connections;
}

vector<vector<int>> Graph::readWeightedGraphFile(string file_name){
    cout<<"Reading file..."<<endl;
    ifstream file;
    file.open(file_name);
    int lines;
    file >> lines;
    vector<vector<int>> connections;
    for(int i=0; i<lines; i++){
        int u, v, w;
        file >> u; file>> v ; file >> w;
        connections.push_back({u,v,w});
    }
    file.close();
    return connections;
}

vector<vector<int>> Graph::readUnweightedGraphFile(string file_name){
    cout<<"Reading file..."<<endl;
    ifstream file;
    file.open(file_name);
    int lines;
    file >> lines;
    vector<vector<int>> connections;
    for(int i=0; i<lines; i++){
        int u, v;
        file >> u; file>> v ; 
        connections.push_back({u,v});
    }
    file.close();
    return connections;
}

void Graph::fillGraph(vector<vector<int>> connections){
    if(connections.size()==0){
        cout<<"The current input is empty, check it"<<endl;
        return;
    }
    
    int elements_per_connection = connections[0].size();
    for(vector<int> connection : connections){
        int u = connection[0];
        int v = connection[1];
        graph[u].push_back( (elements_per_connection==3) ? Node(connection[1], connection[2]) : Node(connection[1]) ); 
        if(graph.find(v)==graph.end()) {graph[v];}
    }
}

unordered_map<int,int>  Graph::dijkstra(){
    
    int V = graph.size();
    priority_queue <Node, vector<Node>, CompareNodeWeight> pq;

    unordered_map<int,int> dist;
    for(auto it=graph.begin(); it!=graph.end();it++){
        dist[it->first] = INT_MAX;
        vector<Node> connections = it->second;
        for(Node n : connections ){
            dist[n.getValue()] = INT_MAX;
        }
    }

    dist[begin]=0;
    parent[begin]=begin; // marks the root so drawGraph knows where to stop walking back
    pq.emplace(Node(begin,0));

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();

        int u = top.getValue(); // u->current node
        int d = top.getWeight(); // d->distance to that node

        if(d > dist[u]) continue;

        for(Node p : graph[u]){
            int v = p.getValue();
            int w = p.getWeight();

            if(dist[u]+ w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u; // best predecessor of v seen so far
                pq.emplace(Node(v,dist[v]));
            }
        }
    }
    return dist;
}

void Graph::drawGraph(){
    vector<int> path;
    if(parent.find(end)!=parent.end()){
        int current = end;
        while(current != parent[current]){
            path.push_back(current);
            current = parent[current];
        }
        path.push_back(begin);
        reverse(path.begin(), path.end());
    }

    set<pair<int,int>> pathEdges;
    for(size_t i=0; i+1<path.size(); i++) pathEdges.insert({path[i], path[i+1]});

    ofstream dot("route.dot");
    dot << "digraph G {\n  rankdir=LR;\n";
    for(auto& entry : graph){
        int u = entry.first;
        for(Node n : entry.second){
            int v = n.getValue();
            int w = n.getWeight();
            bool onPath = pathEdges.count({u,v}) > 0;
            dot << "  " << u << " -> " << v << " [label=\"" << w << "\"" << (onPath ? ", color=red, penwidth=2" : "") << "];\n";
        }
    }
    for(int node : path) dot << "  " << node << " [style=filled, fillcolor=orange];\n";
    dot << "}\n";
    dot.close();

    system("dot -Tpng route.dot -o route.png");
    cout << "Graph image saved to route.png" << endl;
}

void Graph::findRoute(){
    cout<<"Calculating the route..."<<endl;
    unordered_map<int,int> distances = dijkstra();
    int result = distances[end];
    cout<< "The path between "<<begin<<" and "<<end << ((result == INT_MAX) ? "doesn´t exist" : "exists")<<endl;
    if(result!=INT_MAX) cout<< " and the cost is "<<result<<endl;
    drawGraph();
}

