#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tnode
{
	int data;
	struct tnode* lchild, * rchild;
}tnode,*tree;

int Max(int a, int b)
{
	return a > b ? a : b;
}
void insert(tree* T, int x)
{
	if (*T == NULL)
	{
		*T = (tree)malloc(sizeof(tnode));
		(*T)->data = x, (*T)->lchild = (*T)->rchild = NULL;
	}
	else if ((*T)->data > x)	insert(&(*T)->lchild, x);
	else if ((*T)->data < x)	insert(&(*T)->rchild, x);
}
int height(tree T)
{
	if (T == NULL)	return 0;
	return Max(height(T->lchild), height(T->rchild))+1;
}
void inordertraverse(tree T)
{
	if (!T)	return;
	inordertraverse(T->lchild);
	printf("%d ", T->data);
	inordertraverse(T->rchild);
}
int main()
{
	int n,t,i,h = 0;
	tree T = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &t);
		insert(&T, t);
	}
	printf("%d\n", height(T));
	inordertraverse(T);
	return 0;
}