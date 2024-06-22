#include <iostream>
#include "graph.cpp"

using namespace std;
int main() {

    Graph<string> graph = Graph<string>();
    graph.addVertex("elisa");
    graph.addVertex("rose");
    graph.addVertex("jack");
    graph.addDirectedEdge(0, 1);
    graph.addDirectedEdge(1,2);
    graph.printAdjList();
    return 0;
}
