#include "apQueue.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ�����ȼ�����
void InitPQueue(PQueue* pq)
{
	pq->count = 0;
}

///�����ȼ������в���һ��Ԫ��
void PQInsert(PQueue* pq, DataType item)
{
	if (pq->count == MaxPQSize)
	{
		printf("Priority queue overflow!\n");
		exit(1);
	}
	else
	{
		pq->pqList[pq->count] = item;
		pq->count++;
	}
}

//ɾ�����ȼ������е�Ԫ��
DataType PQDelete(PQueue* pq)
{
	DataType min;
	int i, minindex = 0;
	
	if (pq->count > 0)
	{
		min = pq->pqList[0];
		for (i = 0; i < pq->count; i++)					//Ѱ�Ҷ��������ȼ���ߵ�Ԫ��
		{
			if (pq->pqList[i].time < min.time)
			{
				min = pq->pqList[i];
				minindex = i;
			}
		}
		pq->pqList[minindex] = pq->pqList[pq->count - 1];	//����β��Ԫ�ػ���minindex��λ��
		pq->count--;										//����Ԫ�ظ�����1
	}
	else
	{
		printf("Deleting from an empty priority queue!\n");
		exit(1);
	}
	return min;
}

//�����ȼ������Ƿ�Ϊ��
int PQEmpty(PQueue* pq)
{
	return pq->count == 0;
}

//�����ȼ������Ƿ�Ϊ��
int PQFull(PQueue* pq)
{
	return pq->count == MaxPQSize;
}