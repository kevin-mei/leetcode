/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

//#include "pch.h"

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 二叉树层序遍历也就是广度优先搜索遍历(广度和深度遍历 原指的是图的遍历方式)
        vector<vector<int>> res; //存放层序遍历的结果，一行为一层 
        if(nullptr == root)
        {
            return res;
        }
        std::queue<TreeNode*> queue_Node; //初始化一个辅助队列
        queue_Node.push(root); // 先存入根结点
        int currentSize = 0; //当前层的结点数量
        vector<int> level_Vect; 
        while (0 != queue_Node.size()) // 队列不为空进入循环
        {
            // 当前层的结点数量
            currentSize = queue_Node.size();

            for (int i = 0; i < currentSize; i++)
            {
                TreeNode *curNode = queue_Node.front();
                queue_Node.pop();
                // 保存当前层的结点值到level_Vect
                level_Vect.push_back(curNode->val);
                // 当当前结点的左右结点加到队列中，它们是下一层的结点
                if (nullptr != curNode->left)
                {
                    queue_Node.push(curNode->left);
                }
                if (nullptr != curNode->right)
                {
                    queue_Node.push(curNode->right);
                }
            }
            // 保存当前层结点访问结果到最终结果
            res.push_back(level_Vect);
            level_Vect.clear(); // 清空当前层结点
        }
        
        return res;
    }
};
// @lc code=end

