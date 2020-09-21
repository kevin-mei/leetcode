/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (77.99%)
 * Likes:    756
 * Dislikes: 0
 * Total Accepted:    134.9K
 * Total Submissions: 172.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    // 数学归纳法，或者递归解法
    // 假设你知道了较小一级的子问题的解，能不能算出新一级的解,经验：不一定从n开始，已有的元素
    // 从[1,2]和[1,2,3]开始找规律也可以
    // [1,2]的子集 subsets([1,2]) = [] [1] [2] [1,2]
    // [1,2,3]的子集  subsets([1,2,3]) = [3] [1,3] [2,3] [1,2,3] + [1,2]的子集
    // 注意观察：存在[1,2,3]的子集 =  [1,2]的子集 + for([1,2]的子集){ 每个子集+[3](新增元素)} 的关系
    // base case 显然就是当输入集合为空集时，输出子集也就是一个空集。 这里注意空集直接返回return {{}};
    // 空集返回 res.push_back({{}});  return res;，会默认初始化为{{0}},不符合题意，这里需要注意下
    // vector 插入一个vector 的range，使用insert(iter::pos,iter::start,iter::end);在pos位置之前插入[start,end)之间的元素
    vector<vector<int>> subsets_1(vector<int> &nums)
    {
        if (0 == nums.size())
        {
            return {{}};
        }
        // 取出nums的最后一个元素
        int last_element = nums.back();
        nums.pop_back();

        vector<vector<int>> res;                      // 这一次的解
        vector<vector<int>> last_Res = subsets(nums); // 小一级问题的解
        res.insert(res.end(), last_Res.begin(), last_Res.end());

        for (int i = 0; i < last_Res.size(); i++)
        {
            last_Res[i].push_back(last_element); // 小一级问题的解加上最后一个元素
            res.push_back(last_Res[i]);          // 添加的新解当中
        }
        return res;
    }

    // 回溯法
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (0 == nums.size())
        {
            return {{}};
        }
        vector<vector<int>> res;                      // 这一次的解
        return res;
    }
};

// int main()
// {
//     std::cout << "hello" << std::endl;
//     return 0;
// }
// @lc code=end

