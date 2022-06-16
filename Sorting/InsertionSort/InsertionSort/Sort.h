//�������򣬰���ֱ�Ӳ��������۰���������Shell����
#pragma once
#ifndef _SORT_H
#define _SORT_H

typedef int ElementType;

struct forSort
{
	ElementType key;
};
typedef struct forSort ForSort;

/// <summary>
/// ��ʼ������
/// </summary>
/// <param name="FS">ָ��Ԫ�ص�ָ��</param>
/// <param name="a">Ԫ�صĹؼ�ֵ</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// ֱ�Ӳ�������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void DirectInsertionSort(ForSort A[], int n);
/// <summary>
/// �۰��������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void BinaryInsertionSort(ForSort A[], int n);
/// <summary>
/// Shell����
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
/// <param name="s">��һ�������������</param>
void ShellSort(ForSort A[], int n, int s);
/// <summary>
/// ��ӡ������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H


