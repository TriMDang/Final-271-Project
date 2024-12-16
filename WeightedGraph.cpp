//=========================================
// mytests.cpp
// Author: Tri Dang, Andrew Nguyen, Aisha Barry
// Description: Implementations of all class Graph's variable and functions.
//=========================================
#include <tuple>
#include "WeightedGraph.hpp"
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
    adjacencyList.clear();
    vertices.clear();
}

Graph::Graph(const Graph& other) {
    adjacencyList = other.adjacencyList; 
    vertices = other.vertices;              
}

Graph& Graph::operator=(const Graph& other) {
    if (this != &other) { 
        adjacencyList = other.adjacencyList; 
        vertices = other.vertices;              
    }
    return *this; 
}

void Graph::addVertex(int u, double x, double y){
    vertices[u] = make_tuple(x, y);
}

void Graph::addEdge(int u, int v, double weight, string name){
    adjacencyList[u].push_back(make_tuple(v, weight, name));
}


//=========================================
// read from STDIN
// Author: Tri Dang
// Parameter: None. Is an assignment for any graph
// Return: None. Reassign the graph into an STDIN with n nodes, m edges, and all node-to-node edges
// Description: This should take in denison.out inputs and store the data.
//=========================================
Graph Graph::readFromSTDIN() {
    int n, m;
    cin >> n >> m; // Read the number of vertices (n) and edges (m)

    Graph g;

    // adding all the vertices
    for (int i = 0; i < n; ++i) { // check the <= n or < n; check index if correct
        int ID;
        double x, y; // for readability, not necessary I don't think...
        cin >> ID >> x >> y;
        g.addVertex(ID, x, y);
    }

    // adding all the edges
    for (int i = 0; i < m; ++i){
        int u, v;
        double w;
        string buildingName = "";
        
        cin >> u >> v >> w;
        if (cin.peek() != '\n'){ // should check if line m contains a name.
            cin >> buildingName;
        }

        g.addEdge(u, v, w, buildingName);
    }
    return (g);
}
