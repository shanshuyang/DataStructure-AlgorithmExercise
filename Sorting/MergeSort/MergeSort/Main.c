#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 16

int main()
{
	ForSort FS[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		ForSort* fs = (ForSort*)malloc(sizeof(ForSort));
		InitForSort(fs, rand() % 100);
		FS[i] = *fs;
	}
	printf("-------------Merge Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	MergeSort(FS, SIZE);
	printf("\n\n");

	return 0;
}