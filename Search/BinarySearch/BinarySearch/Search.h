//�۰����
#pragma once
#ifndef _SEARCH_H

typedef struct
{
	int key;
}T;

/// <summary>
/// �۰���ҷ�
/// </summary>
/// <param name="A">�����ҵ�����</param>
/// <param name="key">����Ŀ��Ĺؼ���</param>
/// <param name="n">���������еĸ���</param>
/// <returns></returns>
int BinarySearch(T A[], int key, int n);

#endif // !_SEARCH_H