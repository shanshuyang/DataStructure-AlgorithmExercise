#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ������
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//ֱ�Ӳ�������
void DirectInsertionSort(ForSort A[], int n)
{
	int i, j;
	ForSort temp;

	for (i = 1; i < n; i++)
	{
		j = i;
		temp = A[i];
		while (j > 0 && temp.key < A[j - 1].key)
		{
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
	PrintSortResult(A, n);
}

//�۰��������
void BinaryInsertionSort(ForSort A[], int n)
{
	int i, k, r;
	ForSort temp;
	for (i = 1; i < n; i++)
	{
		temp = A[i];	//�����۰뷨������������ļ�A[0]-A[i-1]֮����A[i]�Ĳ���λ��
		k = 0;
		r = i - 1;
		while (k <= r)
		{
			int m = (k + r) / 2;
			if (temp.key < A[m].key)
			{
				r = m - 1;	//��ǰ�벿�ּ����Ҳ���λ��
			}
			else
			{
				k = m + 1;	//�ں�벿�ּ����Ҳ���λ��
			}
		}
		//�ҵ�����λ��Ϊk���Ƚ�A[k]-A[i-1]����һ��λ��
		for (r = i; r > k; r--)
		{
			A[r] = A[r - 1];
		}
		A[k] = temp;
	}
	PrintSortResult(A, n);
}

//Shell����
void ShellSort(ForSort A[], int n, int s)
{
	int i, j, k;
	ForSort temp;
	//�������򣬳�ʼ����Ϊs��ÿѭ��һ���������룬ֱ������Ϊ0ʱ����
	for (k = s; k > 0; k >>= 1)
	{
		//��������
		for (i = k; i < n; i++)
		{
			temp = A[i];
			j = i - k;
			//�������򣬽�tempֱ�Ӳ������ں��ʵļ�¼λ��
			while (j >= 0 && temp.key < A[j].key)
			{
				A[j + k] = A[j];
				j -= k;
			}
			A[j + k] = temp;
		}
	}
	PrintSortResult(A, n);
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