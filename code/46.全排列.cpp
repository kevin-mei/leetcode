/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
//#include "pch.h"

// 这道题的详细解析：https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/hui-su-suan-fa-xiang-jie-xiu-ding-ban

class Solution {
public:


    vector<vector<int>> _res;
    // 常规操作，在函数外定义一个递归函数
    vector<vector<int>> permute_1(vector<int>& nums) {
        vector<int> list;
        backtrace_1(nums, list);
        return _res;
    }

    void backtrace_1(vector<int>& nums,vector<int>& list)
    {
        if (nums.size() == list.size())
        {
            // base case 以保存的路径值等于要求数组nums的长度
            // 说明已经这个路径遍历完nums了
            _res.push_back(list);
            return;
        }

        for(auto num : nums)
        {
            if(std::end(list) !=  find(list.begin(),list.end(), num))
            {
                // 路径list已包含num
                continue;
            }
            list.push_back(num); // 将num添加到路径list中
            backtrace_1(nums, list);
            list.pop_back(); // 回溯，弹出已添加的num
        }
    }

    // 利用std::function和lambda表达式完成 函数内定义一个递归函数的操作
    vector<vector<int>> permute_2(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> list;
        std::function<void(vector<int> &nums, vector<int> &list)> backtraceFun;
        backtraceFun = [&backtraceFun, &res](vector<int> &nums, vector<int> &list) {
            if (nums.size() == list.size())
            {
                // base case 以保存的路径值等于要求数组nums的长度
                // 说明已经这个路径遍历完nums了
                res.push_back(list);
                return;
            }

            for (auto num : nums)
            {
                if (std::end(list) != find(list.begin(), list.end(), num))
                {
                    // 路径list已包含num
                    continue;
                }
                list.push_back(num); // 将num添加到路径list中
                backtraceFun(nums, list);
                list.pop_back(); // 回溯，弹出已添加的num
            }
        };
        backtraceFun(nums, list);
        return res;
    }

    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        // 这里先sort排序，作为next_permutation的初始值
        sort(num.begin(), num.end());
        res.push_back(num);
        // next_permutation STL标准库 返回下一个字典排序的num
        // 如果返回的num=sort(num.begin(), num.end());则此函数返回值为false
        while (next_permutation(num.begin(), num.end())) {
            res.push_back(num);
        }
        return res;
    }
};

// @lc code=end

