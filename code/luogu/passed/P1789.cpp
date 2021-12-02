#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,x,y,a[110][110] = {0},cnt = 0;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++)
    {
        cin >> x >> y;
        int j;
        for(int j = x-1;j <= x+3;j++)
        {
            a[j][y+1]++;
        }
        for(int j = y-1;j <= y+3;j++)
        {
            a[x+1][j]++;
        }
        a[x][y]++;
        a[x+2][y+2]++;
        a[x][y+2]++;
        a[x+2][y]++;
    }
    for(int i = 0;i < k;i++)
    {
        cin >> x >> y;
        for(int j = x-1;j <= x+3;j++)
        {
            for(int k = y-1;k <= y+3;k++)
            {
                a[j][k]++;
            }
        }
    }
    for(int j = 2;j <= n+1;j++)
    {
        for(int k = 2;k <= n+1;k++)
        {
            if(!a[j][k])    cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}