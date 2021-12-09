#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int getCount(int n)
{
	int i, count = 0;
	for (i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int a[100];
	int b = 0, i, t = 0;
	int flag;
	while (t != -1)
	{

		scanf("%d", &t);
		if (t != -1)	a[b++] = t;
	}
	flag = a[0];
	int max = getCount(a[0]);
	for (i = 1; i < b; i++)
	{
		if (getCount(a[i]) >= max)
		{
			flag = a[i];
			max = getCount(a[i]);

		}
	}
	printf("%d %d", flag, max);
	return 0;
}