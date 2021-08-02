#include "Node.h"

using namespace std;

Node::Node() {
    state = " ";
    confirmed = 0;
    deaths = 0;
    incidentRate = 0;
    fatalityRate = 0;
}
Node::Node(string _state, string _confirmed, string _deaths, string _incidentRate) {
    state = _state;
    confirmed = stol(_confirmed);
    deaths = stol(_deaths);

    if (_incidentRate == "" || _incidentRate == " ") {
        _incidentRate = "0";
    }
    incidentRate = stod(_incidentRate);

    fatalityRate = ((double)deaths / confirmed) * 100;
}

void Node::add(string _confirmed, string _deaths, string _incidentRate) {
    confirmed = confirmed + stol(_confirmed);
    deaths = deaths + stol(_deaths);

    if (_incidentRate == "" || _incidentRate == " ") {
        _incidentRate = "0";
    }
    incidentRate = (incidentRate + stod(_incidentRate)) / 2;

    fatalityRate = ((double)deaths / confirmed) * 100;
}

void Node::printNode() {
    cout << "State: " << state << endl;
    cout << "Confirmed: " << confirmed << endl;
    cout << "Deaths: " << deaths << endl;
    cout << "Incident Rate: " << incidentRate << endl;
    cout << "Fatality Rate: " << fatalityRate << "%" << endl;
    cout << endl;
}
