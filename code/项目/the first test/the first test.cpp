#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
typedef struct list
{
    int length;
    int *base;
}list;
void initlist(list *a)
{
    a->base = (int*)malloc(4 * MAXN);
    if (!a->base) return;
    printf("请输入元素个数: \n");
    scanf("%d", &a->length);
    printf("请输入元素: \n");
    for (int i = 0; i < a->length; i++)
    {
        scanf("%d", &a->base[i]);
    }
}
void getelem(list a, int pos,int *e)
{
    if (pos < 1 || pos > a.length)
    {
        printf("元素不存在\n");
        return;
    }
    *e = a.base[pos - 1];
    printf("该元素为: %d\n", *e);
}
void del(list *a, int pos, int* e)
{
    if (pos < 1 || pos > a->length)
    {
        printf("元素不存在\n");
        return;
    }
    for (int i = pos - 1; i < a->length-1; i++)
    {
        a->base[i] = a->base[i + 1];
    }
    a->length--;
}
int search(list a, int dest)
{
    for (int i = 0; i < a.length; i++)
    {
        if (a.base[i] == dest)
        {
            return i + 1;
        }
    }
    return 0;
}
void insert(list* a, int pos, int e)
{
    if (pos < 1 || pos > a->length + 1 || a->length == MAXN)   return;
    for (int i = a->length-1; i >= pos-1; i--)
        a->base[i + 1] = a->base[i];
    a->base[pos - 1] = e;
    a->length++;
}
void disp(list a)
{
    for (int i = 0; i < a.length; i++)
    {
        printf("%d ", a.base[i]);
    }
    printf("\n");
}
int main()
{
    list a;
    int pos,e;
    initlist(&a);

    printf("请输入元素位置:\n");
    scanf("%d", &pos);
    getelem(a, pos, &e);
    

    printf("请输入插入位置和元素:\n");
    scanf("%d %d", &pos,&e);
    insert(&a, pos, e);

    printf("请输入要删除元素位置:\n");
    scanf("%d", &pos);
    del(&a, pos, &e);

    printf("请输入要查找元素:\n");
    scanf("%d", &e);
    printf("元素序号:%d\n", search(a, e));

    disp(a);

    system("pause");
    return 0;
}