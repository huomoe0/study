#include <bits/stdc++.h>
#define LL long long
#define N 100
using namespace std;
bool flag[110] = {1,1};
void getprime(vector<LL> &prime)
{
    for(LL i = 2;i <= N;i++)
    {
        if(flag[i] == 0)
            prime.push_back(i);
        for(LL j = 0;j < prime.size() && prime[j]*i <= N;j++)
        {
            flag[i*prime[j]] = 1;
            if(i % prime[j] == 0)   break;
        }
    }
}
int main()
{
    double v = 1;
    vector<LL> s(110,0),prime;
    getprime(prime);
    // for(int i = 0;i < prime.size();i++)
    //     cout << prime[i] << " ";
    for(LL i = 2;i <= 100;i++)
    {
        LL j = 2,t = i;
        while(j*j <= t)
        {
            while(t % j == 0)
            {
                s[j]++;
                t /= j;
            }
            j++;
        }
        if(t > 1)   s[t]++;
    }
    for(auto i :prime)
    {
        cout << i << " " << s[i] << endl;
        v *= s[i]+1;
    }
    printf("%.0f",v);
    return 0;
}