/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // bool isValidBST(TreeNode* root) {
    //     return helper(root, LONG_MIN, LONG_MAX);
    // }

    // bool helper(TreeNode* root, long minval, long maxval)
    // {
    //     bool res = true;
    //     if(nullptr == root)
    //         return res;
    //     if(root->left)
    //     {
    //         bool temp = (minval < root->left->val)  && (root->left->val < maxval);
    //         res =  root->left->val < root->val && temp && helper(root->left, minval, root->val);
    //     }
            
    //     if(res && root->right)
    //     {
    //         bool temp = (minval < root->right->val)  && (root->right->val < maxval);
    //         res =  root->val < root->right->val && temp && helper(root->right, root->val, maxval);
    //     }
            
    //     return res;
    // }


    bool helper(TreeNode* root, long long lower, long long upper) {
        if (root == nullptr) {
            return true;
        }
        if (root -> val <= lower || upper <= root -> val ) {
            return false;
        }
        return helper(root -> left, lower, root -> val) && helper(root -> right, root -> val, upper);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }

};

// @lc code=end

