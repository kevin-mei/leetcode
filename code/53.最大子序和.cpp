/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
//#include "pch.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 分治法
        // 求nums中的最大元素
        vector<int>::iterator max_iter = std::max_element(nums.begin(), nums.end());
        int res_max = *max_iter;
        if (*max_iter <= 0 || 1 == nums.size())
        {
            // 如果最大元素<=0，则最大和的连续子数组就是最大的哪个元素，最大和也就是最大元素本身
            res_max = *max_iter;
        }
        else
        {
            // 如果最大元素>0，最大和的连续子数组 左右两个端点肯定为正数
            // 可以先求出 左右两端点为正数的，且元素和为正值的子数组b， 也就是两个正数之间组一个子数组，判断和是否为正值，是的话，就算找到，端点可以复用
            // 然后确定是否合并 端点相邻的子数组(它们的和相加那也一定)
            vector<int>::iterator cur_left = nums.begin(), cur_right = nums.end() - 1;
            vector<int>::iterator last_left = nums.end(), last_right = nums.end();
            while (cur_left < cur_right)
            {
                if (*cur_left <= 0)
                {
                    cur_left++;
                }
                if (*cur_right <= 0)
                {
                    cur_right--;
                }
                if (*cur_left > 0 && *cur_right > 0 && cur_left <= cur_right)
                {
                    printf("cur_left = %d cur_right = %d \n", *cur_left, *cur_right);
                    //int sum = std::accumulate(v.begin(), v.end(), 0); // 指定元素求和,区间[v.begin(), v.end())  // 0为init值 可以叠加
                    if (nums.end() == last_left && nums.end() == last_right)
                    {
                        last_left = cur_left;
                        last_right = cur_right;
                    }
                    else
                    {
                        // 判断[last_left, cur_left)之间的和知否为正值，为正值，则 last_left不变，为负值或0，则要缩小左边端点
                        if (std::accumulate(last_left, cur_left, 0) <= 0)
                        {
                            last_left = cur_left;
                        }
                        else
                        {
                            // 计算[last_left, cur_left]的和，更新下最大值
                            int temp_left = std::accumulate(last_left, cur_left + 1, 0);
                            if (temp_left > res_max)
                            {
                                res_max = temp_left;
                            }
                        }

                        // 右边判断(cur_right, last_right]的和
                        if (std::accumulate(cur_right + 1, last_right + 1, 0) <= 0)
                        {
                            last_right = cur_right;
                        }
                        else
                        {
                            // 计算[cur_right, last_right]的和，更新下最大值
                            int temp_right = std::accumulate(cur_right, last_right + 1, 0);
                            if (temp_right > res_max)
                            {
                                res_max = temp_right;
                            }
                        }
                    }
                    int temp = std::accumulate(last_left, last_right + 1, 0);
                    printf("last_left = %d last_right = %d sum = %d\n", *last_left, *last_right, temp);
                    if (temp > res_max)
                    {
                        res_max = temp;
                    }

                    if (cur_left < cur_right)
                    {
                        cur_left++;
                        if (*cur_left > 0)
                        {
                            while (*cur_left > 0 && cur_left < cur_right)
                            {
                                cur_left++;
                            }
                            // 计算[last_left, cur_left)的和，更新下最大值 这个区间内的值都大于0
                            int temp_left = std::accumulate(last_left, cur_left, 0);
                            if (temp_left > res_max)
                            {
                                res_max = temp_left;
                            }
                        }

                        cur_right--;
                        if (*cur_right > 0)
                        {
                            while (*cur_right > 0 && cur_left < cur_right)
                            {
                                cur_right--;
                            }
                             // 计算(cur_right, last_right]的和，更新下最大值 这个区间内的值都大于0
                            int temp_right = std::accumulate(cur_right + 1, last_right + 1, 0);
                            if (temp_right > res_max)
                            {
                                res_max = temp_right;
                            }
                        }
                    }


                }
            }
        }
        return res_max;
    }

    int maxSubArray_2(vector<int>& nums) {
        int sum = 0, smax = INT_MIN;
        for (int num : nums) {
            sum += num;
            smax = max(smax, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return smax;
    }

    int maxSubArray_3(vector<int> &nums)
    {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArray(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return INT_MIN;
        }
        int m = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, m - 1);
        int rmax = maxSubArray(nums, m + 1, r);
        for (int i = m - 1, sum = 0; i >= l; i--)
        {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = m + 1, sum = 0; i <= r; i++)
        {
            sum += nums[i];
            mr = max(sum, mr);
        }
        return max(max(lmax, rmax), ml + mr + nums[m]);
    }
};
// @lc code=end
