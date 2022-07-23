#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int n, k, a[1000],i,cnt = 0,vis[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]); getchar();
	}
	scanf("%d", &k);
	int l = 0, r = n - 1,mid;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		vis[cnt++] = a[mid];
		if (a[mid] == k)	break;
		if (a[mid] < k)	l = mid+1;
		else r = mid - 1;
	}
	if (a[mid] == k)
	{
		printf("%d\n", mid);
	}
	else printf("no\n");
	printf("%d", vis[0]);
	for (i = 1; i < cnt; i++)
		printf(",%d", vis[i]);
	return 0;
}