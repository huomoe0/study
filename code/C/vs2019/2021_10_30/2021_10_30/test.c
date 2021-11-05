#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i, j, m, n;
	scanf("%d %d", &n, &m);
	int a[10000][20] = { 0 };
	//Êý×é¸³Öµ
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int count = 0;
	int flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (!(a[i][j] ^ a[i + 1][j]))
				break;
		}
		if (flag == 1)
		{
			flag = 0;
			continue;
		}
		if (j == m)
		{
			count++;
			flag = 1;
		}
	}
	printf("%d\n", count);
	return 0;
}