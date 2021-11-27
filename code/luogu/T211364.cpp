#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,n,cnt = 0,i;
    cin >> n >> k;
    for(i = n;;i++)
    {
        int t = i;
        cnt = 0;
        while(t > 0)
        {
            if(t % 10 == 3) cnt++;
            t /= 10;
        }
        if(cnt == k)    break;
    }
    printf("%d",i);
    return 0;
}