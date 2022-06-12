#include "apQueue.h"
#include <stdio.h>
#include <stdlib.h>

//初始化优先级队列
void InitPQueue(PQueue* pq)
{
	pq->count = 0;
}

///在优先级队列中插入一个元素
void PQInsert(PQueue* pq, DataType item)
{
	if (pq->count == MaxPQSize)
	{
		printf("Priority queue overflow!\n");
		exit(1);
	}
	else
	{
		pq->pqList[pq->count] = item;
		pq->count++;
	}
}

//删除优先级队列中的元素
DataType PQDelete(PQueue* pq)
{
	DataType min;
	int i, minindex = 0;
	
	if (pq->count > 0)
	{
		min = pq->pqList[0];
		for (i = 0; i < pq->count; i++)					//寻找队列中优先级最高的元素
		{
			if (pq->pqList[i].time < min.time)
			{
				min = pq->pqList[i];
				minindex = i;
			}
		}
		pq->pqList[minindex] = pq->pqList[pq->count - 1];	//将队尾的元素换到minindex的位置
		pq->count--;										//队列元素个数减1
	}
	else
	{
		printf("Deleting from an empty priority queue!\n");
		exit(1);
	}
	return min;
}

//判优先级队列是否为空
int PQEmpty(PQueue* pq)
{
	return pq->count == 0;
}

//判优先级队列是否为满
int PQFull(PQueue* pq)
{
	return pq->count == MaxPQSize;
}