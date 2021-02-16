/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (55.88%)
 * Likes:    757
 * Dislikes: 0
 * Total Accepted:    187.5K
 * Total Submissions: 335.6K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 * 
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 * 
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 * 
 * 
 */

// @lc code=start
//#include "pch.h"
// 用stl偷懒算法
class MinStack_1 {
public:
    /** initialize your data structure here. */
    MinStack_1() {
    }
    
    void push(int x) {
        elements.push_back(x);
    }
    
    void pop() {
        if(0 != elements.size())
        {
            elements.pop_back();
        }
    }
    
    int top() {
        if(0 == elements.size())
        {
            return -1;
        }
        return *(elements.rbegin());
    }
    
    int getMin() {
        if(0 == elements.size())
        {
            return -1;
        }
        return *(min_element(elements.begin(), elements.end()));
    }
    vector<int> elements;
};

// 看了题解后的，两个栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        s1.push(x);
        // 这里的条件苛刻些，等于最小值也要压s2栈
        // s1弹栈时，最小值也要更新，如果不记录相同的最小值，那么最小值弹出去后，得到的第二个最小值也就不准确了
        if(s2.empty() || x <= getMin()) 
        {
            s2.push(x);
        }
    }

    void pop()
    {
        // 弹栈时，如果弹的元素和s2栈顶一样，s2也要弹出
        if (s1.top() == getMin())
        {
            s2.pop();
        }
        s1.pop();
    }

    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:    
    stack<int> s1;
    stack<int> s2; // s2的栈顶总是保存s1中最小的元素，如果新插入的元素有比s2栈顶元素还小的，则也插入到s2中
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

