#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int a[20] = { 0 };
	int b[20] = { 0 };
	int c[40] = { 0 };
	char ch = 0;
	int i = 0;
	while (ch != '\n')
	{
		scanf("%d" ,&a[i++]);
		ch = getchar();
	}
	int j = 0;
	ch = 0;
	while (ch != '\n')
	{
		scanf("%d", &b[j++]);
		ch = getchar();
	}
	int m, n,m1,n1;
	//≈≈–Ú
	for (m1 = 0; m1 < i - 1; m1++)
	{
		for (m = 0; m < i - 1; m++)
		{
			if (a[m] > a[m + 1])
			{
				int t = a[m];
				a[m] = a[m + 1];
				a[m + 1] = t;
			}
		}
	}
	for (n1 = 0; n1 < j - 1; n1++)
	{
		for (n = 0; n < j - 1; n++)
		{
			if (b[n] > b[n + 1])
			{
				int t = b[n];
				b[n] = b[n + 1];
				b[n + 1] = t;
			}
		}
	}
	m = 0, n = 0;
	int k = 0;
	while (1)
	{
		if (m == i && n == j)
			break;
		if (m < i)
		{
			if (a[m] == a[m + 1])
			{
				m++;
				continue;
			}
			else
			{
				c[k] = a[m];
				m++;
				k++;
			}
		}
		if (n < j)
		{
			if (b[n] == b[n + 1])
			{
				n++;
				continue;
			}
			else
			{
				c[k] = b[n];
				n++;
				k++;
			}
		}
		
	}
	//≈≈–Ú2
	for (i = 0; i < k-1; i++)
	{
		for (j = 0; j < k -1; j++)
		{
			if (c[j] > c[j+1])
			{
				int t = c[j];
				c[j] = c[j+1];
				c[j+1] = t;
			}
		}
	}
	// ‰≥ˆ
	for (i = k-1; i >=0; i--)
	{
		if (i > 0 && c[i - 1] != c[i])
		{
			printf("%d ", c[i]);
		}
		else if(i == 0)
			printf("%d ", c[0]);
	}
	return 0;
}