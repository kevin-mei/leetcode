/*
一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 classes ，其中 classes[i] = [passi, totali] ，表示你提前知道了第 i 个班级总共有 totali 个学生，其中只有 passi 个学生可以通过考试。

给你一个整数 extraStudents ，表示额外有 extraStudents 个聪明的学生，他们 一定 能通过任何班级的期末考。你需要给这 extraStudents 个学生每人都安排一个班级，使得 所有 班级的 平均 通过率 最大 。

一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数。平均通过率 是所有班级的通过率之和除以班级数目。

请你返回在安排这 extraStudents 个学生去对应班级后的 最大 平均通过率。与标准答案误差范围在 10-5 以内的结果都会视为正确结果。

 

示例 1：

输入：classes = [[1,2],[3,5],[2,2]], extraStudents = 2
输出：0.78333
解释：你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
示例 2：

输入：classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
输出：0.53485

提示：

1 <= classes.length <= 105
classes[i].length == 2
1 <= passi <= totali <= 105
1 <= extraStudents <= 105

*/
#include "pch.h"

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double maxAverage = 0.0;
        double totalAverage = 0.0;
        int classcount = classes.size();
        double before =-1, after=-1;
        int max_index = -1;
        // 优先级队列， 将{index,diff} 保存到优先级队列中
        // 其中index是把学生安排的具体班级的下标，diff是把这个学生安排到这个班级，安排前和安排后，该班通过率的差值
        // 假如只安排一个学生，那我们就找到所有班级对应diff的最大的那个班级，把学生安排进这个班级，最终的平均通过率也就最大
        // 平均通过率， 分母是classcount，不变，变化的是分子，分子就是diff最大的情况
        // 这里用优先级队列(大顶堆)来保存index,diff的对应关系，每次取堆顶diff最大的元素，找出对应的index班级下标
        // 把学生安排进这个班级，更新一次diff值
        // 时间复杂度O(mlgn)； m为extraStudents学生大小，n为班级的数量，每次往优先级队列插入，删除元素，lgn的时间复杂度
        auto compare = [](pair_diff a, pair_diff b) {
            return a.diff < b.diff;
        };
        std::priority_queue<pair_diff, vector<pair_diff>, decltype(compare)> pr_queue(compare);// 大顶堆
        // 初始化大顶堆
        for (int j = 0; j < classcount; j++)
        {
            vector<int> curclass = classes[j];
            before = (double)curclass[0] / curclass[1];
            after = (double)(curclass[0] + 1) / (curclass[1] + 1);
            double temp = after - before;
            pr_queue.push({j, temp});
        }

        for (int i = 0; i < extraStudents; i++)
        {
            pair_diff maxdiff = pr_queue.top();
            pr_queue.pop();
            int max_index = maxdiff.index;
            // 增加学生数
            classes[max_index][0]++;classes[max_index][1]++;
            // 更新队列
            before = (double)classes[max_index][0] / classes[max_index][1];
            after = (double)(classes[max_index][0]+ 1) / (classes[max_index][1] + 1);
            double temp = after - before;
            pr_queue.push({max_index, temp});
        }

        for (vector<int> curclass : classes)
        {
            totalAverage+=(double)curclass[0]/curclass[1];
        }
        return totalAverage/classcount;
    }

    struct pair_diff
    {
        int index;
        double diff;
    };
};

int main()
{
    // {{1,2},{3,5},{2,2}}
    vector<vector<int>> classes = {{2,4},{3,9},{4,5},{2,10}};
    Solution sol;
    int extraStudents = 2;
    double res = sol.maxAverageRatio(classes, extraStudents);
    cout << res<<endl;
    return 0;
}