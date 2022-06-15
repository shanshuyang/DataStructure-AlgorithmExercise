#include "Node.h"
#include "Nodelib.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "CLnkQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//用Nodelib中的函数实现单链表的建立和查找	
	Node* head = NULL;
	Node* currPtr;
	int i, k, key, count = 0;

	srand(time(NULL));
	for (i = 0; i < 10; i++)			//从链表头部随机插入10个整数
	{
		k = 1 + rand() % 10;
		InsertFront(&head, k);
	}

	printf("List:");					//显示链表
	PrintList(head, noNewline);
	printf("\n");

	printf("Enter a key: ");			//由键盘输入一个整数
	scanf_s("%d", &key);

	currPtr = head;						//统计链表中值为key的结点个数
	while (currPtr != NULL)				
	{
		if (currPtr->data == key)
		{
			count++;
		}
		currPtr = currPtr->next;
	}
	printf("The data value %d occurs %d times in the list\n", key, count);
	printf("-------------------------------------------------------------\n");

	//基于单链表结点结构的操作方法实现单链表的建立和查找
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	i = 0;
	k = 0;
	key = 0;
	count = 0;

	srand(time(NULL));
	InitLinkedList(L);
	for (i = 0; i < 10; i++)			//随机插入10个整数到单链表中
	{
		k = 1 + rand() % 10;
		InsertLAfter(L, k);
	}

	printf("List:");					//显示链表
	k = 0;
	while (k < L->size)
	{
		SetPosition(L, k++);
		printf("%d ", GetData(L));
	}
	printf("\n");

	printf("Enter a key: ");			//由键盘输入一个整数
	scanf_s("%d", &key);
	k = 0;								//遍历链表，统计链表中值为key的结点个数
	while (k < L->size)
	{
		SetPosition(L, k++);
		if (GetData(L)==key)
		{
			count++;
		}
	}
	printf("The data value %d occurs %d times in the list\n", key, count);
	printf("-------------------------------------------------------------\n");

	//链栈的实例
	LinkedStack* LS = (LinkedStack*)malloc(sizeof(LinkedStack));
	InitLinkedStack(LS);
	Push(LS, 2);
	Push(LS, 3);
	Push(LS, 5);
	printf("Pop %d\n", Pop(LS));
	printf("Pop %d\n", Pop(LS));
	printf("Pop %d\n", Pop(LS));
	printf("-------------------------------------------------------------\n");

	//链队列（基于单链表结构）的实例
	LinkedQueue* LQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	InitLinkedQueue(LQ);
	InQueue(LQ, 2);
	InQueue(LQ, 3);
	InQueue(LQ, 5);
	OutQueue(LQ);
	OutQueue(LQ);
	printf("The top is %d\n", FrontQueue(LQ));
	ClearLQ(LQ);
	if (IsEmptyLQ(LQ))
	{
		printf("Linkedqueue is empty\n");
	}
	printf("-------------------------------------------------------------\n");

	//链队列（基于单链表结点结构）的实例
	CLnkQueue* q = NULL;
	CLQ_In(&q, 2);
	CLQ_In(&q, 3);
	CLQ_In(&q, 5);
	CLQ_In(&q, 8);
	printf("The lehgth of the queue is %d\n", CLQ_Length(q));
	printf("The queue: ");
	CLQ_Print(q);
	CLQ_Out(&q);
	CLQ_Out(&q);
	printf("The head of the queue is %d\n", CLQ_Head(q));
	if (!CLQ_IsEmpty(q))
	{
		CLQ_Free(q);
		printf("Now the queue is empty\n");
	}
	printf("-------------------------------------------------------------\n");


	return 0;
}