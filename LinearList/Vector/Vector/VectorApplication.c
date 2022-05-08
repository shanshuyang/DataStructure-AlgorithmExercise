#include "VectorApplication.h"
#include <stdlib.h>

//���ϲ����㣬������Va��Vb�ϲ���Vc�У��ظ�Ԫ��ֻ����һ��
Vector* Union(Vector* Va, Vector* Vb)
{
	int m, n, i, k, j;
	ElementType x;
	Vector* Vc = (Vector*)malloc(sizeof(Vector));
	n = Va->VectorLength; //nΪ����Va�ĳ���
	m = Vb->VectorLength; //mΪ����Vb�ĳ���
	InitVector(Vc, m + n);
	j = 0; //��¼����Vc��ǰ�ĳ���
	for (i = 0; i < n; i++) //������Va�еĽ��ȡ�����뵽Vc��
	{
		x = GetNode(Va, i);
		Insert(Vc, x, j);
		j++;
	}
	for (i = 0; i < m; i++) //������Vb�еĽ��ȡ�����ж����ظ�����뵽Vc��
	{
		x = GetNode(Vb, i);
		k = Find(Vc, x);
		if (k == -1)
		{
			Insert(Vc, x, j);
			j++;
		}
	}
	return Vc;
}

//���Ͻ�����
Vector* Insersection(Vector* Va, Vector* Vb)
{
	int m, n, i, k, j;
	ElementType x;
	Vector* Vc = (Vector*)malloc(sizeof(Vector));
	n = Va->VectorLength; //nΪ����Va�ĳ���
	m = Vb->VectorLength; //mΪ����Vb�ĳ���
	InitVector(Vc, (n > m) ? m : n);
	i = 0; 
	j = 0; //��¼����Vc��ǰ�ĳ���
	while (i<m)
	{
		x = GetNode(Vb, i); //ȡ��Vb�е�һ�����
		k = Find(Va, x); //�ж�Va���Ƿ���ڸýڵ�
		if (k!=-1) //��������򽫸ýڵ���뵽Vc��
		{
			Insert(Vc, x, j); 
			j++;
		}
		i++;
	}
	return Vc;
}

//Լɪ�������㷨
void Josephus(Vector* P, int n, int s, int m)
{
	int k = 1, s1 = s, w; //k�Ǳ�ţ�s1��¼��ǰ���е�λ�ã�w��¼���еı��
	int i, j; //i���ڼ�¼���б�ŵ�������j���ڼ�¼û�г��е�����
	for (i = 0; i < n; i++) //��������Ա��Ų���������P
	{
		Insert(P, k, i);
		k++;
	}
	for (j = n; j >= 1; j--)
	{
		s1 = (s1 + m - 1) % j; //������һ�����е�λ��
		if (s1 == 0) //����Ϊ0������£����е�λ��Ϊ������ʣ�����������һ��
		{
			s1 = j;
		}
		w = GetNode(P, s1 - 1); //��ȡ����λ�ý�������
		Remove(P, s1 - 1); //�Ƴ��ýڵ�
		Insert(P, w, n - 1); //����¼�����ݲ��뵽�������������һ��λ��
	}
}
