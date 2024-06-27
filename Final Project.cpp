//Linkhon Hasan
//6/23/2024
#include <iostream>
#include "Util.h"

using namespace std;

//main driver class
int main() {
    //importing pre-existing file
    string filename = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

    //maps the items using utility method into a map 
    map<string, Grocery> itemFrequency = Util::readFile(filename);
    int choice;

    //displays menu to user
    do {
        cout<<"1. Print one frequency\n";
        cout<<"2. Print all frequencies\n";
        cout<<"3. Print histogram\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        //input validation check
        if (cin.fail()) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input."<<endl;
            continue;  
        }

        //Options 1,2 and 3 makes use of static functions from the Util class
        switch(choice){
        case 1:
            Util::getOneFrequency(itemFrequency);
            break;
        case 2:
            Util::printAll(itemFrequency);
            break;
        case 3:
            Util::printGraph(itemFrequency);
            break;
        case 4:
            //writes the data in a .dat file upon user exiting
            Util::backupData(outputFileName, itemFrequency);
            break;
        default:
            cout<<"Invalid choice."<<endl;
            break;
        }
    }while(choice != 4);

    return 0;
}
