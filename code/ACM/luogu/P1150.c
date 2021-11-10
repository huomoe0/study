#include <stdio.h>
int main()
{
    int i,n,k,count = 0;
    scanf("%d %d",&n,&k);
    for(i = 1;i <= n;i++)
    {
        count++;
        if(count == k)
        {
            n++;
            count = 0;
        }
    }
    printf("%d\n",n);
    return 0;
}