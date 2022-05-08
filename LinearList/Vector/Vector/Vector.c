#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>

//���������Ĵ洢�ռ�
void GetArray(Vector* V)
{
	V->elements = (ElementType*)malloc(sizeof(ElementType) * V->ArraySize);
	if (V->elements == NULL)
	{
		printf("Memory Allocation Error");
	}
}

//��ʼ������������һ����󳤶�Ϊsz������
void InitVector(Vector* V, int sz)
{
	if (sz <= 0)
	{
		printf("Invalid Array Size\n");
	}
	else
	{
		V->ArraySize = sz;
		V->VectorLength = 0;
		GetArray(V);
	}
}

//ȡ�����е�i������ֵ����������򷵻ظýڵ��ֵ�����򷵻�NULL
ElementType GetNode(Vector* V, int i)
{
	return (i < 0 || i >= V->VectorLength) ? NULL : V->elements[i];
}

//�ͷ������洢�ռ�
void FreeVector(Vector* V)
{
	free(V->elements);
}

//����ֵΪx�Ľ�㣬����ҵ��򷵻ظý�����ţ����򷵻�-1
int Find(Vector* V, ElementType x)
{
	int i;
	for (i = 0; i < V->VectorLength; i++)
	{
		if (V->elements[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//��������i��λ�ò���ֵΪx���½�㣬�������ɹ�����TRUE�����򷵻�FALSE
Bool Insert(Vector* V, ElementType x, int i)
{
	int j;
	if (V->VectorLength == V->ArraySize) //�����洢�ռ�����
	{
		printf("overflow\n");
		return FALSE;
	}
	else if (i<0 || i>V->VectorLength) //����λ�ô���
	{
		printf("position error\n");
		return FALSE;
	}
	else
	{
		for (j = V->VectorLength - 1; j >= i; j--)
		{
			V->elements[j + 1] = V->elements[j]; //����
		}
		V->elements[i] = x; //����
		V->VectorLength++; //����������1
		return TRUE;
	}
}

//ɾ����i����㣬���ɾ���ɹ�����TRUE�����򷵻�FALSE
Bool Remove(Vector* V, int i)
{
	int j;
	if (V->VectorLength == 0)
	{
		printf("Vector is empty\n");
		return FALSE;
	}
	else if (i<0 || i>V->VectorLength - 1)
	{
		printf("position error\n");
		return FALSE;
	}
	else
	{
		for (j = i; j < V->VectorLength - 1; j++)
		{
			V->elements[j] = V->elements[j + 1]; //ǰ��		
		}
		V->VectorLength--; //�������ȼ�1
		return TRUE;
	}
}

//������������еĽ��
void printout(Vector* V)
{
	int i;
	for ( i = 0; i < V->VectorLength; i++)
	{
		printf("%d ", V->elements[i]);
	}
	printf("\n");
}