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
	//��Nodelib�еĺ���ʵ�ֵ�����Ľ����Ͳ���	
	Node* head = NULL;
	Node* currPtr;
	int i, k, key, count = 0;

	srand(time(NULL));
	for (i = 0; i < 10; i++)			//������ͷ���������10������
	{
		k = 1 + rand() % 10;
		InsertFront(&head, k);
	}

	printf("List:");					//��ʾ����
	PrintList(head, noNewline);
	printf("\n");

	printf("Enter a key: ");			//�ɼ�������һ������
	scanf_s("%d", &key);

	currPtr = head;						//ͳ��������ֵΪkey�Ľ�����
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

	//���ڵ�������ṹ�Ĳ�������ʵ�ֵ�����Ľ����Ͳ���
	LinkedList* L = (LinkedList*)malloc(sizeof(LinkedList));
	i = 0;
	k = 0;
	key = 0;
	count = 0;

	srand(time(NULL));
	InitLinkedList(L);
	for (i = 0; i < 10; i++)			//�������10����������������
	{
		k = 1 + rand() % 10;
		InsertLAfter(L, k);
	}

	printf("List:");					//��ʾ����
	k = 0;
	while (k < L->size)
	{
		SetPosition(L, k++);
		printf("%d ", GetData(L));
	}
	printf("\n");

	printf("Enter a key: ");			//�ɼ�������һ������
	scanf_s("%d", &key);
	k = 0;								//��������ͳ��������ֵΪkey�Ľ�����
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

	//��ջ��ʵ��
	LinkedStack* LS = (LinkedStack*)malloc(sizeof(LinkedStack));
	InitLinkedStack(LS);
	Push(LS, 2);
	Push(LS, 3);
	Push(LS, 5);
	printf("Pop %d\n", Pop(LS));
	printf("Pop %d\n", Pop(LS));
	printf("Pop %d\n", Pop(LS));
	printf("-------------------------------------------------------------\n");

	//�����У����ڵ�����ṹ����ʵ��
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

	//�����У����ڵ�������ṹ����ʵ��
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