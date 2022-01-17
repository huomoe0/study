#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool flag[20010];
int prime[20000],cnt;
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
    int n;
    cin >> n;
    oula(n);
    for(int i = 1;i <= cnt;i++)
    {
        for(int j = i;j <= cnt;j++)
        {
            int t = n - prime[i]-prime[j];
            if(t <= 0)  break;
            if(!flag[t])
            {
                cout << prime[i] << " " << prime[j] << " " << t;
                return 0;
            }
        }
    }
}