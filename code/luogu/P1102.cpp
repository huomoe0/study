#include <bits/stdc++.h>
using namespace std;
int a[200001] = {0};
int main()
{
    map<int,int> mp;
    int n,c,i,t;
    long long count = 0;
    cin >> n >> c;
    for(i = 0;i < n;i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(i = 0;i < n;i++)
    {
        count += mp[a[i]+c];
    }
    cout << count;
    return 0;
}