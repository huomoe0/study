#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[5000010],ans,k;
void find(int a[],int l,int r)
{
    if(l == r)
    {
        ans = a[l];
        return;
    }
    int i = l,j = r,flag = a[(l+r)/2];
    do
    {
        while(a[i] < flag)  i++;
        while(a[j] > flag)  j--;
        if(i <= j)
        {
            int tmp = a[i];
            a[i] = a[j],a[j] = tmp;
            i++,j--;
        }
    } while (i <= j);
    if(i <= k)   find(a,i,r);
    else if(k <= j)   find(a,l,j);
    else find(a,j+1,i-1);
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> k;
    for(int i = 0;i < n;i++)
        cin >> a[i];
    find(a,0,n-1);
    cout << ans;
    return 0;
}