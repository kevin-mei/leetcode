/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (48.07%)
 * Likes:    433
 * Dislikes: 0
 * Total Accepted:    58.6K
 * Total Submissions: 122K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 * 
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 * 
 * 
 * 每个孩子至少分配到 1 个糖果。
 * 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
 * 
 * 
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[1,0,2]
 * 输出：5
 * 解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1,2,2]
 * 输出：4
 * 解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1 颗糖果，这已满足上述两个条件。
 * 
 */

// @lc code=start
//#include "pch.h"

class Solution {
public:
    // 每个孩子至少一个糖果，相邻两个孩子，评分高的孩子一定要比评分低的孩子糖果多，先每人一个
    // 如果用两个指针，它和它的前一个比较，如果比他高，就比他+1，依次遍历，如果第一个高，就比后面+1，
    // 既然是求最小的糖果数，能不能先对这个孩子排序，最小的到最大的，这样会影响相对位置
    // 但是先按照分数先发糖果，这样每个大的，一定比周围小的大
    // 然后看3个3个一看，看看最大的孩子是不是比此大的糖果数大1个以上，是的话，则修改为次大的+1
    // 这里不能看最值，需要看相邻的两个孩子，或者就比较中间的，跟两边的孩子的最大值a比较，是不是比它大2，是的话，则修改为比他大1
    // 这样的话，需要一个map<孩子下标, 糖果数>  然后找三个三个的对比，直到遍历结束
    int candy_1(vector<int>& ratings) {
        int res = 0;
        std::map<int,int> child_map;
        int nCount= ratings.size();
        for(int i = 0; i < nCount; i++)
        {
            child_map.insert({i, 1});
        }
        for(int i = 0; i < (int)(nCount-2); i++)
        {
            // a b c 第一个孩子的糖果
            int a = ratings[i];
            int b = ratings[i+1];
            int c = ratings[i+2];
            vector<int> threeChild = {a, c};
            int d =  std::max(a, c);
            if(b > d)
            {
                if(a == d)
                {
                    child_map[i+1] = child_map[i] + 1;
                }else
                {
                    child_map[i+1] = child_map[i+2] + 1;
                }
            }
            else if(b < d)
            {
                if(a == d)
                {
                    child_map[i] = child_map[i+1] + 1;
                }else
                {
                    child_map[i+2] = child_map[i+1] + 1;
                    if(a > b)
                    {
                        child_map[i] = child_map[i+1] + 1;
                    }
                }
            }
            else // b==d
            {
                if (a != c)
                {
                    if (a == d) // a和b 评分相等， b要等于c的个数+1
                    {
                        child_map[i+1] = child_map[i+2]+1;
                    }
                    else // b 和c的评分相等 b要等于a的个数+1
                    {
                        child_map[i+1] = child_map[i] + 1;
                    }
                }
            }
        }
        for(int i = 0; i < nCount; i++)
        {
            res +=child_map[i];
        }
        return res;
    }

    // 左规则：先从左向右遍历一遍，如果 ratings[i] < ratings[i+1]; 则ratings[i+1]的糖果数等于ratings[i]糖果数+1
    // 有规则：再从右向左遍历一遍，如果 ratings[i] > ratings[i+1],则对应更新糖果数
    // 糖果数取两次的最大值，才能同时满足左规则和右规则
    int candy(vector<int>& ratings)
    {
        int res = 0;
        std::map<int,int> child_map;
        int nCount= ratings.size();
        for(int i = 0; i < nCount; i++)
        {
            child_map.insert({i, 1});
        }

        for(int i = 0; i < nCount-1; i++)
        {
            // a b 相邻两个孩子的分数
            int a = ratings[i];
            int b = ratings[i+1];
            if(a < b )
            {
                child_map[i+1] = child_map[i] + 1;
            }
        }

        for(int i = nCount-1; i >0; i--)
        {
            // a b 相邻两个孩子的分数
            int b = ratings[i];
            int a = ratings[i-1];
            if(a > b )
            {
                int temp = child_map[i] + 1;
                if(temp > child_map[i-1])
                    child_map[i-1] = temp;
            }
        }

        for(int i = 0; i < nCount; i++)
        {
            res +=child_map[i];
        }
        return res;
    } 
};

// int main()
// {
//     vector<int> ratings = {1,0,2};
//     Solution sol;
//     int res = sol.candy(ratings);
//     cout << res << endl;
// }
// @lc code=end
