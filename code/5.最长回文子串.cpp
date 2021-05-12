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
        // 想着上一次循环已经做了dp[i+1][j-1]赋值，下一个就可以直接取值递归了
        // 那么这次的i 应该是递减的，所以i从大往小的遍历，j 应该是递增的，j从小往大遍历
        // 这样递推式刚好能用到上一次的结果
        int left = 0,len = 1;
        int n = s.size();

        vector<vector<bool> > dp(n, vector<bool>(n, false));
        for(int j = 0; j < n; j++)
        {
            dp[j][j] = true;
            //for(int i = 0; i < j; i++)
            for(int i = j-1; i >= 0; i--)
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

class Solution {
public:
    string longestPalindrome(string s) {
        // 考虑减而治之，
        // 1个字母，就是回文串
        // 2个字母，s[i] = s[i+1] ，就是回文串
        // 3个字母，s[i] = s[i+2], 就是回文串
        // 4个字母，相当于2个字母外加两个字母，之判断外面两个字母相等，再&上中间两个字母的结果
        // dp[i][j] 定义为字符串的[i,j]的子串是否为回文串
        // dp[i][j] = s[i] == s[j] if(i == j || i+1 == j|| i+2 == j)
        //          = (s[i] == s[j]) && dp[i+1][j-1] if(i+2 < j) 
        // 最长回文串的起始位置和长度
        int left = 0,len = 0; 
        int n = s.length();
        // 定义n*n的二维数组
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 这里需要注意下迭代顺序dp[i][j] 依赖于 dp[i+1,j-1]
        // 也就是说i+1,j-1要先算，也就是会说i从大往小遍历，j从小往大遍历
        // 同时i<=j
        for(int j = 0; j < s.length(); j++)
        {
            for(int i = j; i >=0; i--)
            {
                if(i == j || i+1 == j|| i+2 == j)
                    dp[i][j] = s[i] == s[j];
                else if(i+2 < j)
                    dp[i][j] = ((s[i] == s[j]) && dp[i+1][j-1]);
                if(dp[i][j] && len < j-i+1) // 注意最长子串的判断
                {
                    //找到回文串，更新left，len 
                    left = i;len = j-i+1;
                }
            }
        }
        return s.substr(left, len);
    }
};

// int main()
// {
//     Solution sol;
//     string s = "babad";
//     string s1 = sol.longestPalindrome(s);
//     cout << s1 << endl;
// }
// @lc code=end

