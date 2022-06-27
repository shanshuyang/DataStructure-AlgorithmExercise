#include "Search.h"
#include <stdio.h>
#include <stdlib.h>

//折半查找法
int BinarySearch(T A[], int key, int n)
{
	int low, high, mid;
	//初始查找区间为整个表
	low = 0;
	high = n - 1;

	while (low <= high)
	{
		//计算中间结点位置
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
	//未找到，返回-1
	return -1;
}