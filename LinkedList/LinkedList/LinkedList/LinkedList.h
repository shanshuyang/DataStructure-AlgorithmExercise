//单链表结构
#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "Node.h"

enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;

struct linkedList
{
	Node* front, * rear;		//指向表头和表尾的指针
	Node* prevPtr, * currPtr;	//用于访问数据、插入和删除结点的指针
	int size;					//表中的结点数
	int position;				//表中当前结点位置计数
};
typedef struct linkedList LinkedList;

/// <summary>
/// 初始化单链表
/// </summary>
/// <param name="L">指向单链表的指针</param>
void InitLinkedList(LinkedList* L);
/// <summary>
/// 判断表是否为空
/// </summary>
/// <param name="L">指向单链表的指针</param>
/// <returns>如果为空返回TRUE，否则返回FALSE</returns>
Bool IsEmpty(LinkedList* L);
/// <summary>
/// 求当前结点的后继结点的位置
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <returns>返回后继结点的位置</returns>
int NextLNode(LinkedList* L);
/// <summary>
/// 重定位链表的当前结点
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <param name="pos">重定位的位置</param>
/// <returns>返回当前结点的位置</returns>
int SetPosition(LinkedList* L, int pos);
/// <summary>
/// 在当前结点处插入结点，插入后当前结点指针指向新插入的结点
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <param name="item">待插入的元素</param>
void InsertLAt(LinkedList* L, ElementType item);
/// <summary>
/// 在当前结点后插入结点，插入后当前结点指针指向新插入的结点
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <param name="item">待插入的元素</param>
void InsertLAfter(LinkedList* L, ElementType item);
/// <summary>
/// 删除当前结点，删除后当前结点指针指向被删除结点的后继结点
/// </summary>
/// <param name="L">指向链表的指针</param>
void DeleteLAt(LinkedList* L);
/// <summary>
/// 删除当前结点的后继结点，当前结点指针指向不变
/// </summary>
/// <param name="L">指向链表的指针</param>
void DeleteLAfter(LinkedList* L);
/// <summary>
/// 获取链表中当前结点的数据
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <returns>返回链表中当前结点的数据</returns>
ElementType GetData(LinkedList* L);
/// <summary>
/// 修改链表中当前结点的数据
/// </summary>
/// <param name="L">指向链表的指针</param>
/// <param name="item">修改后的目标数据</param>
void SetData(LinkedList* L, ElementType item);
/// <summary>
/// 清空链表
/// </summary>
/// <param name="L">指向链表的指针</param>
void Clear(LinkedList* L);

#endif // !_LINKEDLIST_H


