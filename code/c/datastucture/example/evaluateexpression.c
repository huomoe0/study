#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
typedef struct stack
{
	int *base,*top;
	int size;
}stack;
void init(stack *s)
{
	s->size = MAXSIZE;
	s->base = s->top = (int *)malloc(sizeof(int)*MAXSIZE);
}
void pop(stack *s,int *e)
{
	if(s->top == s->base)	return;
	*e = *--s->top;
}
void push(stack *s,int e)
{
	if(s->top - s->base == MAXSIZE)	return;
	*s->top++ = e;
}
int top(stack s)
{
	if(s.top != s.base)	return *(s.top-1);
}
int in(char c)
{
	int i;
	char a[10] = {'+','-','*','/','(',')','#'};
	for(i = 0;i < 7;i++)
	{
		if(c == a[i])	return 1;
	}
	return 0;
}
char precede(char a,char b)
{
	if(a == '+' || a == '-')
	{
		if(b == '+' || b == '-' || b == '#' || b == ')' )	return '>';
		else	return '<';
	}
	if(a == '*' || a == '/')
	{
		if(b == '(')	return '<';
		else	return '>';
	}
	if(a == '(')
		if(b == ')')	return '=';
		else	return '<';
	if(a == ')')	return '>';
	if(a == '#')
		if(b == '#')	return '=';
		else return '<';
}
int operate(int a,char c,int b)
{
	switch(c)
	{
		case '+':a += b;break;
		case '-':a -= b;break;
		case '*':a *= b;break;
		case '/':a /= b;break;
	}
	return a;
}
int cal()
{
	int a,b;
	int op1,c;
	stack op,num;
	init(&op);
	init(&num);
	push(&op,'#');
	c = getchar();
	while(c != '#' || top(op) != '#')
	{
		if(c == '\n')
		{
			c = '#';
			continue;
		}
		if(!in(c))
		{
			int t = 0;
			while(c <= '9' && c >= '0')	t = t*10+c-'0',c = getchar();
			push(&num,t);
		}
		else
		{
			switch(precede(top(op),c))
			{
				case '<':
					push(&op,c);
					c = getchar();
					break;
				case '>':
					pop(&op,&op1);
					pop(&num,&b);pop(&num,&a);
					push(&num,operate(a,op1,b));
					break;
				case '=':
					pop(&op,&op1);
					c = getchar();
			}
		}
	}
	return top(num);
}
int main()
{
	printf("%d\n",cal());
	return 0;
	
}
