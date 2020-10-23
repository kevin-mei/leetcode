/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique_1(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> list;
        vector<int> visited(nums.size(), 0);
        std::function<void(vector<int> &nums, vector<int> &list, vector<int> &visited)> backtraceFun;
        backtraceFun = [&backtraceFun, &res](vector<int> &nums, vector<int> &list, vector<int> &visited) {
            if (nums.size() == list.size())
            {
                // base case 以保存的路径值等于要求数组nums的长度
                // 说明已经这个路径遍历完nums了
                if (std::end(res) == std::find(res.begin(), res.end(), list))
                {
                    res.push_back(list);
                }

                return;
            }


            for (int i = 0; i < nums.size();i++)
            {
                // if (std::end(list) != find(list.begin(), list.end(), num))
                // {
                //     // 路径list已包含num
                //     continue;
                // }
                if(1 == visited[i])
                {
                    continue;
                }
                int num = nums[i];
                list.push_back(num); // 将num添加到路径list中
                visited[i] = 1;
                backtraceFun(nums, list, visited);
                list.pop_back(); // 回溯，弹出已添加的num
                visited[i] = 0;
            }
        };
        backtraceFun(nums, list, visited);
        return res;
    }

    vector<vector<int>> permuteUnique(vector<int>& num) {
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

