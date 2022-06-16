#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void GenKMPNext(int* next, CMyString* s);

//使用KMP匹配算法实现在字符串CS中查找字符串s首次出现的位置
int Find_KMP(CMyString* CS, CMyString* s)
{
	int i, j;
	int* next = (int*)malloc(sizeof(int) * (s->length));
	GenKMPNext(next, s);
	for (i = 0, j = 0; i < s->length && j < CS->length;)
	{
		if (s->str[i] == CS->str[j])
		{
			i++;
			j++;
		}
		else
		{
			if (next[i] >= 0)
			{
				i = next[i];
			}
			else
			{
				i = 0;
				j++;
			}
		}
	}
	if (i >= s->length)
	{
		return j - s->length;
	}
	else
	{
		return -1;
	}
}
//计算next数组
void GenKMPNext(int* next, CMyString* s)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < s->length - 1)
	{
		//找出p0，p1...pi中最大的相同的最左端子串和最右端子串
		while (j >= 0 && s->str[i] != s->str[j])
		{
			j = next[j];
		}
		i++;
		j++;
		if (s->str[i]==s->str[j])
		{
			next[i] = next[j];
		}
		else
		{
			next[i] = j;
		}
	}
}