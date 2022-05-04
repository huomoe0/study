#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node * next;
}node;
node *create()
{
	node *h = (node *)malloc(sizeof(node)),*rear = h;
	if(!h)	return NULL;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		node *p = (node *)malloc(sizeof(node));
		scanf("%d",&p->data );
		rear->next = p,rear = rear->next;
	}
	rear->next = h;
}
int empty(node *rear)
{
	return rear->next->next == rear->next;
}
void push(node *rear,int e)
{
	node *t = rear->next,*p = (node *)malloc(sizeof(node));
	if(!p)	exit(0);
	rear->next = p,p->data = e,p->next = t;
}
void pop(node **rear,int *e)
{
	node *h = (*rear)->next,*p = h->next;
	if(h->next = h)	return;
	*e = p->data;
	if(p == *rear)
	{
		*rear = h;
		h->next = p->next;
	}
	else	h->next = p->next;
	free(p);
}
void clearqueue(node **rear)
{
	*rear = (*rear)->next;
	while(*rear != (*rear)->next)
	{
		node *t = *rear;
		*rear = (*rear)->next;
		free(t);
	}
}
int main()
{
	node *rear = create();
	return 0;
}
