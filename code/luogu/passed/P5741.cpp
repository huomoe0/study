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
        for(j = i+1;j < n;j++)
        {
            if(abs(a[i].sx - a[j].sx) <= 5)
            {
                if(abs(a[i].yy - a[j].yy) <= 5)
                {
                    if(abs(a[i].yw - a[j].yw) <= 5)
                    {
                        if(abs(a[i].sx + a[i].yy + a[i].yw-a[j].sx -a[j].yy -a[j].yw) <= 10)
                            cout << a[i].name << ' ' << a[j].name << endl;
                    }
                }
            }
        }
    }
    return 0;
}