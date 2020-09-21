/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(nullptr == root)
        {
            return res;
        }
        std::queue<TreeNode*> queue_Node;
        queue_Node.push(root);
        int currentSize = 0; //当前层的结点数量
        double curSum = 0; // 当前层结点数值总和

        while (0 != queue_Node.size())
        {
            currentSize = queue_Node.size();

            for (int i = 0; i < currentSize; i++)
            {
                TreeNode *curNode = queue_Node.front();
                queue_Node.pop();
                curSum += (double)curNode->val;
                if (nullptr != curNode->left)
                {
                    queue_Node.push(curNode->left);
                }
                if (nullptr != curNode->right)
                {
                    queue_Node.push(curNode->right);
                }
            }
            
            res.push_back((double)curSum/currentSize);
            curSum = 0; // 重置当前层的结点数值总和
        }
        
        return res;
    }
};
// @lc code=end

