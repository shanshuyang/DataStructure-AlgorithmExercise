//�������򣬰�����������
#pragma once
#ifndef _SORT_H
#define _SORT_H

enum Bool
{
	FALSE,
	TRUE
};
typedef enum Bool Bool;

struct forSort
{
	int key[3];				//������������3λ
	struct forSort* next;
};
typedef struct forSort ForSort;

/// <summary>
/// ��ʼ������
/// </summary>
/// <param name="FS">�������ļ��ĵ������ָ��</param>
/// <param name="a">Ԫ�صĹؼ�ֵ</param>
void InitForSort(ForSort* FS, int a);
/// <summary>
/// ��������
/// </summary>
/// <param name="pData">�������ļ��ĵ������ָ��</param>
/// <param name="Clow">���������Ļ������½�</param>
/// <param name="Chigh">���������Ļ������Ͻ�</param>
/// <param name="d">���������󳤶�</param>
void RadixSort(ForSort* pData, int Clow, int Chigh, int d);
/// <summary>
/// ��ӡ������
/// </summary>
/// <param name="FS">�������ļ��ĵ������ָ��</param>
/// <param name="n">������Ԫ�ظ���</param>
void PrintSortResult(ForSort* FS);

#endif // !_SORT_H#pragma once
