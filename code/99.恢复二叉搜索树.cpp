/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (61.93%)
 * Likes:    467
 * Dislikes: 0
 * Total Accepted:    54.8K
 * Total Submissions: 88.5K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。
 * 
 * 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,3,null,null,2]
 * 输出：[3,1,null,null,2]
 * 解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [3,1,4,null,null,2]
 * 输出：[2,1,4,null,null,3]
 * 解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树上节点的数目在范围 [2, 1000] 内
 * -2^31 
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
    void recoverTree(TreeNode* root) {
        vector<pair<int, TreeNode*>> node_vect;
        // 先中序遍历二叉搜索树，保存节点到vect
        midorder(root, node_vect);
        // 看看是否符合升序排列，找出不符合的下标，存入index_vect
        vector<int> index_vect;
        for(int i =0; i < node_vect.size()-1;i++)
        {
            if(node_vect[i].first > node_vect[i+1].first)
            {
                index_vect.push_back(i);
            }
        }
        if(2 == index_vect.size())
            swap(node_vect[index_vect[0]].second->val, node_vect[index_vect[1]+1].second->val);
        else if(1 == index_vect.size())
            swap(node_vect[index_vect[0]].second->val, node_vect[index_vect[0]+1].second->val);
    }

    void midorder(TreeNode* root, vector<pair<int, TreeNode*>> &node_vect)
    {
        if(nullptr == root)
            return;
        midorder(root->left, node_vect);
        node_vect.push_back({root->val, root});
        midorder(root->right, node_vect);
    }
};
// @lc code=end

