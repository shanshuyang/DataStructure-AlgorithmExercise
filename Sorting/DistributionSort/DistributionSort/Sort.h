//分配排序，包括基数排序
#pragma once
#ifndef _SORT_H
#define _SORT_H

enum Bool
{
	FALSE,
	TRUE
};
typedef enum Bool Bool;

struct forSort
{
	int key[3];				//假设排序码有3位
	struct forSort* next;
};
typedef struct forSort ForSort;

/// <summary>
/// 初始化函数
/// </summary>
/// <param name="FS">被排序文件的单链表的指针</param>
/// <param name="a">元素的关键值</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// 基数排序
/// </summary>
/// <param name="pData">被排序文件的单链表的指针</param>
/// <param name="Clow">组成排序码的基数的下界</param>
/// <param name="Chigh">组成排序码的基数的上界</param>
/// <param name="d">排序码的最大长度</param>
void RadixSort(ForSort* pData, int Clow, int Chigh, int d);
/// <summary>
/// 打印排序结果
/// </summary>
/// <param name="FS">被排序文件的单链表的指针</param>
/// <param name="n">待排序元素个数</param>
void PrintSortResult(ForSort* FS);

#endif // !_SORT_H#pragma once
