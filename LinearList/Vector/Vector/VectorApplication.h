#pragma once
#ifndef _Vector_H
#include "Vector.h"
#endif // !_Vector_H

#ifndef _VectorApplication_H
Vector* Union(Vector*, Vector*);
Vector* Insersection(Vector*, Vector*);
/// <summary>
/// Լɪ�������㷨
/// </summary>
/// <param name="V">ָ��������ָ��</param>
/// <param name="n">����ŵ�����</param>
/// <param name="s">��ʼ������λ��</param>
/// <param name="m">������������</param>
void Josephus(Vector* V, int n, int s, int m);
#endif // !_VectorApplication_H
