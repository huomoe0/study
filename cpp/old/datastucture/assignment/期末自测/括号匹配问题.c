#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct stack
{
	char* base, * top;
	int capacity;
}stack;
void init(stack* s)
{
	s->base = s->top = (char*)malloc(sizeof(int) * MAXSIZE);
	if (s->base)	s->capacity = MAXSIZE;
}
void push(stack* s, char e)
{
	*s->top++ = e;
}
void pop(stack* s, char *e)
{
	*e = *--s->top;
}
int ismatch(char s[], int len)
{
	stack st; init(&st);
	int i; char t;
	for (i = 0; i < len; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')	push(&st, s[i]);
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if (st.top - st.base == 0)	return 0;
			pop(&st, &t);
			if (s[i] == ')' && t != '(' || s[i] == ']' && t != '[' || s[i] == '}' && t != '{')	return 0;
		}
	}
	return 1;
}
int main()
{
	char s[1000];
	scanf("%s", s);
	int len = strlen(s);
	printf("%d\n", ismatch(s, len));
	return 0;
}