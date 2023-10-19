#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
typedef struct sqqueue
{
    int *base;
    int tag,front,rear;
}sqqueue;
void initsqqueue(sqqueue *q)
{
    q->base = (int*)malloc(sizeof(int)*MAXSIZE);
    if(!q->base)   exit(-1);
    q->rear = q->front = q->tag = 0;
}
void enqueue(sqqueue *Q,int e)
{
    if(Q->rear == Q->front && Q->tag == 1)  return;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear+1)%MAXSIZE;
    Q->tag = 1;
}
void dequeue(sqqueue *Q,int *e)
{
    if(Q->tag == 0 && Q->rear == Q->front)  return;
    e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    Q->tag = 0; 
}
int main()
{
    return 0;
}