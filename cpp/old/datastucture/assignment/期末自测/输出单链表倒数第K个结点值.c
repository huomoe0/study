#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node,*list;
list create(int *n)
{
	list h = (list)malloc(sizeof(node)),tail = h;
	int e;
	while (~scanf("%d", &e))
	{
		list p = (list)malloc(sizeof(node));
		p->data = e;
		tail->next = p,tail = tail->next;
		(*n)++;
	}
	tail->next = NULL;
	return h;
}
void knode(list h,int n,int k)
{
	int i = 0;
	while (i < n - k + 1)
	{
		h = h->next, i++;
	}
	if (i == 0)	printf("Not Found\n");
	else printf("%d\n", h->data);
}
int main()
{
	int k,n = 0;
	scanf("%d", &k);
	list h = create(&n);
	knode(h, n, k);
	return 0;
}