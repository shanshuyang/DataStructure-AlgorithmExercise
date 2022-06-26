//顺序查找
#pragma once
#ifndef _SEARCH_H

typedef struct
{
	int key;
}T;

/// <summary>
/// 顺序查找法
/// </summary>
/// <param name="A">待查找的序列</param>
/// <param name="key">查找目标的关键码</param>
/// <param name="n">待查找序列的个数</param>
/// <returns></returns>
int SeqSearch(T A[], int key, int n);

#endif // !_SEARCH_H