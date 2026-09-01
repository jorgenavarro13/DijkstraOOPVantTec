#include <bits/stdc++.h>
#include "./Node.hpp"
using namespace std;

Node::Node(int v){
    V=v;
    W=1;
}

Node::Node(int v, int w){
    V=v;
    W=w;
}

int Node::getWeight(){
    return W;
}

int Node::getValue(){
    return V;
}

pair<int,int> Node::getNode(){
    return make_pair(V,W);
}