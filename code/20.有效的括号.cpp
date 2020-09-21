/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    bool isValid_1(string s) {
        std::stack<char> stack_s;
        //'('，')'，'{'，'}'，'['，']'
        string leftCh = "({[";
        string rightCh = ")}]";
        for(char ch :s)
        {
            if(std::string::npos != leftCh.find(ch) )
            {
                stack_s.push(ch);
            }
            else
            {
                if(0 == stack_s.size())
                    return false;
                //先访问栈顶数据
                char top = stack_s.top();
                // 判断top 和ch 是否为一对
                // leftCh 和 rightCh 就是一一对应的，
                // 可以直接判断top 和ch 在两个字符串的下标是否相等即可
                if(leftCh.find(top) == rightCh.find(ch))
                {
                    // 是成对的，需要弹栈
                    stack_s.pop();
                }else
                {
                    // 不成对，则返回false
                    return false;
                }
            }
        }
        // 最后判断stack_s的size为0，说明每个字符都有匹配到，返回true;
        if (0 == stack_s.size())
            return true;
        else
            return false;
    }

    // 优雅的map解法
    bool isValid(string s) {
        std::stack<char> stack_s;
        //'(', ')'，'{', '}'，'[', ']'
        std::map<char, char> map_ch;
        // map.insert 第一个参数为要插入的位置，第二个参数为要插入的数据
        // 在要插入位置之前会插入这个数据
        map_ch.insert(map_ch.end(), {'(', ')'});
        map_ch.insert(map_ch.end(), {'{', '}'});
        map_ch.insert(map_ch.end(), {'[', ']'});

        for(char ch :s)
        {
            // map.find 返回迭代器，如果没找到，则等于map.end(); 
            // begin()和end()都是迭代器，end()为最后一个元素+1
            if(map_ch.end() != map_ch.find(ch) )
            {
                stack_s.push(ch);
            }
            else
            {
                if(0 == stack_s.size())
                    return false;
                //先访问栈顶数据
                char top = stack_s.top();
                // 判断top 和ch 是否为一对
                // map[key] 直接返回对应的value值，这里判断key对应value是否一样即可成对
                if(map_ch[top] == ch)
                {
                    // 是成对的，需要弹栈
                    stack_s.pop();
                }else
                {
                    // 不成对，则返回false
                    return false;
                }
            }
        }
        // 最后判断stack_s的size为0，说明每个字符都有匹配到，返回true;
        if (0 == stack_s.size())
            return true;
        else
            return false;
    }
};
// @lc code=end

