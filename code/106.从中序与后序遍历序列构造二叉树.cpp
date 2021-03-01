/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (71.26%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    91K
 * Total Submissions: 127.6K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helpbuild(inorder, 0, inorder.size()-1, postorder, 0 , postorder.size()-1);
    }

    // 语义： 给定中序遍历inorder[inleft,inright] 和后序遍历postorder[postleft, postright]
    // 返回 还原后的二叉树
    TreeNode* helpbuild(vector<int>& inorder, int inleft, int inright,
                        vector<int>& postorder, int postleft, int postright) 
    {
        if(inleft > inright || postleft > postright)
            return nullptr;
        // 根结点在后续遍历的最后一个
        int rootvalue = postorder[postright];
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
        TreeNode* root = new TreeNode(rootvalue);
        root->left = helpbuild(inorder, inleft , rootindex - 1, 
                        postorder, postleft, postleft + leftTreelength-1);
        root->right = helpbuild(inorder, rootindex + 1, inright, 
                        postorder, postleft+leftTreelength, postright-1);
        return root;
    }

};
// @lc code=end

