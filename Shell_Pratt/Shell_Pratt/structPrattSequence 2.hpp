#pragma once
#include "Libs.hpp"

struct PrattSequence
{
    vector<int> nums;
    void getPrattNums(int size);
};


void PrattSequence::getPrattNums(int size)  // 2i 3j <= n/2
{
    nums.resize(1);
    nums.push_back(1);
    nums.erase(nums.begin());
    
    bool addedNew = true;
    int min;
    
    while (addedNew) {
        
        addedNew = false;
        min = -1;
        
        for (int i = 0; i < nums.size(); i++)                                                 // check all already added nums
        {
            for (int multiplier = 2; multiplier <=3; multiplier++)                            // multipliers 2 and 3 for Pratt sequence
            {
                if (nums[i] * multiplier <= size/2  &&  nums[i] * multiplier > nums[-1])      // d <= size/2     &&     next num > last added num
                {
                    if (min == -1  ||  min > nums[i] * multiplier)
                    {
                        min = nums[i] * multiplier;
                    }
                }
            }
        }
        if (min != -1) {
            addedNew = true;
            nums.push_back(min);
        }
    }
}
