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
	printf("-------------Bubble Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	BubbleSort(FS, SIZE);
	printf("\n\n");
	for (int i = 0; i < SIZE; i++)
	{
		ForSort* fs = (ForSort*)malloc(sizeof(ForSort));
		InitForSort(fs, rand() % 100);
		FS[i] = *fs;
	}
	printf("--------------Quick Sort---------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	QuickSort(FS, 0, SIZE - 1);
	PrintSortResult(FS, SIZE);
}