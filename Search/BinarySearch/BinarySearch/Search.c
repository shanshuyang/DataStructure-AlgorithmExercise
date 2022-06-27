#include "Search.h"
#include <stdio.h>
#include <stdlib.h>

//�۰���ҷ�
int BinarySearch(T A[], int key, int n)
{
	int low, high, mid;
	//��ʼ��������Ϊ������
	low = 0;
	high = n - 1;

	while (low <= high)
	{
		//�����м���λ��
		mid = (low + high) >> 1;
		if (key == A[mid].key)
		{
			printf("Binary: key %d is found, subscript is %d\n", key, mid);
			return mid;
		}
		else if (key > A[mid].key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	//δ�ҵ�������-1
	return -1;
}