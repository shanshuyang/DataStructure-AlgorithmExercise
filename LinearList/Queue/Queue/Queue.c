#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

//创建队列空间，生成一个空队列
void InitQueue(Queue* Q, int sz)
{
	Q->MaxSize = sz;
	Q->elements = (ElementType*)malloc(sizeof(ElementType) * sz); //创建队列空间
	Q->front = Q->rear = 0;
}

// 队列空间释放
void FreeQueue(Queue* Q)
{
	free(Q->elements);
}

//队列置空
void MakeEmpty(Queue* Q)
{
	Q->front = Q->rear = 0;
}

//判队列是否为空
Bool IsEmpty(Queue* Q)
{
	return (Bool)(Q->front == Q->rear);
}

//判队列是否为满
Bool IsFull(Queue* Q)
{
	return (Bool)(Q->front == ((Q->rear + 1) % Q->MaxSize));
}


//求队列的元素个数
int Length(Queue* Q)
{
	return (Q->rear - Q->front + Q->MaxSize) % (Q->MaxSize);
}

//入队，若队列未满，则item插入队尾，返回0，否则返回-1
int EnQueue(Queue* Q, ElementType item)
{
	if (!IsFull(Q))
	{
		Q->elements[Q->rear] = item;				//入队
		Q->rear = (Q->rear + 1) % (Q->MaxSize);		//队尾指针加1
		return 0;
	}
	else
	{
		return -1;
	}
}

//出队，若队列非空，则删除对首元素，返回该元素的值，否则报错
ElementType DeQueue(Queue* Q)
{
	ElementType item;
	if (!IsEmpty(Q))
	{
		item = Q->elements[Q->front];				
		Q->front = (Q->front + 1) % (Q->MaxSize);	//队首指针加1
		return item;								//队列非空，返回队首元素的值
	}
	else
	{
		printf("error!");
		exit(1);
	}
}

//获取队首元素，若队列非空，则返回队首元素的值，否则报错
ElementType GetFront(Queue* Q)
{
	if (!IsEmpty(Q))
	{	
		return Q->elements[Q->front];	//队列非空，返回队首元素的值
	}
	else
	{
		printf("error!");
		exit(1);
	}
}

