#include <bits/stdc++.h>
using namespace std;
// struct aa
// {
//     int ind = 0,v = 0;
// }a[100005];
// bool operator < (const aa& a,const int n)
// {
//     return a.v<n;
// }
// bool cmp(aa x,aa y)
// {
//     return x.v < y.v;
// }
// int main()
// {
//     int n,q,m;
//     cin >> n;
//     for(int i = 0;i < n;i++)
//     {
//         cin >> a[i].v;
//         a[i].ind = i+1;
//     }
//     sort(a,a+n,cmp);
//     cin >> q;
//     int x;
//     for(int i = 1;i <= q;i++)
//     {
//         cin >> m;
//         x = lower_bound(a,a+n,m)-a;
//         if(a[x].v == m)
//             cout << a[x].ind  << endl;
//         else
//             cout << '0' << endl; 
        
//     }
//     return 0;
// }


int main()
{
    map<int,int> mp;
    int n,x,i,q;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> x;
        mp[x] = i+1;
    }
    cin >> q;
    for(i = 0;i < q;i++)
    {
        cin >> x;
        cout << mp[x] << endl;
    }
    return 0;
}