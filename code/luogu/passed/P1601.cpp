#include <bits/stdc++.h>
using namespace std;
#define MAXN 550
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
	string A,B;
	cin >> A >> B;
	int lena = 0,lenb = 0;
	for(int i = A.size()-1;i >= 0;i--)
	{
		a[lena++] = A[i] - '0';
	}
	for(int i = B.size()-1;i >= 0;i--)
	{
		b[lenb++] = B[i] - '0';
	}
	int len = max(lena,lenb);
	for(int i = 0;i < len;i++)
	{
		c[i] += a[i]+b[i];
		if(c[i] >= 10)
		{
			c[i+1] = c[i] / 10;
			c[i] %= 10;
		}
	}
	if(c[len])	len++;
	for(int i = len-1;i >= 0;i--)
	{
		printf("%d",c[i]);
	}
	return 0;
}
