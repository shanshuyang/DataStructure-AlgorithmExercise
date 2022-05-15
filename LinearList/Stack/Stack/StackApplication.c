#include "StackApplication.h"
#include <stdlib.h>
#include <stdio.h>

//后缀表达式计值
void EvaluatePostfix()
{
	Stack* Spnd = (Stack*)malloc(sizeof(Stack));
	char buf[80] = { '/0' };
	int i = 0, k;

	InitStack(Spnd, 80);
	printf("Input Postfix: \n");
	scanf_s("%s", buf, sizeof(buf));

	while (buf[i] != '\0')
	{
		switch (buf[i])
		{
		case '+':
			k = Pop(Spnd) + Pop(Spnd);
			Push(Spnd, k);
			break;
		case '-':
			k = Pop(Spnd);
			k = Pop(Spnd) - k;
			Push(Spnd, k);
			break;
		case '*':
			k = Pop(Spnd) * Pop(Spnd);
			Push(Spnd, k);
			break;
		case '/':
			k = Pop(Spnd);
			k = Pop(Spnd) / k;
			Push(Spnd, k);
			break;
		default:
			Push(Spnd, (int)(buf[i] - 48));
			break;
		}
		i++;
	}
	printf("The value is: %d\n", Pop(Spnd));
}

//中缀表达式转换为后缀表达式
void ChangeInfillToPostfix()
{
	Stack* Sptr = (Stack*)malloc(sizeof(Stack));
	char buf[80] = { '/0' };
	char result[80] = { '/0' };
	int i = 0, j = 0, k;

	InitStack(Sptr, 80);
	printf("Input Infill: \n");
	scanf_s("%s", buf, sizeof(buf));

	while (buf[i] != '\0')
	{
		if ((int)buf[i] < 48 || (int)buf[i]>57) //如果是符号则进行栈操作
		{
			if (IsEmpty(Sptr)) //如果栈顶为空则直接入栈
			{
				Push(Sptr, buf[i]);
			}
			else //如果栈顶不为空则根据条件进行栈操作
			{
				if (buf[i] == '+' || buf[i] == '-')
				{
					while (1)
					{
						if (IsEmpty(Sptr) || GetTop(Sptr) == '(')
						{
							Push(Sptr, buf[i]);
							break;
						}
						else
						{
							result[j] = Pop(Sptr);
							j++;
						}
					}
				}
				else if (buf[i] == '*' || buf[i] == '/')
				{
					if (IsEmpty(Sptr)||GetTop(Sptr)=='('|| GetTop(Sptr) == '+'|| GetTop(Sptr) == '-')
					{
						Push(Sptr, buf[i]);
					}
					else
					{
						result[j] = Pop(Sptr);
						j++;
					}
				}
				else if (buf[i] == '(')
				{
					Push(Sptr, buf[i]);
				}
				else
				{
					while (GetTop(Sptr)!='(')
					{
						result[j] = Pop(Sptr);
						j++;
					}
					Pop(Sptr);
				}
			}
		}
		else //如果是数字则直接写入结果
		{
			result[j] = buf[i];
			j++;
		}
		i++;
	}
	while (!IsEmpty(Sptr))
	{
		result[j] = Pop(Sptr);
		j++;
	}
	printf("The result is: %s\n", result);
}

//求和算法
int Sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + Sum(n - 1);
	}
}

//阶乘算法
int Factorial(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

//汉诺塔问题算法
void Hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		printf("move %c to %c\n", a, c);
	}
	else
	{
		Hanoi(n - 1, a, c, b);
		printf("move %c to %c\n", a, c);
		Hanoi(n - 1, b, a, c);
	}
}