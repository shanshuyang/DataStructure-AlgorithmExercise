#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//初始化函数
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//直接插入排序
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

//折半插入排序
void BinaryInsertionSort(ForSort A[], int n)
{
	int i, k, r;
	ForSort temp;
	for (i = 1; i < n; i++)
	{
		temp = A[i];	//采用折半法在已排序的子文件A[0]-A[i-1]之间找A[i]的插入位置
		k = 0;
		r = i - 1;
		while (k <= r)
		{
			int m = (k + r) / 2;
			if (temp.key < A[m].key)
			{
				r = m - 1;	//在前半部分继续找插入位置
			}
			else
			{
				k = m + 1;	//在后半部分继续找插入位置
			}
		}
		//找到插入位置为k，先将A[k]-A[i-1]右移一个位置
		for (r = i; r > k; r--)
		{
			A[r] = A[r - 1];
		}
		A[k] = temp;
	}
	PrintSortResult(A, n);
}

//Shell排序
void ShellSort(ForSort A[], int n, int s)
{
	int i, j, k;
	ForSort temp;
	//分组排序，初始增量为s，每循环一次增量减半，直到增量为0时结束
	for (k = s; k > 0; k >>= 1)
	{
		//分组排序
		for (i = k; i < n; i++)
		{
			temp = A[i];
			j = i - k;
			//组内排序，将temp直接插入组内合适的记录位置
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

//打印排序结果
void PrintSortResult(ForSort A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i].key);
	}
	printf("\n");
}