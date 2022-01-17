#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL inv[5000050];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,p,k;
    LL ans = 0;
    cin >> n >> p >> k;
    inv[1] = 1;
    for(int i = 2;i <= 5000000;i++)
    {
        inv[i] = (p - p/i) * inv[p%i] % p;
    }
    for(int i = 1;i <= n;i++)
    {
        int t;
        cin >> t;
        LL v = 1,a = k%p,b = i;
        while(b)
        {
            if(b&1) v = v * a % p;
            b >>= 1;
            a = a*a%p;
        }
        ans += v*inv[t]%p;
    }
    cout << ans%p;
    return 0;
}