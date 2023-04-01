#include "graph.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

#define VERYBIGINT 1000000000

Graph::Graph()
{
    // initializing each element of the adjacency matrix to zero
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = 0;
        }
    }
    vertexCount = 0;
}

void Graph::displayAdjacencyMatrix()
{
    cout << "\n\n Adjacency Matrix:";

    // displaying the 2D array
    for (int i = 0; i < SIZE; ++i) {
        cout << "\n";
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << matrix[i][j];
        }
    }
}
void Graph::addEdge(int x, int y, int weight)
{
    // connecting the vertices
    matrix[y][x] = weight;
    matrix[x][y] = weight;
    
}
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}

void Graph::find_min_dist_floyd() {
    // Ваш код должен быть здесь
    int weights[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++) {
            if (i == j)
                weights[i][j] = 0;
            else {
                if (matrix[i][j] != 0)
                    weights[i][j] = matrix[i][j];
                else
                    weights[i][j] = VERYBIGINT;
            }
        }
    for (int k = 0; k < vertexCount; k++) {
        int ck = vertexes[k];
        for (int i = 0; i < vertexCount; i++) {
            if (i == k) continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++) {
                if (j == k) continue;
                int cj = vertexes[j];
                if (weights[i][j] > weights[i][k] + weights[k][j]) {
                    weights[i][j] = weights[i][k] + weights[k][j];
                }
            }
        }
    }
    // вывод на экран
    char ch = 'A';
    cout << "  ";
    for (int i = 1; i < 6; i++) 
        cout << std::setw(11) << ch++;
    cout << endl;
    
    char ch2 = 'A';
    for (int i = 1; i < 6; i++) {
        ch = 'A';
        cout << ch2++ << " ";
        for (int k = 0; k < vertexCount; k++) {
            int ck = vertexes[k];
            cout << std::setw(11) <<  weights[i][ck];
        }
        cout << endl;
    }
}