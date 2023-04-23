#include <iostream>
using namespace std;
#define elemtype int
struct qnode
{
    elemtype data;
    qnode *next;
};
struct linkqueue
{
    qnode *front, *rear;
};
void initqueue(linkqueue &a)
{
    a.front = a.rear = new qnode;
    a.front->next = NULL;
}
void push(linkqueue &a,elemtype e)
{
    qnode *p = new qnode;
    p->data = e;
    p->next = NULL;
    a.rear->next = p;
    a.rear = p;
}

void pop(linkqueue &a,elemtype &e)
{
    if(a.front == a.rear) exit(0);
    qnode *p = a.front->next;
    e = p->data;
    if(a.rear == p) a.rear = a.front;
    delete p;
}
int main()
{

    system("pause");
    return 0;
}