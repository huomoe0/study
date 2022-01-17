#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool flag[1000010];
int prime[100000],cnt;
void oula(int n)
{
    flag[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!flag[i])    prime[++cnt] = i;
        for(int j = 1;j <= cnt && i*prime[j] <= n;j++)
        {
            flag[i*prime[j]] = 1;
            if(i % prime[j] == 0)   break;
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    oula(m);
    while(n--)
    {
        int l,r,ans = 0;
        cin >> l >> r;
        if(r > m || l < 1)
        {
            cout << "Crossing the line" << "\n";
            continue;
        }
        int j = 1;
        while(prime[j] < l && j <= cnt) j++;
        while(prime[j] <= r && j <= cnt)    j++,ans++;
        cout << ans << "\n";
    }
    return 0;
}