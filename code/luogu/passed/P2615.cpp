#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[40][40] = {0},cnt = 1,n;
    cin >> n;
    int row = 0,col = (n-1)/2;
    a[row][col] = 1;
    while(cnt <= n*n)
    {
        if(row == 0 && col != n-1)
        {
            row = n-1;
            col++;
            a[row][col] = ++cnt;
        }
        else if(col == n-1 && row != 0)
        {
            row--;
            col = 0;
            a[row][col] = ++cnt;
        }
        else if(row == 0 && col == n-1)
        {
            row++;
            a[row][col] = ++cnt;
        }
        else if(row != 0 && col != n-1)
        {
            if(!a[row-1][col+1])    a[--row][++col] = ++cnt;
            else    a[++row][col] = ++cnt;
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}