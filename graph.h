#pragma once

#define SIZE 10

class Graph {
private:
    // adjacency matrix
    int matrix[SIZE][SIZE];
    int vertexCount;
    int vertexes[SIZE];
public:
    // constructor
    Graph();
    void displayAdjacencyMatrix();
    void addEdge(int x, int y, int weight = 1);
    void addVertex(int vnumber);
 
    void find_min_dist_floyd();
};