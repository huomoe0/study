#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1000];
int main()
{
	int T,n;
	cin >> T;
	while(T--)
	{
		int ans = 0;
		cin >> n;
		for(int i = 0;i < n;i++)
		{
			cin >> a[i];
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = i;j < n;j++)
			{
				for(int k = j;k < n;k++)
				{
					if(a[i] + a[j] == a[k])	ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}