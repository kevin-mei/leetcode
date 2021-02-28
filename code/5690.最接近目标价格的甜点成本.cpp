/*
你打算做甜点，现在需要购买配料。目前共有 n 种冰激凌基料和 m 种配料可供选购。而制作甜点需要遵循以下几条规则：

必须选择 一种 冰激凌基料。
可以添加 一种或多种 配料，也可以不添加任何配料。
每种类型的配料 最多两份 。
给你以下三个输入：

baseCosts ，一个长度为 n 的整数数组，其中每个 baseCosts[i] 表示第 i 种冰激凌基料的价格。
toppingCosts，一个长度为 m 的整数数组，其中每个 toppingCosts[i] 表示 一份 第 i 种冰激凌配料的价格。
target ，一个整数，表示你制作甜点的目标价格。
你希望自己做的甜点总成本尽可能接近目标价格 target 。

返回最接近 target 的甜点成本。如果有多种方案，返回 成本相对较低 的一种。

示例 1：

输入：baseCosts = [1,7], toppingCosts = [3,4], target = 10
输出：10
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 7
- 选择 1 份 0 号配料：成本 1 x 3 = 3
- 选择 0 份 1 号配料：成本 0 x 4 = 0
总成本：7 + 3 + 0 = 10 。
示例 2：

输入：baseCosts = [2,3], toppingCosts = [4,5,100], target = 18
输出：17
解释：考虑下面的方案组合（所有下标均从 0 开始）：
- 选择 1 号基料：成本 3
- 选择 1 份 0 号配料：成本 1 x 4 = 4
- 选择 2 份 1 号配料：成本 2 x 5 = 10
- 选择 0 份 2 号配料：成本 0 x 100 = 0
总成本：3 + 4 + 10 + 0 = 17 。不存在总成本为 18 的甜点制作方案。
示例 3：

输入：baseCosts = [3,10], toppingCosts = [2,5], target = 9
输出：8
解释：可以制作总成本为 8 和 10 的甜点。返回 8 ，因为这是成本更低的方案。
示例 4：

输入：baseCosts = [10], toppingCosts = [1], target = 1
输出：10
解释：注意，你可以选择不添加任何配料，但你必须选择一种基料。
 

提示：

n == baseCosts.length
m == toppingCosts.length
1 <= n, m <= 10
1 <= baseCosts[i], toppingCosts[i] <= 104
1 <= target <= 104
*/
#include "pch.h"

class Solution
{
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target)
    {
        // 先排序，所有出现的价格由低到高，方便后面做递归剪枝处理
        sort(baseCosts.begin(), baseCosts.end());
        sort(toppingCosts.begin(), toppingCosts.end());

        // 找出重叠子问题，就可以递归 
        // 一种冰淇淋的基料，对应多种配料的情况：
        // 每次计算冰淇淋的花费，都需要基料 +0，+1，+2倍的toppingCost做判断
        // 假设只有1种配料，你的价格只有3种情况，base1 = base+ 0*top1; base2 =base+ 1*top1; base3=base+ 2*top1;
        // 假设只有2种配料，你的价格能不能也变成3种情况，可以，把上一种的花费的结果当成这一次的basecost，对它来说也就有3种情况
        //    当上一个花费为base1时，cost有三种情况：base1+ 0*top2; base1+ 1*top2; base1+ 2*top2;
        //    当上一个花费为base2时，cost有三种情况：base2+ 0*top2; base2+ 1*top2; base2+ 2*top2;
        //    当上一个花费为base3时，cost有三种情况：base3+ 0*top2; base3+ 1*top2; base3+ 2*top2;
        // 这样就可以看出来重叠子问题了
        // 每次递归前，需要更新下本次递归的basecost，剩下就计算 basecost +0，+1，+2倍的toppingCost，得到本次递归的三种花费
        // 然后对这三种花费，在分别传入下一个配料的计算过程；
        for (int bastCost : baseCosts)
        {
            help(bastCost, 0, toppingCosts, target);
            if (0 == close_diff) // 如果对于基料bastCost，已经得到目标值，则直接返回
                return cloes_res;
        }
        return cloes_res;
    }

    // 递归函数语义：
    // 当冰激凌基料价格为bastCost时，计算从第i个配料开始直到最后一个配料，每种配料0，1，2份，冰淇淋花费的价格
    // 在计算过程更新花费最接近target的解 cloes_res close_diff
    void help(int bastCost, int i, vector<int> &toppingCosts, int target)
    {
        // printIndent(_tabCount++);  // 进入递归前tabcount 计数+1
        // printf("bastCost[%d], i[%d]\n", bastCost, i);
        int next_baseCost = 0; //下一个配料的基础花费
        if(i < toppingCosts.size())
        {
            int toppingCost = toppingCosts[i];
            // 基料+0个配料
            next_baseCost = calculateCost(bastCost, toppingCost, 0, target);
            if (i + 1 < toppingCosts.size() && next_baseCost < target)
                help(next_baseCost, i + 1, toppingCosts, target);
            // 基料+1个配料
            next_baseCost = calculateCost(bastCost, toppingCost, 1, target);
            if (i + 1 < toppingCosts.size() && next_baseCost < target)
                help(next_baseCost, i + 1, toppingCosts, target);
            // 基料+2个配料
            next_baseCost = calculateCost(bastCost, toppingCost, 2, target);
            if (i + 1 < toppingCosts.size() && next_baseCost < target)
                help(next_baseCost, i + 1, toppingCosts, target);
        }
        // printIndent(--_tabCount); //递归退出时，tabcount 计数-1
        // printf("cloes_res=[%d]\n", cloes_res);

    }

    // 计算bastCost+count*toppingCost的花费，并返回
    int calculateCost(int bastCost, int toppingCost, int count, int target)
    {
        int next_baseCost = bastCost + count * toppingCost;
        updateResult(next_baseCost, target);
        return next_baseCost;
    }

    // 根据当前的冰淇淋花费cost和目标值,更新最接近target的花费
    void updateResult(int cost, int target)
    {
        int diff = abs(cost - target);
        if (diff < close_diff)
        {
            close_diff = diff;
            cloes_res = cost;
        }
    }

    // 输入 n，打印 n 个 tab 缩进
    void printIndent(int n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("   ");
        }
    }

private:
    int _tabCount = 0;
    int cloes_res = 0; // 最接近的花费
    int close_diff = INT_MAX; // 本次花费和target相差的绝对值
};

int main()
{
    vector<int> baseCosts = {4152,7816,5153,1641,3402,5201};//,4152,7816,5153,1641,3402,5201
    vector<int> toppingCosts = {650,447,173,4843};//650,447,173,4843
    int target = 9775;//9788
    Solution sol;
    int output = sol.closestCost(baseCosts, toppingCosts, target);
    cout << output << endl;
    return 0;
}