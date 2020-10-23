/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    // 旋转1位怎么弄，然后循环k次 //案例34 数组长度20000，移动11939次，超出时间限制
    // 时间复杂度o(k*n) o(n2)
    void rotate_1(vector<int>& nums, int k) {
        k = k % nums.size();
        while (k--)
        {
            // 每次移动一个，相当于把最后一个元素放在第一位，然后依次排列
            int previous = *(nums.end()-1); //取最后一个元素
            for (int j = 0; j < nums.size(); j++)
            {
                int temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }

    void rotate(vector<int>& nums, int k) {
        //vector<int> temp_num(0, nums.size());
        int length = nums.size();
        vector<int> temp_num;
        temp_num.resize(length);
        // 旋转k位，相当于反向走k位，正向走length - k%length
        // 也就是a[i] 要拷贝到a[i+(length - k%length)]的位置
        // 对应两个数组就是temp_num[i+(length - k%length)] = nums[i]

        // 为什么是 i 移动到：(i + k) % length
        for(int i = 0; i < length;i++)
        {
            temp_num[(i + k) % length] = nums[i];
        }
        nums = temp_num;
    }

};

// int main()
// {
//     vector<int> nums = {1,2,3,4,5,6,7};
//     int k = 3;
//     Solution sol;
//     sol.rotate(nums,3);
//     cout << nums.size();

// }
// @lc code=end

