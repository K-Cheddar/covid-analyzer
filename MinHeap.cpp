#include "MinHeap.h"
#include <iostream>

using namespace std;

MinHeap::MinHeap() {
    // Default size
    size = 0;
    // Default capacity
    capacity = 50;
    // Array based heap
    arrayPtr = new Node [capacity];
}

// Parent of the index i is (i - 1) / 2.
int MinHeap::parent(int i) {
    return ((i - 1) / 2);
}

// Left child of the index i is (2 * i + 1).
int MinHeap::leftChild(int i) {
    return (2 * i + 1);
}

// Right child of the index i is (2 * i + 2).
int MinHeap::rightChild(int i) {
    return (2 * i + 2);
}

// Heapify function is called when ever the properties of the min heap is invalid.
void MinHeap::minHeapify(int i) {
    // Set left and right child for the index i, and set it to min.
    int left = leftChild(i);
    int right = rightChild(i);
    int min = i;

    // If min's left child is less than min, new min is the left child.
    if (left < size && arrayPtr[left].state < arrayPtr[min].state) {
        min = left;
    }
    // If min's right child is less than min, new min is the right child.
    if (right < size && arrayPtr[right].state < arrayPtr[min].state) {
        min = right;
    }
    // When the properties of the min heap is invalid.
    if (min != i) {
        // Set new min's value(Node) and recursively heapify the heap.
        Node temp = arrayPtr[i];
        arrayPtr[i] = arrayPtr[min];
        arrayPtr[min] = temp;

        minHeapify(min);
    }
}

// Insert a new Node into the array based min-heap.
void MinHeap::insert(Node newNode) {
    // If the heap is full
    if (size == capacity) {
        cout << "Min-Heap is full, cannot insert new node";
        return;
    }
    // Else

    // Assign new size for the heap and index for the node.
    size++;
    int i = size - 1;
    arrayPtr[i] = newNode;

    // While the newNode is not on top of the heap, and it is less than its parent, swap their position.
    while(i != 0 && arrayPtr[parent(i)].state > arrayPtr[i].state) {
        Node temp = arrayPtr[i];
        arrayPtr[i] = arrayPtr[parent(i)];
        arrayPtr[parent(i)] = temp;
        i = parent(i);
    }
}

// Print all the node in the heap by order, from min to max.
void MinHeap::printAll() {
    for (int i = 0; i < capacity; i++) {
        arrayPtr[i].printNode();
    }
}

// Search the min-heap through a state name and find the node that has that state's name.
// Return that node.
Node MinHeap::search(const string &state) {
    for (int i = 0; i < capacity; i++) {
        if (arrayPtr[i].state == state) {
            return arrayPtr[i];
        }
    }
    // If the Node we are searching for is not in the heap, return a newNode, empty node.
    return {};
}
