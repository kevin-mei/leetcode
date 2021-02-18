/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        // 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
        // 展开后的单链表应该与二叉树 先序遍历 顺序相同。
        if(nullptr == root)
            return;
        // 先序遍历： 根节点为空，则直接返回，否则先访问根节点，再先序遍历左子树，最后先序遍历右子树
        // flatten 的语义是：把一个数变成单链表
        flatten(root->left); // 相信语义，先把左子树称为单链表
        flatten(root->right);// 再把右子树称为单链表

        // 然后我们将右子树接到左子树上
        // 左子树本来就有右孩子，那怎么整，一直遍历到左子树最后一个右孩子，然后再把右子树接上
        if (nullptr != root->left)
        {
            // 得到最后左子树上的最后一个孩子节点，它的右子树一定为空，
            TreeNode *lastleftBranchChild = root->left; 
            while (nullptr != lastleftBranchChild->right)
            {
                lastleftBranchChild = lastleftBranchChild->right;
            }
            lastleftBranchChild->right = root->right; // 然后再把根节点的右子树接上
            root->right = root->left; // 根节点的右孩子更换为左孩子
            root->left = nullptr; // 根节点的左孩子为空
        }
    }
};
// @lc code=end

