//单链表节点结构
#pragma once
#ifndef _NODE_H
#define _NODE_H
typedef int ElementType;

struct node
{
	struct node* next; //指向下一个结点的指针
	ElementType data;
};
typedef struct node Node;

/// <summary>
/// 初始化单链表结点
/// </summary>
/// <param name="N">指向待初始化结点的指针</param>
/// <param name="item">待初始化结点存储的数据</param>
/// <param name="ptr">指向下一个结点的指针</param>
void InitNode(Node* N, ElementType item, Node* ptr);
/// <summary>
/// 插入一个单链表结点
/// </summary>
/// <param name="N">被插入的位置</param>
/// <param name="P">待插入的结点</param>
void InsertAfter(Node* N, Node* P);
/// <summary>
/// 删除一个单链表结点
/// </summary>
/// <param name="N">待删除的结点</param>
/// <returns>返回指向被删除结点的指针</returns>
Node* DeleteAfter(Node*N);
/// <summary>
/// 创建一个单链表的结点
/// </summary>
/// <param name="item">该节点存储的数据</param>
/// <param name="ptr">指向下一个结点的指针</param>
/// <returns>返回新建结点的指针</returns>
Node* GetNode(ElementType item, Node* ptr);
/// <summary>
/// 释放一个单链表的结点
/// </summary>
/// <param name="N">待释放的结点</param>
void FreeNode(Node* N);
#endif // !_NODE_H
