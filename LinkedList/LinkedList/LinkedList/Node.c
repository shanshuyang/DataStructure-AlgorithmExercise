#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

//初始化单链表结点
void InitNode(Node* N, ElementType item, Node* ptr)
{
	N->data = item;
	N->next = ptr;
}

//插入一个单链表结点
void InsertAfter(Node* N, Node* P)
{
	P->next = N->next;	//当前结点的后继结点连接到结点P之后
	N->next = P;		//将结点P作为当前结点的后继结点
}

//删除一个单链表结点
Node* DeleteAfter(Node* N)
{
	Node* ptr = N->next;	//保存当前结点的后继结点
	if (ptr == NULL)
	{
		return NULL;		//若没有后继结点则返回空指针
	}
	N->next = ptr->next;	//当前结点指向被删除结点的后继结点
	return ptr;				//返回指向被删除结点的指针
}

//创建一个单链表的结点
Node* GetNode(ElementType item, Node* ptr)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		printf("Memory allocation failure!\n");
		exit(1);
	}
	else
	{
		InitNode(newNode, item, ptr);
		return newNode;
	}
}

//释放一个单链表的结点
void FreeNode(Node* N)
{
	if (!N)		//如果N为空，则给出提示并返回
	{
		printf("FreeNode: invalid node pointer!\n");
		return;
	}
	free(N);	//释放结点
}