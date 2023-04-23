#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n = 0, a[1000] = { 0 },i,j;
	while (~scanf("%d", &a[n]))
		n++;
	for (i = 0; i < n - 1; i++)
	{
		int flag = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[flag] > a[j])	flag = j;
		}
		if (flag != i)
		{
			int t = a[flag];
			a[flag] = a[i], a[i] = t;
		}
	}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	return 0;
}