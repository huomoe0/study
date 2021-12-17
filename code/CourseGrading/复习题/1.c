#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n, i, t,a[11] = {0};
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &t);
		while (t != 0)
		{
			a[t % 10]++;
			t /= 10;
		}
	}
	int max = 0;
	for (i = 0; i < 10; i++)
	{
		if (a[i] > max)	max = a[i];
	}
	for (i = 0; i < 10; i++)
	{
		if (max == a[i])	printf("%d ", i);
	}
	return 0;
}
