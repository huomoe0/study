#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,sum = 0,i,l = 1,r = 0;
    scanf("%d",&m);
    while(sum < m)
    {
        r++;
        sum += r;
    }
    if(sum == m)
    {
        printf("%d %d\n",l,r);
    }
    while(r <= m/2+1)
    {
        while(sum > m)
        {
            sum -= l;
            l++;
        }
        if(sum == m)
        {
            printf("%d %d\n",l,r);
        }
        r++;
        sum += r;
    }
    return 0;
}