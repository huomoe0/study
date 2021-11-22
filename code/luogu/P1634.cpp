#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long x,n,result = 1,t;
    int i;
    scanf("%lld %lld",&x,&n);
    for(i = 0;i < n;i++)
    {
        t = result * x;
        result += t;
    }
    printf("%lld",result);
    return 0;
}