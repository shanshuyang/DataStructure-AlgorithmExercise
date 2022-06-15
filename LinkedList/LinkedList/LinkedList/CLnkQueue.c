#include "CLnkQueue.h"
#include <stdio.h>
#include <stdlib.h>

//释放循环链队列
void CLQ_Free(CLnkQueue* q)
{
	CLQ_MakeEmpty(&q);
}

//清空循环链队列
void CLQ_MakeEmpty(CLnkQueue** q)
{
	if (*q == NULL)
	{
		return;
	}
	struct LNode* nodel = *q;
	struct LNode* node = nodel->next;
	free(nodel);
	while (node != *q)
	{
		struct LNode* next = node->next;
		free(node);
		node = next;
	}
	*q = NULL;
}

//判断循环链队列是否为空
int CLQ_IsEmpty(CLnkQueue* q)
{
	return q == NULL;
}

//求循环链队列的长度
int CLQ_Length(CLnkQueue* q)
{
	if (q == NULL)
	{
		return 0;
	}
	int count = 1;
	struct LNode* node = q->next;
	while (node != q)
	{
		count++;
		node = node->next;
	}
	return count;
}

//入队列，新结点加入链队列尾部
void CLQ_In(CLnkQueue** q, T x)
{
	struct LNode* node = (struct LNode*)malloc(sizeof(struct LNode));
	node->data = x;
	if (*q == NULL)
	{
		node->next = node;
	}
	else
	{
		node->next = (*q)->next;
		(*q)->next = node;
	}
	*q = node;
}

//出队列，删除链队列头部的元素
T CLQ_Out(CLnkQueue** q)
{
	if (*q)
	{
		struct LNode* head = (*q)->next;
		T x = head->data;
		if (head == *q)
		{
			*q = NULL;
		}
		else
		{
			(*q)->next = head->next;
		}
		free(head);
		return x;
	}
	else
	{
		printf("CLQ_Out: queue empty\n");
		exit(1);
	}
}

//获取队列头的数据
T CLQ_Head(CLnkQueue* q)
{
	if (q)
	{
		return q->next->data;
	}
	else
	{
		printf("CLQ_Head: queue empty\n");
		exit(1);
	}
}

//打印队列的所有结点
void CLQ_Print(CLnkQueue* q)
{
	if (q == NULL)
	{
		printf("The queue is empty.\n");
		return;
	}
	printf("The queue is: ");
	struct LNode* node = q;
	do
	{
		node = node->next;
		printf("%d ", node->data);
	} while (node != q);
	printf("\n");
}