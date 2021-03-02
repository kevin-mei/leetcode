/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (54.38%)
 * Likes:    1171
 * Dislikes: 0
 * Total Accepted:    218K
 * Total Submissions: 400.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
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
//#include "pch.h"

//tag: linked-list | divide-and-conquer 分治 | heap 堆
class Solution {
public:
    ListNode* mergeKLists_1(vector<ListNode*>& lists) {
        // 之前做过合并两个有序链表，两个的话，谁的值小就合并谁，现在是k个链表，最终都归于最简单的两个链表合并
        // 分而治之 如果是两条链表，两条链表合并呢类似归并排序的思想，
        if (0 == lists.size())
            return nullptr;
        vector<ListNode *> merged_lists;
        while (lists.size() > 1)
        {
            int count = lists.size();
            // 能不能再原链表上保存合并后的链表
            for (int i = 0; i < count - 1; i += 2)
            {
                ListNode *merged_list = mergeTwoLists(lists[i], lists[i + 1]);
                merged_lists.push_back(merged_list);
            }
            if (1 == count % 2)
            {
                //lists为奇数，最后一条链表没有合并,上个循环为处理到，需要添加进merged_lists
                merged_lists.push_back(lists[count - 1]);
            }
            lists.clear();
            lists.insert(lists.end(), merged_lists.begin(), merged_lists.end());
            merged_lists.clear();
        }

        return lists[0];
    }

    // 合并两个有序链表 
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *mergeList = new ListNode(); //初始结点不存值
        ListNode *tailNode = mergeList;
        ListNode *taill1 = l1, *taill2 = l2;
        // 每次比较l1和l2的第一个元素，小的放在新链表里
        while (nullptr != taill1 || nullptr != taill2)
        {
            int val1 = nullptr != taill1 ? taill1->val : INT_MAX;
            int val2 = nullptr != taill2 ? taill2->val : INT_MAX;
            if (val1 < val2)
            {
                ListNode *Node = new ListNode(val1);
                tailNode->next = Node;
                tailNode = Node;
                taill1 = taill1->next;
            }
            else
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

    
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // 采用小顶堆来实现 也就是优先级队列
        // 默认是less比较，a<b true, 实现的是大顶堆，我们这里要用到小顶堆,a>b返回 true;
        // Using lambda to compare elements.
        auto compare=[](ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> p_queue(compare);

        // 将vecot链表放入堆中
        for(auto list : lists)
        {
            if(list) p_queue.push(list);
        }
        ListNode* mergehead = new ListNode(-1); // 合并链表头结点的哨兵
        ListNode* tail = mergehead;
        while(!p_queue.empty()) //优先级队列不为空时就进入循环
        {
            ListNode* minnode = p_queue.top();
            p_queue.pop();
            tail->next = minnode;
            tail = tail->next;
            if(minnode->next)
                p_queue.push(minnode->next);
        }
        return mergehead->next;
    }

     ListNode* mergeKLists_3(vector<ListNode*>& lists) {
        auto cmp = [](ListNode*& a, ListNode*& b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp) > q(cmp);
        for (auto node : lists) {
            if (node) q.push(node);
        }
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if (cur->next) q.push(cur->next);
        }
        return dummy->next;
    }
};
// @lc code=end

