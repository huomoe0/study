#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int a[10000];
void sort(int a[], int l, int r)
{
	int flag = a[(l+r)>>1], i = l, j = r;
	do
	{
		while (a[i] < flag)	i++;
		while (a[j] > flag)j--;
		if (i <= j)
		{
			int t = a[i];
			a[i] = a[j], a[j] = t;
			i++, j--;
		}
	} while (i <= j);
	if (i < r)	sort(a, i, r);
	if (j > l)	sort(a, l, j);
}
int main()
{
	int n = 0,k,i;
	while (~scanf("%d", &a[n]))
		n++;
	if (n > 1)
	{
		n--, k = a[n];
		sort(a, 0, n - 1);
		for (i = 0; i < k; i++)
		{
			printf("%d ", a[i]);
		}
	}
	return 0;
}