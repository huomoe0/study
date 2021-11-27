#include <bits/stdc++.h>
using namespace std;
int main()
{
    int max = 1,n,cnt = 1,a[10005] = {0},i = 0;
    scanf("%d",&n);
    for(i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
    }
    i = 0;
    while(i < n-1)
    {
        
        cnt = 1;
        if(a[i+1] - a[i] == 1)
            while(a[i+1] - a[i] == 1 && i < n-1)
            {
                if(a[i+1]-a[i] == 1)    cnt++;
                i++;
            }
        else    i++;
        if(cnt > max)   max = cnt;
    }
    printf("%d",max);
    return 0;
}