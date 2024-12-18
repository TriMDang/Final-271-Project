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
#include <fstream>

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
    string fileName = "";
    cout << endl << "Enter File Name: ";
    cin >> fileName;
    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "No such file..." << endl;
        return Graph();  // Return an empty graph if file can't be opened
    }

    long n, m;
    inputFile >> n >> m; // Read the number of vertices (n) and edges (m)

    Graph g;

    // adding all the vertices
    for (int i = 0; i < n; ++i) {
        long ID;
        double x, y;
        inputFile >> ID >> x >> y;
        g.addVertex(ID, x, y);
        //cout << ID << " " << x << " " << y << " " << endl; // for data verifications
    }

    // adding all the edges
    for (int i = 0; i < m; ++i){
        long u, v;
        double w;
        string buildingName = "";
        
        inputFile >> u >> v >> w;

        getline(inputFile, buildingName); // scan for name if it exists


        g.addEdge(u, v, w, buildingName);
        //cout << u << " " << v << " " << w << " " << buildingName << " " << endl; // for data verifications
    }
    inputFile.close();
    cout << "Successful retrieval!" << endl << endl;
    return (g);
}
