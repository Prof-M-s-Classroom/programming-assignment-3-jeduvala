#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

Graph::Graph(int vertices) {
    numVertices = vertices;
    adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; ++j)
            adjMatrix[i][j] = INT_MAX;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
}

void Graph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

void Graph::primMST() {
    int* parent = new int[numVertices];
    int* key = new int[numVertices];

    MinHeap heap(numVertices);
    key[0] = 0;
    heap.decreaseKey(0, 0);

    for (int v = 1; v < numVertices; ++v)
        key[v] = INT_MAX;

    for (int i = 0; i < numVertices; ++i)
        parent[i] = -1;

    while (!heap.isEmpty()) {
        int u = heap.extractMin();

        for (int v = 0; v < numVertices; ++v) {
            int weight = adjMatrix[u][v];
            if (weight != INT_MAX && heap.isInMinHeap(v) && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                heap.decreaseKey(v, weight);
            }
        }
    }

    int totalWeight = 0;
    for (int i = 1; i < numVertices; ++i) {
        std::cout << parent[i] << " -- " << i << " (" << adjMatrix[i][parent[i]] << ")\n";
        totalWeight += adjMatrix[i][parent[i]];
    }
    std::cout << "Total Cost: " << totalWeight << std::endl;

    delete[] parent;
    delete[] key;
}
