#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l,n,a[10002] = {0},x,y;
    cin >> l >> n;
    for(int i = 0;i <= l;i++)
    {
        a[i] = 1;
    }
    for(int i = 0;i < n;i++)
    {
        cin >> x >> y;
        for(int j = x;j <= y;j++)
        {
            a[j] = 0;
        }
    }
    int cnt = 0;
    for(int i = 0;i <= l;i++)
    {
        if(a[i])    cnt++;
    }
    printf("%d",cnt);
    return 0;
}