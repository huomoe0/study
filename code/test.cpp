#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100] = {0},t,flag = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    cin >> t;
    sort(a,a+n);
    int l = 0,r = n-1,ans,mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a[mid] == t)
        {
            flag = 1;
            break;
        }
        else if(a[mid] < t)
        {
            l = mid+1;
        }
        else if(a[mid] > t)
        {
            r = mid-1;
        }
        
    }
    if(flag == 1)
    {
        printf("%d",mid+1);
    }
    else
    printf("-1");
    return 0;
}