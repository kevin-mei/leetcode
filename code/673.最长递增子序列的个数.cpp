/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 *
 * https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (36.29%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 39.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未排序的整数数组，找到最长递增子序列的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 2
 * 解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 5
 * 解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
 * 
 * 
 * 注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 * 
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 定义两个一维数组 dp[n] counts[n]
        // dp[i] 代表以nums[i]结尾的LIS的长度
        // counts[i] 代表以nums[i]结尾的LIS的数量 (它的计算)
        // 两层for循环，讲道理 假设 nums[i] 最长长度为3，它的组合数为2
        // 应该找到a 属于[0, i-1]中，nums[a] < nums[i]，且 dp[a] == 2，
        // count[i] = sum(counts[a]);
        // 如何预先知道最长长度为3呢，最长长度应该怎么算？
        // a 属于[0, i-1]中，nums[a] < nums[i],在IS{...nums[a],nums[i]}中，dp[i]=dp[a]+1
        // 这里dp要找最大的，所以只有当dp[a]+1>dp[i],说明dp[i]需要更新，同时 count[i]  = ounts[a]；
        // 如果dp[a]+1=dp[i]，说明前面已经有个达到同样的长度了，这时候count[i] +=counts[a]；
        // 这也就保证了上面说的逻辑count[i] = sum(counts[a]);
        // 有图示的解题思路：https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/dong-tai-gui-hua-dong-tu-fu-zhu-li-jie-ru-you-bang/
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> counts(n,1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        counts[i] = counts[j];
                    }else if(dp[j] + 1 == dp[i])
                    {
                        counts[i] += counts[j];
                    }
                    
                }
            }
        }
        
        // 最后的返回值 应该是以nums[i]结尾的
        // 其中dp[i]达到dp数组长度最长的
        // 所有counts[i]的综和
        int res = 0;
        int LISlength = * max_element(dp.begin(),dp.end());
        for(int i = 0; i < n;i++)
        {
            if(LISlength == dp[i])
            {
                res+=counts[i];
            }

        }
        return res;
    }
};
// @lc code=end

