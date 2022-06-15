#include "LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>

//初始化链栈
void InitLinkedStack(LinkedStack* LS)
{
	LS->stack = (LinkedList*)malloc(sizeof(LinkedList));
	InitLinkedList(LS->stack);
}

//链栈入栈函数
void Push(LinkedStack* LS, ElementType item)
{
	InsertLAt(LS->stack, item);
}

//链栈的弹栈函数
ElementType Pop(LinkedStack* LS)
{
	ElementType tmpData;
	if (!LS->stack->size)					//空栈，给出错误信息并退出
	{
		printf("Pop: underflowed!\n");
		exit(1);
	}
	tmpData = GetData(LS->stack);			//删除栈顶元素
	DeleteLAt(LS->stack);
	return tmpData;							//返回栈顶数据
}

//读取链栈栈顶的元素
ElementType Top(LinkedStack* LS)
{
	if (!LS->stack->size)					//空栈，给出错误信息并退出
	{
		printf("Top: underflowed!\n");
		exit(1);
	}
	return GetData(LS->stack);				//返回栈顶数据
}