#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int t;
        double a;
        cin >> a >> t;
        for(int j = 1;j <= t;j++)
        {
            ans ^= (int)(a*j);
        }
    }
    printf("%d",ans);
    return 0;
}