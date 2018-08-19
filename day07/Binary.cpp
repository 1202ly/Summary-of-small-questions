#include<iostream>
using namespace std;
#include<vector>
// Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归实现
#if 0
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if (NULL == root)
		{
			return result;
		}
		_preorderTraversal(result, root);
		return result;
	}
private:
	void _preorderTraversal(vector<int>& result, TreeNode* root)
	{
		if (NULL == root)
		{
			return;
		}
		result.push_back(root->val);
		if (root->left)
		{
			_preorderTraversal(result, root->left);
		}
		if (root->right)
		{
			_preorderTraversal(result, root->right);
		}
	}
};
#endif 

#if 0
#include<stack>
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) 
	{
		vector<int> tmp;
		if (NULL == root)
		{
			return tmp;
		}
		stack<TreeNode*> s;
		vector<int> result;
		TreeNode* p = root;
		while (!s.empty || p!=NULL)
		{
			while (p != NULL)
			{
				result.push_back(p->val);
				s.push(p);
				p = p->left;
			}
			if (!s.empty())
			{
				p = s.top();
				s.pop();
				p = p->right;
			}
		}
		return result;
	}
};

//非递归实现
int main()
{
	TreeNode* t1 = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	TreeNode* node4 = new TreeNode(5);
	TreeNode* node5 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	t1->left = NULL;
	t1->right = node1;
	node1->right = node2;
	node1->left = NULL;
	Solution s;
	vector<int> r;
	r = s.preorderTraversal(t1);
	system("pause");
	return 0;
}
#endif

//后序遍历---->递归
# if 0
class Solution {
public:
	vector<int> prepostTraversal(TreeNode *root)
	{
		vector<int> result;
		if (NULL == root)
		{
			return result;
		}
		_prepostTraversal(result, root);
		return result;
	}
private:
	void _prepostTraversal(vector<int>& result, TreeNode* root)
	{
		if (NULL == root)
		{
			return;
		}
		if (NULL == root->left)
		{
			_prepostTraversal(result, root->left);
		}
		if (NULL == root->right)
		{
			_prepostTraversal(result, root->right);
		}
		result.push_back(root->val);
	}
};
#endif
