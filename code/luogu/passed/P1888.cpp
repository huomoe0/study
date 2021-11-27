#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4],i;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    for(i = 2;i < a[0];i++)
    {
        if(a[0] % i == 0 && a[2] % i == 0)
        {
            a[0] /= i;
            a[2] /= i;
            i--;
        }
    }
    printf("%d/%d",a[0],a[2]);
    return 0;
}