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
    vector<vector<int>> levelOrder_1(TreeNode* root) {
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

    vector<vector<int>> levelOrder_2(TreeNode *root)
    {
        vector<vector<int>> res;
        if (nullptr == root)
            return res;
        queue<TreeNode *> q;     // q始终存放着一层的结点数量
        q.push(root);            // 根结点先入队
        vector<int> levelresult; // 一层结点的遍历结果
        while (!q.empty())
        {
            int currentsize = q.size(); //当前层的结点梳理

            for (int i = 0; i < currentsize; i++)
            {
                TreeNode *curnode = q.front();
                q.pop();
                levelresult.push_back(curnode->val);
                if (nullptr != curnode->left)
                    q.push(curnode->left);
                if (nullptr != curnode->right)
                    q.push(curnode->right);
            }
            // 一层结点访问完毕
            res.push_back(levelresult); // 保存当前层访问结果到最终结果
            levelresult.clear();        //清空当前层的结果
        }
        return res;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (!root)
            return result;
        queue<TreeNode *> q;
        q.push(root);
        q.push(nullptr); // 插入一个nullptr作为一层的分割点
        vector<int> cur_vec;
        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t == nullptr) // 访问到分层的一点
            {
                result.push_back(cur_vec); // 保存当前层访问结果到最终结果
                cur_vec.resize(0);         //清空当前层的结果
                if (q.size() > 0)          // 此时队列不为空，说明新的一层的结点已经添加进队列
                {
                    q.push(nullptr); // 增加分层的分割点
                }
            }
            else
            {
                cur_vec.push_back(t->val);
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
            }
        }
        return result;
    }

    void helper(vector<vector<int>> &ans, TreeNode *node, int level)
    {
        if (nullptr == node)
            return;
        if (level >= ans.size())
            ans.push_back({});
        ans[level].push_back(node->val);
        helper(ans, node->left, level + 1);
        helper(ans, node->right, level + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        helper(res, root, 0);
        return res;
    }
};

// @lc code=end

