/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructHelp(nums, 0, nums.size()-1);
    }

    // 语义：对数组nums的[left, right]范围内的数组组成最大二叉树
    TreeNode* constructHelp(vector<int>& nums, int left, int right)
    {
        if(left > right)
        {
            return nullptr;
        }
        int maxIndex =  left;
        int maxValue =nums[left];
        for(int i = left+1; i <= right;i++)
        {
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        TreeNode *root = new TreeNode(maxValue);
        root->left = constructHelp(nums, left, maxIndex - 1);
        root->right = constructHelp(nums, maxIndex+1, right);
        return root;
    }
};

// int main()
// {
//     vector<int> nums = {1,3,2};
//     Solution sol;
//     TreeNode *res = sol.constructMaximumBinaryTree(nums);
//     cout << "pause" << endl;
// }
// @lc code=end

