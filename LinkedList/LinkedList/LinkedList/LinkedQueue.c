#include "LinkedQueue.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ��������
void InitLinkedQueue(LinkedQueue* LQ)
{
	LQ->queue = (LinkedList*)malloc(sizeof(LinkedList));
	InitLinkedList(LQ->queue);
}

//�����в���һ��������Ԫ��
void InQueue(LinkedQueue* LQ, ElementType item)
{
	SetPosition(LQ->queue, (LQ->queue)->size - 1);	//���ö�βԪ��Ϊ��ǰ���
	InsertLAfter(LQ->queue, item);					//�ڶ�β��������½��
}

//������ɾ��һ��Ԫ��
ElementType OutQueue(LinkedQueue* LQ)
{
	ElementType tmpData;
	if (!(LQ->queue)->size)							//������Ϊ�գ���ʾ������Ϣ
	{
		printf("OutQueue: underflowed!\n");
		exit(1);
	}

	SetPosition(LQ->queue, 0);						//��ǰ���λ���Ƶ�����ͷ
	tmpData = GetData(LQ->queue);					//�������ͷ��������
	DeleteLAt(LQ->queue);							//ɾ������ͷ���
	return tmpData;									//���ر�ɾ���Ķ���ͷ����
}

//ȡ���е�ͷ��Ԫ��
ElementType FrontQueue(LinkedQueue* LQ)
{
	if (!(LQ->queue)->size)							//������Ϊ�գ���ʾ������Ϣ
	{
		printf("FrontQueue: underflowed!\n");
		exit(1);
	}

	SetPosition(LQ->queue, 0);						//��ǰ���λ���Ƶ�����ͷ
	return GetData(LQ->queue);						//���ض���ͷ����
}

//��������е�����Ԫ��
void ClearLQ(LinkedQueue* LQ)
{
	Clear(LQ->queue);
}

//�ж϶����Ƿ�Ϊ��
Bool IsEmptyLQ(LinkedQueue* LQ)
{
	return LQ->queue->size ? FALSE : TRUE;
}
