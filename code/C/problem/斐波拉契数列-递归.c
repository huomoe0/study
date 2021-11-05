//ตÝน้
#include <stdio.h>
int fs(int n)
{
    if(n == 1)
        return 1;
    if(n == 2)
        return 1;
    return fs(n-1) + fs(n-2);
}

int main()
{
    int x;
    scanf("%d",&x);
    int n = fs(x);
    printf("%d\n",n);
    return 0;
}