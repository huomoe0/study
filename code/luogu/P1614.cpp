#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,m,sum = 0,i,a[3002] = {0},ans = 0;
    cin >> n >> m;
    for(i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    i = 0;
    while(i < m)
        sum += a[i++];
    ans = sum;
    while(i < n && m > 0)
    {
        sum = sum + a[i] - a[i-m];
        if(ans > sum)
            ans = sum;
        i++;
    }
    cout << ans;
    return 0;
}