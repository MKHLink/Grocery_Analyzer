//Linkhon Hasan
//6/23/2024
#ifndef GROCERY_H
#define GROCERY_H

#include <string>

using namespace std;

//grocery class that holds name and frequency of each item
class Grocery {
private:
    string name;
    int frequency;

public:
    Grocery();
    Grocery(const string& name, int frequency = 0);
    string getName() const;
    int getFrequency() const;
    void addFrequency();
};

#endif
