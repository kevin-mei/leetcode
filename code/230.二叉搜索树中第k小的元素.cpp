/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int kthSmallest(TreeNode* root, int k) {
        tranverse(root, k);
        return res;
    }

    void tranverse(TreeNode* root, int k)
    {   // 中序遍历，如果根节点为空，则返回，否则先中序遍历左子树，再访问根节点，再中序遍历右子树
        if(nullptr == root)
            return;
        tranverse(root->left, k);
        count++;
        if(k == count)
        {
            res = root->val;
        }
        tranverse(root->right, k);
    }


private:
    int res=-1;
    int count = 0;
};
// @lc code=end

