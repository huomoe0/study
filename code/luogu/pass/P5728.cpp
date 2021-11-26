#include <bits/stdc++.h>
using namespace std;
struct stu
{
    int yw,sx,yy,zf;
}a[1002];
int main()
{
    int n,cnt = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> a[i].yw >> a[i].sx >> a[i].yy;
        a[i].zf = a[i].sx + a[i].yw + a[i].yy;
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = i+1;j < n;j++)
        {
            if(abs(a[i].sx-a[j].sx) <= 5 && abs(a[i].yy-a[j].yy) <= 5 && abs(a[i].yw-a[j].yw) <= 5 && abs(a[i].zf-a[j].zf) <= 10)
                cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}