#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL cal(LL a,LL b,LL p)
{
    if(b == 0)  return 1;
    else if(b % 2 == 1) return cal(a,b-1,p) * a % p;
    else
    {
        LL tmp = cal(a,b/2,p)%p;
        return tmp*tmp%p;
    }
}
int main()
{
    LL a,b,p,ans = 1,m,t;
    cin >> a >> b >> p;
    t %= p,m = b,t = a;
    while(m)
    {
        if(m&1) ans = ans * t % p;
        m >>= 1;
        t = t*t%p;
    }
    printf("%lld^%lld mod %lld=%lld",a,b,p,ans);
    return 0;
}