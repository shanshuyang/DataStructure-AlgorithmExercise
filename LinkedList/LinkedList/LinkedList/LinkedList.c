#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//初始化单链表
void InitLinkedList(LinkedList* L)
{
	L->front = NULL;
	L->rear = NULL;
	L->prevPtr = NULL;
	L->currPtr = NULL;
	L->size = 0;
	L->position = -1;
}

//判断表是否为空
Bool IsEmpty(LinkedList* L)
{
	return L->size ? FALSE : TRUE;
}

//求当前结点的后继结点的位置
int NextLNode(LinkedList* L)
{
	if (L->position >= 0 && L->position < L->size)
	{
		//若当前结点存在，则将其后继结点设置为当前结点
		L->position++;
		L->prevPtr = L->currPtr;
		L->currPtr = (L->currPtr)->next;
	}
	else
	{
		//否则将当前位置设为表尾后
		L->position = L->size;
	}
	return L->position; //返回新位置
}

//重定位链表的当前结点
int SetPosition(LinkedList* L, int pos)
{
	if (!L->size)
	{
		//链表为空则返回-1
		return -1;
	}
	if (pos<0 || pos>L->size - 1)
	{
		//位置越界则返回-1
		printf("position error");
		return -1;
	}
	//寻找对应的结点
	L->currPtr = L->front;
	L->prevPtr = NULL;
	L->position = 0;
	for (int k = 0; k < pos; k++)
	{
		L->position++;
		L->prevPtr = L->currPtr;
		L->currPtr = (L->currPtr)->next;
	}

	return L->position;
}

//在当前结点处插入结点，插入后当前结点指针指向新插入的结点
void InsertLAt(LinkedList* L, ElementType item)
{
	Node* newNode;
	if (!L->size)
	{
		//在空表中插入
		newNode = GetNode(item, L->front);
		L->front = L->rear = newNode;
		L->position = 0;
	}
	else if (!L->prevPtr)
	{
		//在表头结点处插入
		newNode = GetNode(item, L->front);
		L->front = newNode;
	}
	else
	{
		//在表的中间位置插入
		newNode = GetNode(item, L->currPtr);
		InsertAfter(L->prevPtr, newNode);
	}
	L->size++;				//增加链表的大小
	L->currPtr = newNode;	//新插入的结点为当前结点
}

//在当前结点后插入结点，插入后当前结点指针指向新插入的结点
void InsertLAfter(LinkedList* L, ElementType item)
{
	Node* newNode;
	if (!L->size)
	{
		//在空表中插入
		newNode = GetNode(item, NULL);
		L->front = L->rear = newNode;
		L->position = 0;
	}
	else if (L->currPtr == L->rear || !L->currPtr)
	{
		//在表尾结点后插入
		newNode = GetNode(item, NULL);
		InsertAfter(L->rear, newNode);
		L->prevPtr = L->rear;
		L->rear = newNode;
		L->position = L->size;
	}
	else
	{
		//在链表的中间位置插入
		newNode = GetNode(item, (L->currPtr)->next);
		InsertAfter(L->currPtr, newNode);
		L->prevPtr = L->currPtr;
		L->position++;
	}
	L->size++;				//增加链表的大小
	L->currPtr = newNode;	//新插入的结点为当前结点
}

//删除当前结点，删除后当前结点指针指向被删除结点的后继结点
void DeleteLAt(LinkedList* L)
{
	Node* oldNode;
	if (!L->currPtr)
	{
		//若表为空或已到表尾之后，则给出错误提示并返回
		printf("DeleteAt: current position is invalid!\n");
		return;
	}
	if (!L->prevPtr)
	{
		//删除的是表头结点
		oldNode = L->front;
		L->front = (L->currPtr)->next;
	}
	else
	{
		//删除的是表中结点
		oldNode = DeleteAfter(L->prevPtr);
	}
	if (oldNode == L->rear)
	{
		//删除的是表尾结点，则修改表尾指针
		L->rear = L->prevPtr;
	}
	L->currPtr = oldNode->next;		//后继结点作为新的当前结点
	FreeNode(oldNode);				//释放原当前结点
	L->size--;						//链表大小减1
}

//删除当前结点的后继结点，当前结点指针指向不变
void DeleteLAfter(LinkedList* L)
{
	Node* oldNode;
	if (!L->currPtr || L->currPtr == L->rear)
	{
		//若表为空或已到表尾，则给出错误提示并返回
		printf("DeleteLAfter: current position is invalid!\n");
		return;
	}
	oldNode = DeleteAfter(L->currPtr);	//保存被删除结点的指针并从链表中删除该结点
	if (oldNode == L->rear)
	{
		//删除的是表尾结点，则修改表尾指针
		L->rear = L->currPtr;
	}
	FreeNode(oldNode);	//释放原当前结点
	L->size--;			//链表大小减
}

//获取链表中当前结点的数据
ElementType GetData(LinkedList* L)
{
	if (!L->size || !L->currPtr)
	{
		//若表为空或已经到达表尾之后，则出错
		printf("Data: current node does not exist!\n");
		exit(1);
	}
	return L->currPtr->data;
}

//修改链表中当前结点的数据
void SetData(LinkedList* L, ElementType item)
{
	if (!L->size || !L->currPtr)
	{
		//若表为空或已经到达表尾之后，则出错
		printf("Data: current node does not exist!\n");
		exit(1);
	}
	L->currPtr->data = item;
}

//清空链表
void Clear(LinkedList* L)
{
	Node* currNode = L->front;
	Node* nextNode;
	while (currNode)
	{
		nextNode = currNode->next;
		FreeNode(currNode);
		currNode = nextNode;
	}
	L->front = L->rear = L->currPtr = L->prevPtr = NULL;
	L->size = 0;
	L->position = -1;
}