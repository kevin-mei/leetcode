/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//#include "pch.h"

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(0 == k || nullptr == head)
        {
            return head;
        }
        // 首尾相连，然后从尾开始向头反向遍历，遍历到k处，返回k所在的节点，k的上一个节点定为尾节点
        // 但是链表的next是单向的，只能正向遍历
        // 从尾向头遍历k个节点，相当于从头向尾遍历length-k个节点（0<k<length） 
        // 后面如果k大于length，取 k= k%length; lenght为链表的长度
        ListNode* start = head;
        ListNode* end = head;
        int length = 1; 
        // 先遍历至end节点
        while(nullptr != end->next)
        {
            end = end->next;
            length++;
        }
        //首尾相连
        end->next = start;
        int m = length - k % length;
        while(m)
        {
            end = start; // end为start的上一个节点，这里就提前存下start
            start = start->next;
            m--;
        }
        // 尾节点的next需置为空
        end->next = nullptr;
        return start;
    }
};
// @lc code=end

