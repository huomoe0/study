#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct stack
{
	char *base,*top;
	int size;
}stack;
void init(stack *s);
void push(stack *s,int e);
int pop(stack *s);
int  top(stack s);
int ishuiwen(char str[],int len)
{
	int i;
	stack s;
	init(&s);
	for(i = 0;i < (len+1)/2;i++)
		push(&s,str[i]);
	if(len&1)	pop(&s);
	for(i = (len+1)/2;i < len;i++)
	{
		if(top(s) != str[i])	return 0;
		pop(&s);
	}
	return 1;
}
