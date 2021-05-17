/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Medium (68.78%)
 * Likes:    435
 * Dislikes: 0
 * Total Accepted:    140.6K
 * Total Submissions: 204.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层序遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层序遍历为：
 * 
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (nullptr == root)
            return res;
        queue<TreeNode *> q;     // q始终存放着一层的结点数量
        q.push(root);            // 根结点先入队
        vector<int> levelresult; // 一层结点的遍历结果
        while (!q.empty())
        {
            int currentsize = q.size(); //当前层的结点梳理

            for (int i = 0; i < currentsize; i++)
            {
                TreeNode *curnode = q.front();
                q.pop();
                levelresult.push_back(curnode->val);
                if (nullptr != curnode->left)
                    q.push(curnode->left);
                if (nullptr != curnode->right)
                    q.push(curnode->right);
            }
            // 一层结点访问完毕
            res.push_back(levelresult); // 保存当前层访问结果到最终结果
            levelresult.clear();        //清空当前层的结果
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

