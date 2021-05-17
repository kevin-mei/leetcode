/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Medium (74.48%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    228.9K
 * Total Submissions: 307.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
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
class Solution {
public:
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     helper(root, res);
    //     return res;
    // }

    // void helper(TreeNode* root, vector<int> &visited)
    // {
    //     if(nullptr == root)
    //         return;
    //     helper(root->left, visited);
    //     helper(root->right, visited);
    //     visited.push_back(root->val);
    // }

  struct MyTreeNode
  {
    int val;
    MyTreeNode *parent;
    MyTreeNode *left;
    MyTreeNode *right;
    MyTreeNode() : val(0), parent(nullptr), left(nullptr), right(nullptr) {}
    MyTreeNode(int x) : val(x), parent(nullptr), left(nullptr), right(nullptr) {}
    MyTreeNode(int x, MyTreeNode *parent, MyTreeNode *left, MyTreeNode *right) : val(x), parent(parent), left(left), right(right) {}
  };
  void rebuildBinaryTree(TreeNode *root, MyTreeNode *myroot)
  {
    if (nullptr == root)
      return;
    myroot->val = root->val;
    if (nullptr != root->left)
    {
      MyTreeNode *myleft = new MyTreeNode();
      myleft->parent = myroot;
      myroot->left = myleft;
      rebuildBinaryTree(root->left, myleft);
    }
    if (nullptr != root->right)
    {
      MyTreeNode *myright = new MyTreeNode();
      myright->parent = myroot;
      myroot->right = myright;
      rebuildBinaryTree(root->right, myright);
    }
    return;
  }

  void gotoLeftmostLeaf(stack<MyTreeNode *> &s)
  {
    while (MyTreeNode *curnode = s.top()) // 自顶而下反复检查栈顶结点
    {
      if (nullptr != curnode->left) // 尽可能向左遍历
      {
        if (nullptr != curnode->right) // 如果有右孩子，则右孩子优先入栈
        {
          s.push(curnode->right);
        }
        s.push(curnode->left); // 然后转向左孩子
      }
      else                      // 实不得已。没有左孩子，则右孩子入栈
        s.push(curnode->right); // 这里不用对右孩子判空么
    }
    s.pop();
  }

  vector<int> postorderTraversal(TreeNode *root)
  {
    vector<int> res;
    MyTreeNode *myroot = nullptr == root ? nullptr : new MyTreeNode();
    rebuildBinaryTree(root, myroot);
    stack<MyTreeNode *> s;
    MyTreeNode *curnode = myroot;
    if (nullptr != curnode)
      s.push(curnode); // 根结点首先入栈
    while (!s.empty())
    {
      if (s.top() != curnode->parent) // 如栈顶非curnode的父结点，应该是右侧的兄弟兄弟结点
        gotoLeftmostLeaf(s);          // 则在其左子树中找到最靠左的叶子结点，
      curnode = s.top();
      s.pop();                     // 此时栈顶curnode已经是最靠左的叶子结点，
      res.push_back(curnode->val); // 访问curnode
    }
    return res;
  }
};
// @lc code=end

