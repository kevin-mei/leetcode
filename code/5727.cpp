#include "pch.h"

class Solution {
public:
    int findTheWinner(int n, int k) {
        int real_k = k%n;
        list<int> circle;
        for (int i = 1; i <= n; ++i)  //将猴子的编号放入list
            circle.push_back(i);
        list<int>::iterator it = circle.begin();

        while (circle.size() > 1)
        { //只要还有不止一只猴子，就要找一只猴子让其出列
            for (int i = 1; i < real_k; ++i)
            { //报数
                ++it;
                if (it == circle.end())
                    it = circle.begin();
            }
            it = circle.erase(it); //删除元素后，迭代器失效，
                                    //要重新让迭代器指向被删元素的后面
            if (it == circle.end())
                it = circle.begin();
        }
        return circle.front();
    }
};