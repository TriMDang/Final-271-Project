//=========================================
// Graph.hpp
// Date: 12/6/2024
// Author: Tri Dang, Omar Perez, Esther Zhang
// Description: Declaration of all functions and variables for Weighted graph
//=========================================
#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <tuple>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    unordered_map<long, tuple<double, double>> vertices; // store vertices, <vertex key, <x, y>>
    unordered_map<long, vector<tuple<long, double, string>>> adjacencyList; // store edges; <u, <v, weight, name>>
    unordered_map<long, tuple<double, long>> dijkstraResults; // Key node u: total weight, parent node
public:
    Graph(); // Default constructor
    ~Graph(); // Destructor
    Graph(const Graph& other);   // Copy constructor
    Graph& operator=(const Graph& other);
    static Graph readFromSTDIN();
    void addEdge(long u, long v, double weight, string name=""); // name="" prevents line with no names
    void addVertex(long u, double x, double y);
    void dijkstra(double x, double y, double endX, double endY); // Dijkstra does NOT return anything. 
    void relax(long u, long v, double weight);
};


#endif