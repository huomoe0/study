#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,money,g;
    map<string,int> mp;
    string p[12],name;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> p[i];
    }
    for(i = 0;i < n;i++)
    {
        cin >> name >> money >> g;
        if(g == 0)  continue;
        mp[name] -= (money/g)* g; //用掉的钱
        for(int j = 0;j < g;j++)
        {
            cin >> name;
            mp[name] += money/g;
        }
    }
    for(i = 0;i < n;i++)
    {
        cout << p[i] << ' ' << mp[p[i]] << endl;
    }
    return 0;
}