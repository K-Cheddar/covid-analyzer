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
    Node(string _state, const string& _confirmed, const string& _deaths, string _incidentRate);

    void add(const string& _confirmed, const string& _deaths, string _incidentRate);
    void printNode() const;
};