#### 题目
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.


Example 1:

![](./png/138_example1.png)

Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.

Note:

You must return the copy of the given head as a reference to the cloned list.

解法一：

深拷贝带随机结点的链表，
1. 先遍历一遍，拷贝普通结点，将新建的结点插入到每个结点后面
2. 再遍历一遍拷贝随机指针
3. 最后将新建的结点和原链表断开合并成新链表，同时恢复原有链表

```

class Solution {
public:
	Node* copyRandomList(Node* head) {
		Node *headRes = nullptr;
		if (nullptr == head)
			return headRes;
		Node *curNode = head;
		while (nullptr != curNode)
		{
			Node *Temp = new Node(curNode->val, curNode->next, nullptr);
			curNode->next = Temp;
			curNode = Temp->next;
		}

		curNode = head;
		while (nullptr != curNode)
		{
			Node *Temp = curNode->next;
			if (nullptr != Temp)
			{
				if (nullptr != curNode->random)
					Temp->random = curNode->random->next;
				else
					Temp->random = nullptr;
				curNode = Temp->next;
			}
			else
				curNode = curNode->next;
		}

		curNode = head;
		headRes = curNode->next;
		while (nullptr != curNode)
		{
			Node *Temp = curNode->next;
			if (nullptr != Temp)
			{
				Node *NextCur = Temp->next;
				curNode->next = NextCur;
				if (nullptr != NextCur)
					Temp->next = NextCur->next;
				else
					Temp->next = nullptr;
				curNode = NextCur;
			}
			else
				curNode = curNode->next;

		}
		return headRes;
	}
};
```





















