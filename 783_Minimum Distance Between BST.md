#### BST 
全称：binary Search Tree e

左子树的结点的值 ＜ 根节点的值 < 右子树的结点的值

#### 复习下数的遍历方式：中序遍历

若二叉树的根节点为空，则直接返回，否则 从根节点开始（不是访问），先中序遍历左子树，再访问根节点，最后中序遍历右子树（参考大话数据结构，我觉得这句定义可以直接写递归了，非常实用到位）

#### 题目
Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
Note:

The size of the BST will be between 2 and 100.
The BST is always valid, each node's value is an integer, and each node's value is different.

解释一下：
给定了一个二叉搜索树，需要返回树中任意两个结点的值得最小差值

思路：可以中序遍历，将二叉搜索树转化为有序的链表或者结点保存成有序数组; 要返回所有 结点的最小差值，这个差值肯定在有序数据相邻两个结点的差值中产生，遍历一边数组，即可得到最小差值；


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
```
```
class Solution {
public:
	vector<int> vectValue;
    int minDiffInBST(TreeNode* root) {
        InorderTraverse(root);
        int nDifference = 0xFFFF;
        for(auto iter1 = vectValue.begin(),
        iter2 = vectValue.begin()+1;
        iter2 != vectValue.end();
        iter1++, iter2++)
        {
        	int nTemp = *iter2 - *iter1;
        	if(nTemp < nDifference)
            {
            	nDifference = nTemp;
            }
        }
        return nDifference;
        
    }
    void InorderTraverse(TreeNode* T)
    {
    	if(NULL == T)
        	return;
        InorderTraverse(T->left);
        vectValue.pushback(T->value);
        InorderTraverse(T->right);
    }
    
};
```

