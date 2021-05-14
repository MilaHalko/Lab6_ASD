#include "mainFunctions.hpp"

void Randomly(vector<int> &sequence)
{
    unsigned int qua;  //quantity
    cout << "How many numbers the sequence will have? "; cin >> qua;
    cout << endl;
    
    sequence.resize(qua);
    srand(time(0));
    for (int i = 0; i < qua; i++)
    {
        sequence[i] = rand() % 100;
    }
    
    int length = to_string(qua).size();                                                                                     //  1) ..
    for (int i = 0; i < qua; i++) cout << setw(to_string(qua).size()) << right << i+1 << ") " << sequence[i] << endl;       //  2) ..
    cout << endl;                                                                                                           // ..) ..
    
    cout << "<< ";
    for (int i = 0; i < qua - 1; i++) cout << sequence[i] << ", ";              // << .., .., ..>>
    cout << sequence[qua - 1] << " >>" << endl;
}


void Manually(vector<int> &sequence){
    
    sequence.resize(0);
    string str;
    int counter = 1;
    
    cout << "If you want to stop write anything instead of number:" << endl;
    
    while (true)
    {
        cout << counter << ") "; cin >> str;
        
        bool isNum = true;
        for (int i = 0; i < str.size(); i++)
        if (!isnumber(str[i])) isNum = false;
        
        
        if (isNum == true)
        {
            sequence.push_back(stoi(str));
            counter++;
            str = "";
        }
        else
        {
            cin.ignore();
            break;
        }
    }
    
    cout << "<< ";
    for (int i = 0; i < sequence.size() - 1; i++) cout << sequence[i] << ", ";              // << .., .., ..>>
    cout << sequence[sequence.size() - 1] << " >>" << endl;
}


void ShellSort(vector<int> &sequence)
{
    PrattSequence Pratt;
    Pratt.getPrattNums(sequence.size());
    
    vector<int> subVector;
    subVector.resize(0);
    
    for (int n = 0; n < Pratt.gaps.size(); n++)                          // changes gaps
    {
        for (int i = 0; i < Pratt.gaps[n]; i++)                          // first element (from 0 to gap's value)
        {
            for (int j = 0; j < sequence.size(); j += Pratt.gaps[n])     // take every d element (d = gap's value)
                subVector.insert(subVector.begin(), sequence[j]);
            
            SortSubVector(subVector);                                   // subVector sorting
            
            int counter = 0;
            for (int j = 0; j < sequence.size(); j += Pratt.gaps[n])     // sequence upgrading
            {
                sequence[j] = subVector[counter];
                counter++;
            }
            subVector.clear();
        }
    }
    
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << "  ";
    }
    cout << endl;
}


void SortSubVector(vector<int> &subVector)
{
    int minInd;
    
    for (int i = 0; i < subVector.size() - 1; i++)                  // index for the minimum element
    {
        minInd = i;
        
        for (int j = i + 1; j < subVector.size(); j++)
        {
            if (subVector[minInd] > subVector[j])   minInd = j;
        }
        
        if (minInd != i)   swap(subVector[i], subVector[minInd]);
    }
}
