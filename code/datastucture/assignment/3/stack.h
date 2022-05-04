#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define elemtype int
#define MAXSIZE 1000
typedef struct sqstack
{
	elemtype *base,*top;
	int size;
}sqstack;
void initsqstack(sqstack *s)
{
	s->base = (elemtype *)malloc(sizeof(elemtype)*MAXSIZE);
	if(!s->base ) s->base = s->top = NULL;
	s->size = MAXSIZE,s->top = s->base;
}
void push(sqstack *s,elemtype e)
{
	if(s->top - s->base == s->size )	exit(0);
	*s->top++ = e;
}
void pop(sqstack *s,int *e)
{
	if(s->top == s->base)	exit(0);
	*e =  *--s->top;
}
int top(sqstack s)
{
	if(s.top == s.base)	exit(0);
	return *(s.top-1);
}
