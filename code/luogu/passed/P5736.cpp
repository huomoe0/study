#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,max = -200000000,a[105] = {0};
    cin >> n;
    for(int i = 0;i < n;i++)
    {
		cin >> a[i];
		if(a[i] == 1)	a[i] = 0;
		if(max < a[i])	max = a[i];
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 2;j < max;j++)
		{
			if(a[i] > j && a[i] % j == 0)	a[i] = 0;
		}
	}
	for(int i = 0;i < n;i++)
	{
		if(a[i] != 0)	printf("%d ",a[i]);
	}
	return 0;
}
