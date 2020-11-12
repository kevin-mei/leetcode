/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 *
 * https://leetcode-cn.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (49.58%)
 * Likes:    9585
 * Dislikes: 0
 * Total Accepted:    1.5M
 * Total Submissions: 3.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 
 * 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 nums = [2, 7, 11, 15], target = 9
 * 
 * 因为 nums[0] + nums[1] = 2 + 7 = 9
 * 所以返回 [0, 1]
 * 
 * 
 */

// @lc code=start
#include "pch.h"

class Solution {
public:
    // 平凡的算法会超时
    vector<int> twoSum_timeLimit(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0; i < nums.size();i++)
        {
            for(int j = i+1; j < nums.size();j++)
            {
                if(target == nums[i] + nums[j])
                {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        // 用额外n的空间存储target - nums[i] 的差值
        // map_data 保存 (差值，下标) 数组元素有可能相同，就会有相同的差值，这时候i覆盖
        // 题中说只有一个正确答案，这时候i覆盖的情况，也不会是正确答案，如果是，则不只答案了
        std::unordered_map<int,int> map_data;
        // 遍历一边，一边判断当前nums[i]是否在map_data的keys中能找到，能找到说明是正确答案，找到对应value，就是上一个数的下标
        // 没找到就map_data[差值] = i;把<差值，下标>保存到map中
        vector<int> res;
        for(int i=0; i < nums.size();i++)
        {
           if(map_data.find(nums[i]) != map_data.end())
           {
               res.push_back(map_data[nums[i]]);
               res.push_back(i);
           }else
           {
               int dest = target -nums[i];
               map_data[dest] = i;
           }
        }
        return res;
    }
};
// @lc code=end

