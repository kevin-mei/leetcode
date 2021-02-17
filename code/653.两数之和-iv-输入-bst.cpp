/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (57.88%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 47.2K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 案例 1:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * 输出: True
 * 
 * 
 * 
 * 
 * 案例 2:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * 输出: False
 * 
 * 
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
    bool findTarget(TreeNode* root, int k) {
        bool res = false;
        // 先大概想下思路：
        // 二叉搜索树，左结点的值一定小于根结点，右结点的值一定大于根结点，要找到和为k的两个结点
        // 二叉树的中序遍历，可以得到有序的数组；
        // 问题转化为，在有序数组中，能否找到和为k的两个值，那么也就转化为leetcode 1的第一题，最后判断返回的vector大小即可
        vector<int> nums; // 保存中序遍历的结果
        midorder(root, nums); // 先中序遍历，得到有序数组
        vector<int>  res_vect = twoSum(nums, k);
        res = 0 == res_vect.size()? false:true;
        return res;
    }

    //需要实现的是 二叉树的中序遍历，这里使用递归
    void midorder(TreeNode* root, vector<int> &nums)
    {
        // 中序遍历的概念，回顾一下，概念一出，代码也就出来了：
        // 如果二叉树的根结点为空，则直接返回，否则，则中序遍历左子树，在遍历根结点，最后中序遍历右子树
        if(nullptr == root) return;
        midorder(root->left, nums);
        nums.push_back(root->val);
        midorder(root->right, nums);
    }

    // 这里把leetcode 1直接拷贝过来
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 用额外n的空间存储target - nums[i] 的差值
        // map_data 保存 <差值，下标> 数组元素有可能相同，就会有相同的差值，这时候i覆盖
        // 题中说只有一个正确答案，这时候i覆盖的情况，也不会是正确答案，如果是，则不只一个答案了
        std::unordered_map<int, int> map_data;
        // 遍历一遍，一边判断当前nums[i]是否在map_data的keys中能找到，能找到说明是正确答案，找到对应value，就是上一个数的下标
        // 没找到就map_data[差值] = i;把<差值，下标>保存到map中
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map_data.find(nums[i]) != map_data.end())
            {
                res.push_back(map_data[nums[i]]);
                res.push_back(i);
            }
            else
            {
                int dest = target - nums[i];
                map_data[dest] = i;
            }
        }
        return res;
    }
};
// @lc code=end

