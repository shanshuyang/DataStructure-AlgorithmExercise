#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* GenMinNode(TreeNode nodes[], int n);

//初始化函数
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//直接选择排序
void DirectSelectSort(ForSort A[], int n)
{
	int i, j, k;
	ForSort temp;

	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)		//寻找最小的元素
		{
			if (A[j].key < A[k].key)
			{
				k = j;
			}
		}
		if (i != k)						//如果最小元素不是当前元素，则与当前元素交换位置
		{
			temp = A[k];
			A[k] = A[i];
			A[i] = temp;
		}
	}
	PrintSortResult(A, n);
}

//树形选择排序
void TreeSelectSort(ForSort A[], int n)
{
	TreeNode nodes[100];
	for (int i = 0; i < n; i++)
	{
		TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
		node->index = i;
		node->key = A[i].key;
		nodes[i] = *node;
	}
	for (int i = 0; i < n; i++)
	{
		TreeNode* miniNode = GenMinNode(nodes, n);
		int minNodeIndex = miniNode->index;
		ForSort temp = A[minNodeIndex];
		A[minNodeIndex] = A[i];
		A[i] = temp;
		//调整nodes中index的值，使其与A中的顺序一致；另外还要更改对应的key值，此处尚待优化
		for (int j = 0; j < n; j++)
		{
			if (nodes[j].index == minNodeIndex)
			{
				nodes[j].index = i;
				nodes[j].key = MAX_VALUE;
			}
			else if (nodes[j].index==i)
			{
				nodes[j].index = minNodeIndex;
			}
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

TreeNode* GenMinNode(TreeNode nodes[], int n)
{
	TreeNode subNodes[20];
	int subNum = 0;
	if (n % 2 != 0)
	{
		subNodes[n / 2] = nodes[n];
		n--;
		subNum++;
	}
	for (int i = 0; i < n; i += 2)
	{
		TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
		if (nodes[i].key < nodes[i + 1].key)
		{
			newNode->index = nodes[i].index;
			newNode->key = nodes[i].key;
		}
		else
		{
			newNode->index = nodes[i + 1].index;
			newNode->key = nodes[i + 1].key;
		}
		subNodes[i / 2] = *newNode;
		subNum++;
	}
	if (subNum == 1)
	{
		return &subNodes[0];
	}
	else
	{
		GenMinNode(subNodes, subNum);
	}
}