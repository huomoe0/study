#include <bits/stdc++.h>
#define LL long long
using namespace std;
int a[200],res[200];
int main()
{
    int n;
    cin >> n;
    res[1] = a[1] = 1;
    for(int i = 2;i <= n;i++)
    {
        for(int j = 1;j <= 190;j++)
        {
            res[j] *= i;
        }
        for(int j = 1;j <= 190;j++)
        {
            res[j+1] += res[j]/10;
            res[j] %= 10;
            a[j] += res[j];
        }
    }
    for(int j = 1;j <= 190;j++)
    {
        a[j+1] += a[j]/10;
        a[j] %= 10;
    }
    int len = 191;
    while(a[len] == 0)  len--;
    for(int i = len;i >= 1;i--) cout << a[i];
    return 0;    
}