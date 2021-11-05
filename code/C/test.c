#include <stdio.h>
int main()
{
    int i,a[5];
    for(i = 0;i < 5;i++)
    {
        scanf("%d",&a[i]);
    }
    int * p = a;
    printf("%d",++(*p));
    return 0;

}