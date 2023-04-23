#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct stack
{
	int *base,*top;
	int size;
}stack;
void init(stack *s);
void push(stack *s,int e);
int pop(stack *s);
int  top(stack s);
void T3()
{
	int t,i;
	stack s;
	init(&s);
	while(~scanf("%d",&t))
	{
		
		if(t != -1)
		{
			if(s.top - s.base == s.size)
				printf("stack is full\n");
			else	push(&s,t);
		}
		else
		{
			if(s.top == s.base)
				printf("stack is empty\n");
			else printf("%d ",pop(&s));
		}
	}
}
