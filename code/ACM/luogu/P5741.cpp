#include <bits/stdc++.h>
using namespace std;
struct stu
{
    string name;
    int yw;
    int sx;
    int yy;
};
int main()
{
    int i,n,j,flag = 0;
    scanf("%d",&n);
    stu a[10000];
    for(i = 0;i < n;i++)
    {
        cin >> a[i].name >> a[i].yw >> a[i].sx >> a[i].yy;
    }
    for(i = 0;i < n-1;i++)
    {
        if(abs(a[i].sx - a[i+1].sx) <= 5)
        {
            if(abs(a[i].yy - a[i+1].yy) <= 5)
            {
                if(abs(a[i].yw - a[i+1].yw) <= 5)
                {
                    if(abs(a[i].sx + a[i].yy + a[i].yw-a[i+1].sx -a[i+1].yy -a[i+1].yw) <= 10)
                        cout << a[i].name << ' ' << a[i+1].name << endl;
                }
            }
        }
    }
    return 0;
}