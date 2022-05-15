#include "StackApplication.h"
#include <stdlib.h>
#include <stdio.h>

//��׺���ʽ��ֵ
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

//��׺���ʽת��Ϊ��׺���ʽ
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
		if ((int)buf[i] < 48 || (int)buf[i]>57) //����Ƿ��������ջ����
		{
			if (IsEmpty(Sptr)) //���ջ��Ϊ����ֱ����ջ
			{
				Push(Sptr, buf[i]);
			}
			else //���ջ����Ϊ���������������ջ����
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
		else //�����������ֱ��д����
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

//����㷨
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

//�׳��㷨
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

//��ŵ�������㷨
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