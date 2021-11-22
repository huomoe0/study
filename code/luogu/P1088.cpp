#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,a[10005];
    scanf("%d %d",&n,&m);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 1;i <= m;i++)
    {
        next_permutation(a,a+n);
    }
    for(i = 0;i < n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}