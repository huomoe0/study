#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,t;
    cin >> n;
    for(i = 2;i <= sqrt(n);i%2==0?i++:i+=2)
    {
        if(n/i*i == n)
        {
            t = n / i;
            for(j = 2;j <= sqrt(t);j++)
            {
                if(t % j == 0)  break;
            }
            if(j > sqrt(t))
            {
                for(j = 2;j <= sqrt(i);j++)
                {
                    if(i % j == 0)  break;
                }
                if(j > sqrt(i))
                {
                    cout << t;
                    break;
                }
            }
        }
    }
    return 0;
}