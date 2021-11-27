#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j,cnt = 1;
    cin >> n;
    for(i = 1;i <= n*n;i++)
    {
        printf("%02d",i);
        if(i % n == 0)  printf("\n");
    }
    printf("\n");
    for(i = 1;i <= n;i++)
    {
        for(j = 1;j <= n-i;j++)
        {
            printf("  ");
        }
        for(j = 1;j <= i;j++)
        {
            printf("%02d",cnt++);
        }
        printf("\n");
    }
    return 0;
}