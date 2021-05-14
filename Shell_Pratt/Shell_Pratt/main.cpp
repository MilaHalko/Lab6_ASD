#include "Libs.hpp"
#include "mainFunctions.hpp"

int main() {
    
    //SEQUENCE_CREATING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    string choice = "";
    
    vector<int> sequence;
    
    while (true)
    {
        if (choice == "1"  ||  choice == "2")
        {
            if (choice == "1") Randomly(sequence);
            else               Manually(sequence);
            break;
        }
        else
        {
            cout << "Do you want to create sequence randomly(1) or manually(2)? "; cin >> choice;
            cout << endl;
        }
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ShellSort(sequence);
}
