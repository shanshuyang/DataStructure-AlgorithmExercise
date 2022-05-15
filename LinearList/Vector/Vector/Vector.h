#pragma once
#ifndef _Vector_H
#define _Vector_H
enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;
typedef int ElementType;
struct vector
{
	ElementType* elements;
	int ArraySize;
	int VectorLength;
};
typedef struct vector Vector;
void GetArray(Vector*);
void InitVector(Vector*, int sz);
ElementType GetNode(Vector*, int i);
void FreeVector(Vector*);
/// <summary>
/// 查找值为x的结点，如果找到则返回该结点的序号，否则返回-1
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
/// <returns></returns>
int Find(Vector*, ElementType);
Bool Insert(Vector*, ElementType, int);
Bool Remove(Vector*, int);
void printout(Vector*);
#endif // !_Vector_H
