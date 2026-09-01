#include <bits/stdc++.h>
#include "./Graph.hpp"
using namespace std;

Graph::Graph(vector<vector<int>> & connections){
    int t_begin, t_end;
    for(vector<int> connection : connections){
        int u = connection[0];
        int v = connection[1];
        int w = connection[2];

        Node temp(v,w);
        graph[i].push_back(temp);
        
        t_begin=min(t_begin,min(u,v));
        t_end=max(t_end,max(u,v));
    }
    begin = t_begin;
    end = t_end;
}



void Graph::selectBeggining(){
    cout<<"Select the beggining of the map, this node represents the beggining of the search for the other nodes"<<endl;
    cout<<"Your options are the following ones:"<<endl;
    for(auto it=graph.begin(); it!=graph.end(); it++){
        cout<<graph->first<<", ";
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

void Graph::selectBeggining(){
    cout<<"Select the end of the map, this node represents the final destination of the search"<<endl;
    cout<<"Your options are the following ones:"<<endl;
    for(auto it=graph.begin(); it!=graph.end(); it++){
        cout<<graph->first<<", ";
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

vector<vector<int>> Graph::fillWeightedGraph(){
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
        float u, v, w;
        file >> u; file>> v ; file >> w;
        coordinates.emplace_back(u,v,w);
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
        float u, v;
        file >> u; file>> v ; 
        coordinates.emplace_back(u,v);
    }
    file.close();
    return connections;
}

void Graph::fillGraphFromFile(vector<vector<int>> connections){
    if(connections.size()==0){
        cout<<"The file wasn't read correctly check if the route is correct"<<endl;
        return;
    }
    
    int elements_per_connection = connections[0].size();
    for(vector<int> connection : connections){
        int u = connection[0];
        graph[u] = (elements_per_connection==3) ? Node(connection[1], connection[2]) : Node(connection[1]); 
    }
}
