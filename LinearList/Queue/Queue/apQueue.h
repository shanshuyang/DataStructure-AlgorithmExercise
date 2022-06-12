//优先级队列，以正常插入，删除按优先级删除来实现
//存在另一种实现方式是以优先级插入，正常删除
#pragma once
#ifndef _apQueue_H
#define _apQueue_H
#define MaxPQSize 50
#include "Event.h"
typedef Event DataType; 

struct pQueue
{
	int count;					//优先队列元素个数
	DataType pqList[MaxPQSize];	//队列元素存储数组，DataType为用户定义的优先级类型
};
typedef struct pQueue PQueue;

/// <summary>
/// 初始化优先级队列
/// </summary>
/// <param name="pq">优先级队列指针</param>
void InitPQueue(PQueue* pq);
/// <summary>
/// 在优先级队列中插入一个元素
/// </summary>
/// <param name="pq">优先级队列指针</param>
/// <param name="item">插入元素</param>
void PQInsert(PQueue* pq, DataType item);
/// <summary>
/// 删除优先级队列中的元素
/// </summary>
/// <param name="pq">优先级队列指针</param>
/// <returns>删除成功返回被删除元素的优先级，否则报错</returns>
DataType PQDelete(PQueue* pq);
/// <summary>
/// 判优先级队列是否为空
/// </summary>
/// <param name="pq">优先级队列指针</param>
/// <returns>如果优先级队列为空返回1，否则返回0</returns>
int PQEmpty(PQueue* pq);
/// <summary>
/// 判优先级队列是否为满
/// </summary>
/// <param name="pq">优先级队列指针</param>
/// <returns>如果优先级队列为满返回1，否则返回0</returns>
int PQFull(PQueue* pq);

#endif // !_apQueue_H