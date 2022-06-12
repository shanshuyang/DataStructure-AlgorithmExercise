//循环队列
#pragma once
#ifndef _Queue_H
#define _Queue_H
enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;
typedef int ElementType;

struct queue
{
	int rear;						//队尾指针，指向下一个入队的位置
	int front;						//队首指针
	ElementType* elements;			//存放队列元素的数组
	int MaxSize;					//队列空间的最大尺寸
};
typedef struct queue Queue;

/// <summary>
/// 创建队列空间，生成一个空队列
/// </summary>
/// <param name="Q">队列指针</param>
/// <param name="sz">队列空间大小</param>
void InitQueue(Queue* Q, int sz);	
/// <summary>
/// 队列空间释放
/// </summary>
/// <param name="Q">队列指针</param>
void FreeQueue(Queue* Q);	
/// <summary>
/// 队列置空
/// </summary>
/// <param name="Q">队列指针</param>
void MakeEmpty(Queue* Q);	
/// <summary>
/// 判队列是否为空
/// </summary>
/// <param name="Q">队列指针</param>
/// <returns>如果队列为空返回TRUE，否则返回FALSE</returns>
Bool IsEmpty(Queue* Q);				
/// <summary>
/// 判队列是否为满
/// </summary>
/// <param name="Q">队列指针</param>
/// <returns>如果队列为满返回TRUE，否则返回FALSE</returns>
Bool IsFull(Queue* Q);
/// <summary>
/// 求队列的元素个数
/// </summary>
/// <param name="Q">队列指针</param>
/// <returns>返回当前队列中元素的个数</returns>
int Length(Queue* Q);					
/// <summary>
/// 若队列未满，则插入返回0，否则返回-1
/// </summary>
/// <param name="Q">队列指针</param>
/// <param name="item">入队项</param>
/// <returns>入队成功返回0，否则返回-1</returns>
int EnQueue(Queue* Q, ElementType item);
/// <summary>
/// 若队列非空，则出队，返回队首的值，否则报错
/// </summary>
/// <param name="Q">队列指针</param>
/// <returns>出队成功返回出队元素的值，否则报错</returns>
ElementType DeQueue(Queue* Q);		
/// <summary>
/// 若队列非空，则返回队首元素的值，否则报错
/// </summary>
/// <param name="Q">队列指针</param>
/// <returns>队列非空，则返回队首元素的值，否则报错</returns>
ElementType GetFront(Queue* Q);		

#endif // !_Queue_H