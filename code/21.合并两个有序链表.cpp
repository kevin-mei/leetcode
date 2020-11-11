/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
//#include "pch.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* mergeList = new ListNode(); //初始结点不存值
        ListNode* tailNode = mergeList;
        ListNode *taill1 = l1, *taill2 = l2;
        // 每次比较l1和l2的第一个元素，小的放在新链表里
        while(nullptr != taill1 || nullptr != taill2)
        {
            int val1 = nullptr != taill1? taill1->val:INT_MAX;
            int val2 = nullptr != taill2? taill2->val:INT_MAX;
            if(val1 < val2)
            {
                ListNode *Node = new ListNode(val1);
                tailNode->next = Node;
                tailNode = Node;
                taill1 = taill1->next;
            }else
            {
                ListNode *Node = new ListNode(val2);
                tailNode->next = Node;
                tailNode = Node;
                taill2 = taill2->next;
            }
        }
        // 初始结点不存值
        // 初始结点的下一结点是合并后的链表的头结点
        return mergeList->next;
    }
};
// @lc code=end

