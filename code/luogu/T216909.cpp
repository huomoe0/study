#include <bits/stdc++.h>
using namespace std;
map<int, int>number;
int a[100000] = { 2,3 };
int m[17];
int main()
{
	int n, length = 2;
	scanf("%d", &n);
	number[2] = 1;
	number[3] = 1;
	for (int i = 5; i <= 100000; i++) 
	{
		int cc = 1;
		for (int j = 0; j <= sqrt(length); j++) 
		{
			if (i % a[j] == 0) 
			{
				cc = 0;
				break;
			}
		}
		if (cc) 
		{
			a[length] = i;
			length++;
			number[i] = 1;
		}
	}
	while (n--)
	{
		int x, sum = 0, bbb = 0, length = 0;
		scanf("%d", &x);
		while (x)
		{
			if (x % 2 == 1) 
			{
				m[length] = bbb;
				length++;
			}
			x /= 2;
			bbb++;
		}
		for (int i = 0; i < length; i++) 
		{
			int sss = 1 << m[i];
			for (int j = 0; j < sss; j++) 
			{
				if (number[sss + j] == 1)
				{
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}