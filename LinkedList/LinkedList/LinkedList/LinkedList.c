#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��������
void InitLinkedList(LinkedList* L)
{
	L->front = NULL;
	L->rear = NULL;
	L->prevPtr = NULL;
	L->currPtr = NULL;
	L->size = 0;
	L->position = -1;
}

//�жϱ��Ƿ�Ϊ��
Bool IsEmpty(LinkedList* L)
{
	return L->size ? FALSE : TRUE;
}

//��ǰ���ĺ�̽���λ��
int NextLNode(LinkedList* L)
{
	if (L->position >= 0 && L->position < L->size)
	{
		//����ǰ�����ڣ������̽������Ϊ��ǰ���
		L->position++;
		L->prevPtr = L->currPtr;
		L->currPtr = (L->currPtr)->next;
	}
	else
	{
		//���򽫵�ǰλ����Ϊ��β��
		L->position = L->size;
	}
	return L->position; //������λ��
}

//�ض�λ����ĵ�ǰ���
int SetPosition(LinkedList* L, int pos)
{
	if (!L->size)
	{
		//����Ϊ���򷵻�-1
		return -1;
	}
	if (pos<0 || pos>L->size - 1)
	{
		//λ��Խ���򷵻�-1
		printf("position error");
		return -1;
	}
	//Ѱ�Ҷ�Ӧ�Ľ��
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

//�ڵ�ǰ��㴦�����㣬�����ǰ���ָ��ָ���²���Ľ��
void InsertLAt(LinkedList* L, ElementType item)
{
	Node* newNode;
	if (!L->size)
	{
		//�ڿձ��в���
		newNode = GetNode(item, L->front);
		L->front = L->rear = newNode;
		L->position = 0;
	}
	else if (!L->prevPtr)
	{
		//�ڱ�ͷ��㴦����
		newNode = GetNode(item, L->front);
		L->front = newNode;
	}
	else
	{
		//�ڱ���м�λ�ò���
		newNode = GetNode(item, L->currPtr);
		InsertAfter(L->prevPtr, newNode);
	}
	L->size++;				//��������Ĵ�С
	L->currPtr = newNode;	//�²���Ľ��Ϊ��ǰ���
}

//�ڵ�ǰ��������㣬�����ǰ���ָ��ָ���²���Ľ��
void InsertLAfter(LinkedList* L, ElementType item)
{
	Node* newNode;
	if (!L->size)
	{
		//�ڿձ��в���
		newNode = GetNode(item, NULL);
		L->front = L->rear = newNode;
		L->position = 0;
	}
	else if (L->currPtr == L->rear || !L->currPtr)
	{
		//�ڱ�β�������
		newNode = GetNode(item, NULL);
		InsertAfter(L->rear, newNode);
		L->prevPtr = L->rear;
		L->rear = newNode;
		L->position = L->size;
	}
	else
	{
		//��������м�λ�ò���
		newNode = GetNode(item, (L->currPtr)->next);
		InsertAfter(L->currPtr, newNode);
		L->prevPtr = L->currPtr;
		L->position++;
	}
	L->size++;				//��������Ĵ�С
	L->currPtr = newNode;	//�²���Ľ��Ϊ��ǰ���
}

//ɾ����ǰ��㣬ɾ����ǰ���ָ��ָ��ɾ�����ĺ�̽��
void DeleteLAt(LinkedList* L)
{
	Node* oldNode;
	if (!L->currPtr)
	{
		//����Ϊ�ջ��ѵ���β֮�������������ʾ������
		printf("DeleteAt: current position is invalid!\n");
		return;
	}
	if (!L->prevPtr)
	{
		//ɾ�����Ǳ�ͷ���
		oldNode = L->front;
		L->front = (L->currPtr)->next;
	}
	else
	{
		//ɾ�����Ǳ��н��
		oldNode = DeleteAfter(L->prevPtr);
	}
	if (oldNode == L->rear)
	{
		//ɾ�����Ǳ�β��㣬���޸ı�βָ��
		L->rear = L->prevPtr;
	}
	L->currPtr = oldNode->next;		//��̽����Ϊ�µĵ�ǰ���
	FreeNode(oldNode);				//�ͷ�ԭ��ǰ���
	L->size--;						//�����С��1
}

//ɾ����ǰ���ĺ�̽�㣬��ǰ���ָ��ָ�򲻱�
void DeleteLAfter(LinkedList* L)
{
	Node* oldNode;
	if (!L->currPtr || L->currPtr == L->rear)
	{
		//����Ϊ�ջ��ѵ���β�������������ʾ������
		printf("DeleteLAfter: current position is invalid!\n");
		return;
	}
	oldNode = DeleteAfter(L->currPtr);	//���汻ɾ������ָ�벢��������ɾ���ý��
	if (oldNode == L->rear)
	{
		//ɾ�����Ǳ�β��㣬���޸ı�βָ��
		L->rear = L->currPtr;
	}
	FreeNode(oldNode);	//�ͷ�ԭ��ǰ���
	L->size--;			//�����С��
}

//��ȡ�����е�ǰ��������
ElementType GetData(LinkedList* L)
{
	if (!L->size || !L->currPtr)
	{
		//����Ϊ�ջ��Ѿ������β֮�������
		printf("Data: current node does not exist!\n");
		exit(1);
	}
	return L->currPtr->data;
}

//�޸������е�ǰ��������
void SetData(LinkedList* L, ElementType item)
{
	if (!L->size || !L->currPtr)
	{
		//����Ϊ�ջ��Ѿ������β֮�������
		printf("Data: current node does not exist!\n");
		exit(1);
	}
	L->currPtr->data = item;
}

//�������
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