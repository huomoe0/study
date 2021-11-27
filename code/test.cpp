#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long i ,v = 1;
    for(i = 2;i <= 13;i++)
    {
        v *= i;
    }
    printf("%lld",v);
    return 0;
}