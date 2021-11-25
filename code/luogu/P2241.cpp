#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,jx,zfx = 0,cfx;
    scanf("%lld %lld",&n,&m);
    jx = n*(n+1)/2*m*(m+1)/2;
    for(long long i = 1;i <= min(n,m);i++)
    {
        zfx += (n-i+1)*(m-i+1);
    }
    cfx = jx - zfx;
    printf("%lld %lld",zfx,cfx);
    return 0;
}