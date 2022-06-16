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
	printf("-------------Direct Insertion Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	DirectInsertionSort(FS, SIZE);
	printf("\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		FS[i].key = rand() % 100;
	}
	printf("-------------Binary Insertion Sort--------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	BinaryInsertionSort(FS, SIZE);
	printf("\n\n");

	for (int i = 0; i < SIZE; i++)
	{
		FS[i].key = rand() % 100;
	}
	printf("-------------------Shell Sort-------------------\n");
	printf("Original order: ");
	PrintSortResult(FS, SIZE);
	printf("Sorting order: ");
	ShellSort(FS, SIZE, SIZE / 2);
}