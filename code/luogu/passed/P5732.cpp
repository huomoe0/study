#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[22][22] = {0};
    a[1][1] = 1;
    cin >> n;
    for(int i = 2;i <= n;i++)
    {
        a[i][1] = 1;
        for(int j = 2;j <= i;j++)
        {
            a[i][j] = a[i-1][j]+a[i-1][j-1];
        }
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}