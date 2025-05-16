#include "heap.h"
#include <climits>
#include <algorithm>

MinHeap::MinHeap(int cap) {
    capacity = cap;
    size = cap;
    heapArray = new int[cap];
    keyArray = new int[cap];
    position = new int[cap];

    for (int v = 0; v < cap; ++v) {
        heapArray[v] = v;
        keyArray[v] = INT_MAX;
        position[v] = v;
    }
}

MinHeap::~MinHeap() {
    delete[] heapArray;
    delete[] keyArray;
    delete[] position;
}

void MinHeap::minHeapify(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
        smallest = left;
    if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
        smallest = right;

    if (smallest != index) {
        std::swap(heapArray[index], heapArray[smallest]);
        position[heapArray[index]] = index;
        position[heapArray[smallest]] = smallest;
        minHeapify(smallest);
    }
}

int MinHeap::extractMin() {
    if (size == 0)
        return -1;

    int root = heapArray[0];
    int lastNode = heapArray[size - 1];
    heapArray[0] = lastNode;

    position[root] = size - 1;
    position[lastNode] = 0;
    size--;
    minHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i > 0 && keyArray[heapArray[(i - 1) / 2]] > keyArray[heapArray[i]]) {
        std::swap(heapArray[i], heapArray[(i - 1) / 2]);
        position[heapArray[i]] = i;
        position[heapArray[(i - 1) / 2]] = (i - 1) / 2;
        i = (i - 1) / 2;
    }
}

bool MinHeap::isInMinHeap(int vertex) {
    return position[vertex] < size;
}

bool MinHeap::isEmpty() {
    return size == 0;
}
