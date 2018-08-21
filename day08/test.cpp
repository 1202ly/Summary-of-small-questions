#include<iostream>
using namespace std;
#include<vector>
//验证二叉搜索树

// Definition for a binary tree node.
#if 0
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		if (NULL == root)
		{
			return true;
		}
		if (NULL == root->left && NULL == root->right)
		{
			return true;
		}
		vector<int> result;
		_inOrder(root, result);
		for (int i = 0; i < result.size() - 1; i++)
		{
			if (result[i] >= result[i + 1])
			{
				return false;
				break;
			}
		}
		return true;
	}
	void _inOrder(TreeNode* root, vector<int>& result)
	{
		if (NULL == root)
		{
			return;
		}
		_inOrder(root->left, result);
		result.push_back(root->val);
		_inOrder(root->right, result);
	}
};
#endif


//2、寻找数组中的两个数之和

vector<int> sum(vector<int>& nums, int target)
{
	int sz = nums.size();
	vector<int>result;
	for (int i = 0; i < sz; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
				break;
			}
		}
	}
	return result;
}
int main()
{
	vector<int> s = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> result;
	result = sum(s, 3);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
