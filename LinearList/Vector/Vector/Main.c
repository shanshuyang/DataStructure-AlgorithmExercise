#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "VectorApplication.h"

int main()
{
	//������������
	Vector* V = (Vector*)malloc(sizeof(Vector));
	InitVector(V, 5);
	Insert(V, 10, 0);
	Insert(V, 20, 1);
	Insert(V, 30, 2);
	Insert(V, 40, 3);
	Insert(V, 50, 4);
	printout(V);
	printf("The lcoation of 30 is %d\n", Find(V, 30));
	Remove(V, 1);
	Remove(V, 1);
	printout(V);
	printf("After deletion the 2nd is %d\n", GetNode(V, 1));
	FreeVector(V);
	printf("---------------------------------------------------------------\n");

	//�����Ĳ�����ͽ�����
	const int sizeVa = 6;
	const int sizeVb = 8;
	Vector* Va = (Vector*)malloc(sizeof(Vector));
	Vector* Vb = (Vector*)malloc(sizeof(Vector));
	InitVector(Va, sizeVa);
	InitVector(Vb, sizeVb);
	for (int i = 0; i < sizeVb; i++)
	{
		Insert(Vb, i, i);
	}
	Insert(Va, 0, 0);
	Insert(Va, 1, 0); 
	Insert(Va, 3, 0);
	Insert(Va, 5, 0);
	Insert(Va, 7, 0);
	Insert(Va, 10, 0);
	printf("Vector Va is: ");
	printout(Va);
	printf("Vector Vb is: ");
	printout(Vb);
	printf("The result of Va union Vb is: ");
	printout(Union(Va, Vb));
	printf("The result of Va insersection Vb is: ");
	printout(Insersection(Va, Vb));
	printf("---------------------------------------------------------------\n");

	//Լɪ������
	Vector* P = (Vector*)malloc(sizeof(Vector));
	InitVector(P, 7);
	Josephus(P, 7, 2, 3); //����7���ˣ��ӵ�2���˿�ʼ������ÿ��3��������һ����
	printout(P);
	return 0;
}