#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//初始化函数
void InitForSort(ForSort* FS, int a)
{
	for (int i = 2; i >= 0; i--)
	{
		FS->key[i] = a % 10;
		a = a / 10;
	}
	FS->next = NULL;
}

//基数排序
void RadixSort(ForSort* pData, int Clow, int Chigh, int d)
{
	typedef struct
	{
		ForSort* pHead;
		ForSort* pTail;
	}TempLink;
	int r = Chigh - Clow + 1;		//r表示基数的个数，例如数字的基数为10，字母的基数为26
	int i, j, k;
	TempLink* tlink;				//tlink用于存储各个基数下的数据并用于排序
	ForSort* p;
	tlink = (TempLink*)malloc(sizeof(TempLink) * r);

	for (i = d - 1; i >= 0; i--)
	{
		//初始化r个分配队列
		for (j = 0; j < r; j++)
		{
			tlink[j].pHead = tlink[j].pTail = NULL;
		}
		//将记录的排序码分配到r个队列中
		for (p = pData; p != NULL; p = p->next)
		{
			j = p->key[i] - Clow;
			if (tlink[j].pHead == NULL)
			{
				tlink[j].pHead = tlink[j].pTail = p;
			}
			else
			{
				tlink[j].pTail->next = p;
				tlink[j].pTail = p;
			}
		}
		//收集r个队列中的排序码
		j = 0;
		while (tlink[j].pHead == NULL)
		{
			j++;
		}
		pData = tlink[j].pHead;
		p = tlink[j].pTail;

		for (k = j + 1; k < r; k++)
		{
			if (tlink[k].pHead!=NULL)
			{
				p->next = tlink[k].pHead;
				p = tlink[k].pTail;
			}
		}
		p->next = NULL;
	}
	PrintSortResult(pData);
}

//打印排序结果
void PrintSortResult(ForSort* FS)
{
	while (FS != NULL)
	{
		//计算结点保存的数据并输出
		int num = 0;
		for (int i = 0; i < 2; i++)
		{
			num = (num + FS->key[i]) * 10;
		}
		num += FS->key[2];
		printf("%d ", num);
		FS = FS->next;
	}
	printf("\n");
}