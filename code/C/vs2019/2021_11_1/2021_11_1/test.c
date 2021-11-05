#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>

int sum(int x)
{
	int a = 0;
	while (x > 0)
	{
		a += x % 10;
		x /= 10;
	}
	return a;
}
int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", sum(x));
	return 0;
}