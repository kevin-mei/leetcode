/*
给你一个整数数组 nums ，和两个整数 limit 与 goal 。数组 nums 有一条重要属性：abs(nums[i]) <= limit 。

返回使数组元素总和等于 goal 所需要向数组中添加的 最少元素数量 ，添加元素 不应改变 数组中 abs(nums[i]) <= limit 这一属性。

注意，如果 x >= 0 ，那么 abs(x) 等于 x ；否则，等于 -x 。

 

示例 1：

输入：nums = [1,-1,1], limit = 3, goal = -4
输出：2
解释：可以将 -2 和 -3 添加到数组中，数组的元素总和变为 1 - 1 + 1 - 2 - 3 = -4 。
示例 2：

输入：nums = [1,-10,9,1], limit = 100, goal = 0
输出：1
 

提示：

1 <= nums.length <= 105
1 <= limit <= 106
-limit <= nums[i] <= limit
-109 <= goal <= 109
*/
#include "pch.h"

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        int sum = 0;
        for(int num : nums)
        {
            sum+=num;
        }

        int target = abs(goal - sum);
        if (0 == target)
            return 0;
        // 目标是target, 
        //  当 0 == target%limit 余数为0时，return target/limit 
        //  当 0 != target%limit 余数不为0时， return target/limit +1；
        return target%limit?target/limit+1:target/limit;
    }

};

int main()
{
    vector<int> nums = {1,-1,1};
    int limit = 3;
    int goal=-4;
    Solution sol;
    int res = sol.minElements(nums, limit, goal);
    cout << res;
}

// [2,2,2,5,1,-2]
// 5
// 126614243