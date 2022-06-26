#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 16

int main()
{
	ForSort* FS = (ForSort*)malloc(sizeof(ForSort));
	ForSort* currPtr = (ForSort*)malloc(sizeof(ForSort));
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		ForSort* fs = (ForSort*)malloc(sizeof(ForSort));
		InitForSort(fs, rand() % 1000);
		if (i == 0)
		{
			FS = fs;
		}
		else
		{
			currPtr->next = fs;
		}
		currPtr = fs;
	}
	printf("-------------Bubble Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS);
	printf("Sorting order: ");
	RadixSort(FS, 0, 9, 3);

	return 0;
}