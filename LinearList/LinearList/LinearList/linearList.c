#include <stdlib.h>
#include <stdio.h>
#include "linearList.h"

//线性表的初始化
void InitList(LinearList* L, int sz)
{
	if (sz > 0)
	{
		L->MaxSize = sz;
		L->Last = 0;
		L->data = (ElementType*)malloc(sizeof(ElementType) * L->MaxSize);
	}
}

//释放线性表的存储空间
void FreeList(LinearList* L) 
{
	free(L->data);
}

//判断线性表是否为空
Bool ListEmpty(LinearList* L) 
{
	return (L->Last <= 0) ? TRUE : FALSE;
}

//判断线性表是否为满
Bool ListFull(LinearList* L) 
{
	return (L->Last >= L->MaxSize) ? TRUE : FALSE;
}

//求线性表的长度
int ListLength(LinearList* L) 
{
	return L->Last;
}

//取线性表的第i个表目
ElementType GetElem(LinearList* L, int i) 
{
	return (i<0 || i>L->Last) ? NULL : L->data[i];
}

//在线性表中查找值为x的结点。如果查找成功则返回结点序号，否则返回-1，
//如果表中值为x的结点有多个，找到的是最前面的一个
int LocateElem(LinearList* L, ElementType x)
{
	int i;
	for (i = 0; i < L->Last; i++)
	{
		if (L->data[i] == x)
		{
			return i; //查找成功
		}
	}
	return -1; //查找失败
}

//在表中第i个位置插入值为x的结点。如果插入成功返回TRUE，否则返回FALSE
Bool InsertElem(LinearList* L, ElementType x, int i)
{
	int j;
	if (i<0 || i>L->Last || L->Last == L->MaxSize)
	{
		return FALSE; //插入位置不合适，插入失败
	}
	else
	{
		for (j = L->Last - 1; j >= i; j--) 
		{
			L->data[j + 1] = L->data[j]; //后移
		}
		L->data[i] = x; //插入
		L->Last++; //表长增1
		return TRUE;
	}
}

//删除表中第i个结点。如果删除成功返回TRUE，否则返回FALSE
Bool DeleteElem(LinearList* L, int i)
{
	int j;
	if (i<0 || i>L->Last || L->Last == 0)
	{
		return FALSE; //第i个结点不存在，删除失败
	}
	else
	{
		for (j = i; j < L->Last - 1; j++) 
		{
			L->data[j] = L->data[j + 1]; //前移
		}
		L->Last--; //表长减1
		return TRUE;
	}
}

//打印线性表的表目
void printout(LinearList* L)
{
	int i;
	for ( i = 0; i < L->Last; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}