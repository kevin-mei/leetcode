/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(0 == nums.size())
            return 0;

        // 滑动窗口的两侧
        int left = 0, right = 0;
        // 最长的连续递增子序列长度，一个元素也是递增的，所以初始化为1
        int maxLength = 1; 
        while(right+1 < nums.size())
        {
            // 扩大窗口  判断相邻两个元素递增时，增加窗口大小
            if(nums[right] < nums[right+1])
            {
                right++;
            }else
            {
                // 更新maxLength
                int temp = right - left + 1;
                maxLength = temp > maxLength?temp:maxLength;
                // 缩小窗口
                right++;
                left = right;
            }
        }
        // 最后再更新下maxLength 跳出循环也需要更新
        int temp = right - left + 1;
        maxLength = temp > maxLength?temp:maxLength;
        return maxLength;
    }
};
// @lc code=end

