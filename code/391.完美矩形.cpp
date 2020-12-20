/*
 * @lc app=leetcode.cn id=391 lang=cpp
 *
 * [391] 完美矩形
 *
 * https://leetcode-cn.com/problems/perfect-rectangle/description/
 *
 * algorithms
 * Hard (29.26%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 7.7K
 * Testcase Example:  '[[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]'
 *
 * 我们有 N 个与坐标轴对齐的矩形, 其中 N > 0, 判断它们是否能精确地覆盖一个矩形区域。
 * 
 * 每个矩形用左下角的点和右上角的点的坐标来表示。例如， 一个单位正方形可以表示为 [1,1,2,2]。 ( 左下角的点的坐标为 (1, 1)
 * 以及右上角的点的坐标为 (2, 2) )。
 * 
 * 
 * 
 * 示例 1:
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4],
 * ⁠ [1,3,2,4],
 * ⁠ [2,3,3,4]
 * ]
 * 
 * 返回 true。5个矩形一起可以精确地覆盖一个矩形区域。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * rectangles = [
 * ⁠ [1,1,2,3],
 * ⁠ [1,3,2,4],
 * ⁠ [3,1,4,2],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * 返回 false。两个矩形之间有间隔，无法覆盖成一个矩形。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 3:
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [3,2,4,4]
 * ]
 * 
 * 返回 false。图形顶端留有间隔，无法覆盖成一个矩形。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 4:
 * 
 * rectangles = [
 * ⁠ [1,1,3,3],
 * ⁠ [3,1,4,2],
 * ⁠ [1,3,2,4],
 * ⁠ [2,2,4,4]
 * ]
 * 
 * 返回 false。因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
 * 
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // 完美矩形
        // https://mp.weixin.qq.com/s/PL7h_5hx6XZ1hEyVVusRBA
        // 面积角度 大矩形的面积应等于小矩形的面积，不等于说明有缺的
        // 先算出 最终形成矩形的左下角顶点坐标和右下角顶点坐标
        int x1 = INT_MAX, y1= INT_MAX, x2 = INT_MIN, y2= INT_MIN;
        int sum_area = 0; // 小矩形的面积
        std::map<pair<int,int>, int> angle_map;
        for (vector<int> rectangle : rectangles)
        {
            x1 = min(x1, rectangle[0]);
            y1 = min(y1, rectangle[1]);
            x2 = max(x2, rectangle[2]);
            y2 = max(y2, rectangle[3]);
            // 求小矩形的面积和
            sum_area+=areaRect(rectangle);
            //记录顶点出现的次数
            vector<pair<int,int> > angles = {{rectangle[0],rectangle[1]},{rectangle[2],rectangle[3]},
                                            {rectangle[0],rectangle[3]},{rectangle[2],rectangle[1]}};
            for (pair<int, int> angle : angles)
            {
                if (angle_map.end() != angle_map.find(angle))
                {
                    angle_map.erase(angle);
                }
                else
                {
                    angle_map[angle]++;
                }
            }
        }
        // 然后算小矩形的面积之和是否等于大矩形的面积，不等返回false
        if(sum_area != areaRect({x1,y1,x2,y2}))
            return false;
        // 面积相等，还需要从顶点角度排除掉是否有重合的情况
        // 顶点角度 完美矩形只能有4个顶点
        // 如何知道一个点是不是顶点
        // 如果这个点 是2个，4个矩形的顶点，偶数个，它不是一个顶点
        //          是1个，3个矩形的顶点，奇数个，它是一个顶点
        // 我们要筛选出出现奇数次的顶点，也就是最终组成矩形的顶点数
        // 可以用一个map<pair<int,int>, int> <顶点数，次数>来记录
        // 最终遍历map,求出奇数个顶点
        if(angle_map.size() != 4)
            return false;
        if(angle_map.end() == angle_map.find({x1,y1})) return false;
        if(angle_map.end() == angle_map.find({x1,y2})) return false;
        if(angle_map.end() == angle_map.find({x2,y1})) return false;
        if(angle_map.end() == angle_map.find({x2,y2})) return false;
        return true;
    }

    // 计算给定矩形的面积
    int areaRect(vector<int> rectangle)
    {
        return (rectangle[2] - rectangle[0]) * (rectangle[3] - rectangle[1]); 
    }
};

// int main()
// {
//     Solution sol;
//     vector<vector<int> > rectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
//     bool res = sol.isRectangleCover(rectangles);
//     std::cout << res << std::endl;
// }
// @lc code=end

