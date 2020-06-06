#### 题目

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.

<img src="./png/circularlinkedlist_test1.png" alt="" align=center>

Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
<img src="./png/circularlinkedlist_test2.png" alt="" align=center>

Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.

<img src="./png/circularlinkedlist_test3.png" alt="" align=center>

Follow-up:
Can you solve it without using extra space?

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
    }
};
```


题目解释：给定一个链表，如果有环，返回环开始的结点，如果没有，则返回null

要求: 不适用额外的空间


思路：

1. 使用快慢指针（快指针2倍速）确认该链表是否有环, 如果有环，则两指针会相遇，设相遇于Z点;同141_Linked List Cycle
2. 假设链表的起始位置为X， 环的起始位置为Y， 有环时快慢指针相遇于Z点；Lxy = a; Lyz = b, Lzy = c;
3. 相遇于Z点， 慢指针 走了 a+b的长度， 快指针走了2*(a+b)长度，假设相遇时，快指针已经走了N圈的环长度，b+c是环的长度；那么快指针 也相当于走了a+b+n*(b+c)  (解释下：a+b 确保指针走在Z处，Z处是环内的位置，最终相遇在Z处，也就是快指针多走了N圈的环长度)

	即： 2*(a+b) = a+b+N*(b+c)  => a+b = N*(b+c) => a = (N-1)*b+N*c
=> a = (N-1)(b+c) + c   (Z点 开始 走个c长度到Y点，然后走整数倍的圈数，还是Y点，可以再用快慢指针求解Y点位置)

4. 有了这个关系，那么 一个指针在X点，一个指针在Z点，以相同的速度走，当它们相遇的时候，相遇的位置恰好就是Y点，也就是环开始的位置；

	<img src="./png/cycle.jpg" alt="" align=center>

算法是这样的
1.快慢指针，找到第一次相遇的点
2.接着慢指针回归起始位置，快指针调整和慢指针一个速度，再次相遇的位置就是环开始的位置

参考牛客网看到的wangxiaobao对此题的回答，链接如下：
[https://www.nowcoder.com/questionTerminal/6e630519bf86480296d0f1c868d425ad](https://www.nowcoder.com/questionTerminal/6e630519bf86480296d0f1c868d425ad)


代码如下：

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head)
			return false;
		ListNode *fast = head;

		ListNode *slow = head;

		while (nullptr != fast->next && nullptr != fast->next->next && nullptr != slow->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast->val == slow->val)
				return true;
		}
		return false;
	}
};
```
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (nullptr == head)
			return nullptr;
		ListNode *fast = head;

		ListNode *slow = head;

		while (nullptr != fast->next && nullptr != fast->next->next && nullptr != slow->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				slow = head;
				// 已经确认有环，就可以不用判断next是否为空了
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return fast; //或者return slow
			}
		}
		return nullptr;
    }
};
```