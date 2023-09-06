#include <stdio.h>
#define MAXN 1000
int a[MAXN],b[MAXN];
int main()
{
    int n,m,len,flag = 1;
    scanf("%d %d",&n,&m);
    len = n>m?n:m;
    for(int i = 0;i <= len;i++) a[i] = b[i] = 0;
    for(int i = 0;i <= n;i++)   scanf("%d",&a[i]);
    for(int i = 0;i <= m;i++)   scanf("%d",&b[i]);
    for(int i = 0;i <= len;i++)
    {
        a[i] += b[i];
        if(a[i])
        {
            if(flag)
            {
                printf("%d",a[i]);
                flag = 0;
            }
            else
            {
                if(a[i] > 0)    putchar('+');
                printf("%d",a[i]);
            }
            if(i == 1)  putchar('x');
            if(i > 1)   printf("x^%d",i);
        }
    }
    if(flag)    putchar('0');
    return 0;

}