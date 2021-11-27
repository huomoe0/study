#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,i,count = 0,id = -1;
    cin >> n >> m;
    vector<int> s;
    for(i = 1;i <= n;i++)
    {
        s.push_back(i);
    }
    while(s.size() > 0)
    {
        count++;
        id++;
        if(id == s.size())
        {
            id = 0;
        }   
        if(count == m)
        {
            cout << s[id] << ' ';
            count = 0;
            s.erase(s.begin()+id);
            id--;
        }
    }
    return 0;
}