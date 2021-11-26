#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w,x,h,q,x1,x2,z1,y1,y2,z2,a[21][21][21] = {0},cnt = 0;
    cin >> w >> x >> h >> q;
    for(int i = 0;i < q;i++)
    {
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int j,k,l;
        for(j = x1;j <= x2;j++)
        {
            for(k = y1;k <= y2;k++)
            {
                for(l = z1;l <= z2;l++)
                {
                    a[j-1][k-1][l-1] = 1;
                }
            }
        }
    }
    int j,k,l;
    for(j = 0;j < w;j++)
    {
        for(k = 0;k < x;k++)
        {
            for(l = 0;l < h;l++)
            {
                if(!a[j][k][l])  cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}