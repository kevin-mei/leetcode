/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    bool isPalindrome_1(int x) {
        // 回文数 左右指针  负数一定不是回文数，有负号
        if(x < 0)
            return false;
        if(0 == x)
            return true;
        // 整数需要先存成数组  不让使用字符串，就求余数，整成数组
        vector<int> nums;
        while(0 != x/10 || 0 != x%10)
        {
            nums.push_back(x%10);
            x =  x/10;
        }

        for(auto iter_1 = nums.begin(),iter_2 = nums.end()-1;iter_1 <= iter_2;iter_1++,iter_2--)
        {
            if(*iter_1 != *iter_2)
            {
                return false;
            }
        }
        return true;

    }

    bool isPalindrome(int x) {
        // 回文数 左右指针  负数一定不是回文数，有负号
        if(x < 0)
            return false;
        if(0 == x)
            return true;
        // 整数需要先存成数组  使用字符串
        string nums = std::to_string(x);

        for(auto iter_1 = nums.begin(),iter_2 = nums.end()-1;iter_1 <= iter_2;iter_1++,iter_2--)
        {
            if(*iter_1 != *iter_2)
            {
                return false;
            }
        }
        return true;

    }
};

// int main()
// {
//     int x =121;
//     Solution sol;
//     bool res = sol.isPalindrome(x);
//     std::cout << res << std::endl;
// }
// @lc code=end

