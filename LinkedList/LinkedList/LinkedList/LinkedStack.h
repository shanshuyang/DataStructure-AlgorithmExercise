//�õ�����ṹ�洢ջ---��ջ
#pragma once
#ifndef _LINKEDSTACK_H
#define _LINKEDSTACK_H
#include "LinkedList.h"

struct linkedStack
{
	LinkedList* stack;		//���ջԪ�ص�����
};
typedef struct linkedStack LinkedStack;

/// <summary>
/// ��ʼ����ջ
/// </summary>
/// <param name="LS">ָ����ջ��ָ��</param>
void InitLinkedStack(LinkedStack* LS);
/// <summary>
/// ��ջ��ջ����
/// </summary>
/// <param name="LS">ָ����ջ��ָ��</param>
/// <param name="item">����ջ��Ԫ��</param>
void Push(LinkedStack* LS, ElementType item);
/// <summary>
/// ��ջ�ĵ�ջ����
/// </summary>
/// <param name="LS">ָ����ջ��ָ��</param>
/// <returns>��ջ��Ԫ��</returns>
ElementType Pop(LinkedStack* LS);
/// <summary>
/// ��ȡ��ջջ����Ԫ��
/// </summary>
/// <param name="LS">ָ����ջ��ָ��</param>
/// <returns>������ջջ����Ԫ��</returns>
ElementType Top(LinkedStack* LS);

#endif // !_LINKEDSTACK_H