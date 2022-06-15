//������ڵ�ṹ
#pragma once
#ifndef _NODE_H
#define _NODE_H
typedef int ElementType;

struct node
{
	struct node* next; //ָ����һ������ָ��
	ElementType data;
};
typedef struct node Node;

/// <summary>
/// ��ʼ����������
/// </summary>
/// <param name="N">ָ�����ʼ������ָ��</param>
/// <param name="item">����ʼ�����洢������</param>
/// <param name="ptr">ָ����һ������ָ��</param>
void InitNode(Node* N, ElementType item, Node* ptr);
/// <summary>
/// ����һ����������
/// </summary>
/// <param name="N">�������λ��</param>
/// <param name="P">������Ľ��</param>
void InsertAfter(Node* N, Node* P);
/// <summary>
/// ɾ��һ����������
/// </summary>
/// <param name="N">��ɾ���Ľ��</param>
/// <returns>����ָ��ɾ������ָ��</returns>
Node* DeleteAfter(Node*N);
/// <summary>
/// ����һ��������Ľ��
/// </summary>
/// <param name="item">�ýڵ�洢������</param>
/// <param name="ptr">ָ����һ������ָ��</param>
/// <returns>�����½�����ָ��</returns>
Node* GetNode(ElementType item, Node* ptr);
/// <summary>
/// �ͷ�һ��������Ľ��
/// </summary>
/// <param name="N">���ͷŵĽ��</param>
void FreeNode(Node* N);
#endif // !_NODE_H
