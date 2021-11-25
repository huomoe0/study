#include <stdio.h>
#include <math.h>
int main()
{
    int i,n,j,flag = 0,first = 1;
    scanf("%d",&n);
    for(i = 11;i <= n;i += 10)
    {
        for(j = 2;j <= sqrt(i);j++)
        {
            if(i % j == 0)
                break;
        }
        if(j > sqrt(i))
        {
            flag = 1;
            if(first == 1)
            {
                printf("%d",i);
                first = 0;
            }
            else    printf(" %d",i);
        }
    }
    if(flag == 0)   printf("-1");
    return 0;
}