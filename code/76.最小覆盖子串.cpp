/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.58%)
 * Likes:    823
 * Dislikes: 0
 * Total Accepted:    88K
 * Total Submissions: 222.2K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
 * 
 * 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    string minWindow(string s, string t) {
        // 窗口已经有的字符 hashmap  是否包含t的所有字符
        std::unordered_map<char, int> need, window;
        for (auto ch : t)
            need[ch]++; // every pair is {ch, n}; n is ch occur count
        int left = 0, right = 0, start = 0, len = INT_MAX;
        int vaild = 0;// count of contains t's char 
        while(right < s.size())
        {
            char right_ch = s[right];
            right++;
            if(need.end()!=need.find(right_ch))
            {
                window[right_ch]++;
                if(window[right_ch] == need[right_ch])
                {
                    vaild++;
                }
            }

            while(vaild == need.size())
            {
                // all t's char is already contains ; update the result
                if (right - left < len)
                {
                    start = left;
                    len = right - left;
                }

                // shrink the window
                char left_ch = s[left];
                left++;
                if(need.end()!=need.find(left_ch))
                {
                    if (window[left_ch] == need[left_ch])
                    {
                        vaild--;
                    }
                    window[left_ch]--;
                }
            }
        }
        return len == INT_MAX ?
        "" :s.substr(start, len);
    }

    string minWindow_2(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (valid == need.size()) {
            // 在这里更新最小覆盖子串
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }                    
        }
    }
    // 返回最小覆盖子串
    return len == INT_MAX ?
        "" : s.substr(start, len);
}
};



int main()
{
    Solution sol;
    string s = "a";
    string t = "aa";

    string res = sol.minWindow(s, t);
    cout << res << endl;
}
// @lc code=end

