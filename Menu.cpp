#include "Menu.h"
#include <chrono>

using namespace std;

// All the States name in the USA.
set<string> Menu::States = {"Alabama", "Alaska", "Arizona", "Arkansas", "California",
                             "Colorado", "Connecticut", "Delaware", "Florida", "Georgia",
                             "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas",
                             "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts",
                             "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana",
                             "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico",
                             "New York", "North Carolina", "North Dakota", "Ohio Oklahoma",
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

// Return number according to users choice, if user choose Tree, return 0,
// if user choose Heap, return 1.
int Menu::treeOrHeap() {
    cout << endl;
    cout << "1. Tree Data Structure" << endl;
    cout << "2. Min-Heap Data Structure" << endl;

    string input;
    cin >> input;

    // If the input is not a number.
    if (!isdigit(input.front())) {
        cout << "Invalid input, please enter an integer 1 - 2." << endl;
        return treeOrHeap();
    }
    else {
        int opt;
        opt = stoi(input);

        switch (opt) {
            case 1: {
                return 0;
            }
            case 2: {
                return 1;
            }
            // Invalid input
            default: {
                cout << "Invalid input, please enter an integer 1 - 2." << endl;
                return treeOrHeap();
            }
        }
    }
}

// Function that takes in the state's name and the data structure choice,
// Base on users input, prints out the data for that day.
void Menu::oneDay(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice) {
    cout << endl;
    cout << "Please enter a number (1 - 30) indicating the date" << endl;

    string input;
    cin >> input;

    // If the input is not a number.
    if (!isdigit(input.front())) {
        cout << "Invalid input, please enter an integer 1 - 30." << endl;
        oneDay(_treeData, _heapData, _state, _choice);
    }
    else {
        int date = stoi(input);

        // If the input is a valid date
        if (1 <= date && date <= 30) {
            Node node;

            // If the user choose USA data and choose Tree.
            if (_state == "USA" && _choice == 0) {
                // Start measuring time
                auto begin = chrono::high_resolution_clock::now();

                // Print out every data for that day from treeData[].
                cout << "June " + to_string(date) + ", 2021" << endl;
                _treeData[date - 1].printAll();

                // Stop measuring time and calculate the elapsed time
                auto end = chrono::high_resolution_clock::now();
                auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                // Printing the measured time
                printf("Time measured for Tree: %.5f seconds.\n", elapsed.count() * 1e-9);
                Menu::mainMenu(_treeData, _heapData);
            }
            // If the user choose USA data and choose Heap.
            else if (_state == "USA" && _choice == 1) {
                // Start measuring time
                auto begin = chrono::high_resolution_clock::now();

                // Print out every data for that day from treeData[]
                cout << "June " + to_string(date) + ", 2021" << endl;
                _heapData[date - 1].printAll();

                // Stop measuring time and calculate the elapsed time
                auto end = chrono::high_resolution_clock::now();
                auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                // Printing the measured time
                printf("Time measured for Heap: %.5f seconds.\n", elapsed.count() * 1e-9);
                Menu::mainMenu(_treeData, _heapData);
            }
            // If the choice wasn't USA, then access the state's data.
            else {
                // Start measuring time
                auto begin = chrono::high_resolution_clock::now();

                // If user choose Tree
                if (_choice == 0) {
                    node = _treeData[date - 1].search(_state);
                }
                // If user choose Heap
                if (_choice == 1) {
                    node = _heapData[date - 1].search(_state);
                }

                cout << "======================" << endl;
                cout << "By then end of June " + to_string(date) + ", " + _state + "'s" << endl;
                cout << endl;
                cout << "total confirmed cases is " + to_string(node.confirmed) << endl;
                cout << "total deaths count is " + to_string(node.deaths) << endl;
                cout << "incident Rate is " + to_string(node.incidentRate) + " in every 100,000 people" << endl;
                cout << "fatality Rate is " + to_string(node.fatalityRate) + "%" << endl;
                cout << "======================" << endl;

                // Stop measuring time and calculate the elapsed time
                auto end = chrono::high_resolution_clock::now();
                auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                // Printing the measured time
                printf("Time measured: %.5f seconds.\n", elapsed.count() * 1e-9);
                Menu::mainMenu(_treeData, _heapData);
            }
        }
        // Invalid input
        else {
            cout << "Invalid input, please enter an integer 1 - 30." << endl;
            oneDay(_treeData, _heapData, _state, _choice);
        }
    }
}

// Function that takes in the state's name and the data structure choice,
// Base on users input, prints out the data for that period of time.
void Menu::segment(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice) {
    cout << endl;
    cout << "Please enter a set of numbers (1 - 30) indicating the start and end date seperated by comma" << endl;
    cout << "(ex: 3,18)" << endl;

    string input1;
    string input2;
    getline(cin, input1, ',');
    getline(cin, input2);

    // If the inputs are not numbers.
    if (!isdigit(input1.front()) || !isdigit(input2.front())) {
        cout << "Invalid input, please enter integers" << endl;
        segment(_treeData, _heapData, _state, _choice);
    }
    else {
        int date1 = stoi(input1);
        int date2 = stoi(input2);

        // If the first input is a valid date
        if (1 <= date1 && date1 <= 30) {
            // If the second input is same as the first one, Invalid
            if (date1 == date2) {
                cout << "Invalid input, Please enter a set of numbers (1 - 30)" << endl;
                segment(_treeData, _heapData, _state, _choice);
            }
            // If the second input is a valid date
            else if (date1 < date2 && date2 <= 30) {
                Node temp;
                Node node;

                // If the user choose USA data and choose Tree.
                if (_state == "USA" && _choice == 0) {
                    // Start measuring time
                    auto begin = chrono::high_resolution_clock::now();

                    // Print every state's data from date 1 to date 2.
                    for (int i = date1; i <= date2; i++) {
                        cout << "June " + to_string(i) + ", 2021" << endl;
                        _treeData[i - 1].printAll();
                    }

                    // Stop measuring time and calculate the elapsed time
                    auto end = chrono::high_resolution_clock::now();
                    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                    // Printing the measured time
                    printf("Time measured for Tree: %.5f seconds.\n", elapsed.count() * 1e-9);
                    Menu::mainMenu(_treeData, _heapData);
                }
                // If the user choose USA data and choose Heap.
                else if (_state == "USA" && _choice == 1) {
                    // Start measuring time
                    auto begin = chrono::high_resolution_clock::now();

                    // Print every state's data from date 1 to date 2.
                    for (int i = date1; i <= date2; i++) {
                        cout << "June " + to_string(i) + ", 2021" << endl;
                        _heapData[i - 1].printAll();
                    }

                    // Stop measuring time and calculate the elapsed time
                    auto end = chrono::high_resolution_clock::now();
                    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                    // Printing the measured time
                    printf("Time measured for Heap: %.5f seconds.\n", elapsed.count() * 1e-9);
                    Menu::mainMenu(_treeData, _heapData);
                }
                // If the choice wasn't USA, then access the state's data.
                else {
                    // Start measuring time
                    auto begin = chrono::high_resolution_clock::now();

                    // If user choose Tree
                    if (_choice == 0) {
                        temp = _treeData[date1 - 1].search(_state);
                        node = _treeData[date2 - 1].search(_state);
                    }
                    // IF user choose Heap
                    if (_choice == 1) {
                        temp = _heapData[date1 - 1].search(_state);
                        node = _heapData[date2 - 1].search(_state);
                    }

                    cout << "======================" << endl;
                    cout << "From June " + to_string(date1) + " to June " + to_string(date2) + ", " + _state + "'s" << endl;
                    cout << endl;
                    cout << to_string((node.confirmed - temp.confirmed)) + " people have been tested positive" << endl;
                    cout << to_string((node.deaths - temp.deaths)) + " people have died from covid-19" << endl;
                    cout << "incident Rate is " + to_string(node.incidentRate) + " in every 100,000 people" << endl;
                    cout << "fatality Rate is " + to_string(node.fatalityRate) + " %" << endl;
                    cout << "======================" << endl;

                    // Stop measuring time and calculate the elapsed time
                    auto end = chrono::high_resolution_clock::now();
                    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
                    // Printing the measured time
                    printf("Time measured: %.5f seconds.\n", elapsed.count() * 1e-9);
                    Menu::mainMenu(_treeData, _heapData);
                }
            }
            // Invalid input
            else {
                cout << "Invalid input, Please enter a set of numbers (1 - 30)" << endl;
                segment(_treeData, _heapData, _state, _choice);
            }
        }
        // Invalid input
        else {
            cout << "Invalid input, Please enter a set of numbers (1 - 30)" << endl;
            segment(_treeData, _heapData, _state, _choice);
        }
    }
}

// Function that takes in the state's name and the data structure choice,
// Base on users input, prints out the data for that month.
void Menu::wholeMonth(StateTree _treeData[], MinHeap _heapData[], string &_state, int &_choice) {
    Node temp;
    Node node;

    // If the user choose USA data and choose Tree.
    if (_state == "USA" && _choice == 0) {
        // Start measuring time
        auto begin = chrono::high_resolution_clock::now();

        // Print out every state's data for the whole month.
        for (int i = 0; i < 30; i++) {
            cout << "June " + to_string(i + 1) + ", 2021" << endl;
            _treeData[i].printAll();
        }

        // Stop measuring time and calculate the elapsed time
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // Printing the measured time
        printf("Time measured for Tree: %.5f seconds.\n", elapsed.count() * 1e-9);
        Menu::mainMenu(_treeData, _heapData);
    }
    // If the user choose USA data and choose Heap.
    else if (_state == "USA" && _choice == 1) {
        // Start measuring time
        auto begin = chrono::high_resolution_clock::now();

        // Print out every state's data for the whole month.
        for (int i = 0; i < 30; i++) {
            cout << "June " + to_string(i + 1) + ", 2021" << endl;
            _heapData[i].printAll();
        }

        // Stop measuring time and calculate the elapsed time
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // Printing the measured time
        printf("Time measured for Heap: %.5f seconds.\n", elapsed.count() * 1e-9);
        Menu::mainMenu(_treeData, _heapData);
    }
    // If the choice wasn't USA, then access the state's data.
    else {
        // Start measuring time
        auto begin = chrono::high_resolution_clock::now();

        // If user choose Tree
        if (_choice == 0) {
            temp = _treeData[0].search(_state);
            node = _treeData[29].search(_state);
        }
        // If user choose Heap
        if (_choice == 1) {
            temp = _heapData[0].search(_state);
            node = _heapData[29].search(_state);
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

        // Stop measuring time and calculate the elapsed time
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // Printing the measured time
        printf("Time measured: %.5f seconds.\n", elapsed.count() * 1e-9);
        Menu::mainMenu(_treeData, _heapData);
    }
}

// Function that calls the 3 functions above according to user's input.
void Menu::timeFrame(StateTree _treeData[], MinHeap _heapData[], string &_state) {
    cout << endl;
    cout << "Time Frame" << endl;
    cout << "======================" << endl;
    cout << "1. Whole month" << endl;
    cout << "2. Segment" << endl;
    cout << "3. One day" << endl;
    cout << "======================" << endl;

    string input;
    cin >> input;

    // If the input is not a number.
    if (!isdigit(input.front())) {
        cout << "Invalid input, please enter an integer 1 - 3." << endl;
        timeFrame(_treeData, _heapData, _state);
    }
    else {
        int opt = stoi(input);
        int choice;

        switch (opt) {
            case 1: {
                choice = treeOrHeap();
                wholeMonth(_treeData, _heapData, _state, choice);
                break;
            }
            case 2: {
                choice = treeOrHeap();

                // This getline() is only here for bug fixing purposes.
                string trashLine;
                getline(cin, trashLine);

                segment(_treeData, _heapData, _state, choice);
                break;
            }
            case 3: {
                choice = treeOrHeap();
                oneDay(_treeData, _heapData, _state, choice);
                break;
            }
            // Invalid input
            default: {
                cout << "Invalid input, please enter an integer 1 - 3." << endl;
                timeFrame(_treeData, _heapData, _state);
            }
        }
    }
}

// Function that asks which state's data user would like to access and calls timeFrame().
void Menu::state(StateTree _treeData[], MinHeap _heapData[]) {
    cout << endl;
    cout << "State" << endl;
    cout << "======================" << endl;
    cout << "Please tell us which State's data you would love to know" << endl;
    cout << "For example: Florida" << endl;
    cout << endl;
    cout << "Enter 'USA' for complete nationwide data" << endl;
    cout << "======================" << endl;

    string stateName;
    getline(cin, stateName);

    // State Abbreviation registration.
    if (stateName.length() == 2) {
        stateName[0] = toupper(stateName[0]);
        stateName[1] = toupper(stateName[1]);
        stateName = StateAbbreviations[stateName];
    }
    // State Full name registration.
    if (Menu::States.find(stateName) != Menu::States.end() || stateName == "USA") {
        timeFrame(_treeData, _heapData, stateName);
    }
    // If user's input is not one of the States in the US, or is not "USA".
    else {
        cout << "Could not find the State or Country you are looking for, please enter again" << endl;
        state(_treeData, _heapData);
    }
}

// Print all node from all tree and heap, and report the time it took to execute.
void Menu::allData(StateTree _treeData[], MinHeap _heapData[], int &_choice) {
    // If user choose Tree.
    if (_choice == 0) {
        // Start measuring time
        auto begin = chrono::high_resolution_clock::now();

        for (int i = 0; i < 30; i++) {
            cout << "June " + to_string(i + 1) + ", 2021" << endl;
            _treeData[i].printAll();
        }

        // Stop measuring time and calculate the elapsed time
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // Printing the measured time
        printf("Time measured for Tree: %.5f seconds.\n", elapsed.count() * 1e-9);
        Menu::mainMenu(_treeData, _heapData);
    }
    // If user choose Heap
    else if (_choice == 1) {
        // Start measuring time
        auto begin = chrono::high_resolution_clock::now();

        for (int i = 0; i < 30; i++) {
            cout << "June " + to_string(i + 1) + ", 2021" << endl;
            _heapData[i].printAll();
        }

        // Stop measuring time and calculate the elapsed time
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        // Printing the measured time
        printf("Time measured for Heap: %.5f seconds.\n", elapsed.count() * 1e-9);
        Menu::mainMenu(_treeData, _heapData);
    }
}

// Main Menu interface.
void Menu::mainMenu(StateTree _treeData[], MinHeap _heapData[]) {
    cout << endl;
    cout << "Covid-19 Data Analyzer" << endl;
    cout << "======================" << endl;
    cout << "1. Continue" << endl;
    cout << "2. All Data" << endl;
    cout << "3. Exit" << endl;
    cout << "======================" << endl;

    string input;
    cin >> input;

    // If the input is not a number.
    if (!isdigit(input.front())) {
        cout << "Invalid input, please enter an integer 1 - 3." << endl;
        mainMenu(_treeData, _heapData);
    }
    else {
        int opt = stoi(input);

        switch (opt) {
            // Continue
            case 1: {
                // This getline() is only here for bug fixing purposes.
                string trashLine;
                getline(cin, trashLine);

                state(_treeData, _heapData);
                break;
            }
            // All Data
            case 2: {
                // Choose a data structure
                int choice = treeOrHeap();
                allData(_treeData, _heapData, choice);
                break;
            }

            // Terminate the program
            case 3: {
                exit(0);
            }
            // Invalid input
            default: {
                cout << "Invalid input, please enter an integer 1 - 3." << endl;
                mainMenu(_treeData, _heapData);
            }
        }
    }
}