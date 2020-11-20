/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针，第一个指针从前往后找为0的数，第二个指针从后往前找不为0的数
        // 第一个指针i遇到零，就和第二个指针j交换对应位置上的数
        // 这样保证不了不为0的数的相对位置
        // 怎么能保证位置，找到0后，类似冒泡排序一样的操作，将i上的0依次交换至j处
        int i = 0, j=nums.size()-1;
        while (i < j)
        {
            // 这里的i,j只要合法就行， i,j的合法性在nums[i][j]之前访问， 短路求值，可以避免i，j越界访问
            while (i < nums.size() && 0 != nums[i])
            {
                i++;
            }
            while (j >= 0 && 0 == nums[j])
            {
                j--;
            }
            for (int m = i; m < j; m++) // 类似冒泡排序一样的操作，将i上的0依次交换至j处
            {
                swap(nums[m], nums[m + 1]);
            }
        }
    }
};

// int main()
// {
//     vector<int> nums = {2,1};
//     Solution sol;
//     sol.moveZeroes(nums);
//     std::cout << nums.size();
// }
// @lc code=end

