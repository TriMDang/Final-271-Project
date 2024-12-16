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

//=========================================
// Author: Tri Dang
// Parameter: None
// Return: None. graph is constructed
// Description: Construct graph.
//=========================================
Graph::Graph(){
}

//=========================================
// Author: Tri Dang
// Parameter: None
// Return: None. Graph deleted
// Description: Deletes everything.
//=========================================
Graph::~Graph(){
    adjacencyList.clear();
    vertices.clear();
}

//=========================================
// Author: Tri Dang
// Parameter: Other Graph
// Return: None
// Description: Makes a new graph then copies everything from the other graph.
//=========================================
Graph::Graph(const Graph& other) {
    adjacencyList = other.adjacencyList; 
    vertices = other.vertices;              
}

//=========================================
// Author: Tri Dang
// Parameter: Other Graph
// Return: This graph
// Description: Similar to copy constructor except it works on a prexisting graph.
//=========================================
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) { 
        adjacencyList = other.adjacencyList; 
        vertices = other.vertices;              
    }
    return *this; 
}

//=========================================
// Author: Tri Dang
// Parameter: node u, x coord, y coord
// Return: None
// Description: for reach node u, give the x and y.
//=========================================

void Graph::addVertex(long u, double x, double y){
    vertices[u] = make_tuple(x, y);
}

//=========================================
// Author: Tri Dang
// Parameter: node u, node v, weight, and location name
// Return: None
// Description: For the node key u, add it directs to v with a weight and name in a tuple.
//=========================================
void Graph::addEdge(long u, long v, double weight, string name){
    adjacencyList[u].push_back(make_tuple(v, weight, name));
}


//=========================================
// read from STDIN
// Author: Tri Dang
// Parameter: None. Is an assignment for any graph
// Return: None. Reassign the graph into an STDIN with n nodes, m edges, and all node-to-node edges
// Description: Modified from Project 4. This should take in denison.out inputs and store the data.
//=========================================
Graph Graph::readFromSTDIN() {
    long n, m;
    cin >> n >> m; // Read the number of vertices (n) and edges (m)

    Graph g;
    long verticesProcessed, edgesProcessed;

    // adding all the vertices
    for (int i = 0; i < n; ++i) { // check the <= n or < n; check index if correct
        long ID;
        double x, y; // for readability, not necessary I don't think...
        cin >> ID >> x >> y;
        g.addVertex(ID, x, y);
        verticesProcessed = i;
        //cout << ID << " " << x << " " << y << " " << endl; // for data verifications
    }

    // adding all the edges
    for (int i = 0; i < m; ++i){
        long u, v;
        double w;
        string buildingName = "";
        
        cin >> u >> v >> w;

        if (cin.peek() == ' '){ // should check if line m contains a name.
            getline(cin, buildingName); // getline over cin, idk why it works tho
        }

        g.addEdge(u, v, w, buildingName);
        edgesProcessed = i;
        cout << u << " " << v << " " << w << " " << buildingName << " " << endl; // for data verifications
    }
    // due to indexing, both verticesProcessed and EdgesProcessed are behind by 1. 0 -> n, m  should still work!
    cout << "Successful!" << endl << "Vertices Processed + 1: " << verticesProcessed << endl << "Edges Processed + 1: " << edgesProcessed << endl;
    return (g);
}
