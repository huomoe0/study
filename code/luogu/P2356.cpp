#include <bits/stdc++.h>
using namespace std;
int a[1001][1001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    int row,col,n,i,j,count,ans = -1;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            if(a[i][j] > 0)
                continue;
            else
            {
                count = 0;
                int x,y;
                for(x = 0;x < n;x++)
                {
                    count += (a[i][x] + a[x][j]);
                }
                if(ans < count)
                    ans = count;
            }
        }
    }
    if(ans == -1)
    {
        cout << "Bad Game!";
    }
    else    cout << ans;
    return 0;
}