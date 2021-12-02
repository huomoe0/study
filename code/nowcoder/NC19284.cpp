#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x,long long y)
{
    long long r = x % y;
    while(r != 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    return y;
}
long long lcm(long long x,long long y)
{
    return x/gcd(x,y)*y;
}
int main()
{
    long long x,y;
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> x >> y;
        long long v = lcm(x,y);
        printf("Case %d: %lld\n",i,v);
    }
    return 0;
}