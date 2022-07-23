#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* next;
    int data;
}node, * list;
list create()
{
    node* h = (node*)malloc(sizeof(node)), * tail = h;
    char ch;
    int e;
    while (~scanf("%d", &e))
    {
        node* p = (node*)malloc(sizeof(node));
        p->data = e;
        tail->next = p, tail = tail->next;

        if ((ch = getchar()) == EOF || ch == '\n')   break;
    }
    tail->next = NULL;
    return h;
}

void merge(list a, list b)
{
    a = a->next, b = b->next;
    int before = a->data < b->data ? a->data : b->data;
    printf("%d", before);
    if (a->data == before)   a = a->next;
    else b = b->next;
    while (a && b)
    {
        if (a->data == before)
        {
            a = a->next; continue;
        }
        else if (b->data == before)
        {
            b = b->next; continue;
        }
        if (a->data < b->data) printf(" %d", a->data), a = a->next;
        else if (a->data == b->data) a = a->next;
        else    printf(" %d", b->data), b = b->next;
    }

    node* p = a ? a : b;
    while (p)
    {
        if (p->data == before)
        {
            p = p->next;
            continue;
        }
        printf(" %d", p->data);
        before = p->data, p = p->next;
    }
}

int main()
{
    list a = create(), b = create();
    merge(a, b);
    return 0;
}