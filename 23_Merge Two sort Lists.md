#### 题目
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

题目解释：
合并两个有序的链表为一个有序的链表，如果有共同元素，则都保留

解题思路：

1. 如果两个链表为空，则直接空返回，或只有其中一个为空，返回另一个链表头结点
2. 开始同时遍历两个链表，依次比较元素，直到两个链表 有一个结束，跳出遍历；之后将没结束的链表上的剩余结点挂载到合并后的链表后

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ```
 
 ```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2)
        	return NULL;
        else if(NULL == l1)
        	return l2;
        else  if(NULL == l2)
        	return l1;
        
        ListNode *MergeList = new ListNode(0);
        ListNode *NodeFlag = MergeList;
        
        while(NULL !=l1 && NULL != l2)
        {
        	ListNode *Nodetemp = new ListNode(0);
        	if(l1->val < l2->val)
            {
        		Nodetemp->val = l1->val;
                l1 = l1->next;
            }
            else if(l1->val > l2->val)
            {
            	Nodetemp->val = l2->val;
                l2=l2->next;
            }
            else
            {
            	Nodetemp->val = l1->val;
                l1=l1->next;
            }
            MergeList->next = Nodetemp;
            MergeList = MergeList->next;
        }
        
        if(NULL != l1)
        	MergeList->next = l1;
        else if(NULL != l2)
        	MergeList->next = l2;
        else
        	MergeList->next=NULL;
        ListNode *NodeRes = NodeFlag->next;
        
        return NodeRes;
    }
};
```

说白了，这道题似乎并没有什么算法， 就只是遍历，比较，存入元素；
如果可以使用sort,我觉得还阔以再偷懒一点，遍历到l1的末尾，直接next= l2,然后利用STL sort算法排序  但是sort算法并不支持直接比较两个链表结点的大小，这属于自定义的结构体
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(NULL == l1 && NULL == l2)
        	return NULL;
        else if(NULL == l1)
        	return l2;
        else  if(NULL == l2)
        	return l1;
        ListNode *MergeList = l1;
        while(NULL != l1->next)
        {
        	l1 = l1->next;
        }
        l1->next = l2;
        while(NULL != l2->next)
        {
        	l2=l2->next;
        }
        sort(MergeList, l2);
        return MergeList;
    }
};
 ```