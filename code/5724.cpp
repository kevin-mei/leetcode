#include "pch.h"

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long abs_sum = 0;
        // sum的最小值
        // 最笨的方法，找出对应元素差最大的那个；
        // 替换为其它元素和它的nums2[i]的差最小的这个，
        // 然后求和
        int max_abs = -1;
        int max_index = -1;
        for(int i =0; i < nums1.size(); i++)
        {
            int cur_abs =abs(nums1[i] - nums2[i]);
            abs_sum+=cur_abs;
            if(cur_abs  > max_abs)
            {
                max_abs = cur_abs;
                max_index = i;
            }
        }
        // 在遍历一边sum1,找sum1中abs(nums[i] - nums2[max_index])最小值
        int replace_index = -1,min_abs=INT_MAX;
        for(int i =0; i < nums1.size(); i++)
        {
            int cur_abs =abs(nums1[i] - nums2[max_index]);
            if(cur_abs  < min_abs)
            {
                min_abs = cur_abs;
                replace_index = i;
            }
        }
        abs_sum = abs_sum-max_abs+min_abs;
        long long temp = 1e9 + 7;
        return (int)(abs_sum % temp);
    }
};

int main()
{
    vector<int> nums1 = {1, 7, 5};
    vector<int> nums2 = {2, 3, 5};
    Solution sol;
    int res = sol.minAbsoluteSumDiff(nums1, nums2);
    cout << res;

}