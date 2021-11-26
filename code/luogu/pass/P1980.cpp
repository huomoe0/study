#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,cnt = 0,i;
    cin >> n >> x;
    for(i = 1;i <= n;i++)
    {
        int t = i;
        while(t > 0)
        {
            if(t % 10 == x) cnt++;
            t /= 10;
        }
    }
    cout << cnt;
    return 0;
}