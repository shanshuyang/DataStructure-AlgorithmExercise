//������ṹ
#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "Node.h"

enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;

struct linkedList
{
	Node* front, * rear;		//ָ���ͷ�ͱ�β��ָ��
	Node* prevPtr, * currPtr;	//���ڷ������ݡ������ɾ������ָ��
	int size;					//���еĽ����
	int position;				//���е�ǰ���λ�ü���
};
typedef struct linkedList LinkedList;

/// <summary>
/// ��ʼ��������
/// </summary>
/// <param name="L">ָ�������ָ��</param>
void InitLinkedList(LinkedList* L);
/// <summary>
/// �жϱ��Ƿ�Ϊ��
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <returns>���Ϊ�շ���TRUE�����򷵻�FALSE</returns>
Bool IsEmpty(LinkedList* L);
/// <summary>
/// ��ǰ���ĺ�̽���λ��
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <returns>���غ�̽���λ��</returns>
int NextLNode(LinkedList* L);
/// <summary>
/// �ض�λ����ĵ�ǰ���
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <param name="pos">�ض�λ��λ��</param>
/// <returns>���ص�ǰ����λ��</returns>
int SetPosition(LinkedList* L, int pos);
/// <summary>
/// �ڵ�ǰ��㴦�����㣬�����ǰ���ָ��ָ���²���Ľ��
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <param name="item">�������Ԫ��</param>
void InsertLAt(LinkedList* L, ElementType item);
/// <summary>
/// �ڵ�ǰ��������㣬�����ǰ���ָ��ָ���²���Ľ��
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <param name="item">�������Ԫ��</param>
void InsertLAfter(LinkedList* L, ElementType item);
/// <summary>
/// ɾ����ǰ��㣬ɾ����ǰ���ָ��ָ��ɾ�����ĺ�̽��
/// </summary>
/// <param name="L">ָ�������ָ��</param>
void DeleteLAt(LinkedList* L);
/// <summary>
/// ɾ����ǰ���ĺ�̽�㣬��ǰ���ָ��ָ�򲻱�
/// </summary>
/// <param name="L">ָ�������ָ��</param>
void DeleteLAfter(LinkedList* L);
/// <summary>
/// ��ȡ�����е�ǰ��������
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <returns>���������е�ǰ��������</returns>
ElementType GetData(LinkedList* L);
/// <summary>
/// �޸������е�ǰ��������
/// </summary>
/// <param name="L">ָ�������ָ��</param>
/// <param name="item">�޸ĺ��Ŀ������</param>
void SetData(LinkedList* L, ElementType item);
/// <summary>
/// �������
/// </summary>
/// <param name="L">ָ�������ָ��</param>
void Clear(LinkedList* L);

#endif // !_LINKEDLIST_H


