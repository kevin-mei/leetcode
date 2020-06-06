#### 题目
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42

题目理解： 从树的任意一个结点到另一个任意结点，求两个结点的路径上结点和的最大值, **这个路径最少包含一个路径（可以单结点），并不要求一定要经过根节点**。


```
	4
   / \
  11 13
 / \
7   2
```


根据以往的经验，树的递归解法一般都是递归到叶节点，然后开始边处理边回溯到根节点。那么我们就假设此时已经递归到结点7了，那么其没有左右子节点，所以如果以结点7为根结点的子树最大路径和就是7。然后回溯到结点11，如果以结点11为根结点的子树，我们知道最大路径和为 7+11+2=20。但是当回溯到结点4的时候，对于结点11来说，就不能同时取两条路径了，只能取左路径，或者是右路径，所以当根结点是4的时候，那么结点11只能取其左子结点7，因为7大于2。所以，对于每个结点来说，我们要知道经过其左子结点的 path 之和大还是经过右子节点的 path 之和大。那么我们的递归函数返回值就可以定义为以当前结点为根结点，到叶节点的最大路径之和，然后全局路径最大值放在参数中，用结果 res 来表示。

在递归函数中
1.如果当前结点不存在，那么直接返回0
2.否则就分别对其左右子节点调用递归函数，由于路径和有可能为负数，而我们当然不希望加上负的路径和，所以我们和0相比，取较大的那个，就是要么不加，加就要加正数。
3.然后我们来更新**全局最大值结果 res**，就是以 **左子结点为终点的最大path 之和加上以右子结点为终点的最大path 之和，还要加上当前结点值，这样就组成了一个条完整的路径。**
4.而**我们返回值是取 left 和 right 中 的较大值加上当前结点值**，因为我们返回值的定义是以当前结点为终点的 path 之和，所以只能取 left 和 right 中较大的那个值，而不是两个都要，参见代码如下



```
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN; //比0还小的数
        helper(root, res);
        return res;
    }
    int helper(TreeNode* node, int& res) {
        if (!node) return 0;
        int left = max(helper(node->left, res), 0);
        int right = max(helper(node->right, res), 0);
        res = max(res, left + right + node->val);
        return max(left, right) + node->val;
    }
};
```
```
	-4
   / \
  -11 -13
 / \
-7   -2
```

[-4,-11,-13,-7,-2]
输入的树全是负数的话
res = max(res, left + right + node->val);
left和right虽然会是0，但是node->val仍然是负数啊，res初始为INT_MIN，所以还是会返回最大的负数。

第一个递归 要算到的是 -7结点 left,right=0, res=-7 return=-7
第二个递归要算到的是 -2结点 ，left,right=0, res=-2 (再算第二个res时， res= max(-7, 0+0+-2) = -2, return=-2
第三个递归要算到的是 -11结点，left=-7,right=-2, res=max(-2, -7+-2+-11) = -2; return (-2+-11) = -13;
此后res一直为-2， 故最终最大的路径和为-2







