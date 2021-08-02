#include "Menu.h"

using namespace std;

set<string> Menu::States = {"Alabama", "Alaska", "Arizona", "Arkansas", "California",
                             "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
                             "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas",
                             "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts",
                             "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana",
                             "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico",
                             "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma",
                             "Oregon", "Pennsylvania", "Rhode Island", "South Carolina",
                             "South Dakota", "Tennessee", "Texas", "Utah", "Vermont",
                             "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming"};
map<string, string> Menu::StateAbbreviations = {{"AL", "Alabama"}, {"AK", "Alaska"}, {"AZ", "Arizona"}, {"AR", "Arkansas"}, {"CA", "California"},
                             {"CO", "Colorado"}, {"CT", "Connecticut"}, {"DE", "Delaware"}, {"FL", "Florida"}, {"GA", "Georgia"},
                             {"HI", "Hawaii"}, {"ID", "Idaho"}, {"IL", "Illinois"}, {"IN", "Indiana"}, {"IA", "Iowa"}, {"KA", "Kansas"},
                             {"KY", "Kentucky"}, {"LA", "Louisiana"}, {"ME", "Maine"}, {"MD", "Maryland"}, {"MA", "Massachusetts"},
                             {"MI", "Michigan"}, {"MN", "Minnesota"}, {"MS", "Mississippi"}, {"MO", "Missouri"}, {"MT", "Montana"},
                             {"NE", "Nebraska"}, {"NV", "Nevada"}, {"NH", "New Hampshire"}, {"NJ", "New Jersey"}, {"NM", "New Mexico"},
                             {"NY", "New York"}, {"NC", "North Carolina"}, {"ND", "North Dakota"}, {"OH", "Ohio"}, {"OK", "Oklahoma"},
                             {"OR", "Oregon"}, {"PA", "Pennsylvania"}, {"RI", "Rhode Island"}, {"SC", "South Carolina"},
                             {"SD", "South Dakota"}, {"TN", "Tennessee"}, {"TX", "Texas"}, {"UT", "Utah"}, {"VT", "Vermont"},
                             {"VA", "Virginia"}, {"WA", "Washington"}, {"WV", "West Virginia"}, {"WI", "Wisconsin"}, {"WY", "Wyoming"}};

int Menu::stoiWithCatch(string s) {
    try {return stoi(s);}
    catch(...) { return -1;}
}

int Menu::treeOrMap() {
    cout << endl;
    cout << "1. Tree Data Structure" << endl;
    cout << "2. Map Data Structure (under construction)" << endl;

    string input;
    int opt;
    cin >> input;
    opt = stoiWithCatch(input);

    switch (opt) {
        case 1: {
            return 0;
        }
        case 2: {
            return 1;
        }
        default: {
            cout << "Invalid input, please enter an integer 1 - 2." << endl;
            return treeOrMap();
        }
    }
}

void Menu::oneDay(StateTree _treeData[], string &_state, int &_choice) {
    cout << endl;
    cout << "Please enter a number (1 - 30) indicating the date" << endl;

    string input;
    cin >> input;
    int date = stoiWithCatch(input);

    if (1 <= date && date <= 30) {
        Node node;

        if (_choice == 0) {
            node = _treeData[date - 1].search(_state);
        }

        cout << "======================" << endl;
        cout << "By then end of June " + to_string(date) + ", " + _state + "'s" << endl;
        cout << endl;
        cout << "total confirmed cases is " + to_string(node.confirmed) << endl;
        cout << "total deaths count is " + to_string(node.deaths) << endl;
        cout << "incident Rate is " + to_string(node.incidentRate) + " in every 100,000 people" << endl;
        cout << "fatality Rate is " + to_string(node.fatalityRate) + "%" << endl;
        cout << "======================" << endl;
    }
    else {
        cout << "Invalid input, please enter an integer 1 - 30." << endl;
        oneDay(_treeData, _state, _choice);
    }


}

