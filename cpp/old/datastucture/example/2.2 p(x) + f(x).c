#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int c,e;
    struct node *next;
}node,*linklist;

void initlinklist(linklist *a)
{
    *a = (node*)malloc(sizeof(node));
    if(!*a)  exit(-1);
    (*a)->next = NULL,(*a)->e = -1;
}

void createpolyn(linklist a,int n) //small -> big
{
    node*p,*t;
    while(n--)
    {
        p = (node*)malloc(sizeof(node));
        scanf("%d %d",&p->c,&p->e);
        t = a;
        while(t->next && t->next->e < p->e)
            t = t->next;
        if(t->next)
        {
            if(t->next->e == p->e)
            {
                t->next->e += p->e;
                if(!t->e)
                {
                    node *q = t->next;
                    t->next = q->next;
                    free(q);
                }
            }
            else //p->e < t->next->e
            {
                p->next = t->next;
                t->next = p;
            }
        }
        else
        {
            t->next = p;
            p->next = NULL;
        }
    }
}

void add(linklist a,linklist b) //a = a+b;
{
    node*pa = a->next,*pb = b->next,*p = a,*t;
    while(pb && pa)
    {
        if(pa->e == pb->e)
        {
            pa->c += pb->c;
            if(pa->c)
            {
                p->next = pa,p = pa,pa = pa->next;
                t = pb,pb = pb->next;
                free(t);
            }
            else
            {
                t = pa,pa = pa->next;
                free(t);
                t = pb,pb = pb->next;
                free(t);
            }
        }
        else if(pa->e < pb->e)
        {
            p->next = pa,p = pa,pa = pa->next;
        }
        else
        {
            p->next = pb,p = pb,pb = pb->next;
        }
    }
    p->next = pa?pa:pb;
    free(b);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    linklist a,b;
    initlinklist(&a);
    initlinklist(&b);
    createpolyn(a,n);
    createpolyn(b,m);
    add(a,b);
    node *p = a->next;
    int flag = 1;
    while(p)
    {
        if(flag)
        {
            flag = 0;
            if(p->c == -1)  putchar('-');
            else if(p->c != 1)  printf("%d",p->c);
        }
        else
        {
            if(p->c > 0)    putchar('+');
            if(p->c == -1)  putchar('-');
            else if(p->c != 1)  printf("%d",p->c);
        }
        if(p->e > 0)    putchar('x');
        if(p->e > 1)    printf("^%d",p->e);
        p = p->next;
    }
    return 0;
}