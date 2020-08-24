/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (34.61%)
 * Likes:    2112
 * Dislikes: 0
 * Total Accepted:    438.4K
 * Total Submissions: 1.3M
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 * 10000000000000000000000000000000
 * 2^31 = 2147483648
 * 2147483648
 * 9646324351
 * 
 * 
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    // // 字符串反转算法
    // int reverse(int x) {
    //     int nRes = 0;

    //     // 33位bit数组， 第0-30(31)位存储x的绝对值
    //     // 31，32位 双符号位 保存正负 00 位正 11为负，
    //     // 如果翻转后溢出，那么检测符号位变话了，就溢出了，返回0
    //     string origin_x = std::to_string(std::abs(x));
    //     std::reverse(origin_x.begin(), origin_x.end());
    //     unsigned long ul = 0;
    //     ul = strtoul(origin_x.c_str(), NULL, 10);
    //     std::bitset<64> b64(ul);

    //     for (size_t i = 31; i < b64.size(); i++)
    //     {
    //         if (b64.test(i))
    //             return nRes;
    //     }

    //     if (b64.test(31) || b64.test(32))
    //     {
    //         // 溢出
    //         return nRes;
    //     }
    //     if(x < 0)
    //     {
    //         nRes = -ul;
    //     }else
    //     {
    //         nRes = ul;
    //     }
    //     return nRes;
    // }

    int reverse(int x) {
        int nRes = 0;
        int abs_x = std::abs(x);
        std::queue<int> queue_x;
        cout << "开始压栈";
        while(abs_x/10 != 0 || abs_x%10 !=0)
        {
            int temp = abs_x%10;
            queue_x.push(temp);
            abs_x = abs_x/10;
            cout << temp;
        }
        cout << "压栈结束";
        unsigned long ul = 0;
        unsigned long i = 0;
        while (queue_x.size() != 0)
        {
            i = pow(10, queue_x.size()-1);
            int temp = queue_x.front();
            if(0 == i)
                ul = ul + temp;
            else
                ul = ul + i * temp;
            queue_x.pop();
        }
        std::bitset<64> b64(ul);
        // 64位的bit, 第32位一直到63位，有一位为1，则为溢出
        for (size_t i = 31; i < b64.size(); i++)
        {
            if (b64.test(i))
                return nRes;
        }

        if (b64.test(31) || b64.test(32))
        {
            // 溢出
            return nRes;
        }
        if(x < 0)
        {
            nRes = -ul;
        }else
        {
            nRes = ul;
        }
        return nRes;
    }
};


// int main()
// {
//     int a = 1534236469;
//     Solution sol;
//     int b =sol.reverse(a);
//     cout << b << endl;
// }
// @lc code=end

