#include "Stack.h"

//����ջ�ռ䣬����һ����ջ
void InitStack(Stack* S, int sz)
{
	S->MaxSize = sz;
	S->elements = (ElementType*)malloc(sizeof(ElementType) * sz);
	S->top = -1;
}

//�ͷ�ջ�ռ�
void FreeStack(Stack* S)
{
	free(S->elements);
}

//��ջ
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

//��ջ
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

//ȡջ����ջԪ��
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

//��ջΪ��ջ
void MakeEmpty(Stack* S)
{
	S->top = -1;
}

//�ж�ջ�Ƿ�Ϊ��
Bool IsEmpty(Stack* S)
{
	return (Bool)(S->top == -1);
}

//�ж�ջ�Ƿ�Ϊ��
Bool IsFull(Stack* S)
{
	return (Bool)(S->top == S->MaxSize - 1);
}



