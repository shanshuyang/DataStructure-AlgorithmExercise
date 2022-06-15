#include "Nodelib.h"
#include <stdio.h>
#include <stdlib.h>

//打印链表
void PrintList(Node* head, AppendNewline addnl)
{
	Node* currPtr = head;
	//打印当前结点数据直至表尾
	while (currPtr != NULL)
	{
		if (addnl == addNewline)
		{
			printf("%d\n", currPtr->data);
		}
		else
		{
			printf("%d ", currPtr->data);
		}
		currPtr = currPtr->next;
	}
}

//单链表中基于表目的查找
int Find(Node* head, ElementType item)
{
	Node* currPtr = head;
	Node* prevPtr = NULL;
	while (currPtr != NULL)
	{
		if (currPtr->data == item)	//比较链表结点的数据域
		{
			return 1;	//查找成功
		}
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	return 0;	//查找失败
}

//在单链表的头部插入一个新的单链表结点
void InsertFront(Node** head, ElementType item)
{
	//申请新插入结点的空间
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = *head;	//*head表示指向头结点的指针，head表示指向头结点的指针的地址
	*head = newNode;
}

//删除单链表的头结点
void DeleteAt(Node** head)
{
	Node* p = *head;
	if (*head != NULL)
	{
		*head = (*head)->next;
		free(p);
	}
	else
	{
		printf("delete failure");
	}
}

//删除单链表中值为key的结点
void Delete(Node** head, ElementType key)
{
	Node* currPtr = *head;
	Node* prevPtr = NULL;
	if (currPtr == NULL)
	{
		return;
	}
	while (currPtr != NULL && currPtr->data != key)
	{
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	if (currPtr != NULL)
	{
		if (prevPtr == NULL)
		{
			//删除的是头结点
			*head = (*head)->next;
		}
		else
		{
			//删除的是中间结点
			DeleteAfter(prevPtr);
		}
		free(currPtr);
	}
}

//在有序单链表中插入新结点
void InsertOrder(Node** head, ElementType item)
{
	Node* currPtr, * prevPtr, * newNode;
	prevPtr = NULL;
	currPtr = *head;
	while (currPtr != NULL)
	{
		if (item < currPtr->data)
		{
			break;
		}
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	if (prevPtr == NULL)
	{
		InsertFront(head, item);
	}
	else
	{
		newNode = GetNode(item, NULL);
		InsertAfter(prevPtr, newNode);
	}
}

//删除整个单链表
void ClearList(Node** head)
{
	Node* currPtr, * nextPtr;
	currPtr = *head;
	while (currPtr != NULL)
	{
		nextPtr = currPtr->next;
		free(currPtr);
		currPtr = nextPtr;
	}
	head = NULL;
}