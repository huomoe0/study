#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    scanf("%d",&n);
    double m = 0;
    if(n <= 150)
    {
        m = n * 0.4463;
    }
    else if(n > 150 && n <= 400)
    {
        m = 150 * 0.4463 + (n-150) * 0.4663;
    }
    else if(n > 400)
    {
        m = 150 * 0.4463 + 250 * 0.4663 + (n-400) * 0.5663;
    }
    printf("%.1f",m);
    return 0;
}