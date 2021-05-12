/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (60.39%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 87.1K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
 * 
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde"
 * 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 * 
 * 若这两个字符串没有公共子序列，则返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace"，它的长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc"，它的长度为 3。
 * 
 * 
 * 示例 3:
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * 输入的字符串只含有小写英文字符。
 * 
 * 
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j] (i,j>0)表示 text1的[0,i) 和text2的[0,j) 两个字符串的LCS的长度
        // dp[m][n]表示 text1的 和text2的两个字符串的LCS的长度
        // 所以声明的二维数组dp的大小应为m+1,n+1
        int m = text1.size(), n = text2.size();
        // 初始化(m+1,n+1)二维数组
        vector< vector<int> > dp(m+1, vector<int>(n+1, 0));

        // 减而治之：如果 text[i] == text[j], dp[i][j] = dp[i-1][j-1]+1; 
        // 分而治之：如果 text[i] != text[j], dp[i,j] = max(dp[i-1,j], dp[i,j-1]);

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 第i个元素下标为i-1
                if(text1[i-1] == text2[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1]+1; 
                }else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 定义dp[i][j] 为text1[0,i] 和text2[0,j]的LCS长度
        // if(text1[i] == text2[j]) dp[i][j] = dp[i-1][j-1]+1; (i>=1,j>=1)
        // if(text1[i] != text2[j]) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);(i>=1,j>=1)
        // 递归基：dp[0][0] = text1[0] == text2[0]?1:0;
        // dp[0][1] = （dp[0][0] || text1[0] == text2[1])?1:0;
        // dp[0][2] = （dp[0][1] || text1[0] == text2[2])?1:0;
        int m = text1.length(), n = text2.length();
        if(0 == m || 0 == n)
            return 0;
        vector<vector<int> > dp(m, vector<int>(n,0));
        // 处理递归基
        dp[0][0] = text1[0] == text2[0]?1:0;
        for(int i = 1; i < m;i++) 
        {
            dp[i][0] = (dp[i-1][0] || text1[i] == text2[0])?1:0;
        }
        for(int j=1; j< n;j++)
        {
            dp[0][j] = (dp[0][j-1] || text1[0] == text2[j])?1:0;
        }
        //dp[i][j] 依赖于 dp[i-1][j-1]，先知道小的，再知道大的，所以，i,j 都是递增遍历
        for(int i=1; i < m; i++)
        {
            for(int j=1; j < n;j++)
            {
                if(text1[i] == text2[j]) 
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

