#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>

//申请向量的存储空间
void GetArray(Vector* V)
{
	V->elements = (ElementType*)malloc(sizeof(ElementType) * V->ArraySize);
	if (V->elements == NULL)
	{
		printf("Memory Allocation Error");
	}
}

//初始化函数，建立一个最大长度为sz的数组
void InitVector(Vector* V, int sz)
{
	if (sz <= 0)
	{
		printf("Invalid Array Size\n");
	}
	else
	{
		V->ArraySize = sz;
		V->VectorLength = 0;
		GetArray(V);
	}
}

//取向量中第i个结点的值，如果存在则返回该节点的值，否则返回NULL
ElementType GetNode(Vector* V, int i)
{
	return (i < 0 || i >= V->VectorLength) ? NULL : V->elements[i];
}

//释放向量存储空间
void FreeVector(Vector* V)
{
	free(V->elements);
}

//查找值为x的结点，如果找到则返回该结点的序号，否则返回-1
int Find(Vector* V, ElementType x)
{
	int i;
	for (i = 0; i < V->VectorLength; i++)
	{
		if (V->elements[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//在向量第i个位置插入值为x的新结点，如果插入成功返回TRUE，否则返回FALSE
Bool Insert(Vector* V, ElementType x, int i)
{
	int j;
	if (V->VectorLength == V->ArraySize) //向量存储空间已满
	{
		printf("overflow\n");
		return FALSE;
	}
	else if (i<0 || i>V->VectorLength) //插入位置错误
	{
		printf("position error\n");
		return FALSE;
	}
	else
	{
		for (j = V->VectorLength - 1; j >= i; j--)
		{
			V->elements[j + 1] = V->elements[j]; //后移
		}
		V->elements[i] = x; //插入
		V->VectorLength++; //向量长度增1
		return TRUE;
	}
}

//删除第i个结点，如果删除成功返回TRUE，否则返回FALSE
Bool Remove(Vector* V, int i)
{
	int j;
	if (V->VectorLength == 0)
	{
		printf("Vector is empty\n");
		return FALSE;
	}
	else if (i<0 || i>V->VectorLength - 1)
	{
		printf("position error\n");
		return FALSE;
	}
	else
	{
		for (j = i; j < V->VectorLength - 1; j++)
		{
			V->elements[j] = V->elements[j + 1]; //前移		
		}
		V->VectorLength--; //向量长度减1
		return TRUE;
	}
}

//输出向量中所有的结点
void printout(Vector* V)
{
	int i;
	for ( i = 0; i < V->VectorLength; i++)
	{
		printf("%d ", V->elements[i]);
	}
	printf("\n");
}