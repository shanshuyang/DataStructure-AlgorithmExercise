//���ڵ�������ṹ��������---ѭ����ʽ���У�ֻ��β���ָ�룬��֤�����в��롢ɾ������ʱ�俪��ΪO(1)
#pragma once
#ifndef _CLNKQUEUE_H
#define _CLNKQUEUE_H
typedef int T;

struct LNode
{
	T data;
	struct LNode* next;
};
typedef struct LNode CLnkQueue;

/// <summary>
/// �ͷ�ѭ��������
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
void CLQ_Free(CLnkQueue* q);
/// <summary>
/// ���ѭ��������
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��ĵ�ַ</param>
void CLQ_MakeEmpty(CLnkQueue** q);
/// <summary>
/// �ж�ѭ���������Ƿ�Ϊ��
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
/// <returns>���Ϊ�շ���1�����򷵻�0</returns>
int CLQ_IsEmpty(CLnkQueue* q);
/// <summary>
/// ��ѭ�������еĳ���
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
/// <returns>����ѭ�������еĳ���</returns>
int CLQ_Length(CLnkQueue* q);
/// <summary>
/// ����У��½�����������β��
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
/// <param name="x">�������Ԫ��</param>
void CLQ_In(CLnkQueue** q, T x);
/// <summary>
/// �����У�ɾ��������ͷ����Ԫ��
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��ĵ�ַ</param>
/// <returns>���ر�ɾ���Ľ�������</returns>
T CLQ_Out(CLnkQueue** q);
/// <summary>
/// ��ȡ����ͷ������
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
/// <returns>���ض���ͷ��������</returns>
T CLQ_Head(CLnkQueue* q);
/// <summary>
/// ��ӡ���е����н��
/// </summary>
/// <param name="q">ָ��ѭ��������β����ָ��</param>
void CLQ_Print(CLnkQueue* q);

#endif // !_CLNKQUEUE_H