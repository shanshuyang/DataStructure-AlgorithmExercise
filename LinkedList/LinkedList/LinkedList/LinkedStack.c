#include "LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ����ջ
void InitLinkedStack(LinkedStack* LS)
{
	LS->stack = (LinkedList*)malloc(sizeof(LinkedList));
	InitLinkedList(LS->stack);
}

//��ջ��ջ����
void Push(LinkedStack* LS, ElementType item)
{
	InsertLAt(LS->stack, item);
}

//��ջ�ĵ�ջ����
ElementType Pop(LinkedStack* LS)
{
	ElementType tmpData;
	if (!LS->stack->size)					//��ջ������������Ϣ���˳�
	{
		printf("Pop: underflowed!\n");
		exit(1);
	}
	tmpData = GetData(LS->stack);			//ɾ��ջ��Ԫ��
	DeleteLAt(LS->stack);
	return tmpData;							//����ջ������
}

//��ȡ��ջջ����Ԫ��
ElementType Top(LinkedStack* LS)
{
	if (!LS->stack->size)					//��ջ������������Ϣ���˳�
	{
		printf("Top: underflowed!\n");
		exit(1);
	}
	return GetData(LS->stack);				//����ջ������
}