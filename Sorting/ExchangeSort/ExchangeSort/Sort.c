#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//初始化函数
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//冒泡排序
void BubbleSort(ForSort A[], int n)
{
	int i, j;
	Bool flag;
	ForSort temp;

	for (i = n - 1, flag = (Bool)1; i > 0 && flag; i--)
	{
		flag = FALSE;		//设置未交换标志
		for (j = 0; j < i; j++)
		{
			if (A[j + 1].key < A[j].key)
			{
				flag = TRUE;		//有交换发生，置标志
				temp = A[j + 1];	//交换
				A[j + 1] = A[j];
				A[j] = temp;
			}
		}
	}
	PrintSortResult(A, n);
}

//快速排序
void QuickSort(ForSort A[], int low, int high)
{
	int i, j;
	ForSort temp;
	
	if (low >= high)
	{
		return;
	}

	i = low;
	j = high;
	temp = A[i];
	while (i < j)
	{
		while (i < j && temp.key < A[j].key)	//从后往前进行比较，直到当前记录的排序码小于等于中心值
		{
			j--;
		}
		if (i < j)								//将排序码小于等于中心值的记录交换到前面当前空出的记录位置
		{
			A[i++] = A[j];
		}
		while (i < j && temp.key >= A[i].key)	//从前往后进行比较，直到当前记录的排序码大于中心值
		{
			i++;
		}
		if (i<j)								//将排序码大于中心值的记录交换到后面当前空出的记录位置
		{
			A[j--] = A[i];
		}
	}
	A[i] = temp;								//找到中心值对应的记录所在的位置，写入中心值对应的记录
	QuickSort(A, low, --j);						//递归处理排序码小于等于中心值的那组记录
	QuickSort(A, ++i, high);					//递归处理排序码大于中心值的那组记录
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