#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v = 0,i,t,zan = 0,m;
    for(i = 0;i < 12;i++)
    {
        v += 300;
        cin >> t;
        if(v - t < 0)
        {
            m = i+1;
            break;
        }
        v -= t;
        zan += v/100*100;
        v -= v/100*100;
    }
    if(i == 12)
    {
        printf("%d",(int)(zan*1.2) + v);
    }
    else
    {
        printf("-%d",m);
    }
    return 0;
}