/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode-cn.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (54.78%)
 * Likes:    525
 * Dislikes: 0
 * Total Accepted:    86.5K
 * Total Submissions: 158K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
 * 
 * 每当你爬上一个阶梯你都要花费对应的体力值，一旦支付了相应的体力值，你就可以选择向上爬一个阶梯或者爬两个阶梯。
 * 
 * 请你找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：cost = [10, 15, 20]
 * 输出：15
 * 解释：最低花费是从 cost[1] 开始，然后走两步即可到阶梯顶，一共花费 15 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * 输出：6
 * 解释：最低花费方式是从 cost[0] 开始，逐个经过那些 1 ，跳过 cost[3] ，一共花费 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * cost 的长度范围是 [2, 1000]。
 * cost[i] 将会是一个整型数据，范围为 [0, 999] 。
 * 
 * 
 */

// @lc code=start
#include "pch.h"
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 标准的动态规划问题
        // f[i] 表示爬到第i个阶梯时，耗费的最小的体力值
        // 到达第i个阶级有两个方法：
        // f[i] = min(f[i-1]+cost[i-1], f[i-2]+cost[i-2])
        // f[0] = 0; f[1] = 0;  f[2] = min(f[1]+cost[1] , f[0]+cost[0])
        int count = cost.size();
        vector<int> f(count+1, 0);
        for(int i=2; i<=count; i++)
        {
            f[i] = min(f[i - 1]+cost[i - 1] , f[i - 2]+cost[i - 2]);
        }
        return f[count];
    }
};
// @lc code=end

