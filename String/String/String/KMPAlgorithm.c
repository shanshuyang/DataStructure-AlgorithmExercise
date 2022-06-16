#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void GenKMPNext(int* next, CMyString* s);

//ʹ��KMPƥ���㷨ʵ�����ַ���CS�в����ַ���s�״γ��ֵ�λ��
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
//����next����
void GenKMPNext(int* next, CMyString* s)
{
	int i = 0, j = -1;
	next[0] = -1;
	while (i < s->length - 1)
	{
		//�ҳ�p0��p1...pi��������ͬ��������Ӵ������Ҷ��Ӵ�
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