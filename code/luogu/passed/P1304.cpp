#include <bits/stdc++.h>
using namespace std;
int isprime(int n)
{
	int k;
	for(k = 2;k*k <= n;k++)
	{
		if(n%k == 0)	break;
	}
	if(k*k > n)	return 1;
	else	return 0;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 4;i <= n;i += 2)
    {
		for(int j = 2;j <= i/2;j % 2 == 0?j++:j+=2)
		{
			if(isprime(j))
			{
				int t = i-j;
				if(isprime(t))
				{
					printf("%d=%d+%d\n",i,j,t);
					break;
				}
			}
		}
	}
	return 0;
}
