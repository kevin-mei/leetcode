#include "pch.h"

class Solution {
public:
    string truncateSentence(string s, int k) {
        int lastindex=0;
        for(int i=0;i < s.size();i++)
        {
            if(' ' == s[i])
                k--;
            if(0 == k)
            {
                lastindex = i;break;
            }   
        }
        if(k>0)
            return s;
        else
            return s.substr(0, lastindex);
    }
};