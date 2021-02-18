/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
//#include "pch.h"

class Solution {
public:
    Node* connect(Node* root) {
        // 完美二叉树，是一个满二叉树，简单理解，就是正三角形，要填充每个next指针，让这个指针指向下一个右侧节点
        // 找不到的话，设置为NULL,这一步不同特殊设置，next初始化本身就为null
        if(nullptr == root)
        {
            return root;
        }
        connectTwoNode(root->left, root->right);
        return root;
    }

    // 连接两个节点node1，node2，需要1,2,3,4步骤进行链接
    // 默认node2在node1的右侧，外部调用的时候，左孩子和右孩子
    void connectTwoNode(Node* node1, Node* node2)
    {
        if(nullptr == node1 || nullptr == node2) // 因为是满二叉树，所以左孩子和右孩子会同时为空，直接返回就好
        {
            return;
        }

        node1->next = node2; // 1. node1 和node2连接，连接2，3节点
        //下面是递归调用，不用自己写连接，一切交给递归，相信递归的函数定义
        connectTwoNode(node1->left,node1->right); // 2. 连接节点1的左右孩子，连接4，5节点；
        connectTwoNode(node2->left,node2->right); // 3. 连接节点2的左右孩子，连接6，7节点
        connectTwoNode(node1->right,node2->left); // 4. 跨父节点的连接，连接5，6节点     
    }
};
// @lc code=end

