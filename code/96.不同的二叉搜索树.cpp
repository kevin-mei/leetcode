/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (69.30%)
 * Likes:    1001
 * Dislikes: 0
 * Total Accepted:    104.2K
 * Total Submissions: 150.3K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 *   a     b         c      d          e
 * 
 */

// @lc code=start
//#include "pch.h"
class Solution {
public:
    // 要求二叉搜索树的种类，这个应该是有一个公式，
    // 查找leetcode的题解，知道这个种类的个数，是卡特兰数（编程里同一个序列出栈的不同序列，也是这个数）：https://baike.baidu.com/item/卡特兰数/6125746
    // 自己推导：需要先判断二叉搜索树的不同是怎么不同？这里应该是 所有的树中序遍历都相等，树是等价的；等价的这种树有多少类
    // 满足某一种条件，应该都是不一样：1. 高度不同 2. 同一拓扑结构结点的值不同，如例子中的b,e， 3. 具有不同的拓扑结构 a,e
    // 目前看起来比较难实现；先看看大神的解法 查看leetcode,
    // 用动态规划， 官方题解比较清楚： https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode-solution/
    int numTrees(int n) {
        // G(n) 表示n个序列组成的二叉搜索树种类  G(0) = 1; G(1) = 1; 分别对应0个结点空树，和1个结点，根结点的情况；
        // 递推式：G(n) = 求和{G(i-1)*G(n-i)} (i=[1,n] ) 
        // 展开：G(n) = G(0)*G(n-1)+G(1)*G(n-2) + ... + G(n-1)*G(0) (n≥2) 

        vector<int> G(n+1, 0);
        G[0]=1;
        G[1]=1;

        for(int i =2; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                G[i] += G[j-1] * G[i-j];
            }
        }
        return G[n];
    }
};

// int main()
// {
//     int n = 3;
//     Solution sol;
//     int res = sol.numTrees(n);
//     cout << res << endl;
// }
// @lc code=end

