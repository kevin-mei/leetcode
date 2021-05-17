/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (68.81%)
 * Likes:    488
 * Dislikes: 0
 * Total Accepted:    246.2K
 * Total Submissions: 357.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,null,2,3]
 * 输出：[1,2,3]
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
 * 输出：[1,2]
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
 * 进阶：递归算法很简单，你可以通过迭代算法完成吗？
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
class Solution_1 {
public:
    // 先递归求解
    // 二叉树的前序遍历
    // 如果二叉树为空，则返回，否则先访问根结点，再前序遍历左子树，接着前序遍历右子树
    vector<int> preorderTraversal_1(TreeNode* root) {
        if(nullptr == root)
            return res;
        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if(nullptr != root) s.push(root);
        while(!s.empty())
        {
            TreeNode* curnode = s.top();s.pop();res.push_back(curnode->val);
            if(nullptr != curnode->right) s.push(curnode->right);
            if(nullptr != curnode->left) s.push(curnode->left);
        }

        return res;
    }

    // 迭代算法
    // 利用栈做个迭代
    // 主函数，在局部反复调用visitAlongLeftBranch例程
    vector<int> preorderTraversal_2(TreeNode* root) {
        stack<TreeNode*> s;
        while(true)
        {
            // 访问子树的左侧链，右子树入栈
            visitAlongLeftBranch<PVISIT>(root, visit, s);
            if(s.empty()) break;
            root = s.top();
            s.pop();
        }
        return res;
    }

    // 定义一个历程，用来依次访问二叉数的左子树，并将当前结点的右子树入栈
    // 直到该二叉树的左子树为空
    //template <typename VST>
    // 普通版
    // void visitAlongLeftBranch_1(
    //     TreeNode* root,
    //     stack<TreeNode*> &S )
    // {
    //     while(root)
    //     {
    //         visit(root->val);
    //         S.push(root->right);
    //         root = root->left;
    //     }
    // }

    // 函数指针版
    //typedef void (*pvisit)(int, vector<int>&);
    // void visitAlongLeftBranch(
    //     TreeNode* root,
    //     void (*pvisit)(int, vector<int>&),
    //     stack<TreeNode*> &S )
    // {
    //     while(root)
    //     {
    //         (*pvisit)(root->val, res);
    //         S.push(root->right);
    //         root = root->left;
    //     }
    // }

    // 模版函数版
    typedef void (*PVISIT)(int, vector<int>&);
    template <typename VST>
    void visitAlongLeftBranch(
        TreeNode* root,
        VST pvisit,
        stack<TreeNode*> &S )
    {
        while(root)
        {
            pvisit(root->val, res);
            S.push(root->right);
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

class Solution
{
public:
    // void visitAlongLeftBranch(TreeNode* root, vector<int> &visit, stack<TreeNode*> &s)
    // {
    //     while(nullptr!=root)
    //     {
    //         // 访问当前节点
    //         visit.push_back(root->val);
    //         s.push(root->right); // 左子树入栈
    //         root = root->left; // 沿着左侧链往下
    //     }
    // }

    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode*> s;
    //     if(nullptr != root) s.push(root);
    //     while(!s.empty())
    //     {
    //         TreeNode* curnode = s.top();s.pop();
    //         visitAlongLeftBranch(curnode, res, s);
    //     }

    //     return res;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int> &visited)
    {
        if(nullptr == root)
            return;
        visited.push_back(root->val);
        helper(root->left, visited);
        helper(root->right, visited);
    }

};

// // 函数指针版
// void visitAlongLeftBranch(
//     void (*pvisit)(int), int val)
// {
//     (*pvisit)(val);
// }
// // void (*pvisit)(int)
// void visit(int val)
// {
//     //res.push_back(val);
//     std::cout << val;
// }

// int main()
// {
//     Solution sol;
//     sol.preorderTraversal(nullptr);
//     return 0;
// }
// @lc code=end

