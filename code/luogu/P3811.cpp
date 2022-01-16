#include <bits/stdc++.h>
#define ll long long
using namespace std;
void Exgcd(ll a, ll b, ll &x, ll &y)
{
	if (!b) x = 1, y = 0;
	else Exgcd(b, a % b, y, x), y -= a / b * x;
}
int main()
{
    ios::sync_with_stdio(false);
    ll n,p,x,y;
    cin >> n >> p;
    for(int i = 1;i <= n;i++)
    {
        Exgcd(i,p,x,y);
        cout << (x % p + p) % p << endl;
    }
    return 0;
}