#pragma once
#include <string>
#include <set>
#include <iostream>
#include "Node.h"
#include "StateTree.h"
#include "MinHeap.h"
#include <map>

using namespace std;

class Menu {
private:
    static set<string> States;
    static map <string, string> StateAbbreviations;

public:
    static int treeOrHeap();
    static void oneDay(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice);
    static void segment(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice);
    static void wholeMonth(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice);
    static void timeFrame(StateTree _treeData[], MinHeap _heapData[], string &_state);
    static void state(StateTree _treeData[], MinHeap _heapData[]);
    static void allData(StateTree _treeData[], MinHeap _heapData[], int &_choice);
    static void mainMenu(StateTree _treeData[], MinHeap _heapData[]);
};