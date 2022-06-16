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
	printf("-------------Direct Select Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	DirectSelectSort(FS, SIZE);
	printf("\n\n");
	for (int i = 0; i < SIZE; i++)
	{
		ForSort* fs = (ForSort*)malloc(sizeof(ForSort));
		InitForSort(fs, rand() % 100);
		FS[i] = *fs;
	}
	printf("--------------Tree Select Sort---------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	TreeSelectSort(FS, SIZE);
}