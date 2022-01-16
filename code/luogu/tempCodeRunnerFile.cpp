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
    for(int i = 2;i*i <= n;i++)
    {
        if(!flag[i])
            for(int j = i*i;j <= n;j += i)  flag[j] = 1;
    }
    for(int i = 2;i <= n;i++)
    if(!flag[i])    prime[cnt++] = i;
    while(q--)
    {
        cin >> t;
        cout << prime[t-1] << endl;
    }
    return 0;
}