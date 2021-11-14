#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,l = 0,r = 0;
    cin >> n >> m;
    set<int> s;
    queue<int> q;
    int L = 0,R = n;
    while(l < n - m)
    {
        l++;
        for(int i = l;i <= n;i++)
        {
            int a;
            cin >> a;
            q.push(a);
            s.insert(a);
            r++;
            if(q.front() == a && q.size() > 1)
            {
                q.pop();
                l++;
            }
            if(s.size() == m)
            {
                s.clear();
                break;
            }
        }
        if(r - l < R - L)
        {
            R = r;
            L = l;
        }
    }
    cout << L << ' ' << R;
    return 0;
}