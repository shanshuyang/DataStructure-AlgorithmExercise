#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

//�������пռ䣬����һ���ն���
void InitQueue(Queue* Q, int sz)
{
	Q->MaxSize = sz;
	Q->elements = (ElementType*)malloc(sizeof(ElementType) * sz); //�������пռ�
	Q->front = Q->rear = 0;
}

// ���пռ��ͷ�
void FreeQueue(Queue* Q)
{
	free(Q->elements);
}

//�����ÿ�
void MakeEmpty(Queue* Q)
{
	Q->front = Q->rear = 0;
}

//�ж����Ƿ�Ϊ��
Bool IsEmpty(Queue* Q)
{
	return (Bool)(Q->front == Q->rear);
}

//�ж����Ƿ�Ϊ��
Bool IsFull(Queue* Q)
{
	return (Bool)(Q->front == ((Q->rear + 1) % Q->MaxSize));
}


//����е�Ԫ�ظ���
int Length(Queue* Q)
{
	return (Q->rear - Q->front + Q->MaxSize) % (Q->MaxSize);
}

//��ӣ�������δ������item�����β������0�����򷵻�-1
int EnQueue(Queue* Q, ElementType item)
{
	if (!IsFull(Q))
	{
		Q->elements[Q->rear] = item;				//���
		Q->rear = (Q->rear + 1) % (Q->MaxSize);		//��βָ���1
		return 0;
	}
	else
	{
		return -1;
	}
}

//���ӣ������зǿգ���ɾ������Ԫ�أ����ظ�Ԫ�ص�ֵ�����򱨴�
ElementType DeQueue(Queue* Q)
{
	ElementType item;
	if (!IsEmpty(Q))
	{
		item = Q->elements[Q->front];				
		Q->front = (Q->front + 1) % (Q->MaxSize);	//����ָ���1
		return item;								//���зǿգ����ض���Ԫ�ص�ֵ
	}
	else
	{
		printf("error!");
		exit(1);
	}
}

//��ȡ����Ԫ�أ������зǿգ��򷵻ض���Ԫ�ص�ֵ�����򱨴�
ElementType GetFront(Queue* Q)
{
	if (!IsEmpty(Q))
	{	
		return Q->elements[Q->front];	//���зǿգ����ض���Ԫ�ص�ֵ
	}
	else
	{
		printf("error!");
		exit(1);
	}
}

