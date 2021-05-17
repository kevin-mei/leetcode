/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
//#include "pch.h"

class Solution_1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int target = 0;
        int n = nums.size();
        if(n < 3)
            return res;
        for(int i = 0; i < n; i++)
        {
            // 这里传给twosum的应该是i+1的值
            vector<vector<int>> twores = twoSum(nums, i+1, target - nums[i]);
            for (int j = 0; j < twores.size(); j++)
            {
                twores[j].push_back(nums[i]);
                res.push_back(twores[j]);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }

        return res;
    }


    // 返回从start开始的，nums两数之和为target的所有数组
    vector<vector<int>> twoSum(vector<int>& nums, int start, int target)
    {
        vector<vector<int>> res;
        int left = start, right = nums.size()-1;
        while(left<right)
        {
            int sum = nums[left] + nums[right];
            int low = nums[left], hight = nums[right];
            if (sum < target)
                while (left < right && nums[left] == low) left++;
            else if (sum > target)
                while (left < right && nums[right] == hight) right--;
            else
            {
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == low) left++;
                while (left < right && nums[right] == hight) right--;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        int target = 0;
        int n = nums.size();
        vector<int> twonums;
        for(int i = 0; i < n; i++)
        {
            twonums.clear();
            twonums.insert(twonums.begin(), nums.begin(), nums.end());
            twonums.erase(twonums.begin()+i);
            // 这里传给twosum的应该是i+1的值
            vector<vector<int>> twores = twoSum(twonums,target - nums[i]);
            for (int j = 0; j < twores.size(); j++)
            {
                twores[j].push_back(nums[i]);
                sort(twores[j].begin(),twores[j].end());
                res.insert(res.end(), twores[j]);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }

        return vector<vector<int>>(res.begin(), res.end());
    }


    // 返回从start开始的，nums两数之和为target的所有数组
    vector<vector<int>> twoSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        int left = 0, right = nums.size()-1;
        while(left<right)
        {
            int sum = nums[left] + nums[right];
            int low = nums[left], hight = nums[right];
            if (sum < target)
                while (left < right && nums[left] == low) left++;
            else if (sum > target)
                while (left < right && nums[right] == hight) right--;
            else
            {
                res.push_back({nums[left], nums[right]});
                while (left < right && nums[left] == low) left++;
                while (left < right && nums[right] == hight) right--;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         set<vector<int>> res;
//         sort(nums.begin(), nums.end());
//         if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
//         for (int k = 0; k < (int)nums.size() - 2; ++k) {
//             if (nums[k] > 0) break;
//             int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
//             while (i < j) {
//                 if (nums[i] + nums[j] == target) {
//                     res.insert({nums[k], nums[i], nums[j]});
//                     while (i < j && nums[i] == nums[i + 1]) ++i;
//                     while (i < j && nums[j] == nums[j - 1]) --j;
//                     ++i; --j;
//                 } else if (nums[i] + nums[j] < target) ++i;
//                 else --j;
//             }
//         }
//         return vector<vector<int>>(res.begin(), res.end());
//     }
// };

// int main()
// {
//     vector<int> nums = {-1,0,1,2,-1,-4};
//     Solution sol;
//     vector<vector<int>> res = sol.threeSum(nums);
//     cout << res.size() << endl;
// }
// @lc code=end

