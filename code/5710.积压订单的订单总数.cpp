#include "pch.h"

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // 两个优先级队列， 来存储积压订单
        // 我要找 最低的sell订单 小顶堆  最高的buy订单，大顶堆
        auto less_compare = [](vector<int> a, vector<int> b) {
            return a[0] < b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>,  decltype(less_compare)> buy_orders(less_compare);

        auto large_compare = [](vector<int> a, vector<int> b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(large_compare)> sell_orders(large_compare);
        long long sell_count = 0, buy_count = 0;

        for(int i = 0; i < orders.size(); i++)
        {
            vector<int> curorder = orders[i];
            if (0 == curorder[2]) // 采购订单 buy
            {
                while (curorder[1] > 0 && sell_orders.size() > 0)
                {
                    vector<int> minsellorder = sell_orders.top();
                    if (minsellorder[0] <= curorder[0])
                    {
                        sell_orders.pop();
                        sell_count -= minsellorder[1];
                        // 匹配执行
                        if (minsellorder[1] < curorder[1])
                        {
                            curorder[1] = curorder[1] - minsellorder[1];
                        }
                        else
                        {
                            if (minsellorder[1] > curorder[1])
                            {
                                minsellorder[1] = minsellorder[1] - curorder[1];
                                sell_orders.push(minsellorder);
                                sell_count += minsellorder[1];
                            }
                            curorder[1] = 0;
                        }
                    }
                    else
                        break;
                }
                if (curorder[1] > 0)
                {
                    buy_orders.push(curorder);
                    buy_count += curorder[1];
                }
            }
            else
            { // sell订单

                while (curorder[1] > 0 && buy_orders.size() > 0)
                {
                    vector<int> maxbuyorder = buy_orders.top();
                    if (maxbuyorder[0] >= curorder[0])
                    {
                        buy_orders.pop();
                        buy_count -= maxbuyorder[1];
                        // 匹配执行
                        if (maxbuyorder[1] < curorder[1])
                        {
                            curorder[1] = curorder[1] - maxbuyorder[1];
                        }
                        else
                        {
                            if (maxbuyorder[1] > curorder[1])
                            {
                                maxbuyorder[1] = maxbuyorder[1] - curorder[1];
                                buy_orders.push(maxbuyorder);
                                buy_count += maxbuyorder[1];
                                ;
                            }
                            curorder[1] = 0;
                        }
                    }else
                        break;
                }
                if (curorder[1] > 0)
                {
                    sell_orders.push(curorder);
                    sell_count += curorder[1];
                }
            }
        }
        long long sum = sell_count + buy_count;
        long long temp = 1e9 + 7;
        return (int)(sum % temp);
    }
};

int main()
{
    //{{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};
    //
    vector<vector<int>> orders = {{1,29,1},{22,7,1},{24,1,0},{25,15,1},{18,8,1},{8,22,0},{25,15,1},{30,1,1},{27,30,0}};
    Solution sol;
    int res = sol.getNumberOfBacklogOrders(orders);
    cout << res;
}