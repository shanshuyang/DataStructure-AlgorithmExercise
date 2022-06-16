#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void GenBMDeltal1(CMyString* s, int* delta1);
void GenBMDeltal2(CMyString* s, int* delta2);
int FindCharInPattern(CMyString* s, char c);
int Max(int a, int b);

//使用BM匹配算法实现在字符串CS中查找字符串s首次出现的位置
int Find_BM(CMyString* CS, CMyString* s)
{
	int* delta1 = (int*)malloc(sizeof(int) * (s->length + 1));
	int* delta2 = (int*)malloc(sizeof(int) * (s->length + 1));
	GenBMDeltal1(s, delta1);
	GenBMDeltal2(s, delta2);
	int i = s->length - 1;
	int j = i;
	while (i > 0 && j < CS->length)
	{
		//从右往左开始匹配
		if (s->str[i] == CS->str[j])
		{
			//一个字符匹配成功则继续匹配前一个字符	
			i--;
			j--;
		}
		else
		{
			//如果匹配失败
			int move = Max(delta1[FindCharInPattern(s, CS->str[j])], delta2[i + 1]);
			j += move + i + 1 - s->length;
			i = s->length - 1;
		}
	}
	if (i == 0)
	{
		printf("Match successful, the index is: %d\n", j);
		return j;
	}
	printf("Match failed");
	return -1;
}

//生成数组delta1，存储字符到最右端的最短距离
void GenBMDeltal1(CMyString* s, int* delta1)
{
	delta1[0] = s->length;
	delta1[s->length] = 0;
	for (int i = s->length - 1; i > 0; i--)
	{
		delta1[i] = s->length - i;
		for (int j = i + 1; j < s->length + 1; j++)
		{
			if (s->str[i - 1] == s->str[j - 1])
			{
				delta1[i] = delta1[j];
				break;
			}
		}
	}
}

//生成数组delta2，存储字符左移匹配需要移动的距离
void GenBMDeltal2(CMyString* s, int* delta2)
{
	delta2[s->length] = 1;
	delta2[0] = 0;
	for (int k = 1; k < s->length; k++)
	{
		for (int n = 1; n < k + 1; n++)//移动次数n
		{
			for (int c = 0; c < s->length - k; c++)
			{
				if (s->str[k + c] != s->str[k + c - n])
				{
					break;
				}
				if (c == s->length - k - 1)
				{
					//匹配成功
					//n-1为匹配之前的移动次数
					delta2[k] = s->length - k + n - 1;
				}
			}
			//匹配失败
			if (n == k)
			{
				//n为无法继续匹配前的移动次数，即最大移动次数
				delta2[k] = s->length - k + n;
			}
		}
	}
}

//返回单个字符在串中第一次出现的位置对应与delta1的索引
int FindCharInPattern(CMyString* s, char c)
{
	for (int i = 0; i < s->length; i++)
	{
		if (c == s->str[i])
		{
			return i + 1;
		}
	}
	return 0;
}

//返回两数中较大的一个
int Max(int a, int b)
{
	return a > b ? a : b;
}

