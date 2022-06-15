#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

//初始化链队列
void InitLinkedQueue(LinkedQueue* LQ)
{
	LQ->queue = (LinkedList*)malloc(sizeof(LinkedList));
	InitLinkedList(LQ->queue);
}

//队列中插入一个新数据元素
void InQueue(LinkedQueue* LQ, ElementType item)
{
	SetPosition(LQ->queue, (LQ->queue)->size - 1);	//设置队尾元素为当前结点
	InsertLAfter(LQ->queue, item);					//在队尾结点后插入新结点
}

//队列中删除一个元素
ElementType OutQueue(LinkedQueue* LQ)
{
	ElementType tmpData;
	if (!(LQ->queue)->size)							//若队列为空，提示出错信息
	{
		printf("OutQueue: underflowed!\n");
		exit(1);
	}

	SetPosition(LQ->queue, 0);						//当前结点位置移到队列头
	tmpData = GetData(LQ->queue);					//保存队列头结点的数据
	DeleteLAt(LQ->queue);							//删除队列头结点
	return tmpData;									//返回被删除的队列头数据
}

//取队列的头部元素
ElementType FrontQueue(LinkedQueue* LQ)
{
	if (!(LQ->queue)->size)							//若队列为空，提示出错信息
	{
		printf("FrontQueue: underflowed!\n");
		exit(1);
	}

	SetPosition(LQ->queue, 0);						//当前结点位置移到队列头
	return GetData(LQ->queue);						//返回队列头数据
}

//清除队列中的数据元素
void ClearLQ(LinkedQueue* LQ)
{
	Clear(LQ->queue);
}

//判断队列是否为空
Bool IsEmptyLQ(LinkedQueue* LQ)
{
	return LQ->queue->size ? FALSE : TRUE;
}
