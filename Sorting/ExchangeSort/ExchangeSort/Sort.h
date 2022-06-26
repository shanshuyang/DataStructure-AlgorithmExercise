//交换排序，包括冒泡排序和快速排序
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
/// 初始化函数
/// </summary>
/// <param name="FS">指向元素的指针</param>
/// <param name="a">元素的关键值</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// 冒泡排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void BubbleSort(ForSort A[], int n);
/// <summary>
/// 快速排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="low">待排序的序列起始位置</param>
/// <param name="high">待排序的序列结束位置</param>
void QuickSort(ForSort A[], int low, int high);
/// <summary>
/// 打印排序结果
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H#pragma once
