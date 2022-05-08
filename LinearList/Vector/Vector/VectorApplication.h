#pragma once
#ifndef _Vector_H
#include "Vector.h"
#endif // !_Vector_H

#ifndef _VectorApplication_H
Vector* Union(Vector*, Vector*);
Vector* Insersection(Vector*, Vector*);
/// <summary>
/// 约瑟夫问题算法
/// </summary>
/// <param name="V">指向向量的指针</param>
/// <param name="n">待编号的人数</param>
/// <param name="s">开始报数的位置</param>
/// <param name="m">出列所报的数</param>
void Josephus(Vector* V, int n, int s, int m);
#endif // !_VectorApplication_H
