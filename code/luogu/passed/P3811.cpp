#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll inv[3000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,p;
    cin >> n >> p;
    inv[1] = 1;
    cout << inv[1] << "\n";
    for(register int i = 2;i <= n;i++)
    {
        inv[i] = (p - p/i) * inv[p%i] % p;
        cout << inv[i] << "\n";
    }
    return 0;
}