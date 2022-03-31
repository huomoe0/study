#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
	int n,maxn,minn,t;
	cin >> n;
	cin >> t;
	maxn = minn = t-1;
	for(int i = 2;i <= n;i++)
	{
		cin >> t;
		maxn = max(maxn,t-i);
		minn = min(minn,t-i);
	}
	cout << (maxn-minn+1)/2;
	return 0;
}