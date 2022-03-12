#include <iostream>
#define ElemType int
using namespace std;
typedef struct LNode
{
	ElemType data;
	LNode* next;
}*LinkList;
void InitList(LinkList& a)
{
	a = new LNode;
	a->next = NULL;
}

ElemType GetElem()
{

}
void test1()
{
	LNode* h = new LNode;

}
int main()
{
	test1();
	
	system("pause");
	return 0;
}