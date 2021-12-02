#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,cnt = 0,x,flag = 1;
    cin >> n;
    while(cin >> x)
    {
        while(x--)
        {
            if(flag == 1)   putchar('0');
            else    putchar('1');
            cnt++;
            if(cnt == n)
            {
                cnt = 0;
                putchar('\n');
            }
        }
        flag = -flag;
    }
    return 0;
}