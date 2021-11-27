#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,n;
    long long d = 0,v;
    cin >> x >> n;
    for(int i = 0;i < n;i++)
    {
        if(x <= 5)  d++;
        x++;
        if(x == 8)  x = 1;
    }
    v = d*250;
    printf("%lld",v);
    return 0;
}