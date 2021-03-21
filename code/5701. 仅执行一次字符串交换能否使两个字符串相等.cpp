/*
给你长度相等的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。

如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。

 

示例 1：

输入：s1 = "bank", s2 = "kanb"
输出：true
解释：例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
示例 2：

输入：s1 = "attack", s2 = "defend"
输出：false
解释：一次字符串交换无法使两个字符串相等
示例 3：

输入：s1 = "kelb", s2 = "kelb"
输出：true
解释：两个字符串已经相等，所以不需要进行字符串交换
示例 4：

输入：s1 = "abcd", s2 = "dcba"
输出：false
 

提示：

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 和 s2 仅由小写英文字母组成
*/

#include "pch.h"

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // 两个字符串，只有两个位置不一样
        // 而且，两个位置交换后是一样的
        bool res = false;
        int count1= s1.size();
        int count2=s2.size();
        if(count1 != count2)
            return res;
        int diffCount = 0;
        // 记两个下标即可 diff1,diff2
        int diff1 =-1,diff2=-1;
        for(int i=0; i<count1; i++)
        {
            if(0!=s1[i]-s2[i])
            {
                diffCount++;
                if(1 == diffCount)
                    diff1 = i;
                if(2 == diffCount)
                    diff2=i;
            }
            if(diffCount>2)
                return res;
        }
        if(0 == diffCount) // 两个字符串本身就相等
            res = true;
        else if (2== diffCount&&
        s1[diff1] == s2[diff2] && s1[diff2] == s2[diff1]) //两个字符串有两处不一样
            res = true;

        return res;
    }
};

int main()
{
    string s1 = "bank";
    string s2 = "kanb";
    Solution sol;
    bool res = sol.areAlmostEqual(s1, s2);
    cout << res << endl;
}