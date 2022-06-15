//基于单链表结点结构的链队列---循环链式队列，只用尾结点指针，保证链队列插入、删除运算时间开销为O(1)
#pragma once
#ifndef _CLNKQUEUE_H
#define _CLNKQUEUE_H
typedef int T;

struct LNode
{
	T data;
	struct LNode* next;
};
typedef struct LNode CLnkQueue;

/// <summary>
/// 释放循环链队列
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
void CLQ_Free(CLnkQueue* q);
/// <summary>
/// 清空循环链队列
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针的地址</param>
void CLQ_MakeEmpty(CLnkQueue** q);
/// <summary>
/// 判断循环链队列是否为空
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
/// <returns>如果为空返回1，否则返回0</returns>
int CLQ_IsEmpty(CLnkQueue* q);
/// <summary>
/// 求循环链队列的长度
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
/// <returns>返回循环链队列的长度</returns>
int CLQ_Length(CLnkQueue* q);
/// <summary>
/// 入队列，新结点加入链队列尾部
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
/// <param name="x">待插入的元素</param>
void CLQ_In(CLnkQueue** q, T x);
/// <summary>
/// 出队列，删除链队列头部的元素
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针的地址</param>
/// <returns>返回被删除的结点的数据</returns>
T CLQ_Out(CLnkQueue** q);
/// <summary>
/// 获取队列头的数据
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
/// <returns>返回队列头结点的数据</returns>
T CLQ_Head(CLnkQueue* q);
/// <summary>
/// 打印队列的所有结点
/// </summary>
/// <param name="q">指向循环链队列尾结点的指针</param>
void CLQ_Print(CLnkQueue* q);

#endif // !_CLNKQUEUE_H