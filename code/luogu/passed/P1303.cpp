#include <bits/stdc++.h>
using namespace std;
int a[4005],b[4005],c[4005];
int main()
{
	string A,B;
	cin >> A >> B;
	for(int i = A.size()-1;i >= 0;i--)
	{
		a[A.size()-i] = A[i] - '0';
	}
	for(int i = B.size()-1;i >= 0;i--)
	{
		b[B.size()-i] = B[i] - '0';
	}

	for(int i = 1;i <= A.size();i++)
	{
		for(int j = 1;j <= B.size();j++)
		{
			c[i+j-1] += a[i] * b[j];
		}
	}
	int len = A.size() + B.length();
	while(!c[len] && len > 1)
		len--;
	for(int i = 1;i <= len;i++)
	{
		if(c[i] > 9)
		{
			c[i+1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	if(c[len+1])	len++;
	for(int i = len;i > 0;i--)
	{
		printf("%d",c[i]);
	}
	
	return 0;
}
