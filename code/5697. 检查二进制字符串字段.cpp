/*
给你一个二进制字符串 s ，该字符串 不含前导零 。

如果 s 最多包含 一个由连续的 '1' 组成的字段 ，返回 true​​​ 。否则，返回 false 
*/

#include "pch.h"

class Solution {
public:
    bool checkOnesSegment(string s) {
        // 连续的1只能有一个？
        int count = s.size();
        if(0 == count)
            return false;

        // 先检测连续的1
        bool isCon = true;
        char lastch = s[0];
        for(int i=1; i<count; i++)
        {
            if(lastch != s[i])
            {
                 for(int j=i; j<count; j++)
                {
                    if('1' == s[j])
                    {
                        isCon=false;
                        return isCon;
                    }
                }
                break;
            }
            lastch = s[i];
        }
        return isCon;
    }
};