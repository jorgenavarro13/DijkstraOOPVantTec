#include <bits/stdc++.h>
#include "./Graph.hpp"
using namespace std;

namespace{
    const string inputs_folder = "./graphExamples/";
    const vector<string> weightedExamples = {
        "weightedGraph1.txt",
        "weightedGraph2_diamond.txt",
        "weightedGraph3_disconnected.txt",
        "weightedGraph4_dense.txt"
    };
    const vector<string> unweightedExamples = {
        "unweightedGraph1.txt",
        "unweightedGraph2_cycle.txt"
    };
}

int chooseExample(const vector<string>& examples){
    cout<<"Choose an example graph:"<<endl;
    for(size_t i=0; i<examples.size(); i++){
        cout<<i+1<<") "<<examples[i]<<endl;
    }

    int choice;
    while (!(cin >> choice) || choice<1 || choice>(int)examples.size()) {
        cout << "Error: No valid number, try again:\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice-1;
}

int main(){
    cout<<"Welcome to Dijkstra's algorithm demonstration with OOP"<<endl;

    int action;
    do{
        cout<<"\nWhat do you want to do?"<<endl;
        cout<<"1) Test a weighted graph"<<endl;
        cout<<"2) Test a unweighted graph"<<endl;
        cout<<"3) Create my custom graph"<<endl;
        cout<<"4) Exit"<<endl;

        while (!(cin >> action) || action < 1 || action >  5) {
                cout << "Error: No valid number, try again:\n";
                cin.clear();  cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Graph graph;
        vector<vector<int>> connections;

        switch(action){
            case 1:
                connections = graph.readWeightedGraphFile(inputs_folder+weightedExamples[chooseExample(weightedExamples)]);
                graph.fillGraph(connections);
                graph.selectBeginning();
                graph.selectEnd();
                graph.findRoute();
                break;
            case 2:
                connections = graph.readUnweightedGraphFile(inputs_folder+unweightedExamples[chooseExample(unweightedExamples)]);
                graph.fillGraph(connections);
                graph.selectBeginning();
                graph.selectEnd();
                graph.findRoute();
                break;
            case 3:
                graph.fillWeightedGraph();
                graph.selectBeginning();
                graph.selectEnd();
                graph.findRoute();
                break;
            case 4: 
                graph.fillUnweightedGraph();
                graph.selectBeginning();
                graph.selectEnd();
                graph.findRoute();

            case 5:
                cout<<"Exiting the program..."<<endl;
                break;
            default:
                cout<<"Error: No valid number, try again:\n";
                break;
        }

    } while(action != 4);

    return 0;
}