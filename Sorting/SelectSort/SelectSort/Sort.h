//ѡ�����򣬰���ֱ��ѡ�����������ѡ������
#pragma once
#ifndef _SORT_H
#define _SORT_H
#define MAX_VALUE 500;

typedef int ElementType;

struct forSort
{
	ElementType key;
};
typedef struct forSort ForSort;

struct treeNode
{
	ElementType key;
	int index;
};
typedef struct treeNode TreeNode;

/// <summary>
/// ��ʼ������
/// </summary>
/// <param name="FS">ָ��Ԫ�ص�ָ��</param>
/// <param name="a">Ԫ�صĹؼ�ֵ</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// ֱ��ѡ������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void DirectSelectSort(ForSort A[], int n);
/// <summary>
/// ����ѡ������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void TreeSelectSort(ForSort A[], int n);
/// <summary>
/// ��ӡ������
/// </summary>
/// <param name="A">�����������</param>
/// <param name="n">������Ԫ�ظ���</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H