#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,cnt = 1;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        for(j = n-i;j > 0;j--)
        {
            printf("%02d",cnt);
            cnt++;
        }
        printf("\n");
    }
    return 0;
}