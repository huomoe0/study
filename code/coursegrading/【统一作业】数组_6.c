#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[10][10] = {0};
    int b[10][10] = {0};
    int i,j,k;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    int x,y;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < n;j++)
        {
            y= 0;
            x = a[i][j];
            for(k = 0;k < n;k++)
            {
                y += b[k][j];
            }
            printf("%10d",x*y);
        }
        printf("\n");
    }
}