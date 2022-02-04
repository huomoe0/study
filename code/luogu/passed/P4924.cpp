#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[505][505];
int main()
{
    ios::sync_with_stdio(false);
	int n,m,cnt = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)    a[i][j] = ++cnt;
    while(m--)
    {
        int x,y,r,z;
        cin >> x >> y >> r >> z;
        if(z == 0)
        {
            for(int i = 1;i <= r;i++)
            {
                for(int j = 0;j < 2*i;j++)
                {
                    int t = a[x-i][y-i+j];
                    a[x-i][y-i+j] = a[x+i-j][y-i];
                    a[x+i-j][y-i] = a[x+i][y+i-j];
                    a[x+i][y+i-j] = a[x-i+j][y+i];
                    a[x-i+j][y+i] = t;
                }
            }
        }
        else
        {
            for(int i = 1;i <= r;i++)
            {
                for(int j = 0;j < 2*i;j++)
                {
                    int t = a[x-i+j][y-i];
                    a[x-i+j][y-i] = a[x-i][y+i-j];
                    a[x-i][y+i-j] = a[x+i-j][y+i];
                    a[x+i-j][y+i] = a[x+i][y-i+j];
                    a[x+i][y-i+j] = t;
                }
            }
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}