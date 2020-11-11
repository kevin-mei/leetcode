/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 还是单调栈吧，nums1是nums2的子集，nums1.size() <= nums2.size()

        // 可以把nums2中的每个元素的nextGreater数先算出来，和对应元素存储为map，
        // 由于没有重复元素，所以key-value是唯一的
        // 然后根据nums1出现的顺序，找出对应的value，组成结果vector

        // 单调栈用来干什么， 从最后一个元素开始遍历，如果栈为空，则比它大的元素为-1（没找到）
        // 如果栈不为空，比对当前num和栈顶元素的大小，比它小，则弹栈，直到找到比它大的元素，就是栈顶元素
        std::stack<int> increaseStack;
        std::unordered_map<int, int> key_Greater_map;
        for(int i = nums2.size()-1; i>=0;i--)
        {
            while(!increaseStack.empty())
            {
                if(increaseStack.top() <= nums2[i] )
                {
                    increaseStack.pop();
                }else
                {
                    break; //说明找到了比nums2大的元素
                }
                
            }
            int nextGreaterNum  = increaseStack.empty()?-1:increaseStack.top();
            // 题目说nums不包含重复元素，这里可以不用判断map是否已有此元素，不担心覆盖问题
            key_Greater_map[nums2[i]] = nextGreaterNum;
            // 不要忘了把当前元素入栈
            increaseStack.push(nums2[i]);
        }
        vector<int> res;
        for(int curNum : nums1)
        {
            res.push_back(key_Greater_map[curNum]);
        }
        return res;
    }
};

// int main()
// {
//     vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
//     Solution sol;
//     vector<int> res = sol.nextGreaterElement(nums1, nums2);
//     cout << res.size();
//     return 0;

// }

// @lc code=end

