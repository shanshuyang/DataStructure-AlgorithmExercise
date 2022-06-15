//用单链表结构存储栈---链栈
#pragma once
#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
#include "LinkedList.h"

struct linkedStack
{
	LinkedList* stack;		//存放栈元素的链表
};
typedef struct linkedStack LinkedStack;

/// <summary>
/// 初始化链栈
/// </summary>
/// <param name="LS">指向链栈的指针</param>
void InitLinkedStack(LinkedStack* LS);
/// <summary>
/// 链栈入栈函数
/// </summary>
/// <param name="LS">指向链栈的指针</param>
/// <param name="item">待入栈的元素</param>
void Push(LinkedStack* LS, ElementType item);
/// <summary>
/// 链栈的弹栈函数
/// </summary>
/// <param name="LS">指向链栈的指针</param>
/// <returns>出栈的元素</returns>
ElementType Pop(LinkedStack* LS);
/// <summary>
/// 读取链栈栈顶的元素
/// </summary>
/// <param name="LS">指向链栈的指针</param>
/// <returns>返回链栈栈顶的元素</returns>
ElementType Top(LinkedStack* LS);

#endif // !_LINKEDSTACK_H