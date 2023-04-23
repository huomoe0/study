#include <stdio.h>
#include <stdlib.h>
#define TElemType char
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild,*rchild;
	int LTag,RTag;
}BiThrNode,*BiThrTree;

BiThrTree pre;

void CreateBiTree(BiTree *T)
{
	char ch;
	scanf(" %c",&ch);
	if(ch == '#')	(*T) = NULL;
	else
	{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
		if(*T == NULL)	return;
		(*T)->data = ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
}
int BiTreeEmpty(BiTree T)
{
	if(T)	return 0;
	return 1;
}
void DestroyBiTree(BiTree *T)
{
	if((*T)->lchild)	DestroyBiTree(&(*T)->lchild);
	if((*T)->rchild)	DestroyBiTree(&(*T)->rchild);
	free(*T);
}
int BiTreeDepth(BiTree T)
{
	if(!T)	return 0;
	int m = BiTreeDepth(T->lchild);
	int n = BiTreeDepth(T->rchild);
	return (m>n?m:n)+1;
}
void InOrderTraverse(BiTree T)
{
	if(T == NULL)	return;
	InOrderTraverse(T->lchild);
	printf("%c ",T->data);
	InOrderTraverse(T->rchild);
}
void PreOrderTraverse(BiTree T)
{
	if(T == NULL)	return;
	printf("%c ",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
void PostOrderTraverse(BiTree T)
{
	if(T == NULL)	return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c ",T->data);
}
void Copy(BiTree T,BiTree *NewT)
{
	if(!T)	(*NewT) = NULL;
	else
	{
		(*NewT) = (BiTree)malloc(sizeof(BiTNode));
		(*NewT)->data = T->data;
		if(!(*NewT))	return;
		Copy(T->lchild,&(*NewT)->lchild);
		Copy(T->rchild,&(*NewT)->rchild);
	}
}
int NodeCount(BiTree T)
{
	if(!T)	return 0;
	return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
void InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild );
		if(!p->lchild)
		{
			p->LTag = 1;
			p->lchild = pre;
		}
		else p->LTag = 0;
		if(!pre->rchild )
		{
			pre->RTag = 1;
			pre->rchild= p;
		}
		else	pre->RTag = 0;
		pre = p;
		InThreading(p->rchild );
	}
}
void InOrderThreading(BiThrTree *Thrt,BiThrTree T)
{
	(*Thrt) = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)	return;
	(*Thrt)->LTag = 0,(*Thrt)->RTag = 1;
	(*Thrt)->rchild = (*Thrt);
	if(!T)	(*Thrt)->lchild = (*Thrt);
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);
		pre->rchild = (*Thrt),pre->RTag = 1;
		(*Thrt)->rchild = pre;
	}
}
void InOrderTraverse_Thr(BiThrTree T)
{
	if(!T)	return;
	BiThrTree p = T->lchild;
	while(p!=T)
	{
		while(p->LTag == 0)	p = p->lchild;
		printf("%c ",p->data );
		while(p->RTag == 1 && p->rchild != T)
		{
			p = p->rchild;printf("%c ",p->data);
		}
		p = p->rchild;
	}
}

void test01()
{
	BiTree T,NewT; // A B # # C # #
	CreateBiTree(&T);
	Copy(T,&NewT);
	DestroyBiTree(&T);
	printf("%d\n",NodeCount(NewT));
	PreOrderTraverse(NewT);
	putchar('\n');
	InOrderTraverse(NewT);
	putchar('\n');
	PostOrderTraverse(NewT);
}

void test02()
{
	
}
int main()
{
	//test01();
	test02();
	
	return 0;
}
