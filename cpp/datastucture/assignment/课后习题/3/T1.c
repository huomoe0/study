#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef struct
{
	int top[2],bot[2];
	int *v;
	int m;
}dblstack;
void init(dblstack *s)
{
	s->v = (int*)malloc(sizeof(int)*MAXSIZE);
	s->m = MAXSIZE;
	s->bot[0] = -1,s->bot[1] = m,s->top[0] = -1,s->top[1] = m;	
}
void push(dblstack &s,int i,int x)
{
	if(s->top[0] +1 == s->top[1])	return;
	if(i)	s->v[--top[i]] = x;
	else	s->v[++top[i]] = x;
}
void pop(dblstack &s,int i,int *e)
{
	if(s->top[i] == s->bot[i])	exit(0);
	if(i == 1)	*e =  s->v[s->top[i]++];
	else *e =  s->v[s->top[i]--];
}
