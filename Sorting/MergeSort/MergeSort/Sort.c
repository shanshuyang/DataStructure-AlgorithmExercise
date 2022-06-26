#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OnePassMerge(ForSort Dst[], ForSort Src[], int Len, int n);
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s, int e1, int e2);

//��ʼ������
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//��������
//�ö�·���������A[0], A[1], ..., A[n-1]����
void MergeSort(ForSort A[], int n)
{
	int k;
	ForSort* B = (ForSort*)malloc(n * sizeof(ForSort));

	//��ʼ���ļ�����Ϊ1
	k = 1;
	while (k < n)
	{
		//��A�е����ļ�����һ�˲���洢������B
		OnePassMerge(B, A, k, n);
		//��������ļ���������һ��
		k <<= 1;

		if (k >= n)
		{
			//�Ѳ���������ϣ����������ʱ����B�У����ñ�׼����memcpy()���临�Ƶ�A��
			memcpy(A, B, n * sizeof(ForSort));
		}
		else
		{
			//��B�е����ļ�����һ�˲��鲢�洢������A
			OnePassMerge(A, B, k, n);
			//��������ļ���������һ��
			k <<= 1;
		}
	}
	PrintSortResult(A, n);
}

//һ�����鲢�麯��
//��Scr�в�������Ķ�����ļ����鵽Dst�����ļ��ĳ���ΪLen
void OnePassMerge(ForSort Dst[], ForSort Src[], int Len, int n)
{
	int i;
	for (i = 0; i < n - 2 * Len; i += 2 * Len)
	{
		//ִ���������飬��Scr�г���ΪLen�����ļ�����ɳ���Ϊ2*Len�����ļ�����������Dst��
		TwoWayMerge(Dst, Src, i, i + Len - 1, i + 2 * Len - 1);
	}
	if (i < n - Len)
	{
		//β�����໹���������ļ�
		TwoWayMerge(Dst, Src, i, i + Len - 1, n - 1);
	}
	else
	{
		//β�����ܻ���һ�����ļ���ֱ�Ӹ��Ƶ�Dst��
		memcpy(&Dst[i], &Src[i], (n - i) * sizeof(ForSort));
	}
}

//�������麯��
//��Scr�д�s��e1�����ļ��ʹ�e1+1��e2�����ļ����в��飬������Dst�д�s��ʼ��λ��
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s, int e1, int e2)
{
	int s1, s2;
	for (s1 = s, s2 = e1 + 1; s1 <= e1 && s2 <= e2;)
	{
		if (Src[s1].key<=Src[s2].key)
		{
			//��1�����ļ���ǰ���¼��������С�����䲢�鵽Dst
			Dst[s++] = Src[s1++];
		}
		else
		{
			//��2�����ļ���ǰ���¼��������С�����䲢�鵽Dst
			Dst[s++] = Src[s2++];
		}
	}
	if (s1 <= e1)
	{
		//��1�����ļ�δ�����꣬����ֱ�Ӹ��Ƶ�Dst��
		memcpy(&Dst[s], &Src[s1], (e1 - s1 + 1) * sizeof(ForSort));
	}
	else
	{
		//��2�����ļ�δ�����꣬����ֱ�Ӹ��Ƶ�Dst��
		memcpy(&Dst[s], &Src[s2], (e2 - s2 + 1) * sizeof(ForSort));
	}
}

//��ӡ������
void PrintSortResult(ForSort A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i].key);
	}
	printf("\n");
}