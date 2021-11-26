#include <bits/stdc++.h>
using namespace std;
int a[20005] = {0};
bool cmp(int x,int y)
{
    return x < y;
}
int main()
{
    ios::sync_with_stdio(false);
    int n,b,i,ans = 0,sum = 0;
    cin >> n >> b;
    for(i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n,cmp);
    for(i = n-1;i >= 0;i--)
    {
        sum += a[i];
        ans++;
        if(sum >= b)
            break;
    }
    cout << ans;
    return 0;
}