#include <bits/stdc++.h>
#define LL long long
using namespace std;
int prime[6000010],cnt = 0;
bool flag[100000007];
int main()
{
    ios::sync_with_stdio(false);
    int n,q,t;
    cin >> n >> q;
    flag[0] = flag[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        if(!flag[i])    prime[++cnt] = i;
        for(int j = 1;j <= cnt && i*prime[j] <= n;j++)
        {
            flag[i*prime[j]] = 1;
            if(i % prime[j] == 0)   break;
        }
    }
    while(q--)
    {
        cin >> t;
        cout << prime[t] << endl;
    }
    return 0;
}