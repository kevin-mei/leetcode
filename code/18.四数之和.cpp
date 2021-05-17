/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution_1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 4)
            return res;
        for(int i = 0; i < n; i++)
        {
            // 这里传给threeSum的应该是i+1的值
            vector<vector<int>> threeres = threeSum(nums, i+1, target - nums[i]);
            for (int j = 0; j < threeres.size(); j++)
            {
                threeres[j].push_back(nums[i]);
                res.push_back(threeres[j]);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }

        return res;

    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        if(n-start < 3)
            return res;
        for(int i = start; i < n; i++)
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        int n = nums.size();
        vector<int> threenums;
        for(int i = 0; i < n; i++)
        {
            threenums.clear();
            threenums.insert(threenums.begin(), nums.begin(), nums.end());
            threenums.erase(threenums.begin()+i);
            // 这里传给threeSum的应该是i+1的值
            vector<vector<int>> threeres = threeSum(threenums, target - nums[i]);
            for (int j = 0; j < threeres.size(); j++)
            {
                threeres[j].push_back(nums[i]);
                sort(threeres[j].begin(),threeres[j].end());
                res.insert(res.end(), threeres[j]);
            }
            // 跳过第一个数字重复的情况，否则会出现重复结果
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }

        return vector<vector<int>>(res.begin(), res.end());

    }
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
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
// @lc code=end

