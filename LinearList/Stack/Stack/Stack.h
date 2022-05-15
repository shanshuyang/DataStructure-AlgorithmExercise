#pragma once
#ifndef _Stack_H
#define _Stack_H
enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;
typedef int ElementType;

struct stack
{
	int top;						//ջ��ָ��
	ElementType* elements;			//���ջԪ�ص�����
	int MaxSize;					//ջ�ռ�����ߴ�
};
typedef struct stack Stack;

void InitStack(Stack*, int sz);
void FreeStack(Stack*);
int Push(Stack*, ElementType);		
ElementType Pop(Stack*);			
ElementType GetTop(Stack*);
void MakeEmpty(Stack*);
Bool IsEmpty(Stack*);
Bool IsFull(Stack*);

#endif // !_Stack_H