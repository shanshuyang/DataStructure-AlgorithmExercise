#include "Nodelib.h"
#include <stdio.h>
#include <stdlib.h>

//��ӡ����
void PrintList(Node* head, AppendNewline addnl)
{
	Node* currPtr = head;
	//��ӡ��ǰ�������ֱ����β
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

//�������л��ڱ�Ŀ�Ĳ���
int Find(Node* head, ElementType item)
{
	Node* currPtr = head;
	Node* prevPtr = NULL;
	while (currPtr != NULL)
	{
		if (currPtr->data == item)	//�Ƚ��������������
		{
			return 1;	//���ҳɹ�
		}
		prevPtr = currPtr;
		currPtr = currPtr->next;
	}
	return 0;	//����ʧ��
}

//�ڵ������ͷ������һ���µĵ�������
void InsertFront(Node** head, ElementType item)
{
	//�����²�����Ŀռ�
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = *head;	//*head��ʾָ��ͷ����ָ�룬head��ʾָ��ͷ����ָ��ĵ�ַ
	*head = newNode;
}

//ɾ���������ͷ���
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

//ɾ����������ֵΪkey�Ľ��
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
			//ɾ������ͷ���
			*head = (*head)->next;
		}
		else
		{
			//ɾ�������м���
			DeleteAfter(prevPtr);
		}
		free(currPtr);
	}
}

//�����������в����½��
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

//ɾ������������
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