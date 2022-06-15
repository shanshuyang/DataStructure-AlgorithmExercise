//������ڵ�ṹ�⣬ʵ�ֵ�����Ľ��������
#pragma once
#ifndef _NODE_LIBRARY_H
#define _NODE_LIBRARY_H
#include "Node.h"

enum  appendNewline
{
	noNewline,
	addNewline
};
typedef enum appendNewline AppendNewline;

/// <summary>
/// ��ӡ����
/// </summary>
/// <param name="head">����ͷָ��</param>
/// <param name="addnl">ָ�����ÿһ�������Ƿ���</param>
void PrintList(Node* head, AppendNewline addnl);
/// <summary>
/// �������л��ڱ�Ŀ�Ĳ���
/// </summary>
/// <param name="head">����ͷָ��</param>
/// <param name="item">�����ҵ�Ԫ��</param>
/// <returns>���ҳɹ�����1�����򷵻�0</returns>
int Find(Node* head, ElementType item);
/// <summary>
/// �ڵ������ͷ������һ���µĵ�������
/// </summary>
/// <param name="head">ָ��ָ��ͷ���ָ���ָ�룬��ָ��ͷ����ָ��ĵ�ַ</param>
/// <param name="item">�����������</param>
void InsertFront(Node** head, ElementType item);
/// <summary>
/// ɾ���������ͷ���
/// </summary>
/// <param name="head">ָ��ָ��ͷ���ָ���ָ�룬��ָ��ͷ����ָ��ĵ�ַ</param>
void DeleteAt(Node** head);
/// <summary>
/// ɾ����������ֵΪkey�Ľ��
/// </summary>
/// <param name="head">ָ��ָ��ͷ���ָ���ָ�룬��ָ��ͷ����ָ��ĵ�ַ</param>
/// <param name="key">ɾ��Ŀ����Ĺؼ�ֵ</param>
void Delete(Node** head, ElementType key);
/// <summary>
/// �����������в����½��
/// </summary>
/// <param name="head">ָ��ָ��ͷ���ָ���ָ�룬��ָ��ͷ����ָ��ĵ�ַ</param>
/// <param name="item">�����������</param>
void InsertOrder(Node** head, ElementType item);
/// <summary>
/// ɾ������������
/// </summary>
/// <param name="head"></param>
void ClearList(Node** head);
#endif // !_NODE_LIBRARY_H