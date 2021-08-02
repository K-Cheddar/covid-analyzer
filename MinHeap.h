#pragma once
#include "Node.h"

using namespace std;

class MinHeap {
    Node* arrayPtr;
    int capacity;
    int size;

public:
    MinHeap();
    static int parent(int i);
    static int leftChild(int i);
    static int rightChild(int i);
    void minHeapify(int i);
    void insert(Node newNode);
    Node search(const string &state);
    void printAll();
};