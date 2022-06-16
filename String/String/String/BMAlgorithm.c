#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void GenBMDeltal1(CMyString* s, int* delta1);
void GenBMDeltal2(CMyString* s, int* delta2);
int FindCharInPattern(CMyString* s, char c);
int Max(int a, int b);

//ʹ��BMƥ���㷨ʵ�����ַ���CS�в����ַ���s�״γ��ֵ�λ��
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
		//��������ʼƥ��
		if (s->str[i] == CS->str[j])
		{
			//һ���ַ�ƥ��ɹ������ƥ��ǰһ���ַ�	
			i--;
			j--;
		}
		else
		{
			//���ƥ��ʧ��
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

//��������delta1���洢�ַ������Ҷ˵���̾���
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

//��������delta2���洢�ַ�����ƥ����Ҫ�ƶ��ľ���
void GenBMDeltal2(CMyString* s, int* delta2)
{
	delta2[s->length] = 1;
	delta2[0] = 0;
	for (int k = 1; k < s->length; k++)
	{
		for (int n = 1; n < k + 1; n++)//�ƶ�����n
		{
			for (int c = 0; c < s->length - k; c++)
			{
				if (s->str[k + c] != s->str[k + c - n])
				{
					break;
				}
				if (c == s->length - k - 1)
				{
					//ƥ��ɹ�
					//n-1Ϊƥ��֮ǰ���ƶ�����
					delta2[k] = s->length - k + n - 1;
				}
			}
			//ƥ��ʧ��
			if (n == k)
			{
				//nΪ�޷�����ƥ��ǰ���ƶ�������������ƶ�����
				delta2[k] = s->length - k + n;
			}
		}
	}
}

//���ص����ַ��ڴ��е�һ�γ��ֵ�λ�ö�Ӧ��delta1������
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

//���������нϴ��һ��
int Max(int a, int b)
{
	return a > b ? a : b;
}

