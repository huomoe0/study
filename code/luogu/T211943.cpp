#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000010
int n, m, k, t, a[N], ans;
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> t;
        if (a[t]) //接过花跳过
            continue;
        while (1)
        {
            if (a[t] == 1)
                break;
            a[t] = 1;
            t += k;
            t %= n;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            ans++;
    }
    cout << ans;
    return 0;
}