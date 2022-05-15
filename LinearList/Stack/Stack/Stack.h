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
	int top;						//栈顶指针
	ElementType* elements;			//存放栈元素的数组
	int MaxSize;					//栈空间的最大尺寸
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