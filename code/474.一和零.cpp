/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 *
 * https://leetcode-cn.com/problems/ones-and-zeroes/description/
 *
 * algorithms
 * Medium (55.64%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    31.6K
 * Total Submissions: 56.7K
 * Testcase Example:  '["10","0001","111001","1","0"]\n5\n3'
 *
 * 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
 * 
 * 
 * 请你找出并返回 strs 的最大子集的大小，该子集中 最多 有 m 个 0 和 n 个 1 。
 * 
 * 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
 * 输出：4
 * 解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
 * 其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1
 * ，大于 n 的值 3 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["10", "0", "1"], m = 1, n = 1
 * 输出：2
 * 解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * strs[i] 仅由 '0' 和 '1' 组成
 * 1 
 * 
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 新建一个二维DP数组，其中dp[i][j]表示i个0和j个1时能组成的最多字符串的个数
        // 而对于当前的字符串，我们统计出其中0和1的个数为zeros和ones，
        // 然后dp[i-zeros]+dp[j-ones] 表示当前的i 和j减去zeros和ones之前能拼成字符串的个数
        // dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1)

        // 我一直以为的递推式是dp[i][j]和dp[i-1][j-1]之类的关系，也没想到dp[i][j]可以放在等号的右边
        // 相当于等号右边的dp[i][j]只是临时的或者初始化时的dp[i][j]，等到dp数组遍历完成后，才是真正的dp[i][j]
        // 相信dp数组的定义语义，它就是i个0和j个1时，能组成的最多字符串的个数
        // 每遍历一个字符串，都需要更新下和这个字符串相关的dp数组，也就是从dp[m][n]更新到dp[zeros][ones];
        vector<vector<int> > dp(m+1, vector<int>(n+1,0));
        for(string str:strs)
        {
            int zeros=0,ones=0;
            for(char c:str) (c=='0')?zeros++:ones++;
            for (int i = m; i >= zeros; i--)
            {
                for (int j = n; j >= ones; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

