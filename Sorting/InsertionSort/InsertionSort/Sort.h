//插入排序，包括直接插入排序、折半插入排序和Shell排序
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
/// 初始化函数
/// </summary>
/// <param name="FS">指向元素的指针</param>
/// <param name="a">元素的关键值</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// 直接插入排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void DirectInsertionSort(ForSort A[], int n);
/// <summary>
/// 折半插入排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void BinaryInsertionSort(ForSort A[], int n);
/// <summary>
/// Shell排序
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
/// <param name="s">第一次排序分组组数</param>
void ShellSort(ForSort A[], int n, int s);
/// <summary>
/// 打印排序结果
/// </summary>
/// <param name="A">待排序的序列</param>
/// <param name="n">待排序元素个数</param>
void PrintSortResult(ForSort A[], int n);

#endif // !_SORT_H


