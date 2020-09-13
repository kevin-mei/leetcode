/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(0 == nums1.size() && 0 == nums2.size() )
        {
            return 0;
        }

        // 中位数： 奇数数组：下标为中间的数 偶数数组：下标为中间的两个数的平均数

        // 先排序 将nums1和nums2合并为一个数组
        vector<int>  nums;
        nums.insert(nums.end(), nums1.begin(), nums1.end());
        nums.insert(nums.end(), nums2.begin(), nums2.end());
        std::sort(nums.begin(), nums.end());

        double dRes = 0;
        if(0 == nums.size() % 2)
        {
            //偶数数组
            dRes=(double)(nums[nums.size()/2-1] + nums[nums.size()/2])/2.0;
        }else
        {
            //奇数数组
            dRes=nums[nums.size()/2];
        }
        return dRes;
    }
};
// @lc code=end

