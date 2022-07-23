#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1000
typedef struct stack
{
    int * base,*top;
    int stacksize;
}stack;
void initstack(stack *s)
{
    s->base = (int*)malloc(sizeof(int)*MAXN);
    if(!s->base)    exit(-1);
    s->top = s->base;
    s->stacksize = MAXN;
}
void clear(stack *s)
{
    if(s->base != NULL)
    {
        free(s->base);
        s->stacksize = 0;
        s->base = s->top = NULL;
    }
}
void push(stack *s,int e)
{
    if(s->top-s->base == s->stacksize)    exit(0);
    *s->top++ = e;
}
int pop(stack *s)
{
    if(s->top == s->base) exit(0);
    return *--s->top;
}
int empty(stack *s)
{
    if(s->top == s->base) return 1;
    return 0;
}
void change(int n)
{
    stack s;
    initstack(&s);
    while(n)
    {
        push(&s,n%8);
        n /= 8;
    }
    while(!empty(&s))
    {
        printf("%d",pop(&s));
    }
    clear(&s);
}
int main()
{
    int n;
    scanf("%d",&n);
    change(n);
    return 0;
}