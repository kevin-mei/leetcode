/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 *
 * https://leetcode-cn.com/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (68.31%)
 * Likes:    241
 * Dislikes: 0
 * Total Accepted:    144.7K
 * Total Submissions: 211.8K
 * Testcase Example:  '2'
 *
 * 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * 
 * 
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 
 * 
 * 给你 n ，请计算 F(n) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    // 普通递归，可以打印递归树
    int fib_1(int n) {
        int res = 1;
        printindex(_count++);
        printf("n = %d\n", n);
        if(0 == n || 1 == n)
        {
            printindex(--_count);
            printf("return %d\n", res);
            return res;
        }
        res = fib(n-1) + fib(n-1);
        printindex(--_count);
        printf("return %d\n", res);
        return res;
    }

    // 带备忘录的递归， 可以打印递归树
    int fib_2(int n) {
        if(0 == n) return 0;
        if(1 == n) return 1;
        vector<int> mem(n+1, 0);
        mem[0] = 0; // 0,1时，均为1
        mem[1] = 1;
        return fibhelp(mem, n);
    }

    // 传引用的mem当形参，少去形参拷贝赋值的步骤
    int fibhelp(vector<int> & mem, int n) {
        int res = 1;
        if(0 == n || 0 != mem[n])
        {
            return mem[n];
        }
        // printindex(_count++);
        // printf("n = %d\n", n);
        res = fibhelp(mem, n-1) + fibhelp(mem, n-2);
        // printindex(--_count);
        // printf("return %d\n", res);
        mem[n] = res;
        return res;
    }
    
    // dp 
    // 递推式： f(n) = f(n-1) + f(n-2)
    // base case f(0) = 1, f(1) = 1
    // 上一次循环的要比这一次的小，所以i应该是从小往大遍历
    int fib(int n) {
        if(0 == n) return 0;
        if(1 == n) return 1;
        vector<int> mem(n+1, 0);
        mem[0] = 0; // 0,1时，均为1
        mem[1] = 1;
        for(int i = 2; i <=n;i++)
        {
            mem[i] = mem[i-1]+mem[i-2];
        }
        return mem[n];
    }



private:
    int _count = 0;
    void printindex(int n)
    {
        for(int i =0; i < n; i++)
        {
            printf("    ");
        }
    }
};

// int main()
// {
//     Solution sol;
//     int a = sol.fib(7);
//     cout << a << endl;
//     return 0;
// }
// @lc code=end

