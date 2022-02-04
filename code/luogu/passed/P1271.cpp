#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[1010];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
    {
        int t;
        cin >> t;
        a[t]++;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < a[i];j++)
            cout << i << " ";
    }
    return 0;
}