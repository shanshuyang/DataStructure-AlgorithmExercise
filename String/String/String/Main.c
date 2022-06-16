#include "CMyString.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	CMyString* str1, * str2, str3, * str4, * str5, * str6, * str7;
	char* s;
	int result = -1;
	str1 = (CMyString*)malloc(sizeof(CMyString));
	str2 = (CMyString*)malloc(sizeof(CMyString));
	str4 = (CMyString*)malloc(sizeof(CMyString));
	str5 = (CMyString*)malloc(sizeof(CMyString));
	str6 = (CMyString*)malloc(sizeof(CMyString));
	str7 = (CMyString*)malloc(sizeof(CMyString));
	InitCMyString(str1, "aabbcdef");
	InitCMyString(str2, "bcd");
	str3 = SubString(str1, 1, 4);
	printf("str1 is: %s\n", str1->str);
	s = GetString(str2);
	printf("str2 is: %s\n", s);
	printf("str3 is: %s\n", str3.str);
	result = Find(str1, str2);
	if (result != -1)
	{
		printf("Find str2 in str1, the result is: %d\n", result);
	}
	result = Find(&str3, str2);
	if (result == -1)
	{
		printf("Not find str2 in str3\n");
	}
	result = Find_KMP(str1, str2);
	if (result != -1)
	{
		printf("Find str2 in str1 with KMP, the result is: %d\n", result);
	}
	result = Find_BM(str1, str2);
	InitCMyString(str4, "which_finally_halts_at_that");
	InitCMyString(str5, "at_that");
	result = Find_BM(str4, str5);
	InitCMyString(str6, "This is a sample string");
	InitCMyString(str7, "sample string");
	result = Find_BM(str6, str7);
	return 0;
}