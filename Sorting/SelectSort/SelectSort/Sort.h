//选择排序，包括直接选择排序和树形选择排序
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
/// 初始化函数
/// </summary>
/// <param name="FS">指向元素的指针</param>
/// <param name="a">元素的关键值</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// 直接选择排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void DirectSelectSort(ForSort A[], int n);
/// <summary>
/// 树形选择排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void TreeSelectSort(ForSort A[], int n);
/// <summary>
/// 打印排序结果
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H