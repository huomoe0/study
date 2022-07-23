#include <iostream>
#define MAXN 1000
#define elemtype int
using namespace std;

struct queue
{
    elemtype *base;
    int front,rear;
};

void initqueue(queue &a)
{
    a.base = new elemtype[MAXN];
    if(!a.base) exit(-1);
    a.front = a.rear = 0;
}

size_t queuelength(const queue &a)
{
    return (a.rear - a.front + MAXN) % MAXN;
}

int empty(const queue &a)
{
    if(a.front == a.rear)   return 1;
    return 0;
}

void push(queue &a,elemtype e)
{
    if((a.rear + 1) % MAXN == a.front)  return;
    a.base[a.rear] = e;
    a.rear = (a.rear + 1) % MAXN;
}
void pop(queue &a,elemtype &e)
{
    if(a.rear == a.front)   return;
    e = a.base[a.front];
    a.front = (a.front + 1) % MAXN;
}

elemtype top(const queue &a)
{
    if(a.rear != a.front)   return a.base[a.front];
    exit(0);
}
int main()
{
    int e;
    queue a;
    initqueue(a);
    push(a,1);
    push(a,3);
    cout << top(a) << endl;
    pop(a,e);
    cout << top(a) << endl;
    return 0;
}