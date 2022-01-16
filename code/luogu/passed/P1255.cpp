#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[5010][1200];
int main()
{
    int n;
    cin >> n;
    a[1][1] = 1,a[2][1] = 2;
    for(int i = 3;i <= n;i++)
    {
    	for(int j = 1;j < 1200;j++)
    	{
			a[i][j] += a[i-1][j] + a[i-2][j];
			while(a[i][j] > 9)
			{
				a[i][j] -= 10;
				a[i][j+1]++;
			}
		}
	}
	if(!n)	cout << 0;
	else
	{
		int len = 1199;
		while(!a[n][len])	len--;
		for(int i = len;i >= 1;i--)
			cout << a[n][i];
	}
    return 0;
}
