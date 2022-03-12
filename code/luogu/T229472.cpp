#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[1010], b[1010], ans[1000010][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, n;
	cin >> T;
	while (T--)
	{
		int flag = 1, m = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cin >> b[i];


		for (int i = 1; i <= n; i++)
		{
			if (a[i] == b[i])	continue;
			int j;
			for (j = i; j <= n; j++)
			{
				if (a[j] == b[i])
				{
					int t = a[j];
					for (int k = j - 1; k >= i; k--)
					{
						a[k + 1] = a[k];
						ans[m][0] = k, ans[m][1] = k + 1;
						m++;
					}
					break;
				}
			}
			if (j > n)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			cout << "YES\n";
			for (int i = 0; i < m; i++)
			{
				cout << ans[i][0] << " " << ans[i][1] << '\n';
			}
			cout << "0 0\n";
		}
		else	cout << "NO\n";
	}
	return 0;
}