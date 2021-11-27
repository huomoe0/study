#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> s;
    int n,i,sum = 0,t;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> t;
        s.insert(t);
    }
    int x;
    for(i = 0;i < n-1;i++)
    {
        x = *s.begin();
        s.erase(s.begin());
        x += *s.begin();
        s.erase(s.begin());
        sum += x;
        s.insert(x);
    }
    cout << sum;
    return 0;
}