void Menu::segment(StateTree _treeData[], string &_state, int &_choice) {
    cout << endl;
    cout << "Please enter a set of numbers (1 - 30) indicating the start and end date seperated by comma" << endl;
    cout << "(ex: 3,18)" << endl;

    string input1;
    string input2;
    getline(cin, input1, ',');
    getline(cin, input2);

    int date1 = stoiWithCatch(input1);
    int date2 = stoiWithCatch(input2);

    if (1 <= date1 && date1 <= 30) {
        if (date1 == date2) {
            cout << "Invalid input, please enter two different dates" << endl;
            segment(_treeData, _state, _choice);
        }
        else if (date1 < date2 && date2 <= 30) {
            Node temp;
            Node node;

            if (_choice == 0) {
                temp = _treeData[date1 - 1].search(_state);
                node = _treeData[date2 - 1].search(_state);
            }

            cout << "======================" << endl;
            cout << "From June " + to_string(date1) + " to June " + to_string(date2) + ", " + _state + "'s" << endl;
            cout << endl;
            cout << to_string((node.confirmed - temp.confirmed)) + " people have been tested positive" << endl;
            cout << to_string((node.deaths - temp.deaths)) + " people have died from covid-19" << endl;
            cout << "incident Rate is " + to_string(node.incidentRate) + " in every 100,000 people" << endl;
            cout << "fatality Rate is " + to_string(node.fatalityRate) + " %" << endl;
            cout << "======================" << endl;
        }
        else {
            cout << "Invalid input, Please enter a set of numbers (1 - 30)" << endl;
            segment(_treeData, _state, _choice);
        }
    }
    else {
        cout << "Invalid input, Please enter a set of numbers (1 - 30)" << endl;
        segment(_treeData, _state, _choice);
    }
}

void Menu::wholeMonth(StateTree _treeData[], string &_state, int &_choice) {
    Node temp;
    Node node;
    if (_choice == 0) {
        temp = _treeData[0].search(_state);
        node = _treeData[29].search(_state);
    }

    cout << endl;
    cout << "Time Frame: Whole month" << endl;
    cout << "======================" << endl;
    cout << "By then end of June, 2021, " + _state + "'s" << endl;
    cout << endl;
    cout << "total confirmed cases is " + to_string(node.confirmed) << endl;
    cout << "total deaths count is " + to_string(node.deaths) << endl;
    cout << "incident Rate is " + to_string(node.incidentRate) + " in every 100,000 people" << endl;
    cout << "fatality Rate is " + to_string(node.fatalityRate) + "%" << endl;
    cout << endl;
    cout << to_string((node.confirmed - temp.confirmed)) + " people have been tested positive during June, 2021" << endl;
    cout << to_string((node.deaths - temp.deaths)) + " people have died from covid-19 during June, 2021" << endl;
    cout << "======================" << endl;
}

void Menu::timeFrame(StateTree _treeData[], string &_state) {
    cout << endl;
    cout << "Time Frame" << endl;
    cout << "======================" << endl;
    cout << "1. Whole month" << endl;
    cout << "2. Segment" << endl;
    cout << "3. One day" << endl;
    cout << "======================" << endl;

    string input;
    cin >> input;
    int opt = stoiWithCatch(input);
    int choice;

    switch (opt) {
        case 1: {
            choice = treeOrMap();
            wholeMonth(_treeData, _state, choice);
            break;
        }
        case 2: {
            choice = treeOrMap();
            segment(_treeData, _state, choice);
            break;
        }
        case 3: {
            choice = treeOrMap();
            oneDay(_treeData, _state, choice);
            break;
        }
        default: {
            cout << "Invalid input, please enter an integer 1 - 3." << endl;
            timeFrame(_treeData, _state);
        }
    }
}

void Menu::state(StateTree _treeData[]) {
    cout << endl;
    cout << "======================" << endl;
    cout << "Please tell us which State's data you would love to know" << endl;
    cout << "For example: Florida or FL" << endl;
    cout << endl;
    cout << "OR enter 'USA' for complete nationwide data" << endl;
    cout << "======================" << endl;

    string input;
    cin >> input;

    if (input.length() == 2) {
        input[0] = toupper(input[0]);
        input[1] = toupper(input[1]);
        input = StateAbbreviations[input];
    }
//    if (input == "USA") {
//        allData(_treeData);
//    }
    if (Menu::States.find(input) != Menu::States.end()) {
        timeFrame(_treeData, input);
    }
    else {
        cout << "Could not find the State or Country you are looking for, please enter again" << endl;
        state(_treeData);
    }


}

void Menu::allData(StateTree _treeData[]) {
    // TODO: Print all node from all tree and map, and report the time it took to execute
    for (int i = 0; i < 30; i++) {
        cout << "June " + to_string(i + 1) + ", 2021" << endl;
        _treeData[i].printAll();
    }
}

void Menu::mainMenu(StateTree _treeData[]) {
    cout << "Covid-19 Data Analyzer" << endl;
    cout << "======================" << endl;
    cout << "1. Get Specific Data" << endl;
    cout << "2. All Data" << endl;
    cout << "3. Exit" << endl;
    cout << "======================" << endl;

    string input;
    cin >> input;
    int opt = stoiWithCatch(input);

    switch (opt) {
        case 1: {
            state(_treeData);
            break;
        }
        case 2: {
            allData(_treeData);
            break;
        }
        case 3: {
            exit(0);
        }
        default: {
            cout << "Invalid input, please enter an integer 1 - 3." << endl;
            mainMenu(_treeData);
        }
    }
}
