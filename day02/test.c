#include<iostream>
using namespace std;
#include<string.h>
#include<assert.h>
#include<vector>
//给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
//string tranform(int m, int n)
//{
//	assert(n);
//	if (m == 0)
//	{
//		return 0;
//	}
//	if (m < 0)
//	{
//		m = (-m);//转化为正数
//	}
//	char tables[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
//	string str;
//	while (m)
//	{
//		int tmp = m%n;
//		char t = tables[tmp];
//		str = t + str;
//		m = m / n;
//	}
//	return str;
//}
//int main()
//{
//	int m, n;
//	string result="";
//	while (cin >> m >> n)
//	{
//		result = tranform(m, n);
//		if (m < 0)
//		{
//			cout << "-";
//		}
//		//cout << result;//在线oj上ok，vs上不行，可以选择手动调试结果
//	}
//	system("pause");
//	return 0;
//}

//2.输入一个正整数n,求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2
//方法一、通过率百分之六十，对于特别大数字无法存储
//long long result(int n)//求n！
//{
//	assert(n);
//	if (n == 1)
//	{
//		return 1;
//	}
//	else
//		return n*result(n - 1);
//}
//long  zeronum(int m)
//{
//	assert(m);
//	long long jc = result(m);
//	int count = 0;
//	while (jc)
//	{
//		if (jc % 10 == 0)
//		{
//			count++;
//			jc /= 10;
//		}
//		else
//			break;
//	}
//	return count;
//}
//方法二：拆分因子法：
// 首先考虑，如果N!=K*10^M，且K不能被10整除，
//那么N!末尾有M个0，再考虑对N!进行质因数分解N！=（2^x *3^y *5^z..........）
//由于10=2*5，所以M与x和z有关，每一对2和5相乘都会得到一个10，
//于是M=min(x,z).不难看出x大于等于z,因为能被2整除的数比5整除的数多多了，所以把问题简化成M=z;
//int zeronum(int num)
//{
//	assert(num);
//	int count = 0;
//	for (int i = 1; i <= num; i++)
//	{
//		int tmp = i;
//		while (tmp % 5 == 0)
//		{
//			count++;
//			tmp /= 5;
//		}
//	}
//	return count;
//}
//int main()
//{
//	int  m = 10;
//	//cin >> m;
//	int sum = zeronum(m);
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}
