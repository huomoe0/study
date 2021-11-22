#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k,a,n = 0;
    double sum = 0;
    cin >> k;
    while(sum <= k)
    {
        n++;
        sum += 1.0/n;
    }
    cout << n;
    return 0;
}