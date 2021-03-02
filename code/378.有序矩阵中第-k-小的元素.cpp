/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // 使用小顶堆，priority_queue 默认为大顶堆，需要修改比较算法，出队第k个元素，即为所求
        priority_queue<int, vector<int>, std::greater<int>> p_queue;
        for(auto nums : matrix)
        {
            for(int num : nums)
            {
                p_queue.push(num);
            }
        }
        
        if(k > p_queue.size())
            return -1;
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

// int main()
// {
//     vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
//     int k = 8;
//     Solution sol;
//     int res = sol.kthSmallest(matrix, k);
//     cout << res << endl;
// }
// @lc code=end

