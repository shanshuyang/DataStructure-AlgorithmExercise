//˳�����
#pragma once
#ifndef _SEARCH_H

typedef struct
{
	int key;
}T;

/// <summary>
/// ˳����ҷ�
/// </summary>
/// <param name="A">�����ҵ�����</param>
/// <param name="key">����Ŀ��Ĺؼ���</param>
/// <param name="n">���������еĸ���</param>
/// <returns></returns>
int SeqSearch(T A[], int key, int n);

#endif // !_SEARCH_H