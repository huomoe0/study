#include <stdio.h>

int main()
{
    int x,y,a,b,i,j,n,m,k,arr1[10][10]={0},arr2[10][10] = {0},c,flag = 0;
    char ch;
    scanf("%d %d",&n,&m);
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            scanf("%d",&arr1[i][j]);
        }
    }
    scanf("%d",&k);
    for(c = 0;c < k;c++)
    {
        while((ch = getchar()) >'z' || ch < 'a')
        ;
        scanf("%d %d",&a,&b);
        if(ch != 'r' && ch != 'c')
        {
            continue;
        }
        if(flag == 1)
            for(x = 0;x < n;x++)
                for(y = 0;y < m;y++)
                    arr1[x][y] = arr2[x][y];
        if(ch == 'r')  //行变换
        {
            flag = 1;
            for(i = 0;i < n;i++)
            {
                for(j = 0;j < m;j++)
                {
                    if(i == a-1)
                        arr2[i][j] = arr1[b-1][j];
                    else if(i == b-1)
                        arr2[i][j] = arr1[a-1][j];
                    else
                        arr2[i][j] = arr1[i][j];
                }
            }
        }
        else
        {
            flag = 1;
            for(i = 0;i < n;i++)
            {
                for(j = 0;j < m;j++)
                {
                    if(j == a-1)
                        arr2[i][j] = arr1[i][b-1];
                    else if(j == b-1)
                        arr2[i][j] = arr1[i][a-1];
                    else
                        arr2[i][j] = arr1[i][j];
                }
            }
        }
    }
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
        {
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}