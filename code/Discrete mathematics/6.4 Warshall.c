#include <stdio.h>
#include <stdlib.h>
int w[100][100],cnt,n;
void print()
{
    printf("%d\n",cnt++);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            printf("%d ",w[i][j]);
        }
        putchar('\n');
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%d",&w[i][j]);
        }
    }
    print();
    for(int k = 1;k <= n;k++)
    {
        
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
                
            }
        }
        print();
    }
    system("pause");
    return 0;
}