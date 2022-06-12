//ѭ������
#pragma once
#ifndef _Queue_H
#define _Queue_H
enum boolean
{
	FALSE,
	TRUE
};
typedef enum boolean Bool;
typedef int ElementType;

struct queue
{
	int rear;						//��βָ�룬ָ����һ����ӵ�λ��
	int front;						//����ָ��
	ElementType* elements;			//��Ŷ���Ԫ�ص�����
	int MaxSize;					//���пռ�����ߴ�
};
typedef struct queue Queue;

/// <summary>
/// �������пռ䣬����һ���ն���
/// </summary>
/// <param name="Q">����ָ��</param>
/// <param name="sz">���пռ��С</param>
void InitQueue(Queue* Q, int sz);	
/// <summary>
/// ���пռ��ͷ�
/// </summary>
/// <param name="Q">����ָ��</param>
void FreeQueue(Queue* Q);	
/// <summary>
/// �����ÿ�
/// </summary>
/// <param name="Q">����ָ��</param>
void MakeEmpty(Queue* Q);	
/// <summary>
/// �ж����Ƿ�Ϊ��
/// </summary>
/// <param name="Q">����ָ��</param>
/// <returns>�������Ϊ�շ���TRUE�����򷵻�FALSE</returns>
Bool IsEmpty(Queue* Q);				
/// <summary>
/// �ж����Ƿ�Ϊ��
/// </summary>
/// <param name="Q">����ָ��</param>
/// <returns>�������Ϊ������TRUE�����򷵻�FALSE</returns>
Bool IsFull(Queue* Q);
/// <summary>
/// ����е�Ԫ�ظ���
/// </summary>
/// <param name="Q">����ָ��</param>
/// <returns>���ص�ǰ������Ԫ�صĸ���</returns>
int Length(Queue* Q);					
/// <summary>
/// ������δ��������뷵��0�����򷵻�-1
/// </summary>
/// <param name="Q">����ָ��</param>
/// <param name="item">�����</param>
/// <returns>��ӳɹ�����0�����򷵻�-1</returns>
int EnQueue(Queue* Q, ElementType item);
/// <summary>
/// �����зǿգ�����ӣ����ض��׵�ֵ�����򱨴�
/// </summary>
/// <param name="Q">����ָ��</param>
/// <returns>���ӳɹ����س���Ԫ�ص�ֵ�����򱨴�</returns>
ElementType DeQueue(Queue* Q);		
/// <summary>
/// �����зǿգ��򷵻ض���Ԫ�ص�ֵ�����򱨴�
/// </summary>
/// <param name="Q">����ָ��</param>
/// <returns>���зǿգ��򷵻ض���Ԫ�ص�ֵ�����򱨴�</returns>
ElementType GetFront(Queue* Q);		

#endif // !_Queue_H