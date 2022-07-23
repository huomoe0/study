#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct deque
{
    int* base;
    int front,rear;
}deque;
void init(deque *dq)
{
    dq->base = (int*)malloc(sizeof(int)*MAXSIZE);
    dq->front = dq->rear = 0;
}
void push_back(deque *dq,int e)
{
    if((dq->rear + 1)%MAXSIZE == dq->front) return;
    dq->base[dq->rear] = e;
    dq->rear = (dq->rear + 1)%MAXSIZE;
}
void pop_back(deque *dq,int *e)
{
    if(dq->front == dq->rear)   return;
    dq->rear = (dq->rear-1+MAXSIZE) % MAXSIZE;
    *e = dq->base[dq->rear];
}
void pop_front(deque *dq,int *e)
{
    if(dq->front == dq->rear)   return;
    *e = dq->base[dq->front];
    dq->front = (dq->front+1)%MAXSIZE;
}
void push_front(deque *dq,int e)
{
    if((dq->rear + 1)%MAXSIZE == dq->front) return;
    dq->front = (dq->front -1+MAXSIZE) % MAXSIZE;
    dq->base[dq->front] = e;
}
int main()
{
    deque dq;
    init(&dq);

}