//并归排序，包括并归排序
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
/// 并归排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void MergeSort(ForSort A[], int n);
/// <summary>
/// 打印排序结果
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H#pragma once
