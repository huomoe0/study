#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct p
{
    int v,m;
}a[110];
bool cmp(p a,p b){return a.v*1.0/a.m < b.v*1.0/b.m;}
int main()
{
    ios::sync_with_stdio(false);
	int n,t;
    double ans = 0;
    cin >> n >> t;
    for(int i = 0;i < n;i++)
        cin >> a[i].m >> a[i].v;
    while(t > 0 && n > 0)
    {
        sort(a,a+n,cmp);
        if(a[n-1].m < t)
        {
            t -= a[n-1].m;
            ans += a[n-1].v;
            n--;
        }
        else
        {
            ans += a[n-1].v*t*1.0/a[n-1].m;
            a[n-1].m -= t;
            break;
        }
    }
    printf("%.2f",ans);
    return 0;
}