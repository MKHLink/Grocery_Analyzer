//Linkhon Hasan
//6/23/2024
#include "Grocery.h"

//file contating constructors,getters for the Grocery header file, setters not needed for this application

Grocery::Grocery(const string& name, int frequency) : name(name), frequency(frequency) {}

//default constructor
Grocery::Grocery() : name(""), frequency(0) {}

string Grocery::getName() const {
    return name;
}

int Grocery::getFrequency() const {
    return frequency;
}

void Grocery::addFrequency() {
    frequency++;
}
