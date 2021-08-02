#pragma once
#include <string>
#include <set>
#include <map>
#include <iostream>
#include "Node.h"
#include "StateTree.h"

using namespace std;

class Menu {
private:
    static set<string> States;
    static map<string, string> StateAbbreviations;
public:
    static int treeOrMap();
    static void oneDay(StateTree _treeData[], string &_state, int &_choice);
    static void segment(StateTree _treeData[], string &_state, int &_choice);
    static void wholeMonth(StateTree _treeData[], string &_state, int &_choice);
    static void timeFrame(StateTree _treeData[], string &_state);
    static void state(StateTree _treeData[]);
    static void allData(StateTree _treeData[]);
    static void mainMenu(StateTree _treeData[]);
    static int stoiWithCatch(string s);
};
