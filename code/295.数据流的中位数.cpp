/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include "pch.h"
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
    // 默认是std::less<int> 比较函数，大顶堆  可以简写为：std::priority_queue<int>
    std::priority_queue<int, std::vector<int>, std::less<int>> small_heap;  // 大顶堆
    // 使用greater比较函数，小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > large_heap;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().first << q.top().second  << " ";
        q.pop();
    }
    std::cout << '\n';
}


int main()
{
    // 默认是std::less<int> 比较函数，大顶堆  可以简写为：std::priority_queue<int>
    /*
    std::priority_queue<int, std::vector<int>, std::less<int> > small_heap;  // 大顶堆
    for(int n : vect)
        small_heap.push(n); // 输出9 8 7 6 5 4 3 2 1 0 
 
    print_queue(small_heap);
    // 使用greater比较函数，小顶堆
    std::priority_queue<int, std::vector<int>, std::greater<int> > large_heap;  // 小顶堆
    for(int n : vect)
        large_heap.push(n);
    // 按堆顶元素输出，小的在顶部
    print_queue(large_heap); // 输出0 1 2 3 4 5 6 7 8 9 
    */

    // 按从小到达排序，使用大顶堆，原因是，大顶堆的第一个数大，然后大顶堆的对顶放在末尾，
    // 然后再重建堆，在取次大的放在末尾，再重建堆，最终形成从小到大排序

    // 实际上 每次取最大数或最小数，重建堆，取出来的数你想放在新的队头或队尾都可以，
    // 自己定义排序了，升序，降序都可以；
    // 如果是在自身的对象里，那还得小心着按定义来

    // 对pair 数据进行处理
    // std::map<int, int> occursMap;
    // for(int n : vect)
    // {
    //     occursMap[n]++;
    // }

    // // 用自定义函数对象排序
    // struct
    // {
    //     bool operator()(std::pair<int, int> a, std::pair<int, int> b) const
    //     {
    //         return a.second > b.second;
    //     }
    // } customGreat;

    // std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int> > , decltype(customGreat)> queue(customGreat);

    // for (std::pair<int, int> curPair : occursMap)
    // {
    //     queue.push(curPair);
    //     // queue.emplace推入新元素到 priority_queue 。原位构造元素，即不进行移动或复制操作。
    // }

    // print_queue(queue);
    // std::cout << "end" << std::endl;

}
// @lc code=end

