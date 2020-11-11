/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 循环数组 假设数组扩大两倍，然后对原数组的nums.size() 取余数
        // 其它的同496，单调栈完成
        std::stack<int> increaseStack;
        vector<int> res(nums.size()); // 先将res的大小初始化为nums的大小
        for (int i = nums.size() * 2 - 1; i >= 0; i--)
        {
            int realIndex = i % nums.size();
            while (!increaseStack.empty())
            {
                
                if(increaseStack.top() <= nums[realIndex] )
                {
                    increaseStack.pop();
                }else
                {
                    break; //说明找到了比nums[realIndex]大的元素
                }
            }
            int nextGreaterNum = increaseStack.empty() ? -1 : increaseStack.top();
            res[realIndex] = nextGreaterNum;
            // 不要忘了把当前元素入栈
            increaseStack.push(nums[realIndex]);
        }
        return res;
    }
};
// @lc code=end

