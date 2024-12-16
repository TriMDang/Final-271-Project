//=========================================
// mytests.cpp
// Author: Tri Dang, Andrew Nguyen, Aisha Barry
// Description: Implementations of all class Graph's variable and functions.
//=========================================
#include <tuple>
#include "WeightedGraph.hpp"
#include "customexceptions.hpp" 
#include <unordered_map>
#include <vector>
#include <queue>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

Graph::Graph(){
}

Graph::~Graph(){

}

Graph::Graph(const Graph& other){

}


//=========================================
// read from STDIN
// Author: Tri Dang
// Parameter: None. Is an assignment for any graph
// Return: None. Reassign the graph into an STDIN with n nodes, m edges, and all node-to-node edges
// Description: Prompts user to fill out a map in the terminal.
//=========================================
Graph Graph::readFromSTDIN() {
    int n, m;
    cin >> n >> m; // Read the number of vertices (n) and edges (m)

    Graph g;

    // adding all the vertices
    for (int i = i; i <= n; ++i) {
        g.addVertex(i);
    }

    // adding all the edges
    for (int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    return (g);
}
