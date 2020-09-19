/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
//#include "pch.h"
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(small_heap.size() < large_heap.size())
        {
            // 要给small_heap里加元素
            large_heap.push(num);
            small_heap.push(large_heap.top());
            large_heap.pop();
        }else
        {
            small_heap.push(num);
            large_heap.push(small_heap.top());
            small_heap.pop();
        }
        
    }

    double findMedian()
    {
        if (small_heap.size() < large_heap.size())
        {
            return large_heap.top();
        }
        else if (large_heap.size() < small_heap.size())
        {
            return small_heap.top();
        }
        // 两个堆数量相等
        return (double)(small_heap.top() + large_heap.top()) / 2.0;
    }

private:
    std::priority_queue<int, std::vector<int>, std::less<int>> small_heap;  // 大顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > large_heap;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

