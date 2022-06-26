#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>

//��ʼ������
void InitForSort(ForSort* FS, int a)
{
	FS->key = a;
}

//ð������
void BubbleSort(ForSort A[], int n)
{
	int i, j;
	Bool flag;
	ForSort temp;

	for (i = n - 1, flag = (Bool)1; i > 0 && flag; i--)
	{
		flag = FALSE;		//����δ������־
		for (j = 0; j < i; j++)
		{
			if (A[j + 1].key < A[j].key)
			{
				flag = TRUE;		//�н����������ñ�־
				temp = A[j + 1];	//����
				A[j + 1] = A[j];
				A[j] = temp;
			}
		}
	}
	PrintSortResult(A, n);
}

//��������
void QuickSort(ForSort A[], int low, int high)
{
	int i, j;
	ForSort temp;
	
	if (low >= high)
	{
		return;
	}

	i = low;
	j = high;
	temp = A[i];
	while (i < j)
	{
		while (i < j && temp.key < A[j].key)	//�Ӻ���ǰ���бȽϣ�ֱ����ǰ��¼��������С�ڵ�������ֵ
		{
			j--;
		}
		if (i < j)								//��������С�ڵ�������ֵ�ļ�¼������ǰ�浱ǰ�ճ��ļ�¼λ��
		{
			A[i++] = A[j];
		}
		while (i < j && temp.key >= A[i].key)	//��ǰ������бȽϣ�ֱ����ǰ��¼���������������ֵ
		{
			i++;
		}
		if (i<j)								//���������������ֵ�ļ�¼���������浱ǰ�ճ��ļ�¼λ��
		{
			A[j--] = A[i];
		}
	}
	A[i] = temp;								//�ҵ�����ֵ��Ӧ�ļ�¼���ڵ�λ�ã�д������ֵ��Ӧ�ļ�¼
	QuickSort(A, low, --j);						//�ݹ鴦��������С�ڵ�������ֵ�������¼
	QuickSort(A, ++i, high);					//�ݹ鴦���������������ֵ�������¼
}

//��ӡ������
void PrintSortResult(ForSort A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i].key);
	}
	printf("\n");
}