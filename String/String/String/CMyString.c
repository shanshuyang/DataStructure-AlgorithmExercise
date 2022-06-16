#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//��ʼ������������һ���ַ�ָ����ָ�Ĵ�
void InitCMyString(CMyString* CS, char* s)
{
	//���ַ���s����CS�У�������ֹ��
	char* p1, * p2;
	for (CS->length = 0, p1 = CS->str, p2 = (char*)s; *p2; CS->length++)
	{
		*p1++ = *p2++;	
	}
	*p1 = 0;	//����ֹ��д��
}

//���ַ���s���ӵ��ַ���CS֮��
void Concatenate(CMyString* CS, CMyString* s)
{
	if (CS->length + s->length <= MAX_STRING_SIZE)
	{
		memcpy(CS->str + CS->length, s->str, s->length + 1);
		CS->length += s->length;
	}
	else
	{
		printf("error: string length overflow! \n");
	}
}

//���ַ���s���뵽�ַ���CS��pos��ָ���λ��
void InsertS(CMyString* CS, int pos, CMyString* s)
{
	if (CS->length + s->length <= MAX_STRING_SIZE)
	{
		memcpy(CS->str + pos + s->length, CS->str + pos, CS->length - pos + 1);		//����CS��pos����ַ����Ƶ���ȷ��λ��
		memcpy(CS->str + pos, s->str, s->length);									//����s�д�������ַ��Ƶ���CS��
		CS->length += s->length;
	}
	else
	{
		printf("error: string length overflow!\n");
	}
}

//ɾ����posλ��������len���ַ�
void DeleteS(CMyString* CS, int pos, int len)
{
	int rlen = len;
	if (pos + rlen > CS->length)
	{
		rlen = CS->length - pos;	//���¼����ɾ�����ַ���
	}
	CS->length -= rlen;				//���㴮CSʣ����ַ���
	memcpy(CS->str + pos, CS->str + pos + rlen, CS->length - pos + 1);	//��������λ�õ��ַ�ǰ�������ɾ����λ��
}

//��ȡһ���Ӵ�����posλ���𳤶�Ϊlen���ַ�
CMyString SubString(CMyString* CS, const int pos, const int len)
{
	int rlen = len;
	CMyString* tmpStr = (CMyString*)malloc(sizeof(CMyString));
	InitCMyString(tmpStr, " ");
	if (pos + len > CS->length)
	{
		rlen = CS->length - pos;		//���¿�����ȡ���Ӵ��ַ���
	}
	memcpy(tmpStr->str, CS->str + pos, rlen);
	tmpStr->length = rlen;
	tmpStr->str[tmpStr->length] = 0;	//���ַ��������ֹ��
	return*tmpStr;
}

//��ȡ�ַ���
char* GetString(CMyString* CS)
{
	char* tmpStr = (char*)malloc(sizeof(char) * (CS->length + 1));
	memcpy(tmpStr, CS->str, CS->length + 1);
	return tmpStr;
}

//���ַ���CS�в����ַ���s�״γ��ֵ�λ��
int Find(CMyString* CS, CMyString* s)
{
	for (int i = 0; i < CS->length; i++)
	{
		for (int j = 0; j < s->length; j++)
		{
			if (*(s->str + j) != *(CS->str + i + j))
			{
				break;
			}
			if (j == s->length - 1)
			{
				return i;
			}
		}
	}
	return -1;
}
