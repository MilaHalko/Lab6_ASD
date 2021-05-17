#include "Libs.hpp"
#include "mainFunctions.hpp"

int main() {
    
    //SEQUENCE_CREATING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    string choice = "";
    
    vector<int> sequence;
    bool stop = false;
    
    while (!stop)
    {
        if (choice == "1"  ||  choice == "2"  ||  choice == "3"  ||  choice == "4")
        {
            if (choice == "1")          Randomly(sequence);
            else if (choice == "2")     Manually(sequence);
            else if (choice == "3")     RandomlyBest(sequence);
            else                        RandomlyWorst(sequence);
            stop = true;
        }
        else
        {
            cout << "Do you want to create sequence randomly(1), manually(2) or get the best(3) / worst(4) sequence? "; cin >> choice;
            cout << endl;
        }
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    ShellSort(sequence);
}
