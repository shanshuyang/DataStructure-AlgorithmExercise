#include "Search.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 16

int main()
{
	T A[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		A[i].key = i;
	}
	SeqSearch(A, 8, SIZE);
	return 0;
}