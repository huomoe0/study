#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool flag[100000010];
int cnt,prime[10000000];
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
    cout << cnt;
    return 0;
}