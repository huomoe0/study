#include <iostream>
using namespace std;
#define elemtype int
typedef struct stacknode
{
	elemtype data;
	stacknode* next;
}*linkstack;

void initstack(linkstack &a)
{
	a = NULL;
}

int emptystack(linkstack& a)
{
	return a == NULL;
}

void push(linkstack& a, elemtype e)
{
	stacknode* p = new stacknode;
	p->data = e;
	p->next = a;
	a = p;
}

elemtype pop(linkstack& a)
{
	int e = a->data;
	stacknode* p = a;
	a = a->next;
	delete p;
	return e;
}

elemtype top(linkstack& a)
{
	if (a)	return a->data;
	exit(0);
}






int main()
{

}