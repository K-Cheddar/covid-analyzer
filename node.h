#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string state;
    long confirmed;
    long deaths;
    double incidentRate;
    double fatalityRate;

    Node();
    Node(string _state, string _confirmed, string _deaths, string _incidentRate);

    void add(string _confirmed, string _deaths, string _incidentRate);
    void printNode();
};
