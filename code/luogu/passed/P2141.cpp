#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[105] = {0},n,cnt = 0,flag[20001] = {0},g[20001] = {0},maxn = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
        flag[a[i]]++;
    }
    for(int i = 0;i < n-1;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            int t = a[i]+a[j];
            if(flag[t]) g[t]++;
            maxn = max(t,maxn);
        }
    }
    for(int i = 0;i < maxn;i++)
    {
        if(g[i])    cnt++;
    }
    printf("%d",cnt);
    return 0;
}