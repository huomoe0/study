#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0,n,k,a[10005] = {0},ans = 0;
    cin >> n >> k;
    for(int i = 0;i <= n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0;i < n;i++)
    {
        cnt = 0;
        for(int j = i;j < n;j++)
        {
            if(abs(a[j] - a[i]) <= k)    cnt++;
        }
        if(cnt > ans)    ans = cnt;
    }
    printf("%d",ans);
    return 0;
}