#include<iostream>
using namespace std;
#include<assert.h>
#include<vector>
#include<string.h>

//链表中倒数第K个结点
//注意代码的鲁棒性
//struct ListNode {
//
//    int val;
//    struct ListNode *next;
//	ListNode(int x) 
//		:val(x), next(NULL) 
//	{}
//};
//class Solution {
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//		//1、考虑链表为空或者求第k个结点
//		if (pListHead == NULL || k == 0)
//		{
//			return NULL;
//		}
//		ListNode* fast = pListHead;
//		ListNode* slow = pListHead;
//		//2、考虑链表的长度小于k
//		while (--k)
//		{
//			if (fast->next)
//			{
//				fast = fast->next;
//			}
//			else
//				return NULL;
//		}
//		while (fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next;
//		}
//		return slow;
//};
//int main()
//{
//	ListNode* pl1 = new ListNode(-1);
//	ListNode* node1 = new ListNode(1);
//	ListNode* node2 = new ListNode(2);
//	ListNode* node3 = new ListNode(3);
//	ListNode* node4 = new ListNode(4);
//	ListNode* node5 = new ListNode(5);
//	pl1->next = node1;
//	node1->next = node2;
//	node2->next = node3;
//	node3->next = node4;
//	node4->next = node5;
//	Solution s;
//	s.FindKthToTail(pl1, 3);
//	system("pause");
//	return 0;
//}
//机器人的运动范围
//class Solution {
//public:
//	int movingCount(int threshold, int rows, int cols)
//	{
//		//代码的鲁棒性
//		if (threshold < 0 || rows < 1 || cols < 1)
//			return 0;
//		
//		//定义一个标志矩阵，记录走过的路径
//		int* flag = new int[rows*cols];
//		
//		//初始化标志位
//		for (int i = 0; i < rows*cols; i++)
//		{
//			flag[i] = 0;
//		}
//		//寻找路径，并标记
//		filepath(threshold, rows, cols, 0, 0, flag);
//
//		//遍历矩阵，找到标记的个数
//		int count = 0;
//		for (int i = 0; i < rows*cols; i++)
//		{
//			if (flag[i] == 1)//将标记为1的统计起来
//			{
//				count++;
//			}
//		}
//		delete[] flag;
//		return count;
//	}
//
//private:
//	bool AddBitNum(int threshold, int currow, int curcol)
//	{
//		int sumcount = 0;
//		while (currow)
//		{
//			sumcount += currow % 10;
//		    currow /= 10;
//		}
//		while (curcol)
//		{
//			sumcount += curcol % 10;
//			curcol /= 10;
//		}
//		if (threshold < sumcount)
//		{
//			return false;
//		}
//		else
//		{
//			return true;
//		}
//	}
//	void filepath(int threshold, int rows, int cols, int currow, int curcol, int*flag)
//	{
//		//边界控制：超出边界，该方向无法继续
//		if (currow < 0 || curcol<0 || currow>rows - 1 || curcol>cols - 1)
//		{
//			return;
//		}
//		//判断每位的相加是否满足条件
//		if (AddBitNum(threshold, currow, curcol)==false)
//		{
//			return;
//		}
//
//		//标志位控制：已经走过的路不能再走
//		if (flag[currow*cols + curcol] == 1)
//			return;
//		//当前位置通过检测，更新标志位，继续搜索
//		flag[currow*cols + curcol] = 1;
//
//		filepath(threshold, rows, cols, currow - 1, curcol, flag);//向上
//		filepath(threshold, rows, cols, currow + 1, curcol, flag);//向下
//		filepath(threshold, rows, cols, currow , curcol-1, flag);//向左
//		filepath(threshold, rows, cols, currow , curcol+1, flag);//向右
//	}
//};
//
//int main()
//{
//	Solution s;
//	cout << s.movingCount(5, 4, 4);
//	system("pause");
//	return 0;
//}
bool getBitsum(int threshold, int currow, int curcol)
{
	int sum = 0;
	while (currow)
	{
		sum += currow % 10;
		currow /= 10;
	}
	while (curcol)
	{
		sum += curcol % 10;
		curcol /= 10;
	}
	return sum > threshold ? 0 : 1;
}
bool Check(int threshold, int rows, int cols, int currow, int curcol, bool*flag)
{
	if (currow < 0 || curcol<0 || currow > rows - 1 || curcol > cols - 1)//注意这块是rows-1
	{
		return false;
	}
	//判断每位的相加是否满足条件
	if (getBitsum(threshold, currow, curcol) == false)
	{
		return false;
	}
	//标志位控制：已经走过的路不能再走
	if (flag[currow*cols + curcol] == true)
		return false;
	return true;
}
int movingCountCore(int threshold, int rows, int cols, int currow, int curcol, bool* flag)
{
	int count = 0;
	if (Check(threshold, rows, cols, currow, curcol, flag) == true)
	{
		//将访问过的标记为1
		flag[currow*cols + curcol] = true;
		//继续访问
		count = 1 + movingCountCore(threshold, rows, cols, currow + 1, curcol, flag)\
			+movingCountCore(threshold, rows, cols, currow - 1, curcol, flag)\
			+movingCountCore(threshold, rows, cols, currow, curcol + 1, flag)\
			+movingCountCore(threshold, rows, cols, currow, curcol - 1, flag);
	}
	return count;
}
int movingCount(int threshold, int rows, int cols)
{
	//设置一个标志位标记已经走过的位置
	bool* flag = new bool[rows*cols];
	int count = movingCountCore(threshold, rows, cols, 0, 0, flag);
	delete[] flag;
	return count;
}

int main()
{
	cout<<movingCount(5, 4, 4);
	system("pause");
	return 0;
}
