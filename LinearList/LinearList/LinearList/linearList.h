#pragma once
#ifndef _LinearList_H
enum boolean
{
	FALSE,
	TRUE
};
typedef int ElementType; //可以将int修改为任意数据类型以保存不同的数据
typedef enum boolean Bool;

struct linearList
{
	ElementType* data; //采用顺序存储方式，使用数组实现存储数据
	int MaxSize; //线性表最大存储容量
	int Last; //记录线性表的长度
};
typedef struct linearList LinearList;

void InitList(LinearList* L, int sz);
void FreeList(LinearList* L);
Bool ListEmpty(LinearList* L);
Bool ListFull(LinearList* L);
int ListLength(LinearList* L);
ElementType GetElem(LinearList* L, int i);
int LocateElem(LinearList* L, ElementType x);
Bool InsertElem(LinearList* L, ElementType x, int i);
Bool DeleteElem(LinearList* L, int i);
void printout(LinearList* L);
#endif // !_LinearList_H
