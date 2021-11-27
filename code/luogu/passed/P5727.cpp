#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt = 0,a[100000] = {0};
    cin >> n;
    while(n != 1)
    {
        a[cnt++] = n;
        if(n % 2 == 0)  n /= 2;
        else    n = n*3 + 1;
    }
    a[cnt] = 1;
    for(int i = cnt;i >= 0;i--)
        printf("%d ",a[i]);
    return 0;
}