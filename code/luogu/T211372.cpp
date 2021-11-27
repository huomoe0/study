#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int ps,qm,zp,id;
}a[101];
bool cmp(stu a,stu b)
{
    if(a.zp != b.zp) return a.zp > b.zp;
    else return a.id < b.id;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i].name >> a[i].ps >> a[i].qm;
        a[i].id = i;
        a[i].zp = (int)(0.5 + 0.6*ceil((sqrt(a[i].qm)*10))+ 0.4*a[i].ps);
    }
    sort(a,a+n,cmp);
    for(int i = 0;i < n;i++)
    {
        cout << a[i].name << ' ' << a[i].zp << endl;
    }
    return 0;
}