/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 *
 * https://leetcode-cn.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    793
 * Dislikes: 0
 * Total Accepted:    160.4K
 * Total Submissions: 330.4K
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
 * 
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * 
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
 * 
 * 请你实现这个将字符串进行指定行数变换的函数：
 * 
 * string convert(string s, int numRows);
 * 
 * 示例 1:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 3
 * 输出: "LCIRETOESIIGEDHN"
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "LEETCODEISHIRING", numRows = 4
 * 输出: "LDREOEIIECIHNTSG"
 * 解释:
 * 
 * L     D     R
 * E   O E   I I
 * E C   I H   N
 * T     S     G
 * 
 */

// @lc code=start
#include "pch.h"
class Solution {
public:
    string convert(string s, int numRows) {
        if(0 == s.size() || 0 == numRows || 1 == numRows ) 
            return s;
        int realrow = min((int)s.size(), numRows);
        vector<string> rows;
        rows.resize(realrow);

        bool bdown = true;
        int curRowIndex = 0;
        for(int i =0; i < s.size();i++)
        {
            if(0 == curRowIndex)
                bdown = true;
            
            if(realrow -1 == curRowIndex)
                bdown = false;

            rows[curRowIndex].push_back(s[i]);

            curRowIndex = bdown?curRowIndex+1:curRowIndex-1;
        }
        string str;
        for(auto rowstr : rows)
        {
            str.append(rowstr);
        }

        return str;
    }
};

int main()
{
    string s("ab");
    Solution sol;
    string res = sol.convert(s, 1);
    std::cout << res << std::endl;
    return 0;
}
// @lc code=end

