#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ����������
void InitNode(Node* N, ElementType item, Node* ptr)
{
	N->data = item;
	N->next = ptr;
}

//����һ����������
void InsertAfter(Node* N, Node* P)
{
	P->next = N->next;	//��ǰ���ĺ�̽�����ӵ����P֮��
	N->next = P;		//�����P��Ϊ��ǰ���ĺ�̽��
}

//ɾ��һ����������
Node* DeleteAfter(Node* N)
{
	Node* ptr = N->next;	//���浱ǰ���ĺ�̽��
	if (ptr == NULL)
	{
		return NULL;		//��û�к�̽���򷵻ؿ�ָ��
	}
	N->next = ptr->next;	//��ǰ���ָ��ɾ�����ĺ�̽��
	return ptr;				//����ָ��ɾ������ָ��
}

//����һ��������Ľ��
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

//�ͷ�һ��������Ľ��
void FreeNode(Node* N)
{
	if (!N)		//���NΪ�գ��������ʾ������
	{
		printf("FreeNode: invalid node pointer!\n");
		return;
	}
	free(N);	//�ͷŽ��
}