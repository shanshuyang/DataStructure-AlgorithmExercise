#include "Stack.h"

//创建栈空间，生成一个空栈
void InitStack(Stack* S, int sz)
{
	S->MaxSize = sz;
	S->elements = (ElementType*)malloc(sizeof(ElementType) * sz);
	S->top = -1;
}

//释放栈空间
void FreeStack(Stack* S)
{
	free(S->elements);
}

//进栈
int Push(Stack* S, ElementType item)
{
	if (!IsFull(S))
	{
		S->elements[++(S->top)] = item;
		return 0;
	}
	else
	{
		return -1;
	}
}

//出栈
ElementType Pop(Stack* S)
{
	if (!IsEmpty(S))
	{
		return S->elements[(S->top)--];
	}
	else
	{
		printf("stack is empty!\n");
		exit(1);
	}
}

//取栈顶的栈元素
ElementType GetTop(Stack* S)
{
	if (!IsEmpty(S))
	{
		return S->elements[S->top];
	}
	else
	{
		printf("stack is empty!\n");
		exit(1);
	}
}

//置栈为空栈
void MakeEmpty(Stack* S)
{
	S->top = -1;
}

//判断栈是否为空
Bool IsEmpty(Stack* S)
{
	return (Bool)(S->top == -1);
}

//判断栈是否为满
Bool IsFull(Stack* S)
{
	return (Bool)(S->top == S->MaxSize - 1);
}



