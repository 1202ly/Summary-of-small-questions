#include<iostream>
using namespace std;
#include<vector>

#include<queue>
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {}
};
#if 0
//二叉树的镜像
class Solution {
public:
	void Mirror(TreeNode *pRoot) 
	{
		if (NULL == pRoot || (NULL == pRoot->left&&NULL == pRoot->right))
		{
			return;
		}
		queue<TreeNode*> q;
		q.push(pRoot);
		while (!q.empty())
		{
			TreeNode* top = q.front();
			q.pop();
			if (top->left)
			{
				q.push(top->left);
			}
			if (top->right)
			{
				q.push(top->right);
			}
			if (top->left || top->right)
			{
				swap(top->left, top->right);
			}
		}
	}
};
int main()
{
	TreeNode* t = new TreeNode(8);
	TreeNode* t1 = new TreeNode(6);
	TreeNode* t2 = new TreeNode(10);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(7);
	TreeNode* t5 = new TreeNode(9);
	TreeNode* t6 = new TreeNode(11);
	t->left = t1;
	t->right = t2;
	t1->left = t3;
	t1->right = t4;
	t2->left = t5;
	t2->right = t6;
	Solution s;
	s.Mirror(t);
	system("pause");
	return 0;
}
#endif 
//2、求二叉树的高度
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (NULL == pRoot)
		{
			return 0;
		}
		if (NULL == pRoot->left&&NULL == pRoot->right)
		{
			return 1;
		}
		int Lheight = TreeDepth(pRoot->left);
		int Rheight = TreeDepth(pRoot->right);
		return Lheight> Rheight ? Lheight + 1 : Rheight + 1;
	}
};
int main()
{
	TreeNode* t = new TreeNode(8);
	TreeNode* t1 = new TreeNode(6);
	TreeNode* t2 = new TreeNode(10);
	TreeNode* t3 = new TreeNode(5);
	TreeNode* t4 = new TreeNode(7);
	TreeNode* t5 = new TreeNode(9);
	TreeNode* t6 = new TreeNode(11);
	t->left = t1;
	t->right = t2;
	//t1->left = t3;
	t1->right = t4;
	//t2->left = t5;
	//t2->right = t6;
	Solution s;
	int result = s.TreeDepth(t);
	cout << result << endl;
	system("pause");
	return 0;
}
