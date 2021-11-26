#include <bits/stdc++.h>
using namespace std;
int main()
{
    unsigned long long n,x;
    scanf("%lld",&n);
    x = n*(n-1)/2*(n-2)/3*(n-3)/4;
    printf("%lld",x);
    return 0;
}