/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root)
    {
        if(nullptr == root)
            return "#";
        string left = traverse(root->left);
        string right = traverse(root->right);

        string subtree = left + ','+right + ','+ to_string(root->val);
        
        hashmap[subtree]++;
        // 结果出现两次的  当第大于两次的时候，不会重复添加
        if(2 == hashmap[subtree])
        {
            res.push_back(root);
        }
        return subtree;
    }

private:
    vector<TreeNode*> res;
    std::unordered_map<string, int> hashmap;
};
// @lc code=end

