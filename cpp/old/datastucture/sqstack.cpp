#include <iostream>
using namespace std;
#define elemtype int
#define MAXSIZE 100
struct sqstack
{
	int stacksize;
	elemtype* base;
	elemtype* top;
};

void initstack(sqstack& a)
{
	a.stacksize = MAXSIZE;
	a.base = a.top = new elemtype[MAXSIZE];
	if (!a.base)	exit(-1);
}

int stackempty(sqstack& a)
{
	return a.top == a.base;
}

size_t stacklength(sqstack& a)
{
	return a.top - a.base;
}

void clearstack(sqstack& a)
{
	a.top = a.base;
}

void destroystack(sqstack& a)
{
	a.stacksize = 0;
	delete[] a.base;
	a.base = a.top = NULL;
}

void push(sqstack& a, elemtype e)
{
	if (a.top - a.base == a.stacksize)
		return;
	*a.top++ = e;
}

elemtype pop(sqstack& a)
{
	if (a.top == a.base)	exit(0);
	return *a.top--;
}
void test1()
{
	sqstack s;

}

int main()
{
	test1();

	return 0;
}