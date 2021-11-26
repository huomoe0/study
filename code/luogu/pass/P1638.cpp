#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[2005] = {0};
int main()
{
    int n,m,l = 0,r = -1,i = 0,count = 0,ansl,ansr;
    cin >> n >> m;
    for(i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    i = 0;
    while(count != m)
    {
        if(b[a[i]] == 0)
        {
            count++;
        }
        b[a[i]]++;
        i++;
        r++;
    }
    while(b[a[l]] > 1)
        b[a[l++]]--;
    ansl = l;
    ansr = r;
    while(i < n)
    {
        b[a[i]]++;
        r++;
        i++;
        while(b[a[l]] > 1)
            b[a[l++]]--;
        if(ansr-ansl>r-l)
        {
            ansr = r;
            ansl = l;
        }
    }
    printf("%d %d",ansl+1,ansr+1);
    return 0;
}