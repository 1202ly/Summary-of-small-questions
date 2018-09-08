#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int Check()
//{
//	union UN
//	{
//		char c;
//		int i;
//	}un;
//	un.i = 1;//0x00000001 如果是小端存储的话1应该表示为0x10000000
//	return un.c;
//}
//int Check()
//{
//	int i = 1;
//	i = *(char*)&i;
//	return i;
//}
//int Check()
//{
//	union UN
//	{
//		char a[4];
//		int i;
//	}un;
//	un.i = 1;
//	printf("%02hhx%02hhx%02hhx%02hhx\n", un.a[0], un.a[1], un.a[2], un.a[3]);
//  //02表示整数不够2位就补0  
//  //x是以16进制输出
//  //hhx表示只输出两位
//	return un.a[0];
//}
//int main()
//{
//	int ret=Check();
//	if (ret == 1)
//	{
//		printf("大端存储\n");
//	}
//	else
//		printf("小端存储\n");
//	Check();
//	system("pause");
//	return 0;
//}

//模拟实现strcpy函数
//#include<string.h>  
//#include<assert.h>  
//char* my_strcpy(char* dest, const char* src)
//{
//	char *ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src)
//	{
//		*(dest++) = *(src++);
//	}
//	return ret;
//}
//int main()
//{
//	char arr[50]= { 0 };
//	char srr1[] = "my love";
//	my_strcpy(arr, srr1);
//	printf("%s\n", arr);
//	getchar();
//	return 0;
//}
//模拟实现strcat
//char* my_strcat(char* arr1, char* arr2)
//{
//	char* ret = *arr1;
//	while (*arr1)
//	{
//		*arr1++;
//	}
//	while (*arr2)
//	{
//		*arr1++ = *arr2++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[50] = "hello ";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}

//模拟实现strncat函数
//char* my_strncat(char* dest, char* src,int n)
//{
//	char* ret = dest;
//	while (*dest)
//	{
//		*dest++;
//	}
//	while (n--)
//	{
//		*(dest++) = *(src++);
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[50] = "hello ";
//	char arr2[] = "world";
//	my_strncat(arr1, arr2, 3);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}
//模拟实现strlen函数
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr)
//	{
//		count++;
//		*arr++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "hello";
//	int ret = my_strlen(arr);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>  
//#include <assert.h>  
//int my_strncmp(const char *str1, const char *str2)
//{
//	assert(str1);
//	assert(str2);
//	while (*(str1) == *(str2))
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//int main()
//{
//	char *p1 = "ab";
//	char *p2 = "abcd";
//	printf("%d\n", my_strncmp(p1, p1));    //0  
//	printf("%d\n", my_strncmp(p1, p2));    //-1
//	getchar();
//	return 0;
//}
//
//模拟实现strncpy函数
//char* my_strncpy(char* dest, char* src,int n)
//{
//	char* ret = dest;
//	while (n--)
//	{
//		*(dest++) = *(src++);
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[20] = "hello world";
//	char arr2[10] = "ming";
//	my_strncpy(arr1, arr2, 4);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}
