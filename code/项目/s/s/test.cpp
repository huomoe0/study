#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7;
int gua[5000];
int main()
{
    ios::sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m;
    if (n == 0)
    {
        for (int i = 1; i <= m; i++)
            cout << 0 << " ";
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            gua[t]++;
        }
        for (int i = 1; i <= m; i++)
        {
            ll ans = 0;
            int j = 0;
            ans += gua[i] + gua[i * 2];
            for (j = 1; j * 2 < i; j++)
            {
                int a = gua[j] + gua[j * 2];
                gua[j]--, gua[j * 2]--;
                int b = max(gua[i - j], 0) + max(gua[2 * (i - j)], 0);
                gua[j]++, gua[j * 2]++;
                ans += a * b;
            }
            if (j * 2 == i)
            {
                ans += gua[j] * max(0, gua[j] - 1);
                ans += gua[j] * gua[j * 2];
            }
            cout << ans % mod << " ";
        }
    }
    return 0;
}