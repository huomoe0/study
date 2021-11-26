#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,n_new = 0,sign = 0;
    cin >> n;
    if(n < 0)
        sign = 1;
    n = abs(n);
    while(n > 0)
    {
        n_new = n_new * 10 + n%10;
        n /= 10;
    }
    if(sign == 1)   cout << '-';
    cout << n_new;
    return 0;
}