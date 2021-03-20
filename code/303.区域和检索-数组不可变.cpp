/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (69.87%)
 * Likes:    309
 * Dislikes: 0
 * Total Accepted:    107K
 * Total Submissions: 151.1K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点。
 * 
 * 
 * 
 * 实现 NumArray 类：
 * 
 * 
 * NumArray(int[] nums) 使用数组 nums 初始化对象
 * int sumRange(int i, int j) 返回数组 nums 从索引 i 到 j（i ≤ j）范围内元素的总和，包含 i、j 两点（也就是
 * sum(nums[i], nums[i + 1], ... , nums[j])）
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "sumRange", "sumRange"]
 * [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
 * 输出：
 * [null, 1, -1, -3]
 * 
 * 解释：
 * NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
 * numArray.sumRange(0, 2); // return 1 ((-2) + 0 + 3)
 * numArray.sumRange(2, 5); // return -1 (3 + (-5) + 2 + (-1)) 
 * numArray.sumRange(0, 5); // return -3 ((-2) + 0 + 3 + (-5) + 2 + (-1))
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 0 
 * 最多调用 10^4 次 sumRange 方法
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include "pch.h"

// 平平无奇
// class NumArray {
// public:
//     NumArray(vector<int>& nums) {
//         _nums.insert(_nums.end(), nums.begin(), nums.end());
//     }
    
//     int sumRange(int i, int j) {
//         if(i <0 || j > _nums.size()-1)
//             return -1;
//         int sum = 0;
//         for(int k = i; k <=j;k++)
//         {
//             sum+=_nums[k];
//         }
//         return sum;
//     }
// private:
//     vector<int> _nums;
// };

class NumArray {
public:
    NumArray(vector<int>& nums) {
        // _sum[i] 存放前nums的i-1个元素的和 
        // 这样[i,j]区域内的和，就转化为 sum[j+1] - sum[i]的值，只需要o(1)的时间复杂度

        // 怎么算sum[i], 先设置下_sum的大小
        _sum.resize(nums.size()+1);
        // sum[0] = 0； sum[1] = sum[0]+nums[0]; sum[2] =sum[1]+nums[1]
        // sum[i] = sum[i-1]+nums[i-1]  哇哦，又是递推式
        _sum[0]=0;
        for(int i = 1; i <=nums.size();i++)
        {
            _sum[i] = _sum[i-1]+nums[i-1];
        }

    }
    
    int sumRange(int i, int j) {
        if(i <0 || j+1 > _sum.size()-1)
            return -1;
        return _sum[j+1] - _sum[i];
    }
private:
    vector<int> _sum;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

