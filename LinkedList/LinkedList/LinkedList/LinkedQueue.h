//用单链表结构存储队列---链队列
#pragma once
#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H
#include "LinkedList.h"

struct linkedQueue
{
	LinkedList* queue;
};
typedef struct linkedQueue LinkedQueue;

/// <summary>
/// 初始化链队列
/// </summary>
/// <param name="LQ">指向链队列的指针</param>
void InitLinkedQueue(LinkedQueue* LQ);
/// <summary>
/// 队列中插入一个新数据元素
/// </summary>
/// <param name="LQ"指向链队列的指针></param>
/// <param name="item">待插入的元素</param>
void InQueue(LinkedQueue* LQ, ElementType item);
/// <summary>
/// 队列中删除一个元素
/// </summary>
/// <param name="LQ">指向链队列的指针</param>
/// <returns>返回被删除的元素</returns>
ElementType OutQueue(LinkedQueue* LQ);
/// <summary>
/// 取队列的头部元素
/// </summary>
/// <param name="LQ">指向链队列的指针</param>
/// <returns>返回队列头部的元素</returns>
ElementType FrontQueue(LinkedQueue* LQ);
/// <summary>
/// 清除队列中的数据元素
/// </summary>
/// <param name="LQ">指向链队列的指针</param>
void ClearLQ(LinkedQueue* LQ);
/// <summary>
/// 判断队列是否为空
/// </summary>
/// <param name="LQ">指向链队列的指针</param>
/// <returns>如果链队列为空返回TRUE，否则返回FALSE</returns>
Bool IsEmptyLQ(LinkedQueue* LQ);

#endif // !_LINKEDQUEUE_H
