#if 0
 //自顶向下
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		if (NULL == root)
		{
			return result;
		}
		queue<TreeNode*> qu;
		qu.push(root);
		while (!qu.empty())
		{
			vector<int> tmp;
			int sz = qu.size();
			while (sz--)
			{
				TreeNode* topnode = qu.front();
				qu.pop();
				tmp.push_back(topnode->val);
				if (topnode->left)
				{
					qu.push(topnode->left);
				}
				if (topnode->right)
				{
					qu.push(topnode->right);
				}
			}
			result.push_back(tmp);
		}
		return result;
	}
};
#endif
//自底向上
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;//用来保存结果;默认初始化，result不含任何元素
		if (NULL == root)
		{
			return result;
		}
		//用队列保存数据---》先进先出
		queue<TreeNode*> qu;
		qu.push(root);//先将根压进去；
		while (!qu.empty())
		{
			vector<int> tmp;//保存每层的结点值
			int sz = qu.size();
			while (sz--)
			{
				//先保存队头结点
				TreeNode* topnode = qu.front();
				qu.pop();
				tmp.push_back(topnode->val);
				if (topnode->left)
				{
					qu.push(topnode->left);
				}
				if (topnode->right)
				{
					qu.push(topnode->right);
				}
			}
			result.push_back(tmp);
		}
		//这时候是按从上往下的顺序访问的，逆转之后就是自底向上
		reverse(result.begin(), result.end());
		return result;
	}
};
