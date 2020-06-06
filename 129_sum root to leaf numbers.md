#### 题目

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026

题目理解： 给定一个二叉树，让你找叶子节点，从根节点到叶子节点的路径代表一个数字，4->9->5代表495，每多一层，节点上的数字位数就高一位（这里可以用pow(10,y)， y是结点所在的层数，根节点默认为0层），求所有到叶子结点路径所代表的数之和；

还是用DFS最合适，这里再额外用一个vector<int> 来存放路径，每访问一个结点，就push_back该结点的元素， 访问到叶子结点的时候，将该路径代表的数加到sum上（vector<int>的值从后往前访问，每访问一个数位数加+1），访问完了，叶子结点pop, 在回溯找另一个没访问过的结点；

代码如下：
```
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
    int sumNumbers(TreeNode* root) {
		if (NULL == root)
			return 0;

		int sum = 0;
		vector<int> pathNum; // 从跟结点到叶子结点的路径

		set<TreeNode*> set; // 用一个set保存已访问过的结点
		stack<TreeNode*> stackTree;

		stackTree.push(root);
		pathNum.push_back(root->val);
		set.insert(root);

		while (!stackTree.empty())
		{
			TreeNode* cur = stackTree.top();

			if (NULL == cur->left && NULL == cur->right)
			{
				int digitCount = 0;
				// 找到叶子节点, 从 叶子节点往根节点遍历，每走一位，数字位数+1
				for (auto iter = pathNum.rbegin(); iter != pathNum.rend();iter++)
				{
					sum += *iter * pow(10, digitCount); // pow(x,y)  计算x的y次方
					digitCount++;
				}
				stackTree.pop();
				pathNum.pop_back();
				continue;
			}
			
			if (NULL != cur->left)
			{
				if(set.end() == set.find(cur->left))
				{ 
					stackTree.push(cur->left);
					pathNum.push_back(cur->left->val);
					set.insert(cur->left);
					continue;
				}
			}
			
			if (NULL != cur->right)
			{
				if (set.end() == set.find(cur->right))
				{
					stackTree.push(cur->right);
					pathNum.push_back(cur->right->val);
					set.insert(cur->right);
					continue;
				}
			}

			// 如果该结点不是叶子结点，也访问过了，就把它从栈中弹出
			// 也就是去除回溯的结点
			stackTree.pop();
			pathNum.pop_back();
		}
		return sum;
	}
};
```