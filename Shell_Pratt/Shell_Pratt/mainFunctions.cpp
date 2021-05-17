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
        sequence[i] = rand() % 1000;
    }
    
    int length = to_string(qua).size();                                                                                     //  1) ..
    for (int i = 0; i < qua; i++) cout << setw(to_string(qua).size()) << right << i+1 << ") " << sequence[i] << endl;       //  2) ..
    cout << endl;                                                                                                           // ..) ..
    
    cout << "<< ";
    for (int i = 0; i < qua - 1; i++) cout << sequence[i] << ", ";              // << .., .., ..>>
    cout << sequence[qua - 1] << " >>" << endl;
}


void RandomlyBest(vector<int> &sequence)
{
    unsigned int qua;  //quantity
    cout << "How many numbers the sequence will have? "; cin >> qua;
    cout << endl;
    
    sequence.resize(qua);
    for (int i = 0; i < qua; i++)
    {
        sequence[i] = i + 1;
    }
    
    int length = to_string(qua).size();                                                                                     //  1) ..
    for (int i = 0; i < qua; i++) cout << setw(to_string(qua).size()) << right << i+1 << ") " << sequence[i] << endl;       //  2) ..
    cout << endl;                                                                                                           // ..) ..
    
    cout << "<< ";
    for (int i = 0; i < qua - 1; i++) cout << sequence[i] << ", ";              // << .., .., ..>>
    cout << sequence[qua - 1] << " >>" << endl;
}

void RandomlyWorst(vector<int> &sequence)
{
    unsigned int qua;  //quantity
    cout << "How many numbers the sequence will have? "; cin >> qua;
    cout << endl;
    
    sequence.resize(qua);
    int counter = 0;
    for (int i = qua; i > 0; i--)
    {
        sequence[counter] = i;
        counter++;
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
    int unsigned compare = 0;
    int shuffle = 0;
    
    PrattSequence Pratt;
    Pratt.getPrattNums(sequence.size());
    
    for (int n = 0; n < Pratt.gaps.size(); n++)                          // changes gaps
    {
        for (int i = Pratt.gaps[n]; i < sequence.size(); i++)                          // first element (from 0 to gap's value)
        {
            int j;
            bool stop = false;
            for (j = i - Pratt.gaps[n]; j >= 0; j -= Pratt.gaps[n])
            {
                compare++;
                if (sequence[j] < sequence[i])
                {
                    stop = true;
                    break;
                }
            }
            
            j += Pratt.gaps[n];
            compare++;
            
            if (sequence[j] > sequence[i])
            {
                swap(sequence[i], sequence[j]);
                shuffle++;
            }
        }
    }
    
    cout << "<< ";
    for (int i = 0; i < sequence.size() - 1; i++) {
        cout << sequence[i] << ", ";
    }
    cout << sequence[sequence.size() - 1] << " >>" << endl;
    
    cout << "compare = " << compare << endl;
    cout << "shuffle = " << shuffle << endl;
}
