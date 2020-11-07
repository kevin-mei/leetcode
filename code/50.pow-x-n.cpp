/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (36.64%)
 * Likes:    528
 * Dislikes: 0
 * Total Accepted:    135.7K
 * Total Submissions: 368.3K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */

// @lc code=start

//#include "pch.h"
class Solution {
public:
    double myPow(double x, int n) {
        // long long m = n>0?n:-n;
        // return n>0?testmyPow(x, m):1.0/testmyPow(x, m);

        long long m = n;
        return n>0?testmyPow(x, m):1.0/testmyPow(x, -m);
    }

    double testmyPow(double x, long long n) {
        double res = 0;
        if(0==n)
        {
            return 1.0;
        }

        if(n%2)
        {
            // n为奇数
            return x*testmyPow(x,n-1);
        }else
        {
            // n为偶数
            res = testmyPow(x*x,n/2);
        }
        return res;
    }
};
// @lc code=end

