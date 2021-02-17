/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (74.80%)
 * Likes:    856
 * Dislikes: 0
 * Total Accepted:    346.5K
 * Total Submissions: 463.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回它的 中序 遍历。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：[1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：root = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：root = [1,null,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [0, 100] 内
 * -100 
 * 
 * 
 * 
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    // 递归版本
    vector<int> inorderTraversal_1(TreeNode* root) {
        if(nullptr == root)
            return res;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }


    // 迭代算法
    // 利用栈做个迭代
    // 主函数，在局部反复调用goAlongLeftBranch
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        while(true)
        {
            // 访问子树的左侧链，右子树入栈
            goAlongLeftBranch(root, s);
            if(s.empty()) break;
            root = s.top();
            s.pop();
            visit(root->val, res);
            root = root->right;
        }
        return res;
    }

    typedef void (*PVISIT)(int, vector<int>&);
    void goAlongLeftBranch(
        TreeNode* root,
        stack<TreeNode*> &S )
    {
        while(root)
        {
            S.push(root);
            root = root->left;
        }
    }

    static void visit(int val, vector<int> &res_vect)
    {
        res_vect.push_back(val);
    }
private:
    vector<int> res;
};
// @lc code=end

