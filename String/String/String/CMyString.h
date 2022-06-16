//串的结构和运算，采用紧缩的顺序存储方式
#pragma once
#ifndef _CMYSTRING_H
#define _CMYSTRING_H
#define MAX_STRING_SIZE 1024

struct cMyString
{
	int length;					//串的实际长度
	char str[MAX_STRING_SIZE];	//字符串存储空间，包括一个附加的结束字符的存储空间
};
typedef struct cMyString CMyString;

/// <summary>
/// 初始化函数，构造一个字符指针所指的串
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="s">字符指针</param>
void InitCMyString(CMyString* CS, char* s);
/// <summary>
/// 将字符串s附加到字符串CS之后
/// </summary>
/// <param name="CS">指向被附加串的指针</param>
/// <param name="s">指向要附加串的指针</param>
void Concatenate(CMyString* CS, CMyString* s);
/// <summary>
/// 将字符串s插入到字符串CS的pos所指向的位置
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="pos">插入的位置</param>
/// <param name="s">待插入的串</param>
void InsertS(CMyString* CS, int pos, CMyString* s);
/// <summary>
/// 删除从pos位置起连续len个字符
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="pos">删除的位置</param>
/// <param name="len">删除字符的个数</param>
void DeleteS(CMyString* CS, int pos, int len);
/// <summary>
/// 提取一个子串，从pos位置起长度为len的字符
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="pos">子串起始位置</param>
/// <param name="len">子串长度</param>
/// <returns>返回被提取的子串</returns>
CMyString SubString(CMyString* CS, const int pos, const int len);
/// <summary>
/// 获取字符串
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <returns>返回字符串内容</returns>
char* GetString(CMyString* CS);
/// <summary>
/// 在字符串CS中查找字符串s首次出现的位置
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="s">待查找的串</param>
/// <returns>如果找到返回其首次出现的位置，否则返回0</returns>
int Find(CMyString* CS, CMyString* s);
/// <summary>
/// 使用KMP匹配算法实现在字符串CS中查找字符串s首次出现的位置
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="s">待查找的串</param>
/// <returns>如果找到返回其首次出现的位置，否则返回0</returns>
int Find_KMP(CMyString* CS, CMyString* s);
/// <summary>
/// 使用BM匹配算法实现在字符串CS中查找字符串s首次出现的位置
/// </summary>
/// <param name="CS">指向串的指针</param>
/// <param name="s">待查找的串</param>
/// <returns>如果找到返回其首次出现的位置，否则返回0</returns>
int Find_BM(CMyString* CS, CMyString* s);

#endif // !_CMYSTRING_H
