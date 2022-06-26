#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OnePassMerge(ForSort Dst[], ForSort Src[], int Len, int n);
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s, int e1, int e2);

//初始化函数
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//并归排序
//用二路并归排序对A[0], A[1], ..., A[n-1]排序
void MergeSort(ForSort A[], int n)
{
	int k;
	ForSort* B = (ForSort*)malloc(n * sizeof(ForSort));

	//初始子文件长度为1
	k = 1;
	while (k < n)
	{
		//将A中的子文件经过一趟并归存储到数组B
		OnePassMerge(B, A, k, n);
		//并归后子文件长度增加一倍
		k <<= 1;

		if (k >= n)
		{
			//已并归排序完毕，但结果在临时数组B中，调用标准函数memcpy()将其复制到A中
			memcpy(A, B, n * sizeof(ForSort));
		}
		else
		{
			//将B中的子文件经过一趟并归并存储到数组A
			OnePassMerge(A, B, k, n);
			//并归后子文件长度增加一倍
			k <<= 1;
		}
	}
	PrintSortResult(A, n);
}

//一趟两组并归函数
//将Scr中部分排序的多个子文件并归到Dst中子文件的长度为Len
void OnePassMerge(ForSort Dst[], ForSort Src[], int Len, int n)
{
	int i;
	for (i = 0; i < n - 2 * Len; i += 2 * Len)
	{
		//执行两两并归，将Scr中长度为Len的子文件并归成长度为2*Len的子文件，结果存放在Dst中
		TwoWayMerge(Dst, Src, i, i + Len - 1, i + 2 * Len - 1);
	}
	if (i < n - Len)
	{
		//尾部至多还有两个子文件
		TwoWayMerge(Dst, Src, i, i + Len - 1, n - 1);
	}
	else
	{
		//尾部可能还有一个子文件，直接复制到Dst中
		memcpy(&Dst[i], &Src[i], (n - i) * sizeof(ForSort));
	}
}

//两两并归函数
//将Scr中从s到e1的子文件和从e1+1到e2的子文件进行并归，结果存放Dst中从s开始的位置
void TwoWayMerge(ForSort Dst[], ForSort Src[], int s, int e1, int e2)
{
	int s1, s2;
	for (s1 = s, s2 = e1 + 1; s1 <= e1 && s2 <= e2;)
	{
		if (Src[s1].key<=Src[s2].key)
		{
			//第1个子文件最前面记录其排序码小，将其并归到Dst
			Dst[s++] = Src[s1++];
		}
		else
		{
			//第2个子文件最前面记录其排序码小，将其并归到Dst
			Dst[s++] = Src[s2++];
		}
	}
	if (s1 <= e1)
	{
		//第1个子文件未并归完，将其直接复制到Dst中
		memcpy(&Dst[s], &Src[s1], (e1 - s1 + 1) * sizeof(ForSort));
	}
	else
	{
		//第2个子文件未并归完，将其直接复制到Dst中
		memcpy(&Dst[s], &Src[s2], (e2 - s2 + 1) * sizeof(ForSort));
	}
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