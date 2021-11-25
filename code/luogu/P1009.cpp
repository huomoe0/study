#include <bits/stdc++.h>
using namespace std;
int main()
{
    double n,sum = 0,now = 1;
    int i;
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        now *= i;
        sum += now;
        // now = round(now);
        // sum = round(sum);
    }
    printf("%.0f",sum);
    return 0;
}