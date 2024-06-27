//Linkhon Hasan
//6/23/2024
#ifndef UTIL_H
#define UTIL_H

#include <map>
#include <string>
#include "Grocery.h"

using namespace std;

//Header file for the utility function
namespace Util {

    map<string, Grocery> readFile(string& filename);
    void getOneFrequency(map<string, Grocery>& itemFrequency);
    void printAll(map<string, Grocery>& itemFrequency);
    void printGraph(map<string, Grocery>& itemFrequency);
    void backupData(string& filename, map<string, Grocery>& itemFrequency);
};

#endif 
