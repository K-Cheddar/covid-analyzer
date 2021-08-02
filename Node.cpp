#include "Node.h"

using namespace std;

// Default constructor
Node::Node() {
    state = " ";
    confirmed = 0;
    deaths = 0;
    incidentRate = 0;
    fatalityRate = 0;
}

// Construct that gets the 4 different data within .csv files and create a new node object
Node::Node(string _state, const string& _confirmed, const string& _deaths, string _incidentRate) {
    state = _state;
    confirmed = stol(_confirmed);
    deaths = stol(_deaths);

    if (_incidentRate == "" || _incidentRate == " ") {
        _incidentRate = "0";
    }
    incidentRate = stod(_incidentRate);

    fatalityRate = ((double)deaths / confirmed) * 100;
}

// Add the 4 different data within .csv files to an existing node object.
void Node::add(const string& _confirmed, const string& _deaths, string _incidentRate) {
    confirmed = confirmed + stol(_confirmed);
    deaths = deaths + stol(_deaths);

    if (_incidentRate == "" || _incidentRate == " ") {
        _incidentRate = "0";
    }
    incidentRate = (incidentRate + stod(_incidentRate)) / 2;

    fatalityRate = ((double)deaths / confirmed) * 100;
}

// Print the node object
void Node::printNode() const {
    cout << "State: " << state << endl;
    cout << "Confirmed: " << confirmed << endl;
    cout << "Deaths: " << deaths << endl;
    cout << "Incident Rate: " << incidentRate << endl;
    cout << "Fatality Rate: " << fatalityRate << "%" << endl;
    cout << endl;
}