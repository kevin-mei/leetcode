/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode* convertBST(TreeNode* root) {
        // 二叉搜索树的 中序遍历是升序，那修改下也可以变成降序
        // 在来一个遍历，记录从大到小的和，每个遍历到当前节点时，sum加上当前节点的值，累加树当前节点的值就是sum
        tranverse(root);
        return root;
    }

    void tranverse(TreeNode* root)
    {
        if(nullptr == root)
            return;
        tranverse(root->right);
        sum+=root->val;
        root->val = sum;
        tranverse(root->left);
    }

private:
    long long sum = 0;
};
// @lc code=end

