#include <bits/stdc++.h>
using namespace std;
int main()
{
    int sum_a = 0,sum_b = 0,n,k,cnt_a = 0,cnt_b = 0;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        if(i % k == 0)  sum_a += i,cnt_a++;
        else    sum_b += i,cnt_b++;
    }
    printf("%.1f %.1f",sum_a*1.0 / cnt_a, sum_b*1.0 / cnt_b);
    return 0;
}