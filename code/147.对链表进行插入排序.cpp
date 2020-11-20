/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(nullptr == head)
            return nullptr;
        ListNode* sorted_head = new ListNode(head->val); // 先创建一个已排序链表的头节点
        // 外层循环遍历head， 当前节点为cur_node
        // 内层循环 sorted_cur_node是在已排序的链表中遍历，sorted_pre_node 是上一个结点，寻找cur_node可以插入的位置
        // 1. cur_node->val < sorted_cur_node->val，  cur_node 在sorted_pre_node之后，sorted_cur_node之前插入，
        // 2. 遍历到最后，跳出循环， null==sorted_cur_node,说明遍历到最后结点，没找到cur_node插入的位置，那cur_node就是sortedlist的最后一个节点
        ListNode* cur_node= head->next; // 头结点已经插入了,当前结点应为头结点的下一位
        while (cur_node)
        {
            ListNode *sorted_cur_node = sorted_head;
            ListNode *sorted_pre_node = nullptr;
            while (sorted_cur_node)
            {
                if (cur_node->val < sorted_cur_node->val)
                {
                    ListNode *new_node = new ListNode(cur_node->val);
                    if (nullptr == sorted_pre_node) //这里注意判断sorted_pre_node为空，也就是sorted_cur_node是头结点的情况
                    {
                        new_node->next = sorted_head;
                        sorted_head = new_node;
                    }
                    else
                    {
                        sorted_pre_node->next = new_node;
                        new_node->next = sorted_cur_node;
                    }
                    break; // 插入后不要忘了跳出循环
                }
                sorted_pre_node = sorted_cur_node;
                sorted_cur_node = sorted_cur_node->next;
            }
            if (nullptr == sorted_cur_node) // 说明遍历到最后结点，没找到cur_node插入的位置，那cur_node就是sortedlist的最后一个节点
            {
                ListNode *new_node = new ListNode(cur_node->val);
                sorted_pre_node->next = new_node;
            }
            cur_node = cur_node->next;
        }
        return sorted_head;
    }

    ListNode* insertionSortList_1(ListNode* head) {
        if(nullptr == head)
            return nullptr;
        ListNode* sorted_head = new ListNode(head->val); // 先创建一个已排序链表的头结点
        ListNode* cur_node = head->next; // 头结点已经插入了,当前结点应为头结点的下一位
        // 外层循环遍历head， 当前节点为cur_node
        // 内层循环 sorted_cur_node是在已排序的链表中遍历，寻找cur_node可以插入的位置
        // 1. 遍历的最后也没找到位置，sorted_cur_node == null, 插入尾部，新建一个结点，sorted_cur_node->next=new_node
        // 2. 遍历中找到位置， sorted_cur_node->val < cur_node->val <= sorted_cur_node->next->val 
        // temp = sorted_cur_node->next ; sorted_cur_node->next = new_node; new_node->next = temp;
        while(cur_node)
        {
            ListNode* sorted_cur_node = sorted_head;
            while(sorted_cur_node)
            {
                if (sorted_cur_node->val < cur_node->val && cur_node->val <= sorted_cur_node->next->val)
                {
                    ListNode* new_node = new ListNode(cur_node->val); 
                    ListNode *temp = sorted_cur_node->next;
                    sorted_cur_node->next = new_node;
                    new_node->next = temp;
                    break;
                }
                if(nullptr == sorted_cur_node->next) // 已经遍历到的尾结点
                {
                    ListNode* new_node = new ListNode(cur_node->val); 
                    if(cur_node->val < sorted_cur_node->val)
                    {
                        new_node->next = sorted_cur_node;
                        sorted_cur_node->next=new_node;   
                    }else
                    {
                        sorted_cur_node->next=new_node;
                    }
                    
                    
                    break;
                }
                sorted_cur_node = sorted_cur_node->next;
            }
            cur_node = cur_node->next;
        }
        return sorted_head;
    }
};

// @lc code=end

