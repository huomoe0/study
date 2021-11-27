#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x,a[1002] = {0},i = 0;
    do
    {
        cin >> x;
        a[i++] = x;
    } while (x != 0);
    for(i = i-2;i >= 0;i--)
    {
        printf("%d ",a[i]);
    }
    return 0;
}