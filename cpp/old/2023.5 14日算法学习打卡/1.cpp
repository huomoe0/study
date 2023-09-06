#include <iostream>
#include <cstdio>
using namespace std;
const int N = 110;
int a[N];
int main()
{
    int n, m;
    cin >> n;
    for(int i = 1;i <= n;i++)       cin >> a[i];
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        a[x-1] += y-1; //x号电线杆前y-1只鸟跳到前一个电线杆
        a[x+1] += a[x]-y; //x号电线杆后a[x]-y只鸟跳到后一个电线杆
        a[x] = 0; //此时x号电线杆没有鸟
    }
    for(int i = 1;i <= n;i++)   cout << a[i] << "\n";
    return 0;
}