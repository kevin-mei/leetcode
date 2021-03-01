/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.08%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    158.4K
 * Total Submissions: 228.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helpbuild(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    // 语义：已知树的前序遍历为：preorder[preleft,preright]； 树的中序遍历为inorder[inleft, inright]
    // 返回还原的二叉树
    TreeNode* helpbuild(vector<int>& preorder, int preleft, int preright, 
                        vector<int>& inorder, int inleft, int inright)
    {
        if(preleft > preright || inleft > inright)
            return nullptr;
        // 根结点为先序遍历的第一个结点
        int rootvalue = preorder[preleft];
        // 题目说没有重复的元素，可根据中序遍历查找得到根结点的位置，也就区分来左右子树
        int rootindex = inleft;
        for(int i = inleft; i <= inright;i++)
        {
            if(inorder[i] == rootvalue)
            {
                rootindex = i;
            }
        }
        int leftTreelength = rootindex - inleft; // 左子树的长度
        int rightTreelength = inright-rootindex;
        TreeNode* root = new TreeNode(rootvalue);
        root->left = helpbuild(preorder, preleft+1, preleft+leftTreelength, 
                        inorder, inleft , rootindex - 1);
        root->right = helpbuild(preorder, preleft+leftTreelength+1, preright, 
                        inorder, rootindex + 1, inright);
        return root;
    }
};
// @lc code=end

