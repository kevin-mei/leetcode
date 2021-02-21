

/*
当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。
比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。
然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。

给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。
如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。

示例 1：

输入：s = "YazaAay"
输出："aAa"
解释："aAa" 是一个美好字符串，因为这个子串中仅含一种字母，其小写形式 'a' 和大写形式 'A' 也同时出现了。
"aAa" 是最长的美好子字符串。
示例 2：

输入：s = "Bb"
输出："Bb"
解释："Bb" 是美好字符串，因为 'B' 和 'b' 都出现了。整个字符串也是原字符串的子字符串。
示例 3：

输入：s = "c"
输出：""
解释：没有美好子字符串。
示例 4：

输入：s = "dDzeE"
输出："dD"
解释："dD" 和 "eE" 都是最长美好子字符串。
由于有多个美好子字符串，返回 "dD" ，因为它出现得最早。

1 <= s.length <= 100
s 只包含大写和小写英文字母。

*/




#include "pch.h"
class Solution {
public:
    string longestNiceSubstring(string s) {
        // 滑动窗口法是否可行，最长子串是连续的，借助滑动窗口应该可行
        // 如何判断大小写字母同时存在  A:65  Z:90 a:97 z:122 差32
		int left = 0, right = 1;
		int max_length = 0;
        int max_left = 0;

        for(right = 2; right < s.size(); right++)
        {
            for(left = 0; left < right-1; left++)
            {
                string curstr = s.substr(left, right - left);
                if (isNice(curstr))
                {
                    // 更新字串长度 应该使用right-left
                    if (right - left > max_length)
                    {
                        max_length = right - left;
                        max_left = left;
                    }
                }
            }
        }
        if (max_length < 2)
            return "";
        else
            return s.substr(max_left, max_length);
    }

    // 判断是否是nice字符串，只和s有关系
    bool isNice(string s)
    {
        bool res = true;
        int aa[26] = {0};
        int AA[26] = {0};
        // 先遍历s
        for (char ch : s)
        {
            if ('a' <= ch && ch <= 'z')
            {
                aa[ch-'a']++;
            }
            else if ('A' <= ch && ch <= 'Z')
            {
                AA[ch-'A']++;
            }
        }

        for(int i = 0 ; i < 26;i++)
        {
            if( (aa[i] <=0 && AA[i] > 0 ) || (aa[i] > 0 && AA[i] <= 0))
            {
                res =  false;
            }
        }
        return res;
    }

};

int main()
{
    Solution sol;
    string str = "YazaAay";
    string res = sol.longestNiceSubstring(str);
    cout << res << endl;
}