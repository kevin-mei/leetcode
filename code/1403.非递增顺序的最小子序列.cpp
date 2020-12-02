/*
 * @lc app=leetcode.cn id=1403 lang=cpp
 *
 * [1403] 非递增顺序的最小子序列
 */

// @lc code=start
#include "pch.h"
class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        // 最初的想法，给nums排序，然后从最大的开始，剔除最大的元素，剩余元素组成子序列A
        // 剔除的元素组成新的子序列B，判断B>A则停止，这时B一定是符合提议的最小子序列；
        // sort 默认是升序的，组成B序列的时候，每次是取最大的，依次从尾部插入B序列，B序列也就是降序的，符合题意
        std::sort(nums.begin(), nums.end());
        int sum_A = 0; // 剩余元素组成子序列A的综合 B默认为空
        for(int cur_num : nums)
            sum_A+=cur_num;
        vector<int> res;
        int sum_B = 0;
        // rbegin() 代表逆序的第一个数，也就是nums的最后一个元素，最大值，rend()是nums的第一个元素-1的位置
        for(auto iter = nums.rbegin(); iter != nums.rend(); iter++)
        {
            res.push_back(*iter);
            sum_B += *iter;
            sum_A -= *iter;
            if(sum_B > sum_A)
                break;
        }
        return res;
    }
};
// @lc code=end

