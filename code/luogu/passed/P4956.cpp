#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,k;
    cin >> n;
    for(i = 100;i >= 1;i--)
    {
        if(i*364 + 1092 > n) continue;
        else
        {
            for(k = 1;;k++)
            {
                if(i*364 + 1092*k > n)  break;
                else if(i*364 + 1092*k == n)
                {
                    printf("%d\n%d",i,k);
                    break;
                }
            }
            if(i*364 + 1092*k == n) break;
        }
    }
    return 0;
}