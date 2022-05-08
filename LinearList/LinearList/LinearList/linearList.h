#pragma once
#ifndef _LinearList_H
enum boolean
{
	FALSE,
	TRUE
};
typedef int ElementType; //���Խ�int�޸�Ϊ�������������Ա��治ͬ������
typedef enum boolean Bool;

struct linearList
{
	ElementType* data; //����˳��洢��ʽ��ʹ������ʵ�ִ洢����
	int MaxSize; //���Ա����洢����
	int Last; //��¼���Ա�ĳ���
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
