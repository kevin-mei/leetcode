#include "pch.h"

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(auto num : nums)
        {
            if(0 == num)
            {
                sign = 0;
                break;
            }else if(num >0)
            {
                sign=sign*1;
            }else if(num <0)
            {
                sign=sign*-1;
            }
            
        }
        return sign;
    }
};