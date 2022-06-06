#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n = 0,a[1000] = {0},k;
	while (~scanf("%d", &a[n]))
	{
		n++;
	}
	n--, k = a[n];
	int l = 0, r = n - 1,mid,ans = -1;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		if (a[mid] >= k)	r = mid - 1;
		else l = mid;
	}
	if (a[l] < k)	ans = l;
	printf("%d\n", ans);
	return 0;
}