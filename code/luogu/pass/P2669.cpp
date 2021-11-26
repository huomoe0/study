#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0,k,i,sum = 0,d = 0;
    cin >> k;
    while(d <= k)
    {
        cnt++;
        for(i = 1;i <= cnt;i++)
        {
            sum += cnt;
            d++;
            if(d >= k)   break;
        }
        if(d >= k)   break;
    }
    cout << sum;
    return 0;
}