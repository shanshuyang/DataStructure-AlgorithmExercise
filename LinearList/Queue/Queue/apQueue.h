//���ȼ����У����������룬ɾ�������ȼ�ɾ����ʵ��
//������һ��ʵ�ַ�ʽ�������ȼ����룬����ɾ��
#pragma once
#ifndef _apQueue_H
#define _apQueue_H
#define MaxPQSize 50
#include "Event.h"
typedef Event DataType; 

struct pQueue
{
	int count;					//���ȶ���Ԫ�ظ���
	DataType pqList[MaxPQSize];	//����Ԫ�ش洢���飬DataTypeΪ�û���������ȼ�����
};
typedef struct pQueue PQueue;

/// <summary>
/// ��ʼ�����ȼ�����
/// </summary>
/// <param name="pq">���ȼ�����ָ��</param>
void InitPQueue(PQueue* pq);
/// <summary>
/// �����ȼ������в���һ��Ԫ��
/// </summary>
/// <param name="pq">���ȼ�����ָ��</param>
/// <param name="item">����Ԫ��</param>
void PQInsert(PQueue* pq, DataType item);
/// <summary>
/// ɾ�����ȼ������е�Ԫ��
/// </summary>
/// <param name="pq">���ȼ�����ָ��</param>
/// <returns>ɾ���ɹ����ر�ɾ��Ԫ�ص����ȼ������򱨴�</returns>
DataType PQDelete(PQueue* pq);
/// <summary>
/// �����ȼ������Ƿ�Ϊ��
/// </summary>
/// <param name="pq">���ȼ�����ָ��</param>
/// <returns>������ȼ�����Ϊ�շ���1�����򷵻�0</returns>
int PQEmpty(PQueue* pq);
/// <summary>
/// �����ȼ������Ƿ�Ϊ��
/// </summary>
/// <param name="pq">���ȼ�����ָ��</param>
/// <returns>������ȼ�����Ϊ������1�����򷵻�0</returns>
int PQFull(PQueue* pq);

#endif // !_apQueue_H