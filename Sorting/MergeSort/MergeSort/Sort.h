//�������򣬰�����������
#pragma once
#ifndef _SORT_H
#define _SORT_H

typedef int ElementType;

enum Bool
{
	FALSE,
	TRUE
};
typedef enum Bool Bool;

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
/// ��������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void MergeSort(ForSort A[], int n);
/// <summary>
/// ��ӡ������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H#pragma once
