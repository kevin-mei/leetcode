/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(nullptr == root || nullptr == p || nullptr==q )
            return nullptr;
        // 公共祖先，一定是 p->val< root->val < q->val ||  q->val< root->val < p->val
        // 公共祖先可能是节点本身 ，增加等于这个条件p->val<= root->val <= q->val  ||  q->val<= root->val <= p->val
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(root->val < p->val && root->val < q->val )
            return lowestCommonAncestor(root->right, p, q);
        else 
            return root; //p->val<= root->val <= q->val  ||  q->val<= root->val <= p->val
    }
};
// @lc code=end

