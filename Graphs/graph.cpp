//
// Created by Arjun Manjunath on 05/04/24.
//
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <cassert>
#include "../linked-list/list.cpp"

template<typename T>
class Vertex {
private:
    T data;
    LinkedList<Vertex<T>&> adjList = LinkedList<Vertex<T>&>();

public:
    T getData() {
        return this->data;
    }
    Vertex(T data) {
        this->data = data;
    }
    void addEdge(Vertex<T> &adjNode) {
        adjList.insertStart(adjNode);
    }
    void printAdjNodes() {
        cout << this->data << ": ";
        adjList.traverse();
    }
};

using namespace std;
template<typename T>
class Graph {
private:
    int V;
    vector<Vertex<T>> vertices;
public:
    Graph() {
        V = 0;
    }
    void addDirectedEdge(int src, int des) {
        assert(src >= 0 && src < this->V && "Source Vertex Not Found");
        assert(des >= 0 && des < this->V && "Destination Vertex Not Found");
        this->vertices[src].addEdge(vertices[des]);
    }
    void addVertex(T data) {
        this->V++;
         vertices.push_back(Vertex<T>(data));
    }

    void printAdjList() {
        for (Vertex<T> x: vertices) {
            x.printAdjNodes();
        }
    }
    void printVertexArray() {
        cout << "[ ";
        for (Vertex<T> x: vertices) {
            cout << x.getData() << ", ";
        }
        cout << "]" << endl;
    }

    T getVertex(int k) {
        return vertices[k];
    }

    vector<int> findVertexIndexes(T key) {
        vector<int> indexArray;
       for (int i=0; i<vertices.size(); i++) {
           if (vertices[i]->data == key) indexArray.push_back(i);
       }
       return indexArray;
    }
//    void BFS(int start) {
//        vector<bool> visited(this->V, false);
//        queue<int> s;
//        visited[start] = true;
//        s.push(start);
//        while (!s.empty()) {
//            int current = s.front();
//            s.pop();
//            cout << vertices[current] << " ";
//            for (int adjVertex=0; adjVertex<this->V; adjVertex++) {
//                    if (adjMatrix[current][adjVertex] && !visited[adjVertex]) {
//                        visited[adjVertex] = true;
//                        s.push(adjVertex);
//                    }
//            }
//        }
//    }
//    void DFS(int start, string word) {
//        vector<bool> visited(this->V, false);
//        stack<int> s;
//        int i=0;
//        char nextChar = word[i++];
//        s.push(start);
//        while (!s.empty()) {
//            int current = s.top();
//            s.pop();
//            if (!visited[current]) {
//                cout << current << " ";
//                visited[current] = true;
//                for (int adjVertex=this->V; adjVertex>0; adjVertex--) {
//                    if (!visited[adjVertex] && adjMatrix[current][adjVertex] && vertices[adjVertex] == nextChar) {
//                        s.push(adjVertex);
//                        nextChar = word[++i];
//                    }
//                }
//
//            }
//        }
//    }
};
