/*
//
// Created by nesma on 14/03/2023.
//

#ifndef DAGRUPO_GRAPH_H
#define DAGRUPO_GRAPH_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);

    // Depth-First Search: example implementation
    void dfs(int v);

    // Breadth-First Search: example implementation
    void bfs(int v);
};

#endif //DAGRUPO_GRAPH_H
*/
