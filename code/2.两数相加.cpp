/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
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
#include "pch.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;

        int addition = 0; // 进位
        while(nullptr != l1 || nullptr != l2 ) // 这里两个链表都做判断
        {
            int x1 = nullptr == l1 ? 0 : l1->val; // 节点为空时，数值取0
            int x2 = nullptr == l2 ? 0 : l2->val;
            int sum = (x1 + x2 + addition) % 10; //这里三者都需要加
            addition = (x1 + x2 + addition) / 10;
            ListNode* node = new ListNode(sum);
            if(nullptr == tail)
            {
                head = node;
                tail = node;
            }else
            {
                tail->next = node;
                tail = node;
            }
            // 别忘了更新l1,l2,注意判断为空的条件
            l1 = nullptr == l1 ? nullptr : l1->next;
            l2 = nullptr == l2 ? nullptr : l2->next;   
        }
        if(addition > 0)
        {
            ListNode* node = new ListNode(addition);
            tail->next = node;
            tail = node;
        }
        return head;
    }
};
// @lc code=end

