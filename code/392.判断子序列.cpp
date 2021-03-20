/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start

#include "pch.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // 子序列是不改变相对位置 判断s是不是t的子序列
        // 每次找在t中找s[i]，并返回相对的位置，如果有一次没找到，则返回false
        bool res = true;
        int startoffset = 0;
        for(char ch : s)
        {
            int index = t.find(ch, startoffset); // 从startoffset开始，寻找t中是否有ch，有则返回对应的下标index
            if(-1 == index)
            {
                res = false;
                break;
            }
            startoffset = index+1; // 更新开始寻找的下标位置
        }

        return res;
    }
};
// @lc code=end

