#include <bits/stdc++.h>
#define LL long long
using namespace std;
bool cmp(string a,string b)
{
    return a+b > b+a;
}
int main()
{
    string a[25],s;
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)    cin >> a[i];
    sort(a,a+n,cmp);
    for(int i = 0;i < n;i++)    s += a[i];
    cout << s;
    return 0;
}