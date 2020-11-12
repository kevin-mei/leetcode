/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (75.29%)
 * Likes:    734
 * Dislikes: 0
 * Total Accepted:    302K
 * Total Submissions: 401.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "pch.h"
class Solution {
public:
    int maxDepth_1(TreeNode* root) {
        // 层序遍历 访问一层，深度+1
        int deepth = 0; //存放层序遍历的结果，一行为一层 
        if(nullptr == root)
            return deepth;
        std::queue<TreeNode*> queue_Node; //初始化一个辅助队列
        queue_Node.push(root); // 先存入根结点
        int currentSize = 0; //当前层的结点数量
        while (0 != queue_Node.size()) // 队列不为空进入循环
        {
            // 当前层的结点数量
            currentSize = queue_Node.size();
            for (int i = 0; i < currentSize; i++)
            {
                TreeNode *curNode = queue_Node.front();
                queue_Node.pop();
                // 当当前结点的左右结点加到队列中，它们是下一层的结点
                if (nullptr != curNode->left)
                    queue_Node.push(curNode->left);
                if (nullptr != curNode->right)
                    queue_Node.push(curNode->right);
            }
            // 当前层访问完毕，深度+1
            deepth++;
        }
        return deepth;
    }

    // 递归 看的题解的
    int maxDepth(TreeNode* root)
    {
        return nullptr == root?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
// @lc code=end

