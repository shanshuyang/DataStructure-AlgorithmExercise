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

	//��׺���ʽ��ֵ
	//EvaluatePostfix();
	
	//��׺���ʽת��Ϊ��׺���ʽ
	//ChangeInfillToPostfix();

	//���
	printf("The result of 1+2+3+4+5 is: %d\n", Sum(5));

	//�׳�
	printf("The result of 1*2*3*4*5 is: %d\n", Factorial(5));

	//��ŵ��
	char a = '1';
	char b = '2';
	char c = '3';
	Hanoi(3, a, b, c);

	return 0;
}