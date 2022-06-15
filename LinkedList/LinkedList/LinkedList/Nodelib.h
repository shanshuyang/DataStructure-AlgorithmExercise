//单链表节点结构库，实现单链表的建立与访问
#pragma once
#ifndef _NODE_LIBRARY_H
#define _NODE_LIBRARY_H
#include "Node.h"

enum  appendNewline
{
	noNewline,
	addNewline
};
typedef enum appendNewline AppendNewline;

/// <summary>
/// 打印链表
/// </summary>
/// <param name="head">链表头指针</param>
/// <param name="addnl">指定输出每一个结点后是否换行</param>
void PrintList(Node* head, AppendNewline addnl);
/// <summary>
/// 单链表中基于表目的查找
/// </summary>
/// <param name="head">链表头指针</param>
/// <param name="item">待查找的元素</param>
/// <returns>查找成功返回1，否则返回0</returns>
int Find(Node* head, ElementType item);
/// <summary>
/// 在单链表的头部插入一个新的单链表结点
/// </summary>
/// <param name="head">指向指向头结点指针的指针，即指向头结点的指针的地址</param>
/// <param name="item">待插入的数据</param>
void InsertFront(Node** head, ElementType item);
/// <summary>
/// 删除单链表的头结点
/// </summary>
/// <param name="head">指向指向头结点指针的指针，即指向头结点的指针的地址</param>
void DeleteAt(Node** head);
/// <summary>
/// 删除单链表中值为key的结点
/// </summary>
/// <param name="head">指向指向头结点指针的指针，即指向头结点的指针的地址</param>
/// <param name="key">删除目标结点的关键值</param>
void Delete(Node** head, ElementType key);
/// <summary>
/// 在有序单链表中插入新结点
/// </summary>
/// <param name="head">指向指向头结点指针的指针，即指向头结点的指针的地址</param>
/// <param name="item">待插入的数据</param>
void InsertOrder(Node** head, ElementType item);
/// <summary>
/// 删除整个单链表
/// </summary>
/// <param name="head"></param>
void ClearList(Node** head);
#endif // !_NODE_LIBRARY_H