/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    char findTheDifference(string s, string t) {
        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());
        int length = s.size();
        char res  = t[length]; //  t[length]为t的最后一个元素
        for(int i = 0; i != length; i++)
        {
            if(s[i] != t[i])
            {
                res = t[i];
                break;
            }
                
        }
        return res;
    }
};
// @lc code=end

