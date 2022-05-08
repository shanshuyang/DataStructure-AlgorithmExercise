#include "VectorApplication.h"
#include <stdlib.h>

//集合并运算，把向量Va，Vb合并到Vc中，重复元素只保留一个
Vector* Union(Vector* Va, Vector* Vb)
{
	int m, n, i, k, j;
	ElementType x;
	Vector* Vc = (Vector*)malloc(sizeof(Vector));
	n = Va->VectorLength; //n为向量Va的长度
	m = Vb->VectorLength; //m为向量Vb的长度
	InitVector(Vc, m + n);
	j = 0; //记录向量Vc当前的长度
	for (i = 0; i < n; i++) //把向量Va中的结点取出插入到Vc中
	{
		x = GetNode(Va, i);
		Insert(Vc, x, j);
		j++;
	}
	for (i = 0; i < m; i++) //把向量Vb中的结点取出，判断无重复后插入到Vc中
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

//集合交运算
Vector* Insersection(Vector* Va, Vector* Vb)
{
	int m, n, i, k, j;
	ElementType x;
	Vector* Vc = (Vector*)malloc(sizeof(Vector));
	n = Va->VectorLength; //n为向量Va的长度
	m = Vb->VectorLength; //m为向量Vb的长度
	InitVector(Vc, (n > m) ? m : n);
	i = 0; 
	j = 0; //记录向量Vc当前的长度
	while (i<m)
	{
		x = GetNode(Vb, i); //取出Vb中的一个结点
		k = Find(Va, x); //判断Va中是否存在该节点
		if (k!=-1) //如果存在则将该节点插入到Vc中
		{
			Insert(Vc, x, j); 
			j++;
		}
		i++;
	}
	return Vc;
}

//约瑟夫问题算法
void Josephus(Vector* P, int n, int s, int m)
{
	int k = 1, s1 = s, w; //k是编号，s1记录当前出列的位置，w记录出列的编号
	int i, j; //i用于记录进行编号的人数，j用于记录没有出列的人数
	for (i = 0; i < n; i++) //将所有人员编号并存入向量P
	{
		Insert(P, k, i);
		k++;
	}
	for (j = n; j >= 1; j--)
	{
		s1 = (s1 + m - 1) % j; //计算下一个出列的位置
		if (s1 == 0) //余数为0的情况下，出列的位置为向量中剩下人数的最后一个
		{
			s1 = j;
		}
		w = GetNode(P, s1 - 1); //获取出列位置结点的内容
		Remove(P, s1 - 1); //移除该节点
		Insert(P, w, n - 1); //将记录的内容插入到整个向量的最后一个位置
	}
}
