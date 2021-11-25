#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s,v,h,m,spend,t;
    scanf("%d %d",&s,&v);
    spend = ceil(s*1.0/v) + 10;
    t = 60*(24+8) - spend;
    h = t / 60 % 24;
    m = t % 60;
    printf("%02d:%02d",h,m);
    return 0;
}