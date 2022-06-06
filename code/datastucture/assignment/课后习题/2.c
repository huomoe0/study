#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node * next;
}node,*linklist;

typedef struct dnode
{
    int data;
    struct dnode * next,*prior;
}dnode,*dlinklist;

typedef struct sqlist
{
    int *base;
    int length;
}sqlist;
void initlinklist(linklist *a)
{
    *a = (node*)malloc(sizeof(node));
    if(!*a)  exit(-1);
    (*a)->next = NULL;
}

void createlist(linklist a,int n)
{
    node * p,*tail = a;
    while(n--)
    {
        p = (node *)malloc(sizeof(node));
        scanf("%d",&p->data);
        tail->next = p,p->next = NULL,tail = tail->next;
    }
}

void T2_1(linklist a,linklist b)
{
    node *pa = a->next,*pb = b->next,*p = a,*t;
    while(pa && pb)
    {
        if(pa->data < pb->data)
        {
            p->next = pa,p = pa,pa = pa->next;
        }
        else if(pa->data > pb->data)
        {
            p->next = pb,p = pb,pb = pb->next;
        }
        else
        {
            p->next = pa,p = pa,pa = pa->next;
            t = pb,pb = pb->next;
            free(t);
        }
    }
    p->next = pa?pa:pb;
    free(b);
}

void T2_2(linklist a,linklist b)
{
    node *pa = a->next,*pb = b->next,*p = a,*t;
    p->next = NULL;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            t = pa,pa = pa->next;
            t->next = p->next;
            p->next = t;
        }
        else
        {
            t = pb,pb = pb->next;
            t->next = p->next;
            p->next = t;
        }
    }
    while(pa)
    {
        t = pa,pa = pa->next;
        t->next = p->next;
        p->next = t;
    }
    while(pb)
    {
        t = pb,pb = pb->next;
        t->next = p->next;
        p->next = t;
    }
    free(b);
}

void T2_3(linklist a,linklist b)
{
    node *pa = a->next,*pb = b->next,*p = a,*t;
    while(pa && pb)
    {
        while(pa && pb && pa->data < pb->data)
        {
            t = pa,pa = pa->next;
            free(t);
        }
        while(pa && pb && pa->data > pb->data)
        {
            t = pb,pb = pb->next;
            free(t);
        }
        if(pa && pb && pa->data == pb->data)
        {
            p->next = pa,p = pa,pa = pa->next;
            p->next = NULL;
            t = pb,pb = pb->next;
            free(t);
        }
    }
    free(b);
}

void T2_4(linklist a,linklist b,int *e)
{
    int n = 0;
    node *pa = a->next,*pb = b->next,*p = a,*t;
    while(pa && pb)
    {
        while(pb && pa->data > pb->data)
        {
            t = pb,pb = pb->next;
            free(t);
        }
        if(pb && pa->data < pb->data)
        {
            p->next = pa,p = pa,pa = pa->next,p->next = NULL;
            t = pb,pb = pb->next;
            free(t);
            n++;
        }
        else
        {
            t = pb,pb = pb->next;
            free(t);
            t = pa,pa = pa->next;
            free(t);
        }
    }
    if(pa)  p->next = pa;
    free(b);
    *e = n;
}

void T2_5(linklist a,linklist b,linklist c)
{
    node *pa = a->next,*pb = b,*pc = c,*t;
    while(pa)
    {
        if(pa->data < 0)
        {
            pb->next = pa,pb = pa,pa = pa->next,pb->next = NULL;
        }
        else if(pa->data > 0)
        {
            pc->next = pa,pc = pa,pa = pa->next,pc->next = NULL;
        }
        else
        {
            t = pa,pa = pa->next;
            free(t);
        }
    }
}

void T2_6(linklist a,int *e)
{
    node*p = a->next;
    if(!p)  exit(0);
    int maxn = p->data;
    p = p->next;
    while(p)
    {
        maxn = maxn > p->data ? maxn : p->data;
    }
    *e = maxn;
}

void T2_7(linklist a)
{
    node *pa = a->next,*p = a,*t;
    p->next = NULL;
    while(pa)
    {
        t = pa,pa = pa->next;
        t->next = a->next,a->next = t;
    }
}

void T2_8(linklist a,int mink,int maxk)
{
    node *p = a,*t;
    while(p->next)
    {
        if(p->next->data > mink && p->next->data < maxk)
        {
            t = p->next,p->next = t->next;
            free(t);
        }
    }
}

void T2_9(dnode *p)
{
    dnode *t = p->prior;
    t->next = p->next;
    p->prior = t->prior;
    t->prior = p;
    p->next = t;
}

void T2_10(sqlist *a,int item)
{
    int len = 0;
    for(int i = 0;i < (*a).length;i++)
    {
        if((*a).base[i] != item)
        {
            (*a).base[len++] = (*a).base[i];
        }
    }
    (*a).length = len;
}
int main()
{
    // int n,m,e;                   //T2_1 --- T2_4
    // scanf("%d %d",&n,&m);
    // linklist a,b;
    // initlinklist(&a);
    // initlinklist(&b);
    // createlist(a,n);
    // createlist(b,m);
    
    // // T2_1(a,b);
    // //T2_2(a,b);
    // //T2_3(a,b);
    // //T2_4(a,b,&e);

    // node *p = a->next;
    // while(p)
    // {
    //     printf("%d ",p->data);
    //     p = p->next;
    // }

    int n;
    scanf("%d",&n);
    linklist a,b,c;
    initlinklist(&a);
    initlinklist(&b);
    initlinklist(&c);
    createlist(a,n);
    
    // T2_5(a,b,c);
    T2_7(a);
    node*p = a->next;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    // putchar('\n');
    // p = c->next;
    // while(p)
    // {
    //     printf("%d ",p->data);
    //     p = p->next;
    // }
    // putchar('\n');


    

    


    return 0;
}