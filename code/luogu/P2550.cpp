#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[35] = {0},cnt = 0,b[8] = {0};
    scanf("%d",&n);
    for(int i = 0;i < 7;i++)
    {
        int t;
        scanf("%d",&t);
        a[t]++;
    }
    for(int i = 0;i < n;i++)
    {
        cnt = 0;
        for(int j = 0;j < 7;j++)
        {
            int t;
            scanf("%d",&t);
            if(a[t])    cnt++;
        }
        if(cnt == 1)    b[6]++;
        else if(cnt == 2)   b[5]++;
        else if(cnt == 3)   b[4]++;
        else if(cnt == 4)   b[3]++;
        else if(cnt == 5)   b[2]++;
        else if(cnt == 6)   b[1]++;
        else if(cnt == 7)   b[0]++;
    }
    for(int i = 0;i < 7;i++)
    {
        printf("%d ",b[i]);
    }
    return 0;
}