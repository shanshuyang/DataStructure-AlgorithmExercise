#include "Stack.h"
#include "StackApplication.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//Stack* S = (Stack*)malloc(sizeof(Stack));
	//InitStack(S, 5);
	//Push(S, 10);
	//Push(S, 8);
	//Push(S, 6);
	//printf("The top one is: %d\n", GetTop(S));
	//Pop(S);
	//Pop(S);
	//printf("After pop, the top one is: %d\n", GetTop(S));
	//MakeEmpty(S);
	//FreeStack(S);

	//后缀表达式计值
	//EvaluatePostfix();
	
	//中缀表达式转换为后缀表达式
	//ChangeInfillToPostfix();

	//求和
	printf("The result of 1+2+3+4+5 is: %d\n", Sum(5));

	//阶乘
	printf("The result of 1*2*3*4*5 is: %d\n", Factorial(5));

	//汉诺塔
	char a = '1';
	char b = '2';
	char c = '3';
	Hanoi(3, a, b, c);

	return 0;
}