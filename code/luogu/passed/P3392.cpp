#include <bits/stdc++.h>
#define LL long long
using namespace std;
char a[55][55];
int w[55],r[55],b[55];
int main()
{
	int n,m,ans = 100000;
	cin >> n >> m;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            cin >> a[i][j];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(a[i][j] != 'W')  w[i+1]++;
            if(a[i][j] != 'B')  b[i+1]++;
            if(a[i][j] != 'R')  r[i+1]++;
        }
    }
    for(int i = 1;i <= n-2;i++)
    {
        for(int j = i+1;j <= n-1;j++)
        {
            int cnt = 0;
            for(int k = 1;k <= i;k++)   cnt += w[k];
            for(int k = i+1;k <= j;k++) cnt += b[k];
            for(int k = j+1;k <= n;k++) cnt += r[k];
            ans = min(ans,cnt);
        }
    }
    cout << ans;
    return 0;
}