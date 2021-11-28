#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnt = 0;
    cin >> n;
    int a[11][11] = {0},row = 1,col = 1,minr = 1,minc = 1,maxr = n,maxc = n;
    while(cnt <= n*n)
    {
        while(col <= maxc)
        {
            a[row][col] = ++cnt;
            col++;
        }
        col = maxc;
        minr++;
        row++;
        while(row <= maxr)
        {
            a[row][col] = ++cnt;
            row++;
        }
        row = maxr;
        maxc--;
        col--;
        while(col >= minc)
        {
            a[row][col] = ++cnt;
            col--;
        }
        if(cnt == n*n)  break;
        col = minc;
        maxr--;
        row--;
        while(row >= minr)
        {
            a[row][col] = ++cnt;
            row--;
        }
        row = minr;
        minc++;
        col++;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            printf("%3d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}