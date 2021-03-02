/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return -1;
        // 利用大顶堆，默认的priority_queue就是，所有元素入堆，然后弹出堆顶元素，弹K次即可
        priority_queue<int ,vector<int>,std::less<int> > p_queue(nums.begin(),nums.end());
        // for(int num : nums)
        // {
        //     p_queue.push(num);
        // }
        int res = 0;
        while (k > 0 && !p_queue.empty())
        {
            res = p_queue.top();
            p_queue.pop();
            k--;
        }
        return res;
    }
};
// @lc code=end

