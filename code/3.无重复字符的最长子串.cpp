/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 窗口内字符，个数
        std::unordered_map<char,int> hash_map;
        int start = 0, maxlen = 0;
        int left = 0, right=0;
        while(right != s.size())
        {
            // 增大窗口
            char cur_ch = s[right];
            hash_map[cur_ch]++;
            right++;

            // 判断是否有重复的子串 ，有的话，就缩小窗口
            while(hash_map[cur_ch]>1)
            {
                hash_map[s[left]]--;
                left++;
            }
            if(right-left > maxlen)
            {
                maxlen = right-left;
                start = left;
            }

        }
        return maxlen;
    }
};

// int main()
// {
//     string s= "abcabcbb";
//     Solution sol;
//     int res = sol.lengthOfLongestSubstring(s);
//     cout << res << endl;
// }
// @lc code=end

