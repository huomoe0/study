#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[1100][1100],b[1100][1100];
int main()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
    {
		for(int j = 1;j <= m;j++)
	    {
	    	int t;
			cin >> t;
			a[i][t] = j;//第t天第j套
		}
	}
	for(int i = 1;i <= k;i++)//天数
	{
		int cnt = 0;
		for(int j = 1;j <= n;j++)//人
		{
			if(a[j][i] && !b[i][a[j][i]]) //每套是否准备过
			{
				cnt++;
				b[i][a[j][i]]++;
			}
		}
		printf("%d ",cnt);
	}
	return 0;
}
