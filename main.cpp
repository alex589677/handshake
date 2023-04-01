#include <iostream>
#include "graph.h"

using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");
    // creating objects of class Graph
    Graph obj;
    obj.addVertex(1);
    obj.addVertex(2);
    obj.addVertex(3);
    obj.addVertex(4);
    obj.addVertex(5);
    // calling methods
    obj.addEdge(1, 2);
    obj.addEdge(1, 3);
    obj.addEdge(1, 4);
    obj.addEdge(2, 3);

    obj.addEdge(2, 1);
    obj.addEdge(2, 3);
    obj.addEdge(2, 4);
    obj.addEdge(2, 5);

    obj.addEdge(3, 1);
    obj.addEdge(3, 2);
    obj.addEdge(3, 4);
    obj.addEdge(3, 5);

    obj.addEdge(4, 1);
    obj.addEdge(4, 2);
    obj.addEdge(4, 3);
    obj.addEdge(4, 5);

    obj.addEdge(5, 2);
    obj.addEdge(5, 3);
    obj.addEdge(5, 4);
    
    obj.find_min_dist_floyd();
    cout << endl;
 
    return 0;
}