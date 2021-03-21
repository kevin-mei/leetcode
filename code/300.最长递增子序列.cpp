/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (48.33%)
 * Likes:    1455
 * Dislikes: 0
 * Total Accepted:    229.7K
 * Total Submissions: 475.3K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 
 * 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7]
 * 的子序列。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [10,9,2,5,3,7,101,18]
 * 输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,1,0,3,2,3]
 * 输出：4
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以设计时间复杂度为 O(n^2) 的解决方案吗？
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 * 
 * 
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // 题目要求的是： 最长递增子序列的长度
        // dp[i](i>=0)表示 以nums[i]结尾的的LIS的长度 
        // dp[i] 初始化为1， 递增子序列至少可以包含它自身
        // dp[i] = max{dp[0]+1, dp[1]+1,...dp[i-1]+1},其中集合里出现的元素须满足nums[j]<nums[i-1] 0<=j<i-1
        int n = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 1;
        int res = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i;j++)
            {
                if(nums[i] > nums[j])
                {
                    int temp = dp[j]+1;
                    if(temp > dp[i])
                        dp[i]= temp;
                }
            }
        }
        res = *max_element(dp.begin(), dp.end());
        return res;
    }
};

int main()
{
    vector<int> nums = {0,1,0,3,2,3};
    Solution sol;
    int res = sol.lengthOfLIS(nums);
    cout << res << endl;
}
// @lc code=end

