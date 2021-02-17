/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (55.20%)
 * Likes:    591
 * Dislikes: 0
 * Total Accepted:    173.4K
 * Total Submissions: 314K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = []
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4 
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
class Solution {
public:
    //左子树有3层，平衡，右子树为空树，平衡，那么这个树不平衡，所以左右子树的平衡心传导不到根结点上
    // 递归算一下二叉树的高度
    // 左右子树的高度相差大于1，则不平衡，否则平衡
    bool isBalanced(TreeNode* root) {
        if (nullptr == root)
            return true;
        // 这里还是要递归
        // 树中每一颗子树都要平衡，整棵树才平衡    
        int heightleft = getTreeHeight(root->left);
        int heightright = getTreeHeight(root->right);
        if (abs(heightleft - heightright) > 1)
            return false;
        else
            return isBalanced(root->left) && isBalanced(root->right);
    }

    // 递归算一下二叉树的高度
    int getTreeHeight(TreeNode *root)
    {
        if (nullptr == root)
            return 0;
        int heightleft = 1 + getTreeHeight(root->left);
        int heightright = 1 + getTreeHeight(root->right);
        return heightleft > heightright ? heightleft : heightright;
    }
};
// @lc code=end

