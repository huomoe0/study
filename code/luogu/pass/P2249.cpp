#include <bits/stdc++.h>
using namespace std;
int main()
{
    //map<int,int> mp;
    unordered_map<int,int> mp;
    int n,m,i,x;
    cin >> n >> m;
    for(i = 1;i <= n;i++)
    {
        scanf("%d",&x);
        if(mp[x] == 0)
        {
            mp[x] = i;
        }
    }
    for(i = 0;i < m;i++)
    {
        cin >> x;
        if(mp[x] != 0)
        {
            printf("%d ",mp[x]);
        }
        else
            printf("-1 ");
    }
    return 0;
}