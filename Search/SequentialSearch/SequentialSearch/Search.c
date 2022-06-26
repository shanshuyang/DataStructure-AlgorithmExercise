#include "Search.h"
#include <stdio.h>
#include <stdlib.h>


//À≥–Ú≤È’“∑®
int SeqSearch(T A[], int key, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (A[i].key == key)
		{
			printf("seq: key %d is found, subscript is %d\n", key, i);
			return i;
		}
	}
	printf("seq: key %d is not found\n", key);
	return -1;
}
