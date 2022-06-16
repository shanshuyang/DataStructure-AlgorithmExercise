#include "CMyString.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//初始化函数，构造一个字符指针所指的串
void InitCMyString(CMyString* CS, char* s)
{
	//将字符串s存入CS中，包含终止符
	char* p1, * p2;
	for (CS->length = 0, p1 = CS->str, p2 = (char*)s; *p2; CS->length++)
	{
		*p1++ = *p2++;	
	}
	*p1 = 0;	//将终止符写入
}

//将字符串s附加到字符串CS之后
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

//将字符串s插入到字符串CS的pos所指向的位置
void InsertS(CMyString* CS, int pos, CMyString* s)
{
	if (CS->length + s->length <= MAX_STRING_SIZE)
	{
		memcpy(CS->str + pos + s->length, CS->str + pos, CS->length - pos + 1);		//将串CS中pos后的字符后移到正确的位置
		memcpy(CS->str + pos, s->str, s->length);									//将串s中待插入的字符移到串CS中
		CS->length += s->length;
	}
	else
	{
		printf("error: string length overflow!\n");
	}
}

//删除从pos位置起连续len个字符
void DeleteS(CMyString* CS, int pos, int len)
{
	int rlen = len;
	if (pos + rlen > CS->length)
	{
		rlen = CS->length - pos;	//重新计算可删除的字符数
	}
	CS->length -= rlen;				//计算串CS剩余的字符数
	memcpy(CS->str + pos, CS->str + pos + rlen, CS->length - pos + 1);	//将串后续位置的字符前移以填补被删除的位置
}

//提取一个子串，从pos位置起长度为len的字符
CMyString SubString(CMyString* CS, const int pos, const int len)
{
	int rlen = len;
	CMyString* tmpStr = (CMyString*)malloc(sizeof(CMyString));
	InitCMyString(tmpStr, " ");
	if (pos + len > CS->length)
	{
		rlen = CS->length - pos;		//重新可以提取的子串字符数
	}
	memcpy(tmpStr->str, CS->str + pos, rlen);
	tmpStr->length = rlen;
	tmpStr->str[tmpStr->length] = 0;	//给字符串添加终止符
	return*tmpStr;
}

//获取字符串
char* GetString(CMyString* CS)
{
	char* tmpStr = (char*)malloc(sizeof(char) * (CS->length + 1));
	memcpy(tmpStr, CS->str, CS->length + 1);
	return tmpStr;
}

//在字符串CS中查找字符串s首次出现的位置
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
