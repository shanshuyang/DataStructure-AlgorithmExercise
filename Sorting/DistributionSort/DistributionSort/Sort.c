#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ������
void InitForSort(ForSort* FS, int a)
{
	for (int i = 2; i >= 0; i--)
	{
		FS->key[i] = a % 10;
		a = a / 10;
	}
	FS->next = NULL;
}

//��������
void RadixSort(ForSort* pData, int Clow, int Chigh, int d)
{
	typedef struct
	{
		ForSort* pHead;
		ForSort* pTail;
	}TempLink;
	int r = Chigh - Clow + 1;		//r��ʾ�����ĸ������������ֵĻ���Ϊ10����ĸ�Ļ���Ϊ26
	int i, j, k;
	TempLink* tlink;				//tlink���ڴ洢���������µ����ݲ���������
	ForSort* p;
	tlink = (TempLink*)malloc(sizeof(TempLink) * r);

	for (i = d - 1; i >= 0; i--)
	{
		//��ʼ��r���������
		for (j = 0; j < r; j++)
		{
			tlink[j].pHead = tlink[j].pTail = NULL;
		}
		//����¼����������䵽r��������
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
		//�ռ�r�������е�������
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

//��ӡ������
void PrintSortResult(ForSort* FS)
{
	while (FS != NULL)
	{
		//�����㱣������ݲ����
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