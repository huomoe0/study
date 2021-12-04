#include <bits/stdc++.h>
using namespace std;
long long s[100][100][100];
long long w(long long a,long long b,long long c)
{
	if(a <= 0 || b <= 0 || c <= 0)	return 1;
	else if(a > 20 || b > 20 || c > 20)
	{
		s[20][20][20] = w(20,20,20);
		return s[20][20][20];
	}
	else if(s[a][b][c] != 0)	return s[a][b][c];
	else if(a < b && b < c)
	{
		s[a][b][c] = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		return s[a][b][c];
	}
	else
	{
		s[a][b][c] = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
		return s[a][b][c];
	}
}
int main()
{
    long long a,b,c;
    while(cin >> a >> b >> c)
    {
		if(a == -1 && b == -1 && c == -1)	break;
		else
		{
			printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
		}
	}
    return 0;
}
