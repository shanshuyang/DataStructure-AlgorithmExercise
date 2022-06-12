#include "Queue.h"
#include "apQueue.h"
#include "Bank.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


int main()
{
	//ѭ�����в�������
	Queue* Q = (Queue*)malloc(sizeof(Queue));
	InitQueue(Q, SIZE);
	EnQueue(Q, 2);
	EnQueue(Q, 3);
	EnQueue(Q, 5);
	printf("The Delete one is %d\n", DeQueue(Q));
	EnQueue(Q, 8);
	printf("Now the length of Queue is %d\n", Length(Q));
	printf("Now the top element of Queue is %d\n", GetFront(Q));
	FreeQueue(Q);
	free(Q);
	printf("---------------------------------------------------------------\n");
	//���е�Ӧ��--ģ�����л
	Simulation* S = (Simulation*)malloc(sizeof(Simulation));
	srand(time(NULL));
	InitSimulation(S);
	RunSimulation(S);
	PrintSimulationResults(S);

	return 0;
}