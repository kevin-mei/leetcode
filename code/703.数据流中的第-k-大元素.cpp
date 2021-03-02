/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
//#include "pch.h"

class KthLargest {
public:
    // 使用优先级队列保存数据流，涉及到出队，然后恢复队列，time limit
    void KthLargest_1(int k, vector<int>& nums) {
        _k = k; // 保存k
        for(int num : nums)
        {
            _p_queue.push(num);
        }
    }
    
    int add_1(int val) {
        _p_queue.push(val);
        if(_k > _p_queue.size())
            return -1;
        int i = 0;
        int res = 0;
        stack<int> s; // 获取第K个最大的元素
        while (i < _k)
        {
            res = _p_queue.top();
            _p_queue.pop();
            s.push(res);
            i++;
        }

        // 恢复优先级队列
        while(!s.empty())
        {
            int temp = s.top();
            _p_queue.push(temp);
            s.pop();
        }
        return res;
    }

    // 使用排序数组保存数据流，从大到小排序，第K大的元素，就是排序后sort_nums[_k-1]元素，add的复杂度，插入排序，最差O(n)
    KthLargest(int k, vector<int> &nums)
    {
        _k = k; // 保存k
        sort_nums.insert(sort_nums.end(), nums.begin(), nums.end());
        sort(sort_nums.begin(), sort_nums.end(), std::greater<int>());
    }

    int add(int val)
    {
        if (0 == sort_nums.size()) // 如果sort_nums没有元素，则直接加入新元素
        {
            sort_nums.push_back(val);
        }
        else
        {
            for (int i = 0; i < sort_nums.size(); i++)
            {
                if (val >= sort_nums[i])
                {
                    sort_nums.insert(sort_nums.begin() + i, val);
                    break; // 因为只需要插入一个元素，所以插入完退出循环，不退出的话，vector大小变了，也会有死循环发生
                }
            }
        }

        if (_k > sort_nums.size())
            return -1;
        return sort_nums[_k-1];
    }

    private:
    int _k;
    priority_queue<int, vector<int>> _p_queue;
    vector<int> sort_nums;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// int main()
// {
//     int k = 3;
//     vector<int> nums = {4,5,8,2};
//     KthLargest* obj = new KthLargest(k, nums);
//     int val = 3;
//     int param_1 = obj->add(val);
//     cout << 3 << endl;;
// }
// @lc code=end

