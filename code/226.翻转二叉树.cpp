/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
#include "pch.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // 翻转一课二叉树，为空，则返回，否则则交换当前节点的左右子树；再递归翻转左子树，右子树
        if(nullptr == root)
            return root;
        // TreeNode* temp = root->left;
        // root->left = root->right;
        // root->right = temp;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
// @lc code=end

