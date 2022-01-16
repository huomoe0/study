#include <bits/stdc++.h>
#define LL long long
using namespace std;
struct p
{
    int id,s;
}a[5010];
bool cmp(p a,p b)
{
    if(a.s != b.s)  return a.s > b.s;
    return a.id < b.id;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < n;i++)
        cin >> a[i].id >> a[i].s;
    sort(a,a+n,cmp);
    int line = a[(int)(m*1.5)-1].s,cnt = 0;
    while(a[cnt].s >= line) cnt++;
    cout << line << " " << cnt << endl;
    for(int i = 0;i < cnt;i++)
    {
        cout << a[i].id << " " << a[i].s << endl;
    }
    return 0;
}