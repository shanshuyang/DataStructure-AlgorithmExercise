#include <stdlib.h>
#include <stdio.h>
#include "linearList.h"

//���Ա�ĳ�ʼ��
void InitList(LinearList* L, int sz)
{
	if (sz > 0)
	{
		L->MaxSize = sz;
		L->Last = 0;
		L->data = (ElementType*)malloc(sizeof(ElementType) * L->MaxSize);
	}
}

//�ͷ����Ա�Ĵ洢�ռ�
void FreeList(LinearList* L) 
{
	free(L->data);
}

//�ж����Ա��Ƿ�Ϊ��
Bool ListEmpty(LinearList* L) 
{
	return (L->Last <= 0) ? TRUE : FALSE;
}

//�ж����Ա��Ƿ�Ϊ��
Bool ListFull(LinearList* L) 
{
	return (L->Last >= L->MaxSize) ? TRUE : FALSE;
}

//�����Ա�ĳ���
int ListLength(LinearList* L) 
{
	return L->Last;
}

//ȡ���Ա�ĵ�i����Ŀ
ElementType GetElem(LinearList* L, int i) 
{
	return (i<0 || i>L->Last) ? NULL : L->data[i];
}

//�����Ա��в���ֵΪx�Ľ�㡣������ҳɹ��򷵻ؽ����ţ����򷵻�-1��
//�������ֵΪx�Ľ���ж�����ҵ�������ǰ���һ��
int LocateElem(LinearList* L, ElementType x)
{
	int i;
	for (i = 0; i < L->Last; i++)
	{
		if (L->data[i] == x)
		{
			return i; //���ҳɹ�
		}
	}
	return -1; //����ʧ��
}

//�ڱ��е�i��λ�ò���ֵΪx�Ľ�㡣�������ɹ�����TRUE�����򷵻�FALSE
Bool InsertElem(LinearList* L, ElementType x, int i)
{
	int j;
	if (i<0 || i>L->Last || L->Last == L->MaxSize)
	{
		return FALSE; //����λ�ò����ʣ�����ʧ��
	}
	else
	{
		for (j = L->Last - 1; j >= i; j--) 
		{
			L->data[j + 1] = L->data[j]; //����
		}
		L->data[i] = x; //����
		L->Last++; //����1
		return TRUE;
	}
}

//ɾ�����е�i����㡣���ɾ���ɹ�����TRUE�����򷵻�FALSE
Bool DeleteElem(LinearList* L, int i)
{
	int j;
	if (i<0 || i>L->Last || L->Last == 0)
	{
		return FALSE; //��i����㲻���ڣ�ɾ��ʧ��
	}
	else
	{
		for (j = i; j < L->Last - 1; j++) 
		{
			L->data[j] = L->data[j + 1]; //ǰ��
		}
		L->Last--; //����1
		return TRUE;
	}
}

//��ӡ���Ա�ı�Ŀ
void printout(LinearList* L)
{
	int i;
	for ( i = 0; i < L->Last; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}