/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (52.72%)
 * Likes:    976
 * Dislikes: 0
 * Total Accepted:    196.1K
 * Total Submissions: 371.5K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你可以运用递归和迭代两种方法解决这个问题吗？
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//#include "pch.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 1. 如果二叉树为空，则返回true
        // 2. 否则  对比二叉树的左右子树，是否相同
        // 注意 递归比较 为镜像比较  左子树的左子树和右子树的右子树进行比较，反之亦然
        if(nullptr == root)
        {
            return true;
        }
        return isSame(root->left, root->right);

    }

    bool isSame(TreeNode* left, TreeNode* right)
    {
        if (nullptr == left && nullptr == right)
        {
            return true;
        }
        else
        {
            // 只有一个节点为nullptr
            if (nullptr == left || nullptr == right)
            {
                return false;
            }

            if (left->val != right->val)
            {
                return false;
            }

            return isSame(left->left, right->right) && isSame(left->right, right->left);
        }
    }
};

// class Solution {
// public:
//     bool isSymmetric(TreeNode* root) {
//         // 1. 如果二叉树为空，则返回true
//         // 2. 否则  对比二叉树的左右子树，是否相同
//         // 迭代算法 利用队列，一次取两个节点，存4个节点？
//         if(nullptr == root)
//         {
//             return true;
//         }
//         std::queue<TreeNode*> queue_node;
//         queue_node.push(root->left);
//         queue_node.push(root->right);
//         bool res = false;
//         while(0 != queue_node.size())
//         {
//             TreeNode* left_node = queue_node.front();
//             queue_node.pop();
//             TreeNode* right_node = queue_node.front();
//             queue_node.pop();
//             if (nullptr == left_node && nullptr == right_node)
//             {
//                 res = true;
//             }
//             else
//             {
//                 // 只有一个节点为nullptr
//                 if (nullptr == left_node || nullptr == right_node)
//                 {
//                     res = false;
//                     break;
//                 }

//                 if (left_node->val != right_node->val)
//                 {
//                     res = false;
//                     break;
//                 }
//                 queue_node.push(left_node->left);
//                 queue_node.push(right_node->right);

//                 queue_node.push(left_node->right);
//                 queue_node.push(right_node->left);
//             }
//         }
//         return res;

//     }
// };
// @lc code=end