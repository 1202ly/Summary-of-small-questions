#include<iostream>
using namespace std;
//1、leetcode61题-->旋转链表
//给出：1->2->3->4->5->NULL  k=2
//返回：4->5->1->2->3->NULL
// Definition for singly-linked list.
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode *rotateRight(ListNode *head, int k) {
//		if (NULL == head)
//		{
//			return NULL;
//		}
//		if (head->next == NULL)
//		{
//			return head;
//		}
//		ListNode* ret = head;
//		int len = 0;
//		while (ret != NULL)
//		{
//			len++;
//			ret = ret->next;
//		}
//		ListNode* cur = head;//遍历链表
//		ListNode* pre = NULL;//指向cur的前一个
//		ListNode* result = head;//链接结果链表
//		int kk = k % len;
//		if (kk == 0)
//		{
//			return head;
//		}
//		while (kk--)
//		{
//			while (cur &&cur->next)
//			{
//				pre = cur;
//				cur = cur->next;
//			}
//			pre->next = NULL;
//			cur->next = result;
//			result = cur;
//		}
//		return result;
//	}
//};
//int main()
//{
//	ListNode* l1 = new ListNode(1);
//	ListNode* node1 = new ListNode(2);
//	ListNode* node2 = new ListNode(3);
//	ListNode* node3 = new ListNode(4);
//	ListNode* node4 = new ListNode(5);
//	ListNode* node5 = new ListNode(6);
//	l1->next = node1;
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	ListNode* pl = NULL;
//	Solution s;
//	pl = s.rotateRight(l1, 4);
//	cout << pl->val << endl;
//	system("pause");
//	return 0;
//}

//2、leetcode19题-》remove-nth-node-from-end-of-list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) 
	{
		if (NULL == head)
		{
			return NULL;
		}
		if (NULL == head->next&&n == 1)
		{
			return NULL;
		}
		ListNode*slow = head;
		ListNode*fast = head;
		ListNode* pre = NULL;
		while (--n&&fast->next)//先让fast走n步
		{
			fast = fast->next;
		}
		while (fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next;
		}
		if (pre)
		{
			pre->next = slow->next;
		}
		else//如果slow还停留在头节点
		{
			head = head->next;
		}
		return head;
	}
};
int main()
{
	ListNode* l1 = new ListNode(1);
	ListNode* node1 = new ListNode(2);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(4);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(6);
	l1->next = node1;
	//node1->next = node2;
	/*node2->next = node3;
	node3->next = node4;
	node4->next = node5;*/
	ListNode* pl = NULL;
	Solution s;
	pl = s.removeNthFromEnd(l1, 2);
	system("pause");
	return 0;
}
