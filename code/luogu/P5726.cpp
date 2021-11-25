#include <bits/stdc++.h>
using namespace std;
int main()
{
    int min = 10,max = 0,n,t,sum = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> t;
        sum += t;
        if(t > max) max = t;
        if(t < min) min = t;
    }
    double avg = (sum-min-max) / (n-2.0);
    printf("%.2f",avg);
    return 0;
}