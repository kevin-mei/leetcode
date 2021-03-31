/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.71%)
 * Likes:    763
 * Dislikes: 0
 * Total Accepted:    319.6K
 * Total Submissions: 804.8K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    // 循环两次，不够简洁
    int strStr_1(string haystack, string needle) {
        if("" == needle) return 0;
        int res = -1;
        for(int i = 0; i < haystack.size();i++)
        {
            int m = i;
            int n = 0;
            while (m < haystack.size() && n < needle.size() && haystack[m] == needle[n] )
            {
                m++;
                n++;
            }
            if (n == needle.size())
            {
                res = i;
                break;
            }
        }
        return res;
    }

    // 一次循环的暴力求解，以i-j作为返回值
    int strStr_2(string haystack, string needle) {
        int n = haystack.size(), i=0;
        int m = needle.size(),j=0;
        while(i<n && j <m)
        {
            if(haystack[i] == needle[j]) {i++;j++;}
            else {i = i-j+1;j=0; }
        }
        // 当i-j大于n-m时，说明匹配位置比最后一个能匹配的下标还大，即匹配失败，返回-1
        return i-j > n-m?-1:i-j; 
    }

    // KMP算法
    

};
// @lc code=end

