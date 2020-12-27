/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 *
 * https://leetcode-cn.com/problems/validate-stack-sequences/description/
 *
 * algorithms
 * Medium (60.13%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    16.9K
 * Total Submissions: 28.1K
 * Testcase Example:  '[1,2,3,4,5]\n[4,5,3,2,1]'
 *
 * 给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop
 * 操作序列的结果时，返回 true；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
 * 输出：true
 * 解释：我们可以按以下顺序执行：
 * push(1), push(2), push(3), push(4), pop() -> 4,
 * push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
 * 输出：false
 * 解释：1 不能在 2 之前弹出。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= pushed.length == popped.length <= 1000
 * 0 <= pushed[i], popped[i] < 1000
 * pushed 是 popped 的排列。
 * 
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    //先理清思路
    // 用一个栈模拟入栈，弹栈过程，看看能不能复现出pop的队列
    // 依次从pushed队列中拿到数字，然后入栈，
    // 循环 栈不为空 判断栈顶的元素是否等于pop队列待访问的元素(从0开始)
    //  等于栈顶的元素，则弹栈，且visited+1，，则继续判断，直到不等于的情况
    //  不等于，则继续入栈，待下轮访问，
    // 最后循环外，如果栈不为空或者visit不等于popped.size(), 则返回false 
    // visit最后自增，应该达到最后 一个元素下标+1，也就是popped.size()的大小
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> mid_stack;
        int nvisited = 0;
        for(int num : pushed)
        {
            mid_stack.push(num);
            while (0 != mid_stack.size())
            {
                if (popped[nvisited] == mid_stack.top())
                {
                    mid_stack.pop();
                    nvisited++;
                }
                else
                {
                    break;
                }
                
            }
        }
        if(0 != mid_stack.size() || nvisited != popped.size())
        {
            return false;
        }
        return true;
    }
};

// int main()
// {
//     vector<int> pushed = {1,2,3,4,5};
//     vector<int> poped = {4,5,3,2,1};
//     Solution sol;
//     bool res = sol.validateStackSequences(pushed, poped);
//     cout << "pause" << endl;
// }
// @lc code=end

