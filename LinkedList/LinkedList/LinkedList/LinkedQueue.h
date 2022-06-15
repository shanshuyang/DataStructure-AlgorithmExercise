//�õ�����ṹ�洢����---������
#pragma once
#ifndef _LINKEDQUEUE_H
#define _LINKEDQUEUE_H
#include "LinkedList.h"

struct linkedQueue
{
	LinkedList* queue;
};
typedef struct linkedQueue LinkedQueue;

/// <summary>
/// ��ʼ��������
/// </summary>
/// <param name="LQ">ָ�������е�ָ��</param>
void InitLinkedQueue(LinkedQueue* LQ);
/// <summary>
/// �����в���һ��������Ԫ��
/// </summary>
/// <param name="LQ"ָ�������е�ָ��></param>
/// <param name="item">�������Ԫ��</param>
void InQueue(LinkedQueue* LQ, ElementType item);
/// <summary>
/// ������ɾ��һ��Ԫ��
/// </summary>
/// <param name="LQ">ָ�������е�ָ��</param>
/// <returns>���ر�ɾ����Ԫ��</returns>
ElementType OutQueue(LinkedQueue* LQ);
/// <summary>
/// ȡ���е�ͷ��Ԫ��
/// </summary>
/// <param name="LQ">ָ�������е�ָ��</param>
/// <returns>���ض���ͷ����Ԫ��</returns>
ElementType FrontQueue(LinkedQueue* LQ);
/// <summary>
/// ��������е�����Ԫ��
/// </summary>
/// <param name="LQ">ָ�������е�ָ��</param>
void ClearLQ(LinkedQueue* LQ);
/// <summary>
/// �ж϶����Ƿ�Ϊ��
/// </summary>
/// <param name="LQ">ָ�������е�ָ��</param>
/// <returns>���������Ϊ�շ���TRUE�����򷵻�FALSE</returns>
Bool IsEmptyLQ(LinkedQueue* LQ);

#endif // !_LINKEDQUEUE_H
