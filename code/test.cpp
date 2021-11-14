#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    map<string,int> shop;
    string name;
    int p;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> name;
    }
    cin >> m;
    while(m--)
    {
        shop.clear();
        for(int i = 0;i < n;i++)
        {
            cin >> p >> name;
            shop[name] += p;
        }
        int rank = 1;
        map<string,int>::iterator it;
        for(it = shop.begin();it != shop.end();it++)
        {
            if(shop["memory"] < it->second)
                rank++;
        }
        cout << rank << endl;
    }
    return 0;
}
