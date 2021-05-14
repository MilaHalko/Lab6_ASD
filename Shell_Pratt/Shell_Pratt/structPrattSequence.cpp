#include "structPrattSequence.hpp"


void PrattSequence::getPrattNums(int size)  // 2i 3j <= n/2
{
    gaps.resize(0);
    gaps.push_back(1);
    
    bool addedNew = true;
    int min;
    
    while (addedNew) {
        
        addedNew = false;
        min = -1;
        
        for (int i = 0; i < gaps.size(); i++)                                                 // check all already added nums
        {
            for (int multiplier = 2; multiplier <= 3; multiplier++)                            // multipliers 2 and 3 for Pratt sequence
            {
                if (gaps[i] * multiplier <= size/2  &&  gaps[i] * multiplier > gaps[gaps.size() - 1])      // d <= size/2     &&     next num > last added num
                {
                    if (min == -1  ||  min > gaps[i] * multiplier)
                    {
                        min = gaps[i] * multiplier;
                    }
                }
            }
        }
        if (min != -1) {
            addedNew = true;
            gaps.push_back(min);
        }
    }
    reverse(gaps.begin(), gaps.end());
}

