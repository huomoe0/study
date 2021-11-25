#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
int main()
{
    char a[1000];
    int i;
    for(i = 0;i < 1000;i++)
    {
        a[i] = -1 - i;
    }
    printf("%d",strlen(a));
    return 0;
}