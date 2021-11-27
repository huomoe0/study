#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,t,s,yu;
    cin >> m >> t >> s;
    if(t == 0)
    {
        yu = 0;
    }
    else
    {
        yu = m - ceil((double)s/t);
        if(yu < 0)
            yu = 0;
    }
    printf("%d",yu);
    return 0;
}