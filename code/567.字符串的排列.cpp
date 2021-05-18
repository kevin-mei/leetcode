/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 *
 * https://leetcode-cn.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (42.25%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    85.5K
 * Total Submissions: 202.3K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 * 
 * 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s1 = "ab" s2 = "eidbaooo"
 * 输出: True
 * 解释: s2 包含 s1 的排列之一 ("ba").
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: s1= "ab" s2 = "eidboaoo"
 * 输出: False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 输入的字符串只包含小写字母
 * 两个字符串的长度都在 [1, 10,000] 之间
 * 
 * 
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // s2 is contains all s1's char and contain't other char
        std::unordered_map<char, int> need, window;
        for(char ch : s1) need[ch]++;
        int left = 0, right = 0, vaild = 0;
        bool res = false;
        while(right < s2.size())
        {
            char right_ch = s2[right];
            right++;
            bool is_shrink = false;
            if(need.count(right_ch))
            {
                window[right_ch]++;
                if(window[right_ch] == need[right_ch])
                {
                    vaild++;
                }
                // else
                // {
                //     while (window[right_ch] > need[right_ch])
                //     {
                //         char left_ch = s2[left];
                //         left++;
                //         if (need.count(left_ch))
                //         {
                //             if (window[left_ch] == need[left_ch])
                //             {
                //                 vaild--;
                //             }
                //             window[left_ch]--;
                //         }
                //     }
                // }
            }
            // 收缩窗口 包含s1的所有字符且不包含其它字符，那Window的大小一定和s1相等
            while (right - left >= s1.size())
            {
                if (vaild == need.size())
                {
                    res = true;
                    break;
                }
                char left_ch = s2[left];
                left++;
                if (need.count(left_ch))
                {
                    if (window[left_ch] == need[left_ch])
                    {
                        vaild--;
                    }
                    window[left_ch]--;
                }
            }
        }
        return res;
    }
};

// int main()
// {
//     Solution sol;
//     string s1 = "hello";
//     string s2 = "ooolleoooleh";
//     bool res = sol.checkInclusion(s1, s2);
//     cout << res << endl;
// }
// @lc code=end

