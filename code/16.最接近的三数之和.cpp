/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = -1;
        int mindiff = INT_MAX;
        vector<int>  twonums;
        for(int i =0; i < nums.size();i++)
        {
            twonums.clear();
            twonums.insert(twonums.begin(), nums.begin(), nums.end());
            twonums.erase(twonums.begin() + i);
            int twores = twoSum(twonums, target - nums[i]);

            int sum = twores + nums[i];
            int temp = abs(sum - target);
            if (temp < mindiff)
            {
                mindiff = temp;
                res = sum;
            }
        }
        return res;
    }

    // 返回从start开始的，nums两数之和最接近target的数组 
    int twoSum(vector<int>& nums, int target)
    {
        int res = 0;
        int left = 0, right = nums.size()-1;
        int mindiff = INT_MAX;
        while(left<right)
        {
            int sum = nums[left] + nums[right];
            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
            {
                mindiff = 0;
                res = sum;
                break;
            }
            int temp = abs(target - sum);
            if(temp < mindiff)
            {
                mindiff = temp;
                res = sum;
            }
        }
        return res;
    }
};

// int main()
// {
//     vector<int> nums = {-1,2,1,-4}; // -1,2,1,-4  {0,2,1,-3};
//     Solution sol;
//     int target = 1;
//     int res = sol.threeSumClosest(nums, target);
//     cout << res << endl;
// }
// @lc code=end

