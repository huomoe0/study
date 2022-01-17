#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL ans = 0;
long long fastpow(long long x, long long y, long long mod)
{
    x %= mod;
    long long res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
int isprime(int n)
{
    int flag = 1;
    for(int i = 2;i*i <= n;i++)
    {
        if(n*i == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    int a,b,mod = 9901;
    cin >> a >> b;
    a %= mod;
    if(isprime(a))  ans += 1;
    else    
    for(int i = 1;i <= a/2;i++)
    {
        if(a % i == 0)  ans += i;
    }
    for(int i = 1;i <= b;i++)
    {
        ans += fastpow(a,i,mod);
        ans %= mod;
    }
    cout << ans;
    return 0;
}