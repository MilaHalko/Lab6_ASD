#include "Libs.hpp"
#include "mainFunctions.hpp"

int main() {
    /*
    //SEQUENCE_CREATING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    
    int choice;
    cout << "Do you want to create sequence randomly(1) or manually(2)? "; cin >> choice;
    cout << endl;
    
    vector<int> sequence;
    switch (choice) {
        case 1:
            Randomly(sequence);
            break;
            
        case 2:
            Manually(sequence);
            break;
            
        default:
            cout << "You wrote wrong symbol!" << endl;
            exit(0);
    }
    
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    */
    //ShellSort(sequence);
    PrattSequence Pratt;
    Pratt.getPrattNums(200);
    for (int i = 0; i < Pratt.nums.size(); i++) {
        cout << Pratt.nums[i] << "  ";
    }
    cout << endl;
}
