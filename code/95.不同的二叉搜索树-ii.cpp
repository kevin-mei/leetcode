/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (67.14%)
 * Likes:    776
 * Dislikes: 0
 * Total Accepted:    73K
 * Total Submissions: 108.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：3
 * 输出：
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释：
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 8
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//#include "pch.h"
// 二叉搜索树关键的性质是根节点的值大于左子树所有节点的值，小于右子树所有节点的值，且左子树和右子树也同样为二叉搜索树。
// 因此在生成所有可行的二叉搜索树的时候，假设当前序列长度为 n
// n，如果我们枚举根节点的值为 i，那么根据二叉搜索树的性质我们可以知道左子树的节点值的集合为[1…i−1]，右子树的节点值的集合为 [i+1…n]。
// 而左子树和右子树的生成相较于原问题是一个序列长度缩小的子问题，因此我们可以想到用回溯的方法来解决这道题目。

// 我们定义 generateTrees(start, end) 函数表示当前值的集合为 [start,end]，返回序列 [start,end] 生成的所有可行的二叉搜索树。
// 按照上文的思路，我们考虑枚举 [start,end] 中的值 i 为当前二叉搜索树的根，那么序列划分为了 [start,i−1] 和 [i+1,end] 两部分。
// 我们递归调用这两部分，即 generateTrees(start, i - 1) 和 generateTrees(i + 1, end)，获得所有可行的左子树和可行的右子树，
// 那么最后一步我们只要从可行左子树集合中选一棵，再从可行右子树集合中选一棵拼接到根节点上，并将生成的二叉搜索树放入答案数组即可。
// 递归的入口即为 generateTrees(1, n)，出口为当 start>end 的时候，当前二叉搜索树为空，返回空节点即可。

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreehelp(1, n);
    }

    // 当值集合为[start,end]时，返回所有可行的二叉搜索树
    vector<TreeNode*> generateTreehelp(int start, int end)
    {
        vector<TreeNode*> allTrees;
        if(start > end) // base case ,这里空树也要作为一个结点返回，不然会影响下一个的组成新的子树
        {
            allTrees.push_back(nullptr);
            return allTrees;
        }
        for(int i = start; i <= end; i++)
        {
            // 二叉搜索树的左右子树也是二叉搜索树
            vector<TreeNode*> leftTrees = generateTreehelp(start, i-1);
            vector<TreeNode*> rightTrees = generateTreehelp(i+1, end);

            //任选左右子树集合中的各一个，组成新的二叉搜索树
            // 因为空树也加到集合了里，所以这不用担心左右子树某一个为空的情况，导致没有生成新的树
            for (TreeNode *left : leftTrees)
            {
                for (TreeNode *right : rightTrees)
                {
                    TreeNode* root = new TreeNode(i); // 新建根结点
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};

// int main()
// {
//     int n =3;
//     Solution sol;
//     vector<TreeNode*> res = sol.generateTrees(n);
//     cout << res.size() << endl;
// }
// @lc code=end

