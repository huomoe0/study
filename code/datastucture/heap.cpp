#include <iostream>
#include <cstdlib>
using namespace std;
struct heap
{
	int *data;
	int size,capacity;
	heap()
	{
		data = NULL;
		size = capacity = 0;
	}
	~heap()
	{
		if(!data)
		{
			delete []data;
			size = capacity = 0;
			data = NULL;
		}
	}
	void checkcapacity()
	{
		if(size == capacity)
		{
			int newC = capacity ? 1 : 2*capacity;
			data = (int*)realloc(data,sizeof(int)*newC);
			capacity = newC;
		}
	}
	void shiftdown(int n,int cur)
	{
		int child = cur*2+1;
		while(child < n)
		{
			if(child+1<n && data[child+1]<data[child])
			{
				++child;
			}
			if(data[child] < data[cur])
			{
				swap(data[child],data[cur]);
				cur = child,child = cur*2+1;
			}
			else	break;
		}
	}
	void shiftup(int n,int cur)
	{
		int parent = (cur-1)/2;
		while(cur > 0)
		{
			if(data[cur] < data[parent])
			{
				swap(data[cur],data[parent]);
				cur = parent,parent = (cur-1)/2;
			}
		}
	}
	void push(int x)
	{
		checkcapacity();
		data[size++] = x;
		shiftup(size,size-1);
	}
	void pop()
	{
		if(size > 0)
		{
			swap(data[0],data[size-1]);
			size--;
			shiftdown(size,0);
		}
	}
	int top()
	{
		if(data == NULL || size == 0)	exit(0);
		return data[0];
	}
	int empty()
	{
		if(data == NULL || size == 0)	return 1;
		return 0;
	}
	void print()
	{
		for(int i = 0;i < size;i++)
		{
			printf("%d ",data[i]);
		}
		putchar('\n');
	}
	void soft()
	{
		for(int i = (size-2)/2;i >= 0;i--)
		{
			shiftdown(size,i);
		}
		int end = size-1;
		while(end > 0)
		{
			swap(data[0],data[end]);
			shiftdown(end,0);
			end--;
		}
	}
	void create(int a[],int n)
	{
		data = (int*)malloc(sizeof(int)*n);
		memcpy(data,a,sizeof(int)*n);
		size = capacity = n;
		for(int i = (size-2)/2;i >= 0;i--)
		{
			shiftdown(size,i);
		}
	}
};
void swap(int &a,int &b)
{
	int t = a;
	a = b,b = t;
}
int main()
{
	int a[] = {9,7,8,10,3,6};
	int n = sizeof(a) / sizeof(int);
	heap hp;
	hp.create(a,n);
	hp.print();
	return 0;
}
