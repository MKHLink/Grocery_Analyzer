//Linkhon Hasan
//6/23/2024
#include "Util.h"
#include <iostream>
#include <fstream>

using namespace std;

//function that reads from a file and maps the data 
map<string, Grocery> Util::readFile(string& filename) {
    ifstream inputFile(filename);

    map<string, Grocery> itemFrequency;
    string item;

    //goes through the file and increments frequency if item already present in the map
    if (inputFile.is_open()) {
        while (inputFile >> item) {
            if (itemFrequency.find(item) == itemFrequency.end()) {
                itemFrequency[item] = Grocery(item);
            }
            itemFrequency[item].addFrequency();
        }
        inputFile.close();
    }else {
        cout << "Invalid file" << endl;
    }
    return itemFrequency;
}

//Returns the frequency of one item based on user input
void Util::getOneFrequency(map<string, Grocery>& itemFrequency) {
    string input;

    cout << "Enter item name: ";
    cin >> input;
    cout << endl;

    //auto is a type inference that gets its type based of whatever it is set to
    auto foundItem = itemFrequency.find(input);

    if (foundItem != itemFrequency.end()) {
        cout<< input << ": "<< foundItem->second.getFrequency()<<endl;
        cout << endl;
    }else {
        cout << input << " not found." << endl;
    }
}

//prints the frequency of all the items in the file
void Util::printAll(map<string, Grocery>& itemFrequency) {
    for (auto& groceryItem : itemFrequency) {
        cout<< groceryItem.first<<" "<< groceryItem.second.getFrequency()<<endl;
        
    }
    cout << endl;
}

//prints a graph of all the items with *
void Util::printGraph(map<string, Grocery>& itemFrequency) {
    for (auto& groceryItem : itemFrequency) {
        cout << groceryItem.first << " ";

        for (int i = 0; i < groceryItem.second.getFrequency(); ++i) {
            cout << "*";
        }
        cout<<endl;
    }
    cout << endl;
}

//backs up the data in a .dat file
void Util::backupData(string& filename, map<string, Grocery>& itemFrequency) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (auto& groceryItem : itemFrequency) {
            outputFile << groceryItem.first << " " << groceryItem.second.getFrequency() << endl;
        }
        outputFile.close();
    }
}