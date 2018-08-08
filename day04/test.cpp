#include<iostream>
using namespace std;
#if 0
// 有序链表转换二叉搜索树
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) 
	{
		if (NULL == head)
		{
			return NULL;
		}
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* preslow = NULL;
		while (fast&&fast->next)
		{
			preslow = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (preslow)
		{
			preslow->next=NULL;
		}
		TreeNode* root = new TreeNode(slow->val);
		if (slow != head)
		{
			root->left = sortedListToBST(head);
		}
		else
		{
			root->left = NULL;
		}
		root->right = sortedListToBST(slow->next);
		return root;
	}
};
int main()
{
	ListNode* ls1 = new ListNode(-10);
	ListNode* node1 = new ListNode(-3);
	ListNode* node2 = new ListNode(0);
	ListNode* node3 = new ListNode(5);
	ListNode* node4 = new ListNode(9);
	ls1->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	Solution s;
	TreeNode* t1;
	t1=s.sortedListToBST(ls1);
	system("pause");
	return 0;
}
#endif

// Definition for singly-linked list.
//分割链表
//给出：1->4->3->2->5->2   3
//得到：1->2->2->4->3->5
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *partition(ListNode *head, int x)
	{
		if (NULL == head)
		{
			return NULL;
		}
		ListNode* NewNode1 = new ListNode(-1);
		ListNode* NewNode2 = new ListNode(-1);
		NewNode1->next = head;
		ListNode* cur = NewNode1;
		ListNode* pcur = NewNode2;
		while (cur->next)
		{
			if (cur->next->val < x)
			{
				pcur->next = cur->next;
				pcur = pcur->next;
				cur->next = cur->next->next;
				pcur->next = NULL;
			}
			else
			{
				cur = cur->next;
			}
		}
		pcur->next = NewNode1->next;
		return NewNode2->next;
	}
};
int main()
{
	ListNode* ls1 = new ListNode(1);
	ListNode* node1 = new ListNode(4);
	ListNode* node2 = new ListNode(3);
	ListNode* node3 = new ListNode(2);
	ListNode* node4 = new ListNode(5);
	ListNode* node5 = new ListNode(2);
	ls1->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
	ListNode* result;
	Solution s;
	result=s.partition(ls1, 3);
	//cout << result->val << endl;
	system("pause");
	return 0;
}
