/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (31.50%)
 * Likes:    2576
 * Dislikes: 0
 * Total Accepted:    348.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start∂
#include "pch.h"

class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        // 从小的1个字符开始算  判断是回文串，然后在求长度
        //如果1个字符，是回文串 
        //2个字符，左右相等是回文串
        //3个字符，第一个和最后一个相等，是回文串
        //4个字符，两边两个相等，中间两个相等  3，4奇偶不同，验证稍有差异
        //n个字符，
        // 迭代算法，自底而上  动态规划 或者递归  自上而下

        // 明确状态 定义一个二维数组dp 其中dp[i][j]表示字符串区间[i,j]是否为回文串；
        // 找出状态转移方程：
        // d[i][j]  =ture  i==j
        //  =s[i] == s[j]              if j = i+1
        //  =s[i] == s[j] && dp[i+1][j-1]           if j > i+1

        int left = 0,len = 1;
        int n = s.size();

        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int j = 0; j < n; j++)
        {
            dp[j][j] = true;
            for(int i = 0; i < j; i++)
            {
                if(j == i+1 && s[i] == s[j] )
                {
                    dp[i][j] = true;
                }
                if(j > i+1)
                {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && len < j-i+1)
                {
                    len = j-i+1;
                    left = i;
                }
            }
        }    
        return s.substr(left, len);
    }
};
// @lc code=end

