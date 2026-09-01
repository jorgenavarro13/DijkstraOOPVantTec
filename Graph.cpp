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