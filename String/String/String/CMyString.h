//���Ľṹ�����㣬���ý�����˳��洢��ʽ
#pragma once
#ifndef _CMYSTRING_H
#define _CMYSTRING_H
#define MAX_STRING_SIZE 1024

struct cMyString
{
	int length;					//����ʵ�ʳ���
	char str[MAX_STRING_SIZE];	//�ַ����洢�ռ䣬����һ�����ӵĽ����ַ��Ĵ洢�ռ�
};
typedef struct cMyString CMyString;

/// <summary>
/// ��ʼ������������һ���ַ�ָ����ָ�Ĵ�
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="s">�ַ�ָ��</param>
void InitCMyString(CMyString* CS, char* s);
/// <summary>
/// ���ַ���s���ӵ��ַ���CS֮��
/// </summary>
/// <param name="CS">ָ�򱻸��Ӵ���ָ��</param>
/// <param name="s">ָ��Ҫ���Ӵ���ָ��</param>
void Concatenate(CMyString* CS, CMyString* s);
/// <summary>
/// ���ַ���s���뵽�ַ���CS��pos��ָ���λ��
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="pos">�����λ��</param>
/// <param name="s">������Ĵ�</param>
void InsertS(CMyString* CS, int pos, CMyString* s);
/// <summary>
/// ɾ����posλ��������len���ַ�
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="pos">ɾ����λ��</param>
/// <param name="len">ɾ���ַ��ĸ���</param>
void DeleteS(CMyString* CS, int pos, int len);
/// <summary>
/// ��ȡһ���Ӵ�����posλ���𳤶�Ϊlen���ַ�
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="pos">�Ӵ���ʼλ��</param>
/// <param name="len">�Ӵ�����</param>
/// <returns>���ر���ȡ���Ӵ�</returns>
CMyString SubString(CMyString* CS, const int pos, const int len);
/// <summary>
/// ��ȡ�ַ���
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <returns>�����ַ�������</returns>
char* GetString(CMyString* CS);
/// <summary>
/// ���ַ���CS�в����ַ���s�״γ��ֵ�λ��
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="s">�����ҵĴ�</param>
/// <returns>����ҵ��������״γ��ֵ�λ�ã����򷵻�0</returns>
int Find(CMyString* CS, CMyString* s);
/// <summary>
/// ʹ��KMPƥ���㷨ʵ�����ַ���CS�в����ַ���s�״γ��ֵ�λ��
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="s">�����ҵĴ�</param>
/// <returns>����ҵ��������״γ��ֵ�λ�ã����򷵻�0</returns>
int Find_KMP(CMyString* CS, CMyString* s);
/// <summary>
/// ʹ��BMƥ���㷨ʵ�����ַ���CS�в����ַ���s�״γ��ֵ�λ��
/// </summary>
/// <param name="CS">ָ�򴮵�ָ��</param>
/// <param name="s">�����ҵĴ�</param>
/// <returns>����ҵ��������״γ��ֵ�λ�ã����򷵻�0</returns>
int Find_BM(CMyString* CS, CMyString* s);

#endif // !_CMYSTRING_H
